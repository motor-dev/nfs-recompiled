#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4df310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df310  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df311  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df312  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df313  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df314  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df316  e865c70000             -call 0x4eba80
    cpu.esp -= 4;
    sub_4eba80(app, cpu);
    if (cpu.terminate) return;
    // 004df31b  3b05c0a28c00           +cmp eax, dword ptr [0x8ca2c0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(9216704) /* 0x8ca2c0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df321  7518                   -jne 0x4df33b
    if (!cpu.flags.zf)
    {
        goto L_0x004df33b;
    }
    // 004df323  8b0dc8a28c00           -mov ecx, dword ptr [0x8ca2c8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(9216712) /* 0x8ca2c8 */);
    // 004df329  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004df32b  740e                   -je 0x4df33b
    if (cpu.flags.zf)
    {
        goto L_0x004df33b;
    }
    // 004df32d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df32e  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 004df330  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004df332  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df335  891dc8a28c00           -mov dword ptr [0x8ca2c8], ebx
    *app->getMemory<x86::reg32>(x86::reg32(9216712) /* 0x8ca2c8 */) = cpu.ebx;
L_0x004df33b:
    // 004df33b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df33c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df33d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df33e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df33f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4df340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df340  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df341  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df343  a1d4a28c00             -mov eax, dword ptr [0x8ca2d4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(9216724) /* 0x8ca2d4 */);
    // 004df348  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df349  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4df350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df350  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df351  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df352  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df353  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df355  8b1550435600           -mov edx, dword ptr [0x564350]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5653328) /* 0x564350 */);
L_0x004df35b:
    // 004df35b  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 004df35d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004df35f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004df361  7412                   -je 0x4df375
    if (cpu.flags.zf)
    {
        goto L_0x004df375;
    }
    // 004df363  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004df366  81fa6ff29e00           +cmp edx, 0x9ef26f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10416751 /*0x9ef26f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df36c  76ed                   -jbe 0x4df35b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004df35b;
    }
    // 004df36e  baf0a28c00             -mov edx, 0x8ca2f0
    cpu.edx = 9216752 /*0x8ca2f0*/;
    // 004df373  ebe6                   -jmp 0x4df35b
    goto L_0x004df35b;
L_0x004df375:
    // 004df375  891550435600           -mov dword ptr [0x564350], edx
    *app->getMemory<x86::reg32>(x86::reg32(5653328) /* 0x564350 */) = cpu.edx;
    // 004df37b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df37c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df37d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df37e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4df380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df380  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df381  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df383  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004df388  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df389  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4df390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df390  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df391  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df393  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df394  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4df3a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df3a0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df3a1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df3a2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df3a3  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df3a4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df3a5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df3a7  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004df3aa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004df3ac  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004df3ae  895df4                 -mov dword ptr [ebp - 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 004df3b1  895df8                 -mov dword ptr [ebp - 8], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004df3b4  833d4843560000         +cmp dword ptr [0x564348], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653320) /* 0x564348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df3bb  7454                   -je 0x4df411
    if (cpu.flags.zf)
    {
        goto L_0x004df411;
    }
    // 004df3bd  a370f29e00             -mov dword ptr [0x9ef270], eax
    *app->getMemory<x86::reg32>(x86::reg32(10416752) /* 0x9ef270 */) = cpu.eax;
    // 004df3c2  891574f29e00           -mov dword ptr [0x9ef274], edx
    *app->getMemory<x86::reg32>(x86::reg32(10416756) /* 0x9ef274 */) = cpu.edx;
    // 004df3c8  e883ffffff             -call 0x4df350
    cpu.esp -= 4;
    sub_4df350(app, cpu);
    if (cpu.terminate) return;
    // 004df3cd  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004df3d0  a174f29e00             -mov eax, dword ptr [0x9ef274]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10416756) /* 0x9ef274 */);
    // 004df3d5  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004df3d8  8950fc                 -mov dword ptr [eax - 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004df3db  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004df3dd  7432                   -je 0x4df411
    if (cpu.flags.zf)
    {
        goto L_0x004df411;
    }
    // 004df3df  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004df3e2  8b154c435600           -mov edx, dword ptr [0x56434c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5653324) /* 0x56434c */);
    // 004df3e8  83e904                 -sub ecx, 4
    (cpu.ecx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004df3eb  42                     -inc edx
    (cpu.edx)++;
    // 004df3ec  8908                   -mov dword ptr [eax], ecx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004df3ee  89154c435600           -mov dword ptr [0x56434c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5653324) /* 0x56434c */) = cpu.edx;
    // 004df3f4  0f31                   -rdtsc 
    cpu.rdtsc();
    // 004df3f6  8995f4ffffff           -mov dword ptr [ebp - 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004df3fc  8985f8ffffff           -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004df402  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004df405  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004df408  894204                 -mov dword ptr [edx + 4], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004df40b  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004df40e  894208                 -mov dword ptr [edx + 8], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004df411:
    // 004df411  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004df413  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df414  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df415  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df416  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df417  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df418  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4df420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df420  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df421  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df422  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df423  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df424  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df425  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df426  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df428  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004df42b  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004df42e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004df430  8945f8                 -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004df433  8955e8                 -mov dword ptr [ebp - 0x18], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 004df436  8955ec                 -mov dword ptr [ebp - 0x14], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 004df439  0f31                   -rdtsc 
    cpu.rdtsc();
    // 004df43b  8995e8ffffff           -mov dword ptr [ebp - 0x18], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 004df441  8985ecffffff           -mov dword ptr [ebp - 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004df447  833d4843560000         +cmp dword ptr [0x564348], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653320) /* 0x564348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df44e  0f84ce000000           -je 0x4df522
    if (cpu.flags.zf)
    {
        goto L_0x004df522;
    }
    // 004df454  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004df457  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 004df459  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004df45c  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004df45f  8945f0                 -mov dword ptr [ebp - 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004df462  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004df465  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004df468  8945f4                 -mov dword ptr [ebp - 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004df46b  8b85ecffffff           -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004df471  8b95e8ffffff           -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004df477  2b85f4ffffff           +sub eax, dword ptr [ebp - 0xc]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004df47d  1b95f0ffffff           -sbb edx, dword ptr [ebp - 0x10]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)) + cpu.flags.cf);
    // 004df483  8985f4ffffff           -mov dword ptr [ebp - 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004df489  8995f0ffffff           -mov dword ptr [ebp - 0x10], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004df48f  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004df492  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004df494  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004df496  8a01                   -mov al, byte ptr [ecx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx);
    // 004df498  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004df49a  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004df49c  ba78f49e00             -mov edx, 0x9ef478
    cpu.edx = 10417272 /*0x9ef478*/;
L_0x004df4a1:
    // 004df4a1  fec8                   -dec al
    (cpu.al)--;
    // 004df4a3  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004df4a5  7409                   -je 0x4df4b0
    if (cpu.flags.zf)
    {
        goto L_0x004df4b0;
    }
    // 004df4a7  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004df4a8  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx);
    // 004df4aa  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004df4ab  8862ff                 -mov byte ptr [edx - 1], ah
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.ah;
    // 004df4ae  ebf1                   -jmp 0x4df4a1
    goto L_0x004df4a1;
L_0x004df4b0:
    // 004df4b0  b878f39e00             -mov eax, 0x9ef378
    cpu.eax = 10417016 /*0x9ef378*/;
    // 004df4b5  c60200                 -mov byte ptr [edx], 0
    *app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004df4b8  ba34985400             -mov edx, 0x549834
    cpu.edx = 5543988 /*0x549834*/;
    // 004df4bd  e826eb0000             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 004df4c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004df4c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df4c6  7444                   -je 0x4df50c
    if (cpu.flags.zf)
    {
        goto L_0x004df50c;
    }
    // 004df4c8  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
L_0x004df4ca:
    // 004df4ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004df4cc  8b354c435600           -mov esi, dword ptr [0x56434c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5653324) /* 0x56434c */);
    // 004df4d2  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004df4d4  39f0                   +cmp eax, esi
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
    // 004df4d6  7d12                   -jge 0x4df4ea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004df4ea;
    }
    // 004df4d8  6838985400             -push 0x549838
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5543992 /*0x549838*/;
    cpu.esp -= 4;
    // 004df4dd  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df4de  fec3                   -inc bl
    (cpu.bl)++;
    // 004df4e0  e89b560100             -call 0x4f4b80
    cpu.esp -= 4;
    sub_4f4b80(app, cpu);
    if (cpu.terminate) return;
    // 004df4e5  83c408                 +add esp, 8
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
    // 004df4e8  ebe0                   -jmp 0x4df4ca
    goto L_0x004df4ca;
L_0x004df4ea:
    // 004df4ea  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004df4ed  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df4ee  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004df4f1  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df4f2  6878f49e00             -push 0x9ef478
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10417272 /*0x9ef478*/;
    cpu.esp -= 4;
    // 004df4f7  683c985400             -push 0x54983c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5543996 /*0x54983c*/;
    cpu.esp -= 4;
    // 004df4fc  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df4fd  e87e560100             -call 0x4f4b80
    cpu.esp -= 4;
    sub_4f4b80(app, cpu);
    if (cpu.terminate) return;
    // 004df502  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004df505  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004df507  e8f4eb0000             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
L_0x004df50c:
    // 004df50c  8b3d4c435600           -mov edi, dword ptr [0x56434c]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5653324) /* 0x56434c */);
    // 004df512  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004df515  4f                     -dec edi
    (cpu.edi)--;
    // 004df516  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004df51c  893d4c435600           -mov dword ptr [0x56434c], edi
    *app->getMemory<x86::reg32>(x86::reg32(5653324) /* 0x56434c */) = cpu.edi;
L_0x004df522:
    // 004df522  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004df524  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df525  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df526  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df527  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df528  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df529  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df52a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4df530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df530  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df531  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df532  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df533  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df535  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004df537:
    // 004df537  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df538  6848985400             -push 0x549848
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5544008 /*0x549848*/;
    cpu.esp -= 4;
    // 004df53d  6878f39e00             -push 0x9ef378
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10417016 /*0x9ef378*/;
    cpu.esp -= 4;
    // 004df542  e849010000             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004df547  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004df54a  ba54985400             -mov edx, 0x549854
    cpu.edx = 5544020 /*0x549854*/;
    // 004df54f  b878f39e00             -mov eax, 0x9ef378
    cpu.eax = 10417016 /*0x9ef378*/;
    // 004df554  e88fea0000             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 004df559  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df55b  7403                   -je 0x4df560
    if (cpu.flags.zf)
    {
        goto L_0x004df560;
    }
    // 004df55d  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004df55e  ebd7                   -jmp 0x4df537
    goto L_0x004df537;
L_0x004df560:
    // 004df560  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df561  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df562  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df563  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4df570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df570  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df571  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df572  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df573  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df574  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df575  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df576  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df578  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004df57b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004df57d  8955f8                 -mov dword ptr [ebp - 8], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004df580  8955fc                 -mov dword ptr [ebp - 4], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004df583  833d4843560000         +cmp dword ptr [0x564348], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653320) /* 0x564348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df58a  7429                   -je 0x4df5b5
    if (cpu.flags.zf)
    {
        goto L_0x004df5b5;
    }
    // 004df58c  e89fffffff             -call 0x4df530
    cpu.esp -= 4;
    sub_4df530(app, cpu);
    if (cpu.terminate) return;
    // 004df591  ff054c435600           -inc dword ptr [0x56434c]
    (*app->getMemory<x86::reg32>(x86::reg32(5653324) /* 0x56434c */))++;
    // 004df597  0f31                   -rdtsc 
    cpu.rdtsc();
    // 004df599  8995f8ffffff           -mov dword ptr [ebp - 8], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004df59f  8985fcffffff           -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004df5a5  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004df5a8  a3a8f59e00             -mov dword ptr [0x9ef5a8], eax
    *app->getMemory<x86::reg32>(x86::reg32(10417576) /* 0x9ef5a8 */) = cpu.eax;
    // 004df5ad  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004df5b0  a3acf59e00             -mov dword ptr [0x9ef5ac], eax
    *app->getMemory<x86::reg32>(x86::reg32(10417580) /* 0x9ef5ac */) = cpu.eax;
L_0x004df5b5:
    // 004df5b5  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004df5b7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df5b8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df5b9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df5ba  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df5bb  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df5bc  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df5bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4df5c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df5c0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df5c1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df5c2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df5c3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df5c4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df5c5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df5c6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df5c8  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004df5cb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004df5cd  8955f0                 -mov dword ptr [ebp - 0x10], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004df5d0  8955f4                 -mov dword ptr [ebp - 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004df5d3  0f31                   -rdtsc 
    cpu.rdtsc();
    // 004df5d5  8995f0ffffff           -mov dword ptr [ebp - 0x10], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004df5db  8985f4ffffff           -mov dword ptr [ebp - 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004df5e1  833d4843560000         +cmp dword ptr [0x564348], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653320) /* 0x564348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df5e8  746c                   -je 0x4df656
    if (cpu.flags.zf)
    {
        goto L_0x004df656;
    }
    // 004df5ea  a1a8f59e00             -mov eax, dword ptr [0x9ef5a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10417576) /* 0x9ef5a8 */);
    // 004df5ef  8945f8                 -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004df5f2  a1acf59e00             -mov eax, dword ptr [0x9ef5ac]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10417580) /* 0x9ef5ac */);
    // 004df5f7  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004df5fa  8b85f4ffffff           -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004df600  8b95f0ffffff           -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004df606  2b85fcffffff           +sub eax, dword ptr [ebp - 4]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004df60c  1b95f8ffffff           -sbb edx, dword ptr [ebp - 8]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)) + cpu.flags.cf);
    // 004df612  8985fcffffff           -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004df618  8995f8ffffff           -mov dword ptr [ebp - 8], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004df61e  ba34985400             -mov edx, 0x549834
    cpu.edx = 5543988 /*0x549834*/;
    // 004df623  b878f39e00             -mov eax, 0x9ef378
    cpu.eax = 10417016 /*0x9ef378*/;
    // 004df628  e8bbe90000             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 004df62d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004df62f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df631  741d                   -je 0x4df650
    if (cpu.flags.zf)
    {
        goto L_0x004df650;
    }
    // 004df633  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004df636  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df637  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004df63a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df63b  6858985400             -push 0x549858
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5544024 /*0x549858*/;
    cpu.esp -= 4;
    // 004df640  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df641  e83a550100             -call 0x4f4b80
    cpu.esp -= 4;
    sub_4f4b80(app, cpu);
    if (cpu.terminate) return;
    // 004df646  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004df649  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004df64b  e8b0ea0000             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
L_0x004df650:
    // 004df650  ff0d4c435600           -dec dword ptr [0x56434c]
    (*app->getMemory<x86::reg32>(x86::reg32(5653324) /* 0x56434c */))--;
L_0x004df656:
    // 004df656  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004df658  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df659  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df65a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df65b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df65c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df65d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df65e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4df660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df660  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df661  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df662  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004df664  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004df666  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004df669  8908                   -mov dword ptr [eax], ecx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004df66b  881a                   -mov byte ptr [edx], bl
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 004df66d  ff4010                 -inc dword ptr [eax + 0x10]
    (*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */))++;
    // 004df670  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df671  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df672  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4df674(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df674  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df675  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df676  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004df678  b960f64d00             -mov ecx, 0x4df660
    cpu.ecx = 5109344 /*0x4df660*/;
    // 004df67d  e84eeb0100             -call 0x4fe1d0
    cpu.esp -= 4;
    sub_4fe1d0(app, cpu);
    if (cpu.terminate) return;
    // 004df682  c6040600               -mov byte ptr [esi + eax], 0
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
    // 004df686  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df687  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df688  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4df690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df690  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df691  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df692  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004df695  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004df699  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004df69b  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004df69f  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004df6a2  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004df6a6  e8c9ffffff             -call 0x4df674
    cpu.esp -= 4;
    sub_4df674(app, cpu);
    if (cpu.terminate) return;
    // 004df6ab  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004df6ae  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df6af  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df6b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4df6c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df6c0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df6c1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df6c2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004df6c5  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004df6c9  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004df6cb  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004df6cf  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004df6d2  b8726f5600             -mov eax, 0x566f72
    cpu.eax = 5664626 /*0x566f72*/;
    // 004df6d7  e838f90100             -call 0x4ff014
    cpu.esp -= 4;
    sub_4ff014(app, cpu);
    if (cpu.terminate) return;
    // 004df6dc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004df6df  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df6e0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df6e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4df6f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df6f0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df6f1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df6f2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df6f3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004df6f5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004df6f7  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004df6f9  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df6fa  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004df6fc  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df6fd  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df6fe  2eff1530465300         -call dword ptr cs:[0x534630]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457456) /* 0x534630 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df705  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004df707  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df709  7c04                   -jl 0x4df70f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004df70f;
    }
    // 004df70b  39f8                   +cmp eax, edi
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
    // 004df70d  7c0c                   -jl 0x4df71b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004df71b;
    }
