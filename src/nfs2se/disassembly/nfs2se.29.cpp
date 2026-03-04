#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x90 */
void Application::sub_4a3ee8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3ee8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3ee9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3eea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a3eec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3eee  7505                   -jne 0x4a3ef5
    if (!cpu.flags.zf)
    {
        goto L_0x004a3ef5;
    }
L_0x004a3ef0:
    // 004a3ef0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3ef2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3ef3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3ef4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a3ef5:
    // 004a3ef5  e826ffffff             -call 0x4a3e20
    cpu.esp -= 4;
    sub_4a3e20(app, cpu);
    if (cpu.terminate) return;
    // 004a3efa  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a3efc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3efe  7522                   -jne 0x4a3f22
    if (!cpu.flags.zf)
    {
        goto L_0x004a3f22;
    }
    // 004a3f00  833df0d34c0000         +cmp dword ptr [0x4cd3f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5034992) /* 0x4cd3f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3f07  74e7                   -je 0x4a3ef0
    if (cpu.flags.zf)
    {
        goto L_0x004a3ef0;
    }
    // 004a3f09  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3f0b  e86450fdff             -call 0x478f74
    cpu.esp -= 4;
    sub_478f74(app, cpu);
    if (cpu.terminate) return;
L_0x004a3f10:
    // 004a3f10  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a3f12  75dc                   -jne 0x4a3ef0
    if (!cpu.flags.zf)
    {
        goto L_0x004a3ef0;
    }
    // 004a3f14  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3f16  e8dd4bfdff             -call 0x478af8
    cpu.esp -= 4;
    sub_478af8(app, cpu);
    if (cpu.terminate) return;
    // 004a3f1b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a3f1d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3f1f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3f20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3f21  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a3f22:
    // 004a3f22  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3f24  e85bffffff             -call 0x4a3e84
    cpu.esp -= 4;
    sub_4a3e84(app, cpu);
    if (cpu.terminate) return;
    // 004a3f29  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a3f2b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3f2d  74e1                   -je 0x4a3f10
    if (cpu.flags.zf)
    {
        goto L_0x004a3f10;
    }
    // 004a3f2f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3f31  e83e50fdff             -call 0x478f74
    cpu.esp -= 4;
    sub_478f74(app, cpu);
    if (cpu.terminate) return;
    // 004a3f36  2b05ecd34c00           +sub eax, dword ptr [0x4cd3ec]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5034988) /* 0x4cd3ec */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a3f3c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004a3f3e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a3f40  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3f42  e8e18dfdff             -call 0x47cd28
    cpu.esp -= 4;
    sub_47cd28(app, cpu);
    if (cpu.terminate) return;
    // 004a3f47  ebc7                   -jmp 0x4a3f10
    goto L_0x004a3f10;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a3f4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3f4c  c7053cac4c00e83e4a00   -mov dword ptr [0x4cac3c], 0x4a3ee8
    app->getMemory<x86::reg32>(x86::reg32(5024828) /* 0x4cac3c */) = 4865768 /*0x4a3ee8*/;
    // 004a3f56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a3f57(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3f57  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3f58  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3f59  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a3f5a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3f5b  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004a3f5e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a3f60  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004a3f62  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 004a3f67  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004a3f69  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a3f6c  885c246c               -mov byte ptr [esp + 0x6c], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.bl;
    // 004a3f70  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004a3f72  89542468               -mov dword ptr [esp + 0x68], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edx;
    // 004a3f76  66895c241e             -mov word ptr [esp + 0x1e], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(30) /* 0x1e */) = cpu.bx;
    // 004a3f7b  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004a3f7d  66894c241c             -mov word ptr [esp + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 004a3f82  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004a3f86  e978000000             -jmp 0x4a4003
    goto L_0x004a4003;
L_0x004a3f8b:
    // 004a3f8b  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004a3f8d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a3f8f  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004a3f93  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 004a3f97  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a3f99  e87a020000             -call 0x4a4218
    cpu.esp -= 4;
    sub_4a4218(app, cpu);
    if (cpu.terminate) return;
    // 004a3f9e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a3fa0  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004a3fa4  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a3fa6  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004a3fa8  47                     -inc edi
    (cpu.edi)++;
    // 004a3fa9  88442415               -mov byte ptr [esp + 0x15], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) = cpu.al;
    // 004a3fad  897c2468               -mov dword ptr [esp + 0x68], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
    // 004a3fb1  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004a3fb3  0f8453020000           -je 0x4a420c
    if (cpu.flags.zf)
    {
        goto L_0x004a420c;
    }
    // 004a3fb9  3c6e                   +cmp al, 0x6e
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(110 /*0x6e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a3fbb  0f85d8000000           -jne 0x4a4099
    if (!cpu.flags.zf)
    {
        goto L_0x004a4099;
    }
    // 004a3fc1  8a74241e               -mov dh, byte ptr [esp + 0x1e]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */);
    // 004a3fc5  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 004a3fc8  7461                   -je 0x4a402b
    if (cpu.flags.zf)
    {
        goto L_0x004a402b;
    }
    // 004a3fca  f6c680                 +test dh, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 128 /*0x80*/));
    // 004a3fcd  7413                   -je 0x4a3fe2
    if (cpu.flags.zf)
    {
        goto L_0x004a3fe2;
    }
    // 004a3fcf  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a3fd1  83c208                 +add edx, 8
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
    // 004a3fd4  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a3fd6  c452f8                 -les edx, ptr [edx - 8]
    NFS2_ASSERT(false);
L_0x004a3fd9:
    // 004a3fd9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a3fdd  268902                 -mov dword ptr es:[edx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.eax;
    // 004a3fe0  eb21                   -jmp 0x4a4003
    goto L_0x004a4003;
L_0x004a3fe2:
    // 004a3fe2  f6c640                 +test dh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 64 /*0x40*/));
    // 004a3fe5  740c                   -je 0x4a3ff3
    if (cpu.flags.zf)
    {
        goto L_0x004a3ff3;
    }
    // 004a3fe7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a3fe9  83c004                 +add eax, 4
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
    // 004a3fec  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a3fee  8b50fc                 -mov edx, dword ptr [eax - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004a3ff1  eb0a                   -jmp 0x4a3ffd
    goto L_0x004a3ffd;
L_0x004a3ff3:
    // 004a3ff3  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 004a3ff5  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3ff8  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004a3ffa  8b57fc                 -mov edx, dword ptr [edi - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
L_0x004a3ffd:
    // 004a3ffd  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a4001  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004a4003:
    // 004a4003  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004a4007  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 004a4009  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 004a400b  0f84fb010000           -je 0x4a420c
    if (cpu.flags.zf)
    {
        goto L_0x004a420c;
    }
    // 004a4011  8d7801                 -lea edi, [eax + 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a4014  80ff25                 +cmp bh, 0x25
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(37 /*0x25*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4017  0f846effffff           -je 0x4a3f8b
    if (cpu.flags.zf)
    {
        goto L_0x004a3f8b;
    }
    // 004a401d  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a401f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a4021  88fa                   -mov dl, bh
    cpu.dl = cpu.bh;
    // 004a4023  897c2468               -mov dword ptr [esp + 0x68], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
    // 004a4027  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a4029  ebd8                   -jmp 0x4a4003
    goto L_0x004a4003;
L_0x004a402b:
    // 004a402b  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 004a402e  743d                   -je 0x4a406d
    if (cpu.flags.zf)
    {
        goto L_0x004a406d;
    }
    // 004a4030  f6c680                 +test dh, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 128 /*0x80*/));
    // 004a4033  7414                   -je 0x4a4049
    if (cpu.flags.zf)
    {
        goto L_0x004a4049;
    }
    // 004a4035  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a4037  83c108                 +add ecx, 8
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a403a  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004a403c  c451f8                 -les edx, ptr [ecx - 8]
    NFS2_ASSERT(false);
    // 004a403f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a4043  66268902               -mov word ptr es:[edx], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.edx) = cpu.ax;
    // 004a4047  ebba                   -jmp 0x4a4003
    goto L_0x004a4003;
L_0x004a4049:
    // 004a4049  f6c640                 +test dh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 64 /*0x40*/));
    // 004a404c  7413                   -je 0x4a4061
    if (cpu.flags.zf)
    {
        goto L_0x004a4061;
    }
    // 004a404e  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a4050  83c304                 +add ebx, 4
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
    // 004a4053  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 004a4055  8b53fc                 -mov edx, dword ptr [ebx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x004a4058:
    // 004a4058  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a405c  668902                 -mov word ptr [edx], ax
    app->getMemory<x86::reg16>(cpu.edx) = cpu.ax;
    // 004a405f  eba2                   -jmp 0x4a4003
    goto L_0x004a4003;
L_0x004a4061:
    // 004a4061  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a4063  83c204                 +add edx, 4
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
    // 004a4066  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a4068  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004a406b  ebeb                   -jmp 0x4a4058
    goto L_0x004a4058;
L_0x004a406d:
    // 004a406d  f6c680                 +test dh, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 128 /*0x80*/));
    // 004a4070  740f                   -je 0x4a4081
    if (cpu.flags.zf)
    {
        goto L_0x004a4081;
    }
    // 004a4072  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a4074  83c008                 +add eax, 8
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
    // 004a4077  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a4079  c450f8                 -les edx, ptr [eax - 8]
    NFS2_ASSERT(false);
    // 004a407c  e958ffffff             -jmp 0x4a3fd9
    goto L_0x004a3fd9;
L_0x004a4081:
    // 004a4081  f6c640                 +test dh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 64 /*0x40*/));
    // 004a4084  0f8569ffffff           -jne 0x4a3ff3
    if (!cpu.flags.zf)
    {
        goto L_0x004a3ff3;
    }
    // 004a408a  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a408c  83c104                 +add ecx, 4
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
    // 004a408f  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004a4091  8b51fc                 -mov edx, dword ptr [ecx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 004a4094  e964ffffff             -jmp 0x4a3ffd
    goto L_0x004a3ffd;
L_0x004a4099:
    // 004a4099  8d4c246c               -lea ecx, [esp + 0x6c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 004a409d  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004a409f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a40a1  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004a40a5  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 004a40a9  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004a40ad  e878050000             -call 0x4a462a
    cpu.esp -= 4;
    sub_4a462a(app, cpu);
    if (cpu.terminate) return;
    // 004a40b2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a40b4  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004a40b8  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004a40ba  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a40bc  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a40c0  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a40c4  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a40c8  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a40ca  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a40ce  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a40d0  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a40d4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a40d6  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a40da  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a40dc  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a40e0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a40e2  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a40e4  8a64241e               -mov ah, byte ptr [esp + 0x1e]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */);
    // 004a40e8  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a40ec  f6c408                 +test ah, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 8 /*0x8*/));
    // 004a40ef  751d                   -jne 0x4a410e
    if (!cpu.flags.zf)
    {
        goto L_0x004a410e;
    }
    // 004a40f1  807c241620             +cmp byte ptr [esp + 0x16], 0x20
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(22) /* 0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a40f6  7516                   -jne 0x4a410e
    if (!cpu.flags.zf)
    {
        goto L_0x004a410e;
    }
L_0x004a40f8:
    // 004a40f8  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004a40fd  7e0f                   -jle 0x4a410e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a410e;
    }
    // 004a40ff  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004a4104  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a4106  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a4108  ff4c2404               +dec dword ptr [esp + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a410c  ebea                   -jmp 0x4a40f8
    goto L_0x004a40f8;
L_0x004a410e:
    // 004a410e  8d5c2438               -lea ebx, [esp + 0x38]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
L_0x004a4112:
    // 004a4112  837c242000             +cmp dword ptr [esp + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4117  7e14                   -jle 0x4a412d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a412d;
    }
    // 004a4119  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a411b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a411d  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004a411f  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a4121  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a4125  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a4126  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a4127  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004a412b  ebe5                   -jmp 0x4a4112
    goto L_0x004a4112;
L_0x004a412d:
    // 004a412d  837c242400             +cmp dword ptr [esp + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4132  7e0f                   -jle 0x4a4143
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4143;
    }
    // 004a4134  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 004a4139  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a413b  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a413d  ff4c2424               +dec dword ptr [esp + 0x24]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a4141  ebea                   -jmp 0x4a412d
    goto L_0x004a412d;
L_0x004a4143:
    // 004a4143  8a742415               -mov dh, byte ptr [esp + 0x15]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */);
    // 004a4147  80fe73                 +cmp dh, 0x73
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(115 /*0x73*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a414a  7532                   -jne 0x4a417e
    if (!cpu.flags.zf)
    {
        goto L_0x004a417e;
    }
    // 004a414c  f644241e20             +test byte ptr [esp + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 004a4151  740f                   -je 0x4a4162
    if (cpu.flags.zf)
    {
        goto L_0x004a4162;
    }
L_0x004a4153:
    // 004a4153  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004a4155  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004a4157  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004a4159  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a415b  e872040000             -call 0x4a45d2
    cpu.esp -= 4;
    sub_4a45d2(app, cpu);
    if (cpu.terminate) return;
    // 004a4160  eb3d                   -jmp 0x4a419f
    goto L_0x004a419f;
L_0x004a4162:
    // 004a4162  837c242800             +cmp dword ptr [esp + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4167  7e36                   -jle 0x4a419f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a419f;
    }
    // 004a4169  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a416b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a416d  268a17                 -mov dl, byte ptr es:[edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.edi);
    // 004a4170  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a4172  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a4176  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a4177  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a4178  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004a417c  ebe4                   -jmp 0x4a4162
    goto L_0x004a4162;
L_0x004a417e:
    // 004a417e  80fe53                 +cmp dh, 0x53
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4181  74d0                   -je 0x4a4153
    if (cpu.flags.zf)
    {
        goto L_0x004a4153;
    }
L_0x004a4183:
    // 004a4183  837c242800             +cmp dword ptr [esp + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4188  7e15                   -jle 0x4a419f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a419f;
    }
    // 004a418a  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a418c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a418e  268a17                 -mov dl, byte ptr es:[edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.edi);
    // 004a4191  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a4193  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a4197  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a4198  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a4199  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004a419d  ebe4                   -jmp 0x4a4183
    goto L_0x004a4183;
L_0x004a419f:
    // 004a419f  837c242c00             +cmp dword ptr [esp + 0x2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a41a4  7e0f                   -jle 0x4a41b5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a41b5;
    }
    // 004a41a6  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 004a41ab  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a41ad  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a41af  ff4c242c               +dec dword ptr [esp + 0x2c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a41b3  ebea                   -jmp 0x4a419f
    goto L_0x004a419f;
L_0x004a41b5:
    // 004a41b5  837c243000             +cmp dword ptr [esp + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a41ba  7e15                   -jle 0x4a41d1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a41d1;
    }
    // 004a41bc  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a41be  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a41c0  268a17                 -mov dl, byte ptr es:[edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.edi);
    // 004a41c3  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a41c5  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a41c9  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a41ca  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a41cb  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 004a41cf  ebe4                   -jmp 0x4a41b5
    goto L_0x004a41b5;
L_0x004a41d1:
    // 004a41d1  837c243400             +cmp dword ptr [esp + 0x34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a41d6  7e0f                   -jle 0x4a41e7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a41e7;
    }
    // 004a41d8  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 004a41dd  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a41df  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a41e1  ff4c2434               +dec dword ptr [esp + 0x34]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a41e5  ebea                   -jmp 0x4a41d1
    goto L_0x004a41d1;
L_0x004a41e7:
    // 004a41e7  f644241e08             +test byte ptr [esp + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) & 8 /*0x8*/));
    // 004a41ec  0f8411feffff           -je 0x4a4003
    if (cpu.flags.zf)
    {
        goto L_0x004a4003;
    }
L_0x004a41f2:
    // 004a41f2  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004a41f7  0f8e06feffff           -jle 0x4a4003
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4003;
    }
    // 004a41fd  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004a4202  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a4204  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a4206  ff4c2404               +dec dword ptr [esp + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a420a  ebe6                   -jmp 0x4a41f2
    goto L_0x004a41f2;
L_0x004a420c:
    // 004a420c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a4210  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004a4213  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4214  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a4215  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4216  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4217  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a4218(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4218  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a4219  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a421a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a421b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a421d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a421f  c6431620               -mov byte ptr [ebx + 0x16], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = 32 /*0x20*/;
    // 004a4223  e83d010000             -call 0x4a4365
    cpu.esp -= 4;
    sub_4a4365(app, cpu);
    if (cpu.terminate) return;
    // 004a4228  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a422f  80382a                 +cmp byte ptr [eax], 0x2a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4232  7524                   -jne 0x4a4258
    if (!cpu.flags.zf)
    {
        goto L_0x004a4258;
    }
    // 004a4234  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a4236  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a4239  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a423b  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004a423e  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a4241  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a4243  7d10                   -jge 0x4a4255
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a4255;
    }
    // 004a4245  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a4247  8a6b1e                 -mov ch, byte ptr [ebx + 0x1e]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 004a424a  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 004a424c  80cd08                 +or ch, 8
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004a424f  897b04                 -mov dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004a4252  886b1e                 -mov byte ptr [ebx + 0x1e], ch
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.ch;
L_0x004a4255:
    // 004a4255  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a4256  eb1f                   -jmp 0x4a4277
    goto L_0x004a4277;
L_0x004a4258:
    // 004a4258  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a425a  80fa30                 +cmp dl, 0x30
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
    // 004a425d  7218                   -jb 0x4a4277
    if (cpu.flags.cf)
    {
        goto L_0x004a4277;
    }
    // 004a425f  80fa39                 +cmp dl, 0x39
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
    // 004a4262  7713                   -ja 0x4a4277
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a4277;
    }
    // 004a4264  6b4b040a               -imul ecx, dword ptr [ebx + 4], 0xa
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004a4268  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a426a  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a426c  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004a426f  01d1                   +add ecx, edx
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
    // 004a4271  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a4272  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a4275  ebe1                   -jmp 0x4a4258
    goto L_0x004a4258;
L_0x004a4277:
    // 004a4277  c74308ffffffff         -mov dword ptr [ebx + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 004a427e  80382e                 +cmp byte ptr [eax], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4281  7551                   -jne 0x4a42d4
    if (!cpu.flags.zf)
    {
        goto L_0x004a42d4;
    }
    // 004a4283  40                     -inc eax
    (cpu.eax)++;
    // 004a4284  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004a428b  80382a                 +cmp byte ptr [eax], 0x2a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a428e  751b                   -jne 0x4a42ab
    if (!cpu.flags.zf)
    {
        goto L_0x004a42ab;
    }
    // 004a4290  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a4292  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a4295  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a4297  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004a429a  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a429d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a429f  7d07                   -jge 0x4a42a8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a42a8;
    }
    // 004a42a1  c74308ffffffff         -mov dword ptr [ebx + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
L_0x004a42a8:
    // 004a42a8  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a42a9  eb1f                   -jmp 0x4a42ca
    goto L_0x004a42ca;
L_0x004a42ab:
    // 004a42ab  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a42ad  80fa30                 +cmp dl, 0x30
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
    // 004a42b0  7218                   -jb 0x4a42ca
    if (cpu.flags.cf)
    {
        goto L_0x004a42ca;
    }
    // 004a42b2  80fa39                 +cmp dl, 0x39
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
    // 004a42b5  7713                   -ja 0x4a42ca
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a42ca;
    }
    // 004a42b7  6b4b080a               -imul ecx, dword ptr [ebx + 8], 0xa
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004a42bb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a42bd  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a42bf  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004a42c2  01d1                   +add ecx, edx
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
    // 004a42c4  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a42c5  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004a42c8  ebe1                   -jmp 0x4a42ab
    goto L_0x004a42ab;
L_0x004a42ca:
    // 004a42ca  837b08ff               +cmp dword ptr [ebx + 8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a42ce  7404                   -je 0x4a42d4
    if (cpu.flags.zf)
    {
        goto L_0x004a42d4;
    }
    // 004a42d0  c6431620               -mov byte ptr [ebx + 0x16], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = 32 /*0x20*/;
L_0x004a42d4:
    // 004a42d4  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a42d6  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a42d9  80fa4e                 +cmp dl, 0x4e
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(78 /*0x4e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a42dc  721f                   -jb 0x4a42fd
    if (cpu.flags.cf)
    {
        goto L_0x004a42fd;
    }
    // 004a42de  0f8677000000           -jbe 0x4a435b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a435b;
    }
    // 004a42e4  80fa6c                 +cmp dl, 0x6c
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
    // 004a42e7  720b                   -jb 0x4a42f4
    if (cpu.flags.cf)
    {
        goto L_0x004a42f4;
    }
    // 004a42e9  762b                   -jbe 0x4a4316
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a4316;
    }
    // 004a42eb  80fa77                 +cmp dl, 0x77
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
    // 004a42ee  7426                   -je 0x4a4316
    if (cpu.flags.zf)
    {
        goto L_0x004a4316;
    }
    // 004a42f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a42f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a42f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a42f3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a42f4:
    // 004a42f4  80fa68                 +cmp dl, 0x68
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
    // 004a42f7  742b                   -je 0x4a4324
    if (cpu.flags.zf)
    {
        goto L_0x004a4324;
    }
    // 004a42f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a42fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a42fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a42fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a42fd:
    // 004a42fd  80fa49                 +cmp dl, 0x49
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
    // 004a4300  720b                   -jb 0x4a430d
    if (cpu.flags.cf)
    {
        goto L_0x004a430d;
    }
    // 004a4302  7626                   -jbe 0x4a432a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a432a;
    }
    // 004a4304  80fa4c                 +cmp dl, 0x4c
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
    // 004a4307  743d                   -je 0x4a4346
    if (cpu.flags.zf)
    {
        goto L_0x004a4346;
    }
    // 004a4309  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a430a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a430b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a430c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a430d:
    // 004a430d  80fa46                 +cmp dl, 0x46
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4310  7443                   -je 0x4a4355
    if (cpu.flags.zf)
    {
        goto L_0x004a4355;
    }
    // 004a4312  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4313  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4314  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4315  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4316:
    // 004a4316  8a4b1e                 -mov cl, byte ptr [ebx + 0x1e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 004a4319  80c920                 -or cl, 0x20
    cpu.cl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004a431c  40                     -inc eax
    (cpu.eax)++;
    // 004a431d  884b1e                 -mov byte ptr [ebx + 0x1e], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.cl;
    // 004a4320  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4321  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4322  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4323  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4324:
    // 004a4324  804b1e10               +or byte ptr [ebx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 004a4328  eb35                   -jmp 0x4a435f
    goto L_0x004a435f;
L_0x004a432a:
    // 004a432a  80780136               +cmp byte ptr [eax + 1], 0x36
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(54 /*0x36*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a432e  7531                   -jne 0x4a4361
    if (!cpu.flags.zf)
    {
        goto L_0x004a4361;
    }
    // 004a4330  80780234               +cmp byte ptr [eax + 2], 0x34
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4334  752b                   -jne 0x4a4361
    if (!cpu.flags.zf)
    {
        goto L_0x004a4361;
    }
    // 004a4336  8a6b1f                 -mov ch, byte ptr [ebx + 0x1f]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */);
    // 004a4339  80cd01                 -or ch, 1
    cpu.ch |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004a433c  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a433f  886b1f                 -mov byte ptr [ebx + 0x1f], ch
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */) = cpu.ch;
    // 004a4342  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4343  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4344  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4345  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4346:
    // 004a4346  8a531f                 -mov dl, byte ptr [ebx + 0x1f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */);
    // 004a4349  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004a434c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a434e  88531f                 -mov byte ptr [ebx + 0x1f], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */) = cpu.dl;
    // 004a4351  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4352  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4353  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4354  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4355:
    // 004a4355  804b1e80               +or byte ptr [ebx + 0x1e], 0x80
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 004a4359  eb04                   -jmp 0x4a435f
    goto L_0x004a435f;
L_0x004a435b:
    // 004a435b  804b1e40               -or byte ptr [ebx + 0x1e], 0x40
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x004a435f:
    // 004a435f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004a4361:
    // 004a4361  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4362  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4363  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4364  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a4365(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4365  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4366  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a4367  66c7421e0000           -mov word ptr [edx + 0x1e], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */) = 0 /*0x0*/;
L_0x004a436d:
    // 004a436d  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a436f  80fb2d                 +cmp bl, 0x2d
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4372  7506                   -jne 0x4a437a
    if (!cpu.flags.zf)
    {
        goto L_0x004a437a;
    }
    // 004a4374  804a1e08               +or byte ptr [edx + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004a4378  eb42                   -jmp 0x4a43bc
    goto L_0x004a43bc;
L_0x004a437a:
    // 004a437a  80fb23                 +cmp bl, 0x23
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(35 /*0x23*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a437d  7506                   -jne 0x4a4385
    if (!cpu.flags.zf)
    {
        goto L_0x004a4385;
    }
    // 004a437f  804a1e01               +or byte ptr [edx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004a4383  eb37                   -jmp 0x4a43bc
    goto L_0x004a43bc;
L_0x004a4385:
    // 004a4385  80fb2b                 +cmp bl, 0x2b
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4388  7513                   -jne 0x4a439d
    if (!cpu.flags.zf)
    {
        goto L_0x004a439d;
    }
    // 004a438a  8a6a1e                 -mov ch, byte ptr [edx + 0x1e]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 004a438d  80cd04                 -or ch, 4
    cpu.ch |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004a4390  88eb                   -mov bl, ch
    cpu.bl = cpu.ch;
    // 004a4392  886a1e                 -mov byte ptr [edx + 0x1e], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.ch;
    // 004a4395  80e3fd                 +and bl, 0xfd
    cpu.clear_co();
    cpu.set_szp((cpu.bl &= x86::reg8(x86::sreg8(253 /*0xfd*/))));
    // 004a4398  885a1e                 -mov byte ptr [edx + 0x1e], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.bl;
    // 004a439b  eb1f                   -jmp 0x4a43bc
    goto L_0x004a43bc;
L_0x004a439d:
    // 004a439d  80fb20                 +cmp bl, 0x20
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a43a0  7512                   -jne 0x4a43b4
    if (!cpu.flags.zf)
    {
        goto L_0x004a43b4;
    }
    // 004a43a2  8a7a1e                 -mov bh, byte ptr [edx + 0x1e]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 004a43a5  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 004a43a8  7512                   -jne 0x4a43bc
    if (!cpu.flags.zf)
    {
        goto L_0x004a43bc;
    }
    // 004a43aa  88f9                   -mov cl, bh
    cpu.cl = cpu.bh;
    // 004a43ac  80c902                 +or cl, 2
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 004a43af  884a1e                 -mov byte ptr [edx + 0x1e], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.cl;
    // 004a43b2  eb08                   -jmp 0x4a43bc
    goto L_0x004a43bc;
L_0x004a43b4:
    // 004a43b4  80fb30                 +cmp bl, 0x30
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a43b7  7506                   -jne 0x4a43bf
    if (!cpu.flags.zf)
    {
        goto L_0x004a43bf;
    }
    // 004a43b9  885a16                 -mov byte ptr [edx + 0x16], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(22) /* 0x16 */) = cpu.bl;
L_0x004a43bc:
    // 004a43bc  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a43bd  ebae                   -jmp 0x4a436d
    goto L_0x004a436d;
L_0x004a43bf:
    // 004a43bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a43c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a43c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a43c2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a43c2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a43c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a43c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a43c5  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a43c6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a43c8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a43ca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a43cc  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 004a43ce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a43d0:
    // 004a43d0  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a43d2  268a1e                 -mov bl, byte ptr es:[esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ees + cpu.esi);
    // 004a43d5  42                     -inc edx
    (cpu.edx)++;
    // 004a43d6  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a43d8  7407                   -je 0x4a43e1
    if (cpu.flags.zf)
    {
        goto L_0x004a43e1;
    }
    // 004a43da  39f8                   +cmp eax, edi
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
    // 004a43dc  7403                   -je 0x4a43e1
    if (cpu.flags.zf)
    {
        goto L_0x004a43e1;
    }
    // 004a43de  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a43df  ebef                   -jmp 0x4a43d0
    goto L_0x004a43d0;
L_0x004a43e1:
    // 004a43e1  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a43e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a43e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a43e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a43e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a43e6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a43e6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a43e7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a43e8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a43e9  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a43ec  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a43ee  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004a43f0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a43f2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a43f4  83feff                 +cmp esi, -1
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
    // 004a43f7  7525                   -jne 0x4a441e
    if (!cpu.flags.zf)
    {
        goto L_0x004a441e;
    }
L_0x004a43f9:
    // 004a43f9  66268b33               -mov si, word ptr es:[ebx]
    cpu.si = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
    // 004a43fd  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 004a4400  7418                   -je 0x4a441a
    if (cpu.flags.zf)
    {
        goto L_0x004a441a;
    }
    // 004a4402  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4404  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a4406  6689f2                 -mov dx, si
    cpu.dx = cpu.si;
    // 004a4409  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a440c  e8227b0000             -call 0x4abf33
    cpu.esp -= 4;
    sub_4abf33(app, cpu);
    if (cpu.terminate) return;
    // 004a4411  83f8ff                 +cmp eax, -1
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
    // 004a4414  74e3                   -je 0x4a43f9
    if (cpu.flags.zf)
    {
        goto L_0x004a43f9;
    }
    // 004a4416  01c1                   +add ecx, eax
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
    // 004a4418  ebdf                   -jmp 0x4a43f9
    goto L_0x004a43f9;
L_0x004a441a:
    // 004a441a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a441c  eb2a                   -jmp 0x4a4448
    goto L_0x004a4448;
L_0x004a441e:
    // 004a441e  6626833b00             +cmp word ptr es:[ebx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a4423  741d                   -je 0x4a4442
    if (cpu.flags.zf)
    {
        goto L_0x004a4442;
    }
    // 004a4425  39f1                   +cmp ecx, esi
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
    // 004a4427  7f19                   -jg 0x4a4442
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a4442;
    }
    // 004a4429  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a442b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a442d  66268b13               -mov dx, word ptr es:[ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
    // 004a4431  e8fd7a0000             -call 0x4abf33
    cpu.esp -= 4;
    sub_4abf33(app, cpu);
    if (cpu.terminate) return;
    // 004a4436  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a4439  83f8ff                 +cmp eax, -1
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
    // 004a443c  74e0                   -je 0x4a441e
    if (cpu.flags.zf)
    {
        goto L_0x004a441e;
    }
    // 004a443e  01c1                   +add ecx, eax
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
    // 004a4440  ebdc                   -jmp 0x4a441e
    goto L_0x004a441e;