L_0x004df70f:
    // 004df70f  81fb02010000           -cmp ebx, 0x102
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(258 /*0x102*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df715  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004df717  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df718  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df719  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df71a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df71b:
    // 004df71b  8b0486                 -mov eax, dword ptr [esi + eax*4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 004df71e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df71f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df720  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df721  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4df730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df730  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004df734  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df736  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004df738  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4df740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df740  833db8f59e0000         +cmp dword ptr [0x9ef5b8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10417592) /* 0x9ef5b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df747  7401                   -je 0x4df74a
    if (cpu.flags.zf)
    {
        goto L_0x004df74a;
    }
    // 004df749  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df74a:
    // 004df74a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df74b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df74c  2eff150c455300         -call dword ptr cs:[0x53450c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457164) /* 0x53450c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df753  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004df755  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004df757  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004df759  68b0f59e00             -push 0x9ef5b0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10417584 /*0x9ef5b0*/;
    cpu.esp -= 4;
    // 004df75e  a3b4f59e00             -mov dword ptr [0x9ef5b4], eax
    *app->getMemory<x86::reg32>(x86::reg32(10417588) /* 0x9ef5b4 */) = cpu.eax;
    // 004df763  2eff1504455300         -call dword ptr cs:[0x534504]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457156) /* 0x534504 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df76a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df76b  2eff1510455300         -call dword ptr cs:[0x534510]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457168) /* 0x534510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df772  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df773  2eff1504455300         -call dword ptr cs:[0x534504]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457156) /* 0x534504 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df77a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df77b  2eff15b4445300         -call dword ptr cs:[0x5344b4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457076) /* 0x5344b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df782  c705b8f59e0001000000   -mov dword ptr [0x9ef5b8], 1
    *app->getMemory<x86::reg32>(x86::reg32(10417592) /* 0x9ef5b8 */) = 1 /*0x1*/;
    // 004df78c  e84fbb0000             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004df791  a380445600             -mov dword ptr [0x564480], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */) = cpu.eax;
    // 004df796  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df797  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df798  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4df7a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df7a0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df7a1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df7a2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df7a3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004df7a6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004df7a8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004df7aa  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004df7ac  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004df7b0  e8bb980100             -call 0x4f9070
    cpu.esp -= 4;
    sub_4f9070(app, cpu);
    if (cpu.terminate) return;
    // 004df7b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df7b7  7570                   -jne 0x4df829
    if (!cpu.flags.zf)
    {
        goto L_0x004df829;
    }
L_0x004df7b9:
    // 004df7b9  833db8f59e0000         +cmp dword ptr [0x9ef5b8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10417592) /* 0x9ef5b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df7c0  7507                   -jne 0x4df7c9
    if (!cpu.flags.zf)
    {
        goto L_0x004df7c9;
    }
    // 004df7c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004df7c4  e877ffffff             -call 0x4df740
    cpu.esp -= 4;
    sub_4df740(app, cpu);
    if (cpu.terminate) return;
L_0x004df7c9:
    // 004df7c9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004df7cb  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df7cc  6a04                   -push 4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004df7ce  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df7cf  6830f74d00             -push 0x4df730
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5109552 /*0x4df730*/;
    cpu.esp -= 4;
    // 004df7d4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df7d5  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004df7d7  2eff15a4445300         -call dword ptr cs:[0x5344a4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457060) /* 0x5344a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df7de  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004df7e0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004df7e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df7e4  7431                   -je 0x4df817
    if (cpu.flags.zf)
    {
        goto L_0x004df817;
    }
    // 004df7e6  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004df7ed  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004df7ef  897b04                 -mov dword ptr [ebx + 4], edi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004df7f2  897308                 -mov dword ptr [ebx + 8], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004df7f5  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004df7f8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004df7fa  894310                 -mov dword ptr [ebx + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004df7fd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004df7ff  e82c020000             -call 0x4dfa30
    cpu.esp -= 4;
    sub_4dfa30(app, cpu);
    if (cpu.terminate) return;
    // 004df804  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df805  2eff15bc455300         -call dword ptr cs:[0x5345bc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457340) /* 0x5345bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df80c  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004df80e  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004df810  2eff1504465300         -call dword ptr cs:[0x534604]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457412) /* 0x534604 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004df817:
    // 004df817  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004df819  7440                   -je 0x4df85b
    if (cpu.flags.zf)
    {
        goto L_0x004df85b;
    }
    // 004df81b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004df820  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004df823  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df824  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df825  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df826  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004df829:
    // 004df829  ba68985400             -mov edx, 0x549868
    cpu.edx = 5544040 /*0x549868*/;
    // 004df82e  b978985400             -mov ecx, 0x549878
    cpu.ecx = 5544056 /*0x549878*/;
    // 004df833  b89f000000             -mov eax, 0x9f
    cpu.eax = 159 /*0x9f*/;
    // 004df838  6888985400             -push 0x549888
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5544072 /*0x549888*/;
    cpu.esp -= 4;
    // 004df83d  891590215500           -mov dword ptr [0x552190], edx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004df843  890d94215500           -mov dword ptr [0x552194], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004df849  a398215500             -mov dword ptr [0x552198], eax
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004df84e  e8bd17f2ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004df853  83c404                 +add esp, 4
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
    // 004df856  e95effffff             -jmp 0x4df7b9
    goto L_0x004df7b9;
L_0x004df85b:
    // 004df85b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004df85d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004df860  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df861  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df862  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df863  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4df870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df870  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df871  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df872  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df873  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df875  741d                   -je 0x4df894
    if (cpu.flags.zf)
    {
        goto L_0x004df894;
    }
    // 004df877  83f8ff                 +cmp eax, -1
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
    // 004df87a  744a                   -je 0x4df8c6
    if (cpu.flags.zf)
    {
        goto L_0x004df8c6;
    }
    // 004df87c  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
L_0x004df87e:
    // 004df87e  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004df880  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df881  2eff1508465300         -call dword ptr cs:[0x534608]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457416) /* 0x534608 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df888  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df889  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df890  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df891  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df892  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df893  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df894:
    // 004df894  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df895  ba68985400             -mov edx, 0x549868
    cpu.edx = 5544040 /*0x549868*/;
    // 004df89a  b9c0985400             -mov ecx, 0x5498c0
    cpu.ecx = 5544128 /*0x5498c0*/;
    // 004df89f  bedc000000             -mov esi, 0xdc
    cpu.esi = 220 /*0xdc*/;
    // 004df8a4  68d0985400             -push 0x5498d0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5544144 /*0x5498d0*/;
    cpu.esp -= 4;
    // 004df8a9  891590215500           -mov dword ptr [0x552190], edx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004df8af  890d94215500           -mov dword ptr [0x552194], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004df8b5  893598215500           -mov dword ptr [0x552198], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004df8bb  e85017f2ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004df8c0  83c404                 +add esp, 4
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
    // 004df8c3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df8c4  ebb8                   -jmp 0x4df87e
    goto L_0x004df87e;
L_0x004df8c6:
    // 004df8c6  2eff1510455300         -call dword ptr cs:[0x534510]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457168) /* 0x534510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df8cd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004df8cf  ebad                   -jmp 0x4df87e
    goto L_0x004df87e;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4df8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df8e0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df8e1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df8e2  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004df8e4  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df8e5  2eff1504465300         -call dword ptr cs:[0x534604]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457412) /* 0x534604 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df8ec  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df8ed  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df8ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4df8f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df8f0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df8f1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df8f2  8b0dd8435600           -mov ecx, dword ptr [0x5643d8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004df8f8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004df8fa  7505                   -jne 0x4df901
    if (!cpu.flags.zf)
    {
        goto L_0x004df901;
    }
    // 004df8fc  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
L_0x004df901:
    // 004df901  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004df903  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004df906  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004df908  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004df90b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004df90d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004df910  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004df912  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004df915  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004df917  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004df919  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004df91c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004df91e  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004df920  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df921  2eff1504465300         -call dword ptr cs:[0x534604]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457412) /* 0x534604 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df928  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df929  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df92a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4df930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df930  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df931  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df932  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df933  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004df935  2eff150c455300         -call dword ptr cs:[0x53450c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457164) /* 0x53450c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df93c  8b0db8f59e00           -mov ecx, dword ptr [0x9ef5b8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10417592) /* 0x9ef5b8 */);
    // 004df942  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004df944  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004df946  7415                   -je 0x4df95d
    if (cpu.flags.zf)
    {
        goto L_0x004df95d;
    }
L_0x004df948:
    // 004df948  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004df94a  7520                   -jne 0x4df96c
    if (!cpu.flags.zf)
    {
        goto L_0x004df96c;
    }
    // 004df94c  3b15b4f59e00           +cmp edx, dword ptr [0x9ef5b4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10417588) /* 0x9ef5b4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df952  7512                   -jne 0x4df966
    if (!cpu.flags.zf)
    {
        goto L_0x004df966;
    }
L_0x004df954:
    // 004df954  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004df959  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df95a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df95b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df95c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df95d:
    // 004df95d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004df95f  e8dcfdffff             -call 0x4df740
    cpu.esp -= 4;
    sub_4df740(app, cpu);
    if (cpu.terminate) return;
    // 004df964  ebe2                   -jmp 0x4df948
    goto L_0x004df948;
L_0x004df966:
    // 004df966  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004df968  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df969  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df96a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df96b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df96c:
    // 004df96c  83fbff                 +cmp ebx, -1
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
    // 004df96f  74e3                   -je 0x4df954
    if (cpu.flags.zf)
    {
        goto L_0x004df954;
    }
    // 004df971  3b5310                 +cmp edx, dword ptr [ebx + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df974  74de                   -je 0x4df954
    if (cpu.flags.zf)
    {
        goto L_0x004df954;
    }
    // 004df976  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004df978  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df979  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df97a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df97b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4df980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df980  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df981  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df982  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004df984  833db8f59e0000         +cmp dword ptr [0x9ef5b8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10417592) /* 0x9ef5b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df98b  742f                   -je 0x4df9bc
    if (cpu.flags.zf)
    {
        goto L_0x004df9bc;
    }
L_0x004df98d:
    // 004df98d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004df98f  7534                   -jne 0x4df9c5
    if (!cpu.flags.zf)
    {
        goto L_0x004df9c5;
    }
    // 004df991  a1b0f59e00             -mov eax, dword ptr [0x9ef5b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10417584) /* 0x9ef5b0 */);
L_0x004df996:
    // 004df996  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df997  2eff1564455300         -call dword ptr cs:[0x534564]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457252) /* 0x534564 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df99e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df9a0  7c35                   -jl 0x4df9d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004df9d7;
    }
    // 004df9a2  0f8e5b000000           -jle 0x4dfa03
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004dfa03;
    }
    // 004df9a8  83f802                 +cmp eax, 2
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
    // 004df9ab  7c4e                   -jl 0x4df9fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004df9fb;
    }
    // 004df9ad  7e44                   -jle 0x4df9f3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004df9f3;
    }
    // 004df9af  83f80f                 +cmp eax, 0xf
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
    // 004df9b2  754f                   -jne 0x4dfa03
    if (!cpu.flags.zf)
    {
        goto L_0x004dfa03;
    }
    // 004df9b4  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004df9b9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df9ba  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df9bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df9bc:
    // 004df9bc  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004df9be  e87dfdffff             -call 0x4df740
    cpu.esp -= 4;
    sub_4df740(app, cpu);
    if (cpu.terminate) return;
    // 004df9c3  ebc8                   -jmp 0x4df98d
    goto L_0x004df98d;
L_0x004df9c5:
    // 004df9c5  83faff                 +cmp edx, -1
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
    // 004df9c8  7404                   -je 0x4df9ce
    if (cpu.flags.zf)
    {
        goto L_0x004df9ce;
    }
    // 004df9ca  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 004df9cc  ebc8                   -jmp 0x4df996
    goto L_0x004df996;
L_0x004df9ce:
    // 004df9ce  2eff1510455300         -call dword ptr cs:[0x534510]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457168) /* 0x534510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df9d5  ebbf                   -jmp 0x4df996
    goto L_0x004df996;
L_0x004df9d7:
    // 004df9d7  83f8fe                 +cmp eax, -2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df9da  7d0d                   -jge 0x4df9e9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004df9e9;
    }
    // 004df9dc  83f8f1                 +cmp eax, -0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-15 /*-0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df9df  7522                   -jne 0x4dfa03
    if (!cpu.flags.zf)
    {
        goto L_0x004dfa03;
    }
    // 004df9e1  b8fdffffff             -mov eax, 0xfffffffd
    cpu.eax = 4294967293 /*0xfffffffd*/;
    // 004df9e6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df9e7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df9e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df9e9:
    // 004df9e9  7f1d                   -jg 0x4dfa08
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004dfa08;
    }
    // 004df9eb  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 004df9f0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df9f1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df9f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df9f3:
    // 004df9f3  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004df9f8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df9f9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df9fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df9fb:
    // 004df9fb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004dfa00  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfa01  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfa02  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004dfa03:
    // 004dfa03  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004dfa05  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfa06  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfa07  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004dfa08:
    // 004dfa08  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004dfa0d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfa0e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfa0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4dfa30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004dfa30  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfa31  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfa32  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004dfa34  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004dfa36  833db8f59e0000         +cmp dword ptr [0x9ef5b8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10417592) /* 0x9ef5b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dfa3d  742a                   -je 0x4dfa69
    if (cpu.flags.zf)
    {
        goto L_0x004dfa69;
    }
L_0x004dfa3f:
    // 004dfa3f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004dfa41  752f                   -jne 0x4dfa72
    if (!cpu.flags.zf)
    {
        goto L_0x004dfa72;
    }
    // 004dfa43  8b0db0f59e00           -mov ecx, dword ptr [0x9ef5b0]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10417584) /* 0x9ef5b0 */);
    // 004dfa49  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004dfa4c  83f806                 +cmp eax, 6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dfa4f  7764                   -ja 0x4dfab5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004dfab5;
    }
    // 004dfa51  ff248510fa4d00         -jmp dword ptr [eax*4 + 0x4dfa10]
    cpu.ip = *app->getMemory<x86::reg32>(5110288 + cpu.eax * 4); goto dynamic_jump;
  case 0x004dfa58:
    // 004dfa58  b8f1ffffff             -mov eax, 0xfffffff1
    cpu.eax = 4294967281 /*0xfffffff1*/;
L_0x004dfa5d:
    // 004dfa5d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfa5e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfa5f  2eff15fc455300         -call dword ptr cs:[0x5345fc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457404) /* 0x5345fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfa66  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfa67  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfa68  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004dfa69:
    // 004dfa69  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004dfa6b  e8d0fcffff             -call 0x4df740
    cpu.esp -= 4;
    sub_4df740(app, cpu);
    if (cpu.terminate) return;
    // 004dfa70  ebcd                   -jmp 0x4dfa3f
    goto L_0x004dfa3f;
L_0x004dfa72:
    // 004dfa72  83f9ff                 +cmp ecx, -1
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
    // 004dfa75  7411                   -je 0x4dfa88
    if (cpu.flags.zf)
    {
        goto L_0x004dfa88;
    }
    // 004dfa77  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 004dfa79  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004dfa7c  83f806                 +cmp eax, 6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dfa7f  7734                   -ja 0x4dfab5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004dfab5;
    }
    // 004dfa81  ff248510fa4d00         -jmp dword ptr [eax*4 + 0x4dfa10]
    cpu.ip = *app->getMemory<x86::reg32>(5110288 + cpu.eax * 4); goto dynamic_jump;
L_0x004dfa88:
    // 004dfa88  2eff1510455300         -call dword ptr cs:[0x534510]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457168) /* 0x534510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfa8f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004dfa91  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004dfa94  83f806                 +cmp eax, 6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dfa97  771c                   -ja 0x4dfab5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004dfab5;
    }
    // 004dfa99  ff248510fa4d00         -jmp dword ptr [eax*4 + 0x4dfa10]
    cpu.ip = *app->getMemory<x86::reg32>(5110288 + cpu.eax * 4); goto dynamic_jump;
  case 0x004dfaa0:
    // 004dfaa0  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 004dfaa5  ebb6                   -jmp 0x4dfa5d
    goto L_0x004dfa5d;
  case 0x004dfaa7:
    // 004dfaa7  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004dfaac  ebaf                   -jmp 0x4dfa5d
    goto L_0x004dfa5d;
  case 0x004dfaae:
    // 004dfaae  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004dfab3  eba8                   -jmp 0x4dfa5d
    goto L_0x004dfa5d;
  case 0x004dfab5:
L_0x004dfab5:
    // 004dfab5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004dfab7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfab8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfab9  2eff15fc455300         -call dword ptr cs:[0x5345fc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457404) /* 0x5345fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfac0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfac1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfac2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004dfac3:
    // 004dfac3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004dfac8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfac9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfaca  2eff15fc455300         -call dword ptr cs:[0x5345fc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457404) /* 0x5345fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfad1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfad2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfad3  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004dfad4:
    // 004dfad4  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 004dfad9  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfada  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfadb  2eff15fc455300         -call dword ptr cs:[0x5345fc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457404) /* 0x5345fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfae2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfae3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfae4  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4dfaf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfaf0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfaf1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfaf2  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004dfaf4  2eff15c4445300         -call dword ptr cs:[0x5344c4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457092) /* 0x5344c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfafb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfafc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfafd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4dfb00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfb00  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfb01  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfb02  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004dfb04  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004dfb06  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004dfb08  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004dfb0a  2eff1594445300         -call dword ptr cs:[0x534494]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457044) /* 0x534494 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfb11  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb12  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb13  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4dfb20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfb20  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dfb22  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004dfb28  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004dfb2e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004dfb30  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfb31  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfb32  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfb33  2eff15e8455300         -call dword ptr cs:[0x5345e8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457384) /* 0x5345e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfb3a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb3b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4dfb30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004dfb30;
    // 004dfb20  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dfb22  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004dfb28  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004dfb2e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x004dfb30:
    // 004dfb30  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfb31  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfb32  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfb33  2eff15e8455300         -call dword ptr cs:[0x5345e8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457384) /* 0x5345e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfb3a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb3b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4dfb40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfb40  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfb41  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfb42  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfb45  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004dfb48  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004dfb4a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004dfb4f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004dfb51  e89afbffff             -call 0x4df6f0
    cpu.esp -= 4;
    sub_4df6f0(app, cpu);
    if (cpu.terminate) return;
    // 004dfb56  3b0424                 +cmp eax, dword ptr [esp]
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
    // 004dfb59  750b                   -jne 0x4dfb66
    if (!cpu.flags.zf)
    {
        goto L_0x004dfb66;
    }
    // 004dfb5b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004dfb60  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfb63  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb64  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb65  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004dfb66:
    // 004dfb66  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004dfb68  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfb6b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb6c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb6d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4dfb70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfb70  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfb71  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfb72  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfb75  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004dfb78  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004dfb7d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004dfb7f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004dfb84  e867fbffff             -call 0x4df6f0
    cpu.esp -= 4;
    sub_4df6f0(app, cpu);
    if (cpu.terminate) return;
    // 004dfb89  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfb8c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb8d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4dfb90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfb90  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfb91  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfb92  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfb95  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004dfb98  8b0dd8435600           -mov ecx, dword ptr [0x5643d8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004dfb9e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004dfba0  7505                   -jne 0x4dfba7
    if (!cpu.flags.zf)
    {
        goto L_0x004dfba7;
    }
    // 004dfba2  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
L_0x004dfba7:
    // 004dfba7  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004dfbae  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004dfbb0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004dfbb3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004dfbb5  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004dfbb8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004dfbba  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004dfbbd  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004dfbbf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dfbc1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004dfbc4  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004dfbc6  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004dfbc8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004dfbca  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004dfbcf  e81cfbffff             -call 0x4df6f0
    cpu.esp -= 4;
    sub_4df6f0(app, cpu);
    if (cpu.terminate) return;
    // 004dfbd4  3b0424                 +cmp eax, dword ptr [esp]
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
    // 004dfbd7  750b                   -jne 0x4dfbe4
    if (!cpu.flags.zf)
    {
        goto L_0x004dfbe4;
    }
    // 004dfbd9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004dfbde  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfbe1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfbe2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfbe3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004dfbe4:
    // 004dfbe4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004dfbe6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfbe9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfbea  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfbeb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4dfbf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfbf0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfbf1  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004dfbf6  e8f5faffff             -call 0x4df6f0
    cpu.esp -= 4;
    sub_4df6f0(app, cpu);
    if (cpu.terminate) return;
    // 004dfbfb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfbfc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4dfc00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfc00  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfc01  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfc02  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfc03  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfc0a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc0b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4dfc10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfc10  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfc11  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfc12  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004dfc14  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004dfc16  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004dfc18  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004dfc1a  2eff1594445300         -call dword ptr cs:[0x534494]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457044) /* 0x534494 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfc21  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc22  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4dfc30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfc30  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfc31  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfc32  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfc33  2eff15e8455300         -call dword ptr cs:[0x5345e8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457384) /* 0x5345e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfc3a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc3b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4dfc40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfc40  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfc41  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfc42  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfc43  2eff15b8455300         -call dword ptr cs:[0x5345b8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457336) /* 0x5345b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfc4a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc4b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4dfc50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfc50  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfc51  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfc52  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfc53  2eff15a4455300         -call dword ptr cs:[0x5345a4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457316) /* 0x5345a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfc5a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc5b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc5c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4dfc60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfc60  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfc61  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfc62  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfc65  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004dfc68  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004dfc6d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004dfc6f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004dfc74  e877faffff             -call 0x4df6f0
    cpu.esp -= 4;
    sub_4df6f0(app, cpu);
    if (cpu.terminate) return;
    // 004dfc79  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfc7c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc7d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4dfc80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfc80  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfc81  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfc82  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfc83  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004dfc85  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfc86  2eff15e8455300         -call dword ptr cs:[0x5345e8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457384) /* 0x5345e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfc8d  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfc8e  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfc95  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc96  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc97  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc98  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4dfca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfca0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004dfca2  750b                   -jne 0x4dfcaf
    if (!cpu.flags.zf)
    {
        goto L_0x004dfcaf;
    }
    // 004dfca4  a1bcf59e00             -mov eax, dword ptr [0x9ef5bc]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10417596) /* 0x9ef5bc */);
    // 004dfca9  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004dfcae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004dfcaf:
    // 004dfcaf  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfcb0  8b15bcf59e00           -mov edx, dword ptr [0x9ef5bc]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10417596) /* 0x9ef5bc */);
    // 004dfcb6  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004dfcbc  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfcbd  6800995400             -push 0x549900
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5544192 /*0x549900*/;
    cpu.esp -= 4;
    // 004dfcc2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfcc3  e8c8f9ffff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004dfcc8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004dfccb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfccc  a1bcf59e00             -mov eax, dword ptr [0x9ef5bc]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10417596) /* 0x9ef5bc */);
    // 004dfcd1  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004dfcd6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4dfce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfce0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfce1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfce2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfce3  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfcea  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfceb  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfcec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4dfcf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfcf0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfcf1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfcf2  2eff1534455300         -call dword ptr cs:[0x534534]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457204) /* 0x534534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfcf9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfcfa  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfcfb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4dfd00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfd00  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4dfd04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfd04  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfd05  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfd06  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004dfd08  ff1584445600           -call dword ptr [0x564484]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5653636) /* 0x564484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfd0e  803d20649f0000         +cmp byte ptr [0x9f6420], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10445856) /* 0x9f6420 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004dfd15  750f                   -jne 0x4dfd26
    if (!cpu.flags.zf)
    {
        goto L_0x004dfd26;
    }
    // 004dfd17  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 004dfd1c  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004dfd21  e846f70100             -call 0x4ff46c
    cpu.esp -= 4;
    sub_4ff46c(app, cpu);
    if (cpu.terminate) return;
L_0x004dfd26:
    // 004dfd26  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004dfd28  e803000000             -call 0x4dfd30
    cpu.esp -= 4;
    sub_4dfd30(app, cpu);
    if (cpu.terminate) return;
    // 004dfd2d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfd2e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfd2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4dfd30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfd30  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfd31  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004dfd33  ff1584445600           -call dword ptr [0x564484]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5653636) /* 0x564484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfd39  ff1588445600           -call dword ptr [0x564488]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5653640) /* 0x564488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfd3f  833df077560000         +cmp dword ptr [0x5677f0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5666800) /* 0x5677f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dfd46  7406                   -je 0x4dfd4e
    if (cpu.flags.zf)
    {
        goto L_0x004dfd4e;
    }
    // 004dfd48  ff15f0775600           -call dword ptr [0x5677f0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666800) /* 0x5677f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004dfd4e:
    // 004dfd4e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dfd50  e937f60100             -jmp 0x4ff38c
    return sub_4ff38c(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_4dfd56(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfd56  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfd57  9b                     -wait 
    /*nothing*/;
    // 004dfd58  d93c24                 -fnstcw word ptr [esp]
    *app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004dfd5b  9b                     -wait 
    /*nothing*/;
    // 004dfd5c  ff3424                 -push dword ptr [esp]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp -= 4;
    // 004dfd5f  c64424011f             -mov byte ptr [esp + 1], 0x1f
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = 31 /*0x1f*/;
    // 004dfd64  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp);
    // 004dfd67  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 004dfd69  d96c2404               -fldcw word ptr [esp + 4]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfd6d  9b                     -wait 
    /*nothing*/;
    // 004dfd6e  8d642408               -lea esp, [esp + 8]
    cpu.esp = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004dfd72  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4dfd80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfd80  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfd81  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfd82  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfd83  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004dfd86  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004dfd88  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfd8c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004dfd8e  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004dfd92  e8d9ab0000             -call 0x4ea970
    cpu.esp -= 4;
    sub_4ea970(app, cpu);
    if (cpu.terminate) return;
    // 004dfd97  c7010000803f           -mov dword ptr [ecx], 0x3f800000
    *app->getMemory<x86::reg32>(cpu.ecx) = 1065353216 /*0x3f800000*/;
    // 004dfd9d  c7410400000000         -mov dword ptr [ecx + 4], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004dfda4  c7410800000000         -mov dword ptr [ecx + 8], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004dfdab  c7410c00000000         -mov dword ptr [ecx + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004dfdb2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfdb6  894110                 -mov dword ptr [ecx + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004dfdb9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004dfdbc  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004dfdc3  894114                 -mov dword ptr [ecx + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004dfdc6  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp)));
    // 004dfdc9  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004dfdcb  d9591c                 -fstp dword ptr [ecx + 0x1c]
    *app->getMemory<float>(cpu.ecx + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dfdce  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfdd2  894120                 -mov dword ptr [ecx + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004dfdd5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004dfdd8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfdd9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfdda  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfddb  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4dfde0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfde0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfde1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfde2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfde3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004dfde6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004dfde8  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfdec  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004dfdee  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004dfdf2  e879ab0000             -call 0x4ea970
    cpu.esp -= 4;
    sub_4ea970(app, cpu);
    if (cpu.terminate) return;
    // 004dfdf7  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfdfb  c7410400000000         -mov dword ptr [ecx + 4], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004dfe02  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004dfe04  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp)));
    // 004dfe07  c7410c00000000         -mov dword ptr [ecx + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004dfe0e  c741100000803f         -mov dword ptr [ecx + 0x10], 0x3f800000
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = 1065353216 /*0x3f800000*/;
    // 004dfe15  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004dfe1c  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004dfe1e  d95908                 -fstp dword ptr [ecx + 8]
    *app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dfe21  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004dfe24  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004dfe2b  894118                 -mov dword ptr [ecx + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004dfe2e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfe32  894120                 -mov dword ptr [ecx + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004dfe35  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004dfe38  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfe39  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfe3a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfe3b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4dfe40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfe40  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfe41  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfe42  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfe43  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004dfe46  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004dfe48  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfe4c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004dfe4e  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004dfe52  e819ab0000             -call 0x4ea970
    cpu.esp -= 4;
    sub_4ea970(app, cpu);
    if (cpu.terminate) return;
    // 004dfe57  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfe5b  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004dfe5d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004dfe60  c7410800000000         -mov dword ptr [ecx + 8], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004dfe67  894104                 -mov dword ptr [ecx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004dfe6a  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp)));
    // 004dfe6d  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004dfe6f  d9590c                 -fstp dword ptr [ecx + 0xc]
    *app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dfe72  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfe76  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004dfe7d  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004dfe84  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004dfe8b  c741200000803f         -mov dword ptr [ecx + 0x20], 0x3f800000
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1065353216 /*0x3f800000*/;
    // 004dfe92  894110                 -mov dword ptr [ecx + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004dfe95  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004dfe98  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfe99  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfe9a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfe9b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4dfea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfea0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfea1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004dfea2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004dfea3  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004dfea6  8b7c2444               -mov edi, dword ptr [esp + 0x44]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004dfeaa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004dfeac  f7442440ffffff7f       +test dword ptr [esp + 0x40], 0x7fffffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) & 2147483647 /*0x7fffffff*/));
    // 004dfeb4  7515                   -jne 0x4dfecb
    if (!cpu.flags.zf)
    {
        goto L_0x004dfecb;
    }
    // 004dfeb6  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 004dfebb  be98445600             -mov esi, 0x564498
    cpu.esi = 5653656 /*0x564498*/;
    // 004dfec0  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004dfec2  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004dfec5  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfec6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfec7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfec8  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004dfecb:
    // 004dfecb  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfecc  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfecd  8d5c2434               -lea ebx, [esp + 0x34]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004dfed1  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004dfed5  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004dfed9  e892aa0000             -call 0x4ea970
    cpu.esp -= 4;
    sub_4ea970(app, cpu);
    if (cpu.terminate) return;
    // 004dfede  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004dfee2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004dfee4  e8d7020000             -call 0x4e01c0
    cpu.esp -= 4;
    sub_4e01c0(app, cpu);
    if (cpu.terminate) return;
    // 004dfee9  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004dfeed  d84c2408               -fmul dword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 004dfef1  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004dfef5  d84c240c               -fmul dword ptr [esp + 0xc]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 004dfef9  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004dfefd  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004dff01  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004dff03  d8642434               -fsub dword ptr [esp + 0x34]
    cpu.fpu.st(0) -= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */));
    // 004dff07  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004dff09  d84c2408               -fmul dword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 004dff0d  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 004dff0f  d84c240c               -fmul dword ptr [esp + 0xc]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 004dff13  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dff15  d954241c               -fst dword ptr [esp + 0x1c]
    *app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    // 004dff19  d84c2408               -fmul dword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 004dff1d  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004dff1f  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004dff23  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004dff25  d8442434               -fadd dword ptr [esp + 0x34]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */));
    // 004dff29  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004dff2d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dff2f  d91f                   -fstp dword ptr [edi]
    *app->getMemory<float>(cpu.edi) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dff31  d84c240c               -fmul dword ptr [esp + 0xc]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 004dff35  d8c3                   -fadd st(3)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(3));
    // 004dff37  d95f04                 -fstp dword ptr [edi + 4]
    *app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dff3a  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004dff3e  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004dff42  d8e4                   -fsub st(4)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(4));
    // 004dff44  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 004dff46  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dff48  d95f08                 -fstp dword ptr [edi + 8]
    *app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dff4b  d84c2408               -fmul dword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 004dff4f  dee3                   -fsubrp st(3)
    cpu.fpu.st(3) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(3));
    cpu.fpu.pop();
    // 004dff51  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004dff53  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004dff55  d95f0c                 -fstp dword ptr [edi + 0xc]
    *app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dff58  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004dff5a  d84c240c               -fmul dword ptr [esp + 0xc]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 004dff5e  d8442434               -fadd dword ptr [esp + 0x34]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */));
    // 004dff62  d95f10                 -fstp dword ptr [edi + 0x10]
    *app->getMemory<float>(cpu.edi + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dff65  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dff67  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004dff6b  d8c3                   -fadd st(3)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(3));
    // 004dff6d  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 004dff6f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dff71  d95f14                 -fstp dword ptr [edi + 0x14]
    *app->getMemory<float>(cpu.edi + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dff74  d84c2408               -fmul dword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 004dff78  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004dff7a  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004dff7c  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004dff7e  d95f18                 -fstp dword ptr [edi + 0x18]
    *app->getMemory<float>(cpu.edi + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dff81  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dff83  d84c240c               -fmul dword ptr [esp + 0xc]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 004dff87  dee2                   -fsubrp st(2)
    cpu.fpu.st(2) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(2));
    cpu.fpu.pop();
    // 004dff89  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dff8b  d95f1c                 -fstp dword ptr [edi + 0x1c]
    *app->getMemory<float>(cpu.edi + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dff8e  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004dff92  d8442434               -fadd dword ptr [esp + 0x34]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */));
    // 004dff96  d95f20                 -fstp dword ptr [edi + 0x20]
    *app->getMemory<float>(cpu.edi + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dff99  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dff9a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dff9b  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004dff9e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dff9f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dffa0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dffa1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4dffb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dffb0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004dffb1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004dffb2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004dffb4  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004dffb6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dffb8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004dffba  7e34                   -jle 0x4dfff0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004dfff0;
    }