L_0x004a4442:
    // 004a4442  39f1                   +cmp ecx, esi
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
    // 004a4444  7ed4                   -jle 0x4a441a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a441a;
    }
    // 004a4446  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a4448:
    // 004a4448  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a444b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a444c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a444d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a444e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a444f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a444f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a4450  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4451  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4452  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a4453  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a4456  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004a4458  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004a445b  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004a4460  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004a4462  e84a7b0000             -call 0x4abfb1
    cpu.esp -= 4;
    sub_4abfb1(app, cpu);
    if (cpu.terminate) return;
    // 004a4467  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a4468  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a446a  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a446c  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a446e  49                     -dec ecx
    (cpu.ecx)--;
    // 004a446f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a4471  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 004a4473  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004a4475  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a4476  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a4477  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a447a  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004a447c  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a447d  8d1429                 -lea edx, [ecx + ebp]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 004a4480  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 004a4483  eb07                   -jmp 0x4a448c
    goto L_0x004a448c;
L_0x004a4485:
    // 004a4485  4a                     -dec edx
    (cpu.edx)--;
    // 004a4486  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a4488  48                     -dec eax
    (cpu.eax)--;
    // 004a4489  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004a448b  4b                     -dec ebx
    (cpu.ebx)--;
L_0x004a448c:
    // 004a448c  39f2                   +cmp edx, esi
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
    // 004a448e  75f5                   -jne 0x4a4485
    if (!cpu.flags.zf)
    {
        goto L_0x004a4485;
    }
    // 004a4490  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
L_0x004a4493:
    // 004a4493  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4495  7c07                   -jl 0x4a449e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a449e;
    }
    // 004a4497  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a4498  c60230                 -mov byte ptr [edx], 0x30
    app->getMemory<x86::reg8>(cpu.edx) = 48 /*0x30*/;
    // 004a449b  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a449c  ebf5                   -jmp 0x4a4493
    goto L_0x004a4493;
L_0x004a449e:
    // 004a449e  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 004a44a1  c6450000               -mov byte ptr [ebp], 0
    app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
    // 004a44a5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a44a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a44a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a44aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a44ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a44ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a44ad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a44ad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a44ae  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a44af  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a44b0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a44b3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a44b5  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a44b7  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a44ba  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a44bc  7d0b                   -jge 0x4a44c9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a44c9;
    }
    // 004a44be  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004a44c0  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a44c3  c6002d                 -mov byte ptr [eax], 0x2d
    app->getMemory<x86::reg8>(cpu.eax) = 45 /*0x2d*/;
    // 004a44c6  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x004a44c9:
    // 004a44c9  837e08ff               +cmp dword ptr [esi + 8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a44cd  7507                   -jne 0x4a44d6
    if (!cpu.flags.zf)
    {
        goto L_0x004a44d6;
    }
    // 004a44cf  c7460804000000         -mov dword ptr [esi + 8], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 4 /*0x4*/;
L_0x004a44d6:
    // 004a44d6  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004a44db  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a44dd  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a44df  668b442402             -mov ax, word ptr [esp + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 004a44e4  e8c87a0000             -call 0x4abfb1
    cpu.esp -= 4;
    sub_4abfb1(app, cpu);
    if (cpu.terminate) return;
    // 004a44e9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x004a44eb:
    // 004a44eb  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a44ed  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004a44f0  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004a44f2  7404                   -je 0x4a44f8
    if (cpu.flags.zf)
    {
        goto L_0x004a44f8;
    }
    // 004a44f4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a44f6  ebf3                   -jmp 0x4a44eb
    goto L_0x004a44eb;
L_0x004a44f8:
    // 004a44f8  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a44fc  742c                   -je 0x4a452a
    if (cpu.flags.zf)
    {
        goto L_0x004a452a;
    }
    // 004a44fe  c6012e                 -mov byte ptr [ecx], 0x2e
    app->getMemory<x86::reg8>(cpu.ecx) = 46 /*0x2e*/;
    // 004a4501  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a4503  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a4505  eb1b                   -jmp 0x4a4522
    goto L_0x004a4522;
L_0x004a4507:
    // 004a4507  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4509  6689542402             -mov word ptr [esp + 2], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 004a450e  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a4511  6bd70a                 -imul edx, edi, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004a4514  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a4517  8a542402               -mov dl, byte ptr [esp + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 004a451b  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004a451e  40                     -inc eax
    (cpu.eax)++;
    // 004a451f  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 004a4521  41                     -inc ecx
    (cpu.ecx)++;
L_0x004a4522:
    // 004a4522  3b4608                 +cmp eax, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4525  7ce0                   -jl 0x4a4507
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4507;
    }
    // 004a4527  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
L_0x004a452a:
    // 004a452a  f644240180             +test byte ptr [esp + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) & 128 /*0x80*/));
    // 004a452f  7450                   -je 0x4a4581
    if (cpu.flags.zf)
    {
        goto L_0x004a4581;
    }
L_0x004a4531:
    // 004a4531  39d9                   +cmp ecx, ebx
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
    // 004a4533  7532                   -jne 0x4a4567
    if (!cpu.flags.zf)
    {
        goto L_0x004a4567;
    }
    // 004a4535  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a4538  c60331                 -mov byte ptr [ebx], 0x31
    app->getMemory<x86::reg8>(cpu.ebx) = 49 /*0x31*/;
L_0x004a453b:
    // 004a453b  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a453d  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004a4540  80fa30                 +cmp dl, 0x30
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
    // 004a4543  7504                   -jne 0x4a4549
    if (!cpu.flags.zf)
    {
        goto L_0x004a4549;
    }
    // 004a4545  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a4547  ebf2                   -jmp 0x4a453b
    goto L_0x004a453b;
L_0x004a4549:
    // 004a4549  80fa2e                 +cmp dl, 0x2e
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
    // 004a454c  7510                   -jne 0x4a455e
    if (!cpu.flags.zf)
    {
        goto L_0x004a455e;
    }
    // 004a454e  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 004a4551  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a4554  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x004a4556:
    // 004a4556  803930                 +cmp byte ptr [ecx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4559  7503                   -jne 0x4a455e
    if (!cpu.flags.zf)
    {
        goto L_0x004a455e;
    }
    // 004a455b  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a455c  ebf8                   -jmp 0x4a4556
    goto L_0x004a4556;
L_0x004a455e:
    // 004a455e  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 004a4561  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a4562  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 004a4565  eb1a                   -jmp 0x4a4581
    goto L_0x004a4581;
L_0x004a4567:
    // 004a4567  49                     -dec ecx
    (cpu.ecx)--;
    // 004a4568  80392e                 +cmp byte ptr [ecx], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a456b  7501                   -jne 0x4a456e
    if (!cpu.flags.zf)
    {
        goto L_0x004a456e;
    }
    // 004a456d  49                     -dec ecx
    (cpu.ecx)--;
L_0x004a456e:
    // 004a456e  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a4570  3c39                   +cmp al, 0x39
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
    // 004a4572  7408                   -je 0x4a457c
    if (cpu.flags.zf)
    {
        goto L_0x004a457c;
    }
    // 004a4574  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 004a4576  fec4                   +inc ah
    {
        x86::reg8& tmp = cpu.ah;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 004a4578  8821                   -mov byte ptr [ecx], ah
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.ah;
    // 004a457a  eb05                   -jmp 0x4a4581
    goto L_0x004a4581;
L_0x004a457c:
    // 004a457c  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 004a457f  ebb0                   -jmp 0x4a4531
    goto L_0x004a4531;
L_0x004a4581:
    // 004a4581  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a4584  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4585  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4586  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4587  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a4588(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4588  ff1588d64c00           -call dword ptr [0x4cd688]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5035656) /* 0x4cd688 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a458e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a458f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a458f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4590  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a4591  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a4592  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4593  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4594  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a4595  f6401e08               +test byte ptr [eax + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */) & 8 /*0x8*/));
    // 004a4599  7530                   -jne 0x4a45cb
    if (!cpu.flags.zf)
    {
        goto L_0x004a45cb;
    }
    // 004a459b  80781630               +cmp byte ptr [eax + 0x16], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a459f  752a                   -jne 0x4a45cb
    if (!cpu.flags.zf)
    {
        goto L_0x004a45cb;
    }
    // 004a45a1  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a45a4  8b5820                 -mov ebx, dword ptr [eax + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a45a7  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004a45aa  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a45ac  8b7028                 -mov esi, dword ptr [eax + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004a45af  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a45b1  8b782c                 -mov edi, dword ptr [eax + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004a45b4  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a45b6  8b6830                 -mov ebp, dword ptr [eax + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 004a45b9  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004a45bb  8b5834                 -mov ebx, dword ptr [eax + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004a45be  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a45c0  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a45c2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a45c4  7e05                   -jle 0x4a45cb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a45cb;
    }
    // 004a45c6  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a45c8  894824                 -mov dword ptr [eax + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ecx;
L_0x004a45cb:
    // 004a45cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a45d2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a45d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a45d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a45d4  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a45d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a45d6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a45d9  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004a45db  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a45dd  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
L_0x004a45df:
    // 004a45df  837b2800               +cmp dword ptr [ebx + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a45e3  7e3d                   -jle 0x4a4622
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4622;
    }
    // 004a45e5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a45e7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a45e9  66268b16               -mov dx, word ptr es:[esi]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ees + cpu.esi);
    // 004a45ed  e841790000             -call 0x4abf33
    cpu.esp -= 4;
    sub_4abf33(app, cpu);
    if (cpu.terminate) return;
    // 004a45f2  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a45f5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a45f7  83f8ff                 +cmp eax, -1
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
    // 004a45fa  74e3                   -je 0x4a45df
    if (cpu.flags.zf)
    {
        goto L_0x004a45df;
    }
    // 004a45fc  3b4328                 +cmp eax, dword ptr [ebx + 0x28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a45ff  7f1a                   -jg 0x4a461b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a461b;
    }
    // 004a4601  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
L_0x004a4603:
    // 004a4603  4f                     -dec edi
    (cpu.edi)--;
    // 004a4604  83ffff                 +cmp edi, -1
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
    // 004a4607  74d6                   -je 0x4a45df
    if (cpu.flags.zf)
    {
        goto L_0x004a45df;
    }
    // 004a4609  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a460b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a460d  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a460f  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a4611  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004a4614  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a4615  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a4616  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004a4619  ebe8                   -jmp 0x4a4603
    goto L_0x004a4603;
L_0x004a461b:
    // 004a461b  c7432800000000         -mov dword ptr [ebx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
L_0x004a4622:
    // 004a4622  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a4625  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4626  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a4627  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4628  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4629  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a462a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a462a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a462b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a462c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a462d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a462e  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a4631  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a4633  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a4635  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a4637  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a4639  c7432000000000         -mov dword ptr [ebx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004a4640  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004a4647  c7432800000000         -mov dword ptr [ebx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004a464e  c7432c00000000         -mov dword ptr [ebx + 0x2c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 004a4655  c7433000000000         -mov dword ptr [ebx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 004a465c  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004a465e  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 004a4661  c7433400000000         -mov dword ptr [ebx + 0x34], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004a4668  3c69                   +cmp al, 0x69
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
    // 004a466a  7219                   -jb 0x4a4685
    if (cpu.flags.cf)
    {
        goto L_0x004a4685;
    }
    // 004a466c  0f8686000000           -jbe 0x4a46f8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a46f8;
    }
    // 004a4672  3c75                   +cmp al, 0x75
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(117 /*0x75*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4674  720b                   -jb 0x4a4681
    if (cpu.flags.cf)
    {
        goto L_0x004a4681;
    }
    // 004a4676  7620                   -jbe 0x4a4698
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a4698;
    }
    // 004a4678  3c78                   +cmp al, 0x78
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x004a467a:
    // 004a467a  741c                   -je 0x4a4698
    if (cpu.flags.zf)
    {
        goto L_0x004a4698;
    }
    // 004a467c  e956010000             -jmp 0x4a47d7
    goto L_0x004a47d7;
L_0x004a4681:
    // 004a4681  3c6f                   +cmp al, 0x6f
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4683  ebf5                   -jmp 0x4a467a
    goto L_0x004a467a;
L_0x004a4685:
    // 004a4685  3c58                   +cmp al, 0x58
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4687  0f824a010000           -jb 0x4a47d7
    if (cpu.flags.cf)
    {
        goto L_0x004a47d7;
    }
    // 004a468d  7609                   -jbe 0x4a4698
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a4698;
    }
    // 004a468f  3c64                   +cmp al, 0x64
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(100 /*0x64*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4691  7465                   -je 0x4a46f8
    if (cpu.flags.zf)
    {
        goto L_0x004a46f8;
    }
    // 004a4693  e93f010000             -jmp 0x4a47d7
    goto L_0x004a47d7;
L_0x004a4698:
    // 004a4698  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 004a469c  7420                   -je 0x4a46be
    if (cpu.flags.zf)
    {
        goto L_0x004a46be;
    }
    // 004a469e  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a46a0  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a46a3  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004a46a5  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004a46a8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a46ab  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004a46ad  83c504                 +add ebp, 4
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
    // 004a46b0  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004a46b2  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x004a46b5:
    // 004a46b5  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a46b9  e919010000             -jmp 0x4a47d7
    goto L_0x004a47d7;
L_0x004a46be:
    // 004a46be  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 004a46c2  7413                   -je 0x4a46d7
    if (cpu.flags.zf)
    {
        goto L_0x004a46d7;
    }
    // 004a46c4  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004a46c6  83c004                 +add eax, 4
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
    // 004a46c9  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a46cb  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
L_0x004a46ce:
    // 004a46ce  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a46d2  e900010000             -jmp 0x4a47d7
    goto L_0x004a47d7;
L_0x004a46d7:
    // 004a46d7  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004a46d9  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a46dc  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004a46de  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a46e1  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a46e5  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 004a46e9  0f84e8000000           -je 0x4a47d7
    if (cpu.flags.zf)
    {
        goto L_0x004a47d7;
    }
    // 004a46ef  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a46f1  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a46f6  ebd6                   -jmp 0x4a46ce
    goto L_0x004a46ce;
L_0x004a46f8:
    // 004a46f8  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 004a46fc  741d                   -je 0x4a471b
    if (cpu.flags.zf)
    {
        goto L_0x004a471b;
    }
    // 004a46fe  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4700  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a4703  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a4705  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004a4708  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a470b  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a470d  83c304                 +add ebx, 4
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
    // 004a4710  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004a4712  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004a4715  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a4719  eb33                   -jmp 0x4a474e
    goto L_0x004a474e;
L_0x004a471b:
    // 004a471b  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 004a471f  740c                   -je 0x4a472d
    if (cpu.flags.zf)
    {
        goto L_0x004a472d;
    }
    // 004a4721  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4723  83c504                 +add ebp, 4
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
    // 004a4726  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004a4728  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a472b  eb1d                   -jmp 0x4a474a
    goto L_0x004a474a;
L_0x004a472d:
    // 004a472d  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a472f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a4732  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004a4734  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004a4737  8a791e                 -mov bh, byte ptr [ecx + 0x1e]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004a473a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a473e  f6c710                 +test bh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 16 /*0x10*/));
    // 004a4741  740b                   -je 0x4a474e
    if (cpu.flags.zf)
    {
        goto L_0x004a474e;
    }
    // 004a4743  8b442406               -mov eax, dword ptr [esp + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 004a4747  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
L_0x004a474a:
    // 004a474a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004a474e:
    // 004a474e  8a591f                 -mov bl, byte ptr [ecx + 0x1f]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 004a4751  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4753  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 004a4756  7409                   -je 0x4a4761
    if (cpu.flags.zf)
    {
        goto L_0x004a4761;
    }
    // 004a4758  f644240780             +test byte ptr [esp + 7], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) & 128 /*0x80*/));
    // 004a475d  7409                   -je 0x4a4768
    if (cpu.flags.zf)
    {
        goto L_0x004a4768;
    }
    // 004a475f  eb0b                   -jmp 0x4a476c
    goto L_0x004a476c;
L_0x004a4761:
    // 004a4761  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004a4766  7c04                   -jl 0x4a476c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a476c;
    }
L_0x004a4768:
    // 004a4768  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a476a  7444                   -je 0x4a47b0
    if (cpu.flags.zf)
    {
        goto L_0x004a47b0;
    }
L_0x004a476c:
    // 004a476c  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a476f  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a4772  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004a4775  c604062d               -mov byte ptr [esi + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 004a4779  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 004a477d  742b                   -je 0x4a47aa
    if (cpu.flags.zf)
    {
        goto L_0x004a47aa;
    }
    // 004a477f  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a4782  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a4786  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 004a4788  f7d5                   -not ebp
    cpu.ebp = ~cpu.ebp;
    // 004a478a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004a478d  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a4790  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004a4794  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a4797  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4799  7508                   -jne 0x4a47a3
    if (!cpu.flags.zf)
    {
        goto L_0x004a47a3;
    }
    // 004a479b  8d4501                 -lea eax, [ebp + 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004a479e  e912ffffff             -jmp 0x4a46b5
    goto L_0x004a46b5;
L_0x004a47a3:
    // 004a47a3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a47a5  e90bffffff             -jmp 0x4a46b5
    goto L_0x004a46b5;
L_0x004a47aa:
    // 004a47aa  f75c2408               +neg dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = 0;
        auto tmp2 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 004a47ae  eb27                   -jmp 0x4a47d7
    goto L_0x004a47d7;
L_0x004a47b0:
    // 004a47b0  8a411e                 -mov al, byte ptr [ecx + 0x1e]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004a47b3  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004a47b5  740f                   -je 0x4a47c6
    if (cpu.flags.zf)
    {
        goto L_0x004a47c6;
    }
    // 004a47b7  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a47ba  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a47bd  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004a47c0  c604062b               -mov byte ptr [esi + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 004a47c4  eb11                   -jmp 0x4a47d7
    goto L_0x004a47d7;
L_0x004a47c6:
    // 004a47c6  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004a47c8  740d                   -je 0x4a47d7
    if (cpu.flags.zf)
    {
        goto L_0x004a47d7;
    }
    // 004a47ca  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a47cd  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a47d0  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004a47d3  c6040620               -mov byte ptr [esi + eax], 0x20
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x004a47d7:
    // 004a47d7  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 004a47da  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004a47df  3c64                   +cmp al, 0x64
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(100 /*0x64*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a47e1  7261                   -jb 0x4a4844
    if (cpu.flags.cf)
    {
        goto L_0x004a4844;
    }
    // 004a47e3  0f86f0010000           -jbe 0x4a49d9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a49d9;
    }
    // 004a47e9  3c6f                   +cmp al, 0x6f
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a47eb  7238                   -jb 0x4a4825
    if (cpu.flags.cf)
    {
        goto L_0x004a4825;
    }
    // 004a47ed  0f86c6010000           -jbe 0x4a49b9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a49b9;
    }
    // 004a47f3  3c73                   +cmp al, 0x73
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
    // 004a47f5  7221                   -jb 0x4a4818
    if (cpu.flags.cf)
    {
        goto L_0x004a4818;
    }
    // 004a47f7  0f86e0000000           -jbe 0x4a48dd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a48dd;
    }
    // 004a47fd  3c75                   +cmp al, 0x75
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(117 /*0x75*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a47ff  0f82a2030000           -jb 0x4a4ba7
    if (cpu.flags.cf)
    {
        goto L_0x004a4ba7;
    }
    // 004a4805  0f86ce010000           -jbe 0x4a49d9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a49d9;
    }
    // 004a480b  3c78                   +cmp al, 0x78
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a480d  0f8463010000           -je 0x4a4976
    if (cpu.flags.zf)
    {
        goto L_0x004a4976;
    }
    // 004a4813  e98f030000             -jmp 0x4a4ba7
    goto L_0x004a4ba7;
L_0x004a4818:
    // 004a4818  3c70                   +cmp al, 0x70
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(112 /*0x70*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x004a481a:
    // 004a481a  0f845f020000           -je 0x4a4a7f
    if (cpu.flags.zf)
    {
        goto L_0x004a4a7f;
    }
    // 004a4820  e982030000             -jmp 0x4a4ba7
    goto L_0x004a4ba7;
L_0x004a4825:
    // 004a4825  3c66                   +cmp al, 0x66
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(102 /*0x66*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4827  0f8294000000           -jb 0x4a48c1
    if (cpu.flags.cf)
    {
        goto L_0x004a48c1;
    }
    // 004a482d  765d                   -jbe 0x4a488c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a488c;
    }
    // 004a482f  3c67                   +cmp al, 0x67
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(103 /*0x67*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4831  0f868a000000           -jbe 0x4a48c1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a48c1;
    }
    // 004a4837  3c69                   +cmp al, 0x69
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
    // 004a4839  0f849a010000           -je 0x4a49d9
    if (cpu.flags.zf)
    {
        goto L_0x004a49d9;
    }
    // 004a483f  e963030000             -jmp 0x4a4ba7
    goto L_0x004a4ba7;
L_0x004a4844:
    // 004a4844  3c47                   +cmp al, 0x47
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(71 /*0x47*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4846  722f                   -jb 0x4a4877
    if (cpu.flags.cf)
    {
        goto L_0x004a4877;
    }
    // 004a4848  0f8673000000           -jbe 0x4a48c1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a48c1;
    }
    // 004a484e  3c53                   +cmp al, 0x53
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4850  7221                   -jb 0x4a4873
    if (cpu.flags.cf)
    {
        goto L_0x004a4873;
    }
    // 004a4852  0f8685000000           -jbe 0x4a48dd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a48dd;
    }
    // 004a4858  3c58                   +cmp al, 0x58
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a485a  0f8247030000           -jb 0x4a4ba7
    if (cpu.flags.cf)
    {
        goto L_0x004a4ba7;
    }
    // 004a4860  0f8610010000           -jbe 0x4a4976
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a4976;
    }
    // 004a4866  3c63                   +cmp al, 0x63
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(99 /*0x63*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4868  0f849d020000           -je 0x4a4b0b
    if (cpu.flags.zf)
    {
        goto L_0x004a4b0b;
    }
    // 004a486e  e934030000             -jmp 0x4a4ba7
    goto L_0x004a4ba7;
L_0x004a4873:
    // 004a4873  3c50                   +cmp al, 0x50
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(80 /*0x50*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4875  eba3                   -jmp 0x4a481a
    goto L_0x004a481a;
L_0x004a4877:
    // 004a4877  3c45                   +cmp al, 0x45
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(69 /*0x45*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4879  7204                   -jb 0x4a487f
    if (cpu.flags.cf)
    {
        goto L_0x004a487f;
    }
    // 004a487b  7644                   -jbe 0x4a48c1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a48c1;
    }
    // 004a487d  eb0d                   -jmp 0x4a488c
    goto L_0x004a488c;
L_0x004a487f:
    // 004a487f  3c43                   +cmp al, 0x43
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(67 /*0x43*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4881  0f84f4020000           -je 0x4a4b7b
    if (cpu.flags.zf)
    {
        goto L_0x004a4b7b;
    }
    // 004a4887  e91b030000             -jmp 0x4a4ba7
    goto L_0x004a4ba7;
L_0x004a488c:
    // 004a488c  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 004a4890  742f                   -je 0x4a48c1
    if (cpu.flags.zf)
    {
        goto L_0x004a48c1;
    }
    // 004a4892  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4894  83c304                 +add ebx, 4
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
    // 004a4897  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004a4899  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004a489c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a48a0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004a48a2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a48a4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a48a6  e802fcffff             -call 0x4a44ad
    cpu.esp -= 4;
    sub_4a44ad(app, cpu);
    if (cpu.terminate) return;
    // 004a48ab  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004a48b0  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004a48b2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a48b4  e809fbffff             -call 0x4a43c2
    cpu.esp -= 4;
    sub_4a43c2(app, cpu);
    if (cpu.terminate) return;
    // 004a48b9  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004a48bc  e9f9020000             -jmp 0x4a4bba
    goto L_0x004a4bba;
L_0x004a48c1:
    // 004a48c1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004a48c3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a48c5  e8befcffff             -call 0x4a4588
    cpu.esp -= 4;
    sub_4a4588(app, cpu);
    if (cpu.terminate) return;
    // 004a48ca  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a48cc  e8befcffff             -call 0x4a458f
    cpu.esp -= 4;
    sub_4a458f(app, cpu);
    if (cpu.terminate) return;
    // 004a48d1  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a48d3  8d7e01                 -lea edi, [esi + 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a48d6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a48d8  e9dd020000             -jmp 0x4a4bba
    goto L_0x004a4bba;
L_0x004a48dd:
    // 004a48dd  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 004a48e0  8a411e                 -mov al, byte ptr [ecx + 0x1e]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004a48e3  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004a48e5  741d                   -je 0x4a4904
    if (cpu.flags.zf)
    {
        goto L_0x004a4904;
    }
    // 004a48e7  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004a48e9  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a48ec  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004a48ee  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004a48f1  668b55fc               -mov dx, word ptr [ebp - 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a48f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a48f7  7505                   -jne 0x4a48fe
    if (!cpu.flags.zf)
    {
        goto L_0x004a48fe;
    }
    // 004a48f9  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004a48fc  742e                   -je 0x4a492c
    if (cpu.flags.zf)
    {
        goto L_0x004a492c;
    }
L_0x004a48fe:
    // 004a48fe  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004a4900  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a4902  eb28                   -jmp 0x4a492c
    goto L_0x004a492c;
L_0x004a4904:
    // 004a4904  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 004a4906  7410                   -je 0x4a4918
    if (cpu.flags.zf)
    {
        goto L_0x004a4918;
    }
    // 004a4908  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004a490a  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a490d  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004a490f  8b46fc                 -mov eax, dword ptr [esi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 004a4912  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4914  7416                   -je 0x4a492c
    if (cpu.flags.zf)
    {
        goto L_0x004a492c;
    }
    // 004a4916  eb0e                   -jmp 0x4a4926
    goto L_0x004a4926;
L_0x004a4918:
    // 004a4918  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a491a  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a491d  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004a491f  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004a4922  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4924  7406                   -je 0x4a492c
    if (cpu.flags.zf)
    {
        goto L_0x004a492c;
    }
L_0x004a4926:
    // 004a4926  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004a4928  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a492a  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
L_0x004a492c:
    // 004a492c  80791553               +cmp byte ptr [ecx + 0x15], 0x53
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4930  7514                   -jne 0x4a4946
    if (!cpu.flags.zf)
    {
        goto L_0x004a4946;
    }
    // 004a4932  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 004a4936  7514                   -jne 0x4a494c
    if (!cpu.flags.zf)
    {
        goto L_0x004a494c;
    }
L_0x004a4938:
    // 004a4938  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004a493a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a493c  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a493f  e8a2faffff             -call 0x4a43e6
    cpu.esp -= 4;
    sub_4a43e6(app, cpu);
    if (cpu.terminate) return;
    // 004a4944  eb12                   -jmp 0x4a4958
    goto L_0x004a4958;
L_0x004a4946:
    // 004a4946  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 004a494a  75ec                   -jne 0x4a4938
    if (!cpu.flags.zf)
    {
        goto L_0x004a4938;
    }
L_0x004a494c:
    // 004a494c  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004a494e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a4950  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a4953  e86afaffff             -call 0x4a43c2
    cpu.esp -= 4;
    sub_4a43c2(app, cpu);
    if (cpu.terminate) return;
L_0x004a4958:
    // 004a4958  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a495b  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004a495e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a4960  0f8c54020000           -jl 0x4a4bba
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4bba;
    }
    // 004a4966  39d0                   +cmp eax, edx
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
    // 004a4968  0f8e4c020000           -jle 0x4a4bba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4bba;
    }
    // 004a496e  895128                 -mov dword ptr [ecx + 0x28], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004a4971  e944020000             -jmp 0x4a4bba
    goto L_0x004a4bba;
L_0x004a4976:
    // 004a4976  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 004a497a  7438                   -je 0x4a49b4
    if (cpu.flags.zf)
    {
        goto L_0x004a49b4;
    }
    // 004a497c  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 004a4980  740f                   -je 0x4a4991
    if (cpu.flags.zf)
    {
        goto L_0x004a4991;
    }
    // 004a4982  833c2400               +cmp dword ptr [esp], 0
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
    // 004a4986  7510                   -jne 0x4a4998
    if (!cpu.flags.zf)
    {
        goto L_0x004a4998;
    }
    // 004a4988  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004a498d  7425                   -je 0x4a49b4
    if (cpu.flags.zf)
    {
        goto L_0x004a49b4;
    }
    // 004a498f  eb07                   -jmp 0x4a4998
    goto L_0x004a4998;
L_0x004a4991:
    // 004a4991  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004a4996  741c                   -je 0x4a49b4
    if (cpu.flags.zf)
    {
        goto L_0x004a49b4;
    }
L_0x004a4998:
    // 004a4998  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a499b  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a499e  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004a49a1  c6040630               -mov byte ptr [esi + eax], 0x30
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 48 /*0x30*/;
    // 004a49a5  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a49a8  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a49ab  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004a49ae  8a5115                 -mov dl, byte ptr [ecx + 0x15]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 004a49b1  881406                 -mov byte ptr [esi + eax], dl
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = cpu.dl;
L_0x004a49b4:
    // 004a49b4  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x004a49b9:
    // 004a49b9  8079156f               +cmp byte ptr [ecx + 0x15], 0x6f
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a49bd  751a                   -jne 0x4a49d9
    if (!cpu.flags.zf)
    {
        goto L_0x004a49d9;
    }
    // 004a49bf  8a511e                 -mov dl, byte ptr [ecx + 0x1e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004a49c2  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004a49c7  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004a49ca  740d                   -je 0x4a49d9
    if (cpu.flags.zf)
    {
        goto L_0x004a49d9;
    }
    // 004a49cc  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a49cf  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a49d2  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004a49d5  c6040630               -mov byte ptr [esi + eax], 0x30
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 48 /*0x30*/;
L_0x004a49d9:
    // 004a49d9  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004a49db  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a49de  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004a49e0  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a49e2  8a711f                 -mov dh, byte ptr [ecx + 0x1f]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 004a49e5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a49e7  f6c601                 +test dh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 1 /*0x1*/));
    // 004a49ea  7436                   -je 0x4a4a22
    if (cpu.flags.zf)
    {
        goto L_0x004a4a22;
    }
    // 004a49ec  83790800               +cmp dword ptr [ecx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a49f0  7515                   -jne 0x4a4a07
    if (!cpu.flags.zf)
    {
        goto L_0x004a4a07;
    }
    // 004a49f2  833c2400               +cmp dword ptr [esp], 0
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
    // 004a49f6  750f                   -jne 0x4a4a07
    if (!cpu.flags.zf)
    {
        goto L_0x004a4a07;
    }
    // 004a49f8  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004a49fd  7508                   -jne 0x4a4a07
    if (!cpu.flags.zf)
    {
        goto L_0x004a4a07;
    }
L_0x004a49ff:
    // 004a49ff  26c60000               -mov byte ptr es:[eax], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.eax) = 0 /*0x0*/;
    // 004a4a03  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a4a05  eb51                   -jmp 0x4a4a58
    goto L_0x004a4a58;
L_0x004a4a07:
    // 004a4a07  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a4a0a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a4a0c  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a4a0e  e8b9750000             -call 0x4abfcc
    cpu.esp -= 4;
    sub_4abfcc(app, cpu);
    if (cpu.terminate) return;
    // 004a4a13  80791558               +cmp byte ptr [ecx + 0x15], 0x58
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4a17  7531                   -jne 0x4a4a4a
    if (!cpu.flags.zf)
    {
        goto L_0x004a4a4a;
    }
    // 004a4a19  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a4a1b  e8a6010000             -call 0x4a4bc6
    cpu.esp -= 4;
    sub_4a4bc6(app, cpu);
    if (cpu.terminate) return;
    // 004a4a20  eb28                   -jmp 0x4a4a4a
    goto L_0x004a4a4a;
L_0x004a4a22:
    // 004a4a22  83790800               +cmp dword ptr [ecx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4a26  7507                   -jne 0x4a4a2f
    if (!cpu.flags.zf)
    {
        goto L_0x004a4a2f;
    }
    // 004a4a28  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004a4a2d  74d0                   -je 0x4a49ff
    if (cpu.flags.zf)
    {
        goto L_0x004a49ff;
    }
L_0x004a4a2f:
    // 004a4a2f  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a4a32  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a4a36  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a4a38  e87c760000             -call 0x4ac0b9
    cpu.esp -= 4;
    sub_4ac0b9(app, cpu);
    if (cpu.terminate) return;
    // 004a4a3d  80791558               +cmp byte ptr [ecx + 0x15], 0x58
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4a41  7507                   -jne 0x4a4a4a
    if (!cpu.flags.zf)
    {
        goto L_0x004a4a4a;
    }
    // 004a4a43  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a4a45  e87c010000             -call 0x4a4bc6
    cpu.esp -= 4;
    sub_4a4bc6(app, cpu);
    if (cpu.terminate) return;
L_0x004a4a4a:
    // 004a4a4a  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004a4a4f  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004a4a51  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a4a53  e86af9ffff             -call 0x4a43c2
    cpu.esp -= 4;
    sub_4a43c2(app, cpu);
    if (cpu.terminate) return;
L_0x004a4a58:
    // 004a4a58  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004a4a5b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a4a5d  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a4a60  39c2                   +cmp edx, eax
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
    // 004a4a62  7d05                   -jge 0x4a4a69
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a4a69;
    }
    // 004a4a64  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4a66  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x004a4a69:
    // 004a4a69  837908ff               +cmp dword ptr [ecx + 8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4a6d  0f8547010000           -jne 0x4a4bba
    if (!cpu.flags.zf)
    {
        goto L_0x004a4bba;
    }
    // 004a4a73  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a4a75  e815fbffff             -call 0x4a458f
    cpu.esp -= 4;
    sub_4a458f(app, cpu);
    if (cpu.terminate) return;
    // 004a4a7a  e93b010000             -jmp 0x4a4bba
    goto L_0x004a4bba;