L_0x004dffbc:
    // 004dffbc  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004dffbe  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004dffc0  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004dffc2  d802                   -fadd dword ptr [edx]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.edx));
    // 004dffc4  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004dffc7  d84204                 -fadd dword ptr [edx + 4]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004dffca  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004dffcd  d84208                 -fadd dword ptr [edx + 8]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004dffd0  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004dffd2  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004dffd5  d91b                   -fstp dword ptr [ebx]
    *app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dffd7  d95b04                 -fstp dword ptr [ebx + 4]
    *app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dffda  d95b08                 -fstp dword ptr [ebx + 8]
    *app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dffdd  83c10c                 +add ecx, 0xc
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004dffe0  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004dffe1  75d9                   -jne 0x4dffbc
    if (!cpu.flags.zf)
    {
        goto L_0x004dffbc;
    }
    // 004dffe3  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004dffe9  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004dffef  90                     -nop 
    ;
L_0x004dfff0:
    // 004dfff0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfff1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfff2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e0000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0000  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0001  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0002  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e0004  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004e0006  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e0008  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e000a  7e34                   -jle 0x4e0040
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e0040;
    }
L_0x004e000c:
    // 004e000c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004e000e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004e0010  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e0012  d822                   -fsub dword ptr [edx]
    cpu.fpu.st(0) -= x86::Float(*app->getMemory<float>(cpu.edx));
    // 004e0014  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e0017  d86204                 -fsub dword ptr [edx + 4]
    cpu.fpu.st(0) -= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e001a  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e001d  d86208                 -fsub dword ptr [edx + 8]
    cpu.fpu.st(0) -= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e0020  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e0022  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e0025  d91b                   -fstp dword ptr [ebx]
    *app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0027  d95b04                 -fstp dword ptr [ebx + 4]
    *app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e002a  d95b08                 -fstp dword ptr [ebx + 8]
    *app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e002d  83c10c                 +add ecx, 0xc
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0030  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e0031  75d9                   -jne 0x4e000c
    if (!cpu.flags.zf)
    {
        goto L_0x004e000c;
    }
    // 004e0033  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004e0039  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004e003f  90                     -nop 
    ;
L_0x004e0040:
    // 004e0040  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0041  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0042  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e0050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0050  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0051  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e0053  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e0057  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e0059  7e25                   -jle 0x4e0080
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e0080;
    }
    // 004e005b  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
L_0x004e005f:
    // 004e005f  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 004e0061  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004e0063  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0065  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004e0068  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004e006a  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e006d  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004e0070  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004e0072  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0075  83c20c                 +add edx, 0xc
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0078  d958fc                 +fstp dword ptr [eax - 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e007b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e007c  75e1                   -jne 0x4e005f
    if (!cpu.flags.zf)
    {
        goto L_0x004e005f;
    }
    // 004e007e  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004e0080:
    // 004e0080  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0081  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4e0090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0090  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0093  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 004e0095  d820                   -fsub dword ptr [eax]
    cpu.fpu.st(0) -= x86::Float(*app->getMemory<float>(cpu.eax));
    // 004e0097  d91c24                 -fstp dword ptr [esp]
    *app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e009a  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004e009d  d86004                 -fsub dword ptr [eax + 4]
    cpu.fpu.st(0) -= x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 004e00a0  d95c2404               -fstp dword ptr [esp + 4]
    *app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e00a4  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004e00a7  d86008                 -fsub dword ptr [eax + 8]
    cpu.fpu.st(0) -= x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */));
    // 004e00aa  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e00ac  d95c2408               -fstp dword ptr [esp + 8]
    *app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e00b0  e8eb050000             -call 0x4e06a0
    cpu.esp -= 4;
    sub_4e06a0(app, cpu);
    if (cpu.terminate) return;
    // 004e00b5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e00b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e00c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e00c0  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e00c2  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx));
    // 004e00c4  d91b                   -fstp dword ptr [ebx]
    *app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e00c6  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e00c9  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx));
    // 004e00cb  d95b04                 -fstp dword ptr [ebx + 4]
    *app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e00ce  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e00d1  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx));
    // 004e00d3  d95b08                 -fstp dword ptr [ebx + 8]
    *app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e00d6  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004e00d9  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e00dc  d95b0c                 -fstp dword ptr [ebx + 0xc]
    *app->getMemory<float>(cpu.ebx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e00df  d94010                 -fld dword ptr [eax + 0x10]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */)));
    // 004e00e2  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e00e5  d95b10                 -fstp dword ptr [ebx + 0x10]
    *app->getMemory<float>(cpu.ebx + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e00e8  d94014                 -fld dword ptr [eax + 0x14]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */)));
    // 004e00eb  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e00ee  d95b14                 -fstp dword ptr [ebx + 0x14]
    *app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e00f1  d94018                 -fld dword ptr [eax + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */)));
    // 004e00f4  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e00f7  d95b18                 -fstp dword ptr [ebx + 0x18]
    *app->getMemory<float>(cpu.ebx + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e00fa  d9401c                 -fld dword ptr [eax + 0x1c]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 004e00fd  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e0100  d95b1c                 -fstp dword ptr [ebx + 0x1c]
    *app->getMemory<float>(cpu.ebx + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0103  d94020                 -fld dword ptr [eax + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */)));
    // 004e0106  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e0109  d95b20                 -fstp dword ptr [ebx + 0x20]
    *app->getMemory<float>(cpu.ebx + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e010c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e0110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0110  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0111  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e0114  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004e0116  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004e0118  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e011b  894a10                 -mov dword ptr [edx + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004e011e  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004e0121  894a20                 -mov dword ptr [edx + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004e0124  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004e0127  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e012a  d95a04                 -fstp dword ptr [edx + 4]
    *app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e012d  894a0c                 -mov dword ptr [edx + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004e0130  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004e0133  d94018                 -fld dword ptr [eax + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */)));
    // 004e0136  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e0139  d95a08                 -fstp dword ptr [edx + 8]
    *app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e013c  894a18                 -mov dword ptr [edx + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004e013f  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004e0142  d9401c                 -fld dword ptr [eax + 0x1c]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 004e0145  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004e0148  d95a14                 -fstp dword ptr [edx + 0x14]
    *app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e014b  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004e014e  894a1c                 -mov dword ptr [edx + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004e0151  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e0154  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0155  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e0160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0160  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e0163  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e0166  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e0169  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx));
    // 004e016b  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e016d  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e0170  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e0172  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e0175  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e0178  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e017a  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e017d  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e0180  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx));
    // 004e0182  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e0184  deeb                   -fsubp st(3)
    cpu.fpu.st(3) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0186  deeb                   -fsubp st(3)
    cpu.fpu.st(3) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0188  deeb                   -fsubp st(3)
    cpu.fpu.st(3) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e018a  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e018d  d91b                   -fstp dword ptr [ebx]
    *app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e018f  d95b04                 -fstp dword ptr [ebx + 4]
    *app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0192  d95b08                 -fstp dword ptr [ebx + 8]
    *app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0195  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4e01a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e01a0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e01a1  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e01a4  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004e01a6  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004e01a8  e8b3ffffff             -call 0x4e0160
    cpu.esp -= 4;
    sub_4e0160(app, cpu);
    if (cpu.terminate) return;
    // 004e01ad  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e01af  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e01b1  e80a000000             -call 0x4e01c0
    cpu.esp -= 4;
    sub_4e01c0(app, cpu);
    if (cpu.terminate) return;
    // 004e01b6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e01b9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e01ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4e01c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e01c0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e01c1  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e01c4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e01c6  e8d5040000             -call 0x4e06a0
    cpu.esp -= 4;
    sub_4e06a0(app, cpu);
    if (cpu.terminate) return;
    // 004e01cb  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004e01cd  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx)));
    // 004e01cf  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004e01d1  def2                   -fdivrp st(2)
    cpu.fpu.st(2) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(2));
    cpu.fpu.pop();
    // 004e01d3  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004e01d5  d91a                   -fstp dword ptr [edx]
    *app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e01d7  d94104                 -fld dword ptr [ecx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004e01da  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004e01dc  d95a04                 -fstp dword ptr [edx + 4]
    *app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e01df  d84908                 -fmul dword ptr [ecx + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */));
    // 004e01e2  d95a08                 -fstp dword ptr [edx + 8]
    *app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e01e5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e01e8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e01e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4e01f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e01f0  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e01f2  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx));
    // 004e01f4  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e01f7  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e01fa  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e01fd  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e0200  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e0202  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0204  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0206  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4e0210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0210  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0211  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0212  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004e0214  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004e0216  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e0218  7e26                   -jle 0x4e0240
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e0240;
    }
L_0x004e021a:
    // 004e021a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004e021c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e021e  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e0221  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e0223  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx));
    // 004e0225  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e0228  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e022b  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e022e  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e0231  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e0233  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0235  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0237  d959fc                 -fstp dword ptr [ecx - 4]
    *app->getMemory<float>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e023a  83c60c                 +add esi, 0xc
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e023d  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e023e  75da                   -jne 0x4e021a
    if (!cpu.flags.zf)
    {
        goto L_0x004e021a;
    }
L_0x004e0240:
    // 004e0240  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0241  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0242  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e0250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0250  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e0251  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0254  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004e0256  e865ffffff             -call 0x4e01c0
    cpu.esp -= 4;
    sub_4e01c0(app, cpu);
    if (cpu.terminate) return;
    // 004e025b  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004e025f  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e0260  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004e0265  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e0269  ff742418               -push dword ptr [esp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004e026d  e8defdffff             -call 0x4e0050
    cpu.esp -= 4;
    sub_4e0050(app, cpu);
    if (cpu.terminate) return;
    // 004e0272  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0275  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0276  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e0280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0280  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0281  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0282  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0283  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e0284  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004e0287  89442424               -mov dword ptr [esp + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004e028b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004e028d  895c2428               -mov dword ptr [esp + 0x28], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004e0291  39d8                   +cmp eax, ebx
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
    // 004e0293  0f84fd000000           -je 0x4e0396
    if (cpu.flags.zf)
    {
        goto L_0x004e0396;
    }
L_0x004e0299:
    // 004e0299  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004e029d  39fd                   +cmp ebp, edi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e029f  7513                   -jne 0x4e02b4
    if (!cpu.flags.zf)
    {
        goto L_0x004e02b4;
    }
    // 004e02a1  3b7c2424               +cmp edi, dword ptr [esp + 0x24]
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
    // 004e02a5  740b                   -je 0x4e02b2
    if (cpu.flags.zf)
    {
        goto L_0x004e02b2;
    }
    // 004e02a7  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 004e02ac  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004e02ae  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004e02b0  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x004e02b2:
    // 004e02b2  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
L_0x004e02b4:
    // 004e02b4  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e02b7  d84a0c                 -fmul dword ptr [edx + 0xc]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 004e02ba  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e02bc  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx));
    // 004e02be  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e02c0  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e02c3  d84a18                 -fmul dword ptr [edx + 0x18]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 004e02c6  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e02c8  d91b                   -fstp dword ptr [ebx]
    *app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e02ca  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e02cd  d84a10                 -fmul dword ptr [edx + 0x10]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 004e02d0  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e02d2  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e02d5  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e02d7  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e02da  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004e02dd  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e02df  d95b04                 -fstp dword ptr [ebx + 4]
    *app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e02e2  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e02e5  d84a14                 -fmul dword ptr [edx + 0x14]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */));
    // 004e02e8  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e02ea  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e02ed  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e02ef  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e02f2  d84a20                 -fmul dword ptr [edx + 0x20]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 004e02f5  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e02f7  d95b08                 -fstp dword ptr [ebx + 8]
    *app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e02fa  d94010                 -fld dword ptr [eax + 0x10]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */)));
    // 004e02fd  d84a0c                 -fmul dword ptr [edx + 0xc]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 004e0300  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004e0303  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx));
    // 004e0305  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0307  d94014                 -fld dword ptr [eax + 0x14]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */)));
    // 004e030a  d84a18                 -fmul dword ptr [edx + 0x18]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 004e030d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e030f  d95b0c                 -fstp dword ptr [ebx + 0xc]
    *app->getMemory<float>(cpu.ebx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0312  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004e0315  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e0318  d94010                 -fld dword ptr [eax + 0x10]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */)));
    // 004e031b  d84a10                 -fmul dword ptr [edx + 0x10]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 004e031e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0320  d94014                 -fld dword ptr [eax + 0x14]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */)));
    // 004e0323  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004e0326  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0328  d95b10                 -fstp dword ptr [ebx + 0x10]
    *app->getMemory<float>(cpu.ebx + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e032b  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004e032e  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e0331  d94010                 -fld dword ptr [eax + 0x10]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */)));
    // 004e0334  d84a14                 -fmul dword ptr [edx + 0x14]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */));
    // 004e0337  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0339  d94014                 -fld dword ptr [eax + 0x14]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */)));
    // 004e033c  d84a20                 -fmul dword ptr [edx + 0x20]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 004e033f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0341  d95b14                 -fstp dword ptr [ebx + 0x14]
    *app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0344  d9401c                 -fld dword ptr [eax + 0x1c]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 004e0347  d84a0c                 -fmul dword ptr [edx + 0xc]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 004e034a  d94018                 -fld dword ptr [eax + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */)));
    // 004e034d  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx));
    // 004e034f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0351  d94020                 -fld dword ptr [eax + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */)));
    // 004e0354  d84a18                 -fmul dword ptr [edx + 0x18]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 004e0357  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0359  d95b18                 -fstp dword ptr [ebx + 0x18]
    *app->getMemory<float>(cpu.ebx + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e035c  d94018                 -fld dword ptr [eax + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */)));
    // 004e035f  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e0362  d9401c                 -fld dword ptr [eax + 0x1c]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 004e0365  d84a10                 -fmul dword ptr [edx + 0x10]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 004e0368  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e036a  d94020                 -fld dword ptr [eax + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */)));
    // 004e036d  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004e0370  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0372  d95b1c                 -fstp dword ptr [ebx + 0x1c]
    *app->getMemory<float>(cpu.ebx + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0375  d94018                 -fld dword ptr [eax + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */)));
    // 004e0378  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e037b  d9401c                 -fld dword ptr [eax + 0x1c]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 004e037e  d84a14                 -fmul dword ptr [edx + 0x14]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */));
    // 004e0381  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0383  d94020                 -fld dword ptr [eax + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */)));
    // 004e0386  d84a20                 -fmul dword ptr [edx + 0x20]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 004e0389  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e038b  d95b20                 -fstp dword ptr [ebx + 0x20]
    *app->getMemory<float>(cpu.ebx + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e038e  83c42c                 +add esp, 0x2c
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
    // 004e0391  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0392  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0393  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0394  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0395  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0396:
    // 004e0396  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 004e039b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004e039d  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004e03a1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e03a3  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004e03a5  e9effeffff             -jmp 0x4e0299
    goto L_0x004e0299;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4e03b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e03b0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e03b1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e03b2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e03b4  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004e03b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e03b8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e03ba  7e64                   -jle 0x4e0420
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e0420;
    }
L_0x004e03bc:
    // 004e03bc  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004e03be  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004e03c0  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e03c2  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx));
    // 004e03c4  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e03c6  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e03c9  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e03cb  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e03ce  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e03d0  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e03d3  d84a0c                 -fmul dword ptr [edx + 0xc]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 004e03d6  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e03d9  d84a10                 -fmul dword ptr [edx + 0x10]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 004e03dc  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e03df  d84a14                 -fmul dword ptr [edx + 0x14]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */));
    // 004e03e2  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e03e4  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e03e6  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e03e8  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e03ea  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e03ed  d84a18                 -fmul dword ptr [edx + 0x18]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 004e03f0  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e03f3  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004e03f6  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e03f9  d84a20                 -fmul dword ptr [edx + 0x20]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 004e03fc  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e03fe  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0400  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0402  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0404  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e0407  d91b                   -fstp dword ptr [ebx]
    *app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0409  d95b04                 -fstp dword ptr [ebx + 4]
    *app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e040c  d95b08                 -fstp dword ptr [ebx + 8]
    *app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e040f  83c10c                 +add ecx, 0xc
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0412  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e0413  75a7                   -jne 0x4e03bc
    if (!cpu.flags.zf)
    {
        goto L_0x004e03bc;
    }
    // 004e0415  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004e041b  8d5200                 -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004e041e  8bdb                   -mov ebx, ebx
    cpu.ebx = cpu.ebx;
L_0x004e0420:
    // 004e0420  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0421  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0422  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e0430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0430  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0431  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0432  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e0433  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e0436  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e0438  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004e043a  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004e043c  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004e043f  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004e0443  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e0445  0f8e85000000           -jle 0x4e04d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e04d0;
    }
L_0x004e044b:
    // 004e044b  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004e044d  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004e044f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e0451  d900                   +fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e0453  d80a                   +fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx));
    // 004e0455  d900                   +fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e0457  d84a04                 +fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e045a  d900                   +fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e045c  d84a08                 +fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e045f  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e0461  d94004                 +fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e0464  d84a0c                 +fmul dword ptr [edx + 0xc]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 004e0467  d94004                 +fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e046a  d84a10                 +fmul dword ptr [edx + 0x10]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 004e046d  d94004                 +fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e0470  d84a14                 +fmul dword ptr [edx + 0x14]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */));
    // 004e0473  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e0475  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0477  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0479  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e047b  d94008                 +fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e047e  d84a18                 +fmul dword ptr [edx + 0x18]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 004e0481  d94008                 +fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e0484  d84a1c                 +fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004e0487  d94008                 +fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e048a  d84a20                 +fmul dword ptr [edx + 0x20]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 004e048d  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e048f  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0491  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0493  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0495  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e0498  d91b                   +fstp dword ptr [ebx]
    *app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e049a  d95b04                 +fstp dword ptr [ebx + 4]
    *app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e049d  d95b08                 +fstp dword ptr [ebx + 8]
    *app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e04a0  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 004e04a3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004e04a5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004e04a7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e04a9  d900                   +fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e04ab  d802                   +fadd dword ptr [edx]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.edx));
    // 004e04ad  d94004                 +fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e04b0  d84204                 +fadd dword ptr [edx + 4]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e04b3  d94008                 +fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e04b6  d84208                 +fadd dword ptr [edx + 8]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e04b9  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e04bb  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e04be  d91b                   +fstp dword ptr [ebx]
    *app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e04c0  d95b04                 +fstp dword ptr [ebx + 4]
    *app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e04c3  d95b08                 +fstp dword ptr [ebx + 8]
    *app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e04c6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e04c8  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e04c9  7580                   -jne 0x4e044b
    if (!cpu.flags.zf)
    {
        goto L_0x004e044b;
    }
    // 004e04cb  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004e04ce  8bc9                   -mov ecx, ecx
    cpu.ecx = cpu.ecx;
L_0x004e04d0:
    // 004e04d0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e04d3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e04d4  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e04d5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e04d6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e04e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e04e0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e04e1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e04e2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e04e3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e04e6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e04e8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004e04ea  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004e04ed  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004e04ef  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004e04f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e04f5  0f8ea5000000           -jle 0x4e05a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e05a0;
    }
    // 004e04fb  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004e04ff  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004e0506  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e0508  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004e050b  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004e050f:
    // 004e050f  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 004e0512  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004e0514  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e0516  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e0518  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx));
    // 004e051a  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e051c  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e051f  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e0521  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e0524  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e0526  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e0529  d84a0c                 -fmul dword ptr [edx + 0xc]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 004e052c  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e052f  d84a10                 -fmul dword ptr [edx + 0x10]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 004e0532  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e0535  d84a14                 -fmul dword ptr [edx + 0x14]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */));
    // 004e0538  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e053a  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e053c  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e053e  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0540  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e0543  d84a18                 -fmul dword ptr [edx + 0x18]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 004e0546  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e0549  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004e054c  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e054f  d84a20                 -fmul dword ptr [edx + 0x20]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 004e0552  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e0554  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0556  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0558  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e055a  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e055d  d91b                   -fstp dword ptr [ebx]
    *app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e055f  d95b04                 -fstp dword ptr [ebx + 4]
    *app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0562  d95b08                 -fstp dword ptr [ebx + 8]
    *app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0565  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004e0567  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004e0569  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004e056b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e056d  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e056f  d802                   -fadd dword ptr [edx]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.edx));
    // 004e0571  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e0574  d84204                 -fadd dword ptr [edx + 4]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e0577  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e057a  d84208                 -fadd dword ptr [edx + 8]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e057d  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e057f  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e0582  d91b                   -fstp dword ptr [ebx]
    *app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0584  d95b04                 -fstp dword ptr [ebx + 4]
    *app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0587  d95b08                 -fstp dword ptr [ebx + 8]
    *app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e058a  034c2404               +add ecx, dword ptr [esp + 4]
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e058e  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e058f  0f857affffff           -jne 0x4e050f
    if (!cpu.flags.zf)
    {
        goto L_0x004e050f;
    }
    // 004e0595  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004e059b  8d5200                 -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004e059e  8bdb                   -mov ebx, ebx
    cpu.ebx = cpu.ebx;
L_0x004e05a0:
    // 004e05a0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e05a3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e05a4  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e05a5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e05a6  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e05b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e05b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e05b1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e05b2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e05b3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e05b5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e05b7  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004e05bc  e82f9f0000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e05c1  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004e05c6  8d5110                 -lea edx, [ecx + 0x10]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e05c9  8d460c                 -lea eax, [esi + 0xc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004e05cc  e81f9f0000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e05d1  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004e05d6  8d5120                 -lea edx, [ecx + 0x20]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004e05d9  8d4618                 -lea eax, [esi + 0x18]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004e05dc  e80f9f0000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e05e1  c7413800000000         -mov dword ptr [ecx + 0x38], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
    // 004e05e8  c7413c0000803f         -mov dword ptr [ecx + 0x3c], 0x3f800000
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */) = 1065353216 /*0x3f800000*/;
    // 004e05ef  8b4138                 -mov eax, dword ptr [ecx + 0x38]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 004e05f2  894134                 -mov dword ptr [ecx + 0x34], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004e05f5  8b4134                 -mov eax, dword ptr [ecx + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 004e05f8  894130                 -mov dword ptr [ecx + 0x30], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004e05fb  8b4130                 -mov eax, dword ptr [ecx + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 004e05fe  89412c                 -mov dword ptr [ecx + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004e0601  8b412c                 -mov eax, dword ptr [ecx + 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 004e0604  89411c                 -mov dword ptr [ecx + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004e0607  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004e060a  89410c                 -mov dword ptr [ecx + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004e060d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e060e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e060f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0610  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4e0620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0620  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0621  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e0623  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004e0625  e886ffffff             -call 0x4e05b0
    cpu.esp -= 4;
    sub_4e05b0(app, cpu);
    if (cpu.terminate) return;
    // 004e062a  8d5330                 -lea edx, [ebx + 0x30]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 004e062d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e062f  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004e0634  e8b79e0000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e0639  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e063a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e0640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0640  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0641  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004e0643  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e0644  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 004e0646  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004e0649  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 004e064b  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004e064e  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 004e0650  e86bee0100             -call 0x4ff4c0
    cpu.esp -= 4;
    sub_4ff4c0(app, cpu);
    if (cpu.terminate) return;
    // 004e0655  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0656  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0657  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e0658(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0658  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e0659(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0659  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e0660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0660  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0661  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004e0664  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e0666  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e066a  e851fbffff             -call 0x4e01c0
    cpu.esp -= 4;
    sub_4e01c0(app, cpu);
    if (cpu.terminate) return;
    // 004e066f  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004e0671  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e0673  e848fbffff             -call 0x4e01c0
    cpu.esp -= 4;
    sub_4e01c0(app, cpu);
    if (cpu.terminate) return;
    // 004e0678  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004e067a  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e067e  e86dfbffff             -call 0x4e01f0
    cpu.esp -= 4;
    sub_4e01f0(app, cpu);
    if (cpu.terminate) return;
    // 004e0683  e8fa8d0100             -call 0x4f9482
    cpu.esp -= 4;
    sub_4f9482(app, cpu);
    if (cpu.terminate) return;
    // 004e0688  dc0d20995400           -fmul qword ptr [0x549920]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<double>(x86::reg32(5544224) /* 0x549920 */));
    // 004e068e  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004e0691  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0692  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e06a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e06a0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e06a3  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax)));
    // 004e06a5  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 004e06a7  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e06aa  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 004e06ac  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e06af  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004e06b1  d8c2                   -fadd st(2)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(2));
    // 004e06b3  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004e06b5  d84808                 -fmul dword ptr [eax + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */));
    // 004e06b8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004e06ba  ddda                   -fstp st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e06bc  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e06be  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
    // 004e06c0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e06c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e06c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e06c4  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004e06c6  f6055878560001         +test byte ptr [0x567858], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(x86::reg32(5666904) /* 0x567858 */) & 1 /*0x1*/));
    // 004e06cd  7504                   -jne 0x4e06d3
    if (!cpu.flags.zf)
    {
        goto L_0x004e06d3;
    }
    // 004e06cf  d9f3                   +fpatan 
    cpu.fpu.st(1) = cpu.fpu.atan(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004e06d1  eb05                   -jmp 0x4e06d8
    goto L_0x004e06d8;
L_0x004e06d3:
    // 004e06d3  e84cef0100             -call 0x4ff624
    cpu.esp -= 4;
    sub_4ff624(app, cpu);
    if (cpu.terminate) return;
L_0x004e06d8:
    // 004e06d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e06d9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e06d9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004e06db  f6055878560001         +test byte ptr [0x567858], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(x86::reg32(5666904) /* 0x567858 */) & 1 /*0x1*/));
    // 004e06e2  7504                   -jne 0x4e06e8
    if (!cpu.flags.zf)
    {
        goto L_0x004e06e8;
    }
    // 004e06e4  d9f3                   +fpatan 
    cpu.fpu.st(1) = cpu.fpu.atan(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004e06e6  eb05                   -jmp 0x4e06ed
    goto L_0x004e06ed;
L_0x004e06e8:
    // 004e06e8  e837ef0100             -call 0x4ff624
    cpu.esp -= 4;
    sub_4ff624(app, cpu);
    if (cpu.terminate) return;
L_0x004e06ed:
    // 004e06ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e06ee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e06ee  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004e06f2  e8cdffffff             -call 0x4e06c4
    cpu.esp -= 4;
    sub_4e06c4(app, cpu);
    if (cpu.terminate) return;
    // 004e06f7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4e06fa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e06fa  dd44240c               -fld qword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004e06fe  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004e0702  e8d2ffffff             -call 0x4e06d9
    cpu.esp -= 4;
    sub_4e06d9(app, cpu);
    if (cpu.terminate) return;
    // 004e0707  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4e070c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e070c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e070d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e070f  e80d000000             -call 0x4e0721
    cpu.esp -= 4;
    sub_4e0721(app, cpu);
    if (cpu.terminate) return;
    // 004e0714  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0715  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e0716(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0716  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 004e0718  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e0719  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e071b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004e071e  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004e0720  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0721  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 004e0726  0f85a7000000           -jne 0x4e07d3
    if (!cpu.flags.zf)
    {
        goto L_0x004e07d3;
    }
L_0x004e072c:
    // 004e072c  83fa00                 +cmp edx, 0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e072f  7c3f                   -jl 0x4e0770
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0770;
    }
    // 004e0731  80fbff                 +cmp bl, 0xff
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
    // 004e0734  743b                   -je 0x4e0771
    if (cpu.flags.zf)
    {
        goto L_0x004e0771;
    }
    // 004e0736  38fb                   +cmp bl, bh
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
    // 004e0738  7537                   -jne 0x4e0771
    if (!cpu.flags.zf)
    {
        goto L_0x004e0771;
    }
    // 004e073a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e073b  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e073c  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp)));
    // 004e073f  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0742  7813                   -js 0x4e0757
    if (cpu.flags.sf)
    {
        goto L_0x004e0757;
    }
L_0x004e0744:
    // 004e0744  dd10                   -fst qword ptr [eax]
    *app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 004e0746  dd5008                 -fst qword ptr [eax + 8]
    *app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    // 004e0749  dd5010                 -fst qword ptr [eax + 0x10]
    *app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    // 004e074c  dd5018                 -fst qword ptr [eax + 0x18]
    *app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    // 004e074f  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004e0752  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0755  79ed                   -jns 0x4e0744
    if (!cpu.flags.sf)
    {
        goto L_0x004e0744;
    }
L_0x004e0757:
    // 004e0757  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e075a  780a                   -js 0x4e0766
    if (cpu.flags.sf)
    {
        goto L_0x004e0766;
    }
L_0x004e075c:
    // 004e075c  dd10                   -fst qword ptr [eax]
    *app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 004e075e  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e0761  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0764  79f6                   -jns 0x4e075c
    if (!cpu.flags.sf)
    {
        goto L_0x004e075c;
    }
L_0x004e0766:
    // 004e0766  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0768  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e076b  83c208                 +add edx, 8
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
    // 004e076e  753d                   -jne 0x4e07ad
    if (!cpu.flags.zf)
    {
        goto L_0x004e07ad;
    }
L_0x004e0770:
    // 004e0770  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0771:
    // 004e0771  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0774  781f                   -js 0x4e0795
    if (cpu.flags.sf)
    {
        goto L_0x004e0795;
    }
L_0x004e0776:
    // 004e0776  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e0778  895804                 -mov dword ptr [eax + 4], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004e077b  895808                 -mov dword ptr [eax + 8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004e077e  89580c                 -mov dword ptr [eax + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004e0781  895810                 -mov dword ptr [eax + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004e0784  895814                 -mov dword ptr [eax + 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004e0787  895818                 -mov dword ptr [eax + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004e078a  89581c                 -mov dword ptr [eax + 0x1c], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004e078d  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004e0790  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0793  79e1                   -jns 0x4e0776
    if (!cpu.flags.sf)
    {
        goto L_0x004e0776;
    }
L_0x004e0795:
    // 004e0795  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0798  780d                   -js 0x4e07a7
    if (cpu.flags.sf)
    {
        goto L_0x004e07a7;
    }
L_0x004e079a:
    // 004e079a  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e079c  895804                 -mov dword ptr [eax + 4], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004e079f  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e07a2  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e07a5  79f3                   -jns 0x4e079a
    if (!cpu.flags.sf)
    {
        goto L_0x004e079a;
    }
L_0x004e07a7:
    // 004e07a7  83c208                 +add edx, 8
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
    // 004e07aa  7501                   -jne 0x4e07ad
    if (!cpu.flags.zf)
    {
        goto L_0x004e07ad;
    }
    // 004e07ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e07ad:
    // 004e07ad  f7c204000000           +test edx, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4 /*0x4*/));
    // 004e07b3  7405                   -je 0x4e07ba
    if (cpu.flags.zf)
    {
        goto L_0x004e07ba;
    }
    // 004e07b5  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e07b7  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x004e07ba:
    // 004e07ba  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 004e07c0  7406                   -je 0x4e07c8
    if (cpu.flags.zf)
    {
        goto L_0x004e07c8;
    }
    // 004e07c2  668918                 -mov word ptr [eax], bx
    *app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 004e07c5  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
L_0x004e07c8:
    // 004e07c8  f7c201000000           +test edx, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1 /*0x1*/));
    // 004e07ce  7402                   -je 0x4e07d2
    if (cpu.flags.zf)
    {
        goto L_0x004e07d2;
    }
    // 004e07d0  8818                   -mov byte ptr [eax], bl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x004e07d2:
    // 004e07d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e07d3:
    // 004e07d3  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 004e07d8  740d                   -je 0x4e07e7
    if (cpu.flags.zf)
    {
        goto L_0x004e07e7;
    }
    // 004e07da  83fa01                 +cmp edx, 1
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
    // 004e07dd  7c08                   -jl 0x4e07e7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e07e7;
    }
    // 004e07df  8818                   -mov byte ptr [eax], bl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004e07e1  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004e07e4  83ea01                 -sub edx, 1
    (cpu.edx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004e07e7:
    // 004e07e7  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004e07ec  740e                   -je 0x4e07fc
    if (cpu.flags.zf)
    {
        goto L_0x004e07fc;
    }
    // 004e07ee  83fa02                 +cmp edx, 2
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
    // 004e07f1  7c09                   -jl 0x4e07fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e07fc;
    }
    // 004e07f3  668918                 -mov word ptr [eax], bx
    *app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 004e07f6  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004e07f9  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004e07fc:
    // 004e07fc  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 004e0801  740d                   -je 0x4e0810
    if (cpu.flags.zf)
    {
        goto L_0x004e0810;
    }
    // 004e0803  83fa04                 +cmp edx, 4
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
    // 004e0806  7c08                   -jl 0x4e0810
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0810;
    }
    // 004e0808  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e080a  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e080d  83ea04                 +sub edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004e0810:
    // 004e0810  e917ffffff             -jmp 0x4e072c
    goto L_0x004e072c;
}