L_0x004a4a7f:
    // 004a4a7f  83790400               +cmp dword ptr [ecx + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4a83  7516                   -jne 0x4a4a9b
    if (!cpu.flags.zf)
    {
        goto L_0x004a4a9b;
    }
    // 004a4a85  f6411e80               +test byte ptr [ecx + 0x1e], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 128 /*0x80*/));
    // 004a4a89  7409                   -je 0x4a4a94
    if (cpu.flags.zf)
    {
        goto L_0x004a4a94;
    }
    // 004a4a8b  c741040d000000         -mov dword ptr [ecx + 4], 0xd
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 13 /*0xd*/;
    // 004a4a92  eb07                   -jmp 0x4a4a9b
    goto L_0x004a4a9b;
L_0x004a4a94:
    // 004a4a94  c7410408000000         -mov dword ptr [ecx + 4], 8
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
L_0x004a4a9b:
    // 004a4a9b  80611ef9               -and byte ptr [ecx + 0x1e], 0xf9
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 004a4a9f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4aa1  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a4aa4  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a4aa6  8a591e                 -mov bl, byte ptr [ecx + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004a4aa9  8b68fc                 -mov ebp, dword ptr [eax - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004a4aac  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 004a4aaf  7429                   -je 0x4a4ada
    if (cpu.flags.zf)
    {
        goto L_0x004a4ada;
    }
    // 004a4ab1  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a4ab4  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a4ab6  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004a4abb  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004a4abe  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a4ac0  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 004a4ac5  e885f9ffff             -call 0x4a444f
    cpu.esp -= 4;
    sub_4a444f(app, cpu);
    if (cpu.terminate) return;
    // 004a4aca  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004a4acf  8d5605                 -lea edx, [esi + 5]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 004a4ad2  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a4ad4  c646043a               -mov byte ptr [esi + 4], 0x3a
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 58 /*0x3a*/;
    // 004a4ad8  eb09                   -jmp 0x4a4ae3
    goto L_0x004a4ae3;
L_0x004a4ada:
    // 004a4ada  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004a4adf  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a4ae1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x004a4ae3:
    // 004a4ae3  e867f9ffff             -call 0x4a444f
    cpu.esp -= 4;
    sub_4a444f(app, cpu);
    if (cpu.terminate) return;
    // 004a4ae8  80791550               +cmp byte ptr [ecx + 0x15], 0x50
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(80 /*0x50*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4aec  7507                   -jne 0x4a4af5
    if (!cpu.flags.zf)
    {
        goto L_0x004a4af5;
    }
    // 004a4aee  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a4af0  e8d1000000             -call 0x4a4bc6
    cpu.esp -= 4;
    sub_4a4bc6(app, cpu);
    if (cpu.terminate) return;
L_0x004a4af5:
    // 004a4af5  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004a4afa  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004a4afc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a4afe  e8bff8ffff             -call 0x4a43c2
    cpu.esp -= 4;
    sub_4a43c2(app, cpu);
    if (cpu.terminate) return;
L_0x004a4b03:
    // 004a4b03  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004a4b06  e9af000000             -jmp 0x4a4bba
    goto L_0x004a4bba;
L_0x004a4b0b:
    // 004a4b0b  8a591e                 -mov bl, byte ptr [ecx + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004a4b0e  c7412001000000         -mov dword ptr [ecx + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 004a4b15  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 004a4b18  7453                   -je 0x4a4b6d
    if (cpu.flags.zf)
    {
        goto L_0x004a4b6d;
    }
    // 004a4b1a  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4b1c  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a4b1f  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004a4b21  668b43fc               -mov ax, word ptr [ebx - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004a4b25  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4b27  6689c2                 -mov dx, ax
    cpu.dx = cpu.ax;
    // 004a4b2a  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a4b2e  e800740000             -call 0x4abf33
    cpu.esp -= 4;
    sub_4abf33(app, cpu);
    if (cpu.terminate) return;
    // 004a4b33  83f8ff                 +cmp eax, -1
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
    // 004a4b36  0f847e000000           -je 0x4a4bba
    if (cpu.flags.zf)
    {
        goto L_0x004a4bba;
    }
    // 004a4b3c  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a4b40  8b2d8c705400           -mov ebp, dword ptr [0x54708c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5533836) /* 0x54708c */);
    // 004a4b46  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004a4b48  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a4b4a  746e                   -je 0x4a4bba
    if (cpu.flags.zf)
    {
        goto L_0x004a4bba;
    }
    // 004a4b4c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4b4e  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a4b52  8a8091705400           -mov al, byte ptr [eax + 0x547091]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5533841) /* 0x547091 */);
    // 004a4b58  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004a4b5a  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004a4b5f  7459                   -je 0x4a4bba
    if (cpu.flags.zf)
    {
        goto L_0x004a4bba;
    }
    // 004a4b61  8a44240d               -mov al, byte ptr [esp + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(13) /* 0xd */);
    // 004a4b65  884601                 -mov byte ptr [esi + 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a4b68  ff4120                 +inc dword ptr [ecx + 0x20]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a4b6b  eb4d                   -jmp 0x4a4bba
    goto L_0x004a4bba;
L_0x004a4b6d:
    // 004a4b6d  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4b6f  83c004                 +add eax, 4
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
    // 004a4b72  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a4b74  8a40fc                 -mov al, byte ptr [eax - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004a4b77  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004a4b79  eb3f                   -jmp 0x4a4bba
    goto L_0x004a4bba;
L_0x004a4b7b:
    // 004a4b7b  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4b7d  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a4b80  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004a4b82  668b55fc               -mov dx, word ptr [ebp - 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a4b86  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a4b8c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a4b8e  e8a0730000             -call 0x4abf33
    cpu.esp -= 4;
    sub_4abf33(app, cpu);
    if (cpu.terminate) return;
    // 004a4b93  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a4b95  83f8ff                 +cmp eax, -1
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
    // 004a4b98  0f8565ffffff           -jne 0x4a4b03
    if (!cpu.flags.zf)
    {
        goto L_0x004a4b03;
    }
    // 004a4b9e  c7412000000000         -mov dword ptr [ecx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004a4ba5  eb13                   -jmp 0x4a4bba
    goto L_0x004a4bba;
L_0x004a4ba7:
    // 004a4ba7  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a4bae  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 004a4bb1  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004a4bb3  c7412001000000         -mov dword ptr [ecx + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
L_0x004a4bba:
    // 004a4bba  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004a4bbc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a4bbe  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a4bc1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4bc2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a4bc3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4bc4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4bc5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a4bc6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4bc6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a4bc7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004a4bc9:
    // 004a4bc9  803a00                 +cmp byte ptr [edx], 0
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
    // 004a4bcc  740e                   -je 0x4a4bdc
    if (cpu.flags.zf)
    {
        goto L_0x004a4bdc;
    }
    // 004a4bce  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a4bd0  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004a4bd2  e86b58fdff             -call 0x47a442
    cpu.esp -= 4;
    sub_47a442(app, cpu);
    if (cpu.terminate) return;
    // 004a4bd7  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004a4bd9  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a4bda  ebed                   -jmp 0x4a4bc9
    goto L_0x004a4bc9;
L_0x004a4bdc:
    // 004a4bdc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4bdd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4a4be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4be0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a4be1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a4be3  3d00000100             +cmp eax, 0x10000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4be8  7f1b                   -jg 0x4a4c05
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a4c05;
    }
    // 004a4bea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4bec  7c1e                   -jl 0x4a4c0c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4c0c;
    }
L_0x004a4bee:
    // 004a4bee  e87d80fdff             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 004a4bf3  25ff7f0000             -and eax, 0x7fff
    cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/));
    // 004a4bf8  2d00400000             -sub eax, 0x4000
    (cpu.eax) -= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 004a4bfd  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a4c00  c1f80e                 +sar eax, 0xe
    {
        x86::reg8 tmp = 14 /*0xe*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004a4c03  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4c04  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4c05:
    // 004a4c05  ba00000100             -mov edx, 0x10000
    cpu.edx = 65536 /*0x10000*/;
    // 004a4c0a  ebe2                   -jmp 0x4a4bee
    goto L_0x004a4bee;
L_0x004a4c0c:
    // 004a4c0c  31c2                   +xor edx, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a4c0e  ebde                   -jmp 0x4a4bee
    goto L_0x004a4bee;
}

/* align: skip  */
void Application::sub_4a4c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4c10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a4c12(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4c12  6650                   -push ax
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ax;
    cpu.esp -= 4;
    // 004a4c14  9b                     -wait 
    /*nothing*/;
    // 004a4c15  dbe3                   +fninit 
    cpu.fpu.init();
    // 004a4c17  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 004a4c19  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004a4c1b  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a4c1d  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a4c1f  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a4c21  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004a4c23  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a4c25  b002                   -mov al, 2
    cpu.al = 2 /*0x2*/;
    // 004a4c27  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a4c28  7402                   -je 0x4a4c2c
    if (cpu.flags.zf)
    {
        goto L_0x004a4c2c;
    }
    // 004a4c2a  b003                   -mov al, 3
    cpu.al = 3 /*0x3*/;
L_0x004a4c2c:
    // 004a4c2c  9b                     -wait 
    /*nothing*/;
    // 004a4c2d  dbe3                   -fninit 
    cpu.fpu.init();
    // 004a4c2f  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004a4c32  66870424               -xchg word ptr [esp], ax
    {
        x86::reg16 tmp = app->getMemory<x86::reg16>(cpu.esp);
        app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
        cpu.ax = tmp;
    }
    // 004a4c36  6658                   -pop ax
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a4c38  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a4c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4c40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a4c41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4c42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4c43  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a4c44  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a4c47  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a4c49  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a4c4b  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a4c4d  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
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
    // 004a4c53  7c49                   -jl 0x4a4c9e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4c9e;
    }
    // 004a4c55  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
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
    // 004a4c5b  7d41                   -jge 0x4a4c9e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a4c9e;
    }
    // 004a4c5d  3b35e0844c00           +cmp esi, dword ptr [0x4c84e0]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4c63  7c39                   -jl 0x4a4c9e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4c9e;
    }
    // 004a4c65  3b35e8844c00           +cmp esi, dword ptr [0x4c84e8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4c6b  7d31                   -jge 0x4a4c9e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a4c9e;
    }
    // 004a4c6d  803dec844c0010         +cmp byte ptr [0x4c84ec], 0x10
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
    // 004a4c74  7509                   -jne 0x4a4c7f
    if (!cpu.flags.zf)
    {
        goto L_0x004a4c7f;
    }
    // 004a4c76  803dee844c0000         +cmp byte ptr [0x4c84ee], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014766) /* 0x4c84ee */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4c7d  7427                   -je 0x4a4ca6
    if (cpu.flags.zf)
    {
        goto L_0x004a4ca6;
    }
L_0x004a4c7f:
    // 004a4c7f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004a4c81  c1eb18                 -shr ebx, 0x18
    cpu.ebx >>= 24 /*0x18*/ % 32;
    // 004a4c84  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a4c8a  81fbff000000           +cmp ebx, 0xff
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
    // 004a4c90  0f84ae000000           -je 0x4a4d44
    if (cpu.flags.zf)
    {
        goto L_0x004a4d44;
    }
    // 004a4c96  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a4c98  0f85c0000000           -jne 0x4a4d5e
    if (!cpu.flags.zf)
    {
        goto L_0x004a4d5e;
    }
L_0x004a4c9e:
    // 004a4c9e  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a4ca1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4ca2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4ca3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4ca4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4ca5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4ca6:
    // 004a4ca6  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a4ca8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a4caa  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 004a4cb0  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004a4cb3  8b15fc844c00           -mov edx, dword ptr [0x4c84fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 004a4cb9  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004a4cbc  0305f0844c00           -add eax, dword ptr [0x4c84f0]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 004a4cc2  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004a4cc4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a4cc6  81fb00000010           +cmp ebx, 0x10000000
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
    // 004a4ccc  726b                   -jb 0x4a4d39
    if (cpu.flags.cf)
    {
        goto L_0x004a4d39;
    }
    // 004a4cce  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 004a4cd4  7340                   -jae 0x4a4d16
    if (!cpu.flags.cf)
    {
        goto L_0x004a4d16;
    }
    // 004a4cd6  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004a4cd9  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a4cdb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a4cdd  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004a4ce0  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a4ce3  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004a4ce5  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004a4ceb  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a4cee  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 004a4cf3  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004a4cf6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a4cf8  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004a4cfa  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a4cfd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a4cff  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 004a4d02  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a4d04  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004a4d07  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a4d0d  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004a4d12  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a4d14  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a4d16:
    // 004a4d16  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a4d18  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004a4d1e  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004a4d21  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a4d23  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004a4d26  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004a4d2c  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004a4d2f  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a4d32  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a4d34  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a4d36  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004a4d39:
    // 004a4d39  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a4d3c  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a4d3f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4d40  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4d41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4d42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4d43  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4d44:
    // 004a4d44  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a4d46  e81118fdff             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 004a4d4b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a4d4d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a4d4f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a4d51  e81a75ffff             -call 0x49c270
    cpu.esp -= 4;
    sub_49c270(app, cpu);
    if (cpu.terminate) return;
    // 004a4d56  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a4d59  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4d5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4d5b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4d5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4d5d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4d5e:
    // 004a4d5e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a4d60  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a4d63  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a4d68  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a4d6b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a4d6d  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004a4d70  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a4d76  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a4d7b  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a4d7f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a4d83  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a4d85  b800000100             -mov eax, 0x10000
    cpu.eax = 65536 /*0x10000*/;
    // 004a4d8a  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a4d8d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a4d8f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a4d91  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a4d93  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a4d95  e81610ffff             -call 0x495db0
    cpu.esp -= 4;
    sub_495db0(app, cpu);
    if (cpu.terminate) return;
    // 004a4d9a  e841cefeff             -call 0x491be0
    cpu.esp -= 4;
    sub_491be0(app, cpu);
    if (cpu.terminate) return;
    // 004a4d9f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a4da1  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a4da4  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a4daa  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004a4dae  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a4db0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a4db2  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004a4db5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a4dba  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a4dc0  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a4dc4  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004a4dc8  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 004a4dcd  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 004a4dd2  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a4dd4  2b442414               -sub eax, dword ptr [esp + 0x14]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004a4dd8  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a4ddb  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 004a4de0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a4de2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a4de5  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a4de7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a4de9  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 004a4dec  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4dee  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a4df4  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004a4df8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a4dfa  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a4dfc  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a4dfe  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a4e01  c1e810                 +shr eax, 0x10
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
    // 004a4e04  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004a4e06  030424                 -add eax, dword ptr [esp]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 004a4e09  39d8                   +cmp eax, ebx
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
    // 004a4e0b  0f8e77000000           -jle 0x4a4e88
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4e88;
    }
    // 004a4e11  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004a4e13:
    // 004a4e13  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a4e15  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a4e17  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a4e1b  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a4e1f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a4e21  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a4e24  c1e810                 +shr eax, 0x10
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
    // 004a4e27  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004a4e29  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a4e2b  3dff000000             +cmp eax, 0xff
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
    // 004a4e30  7e6e                   -jle 0x4a4ea0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4ea0;
    }
    // 004a4e32  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x004a4e37:
    // 004a4e37  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a4e39  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a4e3b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a4e3f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a4e41  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a4e44  c1e810                 +shr eax, 0x10
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
    // 004a4e47  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004a4e49  03442404               -add eax, dword ptr [esp + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004a4e4d  3dff000000             +cmp eax, 0xff
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
    // 004a4e52  7e60                   -jle 0x4a4eb4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4eb4;
    }
    // 004a4e54  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x004a4e59:
    // 004a4e59  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a4e5d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a4e5f  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 004a4e62  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004a4e65  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a4e67  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004a4e69  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a4e6c  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a4e6e  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4e70  e8e716fdff             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 004a4e75  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a4e77  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a4e79  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a4e7b  e8f073ffff             -call 0x49c270
    cpu.esp -= 4;
    sub_49c270(app, cpu);
    if (cpu.terminate) return;
    // 004a4e80  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a4e83  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4e84  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4e85  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4e86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4e87  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4e88:
    // 004a4e88  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a4e8a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a4e8c  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a4e8f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a4e91  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a4e94  c1e810                 +shr eax, 0x10
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
    // 004a4e97  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004a4e99  01d8                   +add eax, ebx
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
    // 004a4e9b  e973ffffff             -jmp 0x4a4e13
    goto L_0x004a4e13;
L_0x004a4ea0:
    // 004a4ea0  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a4ea4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a4ea6  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a4ea8  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a4eab  c1e810                 +shr eax, 0x10
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
    // 004a4eae  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004a4eb0  01e8                   +add eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4eb2  eb83                   -jmp 0x4a4e37
    goto L_0x004a4e37;
L_0x004a4eb4:
    // 004a4eb4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a4eb8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a4eba  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a4ebe  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a4ec0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a4ec3  c1e810                 +shr eax, 0x10
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
    // 004a4ec6  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004a4ec8  01c8                   +add eax, ecx
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
    // 004a4eca  eb8d                   -jmp 0x4a4e59
    goto L_0x004a4e59;
}

/* align: skip  */
void Application::sub_4a4ecc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4ecc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4ecd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4ece  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4ecf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a4ed0  837c242400             +cmp dword ptr [esp + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4ed5  0f8efb000000           -jle 0x4a4fd6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4fd6;
    }
    // 004a4edb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a4edd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4edf  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a4ee3  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a4ee7  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a4eeb  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a4eef  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4ef2  0f8cde000000           -jl 0x4a4fd6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4fd6;
    }
    // 004a4ef8  d1e9                   +shr ecx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004a4efa  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004a4efe  7259                   -jb 0x4a4f59
    if (cpu.flags.cf)
    {
        goto L_0x004a4f59;
    }
L_0x004a4f00:
    // 004a4f00  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
L_0x004a4f04:
    // 004a4f04  8a7e01                 -mov bh, byte ptr [esi + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a4f07  8a7601                 -mov dh, byte ptr [esi + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a4f0a  8a5f02                 -mov bl, byte ptr [edi + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a4f0d  8a5703                 -mov dl, byte ptr [edi + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 004a4f10  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 004a4f13  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004a4f16  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 004a4f1a  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 004a4f1e  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a4f21  8a3e                   -mov bh, byte ptr [esi]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi);
    // 004a4f23  8a36                   -mov dh, byte ptr [esi]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi);
    // 004a4f25  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004a4f27  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a4f2a  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 004a4f2d  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004a4f30  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 004a4f34  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 004a4f38  83e901                 +sub ecx, 1
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
    // 004a4f3b  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a4f3d  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a4f40  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a4f43  7fbf                   -jg 0x4a4f04
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a4f04;
    }
    // 004a4f45  03742428               -add esi, dword ptr [esp + 0x28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004a4f49  037c242c               -add edi, dword ptr [esp + 0x2c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004a4f4d  836c242401             +sub dword ptr [esp + 0x24], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4f52  75ac                   -jne 0x4a4f00
    if (!cpu.flags.zf)
    {
        goto L_0x004a4f00;
    }
    // 004a4f54  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4f55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4f56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4f57  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4f58  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4f59:
    // 004a4f59  8344242801             -add dword ptr [esp + 0x28], 1
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a4f5e  8344242c02             -add dword ptr [esp + 0x2c], 2
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004a4f63:
    // 004a4f63  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a4f67  83f900                 +cmp ecx, 0
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
    // 004a4f6a  7441                   -je 0x4a4fad
    if (cpu.flags.zf)
    {
        goto L_0x004a4fad;
    }
L_0x004a4f6c:
    // 004a4f6c  8a7e01                 -mov bh, byte ptr [esi + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a4f6f  8a7601                 -mov dh, byte ptr [esi + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a4f72  8a5f02                 -mov bl, byte ptr [edi + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a4f75  8a5703                 -mov dl, byte ptr [edi + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 004a4f78  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 004a4f7b  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004a4f7e  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 004a4f82  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 004a4f86  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a4f89  8a3e                   -mov bh, byte ptr [esi]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi);
    // 004a4f8b  8a36                   -mov dh, byte ptr [esi]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi);
    // 004a4f8d  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004a4f8f  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a4f92  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 004a4f95  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004a4f98  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 004a4f9c  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 004a4fa0  83e901                 +sub ecx, 1
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
    // 004a4fa3  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a4fa5  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a4fa8  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a4fab  7fbf                   -jg 0x4a4f6c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a4f6c;
    }
L_0x004a4fad:
    // 004a4fad  8a3e                   -mov bh, byte ptr [esi]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi);
    // 004a4faf  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004a4fb1  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a4fb4  88fe                   -mov dh, bh
    cpu.dh = cpu.bh;
    // 004a4fb6  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 004a4fb9  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004a4fbc  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 004a4fc0  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 004a4fc4  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004a4fc7  03742428               -add esi, dword ptr [esp + 0x28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004a4fcb  037c242c               -add edi, dword ptr [esp + 0x2c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004a4fcf  836c242401             +sub dword ptr [esp + 0x24], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4fd4  758d                   -jne 0x4a4f63
    if (!cpu.flags.zf)
    {
        goto L_0x004a4f63;
    }
L_0x004a4fd6:
    // 004a4fd6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4fd7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4fd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4fd9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4fda  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a4fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4fe0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a4fe1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4fe2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4fe3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a4fe4  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a4fe6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4fe8  0f849a000000           -je 0x4a5088
    if (cpu.flags.zf)
    {
        goto L_0x004a5088;
    }
    // 004a4fee  8d480b                 -lea ecx, [eax + 0xb]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 004a4ff1  39c1                   +cmp ecx, eax
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
    // 004a4ff3  0f828f000000           -jb 0x4a5088
    if (cpu.flags.cf)
    {
        goto L_0x004a5088;
    }
    // 004a4ff9  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a4ffb  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004a4ffe  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004a5001  83f910                 +cmp ecx, 0x10
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
    // 004a5004  7305                   -jae 0x4a500b
    if (!cpu.flags.cf)
    {
        goto L_0x004a500b;
    }
    // 004a5006  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
L_0x004a500b:
    // 004a500b  39c1                   +cmp ecx, eax
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
    // 004a500d  0f8775000000           -ja 0x4a5088
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a5088;
    }
    // 004a5013  8b5f10                 -mov ebx, dword ptr [edi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004a5016  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004a5019  39d9                   +cmp ecx, ebx
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
    // 004a501b  7705                   -ja 0x4a5022
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a5022;
    }
    // 004a501d  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 004a5020  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004a5022:
    // 004a5022  8d7720                 -lea esi, [edi + 0x20]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
L_0x004a5025:
    // 004a5025  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a5027  39d1                   +cmp ecx, edx
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
    // 004a5029  7612                   -jbe 0x4a503d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a503d;
    }
    // 004a502b  39da                   +cmp edx, ebx
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
    // 004a502d  7602                   -jbe 0x4a5031
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a5031;
    }
    // 004a502f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x004a5031:
    // 004a5031  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a5034  39f0                   +cmp eax, esi
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
    // 004a5036  75ed                   -jne 0x4a5025
    if (!cpu.flags.zf)
    {
        goto L_0x004a5025;
    }
    // 004a5038  895f14                 -mov dword ptr [edi + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004a503b  eb4b                   -jmp 0x4a5088
    goto L_0x004a5088;
L_0x004a503d:
    // 004a503d  895f10                 -mov dword ptr [edi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004a5040  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 004a5043  43                     -inc ebx
    (cpu.ebx)++;
    // 004a5044  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5046  895f18                 -mov dword ptr [edi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004a5049  83fa10                 +cmp edx, 0x10
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
    // 004a504c  721e                   -jb 0x4a506c
    if (cpu.flags.cf)
    {
        goto L_0x004a506c;
    }
    // 004a504e  8d1c08                 -lea ebx, [eax + ecx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 004a5051  895f0c                 -mov dword ptr [edi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004a5054  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a5056  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a5058  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a505b  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a505e  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a5061  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a5064  895908                 -mov dword ptr [ecx + 8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004a5067  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a506a  eb12                   -jmp 0x4a507e
    goto L_0x004a507e;
L_0x004a506c:
    // 004a506c  ff4f1c                 -dec dword ptr [edi + 0x1c]
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */))--;
    // 004a506f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a5072  89570c                 -mov dword ptr [edi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004a5075  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a5078  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004a507b  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x004a507e:
    // 004a507e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5080  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004a5083  8d6804                 -lea ebp, [eax + 4]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a5086  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x004a5088:
    // 004a5088  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a508a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a508b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a508c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a508d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a508e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a5090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5090  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5091  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5092  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5093  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5094  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a5096  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a5098  0f841d010000           -je 0x4a51bb
    if (cpu.flags.zf)
    {
        goto L_0x004a51bb;
    }
    // 004a509e  8d58fc                 -lea ebx, [eax - 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004a50a1  f60301                 +test byte ptr [ebx], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx) & 1 /*0x1*/));
    // 004a50a4  0f8411010000           -je 0x4a51bb
    if (cpu.flags.zf)
    {
        goto L_0x004a51bb;
    }
    // 004a50aa  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a50ac  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004a50af  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 004a50b2  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a50b4  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 004a50b7  7522                   -jne 0x4a50db
    if (!cpu.flags.zf)
    {
        goto L_0x004a50db;
    }
    // 004a50b9  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004a50bb  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a50bd  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a50bf  3b410c                 +cmp eax, dword ptr [ecx + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a50c2  7503                   -jne 0x4a50c7
    if (!cpu.flags.zf)
    {
        goto L_0x004a50c7;
    }
    // 004a50c4  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x004a50c7:
    // 004a50c7  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a50ca  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a50cd  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a50d0  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a50d3  ff4e1c                 +dec dword ptr [esi + 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a50d6  e994000000             -jmp 0x4a516f
    goto L_0x004a516f;
L_0x004a50db:
    // 004a50db  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a50dd  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a50e0  39c3                   +cmp ebx, eax
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
    // 004a50e2  7316                   -jae 0x4a50fa
    if (!cpu.flags.cf)
    {
        goto L_0x004a50fa;
    }
    // 004a50e4  3b5804                 +cmp ebx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a50e7  0f8782000000           -ja 0x4a516f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a516f;
    }
    // 004a50ed  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004a50f0  39c3                   +cmp ebx, eax
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
    // 004a50f2  0f8277000000           -jb 0x4a516f
    if (cpu.flags.cf)
    {
        goto L_0x004a516f;
    }
    // 004a50f8  eb19                   -jmp 0x4a5113
    goto L_0x004a5113;
L_0x004a50fa:
    // 004a50fa  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a50fd  39c3                   +cmp ebx, eax
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
    // 004a50ff  0f826a000000           -jb 0x4a516f
    if (cpu.flags.cf)
    {
        goto L_0x004a516f;
    }
    // 004a5105  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a5108  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a510b  39d3                   +cmp ebx, edx
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
    // 004a510d  0f875c000000           -ja 0x4a516f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a516f;
    }
L_0x004a5113:
    // 004a5113  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004a5116  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a5119  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a511b  8d4f01                 -lea ecx, [edi + 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a511e  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a5120  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a5122  39f8                   +cmp eax, edi
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
    // 004a5124  7328                   -jae 0x4a514e
    if (!cpu.flags.cf)
    {
        goto L_0x004a514e;
    }
    // 004a5126  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a5129  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004a512b  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a512d  39f8                   +cmp eax, edi
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
    // 004a512f  7705                   -ja 0x4a5136
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a5136;
    }
    // 004a5131  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