/* align: skip  */
void Application::sub_4e0721(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004e0721;
    // 004e0716  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 004e0718  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e0719  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e071b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004e071e  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004e0720  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x004e0721:
    // 004e0721  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 004e0726  0f85a7000000           -jne 0x4e07d3
    if (!cpu.flags.zf)
    {
        goto L_0x004e07d3;
    }
L_0x004e072c:
    // 004e072c  83fa00                 +cmp edx, 0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e072f  7c3f                   -jl 0x4e0770
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0770;
    }
    // 004e0731  80fbff                 +cmp bl, 0xff
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
    // 004e0734  743b                   -je 0x4e0771
    if (cpu.flags.zf)
    {
        goto L_0x004e0771;
    }
    // 004e0736  38fb                   +cmp bl, bh
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
    // 004e0738  7537                   -jne 0x4e0771
    if (!cpu.flags.zf)
    {
        goto L_0x004e0771;
    }
    // 004e073a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e073b  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e073c  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp)));
    // 004e073f  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0742  7813                   -js 0x4e0757
    if (cpu.flags.sf)
    {
        goto L_0x004e0757;
    }
L_0x004e0744:
    // 004e0744  dd10                   -fst qword ptr [eax]
    *app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 004e0746  dd5008                 -fst qword ptr [eax + 8]
    *app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    // 004e0749  dd5010                 -fst qword ptr [eax + 0x10]
    *app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    // 004e074c  dd5018                 -fst qword ptr [eax + 0x18]
    *app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    // 004e074f  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004e0752  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0755  79ed                   -jns 0x4e0744
    if (!cpu.flags.sf)
    {
        goto L_0x004e0744;
    }
L_0x004e0757:
    // 004e0757  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e075a  780a                   -js 0x4e0766
    if (cpu.flags.sf)
    {
        goto L_0x004e0766;
    }
L_0x004e075c:
    // 004e075c  dd10                   -fst qword ptr [eax]
    *app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 004e075e  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e0761  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0764  79f6                   -jns 0x4e075c
    if (!cpu.flags.sf)
    {
        goto L_0x004e075c;
    }
L_0x004e0766:
    // 004e0766  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0768  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e076b  83c208                 +add edx, 8
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
    // 004e076e  753d                   -jne 0x4e07ad
    if (!cpu.flags.zf)
    {
        goto L_0x004e07ad;
    }
L_0x004e0770:
    // 004e0770  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0771:
    // 004e0771  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0774  781f                   -js 0x4e0795
    if (cpu.flags.sf)
    {
        goto L_0x004e0795;
    }
L_0x004e0776:
    // 004e0776  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e0778  895804                 -mov dword ptr [eax + 4], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004e077b  895808                 -mov dword ptr [eax + 8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004e077e  89580c                 -mov dword ptr [eax + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004e0781  895810                 -mov dword ptr [eax + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004e0784  895814                 -mov dword ptr [eax + 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004e0787  895818                 -mov dword ptr [eax + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004e078a  89581c                 -mov dword ptr [eax + 0x1c], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004e078d  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004e0790  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0793  79e1                   -jns 0x4e0776
    if (!cpu.flags.sf)
    {
        goto L_0x004e0776;
    }
L_0x004e0795:
    // 004e0795  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0798  780d                   -js 0x4e07a7
    if (cpu.flags.sf)
    {
        goto L_0x004e07a7;
    }
L_0x004e079a:
    // 004e079a  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e079c  895804                 -mov dword ptr [eax + 4], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004e079f  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e07a2  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e07a5  79f3                   -jns 0x4e079a
    if (!cpu.flags.sf)
    {
        goto L_0x004e079a;
    }
L_0x004e07a7:
    // 004e07a7  83c208                 +add edx, 8
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
    // 004e07aa  7501                   -jne 0x4e07ad
    if (!cpu.flags.zf)
    {
        goto L_0x004e07ad;
    }
    // 004e07ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e07ad:
    // 004e07ad  f7c204000000           +test edx, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4 /*0x4*/));
    // 004e07b3  7405                   -je 0x4e07ba
    if (cpu.flags.zf)
    {
        goto L_0x004e07ba;
    }
    // 004e07b5  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e07b7  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x004e07ba:
    // 004e07ba  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 004e07c0  7406                   -je 0x4e07c8
    if (cpu.flags.zf)
    {
        goto L_0x004e07c8;
    }
    // 004e07c2  668918                 -mov word ptr [eax], bx
    *app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 004e07c5  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
L_0x004e07c8:
    // 004e07c8  f7c201000000           +test edx, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1 /*0x1*/));
    // 004e07ce  7402                   -je 0x4e07d2
    if (cpu.flags.zf)
    {
        goto L_0x004e07d2;
    }
    // 004e07d0  8818                   -mov byte ptr [eax], bl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x004e07d2:
    // 004e07d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e07d3:
    // 004e07d3  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 004e07d8  740d                   -je 0x4e07e7
    if (cpu.flags.zf)
    {
        goto L_0x004e07e7;
    }
    // 004e07da  83fa01                 +cmp edx, 1
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
    // 004e07dd  7c08                   -jl 0x4e07e7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e07e7;
    }
    // 004e07df  8818                   -mov byte ptr [eax], bl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004e07e1  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004e07e4  83ea01                 -sub edx, 1
    (cpu.edx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004e07e7:
    // 004e07e7  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004e07ec  740e                   -je 0x4e07fc
    if (cpu.flags.zf)
    {
        goto L_0x004e07fc;
    }
    // 004e07ee  83fa02                 +cmp edx, 2
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
    // 004e07f1  7c09                   -jl 0x4e07fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e07fc;
    }
    // 004e07f3  668918                 -mov word ptr [eax], bx
    *app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 004e07f6  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004e07f9  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004e07fc:
    // 004e07fc  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 004e0801  740d                   -je 0x4e0810
    if (cpu.flags.zf)
    {
        goto L_0x004e0810;
    }
    // 004e0803  83fa04                 +cmp edx, 4
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
    // 004e0806  7c08                   -jl 0x4e0810
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0810;
    }
    // 004e0808  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e080a  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e080d  83ea04                 +sub edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004e0810:
    // 004e0810  e917ffffff             -jmp 0x4e072c
    goto L_0x004e072c;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e0820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0820  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0821  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0822  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0823  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0824  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e0825  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e0828  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e082a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004e082c  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e082f  7507                   -jne 0x4e0838
    if (!cpu.flags.zf)
    {
        goto L_0x004e0838;
    }
    // 004e0831  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0833  e9ad000000             -jmp 0x4e08e5
    goto L_0x004e08e5;
L_0x004e0838:
    // 004e0838  807a0100               +cmp byte ptr [edx + 1], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e083c  7525                   -jne 0x4e0863
    if (!cpu.flags.zf)
    {
        goto L_0x004e0863;
    }
    // 004e083e  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebx);
L_0x004e0840:
    // 004e0840  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 004e0842  3ac2                   +cmp al, dl
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
    // 004e0844  7412                   -je 0x4e0858
    if (cpu.flags.zf)
    {
        goto L_0x004e0858;
    }
    // 004e0846  3c00                   +cmp al, 0
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
    // 004e0848  740c                   -je 0x4e0856
    if (cpu.flags.zf)
    {
        goto L_0x004e0856;
    }
    // 004e084a  46                     -inc esi
    (cpu.esi)++;
    // 004e084b  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 004e084d  3ac2                   +cmp al, dl
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
    // 004e084f  7407                   -je 0x4e0858
    if (cpu.flags.zf)
    {
        goto L_0x004e0858;
    }
    // 004e0851  46                     -inc esi
    (cpu.esi)++;
    // 004e0852  3c00                   +cmp al, 0
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
    // 004e0854  75ea                   -jne 0x4e0840
    if (!cpu.flags.zf)
    {
        goto L_0x004e0840;
    }
L_0x004e0856:
    // 004e0856  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004e0858:
    // 004e0858  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e085a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e085d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e085e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e085f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0860  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0861  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0862  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0863:
    // 004e0863  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004e0868  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004e086a  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004e086c  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004e086d  e30b                   -jecxz 0x4e087a
    if (cpu.ecx == 0)
    {
        goto L_0x004e087a;
    }
    // 004e086f  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004e0871  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004e0873  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 004e0875  7503                   -jne 0x4e087a
    if (!cpu.flags.zf)
    {
        goto L_0x004e087a;
    }
    // 004e0877  4f                     -dec edi
    (cpu.edi)--;
    // 004e0878  66a989cf               +test ax, 0xcf89
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 53129 /*0xcf89*/));
    // FakeJmpInstruction
    goto L_0x004e087c;
L_0x004e087a:
    // 004e087a  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x004e087c:
    // 004e087c  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004e087d  893c24                 -mov dword ptr [esp], edi
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004e0880  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004e0882  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004e0883  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004e0885  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004e0887  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e0889  49                     -dec ecx
    (cpu.ecx)--;
    // 004e088a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e088c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004e088e  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004e0890  49                     -dec ecx
    (cpu.ecx)--;
    // 004e0891  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004e0892  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
L_0x004e0894:
    // 004e0894  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 004e0897  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004e0899  39e9                   +cmp ecx, ebp
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
    // 004e089b  7246                   -jb 0x4e08e3
    if (cpu.flags.cf)
    {
        goto L_0x004e08e3;
    }
    // 004e089d  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004e089f  8a03                   -mov al, byte ptr [ebx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx);
    // 004e08a1  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004e08a2  e30b                   -jecxz 0x4e08af
    if (cpu.ecx == 0)
    {
        goto L_0x004e08af;
    }
    // 004e08a4  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004e08a6  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004e08a8  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 004e08aa  7503                   -jne 0x4e08af
    if (!cpu.flags.zf)
    {
        goto L_0x004e08af;
    }
    // 004e08ac  4f                     -dec edi
    (cpu.edi)--;
    // 004e08ad  66a989cf               +test ax, 0xcf89
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 53129 /*0xcf89*/));
    // FakeJmpInstruction
    goto L_0x004e08b1;
L_0x004e08af:
    // 004e08af  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x004e08b1:
    // 004e08b1  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004e08b2  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004e08b4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004e08b6  742b                   -je 0x4e08e3
    if (cpu.flags.zf)
    {
        goto L_0x004e08e3;
    }
    // 004e08b8  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004e08ba  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004e08bc  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004e08be  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004e08bf  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004e08c1  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004e08c3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e08c5  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi);
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
    // 004e08c7  7405                   -je 0x4e08ce
    if (cpu.flags.zf)
    {
        goto L_0x004e08ce;
    }
    // 004e08c9  19c0                   +sbb eax, eax
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
    // 004e08cb  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x004e08ce:
    // 004e08ce  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004e08cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e08d1  750b                   -jne 0x4e08de
    if (!cpu.flags.zf)
    {
        goto L_0x004e08de;
    }
    // 004e08d3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e08d5  83c404                 +add esp, 4
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
    // 004e08d8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08d9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08da  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08db  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08dc  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e08de:
    // 004e08de  8d7201                 -lea esi, [edx + 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004e08e1  ebb1                   -jmp 0x4e0894
    goto L_0x004e0894;
L_0x004e08e3:
    // 004e08e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004e08e5:
    // 004e08e5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e08e8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08e9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08ea  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08eb  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08ec  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4e08f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e08f0  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004e08f6  833dc844560002         +cmp dword ptr [0x5644c8], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653704) /* 0x5644c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e08fd  7c6e                   -jl 0x4e096d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e096d;
    }
    // 004e08ff  833dc444560000         +cmp dword ptr [0x5644c4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0906  750a                   -jne 0x4e0912
    if (!cpu.flags.zf)
    {
        goto L_0x004e0912;
    }
    // 004e0908  e8d3a90000             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004e090d  a3c4445600             -mov dword ptr [0x5644c4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */) = cpu.eax;
L_0x004e0912:
    // 004e0912  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0913  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0914  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e0915  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0916  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0917  8b1dc4445600           -mov ebx, dword ptr [0x5644c4]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
    // 004e091d  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e091e  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e0924  8d842420010000         -lea eax, [esp + 0x120]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 004e092b  8d9c2414010000         -lea ebx, [esp + 0x114]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004e0932  8b94241c010000         -mov edx, dword ptr [esp + 0x11c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 004e0939  89842414010000         -mov dword ptr [esp + 0x114], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */) = cpu.eax;
    // 004e0940  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004e0944  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004e0946  e829edffff             -call 0x4df674
    cpu.esp -= 4;
    sub_4df674(app, cpu);
    if (cpu.terminate) return;
    // 004e094b  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004e094f  89b42414010000         -mov dword ptr [esp + 0x114], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */) = cpu.esi;
    // 004e0956  e805010000             -call 0x4e0a60
    cpu.esp -= 4;
    sub_4e0a60(app, cpu);
    if (cpu.terminate) return;
    // 004e095b  8b3dc4445600           -mov edi, dword ptr [0x5644c4]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
    // 004e0961  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0962  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e0968  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0969  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e096a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e096b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e096c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e096d:
    // 004e096d  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004e0973  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4e0980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0980  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0981  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0982  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e0983  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004e0989  8bb42414010000         -mov esi, dword ptr [esp + 0x114]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004e0990  8b9c2418010000         -mov ebx, dword ptr [esp + 0x118]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 004e0997  833dc844560002         +cmp dword ptr [0x5644c8], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653704) /* 0x5644c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e099e  0f8c8a000000           -jl 0x4e0a2e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0a2e;
    }
    // 004e09a4  833dc444560000         +cmp dword ptr [0x5644c4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e09ab  0f8487000000           -je 0x4e0a38
    if (cpu.flags.zf)
    {
        goto L_0x004e0a38;
    }
L_0x004e09b1:
    // 004e09b1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e09b2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e09b3  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e09b4  8b3dc4445600           -mov edi, dword ptr [0x5644c4]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
    // 004e09ba  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e09bb  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e09c1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e09c3  7c23                   -jl 0x4e09e8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e09e8;
    }
    // 004e09c5  83fe50                 +cmp esi, 0x50
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e09c8  7d1e                   -jge 0x4e09e8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e09e8;
    }
    // 004e09ca  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e09cc  7c1a                   -jl 0x4e09e8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e09e8;
    }
    // 004e09ce  83fb19                 +cmp ebx, 0x19
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e09d1  7d15                   -jge 0x4e09e8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e09e8;
    }
    // 004e09d3  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004e09da  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e09dc  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004e09df  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004e09e1  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e09e3  a3d4445600             -mov dword ptr [0x5644d4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */) = cpu.eax;
L_0x004e09e8:
    // 004e09e8  8d84242c010000         -lea eax, [esp + 0x12c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004e09ef  8d9c240c010000         -lea ebx, [esp + 0x10c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004e09f6  8b942428010000         -mov edx, dword ptr [esp + 0x128]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 004e09fd  8984240c010000         -mov dword ptr [esp + 0x10c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.eax;
    // 004e0a04  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e0a08  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004e0a0a  e865ecffff             -call 0x4df674
    cpu.esp -= 4;
    sub_4df674(app, cpu);
    if (cpu.terminate) return;
    // 004e0a0f  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e0a13  89ac240c010000         -mov dword ptr [esp + 0x10c], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.ebp;
    // 004e0a1a  e841000000             -call 0x4e0a60
    cpu.esp -= 4;
    sub_4e0a60(app, cpu);
    if (cpu.terminate) return;
    // 004e0a1f  a1c4445600             -mov eax, dword ptr [0x5644c4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
    // 004e0a24  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e0a25  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e0a2b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a2c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a2d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e0a2e:
    // 004e0a2e  81c404010000           +add esp, 0x104
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(260 /*0x104*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0a34  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a35  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a36  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a37  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0a38:
    // 004e0a38  e8a3a80000             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004e0a3d  a3c4445600             -mov dword ptr [0x5644c4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */) = cpu.eax;
    // 004e0a42  e96affffff             -jmp 0x4e09b1
    goto L_0x004e09b1;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4e0a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004e0a60  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0a61  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0a62  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e0a63  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0a64  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0a65  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e0a66  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e0a69  8b35d4445600           -mov esi, dword ptr [0x5644d4]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */);
    // 004e0a6f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e0a71  833dc844560002         +cmp dword ptr [0x5644c8], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653704) /* 0x5644c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0a78  7d10                   -jge 0x4e0a8a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e0a8a;
    }