L_0x004a5136:
    // 004a5136  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a5138  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004a513a:
    // 004a513a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a513c  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004a513f  742e                   -je 0x4a516f
    if (cpu.flags.zf)
    {
        goto L_0x004a516f;
    }
    // 004a5141  83faff                 +cmp edx, -1
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
    // 004a5144  7408                   -je 0x4a514e
    if (cpu.flags.zf)
    {
        goto L_0x004a514e;
    }
    // 004a5146  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004a5149  01d0                   +add eax, edx
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
    // 004a514b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a514c  75ec                   -jne 0x4a513a
    if (!cpu.flags.zf)
    {
        goto L_0x004a513a;
    }
L_0x004a514e:
    // 004a514e  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a5151  39c3                   +cmp ebx, eax
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
    // 004a5153  7303                   -jae 0x4a5158
    if (!cpu.flags.cf)
    {
        goto L_0x004a5158;
    }
    // 004a5155  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
L_0x004a5158:
    // 004a5158  39c3                   +cmp ebx, eax
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
    // 004a515a  7213                   -jb 0x4a516f
    if (cpu.flags.cf)
    {
        goto L_0x004a516f;
    }
    // 004a515c  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a515f  39c3                   +cmp ebx, eax
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
    // 004a5161  720c                   -jb 0x4a516f
    if (cpu.flags.cf)
    {
        goto L_0x004a516f;
    }
    // 004a5163  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a5166  39c3                   +cmp ebx, eax
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
    // 004a5168  7205                   -jb 0x4a516f
    if (cpu.flags.cf)
    {
        goto L_0x004a516f;
    }
    // 004a516a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a516d  ebe9                   -jmp 0x4a5158
    goto L_0x004a5158;
L_0x004a516f:
    // 004a516f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a5172  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 004a5174  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a5176  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a5178  39df                   +cmp edi, ebx
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
    // 004a517a  7512                   -jne 0x4a518e
    if (!cpu.flags.zf)
    {
        goto L_0x004a518e;
    }
    // 004a517c  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004a517e  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a5180  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004a5182  3b5e0c                 +cmp ebx, dword ptr [esi + 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5185  7503                   -jne 0x4a518a
    if (!cpu.flags.zf)
    {
        goto L_0x004a518a;
    }
    // 004a5187  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x004a518a:
    // 004a518a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a518c  eb0f                   -jmp 0x4a519d
    goto L_0x004a519d;
L_0x004a518e:
    // 004a518e  ff461c                 -inc dword ptr [esi + 0x1c]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))++;
    // 004a5191  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a5194  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a5197  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004a519a  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x004a519d:
    // 004a519d  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a51a0  4a                     -dec edx
    (cpu.edx)--;
    // 004a51a1  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a51a4  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004a51a7  39fb                   +cmp ebx, edi
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
    // 004a51a9  7308                   -jae 0x4a51b3
    if (!cpu.flags.cf)
    {
        goto L_0x004a51b3;
    }
    // 004a51ab  3b4e10                 +cmp ecx, dword ptr [esi + 0x10]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a51ae  7603                   -jbe 0x4a51b3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a51b3;
    }
    // 004a51b0  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x004a51b3:
    // 004a51b3  3b4e14                 +cmp ecx, dword ptr [esi + 0x14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a51b6  7603                   -jbe 0x4a51bb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a51bb;
    }
    // 004a51b8  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x004a51bb:
    // 004a51bb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a51bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a51bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a51be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a51bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a51c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a51c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a51c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a51c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a51c4  a130ac4c00             -mov eax, dword ptr [0x4cac30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024816) /* 0x4cac30 */);
    // 004a51c9  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004a51cb  eb09                   -jmp 0x4a51d6
    goto L_0x004a51d6;
L_0x004a51cd:
    // 004a51cd  39c2                   +cmp edx, eax
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
    // 004a51cf  7209                   -jb 0x4a51da
    if (cpu.flags.cf)
    {
        goto L_0x004a51da;
    }
    // 004a51d1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a51d3  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x004a51d6:
    // 004a51d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a51d8  75f3                   -jne 0x4a51cd
    if (!cpu.flags.zf)
    {
        goto L_0x004a51cd;
    }
L_0x004a51da:
    // 004a51da  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a51dd  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a51e0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a51e2  7405                   -je 0x4a51e9
    if (cpu.flags.zf)
    {
        goto L_0x004a51e9;
    }
    // 004a51e4  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a51e7  eb06                   -jmp 0x4a51ef
    goto L_0x004a51ef;
L_0x004a51e9:
    // 004a51e9  891530ac4c00           -mov dword ptr [0x4cac30], edx
    app->getMemory<x86::reg32>(x86::reg32(5024816) /* 0x4cac30 */) = cpu.edx;
L_0x004a51ef:
    // 004a51ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a51f1  7403                   -je 0x4a51f6
    if (cpu.flags.zf)
    {
        goto L_0x004a51f6;
    }
    // 004a51f3  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x004a51f6:
    // 004a51f6  8d5a20                 -lea ebx, [edx + 0x20]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a51f9  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004a51fb  83c22c                 -add edx, 0x2c
    (cpu.edx) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004a51fe  c742f400000000         -mov dword ptr [edx - 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-12) /* -0xc */) = 0 /*0x0*/;
    // 004a5205  c742e400000000         -mov dword ptr [edx - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-28) /* -0x1c */) = 0 /*0x0*/;
    // 004a520c  c742ec00000000         -mov dword ptr [edx - 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 004a5213  c742f000000000         -mov dword ptr [edx - 0x10], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-16) /* -0x10 */) = 0 /*0x0*/;
    // 004a521a  895af8                 -mov dword ptr [edx - 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004a521d  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004a5220  83e82c                 -sub eax, 0x2c
    (cpu.eax) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004a5223  895ae0                 -mov dword ptr [edx - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 004a5226  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a5228  c70402ffffffff         -mov dword ptr [edx + eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 4294967295 /*0xffffffff*/;
    // 004a522f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5231  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5232  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5233  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5234(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5234  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5235  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5236  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a5237  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5238  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5239  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a523a  833d0cd94c0000         +cmp dword ptr [0x4cd90c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5036300) /* 0x4cd90c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5241  7507                   -jne 0x4a524a
    if (!cpu.flags.zf)
    {
        goto L_0x004a524a;
    }
L_0x004a5243:
    // 004a5243  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a5245  e973000000             -jmp 0x4a52bd
    goto L_0x004a52bd;
L_0x004a524a:
    // 004a524a  833dbcab4c00fe         +cmp dword ptr [0x4cabbc], -2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5024700) /* 0x4cabbc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5251  74f0                   -je 0x4a5243
    if (cpu.flags.zf)
    {
        goto L_0x004a5243;
    }
    // 004a5253  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a5255  e87d000000             -call 0x4a52d7
    cpu.esp -= 4;
    sub_4a52d7(app, cpu);
    if (cpu.terminate) return;
    // 004a525a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a525c  745f                   -je 0x4a52bd
    if (cpu.flags.zf)
    {
        goto L_0x004a52bd;
    }
    // 004a525e  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 004a5260  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 004a5265  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a5269  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a526a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a526c  2eff1594554b00         -call dword ptr cs:[0x4b5594]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937108) /* 0x4b5594 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5273  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5275  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a5277  7444                   -je 0x4a52bd
    if (cpu.flags.zf)
    {
        goto L_0x004a52bd;
    }
    // 004a5279  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a527c  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a527f  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a5282  39f0                   +cmp eax, esi
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
    // 004a5284  77bd                   -ja 0x4a5243
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a5243;
    }
    // 004a5286  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a5289  83f838                 +cmp eax, 0x38
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a528c  72b5                   -jb 0x4a5243
    if (cpu.flags.cf)
    {
        goto L_0x004a5243;
    }
    // 004a528e  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a5290  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5292  e829ffffff             -call 0x4a51c0
    cpu.esp -= 4;
    sub_4a51c0(app, cpu);
    if (cpu.terminate) return;
    // 004a5297  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5299  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a529b  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a529e  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004a52a0  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a52a2  8b7a18                 -mov edi, dword ptr [edx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004a52a5  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004a52ac  47                     -inc edi
    (cpu.edi)++;
    // 004a52ad  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a52b0  897a18                 -mov dword ptr [edx + 0x18], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004a52b3  e89159ffff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004a52b8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a52bd:
    // 004a52bd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a52c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52c2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a52c6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a52c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a52c7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a52c9  e84f6e0000             -call 0x4ac11d
    cpu.esp -= 4;
    sub_4ac11d(app, cpu);
    if (cpu.terminate) return;
    // 004a52ce  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a52d0  e85fffffff             -call 0x4a5234
    cpu.esp -= 4;
    sub_4a5234(app, cpu);
    if (cpu.terminate) return;
    // 004a52d5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a52d7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a52d7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a52d8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a52d9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a52db  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a52dd  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a52e0  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004a52e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a52e4  7438                   -je 0x4a531e
    if (cpu.flags.zf)
    {
        goto L_0x004a531e;
    }
    // 004a52e6  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a52e8  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004a52eb  3b02                   +cmp eax, dword ptr [edx]
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
    // 004a52ed  7305                   -jae 0x4a52f4
    if (!cpu.flags.cf)
    {
        goto L_0x004a52f4;
    }
L_0x004a52ef:
    // 004a52ef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a52f1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52f3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a52f4:
    // 004a52f4  8b0d10d94c00           -mov ecx, dword ptr [0x4cd910]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5036304) /* 0x4cd910 */);
    // 004a52fa  39c8                   +cmp eax, ecx
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
    // 004a52fc  7304                   -jae 0x4a5302
    if (!cpu.flags.cf)
    {
        goto L_0x004a5302;
    }
    // 004a52fe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a5300  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x004a5302:
    // 004a5302  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a5304  05ff0f0000             -add eax, 0xfff
    (cpu.eax) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 004a5309  3b02                   +cmp eax, dword ptr [edx]
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
    // 004a530b  72e2                   -jb 0x4a52ef
    if (cpu.flags.cf)
    {
        goto L_0x004a52ef;
    }
    // 004a530d  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 004a530f  80e4f0                 -and ah, 0xf0
    cpu.ah &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 004a5312  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a5314  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a5316  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004a5319  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x004a531e:
    // 004a531e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a531f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5320  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5321(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5321  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5323  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5324(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5324  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5325  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5326  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a5327  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5329  f6c303                 +test bl, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 3 /*0x3*/));
    // 004a532c  7523                   -jne 0x4a5351
    if (!cpu.flags.zf)
    {
        goto L_0x004a5351;
    }
    // 004a532e  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 004a5333  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5335  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a5337  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a5339  7409                   -je 0x4a5344
    if (cpu.flags.zf)
    {
        goto L_0x004a5344;
    }
L_0x004a533b:
    // 004a533b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a5340  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5341  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5342  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5343  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a5344:
    // 004a5344  b990010000             -mov ecx, 0x190
    cpu.ecx = 400 /*0x190*/;
    // 004a5349  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a534b  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a534d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a534f  74ea                   -je 0x4a533b
    if (cpu.flags.zf)
    {
        goto L_0x004a533b;
    }
L_0x004a5351:
    // 004a5351  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5353  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5354  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5355  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5356  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5357(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5357  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5358  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5359  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a535a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a535b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a535c  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004a535f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5361  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a5364  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a5366  0f85b8000000           -jne 0x4a5424
    if (!cpu.flags.zf)
    {
        goto L_0x004a5424;
    }
    // 004a536c  8d826c070000           -lea eax, [edx + 0x76c]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1900) /* 0x76c */);
    // 004a5372  e8adffffff             -call 0x4a5324
    cpu.esp -= 4;
    sub_4a5324(app, cpu);
    if (cpu.terminate) return;
    // 004a5377  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a5379  7413                   -je 0x4a538e
    if (cpu.flags.zf)
    {
        goto L_0x004a538e;
    }
    // 004a537b  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004a537e  8b3445bafc4b00         -mov esi, dword ptr [eax*2 + 0x4bfcba]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4979898) /* 0x4bfcba */ + cpu.eax * 2);
    // 004a5385  8b0445b8fc4b00         -mov eax, dword ptr [eax*2 + 0x4bfcb8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4979896) /* 0x4bfcb8 */ + cpu.eax * 2);
    // 004a538c  eb11                   -jmp 0x4a539f
    goto L_0x004a539f;
L_0x004a538e:
    // 004a538e  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004a5391  8b3445a0fc4b00         -mov esi, dword ptr [eax*2 + 0x4bfca0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4979872) /* 0x4bfca0 */ + cpu.eax * 2);
    // 004a5398  8b04459efc4b00         -mov eax, dword ptr [eax*2 + 0x4bfc9e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4979870) /* 0x4bfc9e */ + cpu.eax * 2);
L_0x004a539f:
    // 004a539f  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004a53a2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a53a5  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a53a7  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a53a9  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004a53ae  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004a53b1  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004a53b5  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004a53b9  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004a53bd  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004a53c0  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a53c4  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004a53c8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a53ca  897c2420               -mov dword ptr [esp + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 004a53ce  e8820effff             -call 0x496255
    cpu.esp -= 4;
    sub_496255(app, cpu);
    if (cpu.terminate) return;
    // 004a53d3  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a53d7  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004a53da  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a53dc  83c207                 -add edx, 7
    (cpu.edx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a53df  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 004a53e4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a53e6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a53e9  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a53eb  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a53ee  83f805                 +cmp eax, 5
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
    // 004a53f1  751f                   -jne 0x4a5412
    if (!cpu.flags.zf)
    {
        goto L_0x004a5412;
    }
    // 004a53f3  8d48ff                 -lea ecx, [eax - 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004a53f6  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004a53f8  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 004a53fb  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a53fe  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5400  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a5402  39f0                   +cmp eax, esi
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
    // 004a5404  7e08                   -jle 0x4a540e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a540e;
    }
    // 004a5406  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a5409  83e802                 +sub eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a540c  eb05                   -jmp 0x4a5413
    goto L_0x004a5413;
L_0x004a540e:
    // 004a540e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a5410  eb01                   -jmp 0x4a5413
    goto L_0x004a5413;
L_0x004a5412:
    // 004a5412  48                     -dec eax
    (cpu.eax)--;
L_0x004a5413:
    // 004a5413  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a5417  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a5419  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a541b  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a541e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5420  01d8                   +add eax, ebx
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
    // 004a5422  eb0f                   -jmp 0x4a5433
    goto L_0x004a5433;
L_0x004a5424:
    // 004a5424  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5427  7507                   -jne 0x4a5430
    if (!cpu.flags.zf)
    {
        goto L_0x004a5430;
    }
    // 004a5429  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a542c  29c8                   +sub eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a542e  eb03                   -jmp 0x4a5433
    goto L_0x004a5433;
L_0x004a5430:
    // 004a5430  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
L_0x004a5433:
    // 004a5433  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004a5436  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5437  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5438  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5439  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a543a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a543b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a543c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a543c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a543d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a543e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a543f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a5441  83782000               +cmp dword ptr [eax + 0x20], 0
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
    // 004a5445  751b                   -jne 0x4a5462
    if (!cpu.flags.zf)
    {
        goto L_0x004a5462;
    }
    // 004a5447  83792000               +cmp dword ptr [ecx + 0x20], 0
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
    // 004a544b  7515                   -jne 0x4a5462
    if (!cpu.flags.zf)
    {
        goto L_0x004a5462;
    }
    // 004a544d  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a5450  8b7910                 -mov edi, dword ptr [ecx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a5453  39fe                   +cmp esi, edi
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
    // 004a5455  7e09                   -jle 0x4a5460
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a5460;
    }
L_0x004a5457:
    // 004a5457  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a545c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a545d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a545e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a545f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a5460:
    // 004a5460  7c16                   -jl 0x4a5478
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5478;
    }
L_0x004a5462:
    // 004a5462  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a5464  e8eefeffff             -call 0x4a5357
    cpu.esp -= 4;
    sub_4a5357(app, cpu);
    if (cpu.terminate) return;
    // 004a5469  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a546b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a546d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a546f  e8e3feffff             -call 0x4a5357
    cpu.esp -= 4;
    sub_4a5357(app, cpu);
    if (cpu.terminate) return;
    // 004a5474  39c6                   +cmp esi, eax
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
    // 004a5476  7fdf                   -jg 0x4a5457
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a5457;
    }
L_0x004a5478:
    // 004a5478  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a547a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a547b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a547c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a547d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a547e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a547e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a547f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5480  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a5481  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5482  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5483  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5484  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a5487  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a5489  a14ed54c00             -mov eax, dword ptr [0x4cd54e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035342) /* 0x4cd54e */);
    // 004a548e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5490  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a5492  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004a5494  0f8484020000           -je 0x4a571e
    if (cpu.flags.zf)
    {
        goto L_0x004a571e;
    }
    // 004a549a  ba24d44c00             -mov edx, 0x4cd424
    cpu.edx = 5035044 /*0x4cd424*/;
    // 004a549f  b800d44c00             -mov eax, 0x4cd400
    cpu.eax = 5035008 /*0x4cd400*/;
    // 004a54a4  8b5914                 -mov ebx, dword ptr [ecx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004a54a7  e890ffffff             -call 0x4a543c
    cpu.esp -= 4;
    sub_4a543c(app, cpu);
    if (cpu.terminate) return;
    // 004a54ac  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a54b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a54b2  740c                   -je 0x4a54c0
    if (cpu.flags.zf)
    {
        goto L_0x004a54c0;
    }
    // 004a54b4  be24d44c00             -mov esi, 0x4cd424
    cpu.esi = 5035044 /*0x4cd424*/;
    // 004a54b9  bb00d44c00             -mov ebx, 0x4cd400
    cpu.ebx = 5035008 /*0x4cd400*/;
    // 004a54be  eb0a                   -jmp 0x4a54ca
    goto L_0x004a54ca;
L_0x004a54c0:
    // 004a54c0  be00d44c00             -mov esi, 0x4cd400
    cpu.esi = 5035008 /*0x4cd400*/;
    // 004a54c5  bb24d44c00             -mov ebx, 0x4cd424
    cpu.ebx = 5035044 /*0x4cd424*/;
L_0x004a54ca:
    // 004a54ca  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004a54cd  056c070000             -add eax, 0x76c
    (cpu.eax) += x86::reg32(x86::sreg32(1900 /*0x76c*/));
    // 004a54d2  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a54d5  e84afeffff             -call 0x4a5324
    cpu.esp -= 4;
    sub_4a5324(app, cpu);
    if (cpu.terminate) return;
    // 004a54da  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a54dc  8d442d00               -lea eax, [ebp + ebp]
    cpu.eax = x86::reg32(cpu.ebp + cpu.ebp * 1);
    // 004a54e0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a54e2  740e                   -je 0x4a54f2
    if (cpu.flags.zf)
    {
        goto L_0x004a54f2;
    }
    // 004a54e4  8b90bafc4b00           -mov edx, dword ptr [eax + 0x4bfcba]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4979898) /* 0x4bfcba */);
    // 004a54ea  8b80b8fc4b00           -mov eax, dword ptr [eax + 0x4bfcb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4979896) /* 0x4bfcb8 */);
    // 004a54f0  eb0c                   -jmp 0x4a54fe
    goto L_0x004a54fe;
L_0x004a54f2:
    // 004a54f2  8b90a0fc4b00           -mov edx, dword ptr [eax + 0x4bfca0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4979872) /* 0x4bfca0 */);
    // 004a54f8  8b809efc4b00           -mov eax, dword ptr [eax + 0x4bfc9e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4979870) /* 0x4bfc9e */);
L_0x004a54fe:
    // 004a54fe  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004a5501  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a5504  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5506  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004a550a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a550c  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004a550f  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a5513  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a5515  0f85b9000000           -jne 0x4a55d4
    if (!cpu.flags.zf)
    {
        goto L_0x004a55d4;
    }
    // 004a551b  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a551e  39d5                   +cmp ebp, edx
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
    // 004a5520  7e0a                   -jle 0x4a552c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a552c;
    }
    // 004a5522  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004a5527  e9dd000000             -jmp 0x4a5609
    goto L_0x004a5609;
L_0x004a552c:
    // 004a552c  0f85d7000000           -jne 0x4a5609
    if (!cpu.flags.zf)
    {
        goto L_0x004a5609;
    }
    // 004a5532  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004a5535  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a5538  83c207                 -add edx, 7
    (cpu.edx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a553b  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a553d  c744241807000000       -mov dword ptr [esp + 0x18], 7
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 7 /*0x7*/;
    // 004a5545  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5547  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a554a  f77c2418               -idiv dword ptr [esp + 0x18]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a554e  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a5551  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5553  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004a5556  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a555a  83c206                 -add edx, 6
    (cpu.edx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 004a555d  2b5618                 -sub edx, dword ptr [esi + 0x18]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)));
    // 004a5560  c744241807000000       -mov dword ptr [esp + 0x18], 7
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 7 /*0x7*/;
    // 004a5568  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a556a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a556d  f77c2418               -idiv dword ptr [esp + 0x18]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a5571  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a5574  48                     -dec eax
    (cpu.eax)--;
    // 004a5575  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5577  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a557a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a557e  83fa05                 +cmp edx, 5
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5581  7529                   -jne 0x4a55ac
    if (!cpu.flags.zf)
    {
        goto L_0x004a55ac;
    }
    // 004a5583  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a5587  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a558b  83e807                 -sub eax, 7
    (cpu.eax) -= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a558e  39d0                   +cmp eax, edx
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
    // 004a5590  0f8d73000000           -jge 0x4a5609
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a5609;
    }
    // 004a5596  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a559a  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004a559f  39d0                   +cmp eax, edx
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
    // 004a55a1  0f8c62000000           -jl 0x4a5609
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5609;
    }
    // 004a55a7  e964000000             -jmp 0x4a5610
    goto L_0x004a5610;
L_0x004a55ac:
    // 004a55ac  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a55af  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a55b3  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a55b7  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a55ba  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a55bc  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a55c0  40                     -inc eax
    (cpu.eax)++;
    // 004a55c1  39d0                   +cmp eax, edx
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
    // 004a55c3  7f44                   -jg 0x4a5609
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a5609;
    }
    // 004a55c5  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a55c9  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004a55ce  39d0                   +cmp eax, edx
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
    // 004a55d0  7e37                   -jle 0x4a5609
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a5609;
    }
    // 004a55d2  eb3c                   -jmp 0x4a5610
    goto L_0x004a5610;
L_0x004a55d4:
    // 004a55d4  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004a55d7  83f801                 +cmp eax, 1
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
    // 004a55da  751f                   -jne 0x4a55fb
    if (!cpu.flags.zf)
    {
        goto L_0x004a55fb;
    }
    // 004a55dc  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004a55df  056c070000             -add eax, 0x76c
    (cpu.eax) += x86::reg32(x86::sreg32(1900 /*0x76c*/));
    // 004a55e4  e83bfdffff             -call 0x4a5324
    cpu.esp -= 4;
    sub_4a5324(app, cpu);
    if (cpu.terminate) return;
    // 004a55e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a55eb  740d                   -je 0x4a55fa
    if (cpu.flags.zf)
    {
        goto L_0x004a55fa;
    }
    // 004a55ed  a1a2fc4b00             -mov eax, dword ptr [0x4bfca2]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4979874) /* 0x4bfca2 */);
    // 004a55f2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a55f5  39c2                   +cmp edx, eax
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
    // 004a55f7  7e01                   -jle 0x4a55fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a55fa;
    }
    // 004a55f9  42                     -inc edx
    (cpu.edx)++;
L_0x004a55fa:
    // 004a55fa  4a                     -dec edx
    (cpu.edx)--;
L_0x004a55fb:
    // 004a55fb  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004a55fe  39c2                   +cmp edx, eax
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
    // 004a5600  7f07                   -jg 0x4a5609
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a5609;
    }
    // 004a5602  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004a5607  7407                   -je 0x4a5610
    if (cpu.flags.zf)
    {
        goto L_0x004a5610;
    }
L_0x004a5609:
    // 004a5609  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004a560e  7416                   -je 0x4a5626
    if (cpu.flags.zf)
    {
        goto L_0x004a5626;
    }
L_0x004a5610:
    // 004a5610  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a5612  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a5614  e814010000             -call 0x4a572d
    cpu.esp -= 4;
    sub_4a572d(app, cpu);
    if (cpu.terminate) return;
    // 004a5619  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a561b  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 004a561e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a5620  81e7ff000000           -and edi, 0xff
    cpu.edi &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x004a5626:
    // 004a5626  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a5628  7513                   -jne 0x4a563d
    if (!cpu.flags.zf)
    {
        goto L_0x004a563d;
    }
    // 004a562a  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a562e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a5630  0f84e8000000           -je 0x4a571e
    if (cpu.flags.zf)
    {
        goto L_0x004a571e;
    }
    // 004a5636  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a5638  e9e1000000             -jmp 0x4a571e
    goto L_0x004a571e;
L_0x004a563d:
    // 004a563d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a563f  8b7320                 -mov esi, dword ptr [ebx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004a5642  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a5645  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a5647  0f857f000000           -jne 0x4a56cc
    if (!cpu.flags.zf)
    {
        goto L_0x004a56cc;
    }
    // 004a564d  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004a5650  39c5                   +cmp ebp, eax
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
    // 004a5652  7e07                   -jle 0x4a565b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a565b;
    }
    // 004a5654  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004a5656  e9a6000000             -jmp 0x4a5701
    goto L_0x004a5701;
L_0x004a565b:
    // 004a565b  0f85a0000000           -jne 0x4a5701
    if (!cpu.flags.zf)
    {
        goto L_0x004a5701;
    }
    // 004a5661  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004a5664  8b7318                 -mov esi, dword ptr [ebx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004a5667  83c207                 -add edx, 7
    (cpu.edx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a566a  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a566c  be07000000             -mov esi, 7
    cpu.esi = 7 /*0x7*/;
    // 004a5671  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5673  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a5676  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a5678  8b690c                 -mov ebp, dword ptr [ecx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a567b  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a567d  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004a5680  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004a5683  83c206                 -add edx, 6
    (cpu.edx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 004a5686  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5688  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a568a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a568d  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a568f  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a5692  48                     -dec eax
    (cpu.eax)--;
    // 004a5693  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a5695  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5697  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a569a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a569c  83fe05                 +cmp esi, 5
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a569f  7518                   -jne 0x4a56b9
    if (!cpu.flags.zf)
    {
        goto L_0x004a56b9;
    }
    // 004a56a1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a56a5  83e807                 -sub eax, 7
    (cpu.eax) -= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a56a8  39c5                   +cmp ebp, eax
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
    // 004a56aa  7f07                   -jg 0x4a56b3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a56b3;
    }
L_0x004a56ac:
    // 004a56ac  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004a56b1  eb4e                   -jmp 0x4a5701
    goto L_0x004a5701;
L_0x004a56b3:
    // 004a56b3  39c2                   +cmp edx, eax
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
    // 004a56b5  7f4a                   -jg 0x4a5701
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a5701;
    }
    // 004a56b7  eb4e                   -jmp 0x4a5707
    goto L_0x004a5707;
L_0x004a56b9:
    // 004a56b9  4e                     -dec esi
    (cpu.esi)--;
    // 004a56ba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a56bc  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a56bf  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a56c1  40                     -inc eax
    (cpu.eax)++;
    // 004a56c2  39c5                   +cmp ebp, eax
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
    // 004a56c4  7ce6                   -jl 0x4a56ac
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a56ac;
    }
    // 004a56c6  39c2                   +cmp edx, eax
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
    // 004a56c8  7d37                   -jge 0x4a5701
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a5701;
    }
    // 004a56ca  eb3b                   -jmp 0x4a5707
    goto L_0x004a5707;
L_0x004a56cc:
    // 004a56cc  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004a56cf  83fe01                 +cmp esi, 1
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
    // 004a56d2  7520                   -jne 0x4a56f4
    if (!cpu.flags.zf)
    {
        goto L_0x004a56f4;
    }
    // 004a56d4  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004a56d7  056c070000             -add eax, 0x76c
    (cpu.eax) += x86::reg32(x86::sreg32(1900 /*0x76c*/));
    // 004a56dc  e843fcffff             -call 0x4a5324
    cpu.esp -= 4;
    sub_4a5324(app, cpu);
    if (cpu.terminate) return;
    // 004a56e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a56e3  740e                   -je 0x4a56f3
    if (cpu.flags.zf)
    {
        goto L_0x004a56f3;
    }
    // 004a56e5  a1a2fc4b00             -mov eax, dword ptr [0x4bfca2]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4979874) /* 0x4bfca2 */);
    // 004a56ea  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a56ed  39c2                   +cmp edx, eax
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
    // 004a56ef  7e02                   -jle 0x4a56f3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a56f3;
    }
    // 004a56f1  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004a56f3:
    // 004a56f3  4a                     -dec edx
    (cpu.edx)--;
L_0x004a56f4:
    // 004a56f4  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004a56f7  39c2                   +cmp edx, eax
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
    // 004a56f9  7f06                   -jg 0x4a5701
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a5701;
    }
    // 004a56fb  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a56fd  39c2                   +cmp edx, eax
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
    // 004a56ff  7406                   -je 0x4a5707
    if (cpu.flags.zf)
    {
        goto L_0x004a5707;
    }
L_0x004a5701:
    // 004a5701  833c2400               +cmp dword ptr [esp], 0
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
    // 004a5705  740b                   -je 0x4a5712
    if (cpu.flags.zf)
    {
        goto L_0x004a5712;
    }
L_0x004a5707:
    // 004a5707  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a5709  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a570b  e81d000000             -call 0x4a572d
    cpu.esp -= 4;
    sub_4a572d(app, cpu);
    if (cpu.terminate) return;
    // 004a5710  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004a5712:
    // 004a5712  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a5716  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a5718  7404                   -je 0x4a571e
    if (cpu.flags.zf)
    {
        goto L_0x004a571e;
    }
    // 004a571a  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004a571c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004a571e:
    // 004a571e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a5720  897920                 -mov dword ptr [ecx + 0x20], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 004a5723  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a5726  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5727  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5728  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5729  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a572a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a572b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a572c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a572d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a572d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a572e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a572f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5730  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5731  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a5734  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a5737  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a5739  39f1                   +cmp ecx, esi
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
    // 004a573b  7c14                   -jl 0x4a5751
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5751;
    }
    // 004a573d  7517                   -jne 0x4a5756
    if (!cpu.flags.zf)
    {
        goto L_0x004a5756;
    }
    // 004a573f  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a5742  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a5745  39e9                   +cmp ecx, ebp
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
    // 004a5747  7c08                   -jl 0x4a5751
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5751;
    }
    // 004a5749  750b                   -jne 0x4a5756
    if (!cpu.flags.zf)
    {
        goto L_0x004a5756;
    }
    // 004a574b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a574d  3b02                   +cmp eax, dword ptr [edx]
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
    // 004a574f  7d05                   -jge 0x4a5756
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a5756;
    }
L_0x004a5751:
    // 004a5751  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004a5756:
    // 004a5756  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a5758  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5759  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a575a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a575b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a575c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a575d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a575d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a575e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a575f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5760  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a5762  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a5764  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a5766  81fac0a80000           +cmp edx, 0xa8c0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43200 /*0xa8c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a576c  731c                   -jae 0x4a578a
    if (!cpu.flags.cf)
    {
        goto L_0x004a578a;
    }
    // 004a576e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a5770  7e18                   -jle 0x4a578a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a578a;
    }
    // 004a5772  8db280510100           -lea esi, [edx + 0x15180]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(86400) /* 0x15180 */);
    // 004a5778  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a577a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a577c  bb80510100             -mov ebx, 0x15180
    cpu.ebx = 86400 /*0x15180*/;
    // 004a5781  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5783  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a5785  01c7                   +add edi, eax
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
    // 004a5787  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a5788  eb0f                   -jmp 0x4a5799
    goto L_0x004a5799;
L_0x004a578a:
    // 004a578a  bb80510100             -mov ebx, 0x15180
    cpu.ebx = 86400 /*0x15180*/;
    // 004a578f  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5791  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5793  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5795  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a5797  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a5799:
    // 004a5799  bb80510100             -mov ebx, 0x15180
    cpu.ebx = 86400 /*0x15180*/;
    // 004a579e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a57a0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a57a2  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a57a4  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a57a6  be100e0000             -mov esi, 0xe10
    cpu.esi = 3600 /*0xe10*/;
    // 004a57ab  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a57ad  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a57af  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a57b1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a57b3  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a57b6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a57b8  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a57ba  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a57bc  be3c000000             -mov esi, 0x3c
    cpu.esi = 60 /*0x3c*/;
    // 004a57c1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a57c3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a57c5  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a57c7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a57c9  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a57cc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a57ce  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a57d0  bb6e010000             -mov ebx, 0x16e
    cpu.ebx = 366 /*0x16e*/;
    // 004a57d5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a57d7  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004a57d9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a57db  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a57dd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a57df  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a57e2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a57e4  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a57e7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a57e9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a57eb  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a57ee  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a57f0  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a57f2  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a57f4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a57f6  7608                   -jbe 0x4a5800
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a5800;
    }
    // 004a57f8  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a57fb  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004a57fe  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a5800:
    // 004a5800  8d826c070000           -lea eax, [edx + 0x76c]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1900) /* 0x76c */);
    // 004a5806  e819fbffff             -call 0x4a5324
    cpu.esp -= 4;
    sub_4a5324(app, cpu);
    if (cpu.terminate) return;
    // 004a580b  056d010000             -add eax, 0x16d
    (cpu.eax) += x86::reg32(x86::sreg32(365 /*0x16d*/));
L_0x004a5810:
    // 004a5810  39c3                   +cmp ebx, eax
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
    // 004a5812  7205                   -jb 0x4a5819
    if (cpu.flags.cf)
    {
        goto L_0x004a5819;
    }
    // 004a5814  42                     -inc edx
    (cpu.edx)++;
    // 004a5815  29c3                   +sub ebx, eax
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5817  ebf7                   -jmp 0x4a5810
    goto L_0x004a5810;
L_0x004a5819:
    // 004a5819  bea0fc4b00             -mov esi, 0x4bfca0
    cpu.esi = 4979872 /*0x4bfca0*/;
    // 004a581e  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004a5821  8d826c070000           -lea eax, [edx + 0x76c]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1900) /* 0x76c */);
    // 004a5827  89591c                 -mov dword ptr [ecx + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004a582a  e8f5faffff             -call 0x4a5324
    cpu.esp -= 4;
    sub_4a5324(app, cpu);
    if (cpu.terminate) return;
    // 004a582f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a5831  7405                   -je 0x4a5838
    if (cpu.flags.zf)
    {
        goto L_0x004a5838;
    }
    // 004a5833  bebafc4b00             -mov esi, 0x4bfcba
    cpu.esi = 4979898 /*0x4bfcba*/;
L_0x004a5838:
    // 004a5838  bd1f000000             -mov ebp, 0x1f
    cpu.ebp = 31 /*0x1f*/;
    // 004a583d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a583f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5841  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a5843  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5845  8b1456                 -mov edx, dword ptr [esi + edx*2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 2);
    // 004a5848  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004a584b  39d3                   +cmp ebx, edx
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
    // 004a584d  7201                   -jb 0x4a5850
    if (cpu.flags.cf)
    {
        goto L_0x004a5850;
    }
    // 004a584f  40                     -inc eax
    (cpu.eax)++;
L_0x004a5850:
    // 004a5850  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a5853  0fbf0446               -movsx eax, word ptr [esi + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2)));
    // 004a5857  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5859  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a585b  43                     -inc ebx
    (cpu.ebx)++;
    // 004a585c  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a585f  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004a5862  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 004a5867  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a5869  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a586b  895118                 -mov dword ptr [ecx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004a586e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a586f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5870  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5871  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5872(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5872  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5873  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5874  c7422000000000         -mov dword ptr [edx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004a587b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a587d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a587f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a5881  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5883  b8df630000             -mov eax, 0x63df
    cpu.eax = 25567 /*0x63df*/;
    // 004a5888  e8d0feffff             -call 0x4a575d
    cpu.esp -= 4;
    sub_4a575d(app, cpu);
    if (cpu.terminate) return;
    // 004a588d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a588e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a588f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5890  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5891  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a5892  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5894  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a589a  8d5014                 -lea edx, [eax + 0x14]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004a589d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a589f  e8ceffffff             -call 0x4a5872
    cpu.esp -= 4;
    sub_4a5872(app, cpu);
    if (cpu.terminate) return;
    // 004a58a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a58a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a58a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a58a7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a58a7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a58a8  8a155ed54c00           -mov dl, byte ptr [0x4cd55e]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5035358) /* 0x4cd55e */);
    // 004a58ae  a15ed54c00             -mov eax, dword ptr [0x4cd55e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035358) /* 0x4cd55e */);
    // 004a58b3  80e2fc                 -and dl, 0xfc
    cpu.dl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004a58b6  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a58b9  88155ed54c00           -mov byte ptr [0x4cd55e], dl
    app->getMemory<x86::reg8>(x86::reg32(5035358) /* 0x4cd55e */) = cpu.dl;
    // 004a58bf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a58c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a58c1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a58c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a58c2  8a155ed54c00           -mov dl, byte ptr [0x4cd55e]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5035358) /* 0x4cd55e */);
    // 004a58c8  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004a58cb  a15ed54c00             -mov eax, dword ptr [0x4cd55e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035358) /* 0x4cd55e */);
    // 004a58d0  88155ed54c00           -mov byte ptr [0x4cd55e], dl
    app->getMemory<x86::reg8>(x86::reg32(5035358) /* 0x4cd55e */) = cpu.dl;
    // 004a58d6  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 004a58d8  80e6fd                 -and dh, 0xfd
    cpu.dh &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 004a58db  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a58de  88355ed54c00           -mov byte ptr [0x4cd55e], dh
    app->getMemory<x86::reg8>(x86::reg32(5035358) /* 0x4cd55e */) = cpu.dh;
    // 004a58e4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a58e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a58e6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a58e6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a58e7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a58e8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a58e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a58ea  81ecac000000           -sub esp, 0xac
    (cpu.esp) -= x86::reg32(x86::sreg32(172 /*0xac*/));
    // 004a58f0  8a255ed54c00           -mov ah, byte ptr [0x4cd55e]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5035358) /* 0x4cd55e */);
    // 004a58f6  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 004a58f9  7409                   -je 0x4a5904
    if (cpu.flags.zf)
    {
        goto L_0x004a5904;
    }
    // 004a58fb  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 004a58fe  0f85cd000000           -jne 0x4a59d1
    if (!cpu.flags.zf)
    {
        goto L_0x004a59d1;
    }
L_0x004a5904:
    // 004a5904  8a355ed54c00           -mov dh, byte ptr [0x4cd55e]
    cpu.dh = app->getMemory<x86::reg8>(x86::reg32(5035358) /* 0x4cd55e */);
    // 004a590a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a590c  80ce02                 -or dh, 2
    cpu.dh |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004a590f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a5910  88355ed54c00           -mov byte ptr [0x4cd55e], dh
    app->getMemory<x86::reg8>(x86::reg32(5035358) /* 0x4cd55e */) = cpu.dh;
    // 004a5916  2eff15f8544b00         -call dword ptr cs:[0x4b54f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936952) /* 0x4b54f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a591d  83f801                 +cmp eax, 1
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
    // 004a5920  0f82ab000000           -jb 0x4a59d1
    if (cpu.flags.cf)
    {
        goto L_0x004a59d1;
    }
    // 004a5926  7635                   -jbe 0x4a595d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a595d;
    }
    // 004a5928  83f802                 +cmp eax, 2
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
    // 004a592b  0f85a0000000           -jne 0x4a59d1
    if (!cpu.flags.zf)
    {
        goto L_0x004a59d1;
    }
    // 004a5931  c70556d54c0001000000   -mov dword ptr [0x4cd556], 1
    app->getMemory<x86::reg32>(x86::reg32(5035350) /* 0x4cd556 */) = 1 /*0x1*/;
    // 004a593b  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 004a5942  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5944  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004a5947  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5949  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a594c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a594e  a35ad54c00             -mov dword ptr [0x4cd55a], eax
    app->getMemory<x86::reg32>(x86::reg32(5035354) /* 0x4cd55a */) = cpu.eax;
    // 004a5953  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 004a5955  891d5ad54c00           -mov dword ptr [0x4cd55a], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035354) /* 0x4cd55a */) = cpu.ebx;
    // 004a595b  eb08                   -jmp 0x4a5965
    goto L_0x004a5965;
L_0x004a595d:
    // 004a595d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a595f  890d56d54c00           -mov dword ptr [0x4cd556], ecx
    app->getMemory<x86::reg32>(x86::reg32(5035350) /* 0x4cd556 */) = cpu.ecx;
L_0x004a5965:
    // 004a5965  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004a5969  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a596c  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a596e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5970  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004a5973  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5975  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 004a597a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a597d  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a5981  a352d54c00             -mov dword ptr [0x4cd552], eax
    app->getMemory<x86::reg32>(x86::reg32(5035346) /* 0x4cd552 */) = cpu.eax;
    // 004a5986  b848d44c00             -mov eax, 0x4cd448
    cpu.eax = 5035080 /*0x4cd448*/;
    // 004a598b  e854680000             -call 0x4ac1e4
    cpu.esp -= 4;
    sub_4ac1e4(app, cpu);
    if (cpu.terminate) return;
    // 004a5990  83f8ff                 +cmp eax, -1
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
    // 004a5993  750a                   -jne 0x4a599f
    if (!cpu.flags.zf)
    {
        goto L_0x004a599f;
    }
    // 004a5995  30ff                   +xor bh, bh
    cpu.clear_co();
    cpu.set_szp((cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh))));
    // 004a5997  883d48d44c00           -mov byte ptr [0x4cd448], bh
    app->getMemory<x86::reg8>(x86::reg32(5035080) /* 0x4cd448 */) = cpu.bh;
    // 004a599d  eb08                   -jmp 0x4a59a7
    goto L_0x004a59a7;
L_0x004a599f:
    // 004a599f  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004a59a1  881dc8d44c00           -mov byte ptr [0x4cd4c8], bl
    app->getMemory<x86::reg8>(x86::reg32(5035208) /* 0x4cd4c8 */) = cpu.bl;
L_0x004a59a7:
    // 004a59a7  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 004a59ac  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004a59b0  b8c9d44c00             -mov eax, 0x4cd4c9
    cpu.eax = 5035209 /*0x4cd4c9*/;
    // 004a59b5  e82a680000             -call 0x4ac1e4
    cpu.esp -= 4;
    sub_4ac1e4(app, cpu);
    if (cpu.terminate) return;
    // 004a59ba  83f8ff                 +cmp eax, -1
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
    // 004a59bd  750a                   -jne 0x4a59c9
    if (!cpu.flags.zf)
    {
        goto L_0x004a59c9;
    }
    // 004a59bf  30ed                   +xor ch, ch
    cpu.clear_co();
    cpu.set_szp((cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch))));
    // 004a59c1  882dc9d44c00           -mov byte ptr [0x4cd4c9], ch
    app->getMemory<x86::reg8>(x86::reg32(5035209) /* 0x4cd4c9 */) = cpu.ch;
    // 004a59c7  eb08                   -jmp 0x4a59d1
    goto L_0x004a59d1;
L_0x004a59c9:
    // 004a59c9  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 004a59cb  880d49d54c00           -mov byte ptr [0x4cd549], cl
    app->getMemory<x86::reg8>(x86::reg32(5035337) /* 0x4cd549 */) = cpu.cl;
L_0x004a59d1:
    // 004a59d1  81c4ac000000           -add esp, 0xac
    (cpu.esp) += x86::reg32(x86::sreg32(172 /*0xac*/));
    // 004a59d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a59d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a59d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a59da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a59db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a59dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a59dc  b800f64b00             -mov eax, 0x4bf600
    cpu.eax = 4978176 /*0x4bf600*/;
    // 004a59e1  e813430000             -call 0x4a9cf9
    cpu.esp -= 4;
    sub_4a9cf9(app, cpu);
    if (cpu.terminate) return;
    // 004a59e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a59e8  0f84f8feffff           -je 0x4a58e6
    if (cpu.flags.zf)
    {
        return sub_4a58e6(app, cpu);
    }
    // 004a59ee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a59ef  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a59f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a59f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a59f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a59f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a59f4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a59f7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a59f9  bb52d54c00             -mov ebx, 0x4cd552
    cpu.ebx = 5035346 /*0x4cd552*/;
    // 004a59fe  891556d54c00           -mov dword ptr [0x4cd556], edx
    app->getMemory<x86::reg32>(x86::reg32(5035350) /* 0x4cd556 */) = cpu.edx;
    // 004a5a04  ba48d44c00             -mov edx, 0x4cd448
    cpu.edx = 5035080 /*0x4cd448*/;
    // 004a5a09  e83d000000             -call 0x4a5a4b
    cpu.esp -= 4;
    sub_4a5a4b(app, cpu);
    if (cpu.terminate) return;
    // 004a5a0e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a5a10  8a20                   -mov ah, byte ptr [eax]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5a12  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004a5a14  0f8534020000           -jne 0x4a5c4e
    if (!cpu.flags.zf)
    {
        return sub_4a5c4e(app, cpu);
    }
    // 004a5a1a  8825c9d44c00           -mov byte ptr [0x4cd4c9], ah
    app->getMemory<x86::reg8>(x86::reg32(5035209) /* 0x4cd4c9 */) = cpu.ah;
    // 004a5a20  e9e7020000             -jmp 0x4a5d0c
    return sub_4a5d0c(app, cpu);
}

/* align: skip  */
void Application::sub_4a5a25(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5a25  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5a26  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5a27  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a5a29  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a5a2b:
    // 004a5a2b  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5a2d  80fb30                 +cmp bl, 0x30
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5a30  7214                   -jb 0x4a5a46
    if (cpu.flags.cf)
    {
        goto L_0x004a5a46;
    }
    // 004a5a32  80fb39                 +cmp bl, 0x39
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5a35  770f                   -ja 0x4a5a46
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a5a46;
    }
    // 004a5a37  6bd20a                 -imul edx, edx, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004a5a3a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a5a3c  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5a3e  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a5a40  40                     -inc eax
    (cpu.eax)++;
    // 004a5a41  83ea30                 +sub edx, 0x30
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5a44  ebe5                   -jmp 0x4a5a2b
    goto L_0x004a5a2b;
L_0x004a5a46:
    // 004a5a46  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004a5a48  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5a49  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5a4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5a4b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5a4b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5a4c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5a4d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5a4e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5a4f  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a5a52  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a5a54  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a5a57  80383a                 +cmp byte ptr [eax], 0x3a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5a5a  7501                   -jne 0x4a5a5d
    if (!cpu.flags.zf)
    {
        goto L_0x004a5a5d;
    }
    // 004a5a5c  45                     -inc ebp
    (cpu.ebp)++;
L_0x004a5a5d:
    // 004a5a5d  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x004a5a5f:
    // 004a5a5f  8a5500                 -mov dl, byte ptr [ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp);
    // 004a5a62  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004a5a64  741c                   -je 0x4a5a82
    if (cpu.flags.zf)
    {
        goto L_0x004a5a82;
    }
    // 004a5a66  80fa2c                 +cmp dl, 0x2c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5a69  7417                   -je 0x4a5a82
    if (cpu.flags.zf)
    {
        goto L_0x004a5a82;
    }
    // 004a5a6b  80fa2d                 +cmp dl, 0x2d
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
    // 004a5a6e  7412                   -je 0x4a5a82
    if (cpu.flags.zf)
    {
        goto L_0x004a5a82;
    }
    // 004a5a70  80fa2b                 +cmp dl, 0x2b
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
    // 004a5a73  740d                   -je 0x4a5a82
    if (cpu.flags.zf)
    {
        goto L_0x004a5a82;
    }
    // 004a5a75  80fa30                 +cmp dl, 0x30
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
    // 004a5a78  7205                   -jb 0x4a5a7f
    if (cpu.flags.cf)
    {
        goto L_0x004a5a7f;
    }
    // 004a5a7a  80fa39                 +cmp dl, 0x39
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
    // 004a5a7d  7603                   -jbe 0x4a5a82
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a5a82;
    }
L_0x004a5a7f:
    // 004a5a7f  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a5a80  ebdd                   -jmp 0x4a5a5f
    goto L_0x004a5a5f;
L_0x004a5a82:
    // 004a5a82  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a5a84  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a5a86  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a5a8a  3d80000000             +cmp eax, 0x80
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5a8f  7e08                   -jle 0x4a5a99
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a5a99;
    }
    // 004a5a91  c744241080000000       -mov dword ptr [esp + 0x10], 0x80
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 128 /*0x80*/;
L_0x004a5a99:
    // 004a5a99  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a5a9d  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a5aa0  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a5aa1  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a5aa3  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a5aa5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5aa6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a5aa8  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004a5aab  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a5aad  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a5aaf  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004a5ab2  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004a5ab4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5ab5  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a5ab6  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a5aba  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 004a5abd  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004a5ac0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5ac2  8d4501                 -lea eax, [ebp + 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004a5ac5  80fa2d                 +cmp dl, 0x2d
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
    // 004a5ac8  7507                   -jne 0x4a5ad1
    if (!cpu.flags.zf)
    {
        goto L_0x004a5ad1;
    }
    // 004a5aca  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004a5acf  eb05                   -jmp 0x4a5ad6
    goto L_0x004a5ad6;
L_0x004a5ad1:
    // 004a5ad1  80fa2b                 +cmp dl, 0x2b
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
    // 004a5ad4  7502                   -jne 0x4a5ad8
    if (!cpu.flags.zf)
    {
        goto L_0x004a5ad8;
    }
L_0x004a5ad6:
    // 004a5ad6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x004a5ad8:
    // 004a5ad8  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 004a5adb  3c30                   +cmp al, 0x30
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
    // 004a5add  0f8273000000           -jb 0x4a5b56
    if (cpu.flags.cf)
    {
        goto L_0x004a5b56;
    }
    // 004a5ae3  3c39                   +cmp al, 0x39
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
    // 004a5ae5  776f                   -ja 0x4a5b56
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a5b56;
    }
    // 004a5ae7  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a5aeb  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a5aed  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a5aef  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004a5af3  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004a5af7  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004a5afb  e825ffffff             -call 0x4a5a25
    cpu.esp -= 4;
    sub_4a5a25(app, cpu);
    if (cpu.terminate) return;
    // 004a5b00  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5b02  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a5b04  80fa3a                 +cmp dl, 0x3a
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5b07  751f                   -jne 0x4a5b28
    if (!cpu.flags.zf)
    {
        goto L_0x004a5b28;
    }
    // 004a5b09  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a5b0d  40                     -inc eax
    (cpu.eax)++;
    // 004a5b0e  e812ffffff             -call 0x4a5a25
    cpu.esp -= 4;
    sub_4a5a25(app, cpu);
    if (cpu.terminate) return;
    // 004a5b13  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5b15  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a5b17  80fe3a                 +cmp dh, 0x3a
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5b1a  750c                   -jne 0x4a5b28
    if (!cpu.flags.zf)
    {
        goto L_0x004a5b28;
    }
    // 004a5b1c  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a5b20  40                     -inc eax
    (cpu.eax)++;
    // 004a5b21  e8fffeffff             -call 0x4a5a25
    cpu.esp -= 4;
    sub_4a5a25(app, cpu);
    if (cpu.terminate) return;
    // 004a5b26  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x004a5b28:
    // 004a5b28  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a5b2c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5b2e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004a5b31  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a5b33  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a5b37  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a5b3a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a5b3c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5b3e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004a5b41  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5b43  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a5b47  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a5b4a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a5b4c  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a5b4e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a5b50  7404                   -je 0x4a5b56
    if (cpu.flags.zf)
    {
        goto L_0x004a5b56;
    }
    // 004a5b52  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004a5b54  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x004a5b56:
    // 004a5b56  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a5b58  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a5b5b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5b5c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5b5d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5b5e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5b5f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5b60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5b60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5b61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5b62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5b63  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a5b66  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5b68  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a5b6a  8a20                   -mov ah, byte ptr [eax]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5b6c  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 004a5b71  80fc4a                 +cmp ah, 0x4a
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(74 /*0x4a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5b74  7507                   -jne 0x4a5b7d
    if (!cpu.flags.zf)
    {
        goto L_0x004a5b7d;
    }
    // 004a5b76  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a5b7b  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004a5b7d:
    // 004a5b7d  803b4d                 +cmp byte ptr [ebx], 0x4d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(77 /*0x4d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5b80  7503                   -jne 0x4a5b85
    if (!cpu.flags.zf)
    {
        goto L_0x004a5b85;
    }
    // 004a5b82  43                     -inc ebx
    (cpu.ebx)++;
    // 004a5b83  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004a5b85:
    // 004a5b85  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a5b89  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a5b8b  897120                 -mov dword ptr [ecx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004a5b8e  e892feffff             -call 0x4a5a25
    cpu.esp -= 4;
    sub_4a5a25(app, cpu);
    if (cpu.terminate) return;
    // 004a5b93  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5b95  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5b97  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a5b99  7409                   -je 0x4a5ba4
    if (cpu.flags.zf)
    {
        goto L_0x004a5ba4;
    }
    // 004a5b9b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a5b9f  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004a5ba2  eb45                   -jmp 0x4a5be9
    goto L_0x004a5be9;
L_0x004a5ba4:
    // 004a5ba4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a5ba8  48                     -dec eax
    (cpu.eax)--;
    // 004a5ba9  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a5bac  803a2e                 +cmp byte ptr [edx], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5baf  7531                   -jne 0x4a5be2
    if (!cpu.flags.zf)
    {
        goto L_0x004a5be2;
    }
    // 004a5bb1  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a5bb4  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a5bb8  e868feffff             -call 0x4a5a25
    cpu.esp -= 4;
    sub_4a5a25(app, cpu);
    if (cpu.terminate) return;
    // 004a5bbd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5bbf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5bc1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a5bc5  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a5bc8  803a2e                 +cmp byte ptr [edx], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5bcb  7515                   -jne 0x4a5be2
    if (!cpu.flags.zf)
    {
        goto L_0x004a5be2;
    }
    // 004a5bcd  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a5bd0  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a5bd4  e84cfeffff             -call 0x4a5a25
    cpu.esp -= 4;
    sub_4a5a25(app, cpu);
    if (cpu.terminate) return;
    // 004a5bd9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5bdb  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a5bdf  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x004a5be2:
    // 004a5be2  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
L_0x004a5be9:
    // 004a5be9  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004a5bee  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a5bf0  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a5bf4  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004a5bf7  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004a5bfb  803b2f                 +cmp byte ptr [ebx], 0x2f
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5bfe  7532                   -jne 0x4a5c32
    if (!cpu.flags.zf)
    {
        goto L_0x004a5c32;
    }
    // 004a5c00  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a5c04  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a5c07  e819feffff             -call 0x4a5a25
    cpu.esp -= 4;
    sub_4a5a25(app, cpu);
    if (cpu.terminate) return;
    // 004a5c0c  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5c0e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5c10  80fe3a                 +cmp dh, 0x3a
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5c13  751d                   -jne 0x4a5c32
    if (!cpu.flags.zf)
    {
        goto L_0x004a5c32;
    }
    // 004a5c15  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a5c19  40                     -inc eax
    (cpu.eax)++;
    // 004a5c1a  e806feffff             -call 0x4a5a25
    cpu.esp -= 4;
    sub_4a5a25(app, cpu);
    if (cpu.terminate) return;
    // 004a5c1f  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5c21  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5c23  80fa3a                 +cmp dl, 0x3a
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5c26  750a                   -jne 0x4a5c32
    if (!cpu.flags.zf)
    {
        goto L_0x004a5c32;
    }
    // 004a5c28  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004a5c2a  40                     -inc eax
    (cpu.eax)++;
    // 004a5c2b  e8f5fdffff             -call 0x4a5a25
    cpu.esp -= 4;
    sub_4a5a25(app, cpu);
    if (cpu.terminate) return;
    // 004a5c30  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004a5c32:
    // 004a5c32  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a5c35  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004a5c37  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a5c3b  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a5c3e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a5c42  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a5c45  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a5c47  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a5c4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c4b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5c4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5c4e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5c4e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004a5c53  bac9d44c00             -mov edx, 0x4cd4c9
    cpu.edx = 5035209 /*0x4cd4c9*/;
    // 004a5c58  a152d54c00             -mov eax, dword ptr [0x4cd552]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035346) /* 0x4cd552 */);
    // 004a5c5d  891d56d54c00           -mov dword ptr [0x4cd556], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035350) /* 0x4cd556 */) = cpu.ebx;
    // 004a5c63  2d100e0000             -sub eax, 0xe10
    (cpu.eax) -= x86::reg32(x86::sreg32(3600 /*0xe10*/));
    // 004a5c68  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004a5c6a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a5c6d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a5c6f  e8d7fdffff             -call 0x4a5a4b
    cpu.esp -= 4;
    sub_4a5a4b(app, cpu);
    if (cpu.terminate) return;
    // 004a5c74  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a5c77  8b1d52d54c00           -mov ebx, dword ptr [0x4cd552]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5035346) /* 0x4cd552 */);
    // 004a5c7d  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5c7f  891d5ad54c00           -mov dword ptr [0x4cd55a], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035354) /* 0x4cd55a */) = cpu.ebx;
    // 004a5c85  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5c87  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5c89  80fb2c                 +cmp bl, 0x2c
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5c8c  750d                   -jne 0x4a5c9b
    if (!cpu.flags.zf)
    {
        goto L_0x004a5c9b;
    }
    // 004a5c8e  ba00d44c00             -mov edx, 0x4cd400
    cpu.edx = 5035008 /*0x4cd400*/;
    // 004a5c93  40                     -inc eax
    (cpu.eax)++;
    // 004a5c94  e8c7feffff             -call 0x4a5b60
    cpu.esp -= 4;
    sub_4a5b60(app, cpu);
    if (cpu.terminate) return;
    // 004a5c99  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004a5c9b:
    // 004a5c9b  803a2c                 +cmp byte ptr [edx], 0x2c
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5c9e  756c                   -jne 0x4a5d0c
    if (!cpu.flags.zf)
    {
        goto L_0x004a5d0c;
    }
    // 004a5ca0  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a5ca3  ba24d44c00             -mov edx, 0x4cd424
    cpu.edx = 5035044 /*0x4cd424*/;
    // 004a5ca8  e8b3feffff             -call 0x4a5b60
    cpu.esp -= 4;
    sub_4a5b60(app, cpu);
    if (cpu.terminate) return;
    // 004a5cad  a15ad54c00             -mov eax, dword ptr [0x4cd55a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035354) /* 0x4cd55a */);
    // 004a5cb2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5cb4  bb100e0000             -mov ebx, 0xe10
    cpu.ebx = 3600 /*0xe10*/;
    // 004a5cb9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a5cbc  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a5cbe  8b352cd44c00           -mov esi, dword ptr [0x4cd42c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5035052) /* 0x4cd42c */);
    // 004a5cc4  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5cc6  a15ad54c00             -mov eax, dword ptr [0x4cd55a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035354) /* 0x4cd55a */);
    // 004a5ccb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5ccd  bb3c000000             -mov ebx, 0x3c
    cpu.ebx = 60 /*0x3c*/;
    // 004a5cd2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a5cd5  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a5cd7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5cd9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a5cdc  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a5cde  8b3d28d44c00           -mov edi, dword ptr [0x4cd428]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5035048) /* 0x4cd428 */);
    // 004a5ce4  a15ad54c00             -mov eax, dword ptr [0x4cd55a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035354) /* 0x4cd55a */);
    // 004a5ce9  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5ceb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5ced  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a5cf0  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a5cf2  8b2d24d44c00           -mov ebp, dword ptr [0x4cd424]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5035044) /* 0x4cd424 */);
    // 004a5cf8  89352cd44c00           -mov dword ptr [0x4cd42c], esi
    app->getMemory<x86::reg32>(x86::reg32(5035052) /* 0x4cd42c */) = cpu.esi;
    // 004a5cfe  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5d00  893d28d44c00           -mov dword ptr [0x4cd428], edi
    app->getMemory<x86::reg32>(x86::reg32(5035048) /* 0x4cd428 */) = cpu.edi;
    // 004a5d06  892d24d44c00           -mov dword ptr [0x4cd424], ebp
    app->getMemory<x86::reg32>(x86::reg32(5035044) /* 0x4cd424 */) = cpu.ebp;
L_0x004a5d0c:
    // 004a5d0c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a5d0f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d10  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d11  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d12  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5d0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a5d0c;
    // 004a5c4e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004a5c53  bac9d44c00             -mov edx, 0x4cd4c9
    cpu.edx = 5035209 /*0x4cd4c9*/;
    // 004a5c58  a152d54c00             -mov eax, dword ptr [0x4cd552]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035346) /* 0x4cd552 */);
    // 004a5c5d  891d56d54c00           -mov dword ptr [0x4cd556], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035350) /* 0x4cd556 */) = cpu.ebx;
    // 004a5c63  2d100e0000             -sub eax, 0xe10
    (cpu.eax) -= x86::reg32(x86::sreg32(3600 /*0xe10*/));
    // 004a5c68  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004a5c6a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a5c6d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a5c6f  e8d7fdffff             -call 0x4a5a4b
    cpu.esp -= 4;
    sub_4a5a4b(app, cpu);
    if (cpu.terminate) return;
    // 004a5c74  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a5c77  8b1d52d54c00           -mov ebx, dword ptr [0x4cd552]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5035346) /* 0x4cd552 */);
    // 004a5c7d  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5c7f  891d5ad54c00           -mov dword ptr [0x4cd55a], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035354) /* 0x4cd55a */) = cpu.ebx;
    // 004a5c85  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a5c87  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5c89  80fb2c                 +cmp bl, 0x2c
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5c8c  750d                   -jne 0x4a5c9b
    if (!cpu.flags.zf)
    {
        goto L_0x004a5c9b;
    }
    // 004a5c8e  ba00d44c00             -mov edx, 0x4cd400
    cpu.edx = 5035008 /*0x4cd400*/;
    // 004a5c93  40                     -inc eax
    (cpu.eax)++;
    // 004a5c94  e8c7feffff             -call 0x4a5b60
    cpu.esp -= 4;
    sub_4a5b60(app, cpu);
    if (cpu.terminate) return;
    // 004a5c99  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004a5c9b:
    // 004a5c9b  803a2c                 +cmp byte ptr [edx], 0x2c
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5c9e  756c                   -jne 0x4a5d0c
    if (!cpu.flags.zf)
    {
        goto L_0x004a5d0c;
    }
    // 004a5ca0  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a5ca3  ba24d44c00             -mov edx, 0x4cd424
    cpu.edx = 5035044 /*0x4cd424*/;
    // 004a5ca8  e8b3feffff             -call 0x4a5b60
    cpu.esp -= 4;
    sub_4a5b60(app, cpu);
    if (cpu.terminate) return;
    // 004a5cad  a15ad54c00             -mov eax, dword ptr [0x4cd55a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035354) /* 0x4cd55a */);
    // 004a5cb2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5cb4  bb100e0000             -mov ebx, 0xe10
    cpu.ebx = 3600 /*0xe10*/;
    // 004a5cb9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a5cbc  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a5cbe  8b352cd44c00           -mov esi, dword ptr [0x4cd42c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5035052) /* 0x4cd42c */);
    // 004a5cc4  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5cc6  a15ad54c00             -mov eax, dword ptr [0x4cd55a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035354) /* 0x4cd55a */);
    // 004a5ccb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5ccd  bb3c000000             -mov ebx, 0x3c
    cpu.ebx = 60 /*0x3c*/;
    // 004a5cd2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a5cd5  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a5cd7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5cd9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a5cdc  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a5cde  8b3d28d44c00           -mov edi, dword ptr [0x4cd428]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5035048) /* 0x4cd428 */);
    // 004a5ce4  a15ad54c00             -mov eax, dword ptr [0x4cd55a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035354) /* 0x4cd55a */);
    // 004a5ce9  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5ceb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5ced  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a5cf0  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a5cf2  8b2d24d44c00           -mov ebp, dword ptr [0x4cd424]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5035044) /* 0x4cd424 */);
    // 004a5cf8  89352cd44c00           -mov dword ptr [0x4cd42c], esi
    app->getMemory<x86::reg32>(x86::reg32(5035052) /* 0x4cd42c */) = cpu.esi;
    // 004a5cfe  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5d00  893d28d44c00           -mov dword ptr [0x4cd428], edi
    app->getMemory<x86::reg32>(x86::reg32(5035048) /* 0x4cd428 */) = cpu.edi;
    // 004a5d06  892d24d44c00           -mov dword ptr [0x4cd424], ebp
    app->getMemory<x86::reg32>(x86::reg32(5035044) /* 0x4cd424 */) = cpu.ebp;
L_0x004a5d0c:
L_entry_0x004a5d0c:
    // 004a5d0c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a5d0f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d10  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d11  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d12  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a5d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5d20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5d21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a5d22  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a5d24  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5d26  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a5d28  7c3f                   -jl 0x4a5d69
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5d69;
    }