L_0x004e0a7a:
    // 004e0a7a  8b35d4445600           -mov esi, dword ptr [0x5644d4]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */);
    // 004e0a80  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e0a83  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a84  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a85  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a86  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a87  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a88  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a89  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0a8a:
    // 004e0a8a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004e0a8c  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e0a8e  49                     -dec ecx
    (cpu.ecx)--;
    // 004e0a8f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e0a91  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004e0a93  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004e0a95  49                     -dec ecx
    (cpu.ecx)--;
    // 004e0a96  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004e0a98  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004e0a9b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004e0a9d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e0a9f  7ed9                   -jle 0x4e0a7a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e0a7a;
    }
    // 004e0aa1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
L_0x004e0aa3:
    // 004e0aa3  80fb0e                 +cmp bl, 0xe
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(14 /*0xe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e0aa6  7447                   -je 0x4e0aef
    if (cpu.flags.zf)
    {
        goto L_0x004e0aef;
    }
    // 004e0aa8  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx);
    // 004e0aaa  8b35d4445600           -mov esi, dword ptr [0x5644d4]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */);
    // 004e0ab0  80fb20                 +cmp bl, 0x20
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
    // 004e0ab3  7247                   -jb 0x4e0afc
    if (cpu.flags.cf)
    {
        goto L_0x004e0afc;
    }
    // 004e0ab5  e856010000             -call 0x4e0c10
    cpu.esp -= 4;
    sub_4e0c10(app, cpu);
    if (cpu.terminate) return;
    // 004e0aba  8b35d4445600           -mov esi, dword ptr [0x5644d4]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */);
    // 004e0ac0  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004e0ac2  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004e0ac4  a0d9445600             -mov al, byte ptr [0x5644d9]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5653721) /* 0x5644d9 */);
    // 004e0ac9  88da                   -mov dl, bl
    cpu.dl = cpu.bl;
    // 004e0acb  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004e0ace  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004e0ad1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e0ad3  8b15d0445600           -mov edx, dword ptr [0x5644d0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5653712) /* 0x5644d0 */);
    // 004e0ad9  8935d4445600           -mov dword ptr [0x5644d4], esi
    *app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */) = cpu.esi;
    // 004e0adf  66894432fe             -mov word ptr [edx + esi - 2], ax
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */ + cpu.esi * 1) = cpu.ax;
L_0x004e0ae4:
    // 004e0ae4  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 004e0ae7  47                     -inc edi
    (cpu.edi)++;
    // 004e0ae8  41                     -inc ecx
    (cpu.ecx)++;
    // 004e0ae9  39ef                   +cmp edi, ebp
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
    // 004e0aeb  7d8d                   -jge 0x4e0a7a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e0a7a;
    }
    // 004e0aed  ebb4                   -jmp 0x4e0aa3
    goto L_0x004e0aa3;
L_0x004e0aef:
    // 004e0aef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e0af1  8a01                   -mov al, byte ptr [ecx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx);
    // 004e0af3  30db                   +xor bl, bl
    cpu.clear_co();
    cpu.set_szp((cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl))));
    // 004e0af5  e856020000             -call 0x4e0d50
    cpu.esp -= 4;
    sub_4e0d50(app, cpu);
    if (cpu.terminate) return;
    // 004e0afa  ebe8                   -jmp 0x4e0ae4
    goto L_0x004e0ae4;
L_0x004e0afc:
    // 004e0afc  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004e0afe  2c08                   -sub al, 8
    (cpu.al) -= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004e0b00  3c04                   +cmp al, 4
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
    // 004e0b02  77e0                   -ja 0x4e0ae4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004e0ae4;
    }
    // 004e0b04  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004e0b09  ff2485480a4e00         -jmp dword ptr [eax*4 + 0x4e0a48]
    cpu.ip = *app->getMemory<x86::reg32>(5114440 + cpu.eax * 4); goto dynamic_jump;
  case 0x004e0b10:
    // 004e0b10  83fe02                 +cmp esi, 2
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
    // 004e0b13  7ccf                   -jl 0x4e0ae4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0ae4;
    }
    // 004e0b15  83ee02                 -sub esi, 2
    (cpu.esi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004e0b18  8935d4445600           -mov dword ptr [0x5644d4], esi
    *app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */) = cpu.esi;
    // 004e0b1e  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 004e0b21  47                     -inc edi
    (cpu.edi)++;
    // 004e0b22  41                     -inc ecx
    (cpu.ecx)++;
    // 004e0b23  39ef                   +cmp edi, ebp
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
    // 004e0b25  0f8d4fffffff           -jge 0x4e0a7a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e0a7a;
    }
    // 004e0b2b  e973ffffff             -jmp 0x4e0aa3
    goto L_0x004e0aa3;
  case 0x004e0b30:
    // 004e0b30  803dda44560001         +cmp byte ptr [0x5644da], 1
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5653722) /* 0x5644da */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e0b37  76ab                   -jbe 0x4e0ae4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004e0ae4;
    }
    // 004e0b39  bda0000000             -mov ebp, 0xa0
    cpu.ebp = 160 /*0xa0*/;
    // 004e0b3e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e0b40  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0b42  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004e0b45  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004e0b47  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004e0b4a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e0b4c  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004e0b4e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e0b50  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004e0b53  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e0b55  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004e0b57  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e0b59  0fb635da445600         -movzx esi, byte ptr [0x5644da]
    cpu.esi = x86::reg32(*app->getMemory<x86::reg8>(x86::reg32(5653722) /* 0x5644da */));
    // 004e0b60  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004e0b63  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004e0b65  40                     -inc eax
    (cpu.eax)++;
    // 004e0b66  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004e0b69  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e0b6b  8d3428                 -lea esi, [eax + ebp]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 004e0b6e  8935d4445600           -mov dword ptr [0x5644d4], esi
    *app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */) = cpu.esi;
    // 004e0b74  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 004e0b77  47                     -inc edi
    (cpu.edi)++;
    // 004e0b78  41                     -inc ecx
    (cpu.ecx)++;
    // 004e0b79  39ef                   +cmp edi, ebp
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
    // 004e0b7b  0f8df9feffff           -jge 0x4e0a7a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e0a7a;
    }
    // 004e0b81  e91dffffff             -jmp 0x4e0aa3
    goto L_0x004e0aa3;
  case 0x004e0b86:
    // 004e0b86  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0b88  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e0b8a  bea0000000             -mov esi, 0xa0
    cpu.esi = 160 /*0xa0*/;
    // 004e0b8f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004e0b92  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004e0b94  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004e0b97  69f6a0000000           -imul esi, esi, 0xa0
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(160 /*0xa0*/)));
    // 004e0b9d  8935d4445600           -mov dword ptr [0x5644d4], esi
    *app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */) = cpu.esi;
    // 004e0ba3  e868000000             -call 0x4e0c10
    cpu.esp -= 4;
    sub_4e0c10(app, cpu);
    if (cpu.terminate) return;
    // 004e0ba8  8b35d4445600           -mov esi, dword ptr [0x5644d4]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */);
    // 004e0bae  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 004e0bb1  47                     -inc edi
    (cpu.edi)++;
    // 004e0bb2  41                     -inc ecx
    (cpu.ecx)++;
    // 004e0bb3  39ef                   +cmp edi, ebp
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
    // 004e0bb5  0f8dbffeffff           -jge 0x4e0a7a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e0a7a;
    }
    // 004e0bbb  e9e3feffff             -jmp 0x4e0aa3
    goto L_0x004e0aa3;
  case 0x004e0bc0:
    // 004e0bc0  0fb635d8445600         -movzx esi, byte ptr [0x5644d8]
    cpu.esi = x86::reg32(*app->getMemory<x86::reg8>(x86::reg32(5653720) /* 0x5644d8 */));
    // 004e0bc7  69f6a0000000           -imul esi, esi, 0xa0
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(160 /*0xa0*/)));
    // 004e0bcd  8935d4445600           -mov dword ptr [0x5644d4], esi
    *app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */) = cpu.esi;
    // 004e0bd3  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 004e0bd6  47                     -inc edi
    (cpu.edi)++;
    // 004e0bd7  41                     -inc ecx
    (cpu.ecx)++;
    // 004e0bd8  39ef                   +cmp edi, ebp
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
    // 004e0bda  0f8d9afeffff           -jge 0x4e0a7a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e0a7a;
    }
    // 004e0be0  e9befeffff             -jmp 0x4e0aa3
    goto L_0x004e0aa3;
  case 0x004e0be5:
    // 004e0be5  e8b6000000             -call 0x4e0ca0
    cpu.esp -= 4;
    sub_4e0ca0(app, cpu);
    if (cpu.terminate) return;
    // 004e0bea  0fb635d8445600         -movzx esi, byte ptr [0x5644d8]
    cpu.esi = x86::reg32(*app->getMemory<x86::reg8>(x86::reg32(5653720) /* 0x5644d8 */));
    // 004e0bf1  69f6a0000000           -imul esi, esi, 0xa0
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(160 /*0xa0*/)));
    // 004e0bf7  8935d4445600           -mov dword ptr [0x5644d4], esi
    *app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */) = cpu.esi;
    // 004e0bfd  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 004e0c00  47                     -inc edi
    (cpu.edi)++;
    // 004e0c01  41                     -inc ecx
    (cpu.ecx)++;
    // 004e0c02  39ef                   +cmp edi, ebp
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
    // 004e0c04  0f8d70feffff           -jge 0x4e0a7a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e0a7a;
    }
    // 004e0c0a  e994feffff             -jmp 0x4e0aa3
    goto L_0x004e0aa3;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x90 */
void Application::sub_4e0c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0c10  813dd4445600a00f0000   +cmp dword ptr [0x5644d4], 0xfa0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4000 /*0xfa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0c1a  7d01                   -jge 0x4e0c1d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e0c1d;
    }
    // 004e0c1c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0c1d:
    // 004e0c1d  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0c1e  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0c1f  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e0c20  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0c21  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0c22  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e0c24  b919000000             -mov ecx, 0x19
    cpu.ecx = 25 /*0x19*/;
    // 004e0c29  8a15d8445600           -mov dl, byte ptr [0x5644d8]
    cpu.dl = *app->getMemory<x86::reg8>(x86::reg32(5653720) /* 0x5644d8 */);
    // 004e0c2f  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e0c31  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004e0c38  49                     -dec ecx
    (cpu.ecx)--;
    // 004e0c39  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e0c3b  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 004e0c42  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004e0c45  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e0c47  8b0dd0445600           -mov ecx, dword ptr [0x5644d0]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5653712) /* 0x5644d0 */);
    // 004e0c4d  42                     -inc edx
    (cpu.edx)++;
    // 004e0c4e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e0c50  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004e0c57  8b35d0445600           -mov esi, dword ptr [0x5644d0]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5653712) /* 0x5644d0 */);
    // 004e0c5d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e0c5f  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 004e0c62  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004e0c65  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e0c67  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004e0c69  e882980000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e0c6e  a1d0445600             -mov eax, dword ptr [0x5644d0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5653712) /* 0x5644d0 */);
    // 004e0c73  baa0000000             -mov edx, 0xa0
    cpu.edx = 160 /*0xa0*/;
    // 004e0c78  05000f0000             -add eax, 0xf00
    (cpu.eax) += x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004e0c7d  bf000f0000             -mov edi, 0xf00
    cpu.edi = 3840 /*0xf00*/;
    // 004e0c82  e885faffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004e0c87  893dd4445600           -mov dword ptr [0x5644d4], edi
    *app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */) = cpu.edi;
    // 004e0c8d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0c8e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0c8f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0c90  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0c91  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0c92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e0ca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0ca0  833dc844560002         +cmp dword ptr [0x5644c8], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653704) /* 0x5644c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0ca7  7c44                   -jl 0x4e0ced
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0ced;
    }
    // 004e0ca9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0caa  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e0cab  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0cac  833dc444560000         +cmp dword ptr [0x5644c4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0cb3  7439                   -je 0x4e0cee
    if (cpu.flags.zf)
    {
        goto L_0x004e0cee;
    }
L_0x004e0cb5:
    // 004e0cb5  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0cb6  8b1dc4445600           -mov ebx, dword ptr [0x5644c4]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
    // 004e0cbc  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0cbd  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e0cc3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e0cc5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e0cc6:
    // 004e0cc6  8b15d0445600           -mov edx, dword ptr [0x5644d0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5653712) /* 0x5644d0 */);
    // 004e0ccc  c7040200000000         -mov dword ptr [edx + eax], 0
    *app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 004e0cd3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e0cd6  3da00f0000             +cmp eax, 0xfa0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4000 /*0xfa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0cdb  7ce9                   -jl 0x4e0cc6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0cc6;
    }
    // 004e0cdd  8b35c4445600           -mov esi, dword ptr [0x5644c4]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
    // 004e0ce3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0ce4  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e0cea  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0ceb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0cec  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e0ced:
    // 004e0ced  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0cee:
    // 004e0cee  e8eda50000             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004e0cf3  a3c4445600             -mov dword ptr [0x5644c4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */) = cpu.eax;
    // 004e0cf8  ebbb                   -jmp 0x4e0cb5
    goto L_0x004e0cb5;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4e0d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0d00  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0d01  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0d02  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e0d03  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e0d05  833dc444560000         +cmp dword ptr [0x5644c4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0d0c  750a                   -jne 0x4e0d18
    if (!cpu.flags.zf)
    {
        goto L_0x004e0d18;
    }
    // 004e0d0e  e8cda50000             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004e0d13  a3c4445600             -mov dword ptr [0x5644c4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */) = cpu.eax;
L_0x004e0d18:
    // 004e0d18  8b0dc4445600           -mov ecx, dword ptr [0x5644c4]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
    // 004e0d1e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0d1f  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e0d25  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e0d27  7c0b                   -jl 0x4e0d34
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0d34;
    }
    // 004e0d29  83fb18                 +cmp ebx, 0x18
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
    // 004e0d2c  7f06                   -jg 0x4e0d34
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e0d34;
    }
    // 004e0d2e  881dd8445600           -mov byte ptr [0x5644d8], bl
    *app->getMemory<x86::reg8>(x86::reg32(5653720) /* 0x5644d8 */) = cpu.bl;
L_0x004e0d34:
    // 004e0d34  8b1dc4445600           -mov ebx, dword ptr [0x5644c4]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
    // 004e0d3a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0d3b  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e0d41  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0d42  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0d43  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0d44  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4e0d50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0d50  a2d9445600             -mov byte ptr [0x5644d9], al
    *app->getMemory<x86::reg8>(x86::reg32(5653721) /* 0x5644d9 */) = cpu.al;
    // 004e0d55  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4e0d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0d60  83f801                 +cmp eax, 1
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
    // 004e0d63  7d01                   -jge 0x4e0d66
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e0d66;
    }
    // 004e0d65  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0d66:
    // 004e0d66  a2da445600             -mov byte ptr [0x5644da], al
    *app->getMemory<x86::reg8>(x86::reg32(5653722) /* 0x5644da */) = cpu.al;
    // 004e0d6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4e0d70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0d70  c1e00f                 -shl eax, 0xf
    cpu.eax <<= 15 /*0xf*/ % 32;
    // 004e0d73  0500000b00             -add eax, 0xb0000
    (cpu.eax) += x86::reg32(x86::sreg32(720896 /*0xb0000*/));
    // 004e0d78  a3d0445600             -mov dword ptr [0x5644d0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653712) /* 0x5644d0 */) = cpu.eax;
    // 004e0d7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e0d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0d80  c60000                 -mov byte ptr [eax], 0
    *app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004e0d83  c60200                 -mov byte ptr [edx], 0
    *app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004e0d86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4e0d88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0d88  a1f4445600             -mov eax, dword ptr [0x5644f4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5653748) /* 0x5644f4 */);
    // 004e0d8d  0305f0445600           +add eax, dword ptr [0x5644f0]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5653744) /* 0x5644f0 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0d93  a3f0445600             -mov dword ptr [0x5644f0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653744) /* 0x5644f0 */) = cpu.eax;
    // 004e0d98  1305ec445600           +adc eax, dword ptr [0x5644ec]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5653740) /* 0x5644ec */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0d9e  a3ec445600             -mov dword ptr [0x5644ec], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653740) /* 0x5644ec */) = cpu.eax;
    // 004e0da3  1305e8445600           +adc eax, dword ptr [0x5644e8]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5653736) /* 0x5644e8 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0da9  a3e8445600             -mov dword ptr [0x5644e8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653736) /* 0x5644e8 */) = cpu.eax;
    // 004e0dae  1305e4445600           +adc eax, dword ptr [0x5644e4]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5653732) /* 0x5644e4 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0db4  a3e4445600             -mov dword ptr [0x5644e4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653732) /* 0x5644e4 */) = cpu.eax;
    // 004e0db9  1305e0445600           +adc eax, dword ptr [0x5644e0]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0dbf  ff05f4445600           +inc dword ptr [0x5644f4]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(x86::reg32(5653748) /* 0x5644f4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e0dc5  7521                   -jne 0x4e0de8
    if (!cpu.flags.zf)
    {
        goto L_0x004e0de8;
    }
    // 004e0dc7  ff05f0445600           +inc dword ptr [0x5644f0]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(x86::reg32(5653744) /* 0x5644f0 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e0dcd  7519                   -jne 0x4e0de8
    if (!cpu.flags.zf)
    {
        goto L_0x004e0de8;
    }
    // 004e0dcf  ff05ec445600           +inc dword ptr [0x5644ec]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(x86::reg32(5653740) /* 0x5644ec */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e0dd5  7511                   -jne 0x4e0de8
    if (!cpu.flags.zf)
    {
        goto L_0x004e0de8;
    }
    // 004e0dd7  ff05e8445600           +inc dword ptr [0x5644e8]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(x86::reg32(5653736) /* 0x5644e8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e0ddd  7509                   -jne 0x4e0de8
    if (!cpu.flags.zf)
    {
        goto L_0x004e0de8;
    }
    // 004e0ddf  ff05e4445600           +inc dword ptr [0x5644e4]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(x86::reg32(5653732) /* 0x5644e4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e0de5  7501                   -jne 0x4e0de8
    if (!cpu.flags.zf)
    {
        goto L_0x004e0de8;
    }
    // 004e0de7  40                     -inc eax
    (cpu.eax)++;