L_0x004a5d2a:
    // 004a5d2a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a5d2c  743f                   -je 0x4a5d6d
    if (cpu.flags.zf)
    {
        goto L_0x004a5d6d;
    }
    // 004a5d2e  3d00000100             +cmp eax, 0x10000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5d33  7c06                   -jl 0x4a5d3b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5d3b;
    }
    // 004a5d35  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a5d38  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004a5d3b:
    // 004a5d3b  3d00010000             +cmp eax, 0x100
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
    // 004a5d40  7c06                   -jl 0x4a5d48
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5d48;
    }
    // 004a5d42  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004a5d45  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004a5d48:
    // 004a5d48  83f810                 +cmp eax, 0x10
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
    // 004a5d4b  7c06                   -jl 0x4a5d53
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5d53;
    }
    // 004a5d4d  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004a5d50  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004a5d53:
    // 004a5d53  83f804                 +cmp eax, 4
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
    // 004a5d56  7c06                   -jl 0x4a5d5e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5d5e;
    }
    // 004a5d58  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004a5d5b  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004a5d5e:
    // 004a5d5e  83f802                 +cmp eax, 2
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
    // 004a5d61  7c01                   -jl 0x4a5d64
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5d64;
    }
    // 004a5d63  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x004a5d64:
    // 004a5d64  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5d66  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d68  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a5d69:
    // 004a5d69  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004a5d6b  ebbd                   -jmp 0x4a5d2a
    goto L_0x004a5d2a;
L_0x004a5d6d:
    // 004a5d6d  ba3f000000             -mov edx, 0x3f
    cpu.edx = 63 /*0x3f*/;
    // 004a5d72  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5d74  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d75  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a5d78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5d78  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5d79  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a5d7b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a5d7c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5d7d  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a5d80  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a5d83  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a5d86  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a5d89  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a5d8c  c700965d4a00           -mov dword ptr [eax], 0x4a5d96
    app->getMemory<x86::reg32>(cpu.eax) = 4873622 /*0x4a5d96*/;
    // 004a5d92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d93  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d94  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5d95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5d96(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5d96  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5d97  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a5d99  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a5d9a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5d9b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5d9c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5d9d  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a5da0  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a5da3  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a5da6  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a5da9  db450c                 -fild dword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))));
    // 004a5dac  db4510                 -fild dword ptr [ebp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */))));
    // 004a5daf  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a5db1  d80d64d54c00           -fmul dword ptr [0x4cd564]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5035364) /* 0x4cd564 */));
    // 004a5db7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a5db9  d80d64d54c00           -fmul dword ptr [0x4cd564]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5035364) /* 0x4cd564 */));
    // 004a5dbf  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a5dc1  d91e                   -fstp dword ptr [esi]
    app->getMemory<float>(cpu.esi) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5dc3  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5dc6  83f800                 +cmp eax, 0
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
    // 004a5dc9  7417                   -je 0x4a5de2
    if (cpu.flags.zf)
    {
        goto L_0x004a5de2;
    }
    // 004a5dcb  83fb00                 +cmp ebx, 0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5dce  7448                   -je 0x4a5e18
    if (cpu.flags.zf)
    {
        goto L_0x004a5e18;
    }
    // 004a5dd0  83f87f                 +cmp eax, 0x7f
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
    // 004a5dd3  7414                   -je 0x4a5de9
    if (cpu.flags.zf)
    {
        goto L_0x004a5de9;
    }
    // 004a5dd5  83fb7f                 +cmp ebx, 0x7f
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
    // 004a5dd8  742e                   -je 0x4a5e08
    if (cpu.flags.zf)
    {
        goto L_0x004a5e08;
    }
    // 004a5dda  c701265e4a00           -mov dword ptr [ecx], 0x4a5e26
    app->getMemory<x86::reg32>(cpu.ecx) = 4873766 /*0x4a5e26*/;
    // 004a5de0  eb3e                   -jmp 0x4a5e20
    goto L_0x004a5e20;
L_0x004a5de2:
    // 004a5de2  83fb00                 +cmp ebx, 0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5de5  7409                   -je 0x4a5df0
    if (cpu.flags.zf)
    {
        goto L_0x004a5df0;
    }
    // 004a5de7  eb27                   -jmp 0x4a5e10
    goto L_0x004a5e10;
L_0x004a5de9:
    // 004a5de9  83fb7f                 +cmp ebx, 0x7f
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
    // 004a5dec  740a                   -je 0x4a5df8
    if (cpu.flags.zf)
    {
        goto L_0x004a5df8;
    }
    // 004a5dee  eb10                   -jmp 0x4a5e00
    goto L_0x004a5e00;
L_0x004a5df0:
    // 004a5df0  c70129614a00           -mov dword ptr [ecx], 0x4a6129
    app->getMemory<x86::reg32>(cpu.ecx) = 4874537 /*0x4a6129*/;
    // 004a5df6  eb28                   -jmp 0x4a5e20
    goto L_0x004a5e20;
L_0x004a5df8:
    // 004a5df8  c701b65e4a00           -mov dword ptr [ecx], 0x4a5eb6
    app->getMemory<x86::reg32>(cpu.ecx) = 4873910 /*0x4a5eb6*/;
    // 004a5dfe  eb20                   -jmp 0x4a5e20
    goto L_0x004a5e20;
L_0x004a5e00:
    // 004a5e00  c701a3604a00           -mov dword ptr [ecx], 0x4a60a3
    app->getMemory<x86::reg32>(cpu.ecx) = 4874403 /*0x4a60a3*/;
    // 004a5e06  eb18                   -jmp 0x4a5e20
    goto L_0x004a5e20;
L_0x004a5e08:
    // 004a5e08  c7011e604a00           -mov dword ptr [ecx], 0x4a601e
    app->getMemory<x86::reg32>(cpu.ecx) = 4874270 /*0x4a601e*/;
    // 004a5e0e  eb10                   -jmp 0x4a5e20
    goto L_0x004a5e20;
L_0x004a5e10:
    // 004a5e10  c701a15f4a00           -mov dword ptr [ecx], 0x4a5fa1
    app->getMemory<x86::reg32>(cpu.ecx) = 4874145 /*0x4a5fa1*/;
    // 004a5e16  eb08                   -jmp 0x4a5e20
    goto L_0x004a5e20;
L_0x004a5e18:
    // 004a5e18  c701255f4a00           -mov dword ptr [ecx], 0x4a5f25
    app->getMemory<x86::reg32>(cpu.ecx) = 4874021 /*0x4a5f25*/;
    // 004a5e1e  eb00                   -jmp 0x4a5e20
    goto L_0x004a5e20;
L_0x004a5e20:
    // 004a5e20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5e21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5e22  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5e23  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5e24  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5e25  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5e26(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5e26  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5e27  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a5e29  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a5e2a  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a5e2d  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a5e30  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a5e33  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004a5e36  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004a5e38  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a5e3b  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5e3e  7e45                   -jle 0x4a5e85
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a5e85;
    }
    // 004a5e40  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a5e43:
    // 004a5e43  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a5e45  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a5e47  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a5e49  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a5e4b  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a5e4e  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a5e50  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a5e53  d8cd                   -fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 004a5e55  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a5e57  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a5e5a  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a5e5c  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a5e5f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a5e61  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004a5e64  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a5e66  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004a5e69  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a5e6b  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5e6e  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5e71  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5e74  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5e77  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a5e7a  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a5e7d  83e902                 +sub ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5e80  7fc1                   -jg 0x4a5e43
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a5e43;
    }
    // 004a5e82  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a5e85:
    // 004a5e85  83f900                 +cmp ecx, 0
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
    // 004a5e88  7e25                   -jle 0x4a5eaf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a5eaf;
    }
    // 004a5e8a  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a5e8c  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a5e8e  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a5e90  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a5e92  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a5e94  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a5e97  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a5e99  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a5e9c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a5e9e  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5ea1  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5ea4  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a5ea7  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a5eaa  83e901                 +sub ecx, 1
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
    // 004a5ead  7fd6                   -jg 0x4a5e85
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a5e85;
    }
L_0x004a5eaf:
    // 004a5eaf  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5eb1  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5eb3  61                     -popal 
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
    // 004a5eb4  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5eb5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5eb6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5eb6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5eb7  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a5eb9  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a5eba  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a5ebd  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a5ec0  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a5ec3  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a5ec6  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5ec9  7e35                   -jle 0x4a5f00
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a5f00;
    }
    // 004a5ecb  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a5ece:
    // 004a5ece  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004a5ed1  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004a5ed3  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 004a5ed6  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004a5ed8  d94508                 -fld dword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004a5edb  d84704                 -fadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */));
    // 004a5ede  d9450c                 -fld dword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 004a5ee1  d84704                 -fadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */));
    // 004a5ee4  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a5ee6  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5ee9  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5eec  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5eef  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5ef2  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a5ef5  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a5ef8  83e902                 +sub ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5efb  7fd1                   -jg 0x4a5ece
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a5ece;
    }
    // 004a5efd  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a5f00:
    // 004a5f00  83f900                 +cmp ecx, 0
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
    // 004a5f03  7e1d                   -jle 0x4a5f22
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a5f22;
    }
    // 004a5f05  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004a5f08  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004a5f0a  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 004a5f0d  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004a5f0f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a5f11  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5f14  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5f17  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a5f1a  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a5f1d  83e901                 +sub ecx, 1
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
    // 004a5f20  7fde                   -jg 0x4a5f00
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a5f00;
    }
L_0x004a5f22:
    // 004a5f22  61                     -popal 
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
    // 004a5f23  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5f24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5f25(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5f25  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5f26  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a5f28  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a5f29  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a5f2c  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a5f2f  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a5f32  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004a5f34  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a5f37  83f903                 +cmp ecx, 3
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
    // 004a5f3a  7e46                   -jle 0x4a5f82
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a5f82;
    }
    // 004a5f3c  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004a5f3f:
    // 004a5f3f  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a5f41  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a5f43  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a5f46  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a5f48  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004a5f4b  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a5f4d  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004a5f50  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004a5f52  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a5f54  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a5f57  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a5f59  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004a5f5c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a5f5e  d84510                 -fadd dword ptr [ebp + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */));
    // 004a5f61  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a5f63  d84518                 -fadd dword ptr [ebp + 0x18]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */));
    // 004a5f66  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a5f68  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5f6b  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5f6e  d95d18                 -fstp dword ptr [ebp + 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5f71  d95d10                 -fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5f74  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a5f77  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a5f7a  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5f7d  7fc0                   -jg 0x4a5f3f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a5f3f;
    }
    // 004a5f7f  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004a5f82:
    // 004a5f82  83f900                 +cmp ecx, 0
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
    // 004a5f85  7e15                   -jle 0x4a5f9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a5f9c;
    }
    // 004a5f87  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a5f89  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a5f8b  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a5f8e  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5f91  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a5f94  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a5f97  83e901                 +sub ecx, 1
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
    // 004a5f9a  7fe6                   -jg 0x4a5f82
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a5f82;
    }
L_0x004a5f9c:
    // 004a5f9c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5f9e  61                     -popal 
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
    // 004a5f9f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5fa0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5fa1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5fa1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5fa2  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a5fa4  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a5fa5  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a5fa8  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a5fab  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a5fae  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004a5fb1  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a5fb4  83f903                 +cmp ecx, 3
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
    // 004a5fb7  7e46                   -jle 0x4a5fff
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a5fff;
    }
    // 004a5fb9  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004a5fbc:
    // 004a5fbc  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a5fbe  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a5fc0  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a5fc3  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a5fc5  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004a5fc8  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a5fca  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004a5fcd  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004a5fcf  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a5fd1  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a5fd4  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a5fd6  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004a5fd9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a5fdb  d84514                 -fadd dword ptr [ebp + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */));
    // 004a5fde  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a5fe0  d8451c                 -fadd dword ptr [ebp + 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */));
    // 004a5fe3  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a5fe5  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5fe8  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5feb  d95d1c                 -fstp dword ptr [ebp + 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5fee  d95d14                 -fstp dword ptr [ebp + 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a5ff1  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a5ff4  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a5ff7  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5ffa  7fc0                   -jg 0x4a5fbc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a5fbc;
    }
    // 004a5ffc  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004a5fff:
    // 004a5fff  83f900                 +cmp ecx, 0
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
    // 004a6002  7e15                   -jle 0x4a6019
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a6019;
    }
    // 004a6004  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a6006  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a6008  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a600b  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a600e  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a6011  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a6014  83e901                 +sub ecx, 1
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
    // 004a6017  7fe6                   -jg 0x4a5fff
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a5fff;
    }
L_0x004a6019:
    // 004a6019  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a601b  61                     -popal 
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
    // 004a601c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a601d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a601e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a601e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a601f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a6021  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a6022  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a6025  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a6028  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a602b  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004a602d  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a6030  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6033  7e41                   -jle 0x4a6076
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a6076;
    }
    // 004a6035  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a6038:
    // 004a6038  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a603a  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a603c  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a603e  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a6041  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a6043  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a6046  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a6048  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a604b  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a604d  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a6050  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a6052  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004a6055  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a6057  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004a605a  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a605c  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a605f  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6062  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6065  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6068  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a606b  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a606e  83e902                 +sub ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6071  7fc5                   -jg 0x4a6038
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a6038;
    }
    // 004a6073  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a6076:
    // 004a6076  83f900                 +cmp ecx, 0
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
    // 004a6079  7e23                   -jle 0x4a609e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a609e;
    }
    // 004a607b  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a607d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a607f  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a6081  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a6083  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a6086  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a6088  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a608b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a608d  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6090  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6093  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a6096  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a6099  83e901                 +sub ecx, 1
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
    // 004a609c  7fd8                   -jg 0x4a6076
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a6076;
    }
L_0x004a609e:
    // 004a609e  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a60a0  61                     -popal 
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
    // 004a60a1  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a60a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a60a3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a60a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a60a4  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a60a6  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a60a7  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a60aa  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a60ad  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a60b0  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004a60b3  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a60b6  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a60b9  7e41                   -jle 0x4a60fc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a60fc;
    }
    // 004a60bb  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a60be:
    // 004a60be  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a60c0  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a60c2  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a60c4  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a60c7  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a60ca  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004a60cc  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a60ce  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a60d1  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a60d3  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a60d6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a60d8  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004a60db  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a60dd  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004a60e0  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a60e2  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a60e5  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a60e8  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a60eb  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a60ee  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a60f1  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a60f4  83e902                 +sub ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a60f7  7fc5                   -jg 0x4a60be
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a60be;
    }
    // 004a60f9  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a60fc:
    // 004a60fc  83f900                 +cmp ecx, 0
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
    // 004a60ff  7e23                   -jle 0x4a6124
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a6124;
    }
    // 004a6101  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a6103  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a6105  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a6107  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a6109  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a610c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a610e  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a6111  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a6113  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6116  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6119  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a611c  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a611f  83e901                 +sub ecx, 1
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
    // 004a6122  7fd8                   -jg 0x4a60fc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a60fc;
    }
L_0x004a6124:
    // 004a6124  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6126  61                     -popal 
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
    // 004a6127  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6128  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6129(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6129  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a612a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a612c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a612d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4a6130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6130  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6131  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a6133  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a6134  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6135  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a6138  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a613b  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a613e  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a6141  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a6144  c7004e614a00           -mov dword ptr [eax], 0x4a614e
    app->getMemory<x86::reg32>(cpu.eax) = 4874574 /*0x4a614e*/;
    // 004a614a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a614b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a614c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a614d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a614e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a614e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a614f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a6151  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a6152  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6153  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6154  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6155  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a6158  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a615b  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a615e  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a6161  db450c                 -fild dword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))));
    // 004a6164  db4510                 -fild dword ptr [ebp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */))));
    // 004a6167  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a6169  d80d68d54c00           -fmul dword ptr [0x4cd568]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5035368) /* 0x4cd568 */));
    // 004a616f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a6171  d80d68d54c00           -fmul dword ptr [0x4cd568]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5035368) /* 0x4cd568 */));
    // 004a6177  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a6179  d91e                   -fstp dword ptr [esi]
    app->getMemory<float>(cpu.esi) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a617b  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a617e  83f800                 +cmp eax, 0
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
    // 004a6181  7417                   -je 0x4a619a
    if (cpu.flags.zf)
    {
        goto L_0x004a619a;
    }
    // 004a6183  83fb00                 +cmp ebx, 0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6186  7448                   -je 0x4a61d0
    if (cpu.flags.zf)
    {
        goto L_0x004a61d0;
    }
    // 004a6188  83f87f                 +cmp eax, 0x7f
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
    // 004a618b  7414                   -je 0x4a61a1
    if (cpu.flags.zf)
    {
        goto L_0x004a61a1;
    }
    // 004a618d  83fb7f                 +cmp ebx, 0x7f
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
    // 004a6190  742e                   -je 0x4a61c0
    if (cpu.flags.zf)
    {
        goto L_0x004a61c0;
    }
    // 004a6192  c701de614a00           -mov dword ptr [ecx], 0x4a61de
    app->getMemory<x86::reg32>(cpu.ecx) = 4874718 /*0x4a61de*/;
    // 004a6198  eb3e                   -jmp 0x4a61d8
    goto L_0x004a61d8;
L_0x004a619a:
    // 004a619a  83fb00                 +cmp ebx, 0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a619d  7409                   -je 0x4a61a8
    if (cpu.flags.zf)
    {
        goto L_0x004a61a8;
    }
    // 004a619f  eb27                   -jmp 0x4a61c8
    goto L_0x004a61c8;
L_0x004a61a1:
    // 004a61a1  83fb7f                 +cmp ebx, 0x7f
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
    // 004a61a4  740a                   -je 0x4a61b0
    if (cpu.flags.zf)
    {
        goto L_0x004a61b0;
    }
    // 004a61a6  eb10                   -jmp 0x4a61b8
    goto L_0x004a61b8;
L_0x004a61a8:
    // 004a61a8  c701eb644a00           -mov dword ptr [ecx], 0x4a64eb
    app->getMemory<x86::reg32>(cpu.ecx) = 4875499 /*0x4a64eb*/;
    // 004a61ae  eb28                   -jmp 0x4a61d8
    goto L_0x004a61d8;
L_0x004a61b0:
    // 004a61b0  c70170624a00           -mov dword ptr [ecx], 0x4a6270
    app->getMemory<x86::reg32>(cpu.ecx) = 4874864 /*0x4a6270*/;
    // 004a61b6  eb20                   -jmp 0x4a61d8
    goto L_0x004a61d8;
L_0x004a61b8:
    // 004a61b8  c70163644a00           -mov dword ptr [ecx], 0x4a6463
    app->getMemory<x86::reg32>(cpu.ecx) = 4875363 /*0x4a6463*/;
    // 004a61be  eb18                   -jmp 0x4a61d8
    goto L_0x004a61d8;
L_0x004a61c0:
    // 004a61c0  c701dc634a00           -mov dword ptr [ecx], 0x4a63dc
    app->getMemory<x86::reg32>(cpu.ecx) = 4875228 /*0x4a63dc*/;
    // 004a61c6  eb10                   -jmp 0x4a61d8
    goto L_0x004a61d8;
L_0x004a61c8:
    // 004a61c8  c7015d634a00           -mov dword ptr [ecx], 0x4a635d
    app->getMemory<x86::reg32>(cpu.ecx) = 4875101 /*0x4a635d*/;
    // 004a61ce  eb08                   -jmp 0x4a61d8
    goto L_0x004a61d8;
L_0x004a61d0:
    // 004a61d0  c701e1624a00           -mov dword ptr [ecx], 0x4a62e1
    app->getMemory<x86::reg32>(cpu.ecx) = 4874977 /*0x4a62e1*/;
    // 004a61d6  eb00                   -jmp 0x4a61d8
    goto L_0x004a61d8;
L_0x004a61d8:
    // 004a61d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a61d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a61da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a61db  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a61dc  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a61dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a61de(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a61de  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a61df  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a61e1  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a61e2  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a61e5  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a61e8  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a61eb  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004a61ee  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004a61f0  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a61f3  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a61f6  7e46                   -jle 0x4a623e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a623e;
    }
    // 004a61f8  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a61fb:
    // 004a61fb  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a61fd  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a61ff  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a6202  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a6204  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004a6207  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a6209  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004a620c  d8cd                   -fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 004a620e  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a6210  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a6213  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a6215  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a6218  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a621a  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004a621d  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a621f  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004a6222  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a6224  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6227  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a622a  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a622d  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6230  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a6233  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a6236  83e902                 +sub ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6239  7fc0                   -jg 0x4a61fb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a61fb;
    }
    // 004a623b  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a623e:
    // 004a623e  83f900                 +cmp ecx, 0
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
    // 004a6241  7e26                   -jle 0x4a6269
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a6269;
    }
    // 004a6243  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a6245  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a6247  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a624a  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a624c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a624e  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a6251  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a6253  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a6256  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a6258  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a625b  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a625e  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a6261  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a6264  83e901                 +sub ecx, 1
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
    // 004a6267  7fd5                   -jg 0x4a623e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a623e;
    }
L_0x004a6269:
    // 004a6269  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a626b  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a626d  61                     -popal 
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
    // 004a626e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a626f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6270  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6271  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a6273  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a6274  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a6277  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a627a  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a627d  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a6280  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6283  7e36                   -jle 0x4a62bb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a62bb;
    }
    // 004a6285  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a6288:
    // 004a6288  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004a628b  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004a628d  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 004a6290  d84704                 -fadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */));
    // 004a6293  d94508                 -fld dword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004a6296  d84708                 -fadd dword ptr [edi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 004a6299  d9450c                 -fld dword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 004a629c  d8470c                 -fadd dword ptr [edi + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */));
    // 004a629f  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a62a1  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a62a4  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a62a7  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a62aa  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a62ad  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a62b0  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a62b3  83e902                 +sub ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a62b6  7fd0                   -jg 0x4a6288
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a6288;
    }
    // 004a62b8  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a62bb:
    // 004a62bb  83f900                 +cmp ecx, 0
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
    // 004a62be  7e1e                   -jle 0x4a62de
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a62de;
    }
    // 004a62c0  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004a62c3  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004a62c5  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 004a62c8  d84704                 -fadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */));
    // 004a62cb  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a62cd  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a62d0  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a62d3  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a62d6  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a62d9  83e901                 +sub ecx, 1
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
    // 004a62dc  7fdd                   -jg 0x4a62bb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a62bb;
    }
L_0x004a62de:
    // 004a62de  61                     -popal 
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
    // 004a62df  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a62e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a62e1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a62e1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a62e2  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a62e4  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a62e5  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a62e8  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a62eb  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a62ee  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004a62f0  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a62f3  83f903                 +cmp ecx, 3
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
    // 004a62f6  7e46                   -jle 0x4a633e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a633e;
    }
    // 004a62f8  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004a62fb:
    // 004a62fb  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a62fd  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a62ff  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004a6302  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a6304  d94710                 -fld dword ptr [edi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(16) /* 0x10 */)));
    // 004a6307  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a6309  d94718                 -fld dword ptr [edi + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(24) /* 0x18 */)));
    // 004a630c  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004a630e  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a6310  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a6313  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a6315  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004a6318  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a631a  d84510                 -fadd dword ptr [ebp + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */));
    // 004a631d  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a631f  d84518                 -fadd dword ptr [ebp + 0x18]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */));
    // 004a6322  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a6324  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6327  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a632a  d95d18                 -fstp dword ptr [ebp + 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a632d  d95d10                 -fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6330  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a6333  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a6336  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6339  7fc0                   -jg 0x4a62fb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a62fb;
    }
    // 004a633b  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004a633e:
    // 004a633e  83f900                 +cmp ecx, 0
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
    // 004a6341  7e15                   -jle 0x4a6358
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a6358;
    }
    // 004a6343  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a6345  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a6347  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a634a  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a634d  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a6350  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a6353  83e901                 +sub ecx, 1
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
    // 004a6356  7fe6                   -jg 0x4a633e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a633e;
    }
L_0x004a6358:
    // 004a6358  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a635a  61                     -popal 
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
    // 004a635b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a635c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a635d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a635d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a635e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a6360  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a6361  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a6364  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a6367  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a636a  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004a636d  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a6370  83f903                 +cmp ecx, 3
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
    // 004a6373  7e47                   -jle 0x4a63bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a63bc;
    }
    // 004a6375  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004a6378:
    // 004a6378  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a637b  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a637d  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004a6380  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a6382  d94714                 -fld dword ptr [edi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(20) /* 0x14 */)));
    // 004a6385  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a6387  d9471c                 -fld dword ptr [edi + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(28) /* 0x1c */)));
    // 004a638a  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004a638c  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a638e  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a6391  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a6393  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004a6396  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a6398  d84514                 -fadd dword ptr [ebp + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */));
    // 004a639b  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a639d  d8451c                 -fadd dword ptr [ebp + 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */));
    // 004a63a0  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a63a2  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a63a5  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a63a8  d95d1c                 -fstp dword ptr [ebp + 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a63ab  d95d14                 -fstp dword ptr [ebp + 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a63ae  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a63b1  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a63b4  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a63b7  7fbf                   -jg 0x4a6378
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a6378;
    }
    // 004a63b9  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004a63bc:
    // 004a63bc  83f900                 +cmp ecx, 0
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
    // 004a63bf  7e16                   -jle 0x4a63d7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a63d7;
    }
    // 004a63c1  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a63c4  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a63c6  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a63c9  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a63cc  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a63cf  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a63d2  83e901                 +sub ecx, 1
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
    // 004a63d5  7fe5                   -jg 0x4a63bc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a63bc;
    }
L_0x004a63d7:
    // 004a63d7  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a63d9  61                     -popal 
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
    // 004a63da  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a63db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a63dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a63dc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a63dd  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a63df  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a63e0  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a63e3  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a63e6  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a63e9  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004a63eb  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a63ee  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a63f1  7e42                   -jle 0x4a6435
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a6435;
    }
    // 004a63f3  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a63f6:
    // 004a63f6  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a63f8  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a63fa  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a63fd  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004a6400  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a6402  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004a6405  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a6407  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a640a  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a640c  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a640f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a6411  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004a6414  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a6416  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004a6419  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a641b  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a641e  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6421  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6424  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6427  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a642a  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a642d  83e902                 +sub ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6430  7fc4                   -jg 0x4a63f6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a63f6;
    }
    // 004a6432  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a6435:
    // 004a6435  83f900                 +cmp ecx, 0
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
    // 004a6438  7e24                   -jle 0x4a645e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a645e;
    }
    // 004a643a  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a643c  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a643e  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a6441  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a6443  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a6446  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a6448  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a644b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a644d  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6450  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6453  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a6456  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a6459  83e901                 +sub ecx, 1
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
    // 004a645c  7fd7                   -jg 0x4a6435
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a6435;
    }