L_0x004e0de8:
    // 004e0de8  a3e0445600             -mov dword ptr [0x5644e0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */) = cpu.eax;
    // 004e0ded  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e0dee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0dee  05560e2df2             -add eax, 0xf22d0e56
    (cpu.eax) += x86::reg32(x86::sreg32(4063039062 /*0xf22d0e56*/));
    // 004e0df3  a3e0445600             -mov dword ptr [0x5644e0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */) = cpu.eax;
    // 004e0df8  0593180496             -add eax, 0x96041893
    (cpu.eax) += x86::reg32(x86::sreg32(2516850835 /*0x96041893*/));
    // 004e0dfd  a3e4445600             -mov dword ptr [0x5644e4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653732) /* 0x5644e4 */) = cpu.eax;
    // 004e0e02  0546b6f33d             -add eax, 0x3df3b646
    (cpu.eax) += x86::reg32(x86::sreg32(1039382086 /*0x3df3b646*/));
    // 004e0e07  a3e8445600             -mov dword ptr [0x5644e8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653736) /* 0x5644e8 */) = cpu.eax;
    // 004e0e0c  056de7dd40             -add eax, 0x40dde76d
    (cpu.eax) += x86::reg32(x86::sreg32(1088284525 /*0x40dde76d*/));
    // 004e0e11  a3ec445600             -mov dword ptr [0x5644ec], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653740) /* 0x5644ec */) = cpu.eax;
    // 004e0e16  05e17a3297             -add eax, 0x97327ae1
    (cpu.eax) += x86::reg32(x86::sreg32(2536667873 /*0x97327ae1*/));
    // 004e0e1b  a3f0445600             -mov dword ptr [0x5644f0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653744) /* 0x5644f0 */) = cpu.eax;
    // 004e0e20  05e7fba9d1             -add eax, 0xd1a9fbe7
    (cpu.eax) += x86::reg32(x86::sreg32(3517578215 /*0xd1a9fbe7*/));
    // 004e0e25  a3f4445600             -mov dword ptr [0x5644f4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653748) /* 0x5644f4 */) = cpu.eax;
    // 004e0e2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e0e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0e30  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0e31  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0e32  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e0e34  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e0e36  740f                   -je 0x4e0e47
    if (cpu.flags.zf)
    {
        goto L_0x004e0e47;
    }
L_0x004e0e38:
    // 004e0e38  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e0e3b  740a                   -je 0x4e0e47
    if (cpu.flags.zf)
    {
        goto L_0x004e0e47;
    }
    // 004e0e3d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e0e3e  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx);
    // 004e0e40  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e0e41  8848ff                 -mov byte ptr [eax - 1], cl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 004e0e44  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e0e45  75f1                   -jne 0x4e0e38
    if (!cpu.flags.zf)
    {
        goto L_0x004e0e38;
    }
L_0x004e0e47:
    // 004e0e47  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004e0e49:
    // 004e0e49  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e0e4b  7407                   -je 0x4e0e54
    if (cpu.flags.zf)
    {
        goto L_0x004e0e54;
    }
    // 004e0e4d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e0e4e  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e0e4f  8850ff                 -mov byte ptr [eax - 1], dl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 004e0e52  ebf5                   -jmp 0x4e0e49
    goto L_0x004e0e49;
L_0x004e0e54:
    // 004e0e54  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0e56  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0e57  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0e58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e0e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0e60  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0e61  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0e62  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e0e63  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0e64  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0e67  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e0e6b  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e0e6f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e0e71  8b350c445600           -mov esi, dword ptr [0x56440c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
    // 004e0e77  89150c445600           -mov dword ptr [0x56440c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.edx;
    // 004e0e7d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004e0e7f  e84c1a0000             -call 0x4e28d0
    cpu.esp -= 4;
    sub_4e28d0(app, cpu);
    if (cpu.terminate) return;
    // 004e0e84  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 004e0e87  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e0e89  7511                   -jne 0x4e0e9c
    if (!cpu.flags.zf)
    {
        goto L_0x004e0e9c;
    }
    // 004e0e8b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004e0e8e  89350c445600           -mov dword ptr [0x56440c], esi
    *app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.esi;
    // 004e0e94  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0e97  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0e98  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0e99  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0e9a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0e9b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0e9c:
    // 004e0e9c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e0e9e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004e0ea3  e8f81e0000             -call 0x4e2da0
    cpu.esp -= 4;
    sub_4e2da0(app, cpu);
    if (cpu.terminate) return;
    // 004e0ea8  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004e0eab  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004e0eae  89350c445600           -mov dword ptr [0x56440c], esi
    *app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.esi;
    // 004e0eb4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0eb7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0eb8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0eb9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0eba  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0ebb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4e0ec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0ec0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0ec1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0ec2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0ec3  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0ec4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e0ec5  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0ec8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004e0eca  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004e0ecc  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 004e0ed1  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004e0ed3  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e0ed7  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e0edb  e8e0e80100             -call 0x4ff7c0
    cpu.esp -= 4;
    sub_4ff7c0(app, cpu);
    if (cpu.terminate) return;
    // 004e0ee0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e0ee2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004e0ee4  e8e7190000             -call 0x4e28d0
    cpu.esp -= 4;
    sub_4e28d0(app, cpu);
    if (cpu.terminate) return;
    // 004e0ee9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e0eeb  0f84cc000000           -je 0x4e0fbd
    if (cpu.flags.zf)
    {
        goto L_0x004e0fbd;
    }
    // 004e0ef1  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 004e0ef4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e0ef6  0f84c1000000           -je 0x4e0fbd
    if (cpu.flags.zf)
    {
        goto L_0x004e0fbd;
    }
    // 004e0efc  b90e010000             -mov ecx, 0x10e
    cpu.ecx = 270 /*0x10e*/;
    // 004e0f01  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e0f03  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004e0f06  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004e0f08  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e0f0a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e0f0e  e81de90100             -call 0x4ff830
    cpu.esp -= 4;
    sub_4ff830(app, cpu);
    if (cpu.terminate) return;
    // 004e0f13  8b3560785600           -mov esi, dword ptr [0x567860]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5666912) /* 0x567860 */);
    // 004e0f19  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e0f1b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0f1d  bb28995400             -mov ebx, 0x549928
    cpu.ebx = 5544232 /*0x549928*/;
    // 004e0f22  e8f9e80100             -call 0x4ff820
    cpu.esp -= 4;
    sub_4ff820(app, cpu);
    if (cpu.terminate) return;
    // 004e0f27  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e0f29  be38995400             -mov esi, 0x549938
    cpu.esi = 5544248 /*0x549938*/;
    // 004e0f2e  e88de80100             -call 0x4ff7c0
    cpu.esp -= 4;
    sub_4ff7c0(app, cpu);
    if (cpu.terminate) return;
    // 004e0f33  b84b000000             -mov eax, 0x4b
    cpu.eax = 75 /*0x4b*/;
    // 004e0f38  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 004e0f3b  891d90215500           -mov dword ptr [0x552190], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e0f41  a398215500             -mov dword ptr [0x552198], eax
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e0f46  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004e0f48  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e0f4a  893594215500           -mov dword ptr [0x552194], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e0f50  e8cb060000             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004e0f55  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e0f57  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e0f59  7416                   -je 0x4e0f71
    if (cpu.flags.zf)
    {
        goto L_0x004e0f71;
    }
    // 004e0f5b  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 004e0f5e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e0f60  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e0f64  e8771e0000             -call 0x4e2de0
    cpu.esp -= 4;
    sub_4e2de0(app, cpu);
    if (cpu.terminate) return;
    // 004e0f69  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004e0f6c  a3f8435600             -mov dword ptr [0x5643f8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5653496) /* 0x5643f8 */) = cpu.eax;
L_0x004e0f71:
    // 004e0f71  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e0f75  e8261e0000             -call 0x4e2da0
    cpu.esp -= 4;
    sub_4e2da0(app, cpu);
    if (cpu.terminate) return;
    // 004e0f7a  e861e80100             -call 0x4ff7e0
    cpu.esp -= 4;
    sub_4ff7e0(app, cpu);
    if (cpu.terminate) return;
    // 004e0f7f  833d6878560000         +cmp dword ptr [0x567868], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5666920) /* 0x567868 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0f86  7404                   -je 0x4e0f8c
    if (cpu.flags.zf)
    {
        goto L_0x004e0f8c;
    }
    // 004e0f88  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e0f8a  750b                   -jne 0x4e0f97
    if (!cpu.flags.zf)
    {
        goto L_0x004e0f97;
    }
L_0x004e0f8c:
    // 004e0f8c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0f8e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0f91  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0f92  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0f93  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0f94  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0f95  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0f96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0f97:
    // 004e0f97  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004e0f99  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004e0f9b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0f9d  ff1568785600           -call dword ptr [0x567868]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666920) /* 0x567868 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e0fa3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e0fa5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e0fa7  7507                   -jne 0x4e0fb0
    if (!cpu.flags.zf)
    {
        goto L_0x004e0fb0;
    }
    // 004e0fa9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0fab  e8e0080000             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004e0fb0:
    // 004e0fb0  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004e0fb2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0fb4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0fb7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fb8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fb9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fba  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fbb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fbc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0fbd:
    // 004e0fbd  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e0fc1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e0fc3  74c7                   -je 0x4e0f8c
    if (cpu.flags.zf)
    {
        goto L_0x004e0f8c;
    }
    // 004e0fc5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e0fc7  e8d41d0000             -call 0x4e2da0
    cpu.esp -= 4;
    sub_4e2da0(app, cpu);
    if (cpu.terminate) return;
    // 004e0fcc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0fce  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0fd1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fd2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fd3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fd4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fd5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fd6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4e0fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0fe0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0fe1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0fe2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e0fe4  8b0d0c445600           -mov ecx, dword ptr [0x56440c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
    // 004e0fea  891d0c445600           -mov dword ptr [0x56440c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.ebx;
    // 004e0ff0  e8cbfeffff             -call 0x4e0ec0
    cpu.esp -= 4;
    sub_4e0ec0(app, cpu);
    if (cpu.terminate) return;
    // 004e0ff5  890d0c445600           -mov dword ptr [0x56440c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.ecx;
    // 004e0ffb  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0ffc  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0ffd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4e1000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1000  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e1003  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e1005  7512                   -jne 0x4e1019
    if (!cpu.flags.zf)
    {
        goto L_0x004e1019;
    }
L_0x004e1007:
    // 004e1007  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e100a  3b5004                 +cmp edx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e100d  7ff8                   -jg 0x4e1007
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e1007;
    }
    // 004e100f  6681385342             +cmp word ptr [eax], 0x4253
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16979 /*0x4253*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004e1014  7502                   -jne 0x4e1018
    if (!cpu.flags.zf)
    {
        goto L_0x004e1018;
    }
    // 004e1016  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004e1018:
    // 004e1018  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e1019:
    // 004e1019  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004e101c  3b5004                 +cmp edx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e101f  7ff8                   -jg 0x4e1019
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e1019;
    }
    // 004e1021  6681385342             +cmp word ptr [eax], 0x4253
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16979 /*0x4253*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004e1026  75f0                   -jne 0x4e1018
    if (!cpu.flags.zf)
    {
        goto L_0x004e1018;
    }
    // 004e1028  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e102a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4e1030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1030  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e1031  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1032  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e1035  4a                     -dec edx
    (cpu.edx)--;
    // 004e1036  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e1038  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e103a  7c1b                   -jl 0x4e1057
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e1057;
    }
L_0x004e103c:
    // 004e103c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e103e  751b                   -jne 0x4e105b
    if (!cpu.flags.zf)
    {
        goto L_0x004e105b;
    }
L_0x004e1040:
    // 004e1040  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e1043  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e1046  39f2                   +cmp edx, esi
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
    // 004e1048  7df6                   -jge 0x4e1040
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e1040;
    }
    // 004e104a  6681385342             +cmp word ptr [eax], 0x4253
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16979 /*0x4253*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004e104f  7421                   -je 0x4e1072
    if (cpu.flags.zf)
    {
        goto L_0x004e1072;
    }
    // 004e1051  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e1053  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e1055  ebe9                   -jmp 0x4e1040
    goto L_0x004e1040;
L_0x004e1057:
    // 004e1057  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004e1059  ebe1                   -jmp 0x4e103c
    goto L_0x004e103c;
L_0x004e105b:
    // 004e105b  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004e105e  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e1061  39da                   +cmp edx, ebx
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
    // 004e1063  7df6                   -jge 0x4e105b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e105b;
    }
    // 004e1065  6681385342             +cmp word ptr [eax], 0x4253
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16979 /*0x4253*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004e106a  7406                   -je 0x4e1072
    if (cpu.flags.zf)
    {
        goto L_0x004e1072;
    }
    // 004e106c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004e106e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e1070  ebe9                   -jmp 0x4e105b
    goto L_0x004e105b;
L_0x004e1072:
    // 004e1072  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e1074  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1075  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1076  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4e1080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1080  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e1081  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e1082  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1083  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e1084  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e1086  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004e1089  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e108b  8d73f0                 -lea esi, [ebx - 0x10]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(-16) /* -0x10 */);
    // 004e108e  8b7820                 -mov edi, dword ptr [eax + 0x20]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004e1091  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004e1094  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004e1096  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004e1098  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e109b  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004e109d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e109f  39d9                   +cmp ecx, ebx
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
    // 004e10a1  762c                   -jbe 0x4e10cf
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004e10cf;
    }
L_0x004e10a3:
    // 004e10a3  8b5214                 -mov edx, dword ptr [edx + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004e10a6  39d1                   +cmp ecx, edx
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
    // 004e10a8  72f9                   -jb 0x4e10a3
    if (cpu.flags.cf)
    {
        goto L_0x004e10a3;
    }
    // 004e10aa  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
L_0x004e10ad:
    // 004e10ad  895114                 -mov dword ptr [ecx + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004e10b0  897104                 -mov dword ptr [ecx + 4], esi
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004e10b3  894110                 -mov dword ptr [ecx + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004e10b6  894a10                 -mov dword ptr [edx + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004e10b9  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004e10bc  8a6103                 -mov ah, byte ptr [ecx + 3]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 004e10bf  66c7014642             -mov word ptr [ecx], 0x4246
    *app->getMemory<x86::reg16>(cpu.ecx) = 16966 /*0x4246*/;
    // 004e10c4  80cc40                 -or ah, 0x40
    cpu.ah |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004e10c7  886103                 -mov byte ptr [ecx + 3], ah
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */) = cpu.ah;
    // 004e10ca  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e10cb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e10cc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e10cd  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e10ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e10cf:
    // 004e10cf  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e10d2  39c1                   +cmp ecx, eax
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
    // 004e10d4  77f9                   -ja 0x4e10cf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004e10cf;
    }
    // 004e10d6  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004e10d9  ebd2                   -jmp 0x4e10ad
    goto L_0x004e10ad;
}

}