L_0x004a645e:
    // 004a645e  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6460  61                     -popal 
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
    // 004a6461  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6462  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6463(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6463  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6464  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a6466  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a6467  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a646a  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a646d  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a6470  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004a6473  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a6476  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6479  7e42                   -jle 0x4a64bd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a64bd;
    }
    // 004a647b  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a647e:
    // 004a647e  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a6480  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a6483  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a6485  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004a6488  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004a648b  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004a648d  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a648f  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a6492  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a6494  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a6497  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a6499  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004a649c  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a649e  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004a64a1  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a64a3  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a64a6  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a64a9  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a64ac  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a64af  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a64b2  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a64b5  83e902                 +sub ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a64b8  7fc4                   -jg 0x4a647e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a647e;
    }
    // 004a64ba  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a64bd:
    // 004a64bd  83f900                 +cmp ecx, 0
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
    // 004a64c0  7e24                   -jle 0x4a64e6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a64e6;
    }
    // 004a64c2  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a64c4  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a64c7  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a64c9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a64cb  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a64ce  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a64d0  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a64d3  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a64d5  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a64d8  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a64db  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a64de  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a64e1  83e901                 +sub ecx, 1
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
    // 004a64e4  7fd7                   -jg 0x4a64bd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a64bd;
    }
L_0x004a64e6:
    // 004a64e6  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a64e8  61                     -popal 
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
    // 004a64e9  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a64ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a64eb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a64eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a64ec  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a64ee  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a64ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a64f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a64f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a64f1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a64f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a64f4  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a64f7  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004a64fd  c7460c00000000         -mov dword ptr [esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004a6504  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a6507  c70030654a00           -mov dword ptr [eax], 0x4a6530
    app->getMemory<x86::reg32>(cpu.eax) = 4875568 /*0x4a6530*/;
    // 004a650d  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a6510  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a6513  c70045654a00           -mov dword ptr [eax], 0x4a6545
    app->getMemory<x86::reg32>(cpu.eax) = 4875589 /*0x4a6545*/;
    // 004a6519  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a651c  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a651f  c7008b654a00           -mov dword ptr [eax], 0x4a658b
    app->getMemory<x86::reg32>(cpu.eax) = 4875659 /*0x4a658b*/;
    // 004a6525  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a6528  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6529  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004a652e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a652f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6530  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6531  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a6533  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6534  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a6537  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a653a  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a653d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a653e  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004a6543  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6544  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6545(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6545  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6546  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a6548  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6549  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a654c  817e0400000100         +cmp dword ptr [esi + 4], 0x10000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6553  7c08                   -jl 0x4a655d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a655d;
    }
    // 004a6555  7f1e                   -jg 0x4a6575
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a6575;
    }
    // 004a6557  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6558  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a655b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a655c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a655d:
    // 004a655d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a655e  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a6561  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a6564  4a                     -dec edx
    (cpu.edx)--;
    // 004a6565  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a6568  0306                   -add eax, dword ptr [esi]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004a656a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a656b  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a656e  40                     -inc eax
    (cpu.eax)++;
    // 004a656f  2b460c                 -sub eax, dword ptr [esi + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 004a6572  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6573  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6574  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a6575:
    // 004a6575  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a6576  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a6579  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a657c  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a657f  0306                   -add eax, dword ptr [esi]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004a6581  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6582  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a6585  2b460c                 -sub eax, dword ptr [esi + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 004a6588  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6589  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a658a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a658b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a658b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a658c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a658e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a658f  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a6592  817e0400000100         +cmp dword ptr [esi + 4], 0x10000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6599  750f                   -jne 0x4a65aa
    if (!cpu.flags.zf)
    {
        goto L_0x004a65aa;
    }
    // 004a659b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a659c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a659d  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a65a0  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a65a3  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004a65a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a65a6  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a65a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a65a8  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a65a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a65aa:
    // 004a65aa  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a65ab  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a65ad  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a65b0  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a65b3  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a65b6  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a65b9  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004a65bb  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004a65be  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a65c1  03cf                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a65c3  a36cd54c00             -mov dword ptr [0x4cd56c], eax
    app->getMemory<x86::reg32>(x86::reg32(5035372) /* 0x4cd56c */) = cpu.eax;
    // 004a65c8  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a65cb  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a65ce  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a65cf  c1ee02                 -shr esi, 2
    cpu.esi >>= 2 /*0x2*/ % 32;
    // 004a65d2  8beb                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a65d4  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 004a65d7  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004a65da  83f801                 +cmp eax, 1
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
    // 004a65dd  751c                   -jne 0x4a65fb
    if (!cpu.flags.zf)
    {
        goto L_0x004a65fb;
    }
    // 004a65df  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a65e0  be00000000             -mov esi, 0
    cpu.esi = 0 /*0x0*/;
L_0x004a65e5:
    // 004a65e5  a16cd54c00             -mov eax, dword ptr [0x4cd56c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035372) /* 0x4cd56c */);
    // 004a65ea  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a65ec  03d5                   +add edx, ebp
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a65ee  13f3                   -adc esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a65f0  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a65f3  83fe00                 +cmp esi, 0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a65f6  74ed                   -je 0x4a65e5
    if (cpu.flags.zf)
    {
        goto L_0x004a65e5;
    }
    // 004a65f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a65f9  90                     -nop 
    ;
    // 004a65fa  90                     -nop 
    ;
L_0x004a65fb:
    // 004a65fb  8b04b500000000         -mov eax, dword ptr [esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi * 4);
    // 004a6602  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a6604  03d5                   +add edx, ebp
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6606  13f3                   -adc esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a6608  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a660b  3bf9                   +cmp edi, ecx
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
    // 004a660d  7cec                   -jl 0x4a65fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a65fb;
    }
    // 004a660f  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a6612  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6613  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a6616  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a6618  3b5e04                 +cmp ebx, dword ptr [esi + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a661b  7c11                   -jl 0x4a662e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a662e;
    }
    // 004a661d  8b47fc                 -mov eax, dword ptr [edi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 004a6620  c7460c01000000         -mov dword ptr [esi + 0xc], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 004a6627  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a662a  61                     -popal 
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
    // 004a662b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a662c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a662d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a662e:
    // 004a662e  c7460c00000000         -mov dword ptr [esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004a6635  61                     -popal 
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
    // 004a6636  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6637  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6638  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4a663c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a663c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a663d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a663f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6640  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a6643  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004a6649  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004a6650  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a6653  c7007c664a00           -mov dword ptr [eax], 0x4a667c
    app->getMemory<x86::reg32>(cpu.eax) = 4875900 /*0x4a667c*/;
    // 004a6659  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a665c  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a665f  c70091664a00           -mov dword ptr [eax], 0x4a6691
    app->getMemory<x86::reg32>(cpu.eax) = 4875921 /*0x4a6691*/;
    // 004a6665  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a6668  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a666b  c700d7664a00           -mov dword ptr [eax], 0x4a66d7
    app->getMemory<x86::reg32>(cpu.eax) = 4875991 /*0x4a66d7*/;
    // 004a6671  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004a6674  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6675  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004a667a  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a667b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a667c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a667c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a667d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a667f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6680  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a6683  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a6686  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a6689  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a668a  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004a668f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6690  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6691(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6691  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6692  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a6694  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6695  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a6698  817e0400000100         +cmp dword ptr [esi + 4], 0x10000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a669f  7c08                   -jl 0x4a66a9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a66a9;
    }
    // 004a66a1  7f1e                   -jg 0x4a66c1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a66c1;
    }
    // 004a66a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66a4  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a66a7  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a66a9:
    // 004a66a9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a66aa  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a66ad  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a66b0  4a                     -dec edx
    (cpu.edx)--;
    // 004a66b1  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a66b4  0306                   -add eax, dword ptr [esi]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004a66b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66b7  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a66ba  40                     -inc eax
    (cpu.eax)++;
    // 004a66bb  2b4610                 -sub eax, dword ptr [esi + 0x10]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 004a66be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66bf  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a66c1:
    // 004a66c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a66c2  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a66c5  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a66c8  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a66cb  0306                   -add eax, dword ptr [esi]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004a66cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66ce  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a66d1  2b4610                 -sub eax, dword ptr [esi + 0x10]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 004a66d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66d5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a66d7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a66d7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a66d8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a66da  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a66db  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a66de  817e0400000100         +cmp dword ptr [esi + 4], 0x10000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a66e5  750f                   -jne 0x4a66f6
    if (!cpu.flags.zf)
    {
        goto L_0x004a66f6;
    }
    // 004a66e7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a66e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a66e9  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a66ec  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a66ef  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004a66f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66f2  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66f4  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a66f6:
    // 004a66f6  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a66f7  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a66f9  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a66fc  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a66ff  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a6702  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a6705  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004a6707  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 004a670a  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a670d  03cf                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a670f  a374d54c00             -mov dword ptr [0x4cd574], eax
    app->getMemory<x86::reg32>(x86::reg32(5035380) /* 0x4cd574 */) = cpu.eax;
    // 004a6714  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a6717  a378d54c00             -mov dword ptr [0x4cd578], eax
    app->getMemory<x86::reg32>(x86::reg32(5035384) /* 0x4cd578 */) = cpu.eax;
    // 004a671c  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a671f  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a6722  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6723  c1ee03                 -shr esi, 3
    cpu.esi >>= 3 /*0x3*/ % 32;
    // 004a6726  8beb                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a6728  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 004a672b  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004a672e  83f801                 +cmp eax, 1
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
    // 004a6731  7522                   -jne 0x4a6755
    if (!cpu.flags.zf)
    {
        goto L_0x004a6755;
    }
    // 004a6733  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6734  be00000000             -mov esi, 0
    cpu.esi = 0 /*0x0*/;
L_0x004a6739:
    // 004a6739  a174d54c00             -mov eax, dword ptr [0x4cd574]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035380) /* 0x4cd574 */);
    // 004a673e  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a6740  a178d54c00             -mov eax, dword ptr [0x4cd578]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035384) /* 0x4cd578 */);
    // 004a6745  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a6748  03d5                   +add edx, ebp
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a674a  13f3                   -adc esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a674c  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a674f  83fe00                 +cmp esi, 0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6752  74e5                   -je 0x4a6739
    if (cpu.flags.zf)
    {
        goto L_0x004a6739;
    }
    // 004a6754  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a6755:
    // 004a6755  892570d54c00           -mov dword ptr [0x4cd570], esp
    app->getMemory<x86::reg32>(x86::reg32(5035376) /* 0x4cd570 */) = cpu.esp;
    // 004a675b  90                     -nop 
    ;
L_0x004a675c:
    // 004a675c  8b04f500000000         -mov eax, dword ptr [esi*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi * 8);
    // 004a6763  8b24f504000000         -mov esp, dword ptr [esi*8 + 4]
    cpu.esp = app->getMemory<x86::reg32>(x86::reg32(4) /* 0x4 */ + cpu.esi * 8);
    // 004a676a  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a676c  896704                 -mov dword ptr [edi + 4], esp
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.esp;
    // 004a676f  03d5                   +add edx, ebp
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6771  13f3                   -adc esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a6773  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a6776  3bf9                   +cmp edi, ecx
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
    // 004a6778  7ce2                   -jl 0x4a675c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a675c;
    }
    // 004a677a  8b2570d54c00           -mov esp, dword ptr [0x4cd570]
    cpu.esp = app->getMemory<x86::reg32>(x86::reg32(5035376) /* 0x4cd570 */);
    // 004a6780  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a6783  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6784  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a6787  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a6789  3b5e04                 +cmp ebx, dword ptr [esi + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a678c  7c17                   -jl 0x4a67a5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a67a5;
    }
    // 004a678e  8b47f8                 -mov eax, dword ptr [edi - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */);
    // 004a6791  c7461001000000         -mov dword ptr [esi + 0x10], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004a6798  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a679b  8b47fc                 -mov eax, dword ptr [edi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 004a679e  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a67a1  61                     -popal 
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
    // 004a67a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a67a3  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a67a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a67a5:
    // 004a67a5  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004a67ac  61                     -popal 
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
    // 004a67ad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a67ae  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a67af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a67b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a67b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a67b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a67b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a67b3  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a67b7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a67bb  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a67be  48                     -dec eax
    (cpu.eax)--;
    // 004a67bf  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a67c2  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a67c5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a67c8  8b5a13                 -mov ebx, dword ptr [edx + 0x13]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004a67cb  40                     -inc eax
    (cpu.eax)++;
    // 004a67cc  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a67cf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a67d1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a67d3  8a5a15                 -mov bl, byte ptr [edx + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */);
    // 004a67d6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a67d8  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a67da  7501                   -jne 0x4a67dd
    if (!cpu.flags.zf)
    {
        goto L_0x004a67dd;
    }
    // 004a67dc  40                     -inc eax
    (cpu.eax)++;
L_0x004a67dd:
    // 004a67dd  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a67e1  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a67e4  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a67e7  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004a67ea  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a67ed  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a67ef  885116                 -mov byte ptr [ecx + 0x16], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(22) /* 0x16 */) = cpu.dl;
    // 004a67f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a67f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a67f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a67f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a67f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a67f8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a67fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a6800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6801  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a6805  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a6809  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a680c  48                     -dec eax
    (cpu.eax)--;
    // 004a680d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a6810  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a6813  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a6815  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a6818  8a5a15                 -mov bl, byte ptr [edx + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */);
    // 004a681b  40                     -inc eax
    (cpu.eax)++;
    // 004a681c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a681e  7501                   -jne 0x4a6821
    if (!cpu.flags.zf)
    {
        goto L_0x004a6821;
    }
    // 004a6820  40                     -inc eax
    (cpu.eax)++;
L_0x004a6821:
    // 004a6821  8b5111                 -mov edx, dword ptr [ecx + 0x11]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(17) /* 0x11 */);
    // 004a6824  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a6827  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a6829  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a682a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a682c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a682c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a682d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a682e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a682f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6830  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a6833  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a6837  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a683b  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a683f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a6841  8a4815                 -mov cl, byte ptr [eax + 0x15]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 004a6844  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a6846  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a6848  7571                   -jne 0x4a68bb
    if (!cpu.flags.zf)
    {
        goto L_0x004a68bb;
    }
L_0x004a684a:
    // 004a684a  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a684e  4f                     -dec edi
    (cpu.edi)--;
    // 004a684f  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a6852  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a6854  7f6f                   -jg 0x4a68c5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a68c5;
    }
L_0x004a6856:
    // 004a6856  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a6858  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a685b  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a685f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a6862  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 004a6865  dc0d04f64b00           -fmul qword ptr [0x4bf604]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4978180) /* 0x4bf604 */));
    // 004a686b  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a686d  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004a686f  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004a6871  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a6873  d9448604               -fld dword ptr [esi + eax*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4)));
    // 004a6877  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a6879  d80c86                 -fmul dword ptr [esi + eax*4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 4));
    // 004a687c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a687e  d95cbd00               -fstp dword ptr [ebp + edi*4]
    app->getMemory<float>(cpu.ebp + cpu.edi * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6882  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a6884  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a6887  d9448604               -fld dword ptr [esi + eax*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4)));
    // 004a688b  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a688e  d95b10                 -fstp dword ptr [ebx + 0x10]
    app->getMemory<float>(cpu.ebx + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6891  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a6893  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a6895  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a6897  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a689a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a689d  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a68a3  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a68a5  8b4313                 -mov eax, dword ptr [ebx + 0x13]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(19) /* 0x13 */);
    // 004a68a8  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 004a68aa  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a68ad  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004a68b1  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a68b3  83c414                 +add esp, 0x14
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
    // 004a68b6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a68b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a68b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a68b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a68ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a68bb:
    // 004a68bb  8d72fc                 -lea esi, [edx - 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004a68be  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a68c1  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a68c3  eb85                   -jmp 0x4a684a
    goto L_0x004a684a;
L_0x004a68c5:
    // 004a68c5  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a68c8  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a68cb  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a68ce  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a68d1  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a68d4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a68d5  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a68d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a68d9  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a68dd  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a68e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a68e2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a68e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a68e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a68e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a68e6  e8b1590000             -call 0x4ac29c
    cpu.esp -= 4;
    sub_4ac29c(app, cpu);
    if (cpu.terminate) return;
    // 004a68eb  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a68ee  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a68f2  c1e810                 +shr eax, 0x10
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
    // 004a68f5  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a68f8  e959ffffff             -jmp 0x4a6856
    goto L_0x004a6856;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a6900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6900  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a6904  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a6908  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a690a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a690c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a690c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a690d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a690e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a690f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6910  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a6913  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a6917  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a691b  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a691f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a6921  8a4815                 -mov cl, byte ptr [eax + 0x15]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 004a6924  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a6926  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a6928  0f85c5000000           -jne 0x4a69f3
    if (!cpu.flags.zf)
    {
        goto L_0x004a69f3;
    }
L_0x004a692e:
    // 004a692e  807b1400               +cmp byte ptr [ebx + 0x14], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a6932  7409                   -je 0x4a693d
    if (cpu.flags.zf)
    {
        goto L_0x004a693d;
    }
    // 004a6934  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a6937  8946fc                 -mov dword ptr [esi - 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a693a  83ee04                 +sub esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004a693d:
    // 004a693d  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a6941  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004a6947  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a694a  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a694b  7433                   -je 0x4a6980
    if (cpu.flags.zf)
    {
        goto L_0x004a6980;
    }
    // 004a694d  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a6950  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a6953  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a6956  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a6959  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a695c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a695d  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a6960  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6961  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a6965  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a6969  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a696a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a696b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a696c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a696d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a696e  e829590000             -call 0x4ac29c
    cpu.esp -= 4;
    sub_4ac29c(app, cpu);
    if (cpu.terminate) return;
    // 004a6973  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a6976  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a697a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a697d  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004a6980:
    // 004a6980  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a6982  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a6985  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a6989  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a698c  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 004a698f  dc0d0cf64b00           -fmul qword ptr [0x4bf60c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4978188) /* 0x4bf60c */));
    // 004a6995  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a6997  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004a6999  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004a699b  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a699d  d9448604               -fld dword ptr [esi + eax*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4)));
    // 004a69a1  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a69a3  d80c86                 -fmul dword ptr [esi + eax*4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 4));
    // 004a69a6  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a69a8  d95cbd00               -fstp dword ptr [ebp + edi*4]
    app->getMemory<float>(cpu.ebp + cpu.edi * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a69ac  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a69ae  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a69b1  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a69b3  d9448604               -fld dword ptr [esi + eax*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4)));
    // 004a69b7  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a69ba  8b6b08                 -mov ebp, dword ptr [ebx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a69bd  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a69bf  d95b10                 -fstp dword ptr [ebx + 0x10]
    app->getMemory<float>(cpu.ebx + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a69c2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a69c4  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a69c7  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a69ca  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a69d0  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a69d2  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a69d5  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004a69d7  39e8                   +cmp eax, ebp
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
    // 004a69d9  7225                   -jb 0x4a6a00
    if (cpu.flags.cf)
    {
        goto L_0x004a6a00;
    }
    // 004a69db  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a69dd  c6431401               -mov byte ptr [ebx + 0x14], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 004a69e1  8b1486                 -mov edx, dword ptr [esi + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 004a69e4  89530c                 -mov dword ptr [ebx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004a69e7  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004a69eb  83c414                 +add esp, 0x14
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
    // 004a69ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a69ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a69f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a69f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a69f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a69f3:
    // 004a69f3  8d72fc                 -lea esi, [edx - 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004a69f6  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a69f9  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a69fb  e92effffff             -jmp 0x4a692e
    goto L_0x004a692e;
L_0x004a6a00:
    // 004a6a00  c6431400               -mov byte ptr [ebx + 0x14], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004a6a04  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004a6a08  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a6a0b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6a0c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6a0d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6a0e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6a0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6a10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6a11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6a12  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a6a16  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a6a1a  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a6a1d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a6a1f  81fb00000100           +cmp ebx, 0x10000
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
    // 004a6a25  732c                   -jae 0x4a6a53
    if (!cpu.flags.cf)
    {
        goto L_0x004a6a53;
    }
    // 004a6a27  81fa00000100           +cmp edx, 0x10000
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
    // 004a6a2d  7324                   -jae 0x4a6a53
    if (!cpu.flags.cf)
    {
        goto L_0x004a6a53;
    }
L_0x004a6a2f:
    // 004a6a2f  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a6a32  81fa00000100           +cmp edx, 0x10000
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
    // 004a6a38  724b                   -jb 0x4a6a85
    if (cpu.flags.cf)
    {
        goto L_0x004a6a85;
    }
    // 004a6a3a  7660                   -jbe 0x4a6a9c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a6a9c;
    }
    // 004a6a3c  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a6a3f  c702b0674a00           -mov dword ptr [edx], 0x4a67b0
    app->getMemory<x86::reg32>(cpu.edx) = 4876208 /*0x4a67b0*/;
    // 004a6a45  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a6a48  c7002c684a00           -mov dword ptr [eax], 0x4a682c
    app->getMemory<x86::reg32>(cpu.eax) = 4876332 /*0x4a682c*/;
    // 004a6a4e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6a50  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6a51  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6a52  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a6a53:
    // 004a6a53  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a6a56  39f2                   +cmp edx, esi
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
    // 004a6a58  74d5                   -je 0x4a6a2f
    if (cpu.flags.zf)
    {
        goto L_0x004a6a2f;
    }
    // 004a6a5a  81fe00000100           +cmp esi, 0x10000
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
    // 004a6a60  7608                   -jbe 0x4a6a6a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a6a6a;
    }
    // 004a6a62  81fa00000100           +cmp edx, 0x10000
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
    // 004a6a68  77c5                   -ja 0x4a6a2f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a6a2f;
    }
L_0x004a6a6a:
    // 004a6a6a  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004a6a6e  c6401500               -mov byte ptr [eax + 0x15], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 004a6a72  c6401600               -mov byte ptr [eax + 0x16], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = 0 /*0x0*/;
    // 004a6a76  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a6a7d  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a6a83  ebaa                   -jmp 0x4a6a2f
    goto L_0x004a6a2f;
L_0x004a6a85:
    // 004a6a85  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a6a88  c70200684a00           -mov dword ptr [edx], 0x4a6800
    app->getMemory<x86::reg32>(cpu.edx) = 4876288 /*0x4a6800*/;
    // 004a6a8e  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a6a91  c7000c694a00           -mov dword ptr [eax], 0x4a690c
    app->getMemory<x86::reg32>(cpu.eax) = 4876556 /*0x4a690c*/;
    // 004a6a97  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6a99  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6a9a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6a9b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a6a9c:
    // 004a6a9c  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a6a9f  c702f8674a00           -mov dword ptr [edx], 0x4a67f8
    app->getMemory<x86::reg32>(cpu.edx) = 4876280 /*0x4a67f8*/;
    // 004a6aa5  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a6aa8  c70000694a00           -mov dword ptr [eax], 0x4a6900
    app->getMemory<x86::reg32>(cpu.eax) = 4876544 /*0x4a6900*/;
    // 004a6aae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6ab0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6ab1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6ab2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a6ab4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6ab4  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a6ab8  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a6abe  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a6ac5  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004a6ac9  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004a6ad0  c6401500               -mov byte ptr [eax + 0x15], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 004a6ad4  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a6ad8  c6401601               -mov byte ptr [eax + 0x16], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = 1 /*0x1*/;
    // 004a6adc  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004a6adf  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a6ae3  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004a6ae6  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a6aea  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004a6aed  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a6af0  c700106a4a00           -mov dword ptr [eax], 0x4a6a10
    app->getMemory<x86::reg32>(cpu.eax) = 4876816 /*0x4a6a10*/;
    // 004a6af6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6af8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a6b00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6b00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6b01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6b02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6b03  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a6b07  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a6b0b  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a6b0e  48                     -dec eax
    (cpu.eax)--;
    // 004a6b0f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a6b12  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a6b15  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a6b18  8b5a1b                 -mov ebx, dword ptr [edx + 0x1b]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(27) /* 0x1b */);
    // 004a6b1b  40                     -inc eax
    (cpu.eax)++;
    // 004a6b1c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a6b1f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a6b21  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a6b23  8a5a1d                 -mov bl, byte ptr [edx + 0x1d]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(29) /* 0x1d */);
    // 004a6b26  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a6b28  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a6b2a  7501                   -jne 0x4a6b2d
    if (!cpu.flags.zf)
    {
        goto L_0x004a6b2d;
    }
    // 004a6b2c  40                     -inc eax
    (cpu.eax)++;
L_0x004a6b2d:
    // 004a6b2d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a6b31  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a6b34  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a6b37  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004a6b3a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a6b3d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a6b3f  88511e                 -mov byte ptr [ecx + 0x1e], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) = cpu.dl;
    // 004a6b42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6b43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6b44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6b45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a6b48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6b48  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a6b4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a6b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6b50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6b51  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a6b55  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a6b59  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a6b5c  48                     -dec eax
    (cpu.eax)--;
    // 004a6b5d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a6b60  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a6b63  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a6b65  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a6b68  8a5a1d                 -mov bl, byte ptr [edx + 0x1d]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(29) /* 0x1d */);
    // 004a6b6b  40                     -inc eax
    (cpu.eax)++;
    // 004a6b6c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a6b6e  7501                   -jne 0x4a6b71
    if (!cpu.flags.zf)
    {
        goto L_0x004a6b71;
    }
    // 004a6b70  40                     -inc eax
    (cpu.eax)++;
L_0x004a6b71:
    // 004a6b71  8b5119                 -mov edx, dword ptr [ecx + 0x19]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(25) /* 0x19 */);
    // 004a6b74  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a6b77  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a6b79  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6b7a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a6b7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6b7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6b7d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6b7e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6b7f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6b80  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a6b83  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a6b87  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a6b8b  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a6b8f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a6b91  8a481d                 -mov cl, byte ptr [eax + 0x1d]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(29) /* 0x1d */);
    // 004a6b94  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a6b96  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a6b98  0f8598000000           -jne 0x4a6c36
    if (!cpu.flags.zf)
    {
        goto L_0x004a6c36;
    }
L_0x004a6b9e:
    // 004a6b9e  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a6ba2  4f                     -dec edi
    (cpu.edi)--;
    // 004a6ba3  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a6ba6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a6ba8  0f8f9d000000           -jg 0x4a6c4b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a6c4b;
    }
L_0x004a6bae:
    // 004a6bae  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a6bb0  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a6bb3  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a6bb7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a6bba  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 004a6bbd  dc0d14f64b00           -fmul qword ptr [0x4bf614]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4978196) /* 0x4bf614 */));
    // 004a6bc3  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a6bc5  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004a6bc7  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004a6bc9  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a6bcb  d944c608               -fld dword ptr [esi + eax*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 8)));
    // 004a6bcf  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a6bd1  d904c6                 -fld dword ptr [esi + eax*8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 8)));
    // 004a6bd4  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a6bd6  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a6bd8  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 004a6bdf  d91c28                 -fstp dword ptr [eax + ebp]
    app->getMemory<float>(cpu.eax + cpu.ebp * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6be2  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a6be4  d84cfe04               -fmul dword ptr [esi + edi*8 + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.edi * 8));
    // 004a6be8  d944fe0c               -fld dword ptr [esi + edi*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.edi * 8)));
    // 004a6bec  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a6bee  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a6bf0  d95c2804               -fstp dword ptr [eax + ebp + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6bf4  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a6bf6  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a6bf9  d944c608               -fld dword ptr [esi + eax*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 8)));
    // 004a6bfd  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a6bff  d95b14                 -fstp dword ptr [ebx + 0x14]
    app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6c02  d944c60c               -fld dword ptr [esi + eax*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.eax * 8)));
    // 004a6c06  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a6c09  d95b18                 -fstp dword ptr [ebx + 0x18]
    app->getMemory<float>(cpu.ebx + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6c0c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a6c0e  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a6c10  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a6c12  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a6c15  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a6c18  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a6c1e  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a6c20  8b431b                 -mov eax, dword ptr [ebx + 0x1b]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(27) /* 0x1b */);
    // 004a6c23  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 004a6c25  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a6c28  c6431d01               -mov byte ptr [ebx + 0x1d], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(29) /* 0x1d */) = 1 /*0x1*/;
    // 004a6c2c  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a6c2e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a6c31  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6c32  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6c33  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6c34  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6c35  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a6c36:
    // 004a6c36  8d72fc                 -lea esi, [edx - 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004a6c39  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a6c3c  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a6c3e  83ee04                 +sub esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6c41  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004a6c44  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a6c46  e953ffffff             -jmp 0x4a6b9e
    goto L_0x004a6b9e;
L_0x004a6c4b:
    // 004a6c4b  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a6c4e  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a6c51  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a6c54  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004a6c57  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a6c5a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6c5b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a6c5e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a6c5f  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a6c63  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a6c67  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a6c68  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6c69  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6c6a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6c6b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6c6c  e81b570000             -call 0x4ac38c
    cpu.esp -= 4;
    sub_4ac38c(app, cpu);
    if (cpu.terminate) return;
    // 004a6c71  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a6c74  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a6c78  c1e810                 +shr eax, 0x10
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
    // 004a6c7b  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a6c7e  e92bffffff             -jmp 0x4a6bae
    goto L_0x004a6bae;
}

/* align: skip 0x90 */
void Application::sub_4a6c84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6c84  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a6c88  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a6c8c  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a6c8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a6c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6c90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6c91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6c92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6c93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6c94  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a6c97  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a6c9b  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a6c9f  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a6ca3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a6ca5  8a481d                 -mov cl, byte ptr [eax + 0x1d]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(29) /* 0x1d */);
    // 004a6ca8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a6caa  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a6cac  0f85f2000000           -jne 0x4a6da4
    if (!cpu.flags.zf)
    {
        goto L_0x004a6da4;
    }
L_0x004a6cb2:
    // 004a6cb2  807b1c00               +cmp byte ptr [ebx + 0x1c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a6cb6  7412                   -je 0x4a6cca
    if (cpu.flags.zf)
    {
        goto L_0x004a6cca;
    }
    // 004a6cb8  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004a6cbb  8946fc                 -mov dword ptr [esi - 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a6cbe  83ee04                 -sub esi, 4
    (cpu.esi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a6cc1  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a6cc4  8946fc                 -mov dword ptr [esi - 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a6cc7  83ee04                 -sub esi, 4
    (cpu.esi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004a6cca:
    // 004a6cca  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a6cce  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004a6cd4  4f                     -dec edi
    (cpu.edi)--;
    // 004a6cd5  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a6cd8  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a6cda  7e33                   -jle 0x4a6d0f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a6d0f;
    }
    // 004a6cdc  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a6cdf  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a6ce2  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a6ce5  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a6ce8  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a6ceb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a6cec  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a6cef  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6cf0  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a6cf4  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a6cf8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a6cf9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6cfa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6cfb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6cfc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6cfd  e88a560000             -call 0x4ac38c
    cpu.esp -= 4;
    sub_4ac38c(app, cpu);
    if (cpu.terminate) return;
    // 004a6d02  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a6d05  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a6d09  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a6d0c  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004a6d0f:
    // 004a6d0f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a6d11  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a6d14  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a6d18  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a6d1b  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 004a6d1e  dc0d1cf64b00           -fmul qword ptr [0x4bf61c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4978204) /* 0x4bf61c */));
    // 004a6d24  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a6d26  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a6d28  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004a6d2a  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004a6d2c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a6d2e  d944c608               -fld dword ptr [esi + eax*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 8)));
    // 004a6d32  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a6d34  d904c6                 -fld dword ptr [esi + eax*8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 8)));
    // 004a6d37  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a6d39  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a6d3b  d95cfd00               -fstp dword ptr [ebp + edi*8]
    app->getMemory<float>(cpu.ebp + cpu.edi * 8) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6d3f  d84cd604               -fmul dword ptr [esi + edx*8 + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.edx * 8));
    // 004a6d43  d944d60c               -fld dword ptr [esi + edx*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.edx * 8)));
    // 004a6d47  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a6d49  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a6d4b  d95cfd04               -fstp dword ptr [ebp + edi*8 + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */ + cpu.edi * 8) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6d4f  d944d608               -fld dword ptr [esi + edx*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.edx * 8)));
    // 004a6d53  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a6d56  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a6d59  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a6d5b  8b6b08                 -mov ebp, dword ptr [ebx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a6d5e  d95b14                 -fstp dword ptr [ebx + 0x14]
    app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6d61  d944d60c               -fld dword ptr [esi + edx*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.edx * 8)));
    // 004a6d65  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a6d67  d95b18                 -fstp dword ptr [ebx + 0x18]
    app->getMemory<float>(cpu.ebx + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6d6a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a6d6c  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a6d6f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a6d72  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a6d78  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a6d7a  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a6d7d  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004a6d7f  39e8                   +cmp eax, ebp
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
    // 004a6d81  7236                   -jb 0x4a6db9
    if (cpu.flags.cf)
    {
        goto L_0x004a6db9;
    }
    // 004a6d83  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a6d85  c6431c01               -mov byte ptr [ebx + 0x1c], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 004a6d89  d904c6                 -fld dword ptr [esi + eax*8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 8)));
    // 004a6d8c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a6d8e  d95b0c                 -fstp dword ptr [ebx + 0xc]
    app->getMemory<float>(cpu.ebx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6d91  8b54c604               -mov edx, dword ptr [esi + eax*8 + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 004a6d95  895310                 -mov dword ptr [ebx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004a6d98  c6431d01               -mov byte ptr [ebx + 0x1d], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(29) /* 0x1d */) = 1 /*0x1*/;
    // 004a6d9c  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a6d9f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6da0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6da1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6da2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6da3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a6da4:
    // 004a6da4  8d72fc                 -lea esi, [edx - 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004a6da7  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a6daa  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a6dac  83ee04                 +sub esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6daf  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004a6db2  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a6db4  e9f9feffff             -jmp 0x4a6cb2
    goto L_0x004a6cb2;
L_0x004a6db9:
    // 004a6db9  c6431c00               -mov byte ptr [ebx + 0x1c], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004a6dbd  c6431d01               -mov byte ptr [ebx + 0x1d], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(29) /* 0x1d */) = 1 /*0x1*/;
    // 004a6dc1  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a6dc4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6dc5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6dc6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6dc7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6dc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a6dcc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6dcc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6dcd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6dce  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a6dd2  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a6dd6  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a6dd9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a6ddb  81fb00000100           +cmp ebx, 0x10000
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
    // 004a6de1  732c                   -jae 0x4a6e0f
    if (!cpu.flags.cf)
    {
        goto L_0x004a6e0f;
    }
    // 004a6de3  81fa00000100           +cmp edx, 0x10000
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
    // 004a6de9  7324                   -jae 0x4a6e0f
    if (!cpu.flags.cf)
    {
        goto L_0x004a6e0f;
    }
L_0x004a6deb:
    // 004a6deb  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a6dee  81fa00000100           +cmp edx, 0x10000
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
    // 004a6df4  724b                   -jb 0x4a6e41
    if (cpu.flags.cf)
    {
        goto L_0x004a6e41;
    }
    // 004a6df6  7660                   -jbe 0x4a6e58
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a6e58;
    }
    // 004a6df8  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004a6dfb  c702006b4a00           -mov dword ptr [edx], 0x4a6b00
    app->getMemory<x86::reg32>(cpu.edx) = 4877056 /*0x4a6b00*/;
    // 004a6e01  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004a6e04  c7007c6b4a00           -mov dword ptr [eax], 0x4a6b7c
    app->getMemory<x86::reg32>(cpu.eax) = 4877180 /*0x4a6b7c*/;
    // 004a6e0a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6e0c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6e0d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6e0e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a6e0f:
    // 004a6e0f  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a6e12  39f2                   +cmp edx, esi
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
    // 004a6e14  74d5                   -je 0x4a6deb
    if (cpu.flags.zf)
    {
        goto L_0x004a6deb;
    }
    // 004a6e16  81fe00000100           +cmp esi, 0x10000
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
    // 004a6e1c  7608                   -jbe 0x4a6e26
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a6e26;
    }
    // 004a6e1e  81fa00000100           +cmp edx, 0x10000
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
    // 004a6e24  77c5                   -ja 0x4a6deb
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a6deb;
    }
L_0x004a6e26:
    // 004a6e26  c6401c00               -mov byte ptr [eax + 0x1c], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004a6e2a  c6401d00               -mov byte ptr [eax + 0x1d], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(29) /* 0x1d */) = 0 /*0x0*/;
    // 004a6e2e  c6401e00               -mov byte ptr [eax + 0x1e], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */) = 0 /*0x0*/;
    // 004a6e32  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a6e39  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a6e3f  ebaa                   -jmp 0x4a6deb
    goto L_0x004a6deb;
L_0x004a6e41:
    // 004a6e41  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004a6e44  c702506b4a00           -mov dword ptr [edx], 0x4a6b50
    app->getMemory<x86::reg32>(cpu.edx) = 4877136 /*0x4a6b50*/;
    // 004a6e4a  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004a6e4d  c700906c4a00           -mov dword ptr [eax], 0x4a6c90
    app->getMemory<x86::reg32>(cpu.eax) = 4877456 /*0x4a6c90*/;
    // 004a6e53  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6e55  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6e56  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6e57  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a6e58:
    // 004a6e58  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004a6e5b  c702486b4a00           -mov dword ptr [edx], 0x4a6b48
    app->getMemory<x86::reg32>(cpu.edx) = 4877128 /*0x4a6b48*/;
    // 004a6e61  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004a6e64  c700846c4a00           -mov dword ptr [eax], 0x4a6c84
    app->getMemory<x86::reg32>(cpu.eax) = 4877444 /*0x4a6c84*/;
    // 004a6e6a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6e6c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6e6d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6e6e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a6e70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6e70  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a6e74  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a6e7a  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a6e81  c6401c00               -mov byte ptr [eax + 0x1c], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004a6e85  c6401d00               -mov byte ptr [eax + 0x1d], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(29) /* 0x1d */) = 0 /*0x0*/;
    // 004a6e89  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a6e8d  c6401e00               -mov byte ptr [eax + 0x1e], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */) = 0 /*0x0*/;
    // 004a6e91  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004a6e94  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a6e98  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004a6e9b  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a6e9f  895028                 -mov dword ptr [eax + 0x28], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004a6ea2  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a6ea5  c700cc6d4a00           -mov dword ptr [eax], 0x4a6dcc
    app->getMemory<x86::reg32>(cpu.eax) = 4877772 /*0x4a6dcc*/;
    // 004a6eab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6ead  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4a6eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6eb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6eb1  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a6eb4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a6eb8  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a6ebc  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004a6ebf  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a6ec3  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a6ec5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a6ec7  39d9                   +cmp ecx, ebx
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
    // 004a6ec9  7341                   -jae 0x4a6f0c
    if (!cpu.flags.cf)
    {
        goto L_0x004a6f0c;
    }
L_0x004a6ecb:
    // 004a6ecb  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004a6ece  d800                   -fadd dword ptr [eax]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax));
    // 004a6ed0  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a6ed2  dc0d24f64b00           -fmul qword ptr [0x4bf624]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4978212) /* 0x4bf624 */));
    // 004a6ed8  ddd1                   -fst st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    // 004a6eda  dc052cf64b00           -fadd qword ptr [0x4bf62c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4978220) /* 0x4bf62c */));
    // 004a6ee0  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6ee2  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6ee4  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a6ee6  81e1ffff0f00           -and ecx, 0xfffff
    cpu.ecx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004a6eec  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a6eef  83f97f                 +cmp ecx, 0x7f
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
    // 004a6ef2  7622                   -jbe 0x4a6f16
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a6f16;
    }
    // 004a6ef4  81f980ff0f00           +cmp ecx, 0xfff80
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1048448 /*0xfff80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6efa  731a                   -jae 0x4a6f16
    if (!cpu.flags.cf)
    {
        goto L_0x004a6f16;
    }
    // 004a6efc  81f900000800           +cmp ecx, 0x80000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6f02  730d                   -jae 0x4a6f11
    if (!cpu.flags.cf)
    {
        goto L_0x004a6f11;
    }
    // 004a6f04  c602ff                 -mov byte ptr [edx], 0xff
    app->getMemory<x86::reg8>(cpu.edx) = 255 /*0xff*/;
L_0x004a6f07:
    // 004a6f07  42                     -inc edx
    (cpu.edx)++;
    // 004a6f08  39d8                   +cmp eax, ebx
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
    // 004a6f0a  72bf                   -jb 0x4a6ecb
    if (cpu.flags.cf)
    {
        goto L_0x004a6ecb;
    }
L_0x004a6f0c:
    // 004a6f0c  83c408                 +add esp, 8
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
    // 004a6f0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6f10  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a6f11:
    // 004a6f11  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004a6f14  ebf1                   -jmp 0x4a6f07
    goto L_0x004a6f07;
L_0x004a6f16:
    // 004a6f16  80c180                 -add cl, 0x80
    (cpu.cl) += x86::reg8(x86::sreg8(128 /*0x80*/));
    // 004a6f19  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 004a6f1b  42                     -inc edx
    (cpu.edx)++;
    // 004a6f1c  39d8                   +cmp eax, ebx
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
    // 004a6f1e  72ab                   -jb 0x4a6ecb
    if (cpu.flags.cf)
    {
        goto L_0x004a6ecb;
    }
    // 004a6f20  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a6f23  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6f24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a6f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6f30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6f31  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a6f34  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a6f38  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a6f3c  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004a6f3f  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a6f43  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a6f45  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a6f47  39d9                   +cmp ecx, ebx
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
    // 004a6f49  7339                   -jae 0x4a6f84
    if (!cpu.flags.cf)
    {
        goto L_0x004a6f84;
    }
L_0x004a6f4b:
    // 004a6f4b  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004a6f4d  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a6f4f  dc0534f64b00           -fadd qword ptr [0x4bf634]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4978228) /* 0x4bf634 */));
    // 004a6f55  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6f57  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6f59  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a6f5b  81e1ffff0f00           -and ecx, 0xfffff
    cpu.ecx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004a6f61  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a6f64  81f9ff7f0000           +cmp ecx, 0x7fff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6f6a  7622                   -jbe 0x4a6f8e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a6f8e;
    }
    // 004a6f6c  81f900800f00           +cmp ecx, 0xf8000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1015808 /*0xf8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6f72  731a                   -jae 0x4a6f8e
    if (!cpu.flags.cf)
    {
        goto L_0x004a6f8e;
    }
    // 004a6f74  81f900000800           +cmp ecx, 0x80000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6f7a  730d                   -jae 0x4a6f89
    if (!cpu.flags.cf)
    {
        goto L_0x004a6f89;
    }
    // 004a6f7c  c602ff                 -mov byte ptr [edx], 0xff
    app->getMemory<x86::reg8>(cpu.edx) = 255 /*0xff*/;
L_0x004a6f7f:
    // 004a6f7f  42                     -inc edx
    (cpu.edx)++;
    // 004a6f80  39d8                   +cmp eax, ebx
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
    // 004a6f82  72c7                   -jb 0x4a6f4b
    if (cpu.flags.cf)
    {
        goto L_0x004a6f4b;
    }
L_0x004a6f84:
    // 004a6f84  83c408                 +add esp, 8
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
    // 004a6f87  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6f88  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a6f89:
    // 004a6f89  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004a6f8c  ebf1                   -jmp 0x4a6f7f
    goto L_0x004a6f7f;
L_0x004a6f8e:
    // 004a6f8e  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 004a6f91  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a6f97  81c180000000           -add ecx, 0x80
    (cpu.ecx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004a6f9d  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 004a6f9f  42                     -inc edx
    (cpu.edx)++;
    // 004a6fa0  39d8                   +cmp eax, ebx
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
    // 004a6fa2  72a7                   -jb 0x4a6f4b
    if (cpu.flags.cf)
    {
        goto L_0x004a6f4b;
    }
    // 004a6fa4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a6fa7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6fa8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a6fb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6fb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6fb1  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a6fb4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a6fb8  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a6fbc  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004a6fbf  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a6fc3  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a6fc5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a6fc7  39d9                   +cmp ecx, ebx
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
    // 004a6fc9  7348                   -jae 0x4a7013
    if (!cpu.flags.cf)
    {
        goto L_0x004a7013;
    }
L_0x004a6fcb:
    // 004a6fcb  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004a6fce  d800                   -fadd dword ptr [eax]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax));
    // 004a6fd0  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a6fd2  dc0d3cf64b00           -fmul qword ptr [0x4bf63c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4978236) /* 0x4bf63c */));
    // 004a6fd8  ddd1                   -fst st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    // 004a6fda  dc0544f64b00           -fadd qword ptr [0x4bf644]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4978244) /* 0x4bf644 */));
    // 004a6fe0  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6fe2  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a6fe4  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a6fe6  81e1ffff0f00           -and ecx, 0xfffff
    cpu.ecx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004a6fec  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a6fef  81f9ff7f0000           +cmp ecx, 0x7fff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6ff5  7628                   -jbe 0x4a701f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a701f;
    }
    // 004a6ff7  81f900800f00           +cmp ecx, 0xf8000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1015808 /*0xf8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6ffd  7320                   -jae 0x4a701f
    if (!cpu.flags.cf)
    {
        goto L_0x004a701f;
    }
    // 004a6fff  81f900000800           +cmp ecx, 0x80000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7005  7311                   -jae 0x4a7018
    if (!cpu.flags.cf)
    {
        goto L_0x004a7018;
    }
    // 004a7007  66c702ff7f             -mov word ptr [edx], 0x7fff
    app->getMemory<x86::reg16>(cpu.edx) = 32767 /*0x7fff*/;
L_0x004a700c:
    // 004a700c  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a700f  39d8                   +cmp eax, ebx
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
    // 004a7011  72b8                   -jb 0x4a6fcb
    if (cpu.flags.cf)
    {
        goto L_0x004a6fcb;
    }
L_0x004a7013:
    // 004a7013  83c408                 +add esp, 8
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
    // 004a7016  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7017  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7018:
    // 004a7018  66c7020080             -mov word ptr [edx], 0x8000
    app->getMemory<x86::reg16>(cpu.edx) = 32768 /*0x8000*/;
    // 004a701d  ebed                   -jmp 0x4a700c
    goto L_0x004a700c;
L_0x004a701f:
    // 004a701f  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004a7022  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a7025  39d8                   +cmp eax, ebx
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
    // 004a7027  72a2                   -jb 0x4a6fcb
    if (cpu.flags.cf)
    {
        goto L_0x004a6fcb;
    }
    // 004a7029  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a702c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a702d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4a7030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7030  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7031  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a7034  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a7038  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a703c  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004a703f  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a7043  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7045  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a7047  39d9                   +cmp ecx, ebx
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
    // 004a7049  733d                   -jae 0x4a7088
    if (!cpu.flags.cf)
    {
        goto L_0x004a7088;
    }
L_0x004a704b:
    // 004a704b  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004a704d  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a704f  dc054cf64b00           -fadd qword ptr [0x4bf64c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4978252) /* 0x4bf64c */));
    // 004a7055  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a7057  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a7059  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a705b  81e1ffff0f00           -and ecx, 0xfffff
    cpu.ecx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004a7061  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7064  81f9ff7f0000           +cmp ecx, 0x7fff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a706a  7628                   -jbe 0x4a7094
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a7094;
    }
    // 004a706c  81f900800f00           +cmp ecx, 0xf8000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1015808 /*0xf8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7072  7320                   -jae 0x4a7094
    if (!cpu.flags.cf)
    {
        goto L_0x004a7094;
    }
    // 004a7074  81f900000800           +cmp ecx, 0x80000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a707a  7311                   -jae 0x4a708d
    if (!cpu.flags.cf)
    {
        goto L_0x004a708d;
    }
    // 004a707c  66c702ff7f             -mov word ptr [edx], 0x7fff
    app->getMemory<x86::reg16>(cpu.edx) = 32767 /*0x7fff*/;
L_0x004a7081:
    // 004a7081  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a7084  39d8                   +cmp eax, ebx
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
    // 004a7086  72c3                   -jb 0x4a704b
    if (cpu.flags.cf)
    {
        goto L_0x004a704b;
    }
L_0x004a7088:
    // 004a7088  83c408                 +add esp, 8
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
    // 004a708b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a708c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a708d:
    // 004a708d  66c7020080             -mov word ptr [edx], 0x8000
    app->getMemory<x86::reg16>(cpu.edx) = 32768 /*0x8000*/;
    // 004a7092  ebed                   -jmp 0x4a7081
    goto L_0x004a7081;
L_0x004a7094:
    // 004a7094  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004a7097  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a709a  39d8                   +cmp eax, ebx
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
    // 004a709c  72ad                   -jb 0x4a704b
    if (cpu.flags.cf)
    {
        goto L_0x004a704b;
    }
    // 004a709e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a70a1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a70a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a70a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a70a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a70a5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a70a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a70a8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a70a9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a70aa  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a70ad  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a70b0  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004a70b5  83f90f                 +cmp ecx, 0xf
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
    // 004a70b8  7e3d                   -jle 0x4a70f7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a70f7;
    }
    // 004a70ba  83e90f                 -sub ecx, 0xf
    (cpu.ecx) -= x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x004a70bd:
    // 004a70bd  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a70bf  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a70c2  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a70c5  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a70c8  894710                 -mov dword ptr [edi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a70cb  894714                 -mov dword ptr [edi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a70ce  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a70d1  89471c                 -mov dword ptr [edi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004a70d4  894720                 -mov dword ptr [edi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004a70d7  894724                 -mov dword ptr [edi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004a70da  894728                 -mov dword ptr [edi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004a70dd  89472c                 -mov dword ptr [edi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a70e0  894730                 -mov dword ptr [edi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004a70e3  894734                 -mov dword ptr [edi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004a70e6  894738                 -mov dword ptr [edi + 0x38], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004a70e9  89473c                 -mov dword ptr [edi + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 004a70ec  83c740                 -add edi, 0x40
    (cpu.edi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a70ef  83e910                 +sub ecx, 0x10
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
    // 004a70f2  7fc9                   -jg 0x4a70bd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a70bd;
    }
    // 004a70f4  83c10f                 -add ecx, 0xf
    (cpu.ecx) += x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x004a70f7:
    // 004a70f7  83f900                 +cmp ecx, 0
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
    // 004a70fa  7e0a                   -jle 0x4a7106
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a7106;
    }
    // 004a70fc  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a70fe  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7101  83e901                 +sub ecx, 1
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
    // 004a7104  7ff1                   -jg 0x4a70f7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a70f7;
    }
L_0x004a7106:
    // 004a7106  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7107  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7108  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7109  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a710a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a710c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a710c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a710d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a710f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7110  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7111  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a7114  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a7117  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a711a  c70069714a00           -mov dword ptr [eax], 0x4a7169
    app->getMemory<x86::reg32>(cpu.eax) = 4878697 /*0x4a7169*/;
    // 004a7120  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a7123  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a7126  c70030714a00           -mov dword ptr [eax], 0x4a7130
    app->getMemory<x86::reg32>(cpu.eax) = 4878640 /*0x4a7130*/;
    // 004a712c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a712d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a712e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a712f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a7130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7130  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7131  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a7133  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7134  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7135  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7136  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a7139  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a713c  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004a713f  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a7142  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004a7145  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004a7149  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a714b  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a714e  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a7151  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004a7154  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a7157  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004a715a  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004a715e  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a7161  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a7164  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7165  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7166  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7167  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7168  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a7169(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7169  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a716a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a716c  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a716d  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a7170  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a7173  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a7176  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 004a7179  0f6f4e08               -movq mm1, qword ptr [esi + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 004a717d  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a7180  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a7182  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a7185  83f800                 +cmp eax, 0
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
    // 004a7188  7405                   -je 0x4a718f
    if (cpu.flags.zf)
    {
        goto L_0x004a718f;
    }
    // 004a718a  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a718d  7c3e                   -jl 0x4a71cd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a71cd;
    }
L_0x004a718f:
    // 004a718f  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004a7192  0f6fe1                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 004a7195  0f6e2f                 -movd mm5, dword ptr [edi]
    cpu.mmx.mm5 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.edi)) };
    // 004a7198  0f60f5                 -punpcklbw mm6, mm5
    cpu.mmx.mm6 = { _mm_unpacklo_epi8(cpu.mmx.mm6, cpu.mmx.mm5) };
    // 004a719b  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 004a719e  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 004a71a1  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004a71a4  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 004a71a7  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004a71aa  0fed5500               -paddsw mm2, qword ptr [ebp]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp))) };
    // 004a71ae  0fed5d08               -paddsw mm3, qword ptr [ebp + 8]
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */))) };
    // 004a71b2  0f7f5500               -movq qword ptr [ebp], mm2
    app->getMemory<x86::reg64>(cpu.ebp) = cpu.mmx.mm2;
    // 004a71b6  0f7f5d08               -movq qword ptr [ebp + 8], mm3
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm3;
    // 004a71ba  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a71bd  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a71c0  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a71c3  7fca                   -jg 0x4a718f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a718f;
    }
    // 004a71c5  83f900                 +cmp ecx, 0
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
    // 004a71c8  7503                   -jne 0x4a71cd
    if (!cpu.flags.zf)
    {
        goto L_0x004a71cd;
    }
    // 004a71ca  61                     -popal 
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
    // 004a71cb  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a71cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a71cd:
    // 004a71cd  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a71d0  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a71d2  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
L_0x004a71d7:
    // 004a71d7  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004a71da  0f6fe1                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 004a71dd  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 004a71df  0f6ef0                 -movd mm6, eax
    cpu.mmx.mm6 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a71e2  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 004a71e5  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 004a71e8  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004a71eb  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 004a71ee  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004a71f1  0f6e5d00               -movd mm3, dword ptr [ebp]
    cpu.mmx.mm3 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebp)) };
    // 004a71f5  0fedda                 -paddsw mm3, mm2
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm2) };
    // 004a71f8  0f7e5d00               -movd dword ptr [ebp], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebp), cpu.mmx.mm3);
    // 004a71fc  83c701                 -add edi, 1
    (cpu.edi) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a71ff  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a7202  83c101                 +add ecx, 1
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
    // 004a7205  7cd0                   -jl 0x4a71d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a71d7;
    }
    // 004a7207  61                     -popal 
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
    // 004a7208  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7209  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4a720c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a720c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a720d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a720f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7210  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7211  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a7214  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a7217  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a721a  c70053724a00           -mov dword ptr [eax], 0x4a7253
    app->getMemory<x86::reg32>(cpu.eax) = 4878931 /*0x4a7253*/;
    // 004a7220  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a7223  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a7226  c70030724a00           -mov dword ptr [eax], 0x4a7230
    app->getMemory<x86::reg32>(cpu.eax) = 4878896 /*0x4a7230*/;
    // 004a722c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a722d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a722e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a722f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a7230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7230  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7231  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a7233  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7234  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7235  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7236  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a7239  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a723c  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004a723f  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a7242  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004a7245  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004a7249  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a724b  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a724e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a724f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7250  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7251  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7252  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a7253(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7253  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7254  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a7256  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a7257  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a725a  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a725d  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a7260  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 004a7263  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a7266  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a7268  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a726b  83f800                 +cmp eax, 0
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
    // 004a726e  7405                   -je 0x4a7275
    if (cpu.flags.zf)
    {
        goto L_0x004a7275;
    }
    // 004a7270  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7273  7c38                   -jl 0x4a72ad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a72ad;
    }
L_0x004a7275:
    // 004a7275  0f6f1f                 -movq mm3, qword ptr [edi]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi));
    // 004a7278  0f6fc8                 -movq mm1, mm0
    cpu.mmx.mm1 = cpu.mmx.mm0;
    // 004a727b  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004a727e  0f60e3                 -punpcklbw mm4, mm3
    cpu.mmx.mm4 = { _mm_unpacklo_epi8(cpu.mmx.mm4, cpu.mmx.mm3) };
    // 004a7281  0f68eb                 -punpckhbw mm5, mm3
    cpu.mmx.mm5 = { _mm_unpacklo_epi8(_mm_srli_epi64(cpu.mmx.mm5, 32), _mm_srli_epi64(cpu.mmx.mm3, 32)) };
    // 004a7284  0fe5cc                 -pmulhw mm1, mm4
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, cpu.mmx.mm4) };
    // 004a7287  0fe5d5                 -pmulhw mm2, mm5
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 004a728a  0fed4d00               -paddsw mm1, qword ptr [ebp]
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp))) };
    // 004a728e  0fed5508               -paddsw mm2, qword ptr [ebp + 8]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */))) };
    // 004a7292  0f7f4d00               -movq qword ptr [ebp], mm1
    app->getMemory<x86::reg64>(cpu.ebp) = cpu.mmx.mm1;
    // 004a7296  0f7f5508               -movq qword ptr [ebp + 8], mm2
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm2;
    // 004a729a  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a729d  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a72a0  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a72a3  7fd0                   -jg 0x4a7275
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a7275;
    }
    // 004a72a5  83f900                 +cmp ecx, 0
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
    // 004a72a8  7503                   -jne 0x4a72ad
    if (!cpu.flags.zf)
    {
        goto L_0x004a72ad;
    }
    // 004a72aa  61                     -popal 
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
    // 004a72ab  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a72ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a72ad:
    // 004a72ad  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a72b0  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x004a72b2:
    // 004a72b2  8a4701                 -mov al, byte ptr [edi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a72b5  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004a72b8  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 004a72ba  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a72bd  0fe5c8                 -pmulhw mm1, mm0
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a72c0  0f6e5500               -movd mm2, dword ptr [ebp]
    cpu.mmx.mm2 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebp)) };
    // 004a72c4  0fedca                 -paddsw mm1, mm2
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm2) };
    // 004a72c7  0f7e4d00               -movd dword ptr [ebp], mm1
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebp), cpu.mmx.mm1);
    // 004a72cb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a72ce  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a72d1  83c101                 +add ecx, 1
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
    // 004a72d4  7cdc                   -jl 0x4a72b2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a72b2;
    }
    // 004a72d6  61                     -popal 
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
    // 004a72d7  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a72d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4a72dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a72dc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a72dd  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a72df  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a72e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a72e1  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a72e4  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a72e7  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a72ea  c70039734a00           -mov dword ptr [eax], 0x4a7339
    app->getMemory<x86::reg32>(cpu.eax) = 4879161 /*0x4a7339*/;
    // 004a72f0  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a72f3  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a72f6  c70000734a00           -mov dword ptr [eax], 0x4a7300
    app->getMemory<x86::reg32>(cpu.eax) = 4879104 /*0x4a7300*/;
    // 004a72fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a72fd  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a72fe  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a72ff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a7300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7300  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7301  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a7303  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a7304  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7305  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7306  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a7309  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a730c  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004a730f  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a7312  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004a7315  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004a7319  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a731b  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a731e  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a7321  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004a7324  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a7327  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004a732a  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004a732e  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a7331  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a7334  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7335  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7336  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7337  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7338  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a7339(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7339  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a733a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a733c  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a733d  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a7340  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a7343  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a7346  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 004a7349  0f6f4e08               -movq mm1, qword ptr [esi + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 004a734d  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a7350  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a7352  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a7355  83f800                 +cmp eax, 0
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
    // 004a7358  7405                   -je 0x4a735f
    if (cpu.flags.zf)
    {
        goto L_0x004a735f;
    }
    // 004a735a  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a735d  7c39                   -jl 0x4a7398
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a7398;
    }
L_0x004a735f:
    // 004a735f  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004a7362  0f6fe1                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 004a7365  0f6f37                 -movq mm6, qword ptr [edi]
    cpu.mmx.mm6 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi));
    // 004a7368  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 004a736b  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 004a736e  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004a7371  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 004a7374  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004a7377  0fed13                 -paddsw mm2, qword ptr [ebx]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebx))) };
    // 004a737a  0fed5b08               -paddsw mm3, qword ptr [ebx + 8]
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebx + x86::reg32(8) /* 0x8 */))) };
    // 004a737e  0f7f13                 -movq qword ptr [ebx], mm2
    app->getMemory<x86::reg64>(cpu.ebx) = cpu.mmx.mm2;
    // 004a7381  0f7f5b08               -movq qword ptr [ebx + 8], mm3
    app->getMemory<x86::reg64>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm3;
    // 004a7385  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a7388  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a738b  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a738e  7fcf                   -jg 0x4a735f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a735f;
    }
    // 004a7390  83f900                 +cmp ecx, 0
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
    // 004a7393  7503                   -jne 0x4a7398
    if (!cpu.flags.zf)
    {
        goto L_0x004a7398;
    }
    // 004a7395  61                     -popal 
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
    // 004a7396  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7397  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7398:
    // 004a7398  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a739b  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x004a739d:
    // 004a739d  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004a73a0  0f6fe1                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 004a73a3  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 004a73a6  0f6ef0                 -movd mm6, eax
    cpu.mmx.mm6 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a73a9  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 004a73ac  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 004a73af  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004a73b2  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 004a73b5  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004a73b8  0f6e1b                 -movd mm3, dword ptr [ebx]
    cpu.mmx.mm3 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebx)) };
    // 004a73bb  0fedda                 -paddsw mm3, mm2
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm2) };
    // 004a73be  0f7e1b                 -movd dword ptr [ebx], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebx), cpu.mmx.mm3);
    // 004a73c1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a73c4  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a73c7  83c101                 +add ecx, 1
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
    // 004a73ca  7cd1                   -jl 0x4a739d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a739d;
    }
    // 004a73cc  61                     -popal 
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
    // 004a73cd  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a73ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
