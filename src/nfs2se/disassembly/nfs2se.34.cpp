#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_4b03c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b03c4;
    // 004b03ae  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 004b03b3  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b03b5  39c8                   +cmp eax, ecx
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
    // 004b03b7  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004b03b8  7203                   -jb 0x4b03bd
    if (cpu.flags.cf)
    {
        goto L_0x004b03bd;
    }
    // 004b03ba  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004b03bb  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x004b03bd:
    // 004b03bd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b03be  e801000000             -call 0x4b03c4
    cpu.esp -= 4;
    sub_4b03c4(app, cpu);
    if (cpu.terminate) return;
    // 004b03c3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x004b03c4:
    // 004b03c4  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 004b03c9  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b03cb  39c8                   +cmp eax, ecx
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
    // 004b03cd  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004b03ce  7204                   -jb 0x4b03d4
    if (cpu.flags.cf)
    {
        goto L_0x004b03d4;
    }
    // 004b03d0  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004b03d1  66f7f1                 -div cx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.cx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x004b03d4:
    // 004b03d4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b03d5  e801000000             -call 0x4b03db
    cpu.esp -= 4;
    sub_4b03db(app, cpu);
    if (cpu.terminate) return;
    // 004b03da  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b03db  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 004b03dd  38c8                   +cmp al, cl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b03df  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 004b03e1  7204                   -jb 0x4b03e7
    if (cpu.flags.cf)
    {
        goto L_0x004b03e7;
    }
    // 004b03e3  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 004b03e5  f6f1                   -div cl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.cl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
L_0x004b03e7:
    // 004b03e7  80c430                 -add ah, 0x30
    (cpu.ah) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004b03ea  0430                   -add al, 0x30
    (cpu.al) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004b03ec  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004b03ee  43                     -inc ebx
    (cpu.ebx)++;
    // 004b03ef  8823                   -mov byte ptr [ebx], ah
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.ah;
    // 004b03f1  43                     -inc ebx
    (cpu.ebx)++;
    // 004b03f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b03db(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b03db;
    // 004b03ae  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 004b03b3  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b03b5  39c8                   +cmp eax, ecx
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
    // 004b03b7  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004b03b8  7203                   -jb 0x4b03bd
    if (cpu.flags.cf)
    {
        goto L_0x004b03bd;
    }
    // 004b03ba  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004b03bb  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x004b03bd:
    // 004b03bd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b03be  e801000000             -call 0x4b03c4
    cpu.esp -= 4;
    sub_4b03c4(app, cpu);
    if (cpu.terminate) return;
    // 004b03c3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b03c4  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 004b03c9  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b03cb  39c8                   +cmp eax, ecx
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
    // 004b03cd  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004b03ce  7204                   -jb 0x4b03d4
    if (cpu.flags.cf)
    {
        goto L_0x004b03d4;
    }
    // 004b03d0  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004b03d1  66f7f1                 -div cx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.cx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x004b03d4:
    // 004b03d4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b03d5  e801000000             -call 0x4b03db
    cpu.esp -= 4;
    sub_4b03db(app, cpu);
    if (cpu.terminate) return;
    // 004b03da  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x004b03db:
    // 004b03db  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 004b03dd  38c8                   +cmp al, cl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b03df  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 004b03e1  7204                   -jb 0x4b03e7
    if (cpu.flags.cf)
    {
        goto L_0x004b03e7;
    }
    // 004b03e3  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 004b03e5  f6f1                   -div cl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.cl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
L_0x004b03e7:
    // 004b03e7  80c430                 -add ah, 0x30
    (cpu.ah) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004b03ea  0430                   -add al, 0x30
    (cpu.al) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004b03ec  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004b03ee  43                     -inc ebx
    (cpu.ebx)++;
    // 004b03ef  8823                   -mov byte ptr [ebx], ah
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.ah;
    // 004b03f1  43                     -inc ebx
    (cpu.ebx)++;
    // 004b03f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b03f3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b03f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b03f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b03f5  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004b03f7  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004b03f9  895dd8                 -mov dword ptr [ebp - 0x28], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.ebx;
    // 004b03fc  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b03ff  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004b0401  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 004b0404  e90dffffff             -jmp 0x4b0316
    return sub_4b0316(app, cpu);
}

/* align: skip  */
void Application::sub_4b0409(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0409  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004b040c  8d9569ffffff           -lea edx, [ebp - 0x97]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 004b0412  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x004b0415:
    // 004b0415  803a30                 +cmp byte ptr [edx], 0x30
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
    // 004b0418  7505                   -jne 0x4b041f
    if (!cpu.flags.zf)
    {
        goto L_0x004b041f;
    }
    // 004b041a  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b041b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b041c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b041d  ebf6                   -jmp 0x4b0415
    goto L_0x004b0415;
L_0x004b041f:
    // 004b041f  8a7e08                 -mov bh, byte ptr [esi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b0422  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 004b0424  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 004b0427  740a                   -je 0x4b0433
    if (cpu.flags.zf)
    {
        goto L_0x004b0433;
    }
    // 004b0429  034e04                 -add ecx, dword ptr [esi + 4]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004b042c  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b042f  01df                   +add edi, ebx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0431  eb15                   -jmp 0x4b0448
    goto L_0x004b0448;
L_0x004b0433:
    // 004b0433  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 004b0436  7410                   -je 0x4b0448
    if (cpu.flags.zf)
    {
        goto L_0x004b0448;
    }
    // 004b0438  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b043b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b043d  7e03                   -jle 0x4b0442
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0442;
    }
    // 004b043f  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b0440  eb02                   -jmp 0x4b0444
    goto L_0x004b0444;
L_0x004b0442:
    // 004b0442  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b0444:
    // 004b0444  41                     -inc ecx
    (cpu.ecx)++;
    // 004b0445  2b4e04                 -sub ecx, dword ptr [esi + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
L_0x004b0448:
    // 004b0448  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b044a  0f8c65000000           -jl 0x4b04b5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b04b5;
    }
    // 004b0450  39c7                   +cmp edi, eax
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
    // 004b0452  7e02                   -jle 0x4b0456
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0456;
    }
    // 004b0454  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004b0456:
    // 004b0456  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 004b045b  f6460820               +test byte ptr [esi + 8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 32 /*0x20*/));
    // 004b045f  7405                   -je 0x4b0466
    if (cpu.flags.zf)
    {
        goto L_0x004b0466;
    }
    // 004b0461  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
L_0x004b0466:
    // 004b0466  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 004b046a  7402                   -je 0x4b046e
    if (cpu.flags.zf)
    {
        goto L_0x004b046e;
    }
    // 004b046c  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b046e:
    // 004b046e  39df                   +cmp edi, ebx
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
    // 004b0470  7e03                   -jle 0x4b0475
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0475;
    }
    // 004b0472  8d7b01                 -lea edi, [ebx + 1]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
L_0x004b0475:
    // 004b0475  c645f030               -mov byte ptr [ebp - 0x10], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 48 /*0x30*/;
    // 004b0479  39f8                   +cmp eax, edi
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
    // 004b047b  7e0a                   -jle 0x4b0487
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0487;
    }
    // 004b047d  803c3a35               +cmp byte ptr [edx + edi], 0x35
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b0481  7204                   -jb 0x4b0487
    if (cpu.flags.cf)
    {
        goto L_0x004b0487;
    }
    // 004b0483  c645f039               -mov byte ptr [ebp - 0x10], 0x39
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 57 /*0x39*/;
L_0x004b0487:
    // 004b0487  897de4                 -mov dword ptr [ebp - 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 004b048a  8d0417                 -lea eax, [edi + edx]
    cpu.eax = x86::reg32(cpu.edi + cpu.edx * 1);
L_0x004b048d:
    // 004b048d  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004b0490  4b                     -dec ebx
    (cpu.ebx)--;
    // 004b0491  48                     -dec eax
    (cpu.eax)--;
    // 004b0492  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 004b0495  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b0497  8a7df0                 -mov bh, byte ptr [ebp - 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b049a  38fb                   +cmp bl, bh
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
    // 004b049c  7503                   -jne 0x4b04a1
    if (!cpu.flags.zf)
    {
        goto L_0x004b04a1;
    }
    // 004b049e  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b049f  ebec                   -jmp 0x4b048d
    goto L_0x004b048d;
L_0x004b04a1:
    // 004b04a1  80ff39                 +cmp bh, 0x39
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b04a4  7506                   -jne 0x4b04ac
    if (!cpu.flags.zf)
    {
        goto L_0x004b04ac;
    }
    // 004b04a6  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 004b04a8  fec7                   -inc bh
    (cpu.bh)++;
    // 004b04aa  8838                   -mov byte ptr [eax], bh
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
L_0x004b04ac:
    // 004b04ac  837de400               +cmp dword ptr [ebp - 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b04b0  7d03                   -jge 0x4b04b5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b04b5;
    }
    // 004b04b2  4a                     -dec edx
    (cpu.edx)--;
    // 004b04b3  47                     -inc edi
    (cpu.edi)++;
    // 004b04b4  41                     -inc ecx
    (cpu.ecx)++;
L_0x004b04b5:
    // 004b04b5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b04b7  7f18                   -jg 0x4b04d1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b04d1;
    }
    // 004b04b9  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004b04be  b030                   -mov al, 0x30
    cpu.al = 48 /*0x30*/;
    // 004b04c0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b04c2  888568ffffff           -mov byte ptr [ebp - 0x98], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = cpu.al;
    // 004b04c8  8d9568ffffff           -lea edx, [ebp - 0x98]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-152) /* -0x98 */);
    // 004b04ce  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x004b04d1:
    // 004b04d1  8a6608                 -mov ah, byte ptr [esi + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b04d4  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 004b04d7  7514                   -jne 0x4b04ed
    if (!cpu.flags.zf)
    {
        goto L_0x004b04ed;
    }
    // 004b04d9  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004b04dc  741e                   -je 0x4b04fc
    if (cpu.flags.zf)
    {
        goto L_0x004b04fc;
    }
    // 004b04de  83f9fc                 +cmp ecx, -4
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
    // 004b04e1  7c04                   -jl 0x4b04e7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b04e7;
    }
    // 004b04e3  3b0e                   +cmp ecx, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b04e5  7c06                   -jl 0x4b04ed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b04ed;
    }
L_0x004b04e7:
    // 004b04e7  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 004b04eb  740f                   -je 0x4b04fc
    if (cpu.flags.zf)
    {
        goto L_0x004b04fc;
    }
L_0x004b04ed:
    // 004b04ed  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b04f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b04f1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b04f3  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004b04f5  e822000000             -call 0x4b051c
    cpu.esp -= 4;
    sub_4b051c(app, cpu);
    if (cpu.terminate) return;
    // 004b04fa  eb0d                   -jmp 0x4b0509
    goto L_0x004b0509;
L_0x004b04fc:
    // 004b04fc  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b04ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0500  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004b0502  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0504  e831020000             -call 0x4b073a
    cpu.esp -= 4;
    sub_4b073a(app, cpu);
    if (cpu.terminate) return;
L_0x004b0509:
    // 004b0509  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b050b  668b45ec               -mov ax, word ptr [ebp - 0x14]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004b050f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0510  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b0513  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0514  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b0517  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0518  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0519  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b051a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b051b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b0509(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b0509;
    // 004b0409  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004b040c  8d9569ffffff           -lea edx, [ebp - 0x97]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 004b0412  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x004b0415:
    // 004b0415  803a30                 +cmp byte ptr [edx], 0x30
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
    // 004b0418  7505                   -jne 0x4b041f
    if (!cpu.flags.zf)
    {
        goto L_0x004b041f;
    }
    // 004b041a  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b041b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b041c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b041d  ebf6                   -jmp 0x4b0415
    goto L_0x004b0415;
L_0x004b041f:
    // 004b041f  8a7e08                 -mov bh, byte ptr [esi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b0422  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 004b0424  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 004b0427  740a                   -je 0x4b0433
    if (cpu.flags.zf)
    {
        goto L_0x004b0433;
    }
    // 004b0429  034e04                 -add ecx, dword ptr [esi + 4]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004b042c  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b042f  01df                   +add edi, ebx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0431  eb15                   -jmp 0x4b0448
    goto L_0x004b0448;
L_0x004b0433:
    // 004b0433  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 004b0436  7410                   -je 0x4b0448
    if (cpu.flags.zf)
    {
        goto L_0x004b0448;
    }
    // 004b0438  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b043b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b043d  7e03                   -jle 0x4b0442
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0442;
    }
    // 004b043f  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b0440  eb02                   -jmp 0x4b0444
    goto L_0x004b0444;
L_0x004b0442:
    // 004b0442  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b0444:
    // 004b0444  41                     -inc ecx
    (cpu.ecx)++;
    // 004b0445  2b4e04                 -sub ecx, dword ptr [esi + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
L_0x004b0448:
    // 004b0448  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b044a  0f8c65000000           -jl 0x4b04b5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b04b5;
    }
    // 004b0450  39c7                   +cmp edi, eax
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
    // 004b0452  7e02                   -jle 0x4b0456
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0456;
    }
    // 004b0454  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004b0456:
    // 004b0456  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 004b045b  f6460820               +test byte ptr [esi + 8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 32 /*0x20*/));
    // 004b045f  7405                   -je 0x4b0466
    if (cpu.flags.zf)
    {
        goto L_0x004b0466;
    }
    // 004b0461  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
L_0x004b0466:
    // 004b0466  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 004b046a  7402                   -je 0x4b046e
    if (cpu.flags.zf)
    {
        goto L_0x004b046e;
    }
    // 004b046c  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b046e:
    // 004b046e  39df                   +cmp edi, ebx
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
    // 004b0470  7e03                   -jle 0x4b0475
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0475;
    }
    // 004b0472  8d7b01                 -lea edi, [ebx + 1]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
L_0x004b0475:
    // 004b0475  c645f030               -mov byte ptr [ebp - 0x10], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 48 /*0x30*/;
    // 004b0479  39f8                   +cmp eax, edi
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
    // 004b047b  7e0a                   -jle 0x4b0487
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0487;
    }
    // 004b047d  803c3a35               +cmp byte ptr [edx + edi], 0x35
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b0481  7204                   -jb 0x4b0487
    if (cpu.flags.cf)
    {
        goto L_0x004b0487;
    }
    // 004b0483  c645f039               -mov byte ptr [ebp - 0x10], 0x39
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 57 /*0x39*/;
L_0x004b0487:
    // 004b0487  897de4                 -mov dword ptr [ebp - 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 004b048a  8d0417                 -lea eax, [edi + edx]
    cpu.eax = x86::reg32(cpu.edi + cpu.edx * 1);
L_0x004b048d:
    // 004b048d  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004b0490  4b                     -dec ebx
    (cpu.ebx)--;
    // 004b0491  48                     -dec eax
    (cpu.eax)--;
    // 004b0492  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 004b0495  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b0497  8a7df0                 -mov bh, byte ptr [ebp - 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b049a  38fb                   +cmp bl, bh
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
    // 004b049c  7503                   -jne 0x4b04a1
    if (!cpu.flags.zf)
    {
        goto L_0x004b04a1;
    }
    // 004b049e  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b049f  ebec                   -jmp 0x4b048d
    goto L_0x004b048d;
L_0x004b04a1:
    // 004b04a1  80ff39                 +cmp bh, 0x39
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b04a4  7506                   -jne 0x4b04ac
    if (!cpu.flags.zf)
    {
        goto L_0x004b04ac;
    }
    // 004b04a6  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 004b04a8  fec7                   -inc bh
    (cpu.bh)++;
    // 004b04aa  8838                   -mov byte ptr [eax], bh
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
L_0x004b04ac:
    // 004b04ac  837de400               +cmp dword ptr [ebp - 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b04b0  7d03                   -jge 0x4b04b5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b04b5;
    }
    // 004b04b2  4a                     -dec edx
    (cpu.edx)--;
    // 004b04b3  47                     -inc edi
    (cpu.edi)++;
    // 004b04b4  41                     -inc ecx
    (cpu.ecx)++;
L_0x004b04b5:
    // 004b04b5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b04b7  7f18                   -jg 0x4b04d1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b04d1;
    }
    // 004b04b9  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004b04be  b030                   -mov al, 0x30
    cpu.al = 48 /*0x30*/;
    // 004b04c0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b04c2  888568ffffff           -mov byte ptr [ebp - 0x98], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = cpu.al;
    // 004b04c8  8d9568ffffff           -lea edx, [ebp - 0x98]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-152) /* -0x98 */);
    // 004b04ce  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x004b04d1:
    // 004b04d1  8a6608                 -mov ah, byte ptr [esi + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b04d4  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 004b04d7  7514                   -jne 0x4b04ed
    if (!cpu.flags.zf)
    {
        goto L_0x004b04ed;
    }
    // 004b04d9  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004b04dc  741e                   -je 0x4b04fc
    if (cpu.flags.zf)
    {
        goto L_0x004b04fc;
    }
    // 004b04de  83f9fc                 +cmp ecx, -4
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
    // 004b04e1  7c04                   -jl 0x4b04e7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b04e7;
    }
    // 004b04e3  3b0e                   +cmp ecx, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b04e5  7c06                   -jl 0x4b04ed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b04ed;
    }
L_0x004b04e7:
    // 004b04e7  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 004b04eb  740f                   -je 0x4b04fc
    if (cpu.flags.zf)
    {
        goto L_0x004b04fc;
    }
L_0x004b04ed:
    // 004b04ed  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b04f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b04f1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b04f3  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004b04f5  e822000000             -call 0x4b051c
    cpu.esp -= 4;
    sub_4b051c(app, cpu);
    if (cpu.terminate) return;
    // 004b04fa  eb0d                   -jmp 0x4b0509
    goto L_0x004b0509;
L_0x004b04fc:
    // 004b04fc  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b04ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0500  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004b0502  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0504  e831020000             -call 0x4b073a
    cpu.esp -= 4;
    sub_4b073a(app, cpu);
    if (cpu.terminate) return;
L_0x004b0509:
L_entry_0x004b0509:
    // 004b0509  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b050b  668b45ec               -mov ax, word ptr [ebp - 0x14]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004b050f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0510  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b0513  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0514  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b0517  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0518  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0519  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b051a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b051b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b051c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b051c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b051d  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b051f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0520  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0521  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b0524  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0525  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0526  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0527  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b0529  41                     -inc ecx
    (cpu.ecx)++;
    // 004b052a  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004b052d  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 004b0530  8a6008                 -mov ah, byte ptr [eax + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b0533  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b0535  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004b0538  7425                   -je 0x4b055f
    if (cpu.flags.zf)
    {
        goto L_0x004b055f;
    }
    // 004b053a  3b5df4                 +cmp ebx, dword ptr [ebp - 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b053d  7d0c                   -jge 0x4b054b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b054b;
    }
    // 004b053f  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0542  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 004b0546  7503                   -jne 0x4b054b
    if (!cpu.flags.zf)
    {
        goto L_0x004b054b;
    }
    // 004b0548  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
L_0x004b054b:
    // 004b054b  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b054e  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b0551  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b0553  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 004b0556  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b0558  7d05                   -jge 0x4b055f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b055f;
    }
    // 004b055a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b055c  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
L_0x004b055f:
    // 004b055f  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0562  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b0564  0f8fa4000000           -jg 0x4b060e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b060e;
    }
    // 004b056a  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b056d  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 004b0571  7526                   -jne 0x4b0599
    if (!cpu.flags.zf)
    {
        goto L_0x004b0599;
    }
    // 004b0573  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0576  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b0578  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b057a  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b057d  42                     -inc edx
    (cpu.edx)++;
    // 004b057e  c60630                 -mov byte ptr [esi], 0x30
    app->getMemory<x86::reg8>(cpu.esi) = 48 /*0x30*/;
    // 004b0581  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0583  7f09                   -jg 0x4b058e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b058e;
    }
    // 004b0585  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0588  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 004b058c  740b                   -je 0x4b0599
    if (cpu.flags.zf)
    {
        goto L_0x004b0599;
    }
L_0x004b058e:
    // 004b058e  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0591  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b0593  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0595  42                     -inc edx
    (cpu.edx)++;
    // 004b0596  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
L_0x004b0599:
    // 004b0599  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b059c  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004b059f  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b05a2  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b05a5  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 004b05a7  39fe                   +cmp esi, edi
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
    // 004b05a9  7e0a                   -jle 0x4b05b5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b05b5;
    }
    // 004b05ab  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b05ad  897de8                 -mov dword ptr [ebp - 0x18], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edi;
    // 004b05b0  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004b05b2  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x004b05b5:
    // 004b05b5  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b05b8  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b05bb  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004b05be  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b05c0  897720                 -mov dword ptr [edi + 0x20], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004b05c3  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b05c5  894f20                 -mov dword ptr [edi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004b05c8  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b05cb  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b05cd  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 004b05d0  39fb                   +cmp ebx, edi
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
    // 004b05d2  7e02                   -jle 0x4b05d6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b05d6;
    }
    // 004b05d4  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004b05d6:
    // 004b05d6  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b05d9  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004b05dc  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b05de  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b05e0  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b05e1  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b05e3  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b05e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b05e6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b05e8  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b05eb  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b05ed  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b05ef  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b05f2  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b05f4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b05f5  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b05f6  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b05f9  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004b05fc  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b05ff  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b0601  29de                   +sub esi, ebx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0603  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0606  897328                 -mov dword ptr [ebx + 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 004b0609  e90d010000             -jmp 0x4b071b
    goto L_0x004b071b;
L_0x004b060e:
    // 004b060e  39f3                   +cmp ebx, esi
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
    // 004b0610  7d70                   -jge 0x4b0682
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b0682;
    }
    // 004b0612  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004b0615  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0618  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b061a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b061b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b061d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b061f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0620  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b0622  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b0625  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0627  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b0629  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b062c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b062e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b062f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b0630  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0633  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004b0636  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0639  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b063b  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b063d  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0640  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004b0643  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0646  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0649  8a4e08                 -mov cl, byte ptr [esi + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b064c  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004b064f  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 004b0652  7520                   -jne 0x4b0674
    if (!cpu.flags.zf)
    {
        goto L_0x004b0674;
    }
    // 004b0654  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0658  7f05                   -jg 0x4b065f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b065f;
    }
    // 004b065a  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 004b065d  7415                   -je 0x4b0674
    if (cpu.flags.zf)
    {
        goto L_0x004b0674;
    }
L_0x004b065f:
    // 004b065f  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0662  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b0664  01cb                   +add ebx, ecx
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
    // 004b0666  c6032e                 -mov byte ptr [ebx], 0x2e
    app->getMemory<x86::reg8>(cpu.ebx) = 46 /*0x2e*/;
    // 004b0669  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b066c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b066d  c7432401000000         -mov dword ptr [ebx + 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
L_0x004b0674:
    // 004b0674  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0677  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b067a  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004b067d  e999000000             -jmp 0x4b071b
    goto L_0x004b071b;
L_0x004b0682:
    // 004b0682  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0685  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b0687  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004b068a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b068b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b068d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b068f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0690  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b0692  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b0695  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0697  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b0699  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b069c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b069e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b069f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b06a0  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b06a3  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b06a6  8a6f08                 -mov ch, byte ptr [edi + 8]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004b06a9  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b06ab  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b06ad  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004b06b0  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 004b06b3  7518                   -jne 0x4b06cd
    if (!cpu.flags.zf)
    {
        goto L_0x004b06cd;
    }
    // 004b06b5  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b06b9  7f05                   -jg 0x4b06c0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b06c0;
    }
    // 004b06bb  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 004b06be  741c                   -je 0x4b06dc
    if (cpu.flags.zf)
    {
        goto L_0x004b06dc;
    }
L_0x004b06c0:
    // 004b06c0  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b06c3  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b06c5  01c7                   +add edi, eax
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
    // 004b06c7  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b06c8  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
    // 004b06cb  eb0f                   -jmp 0x4b06dc
    goto L_0x004b06dc;
L_0x004b06cd:
    // 004b06cd  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b06d0  803e30                 +cmp byte ptr [esi], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b06d3  7507                   -jne 0x4b06dc
    if (!cpu.flags.zf)
    {
        goto L_0x004b06dc;
    }
    // 004b06d5  c7471800000000         -mov dword ptr [edi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
L_0x004b06dc:
    // 004b06dc  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b06df  39cb                   +cmp ebx, ecx
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
    // 004b06e1  7e02                   -jle 0x4b06e5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b06e5;
    }
    // 004b06e3  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x004b06e5:
    // 004b06e5  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004b06e8  0375e8                 -add esi, dword ptr [ebp - 0x18]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 004b06eb  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b06ee  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b06f0  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b06f2  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b06f3  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b06f5  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b06f7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b06f8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b06fa  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b06fd  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b06ff  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b0701  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b0704  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b0706  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0707  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b0708  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b070b  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b070d  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004b0710  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b0713  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b0715  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0718  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
L_0x004b071b:
    // 004b071b  035508                 -add edx, dword ptr [ebp + 8]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004b071e  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004b0721  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004b0724  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0725  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0726  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0727  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4b0721(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b0721;
    // 004b051c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b051d  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b051f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0520  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0521  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b0524  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0525  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0526  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0527  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b0529  41                     -inc ecx
    (cpu.ecx)++;
    // 004b052a  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004b052d  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 004b0530  8a6008                 -mov ah, byte ptr [eax + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b0533  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b0535  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004b0538  7425                   -je 0x4b055f
    if (cpu.flags.zf)
    {
        goto L_0x004b055f;
    }
    // 004b053a  3b5df4                 +cmp ebx, dword ptr [ebp - 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b053d  7d0c                   -jge 0x4b054b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b054b;
    }
    // 004b053f  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0542  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 004b0546  7503                   -jne 0x4b054b
    if (!cpu.flags.zf)
    {
        goto L_0x004b054b;
    }
    // 004b0548  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
L_0x004b054b:
    // 004b054b  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b054e  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b0551  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b0553  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 004b0556  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b0558  7d05                   -jge 0x4b055f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b055f;
    }
    // 004b055a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b055c  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
L_0x004b055f:
    // 004b055f  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0562  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b0564  0f8fa4000000           -jg 0x4b060e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b060e;
    }
    // 004b056a  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b056d  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 004b0571  7526                   -jne 0x4b0599
    if (!cpu.flags.zf)
    {
        goto L_0x004b0599;
    }
    // 004b0573  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0576  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b0578  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b057a  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b057d  42                     -inc edx
    (cpu.edx)++;
    // 004b057e  c60630                 -mov byte ptr [esi], 0x30
    app->getMemory<x86::reg8>(cpu.esi) = 48 /*0x30*/;
    // 004b0581  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0583  7f09                   -jg 0x4b058e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b058e;
    }
    // 004b0585  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0588  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 004b058c  740b                   -je 0x4b0599
    if (cpu.flags.zf)
    {
        goto L_0x004b0599;
    }
L_0x004b058e:
    // 004b058e  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0591  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b0593  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0595  42                     -inc edx
    (cpu.edx)++;
    // 004b0596  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
L_0x004b0599:
    // 004b0599  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b059c  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004b059f  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b05a2  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b05a5  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 004b05a7  39fe                   +cmp esi, edi
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
    // 004b05a9  7e0a                   -jle 0x4b05b5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b05b5;
    }
    // 004b05ab  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b05ad  897de8                 -mov dword ptr [ebp - 0x18], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edi;
    // 004b05b0  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004b05b2  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x004b05b5:
    // 004b05b5  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b05b8  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b05bb  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004b05be  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b05c0  897720                 -mov dword ptr [edi + 0x20], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004b05c3  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b05c5  894f20                 -mov dword ptr [edi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004b05c8  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b05cb  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b05cd  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 004b05d0  39fb                   +cmp ebx, edi
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
    // 004b05d2  7e02                   -jle 0x4b05d6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b05d6;
    }
    // 004b05d4  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004b05d6:
    // 004b05d6  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b05d9  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004b05dc  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b05de  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b05e0  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b05e1  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b05e3  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b05e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b05e6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b05e8  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b05eb  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b05ed  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b05ef  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b05f2  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b05f4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b05f5  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b05f6  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b05f9  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004b05fc  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b05ff  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b0601  29de                   +sub esi, ebx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0603  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0606  897328                 -mov dword ptr [ebx + 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 004b0609  e90d010000             -jmp 0x4b071b
    goto L_0x004b071b;
L_0x004b060e:
    // 004b060e  39f3                   +cmp ebx, esi
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
    // 004b0610  7d70                   -jge 0x4b0682
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b0682;
    }
    // 004b0612  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004b0615  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0618  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b061a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b061b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b061d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b061f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0620  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b0622  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b0625  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0627  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b0629  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b062c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b062e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b062f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b0630  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0633  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004b0636  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0639  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b063b  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b063d  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0640  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004b0643  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0646  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0649  8a4e08                 -mov cl, byte ptr [esi + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b064c  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004b064f  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 004b0652  7520                   -jne 0x4b0674
    if (!cpu.flags.zf)
    {
        goto L_0x004b0674;
    }
    // 004b0654  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0658  7f05                   -jg 0x4b065f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b065f;
    }
    // 004b065a  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 004b065d  7415                   -je 0x4b0674
    if (cpu.flags.zf)
    {
        goto L_0x004b0674;
    }
L_0x004b065f:
    // 004b065f  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0662  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b0664  01cb                   +add ebx, ecx
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
    // 004b0666  c6032e                 -mov byte ptr [ebx], 0x2e
    app->getMemory<x86::reg8>(cpu.ebx) = 46 /*0x2e*/;
    // 004b0669  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b066c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b066d  c7432401000000         -mov dword ptr [ebx + 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
L_0x004b0674:
    // 004b0674  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0677  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b067a  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004b067d  e999000000             -jmp 0x4b071b
    goto L_0x004b071b;
L_0x004b0682:
    // 004b0682  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0685  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b0687  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004b068a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b068b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b068d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b068f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0690  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b0692  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b0695  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0697  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b0699  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b069c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b069e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b069f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b06a0  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b06a3  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b06a6  8a6f08                 -mov ch, byte ptr [edi + 8]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004b06a9  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b06ab  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b06ad  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004b06b0  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 004b06b3  7518                   -jne 0x4b06cd
    if (!cpu.flags.zf)
    {
        goto L_0x004b06cd;
    }
    // 004b06b5  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b06b9  7f05                   -jg 0x4b06c0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b06c0;
    }
    // 004b06bb  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 004b06be  741c                   -je 0x4b06dc
    if (cpu.flags.zf)
    {
        goto L_0x004b06dc;
    }
L_0x004b06c0:
    // 004b06c0  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b06c3  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b06c5  01c7                   +add edi, eax
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
    // 004b06c7  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b06c8  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
    // 004b06cb  eb0f                   -jmp 0x4b06dc
    goto L_0x004b06dc;
L_0x004b06cd:
    // 004b06cd  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b06d0  803e30                 +cmp byte ptr [esi], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b06d3  7507                   -jne 0x4b06dc
    if (!cpu.flags.zf)
    {
        goto L_0x004b06dc;
    }
    // 004b06d5  c7471800000000         -mov dword ptr [edi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
L_0x004b06dc:
    // 004b06dc  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b06df  39cb                   +cmp ebx, ecx
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
    // 004b06e1  7e02                   -jle 0x4b06e5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b06e5;
    }
    // 004b06e3  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x004b06e5:
    // 004b06e5  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004b06e8  0375e8                 -add esi, dword ptr [ebp - 0x18]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 004b06eb  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b06ee  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b06f0  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b06f2  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b06f3  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b06f5  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b06f7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b06f8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b06fa  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b06fd  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b06ff  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b0701  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b0704  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b0706  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0707  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b0708  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b070b  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b070d  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004b0710  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b0713  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b0715  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0718  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
L_0x004b071b:
    // 004b071b  035508                 -add edx, dword ptr [ebp + 8]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004b071e  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_entry_0x004b0721:
    // 004b0721  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004b0724  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0725  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0726  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0727  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4b073a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004b073a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b073b  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b073d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b073e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b073f  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b0742  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0743  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0744  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0745  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0746  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b0748  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004b074b  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b074e  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b0751  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b0753  7f05                   -jg 0x4b075a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b075a;
    }
    // 004b0755  0155ec                 +add dword ptr [ebp - 0x14], edx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0758  eb0e                   -jmp 0x4b0768
    goto L_0x004b0768;
L_0x004b075a:
    // 004b075a  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004b075d  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b075f  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 004b0762  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b0765  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
L_0x004b0768:
    // 004b0768  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b076b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b076d  8a5008                 -mov dl, byte ptr [eax + 8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b0770  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 004b0773  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 004b0776  741b                   -je 0x4b0793
    if (cpu.flags.zf)
    {
        goto L_0x004b0793;
    }
    // 004b0778  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b077b  3b45ec                 +cmp eax, dword ptr [ebp - 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b077e  7d03                   -jge 0x4b0783
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b0783;
    }
    // 004b0780  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
L_0x004b0783:
    // 004b0783  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004b0786  4b                     -dec ebx
    (cpu.ebx)--;
    // 004b0787  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 004b078a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b078c  7d05                   -jge 0x4b0793
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b0793;
    }
    // 004b078e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004b0790  8975ec                 -mov dword ptr [ebp - 0x14], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.esi;
L_0x004b0793:
    // 004b0793  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0796  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b0799  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b079b  7f16                   -jg 0x4b07b3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b07b3;
    }
    // 004b079d  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b07a0  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b07a3  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b07a6  01d8                   +add eax, ebx
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
    // 004b07a8  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004b07ab  c60030                 -mov byte ptr [eax], 0x30
    app->getMemory<x86::reg8>(cpu.eax) = 48 /*0x30*/;
    // 004b07ae  e97c000000             -jmp 0x4b082f
    goto L_0x004b082f;
L_0x004b07b3:
    // 004b07b3  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b07b6  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 004b07b9  39d7                   +cmp edi, edx
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
    // 004b07bb  7e03                   -jle 0x4b07c0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b07c0;
    }
    // 004b07bd  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
L_0x004b07c0:
    // 004b07c0  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b07c3  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b07c6  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b07c9  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004b07cc  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b07ce  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b07d1  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b07d2  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b07d4  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b07d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b07d7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b07d9  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b07dc  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b07de  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b07e0  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b07e3  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b07e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b07e6  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b07e7  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b07ea  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004b07ed  8b7de0                 -mov edi, dword ptr [ebp - 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b07f0  8d0c03                 -lea ecx, [ebx + eax]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004b07f3  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b07f5  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b07f7  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 004b07fa  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 004b07fd  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004b0800  897de0                 -mov dword ptr [ebp - 0x20], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edi;
    // 004b0803  39d8                   +cmp eax, ebx
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
    // 004b0805  7d28                   -jge 0x4b082f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b082f;
    }
    // 004b0807  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b080a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b080c  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b080f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0811  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 004b0816  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004b0819  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b081c  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b081f  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b0821  e89939fdff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 004b0826  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0829  8d3c06                 -lea edi, [esi + eax]
    cpu.edi = x86::reg32(cpu.esi + cpu.eax * 1);
    // 004b082c  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
L_0x004b082f:
    // 004b082f  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0832  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b0835  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b0838  f6420808               +test byte ptr [edx + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 004b083c  7520                   -jne 0x4b085e
    if (!cpu.flags.zf)
    {
        goto L_0x004b085e;
    }
    // 004b083e  837dec00               +cmp dword ptr [ebp - 0x14], 0
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
    // 004b0842  7f09                   -jg 0x4b084d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b084d;
    }
    // 004b0844  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0847  f6400810               +test byte ptr [eax + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 004b084b  7411                   -je 0x4b085e
    if (cpu.flags.zf)
    {
        goto L_0x004b085e;
    }
L_0x004b084d:
    // 004b084d  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b0850  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0853  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b0856  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b0858  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 004b085b  c6002e                 -mov byte ptr [eax], 0x2e
    app->getMemory<x86::reg8>(cpu.eax) = 46 /*0x2e*/;
L_0x004b085e:
    // 004b085e  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0861  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b0864  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b0866  7d25                   -jge 0x4b088d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b088d;
    }
    // 004b0868  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b086b  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b086e  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b0870  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004b0873  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 004b0878  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 004b087a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b087c  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 004b087f  e83b39fdff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 004b0884  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0887  8d3401                 -lea esi, [ecx + eax]
    cpu.esi = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 004b088a  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
L_0x004b088d:
    // 004b088d  8b7dec                 -mov edi, dword ptr [ebp - 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004b0890  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b0892  7e49                   -jle 0x4b08dd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b08dd;
    }
    // 004b0894  3b7de0                 +cmp edi, dword ptr [ebp - 0x20]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0897  7d03                   -jge 0x4b089c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b089c;
    }
    // 004b0899  897de0                 -mov dword ptr [ebp - 0x20], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edi;
L_0x004b089c:
    // 004b089c  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b089f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b08a1  7426                   -je 0x4b08c9
    if (cpu.flags.zf)
    {
        goto L_0x004b08c9;
    }
    // 004b08a3  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b08a6  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b08a9  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004b08ac  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b08ae  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b08b0  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b08b1  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b08b3  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b08b5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b08b6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b08b8  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b08bb  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b08bd  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b08bf  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b08c2  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b08c4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b08c5  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b08c6  015df4                 -add dword ptr [ebp - 0xc], ebx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b08c9:
    // 004b08c9  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b08cc  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b08cf  8b7de0                 -mov edi, dword ptr [ebp - 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b08d2  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004b08d5  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004b08d8  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004b08da  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x004b08dd:
    // 004b08dd  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b08e0  83780c00               +cmp dword ptr [eax + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b08e4  7416                   -je 0x4b08fc
    if (cpu.flags.zf)
    {
        goto L_0x004b08fc;
    }
    // 004b08e6  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b08e9  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b08ec  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b08ef  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b08f2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b08f4  8a520c                 -mov dl, byte ptr [edx + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004b08f7  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 004b08fa  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x004b08fc:
    // 004b08fc  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b08ff  8b75dc                 -mov esi, dword ptr [ebp - 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004b0902  40                     -inc eax
    (cpu.eax)++;
    // 004b0903  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b0905  7c0f                   -jl 0x4b0916
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0916;
    }
    // 004b0907  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b090a  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004b090d  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0910  c604022b               -mov byte ptr [edx + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 43 /*0x2b*/;
    // 004b0914  eb14                   -jmp 0x4b092a
    goto L_0x004b092a;
L_0x004b0916:
    // 004b0916  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b0919  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004b091b  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004b091e  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 004b0920  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0923  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 004b0926  c604022d               -mov byte ptr [edx + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 45 /*0x2d*/;
L_0x004b092a:
    // 004b092a  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b092d  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b0930  83fb03                 +cmp ebx, 3
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
    // 004b0933  773e                   -ja 0x4b0973
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b0973;
    }
    // 004b0935  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b0937  2eff24852a074b00       -jmp dword ptr cs:[eax*4 + 0x4b072a]
    cpu.ip = app->getMemory<x86::reg32>(4917034 + cpu.eax * 4); goto dynamic_jump;
  case 0x004b093f:
    // 004b093f  817ddce8030000         +cmp dword ptr [ebp - 0x24], 0x3e8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0946  7d26                   -jge 0x4b096e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b096e;
    }
    // 004b0948  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004b094d  eb24                   -jmp 0x4b0973
    goto L_0x004b0973;
  case 0x004b094f:
    // 004b094f  837ddc0a               +cmp dword ptr [ebp - 0x24], 0xa
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0953  7c05                   -jl 0x4b095a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b095a;
    }
    // 004b0955  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
  [[fallthrough]];
  case 0x004b095a:
L_0x004b095a:
    // 004b095a  837ddc64               +cmp dword ptr [ebp - 0x24], 0x64
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b095e  7c05                   -jl 0x4b0965
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0965;
    }
    // 004b0960  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
  [[fallthrough]];
  case 0x004b0965:
L_0x004b0965:
    // 004b0965  817ddce8030000         +cmp dword ptr [ebp - 0x24], 0x3e8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b096c  7c05                   -jl 0x4b0973
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0973;
    }
L_0x004b096e:
    // 004b096e  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
L_0x004b0973:
    // 004b0973  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0976  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004b0979  83fb04                 +cmp ebx, 4
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
    // 004b097c  7c4b                   -jl 0x4b09c9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b09c9;
    }
    // 004b097e  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b0980  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004b0983  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 004b0986  3de8030000             +cmp eax, 0x3e8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b098b  7c26                   -jl 0x4b09b3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b09b3;
    }
    // 004b098d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b098f  bfe8030000             -mov edi, 0x3e8
    cpu.edi = 1000 /*0x3e8*/;
    // 004b0994  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b0997  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b0999  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004b099c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b099e  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004b09a1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b09a3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b09a6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b09a8  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004b09ab  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004b09ae  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b09b0  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x004b09b3:
    // 004b09b3  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b09b6  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b09b9  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b09bc  8a55f0                 -mov dl, byte ptr [ebp - 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b09bf  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b09c1  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004b09c4  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 004b09c7  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x004b09c9:
    // 004b09c9  83fb03                 +cmp ebx, 3
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
    // 004b09cc  7c49                   -jl 0x4b0a17
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0a17;
    }
    // 004b09ce  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b09d0  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004b09d3  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 004b09d6  83f864                 +cmp eax, 0x64
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b09d9  7c26                   -jl 0x4b0a01
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0a01;
    }
    // 004b09db  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b09dd  bf64000000             -mov edi, 0x64
    cpu.edi = 100 /*0x64*/;
    // 004b09e2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b09e5  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b09e7  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004b09ea  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b09ec  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b09ef  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b09f1  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004b09f4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b09f6  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004b09f9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b09fc  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b09fe  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x004b0a01:
    // 004b0a01  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b0a04  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0a07  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b0a0a  8a55f0                 -mov dl, byte ptr [ebp - 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0a0d  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b0a0f  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004b0a12  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 004b0a15  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x004b0a17:
    // 004b0a17  83fb02                 +cmp ebx, 2
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
    // 004b0a1a  7c43                   -jl 0x4b0a5f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0a5f;
    }
    // 004b0a1c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b0a1e  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004b0a21  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 004b0a24  83f80a                 +cmp eax, 0xa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0a27  7c20                   -jl 0x4b0a49
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0a49;
    }
    // 004b0a29  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b0a2b  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004b0a30  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b0a33  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b0a35  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004b0a38  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b0a3a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b0a3d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b0a3f  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004b0a42  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b0a44  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b0a46  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x004b0a49:
    // 004b0a49  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b0a4c  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0a4f  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b0a52  8a55f0                 -mov dl, byte ptr [ebp - 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0a55  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0a57  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004b0a5a  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 004b0a5d  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x004b0a5f:
    // 004b0a5f  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b0a62  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0a65  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b0a68  8a55dc                 -mov dl, byte ptr [ebp - 0x24]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004b0a6b  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b0a6d  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004b0a70  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004b0a72  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0a75  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b0a77  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b0a7a  29c2                   +sub edx, eax
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
    // 004b0a7c  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0a7f  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004b0a82  8d0437                 -lea eax, [edi + esi]
    cpu.eax = x86::reg32(cpu.edi + cpu.esi * 1);
    // 004b0a85  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 004b0a88  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004b0a8b  e991fcffff             -jmp 0x4b0721
    return sub_4b0721(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4b0a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0a90  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0a91  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b0a93  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0a94  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0a95  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0a96  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004b0a99  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b0a9b  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 004b0a9e  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_0x004b0aa1:
    // 004b0aa1  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b0aa3  80fa20                 +cmp dl, 0x20
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
    // 004b0aa6  740a                   -je 0x4b0ab2
    if (cpu.flags.zf)
    {
        goto L_0x004b0ab2;
    }
    // 004b0aa8  80fa09                 +cmp dl, 9
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
    // 004b0aab  7208                   -jb 0x4b0ab5
    if (cpu.flags.cf)
    {
        goto L_0x004b0ab5;
    }
    // 004b0aad  80fa0d                 +cmp dl, 0xd
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
    // 004b0ab0  7703                   -ja 0x4b0ab5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b0ab5;
    }
L_0x004b0ab2:
    // 004b0ab2  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b0ab3  ebec                   -jmp 0x4b0aa1
    goto L_0x004b0aa1;
L_0x004b0ab5:
    // 004b0ab5  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b0ab8  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 004b0aba  80fa2b                 +cmp dl, 0x2b
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
    // 004b0abd  7407                   -je 0x4b0ac6
    if (cpu.flags.zf)
    {
        goto L_0x004b0ac6;
    }
    // 004b0abf  80fa2d                 +cmp dl, 0x2d
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
    // 004b0ac2  7504                   -jne 0x4b0ac8
    if (!cpu.flags.zf)
    {
        goto L_0x004b0ac8;
    }
    // 004b0ac4  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x004b0ac6:
    // 004b0ac6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004b0ac8:
    // 004b0ac8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b0aca  b630                   -mov dh, 0x30
    cpu.dh = 48 /*0x30*/;
    // 004b0acc  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
L_0x004b0acf:
    // 004b0acf  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b0ad1  40                     -inc eax
    (cpu.eax)++;
    // 004b0ad2  80fa2e                 +cmp dl, 0x2e
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
    // 004b0ad5  750a                   -jne 0x4b0ae1
    if (!cpu.flags.zf)
    {
        goto L_0x004b0ae1;
    }
    // 004b0ad7  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 004b0ada  752d                   -jne 0x4b0b09
    if (!cpu.flags.zf)
    {
        goto L_0x004b0b09;
    }
    // 004b0adc  80c908                 +or cl, 8
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004b0adf  ebee                   -jmp 0x4b0acf
    goto L_0x004b0acf;
L_0x004b0ae1:
    // 004b0ae1  80fa30                 +cmp dl, 0x30
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
    // 004b0ae4  7223                   -jb 0x4b0b09
    if (cpu.flags.cf)
    {
        goto L_0x004b0b09;
    }
    // 004b0ae6  80fa39                 +cmp dl, 0x39
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
    // 004b0ae9  771e                   -ja 0x4b0b09
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b0b09;
    }
    // 004b0aeb  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 004b0aee  7403                   -je 0x4b0af3
    if (cpu.flags.zf)
    {
        goto L_0x004b0af3;
    }
    // 004b0af0  ff45e4                 -inc dword ptr [ebp - 0x1c]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */))++;
L_0x004b0af3:
    // 004b0af3  08d6                   -or dh, dl
    cpu.dh |= x86::reg8(x86::sreg8(cpu.dl));
    // 004b0af5  80fe30                 +cmp dh, 0x30
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
    // 004b0af8  740a                   -je 0x4b0b04
    if (cpu.flags.zf)
    {
        goto L_0x004b0b04;
    }
    // 004b0afa  83fb13                 +cmp ebx, 0x13
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
    // 004b0afd  7d04                   -jge 0x4b0b03
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b0b03;
    }
    // 004b0aff  88542bc0               -mov byte ptr [ebx + ebp - 0x40], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-64) /* -0x40 */ + cpu.ebp * 1) = cpu.dl;
L_0x004b0b03:
    // 004b0b03  43                     -inc ebx
    (cpu.ebx)++;
L_0x004b0b04:
    // 004b0b04  80c904                 +or cl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004b0b07  ebc6                   -jmp 0x4b0acf
    goto L_0x004b0acf;
L_0x004b0b09:
    // 004b0b09  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004b0b0b  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004b0b0e  0f8465000000           -je 0x4b0b79
    if (cpu.flags.zf)
    {
        goto L_0x004b0b79;
    }
    // 004b0b14  80fa65                 +cmp dl, 0x65
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
    // 004b0b17  7405                   -je 0x4b0b1e
    if (cpu.flags.zf)
    {
        goto L_0x004b0b1e;
    }
    // 004b0b19  80fa45                 +cmp dl, 0x45
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
    // 004b0b1c  7557                   -jne 0x4b0b75
    if (!cpu.flags.zf)
    {
        goto L_0x004b0b75;
    }
L_0x004b0b1e:
    // 004b0b1e  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004b0b21  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax);
    // 004b0b23  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004b0b26  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b0b29  80fd2b                 +cmp ch, 0x2b
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
    // 004b0b2c  7408                   -je 0x4b0b36
    if (cpu.flags.zf)
    {
        goto L_0x004b0b36;
    }
    // 004b0b2e  80fd2d                 +cmp ch, 0x2d
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
    // 004b0b31  7505                   -jne 0x4b0b38
    if (!cpu.flags.zf)
    {
        goto L_0x004b0b38;
    }
    // 004b0b33  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004b0b36:
    // 004b0b36  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004b0b38:
    // 004b0b38  80e1fb                 -and cl, 0xfb
    cpu.cl &= x86::reg8(x86::sreg8(251 /*0xfb*/));
L_0x004b0b3b:
    // 004b0b3b  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b0b3d  80fa30                 +cmp dl, 0x30
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
    // 004b0b40  7222                   -jb 0x4b0b64
    if (cpu.flags.cf)
    {
        goto L_0x004b0b64;
    }
    // 004b0b42  80fa39                 +cmp dl, 0x39
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
    // 004b0b45  771d                   -ja 0x4b0b64
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b0b64;
    }
    // 004b0b47  81fee8030000           +cmp esi, 0x3e8
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
    // 004b0b4d  7d0f                   -jge 0x4b0b5e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b0b5e;
    }
    // 004b0b4f  6bf60a                 -imul esi, esi, 0xa
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004b0b52  8975ec                 -mov dword ptr [ebp - 0x14], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.esi;
    // 004b0b55  0fb6f2                 -movzx esi, dl
    cpu.esi = x86::reg32(cpu.dl);
    // 004b0b58  0375ec                 -add esi, dword ptr [ebp - 0x14]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 004b0b5b  83ee30                 -sub esi, 0x30
    (cpu.esi) -= x86::reg32(x86::sreg32(48 /*0x30*/));
L_0x004b0b5e:
    // 004b0b5e  80c904                 +or cl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004b0b61  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b0b62  ebd7                   -jmp 0x4b0b3b
    goto L_0x004b0b3b;
L_0x004b0b64:
    // 004b0b64  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 004b0b67  7402                   -je 0x4b0b6b
    if (cpu.flags.zf)
    {
        goto L_0x004b0b6b;
    }
    // 004b0b69  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
L_0x004b0b6b:
    // 004b0b6b  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004b0b6e  7506                   -jne 0x4b0b76
    if (!cpu.flags.zf)
    {
        goto L_0x004b0b76;
    }
    // 004b0b70  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0b73  eb01                   -jmp 0x4b0b76
    goto L_0x004b0b76;
L_0x004b0b75:
    // 004b0b75  48                     -dec eax
    (cpu.eax)--;
L_0x004b0b76:
    // 004b0b76  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_0x004b0b79:
    // 004b0b79  837de800               +cmp dword ptr [ebp - 0x18], 0
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
    // 004b0b7d  7408                   -je 0x4b0b87
    if (cpu.flags.zf)
    {
        goto L_0x004b0b87;
    }
    // 004b0b7f  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0b82  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b0b85  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004b0b87:
    // 004b0b87  2b75e4                 -sub esi, dword ptr [ebp - 0x1c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */)));
    // 004b0b8a  83fb13                 +cmp ebx, 0x13
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
    // 004b0b8d  7e0a                   -jle 0x4b0b99
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0b99;
    }
    // 004b0b8f  83eb13                 -sub ebx, 0x13
    (cpu.ebx) -= x86::reg32(x86::sreg32(19 /*0x13*/));
    // 004b0b92  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b0b94  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
L_0x004b0b99:
    // 004b0b99  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b0b9b  7e0b                   -jle 0x4b0ba8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0ba8;
    }
    // 004b0b9d  807c2bbf30             +cmp byte ptr [ebx + ebp - 0x41], 0x30
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
    // 004b0ba2  7504                   -jne 0x4b0ba8
    if (!cpu.flags.zf)
    {
        goto L_0x004b0ba8;
    }
    // 004b0ba4  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b0ba5  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b0ba6  ebf1                   -jmp 0x4b0b99
    goto L_0x004b0b99;
L_0x004b0ba8:
    // 004b0ba8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b0baa  7511                   -jne 0x4b0bbd
    if (!cpu.flags.zf)
    {
        goto L_0x004b0bbd;
    }
    // 004b0bac  66c747080000           -mov word ptr [edi + 8], 0
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004b0bb2  895f04                 -mov dword ptr [edi + 4], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b0bb5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b0bb7  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 004b0bb9  31f8                   +xor eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004b0bbb  eb5f                   -jmp 0x4b0c1c
    goto L_0x004b0c1c;
L_0x004b0bbd:
    // 004b0bbd  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004b0bbf  8d45c0                 -lea eax, [ebp - 0x40]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004b0bc2  88542bc0               -mov byte ptr [ebx + ebp - 0x40], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-64) /* -0x40 */ + cpu.ebp * 1) = cpu.dl;
    // 004b0bc6  8d55d4                 -lea edx, [ebp - 0x2c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004b0bc9  e8f4240000             -call 0x4b30c2
    cpu.esp -= 4;
    sub_4b30c2(app, cpu);
    if (cpu.terminate) return;
    // 004b0bce  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b0bd0  740a                   -je 0x4b0bdc
    if (cpu.flags.zf)
    {
        goto L_0x004b0bdc;
    }
    // 004b0bd2  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004b0bd5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b0bd7  e8a4f4ffff             -call 0x4b0080
    cpu.esp -= 4;
    sub_4b0080(app, cpu);
    if (cpu.terminate) return;
L_0x004b0bdc:
    // 004b0bdc  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 004b0bdf  7404                   -je 0x4b0be5
    if (cpu.flags.zf)
    {
        goto L_0x004b0be5;
    }
    // 004b0be1  804ddd80               -or byte ptr [ebp - 0x23], 0x80
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-35) /* -0x23 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x004b0be5:
    // 004b0be5  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004b0be8  66894708               -mov word ptr [edi + 8], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 004b0bec  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004b0bef  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b0bf2  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004b0bf5  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004b0bf7  8d441eff               -lea eax, [esi + ebx - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */ + cpu.ebx * 1);
    // 004b0bfb  3d34010000             +cmp eax, 0x134
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
    // 004b0c00  7e07                   -jle 0x4b0c09
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0c09;
    }
    // 004b0c02  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004b0c07  eb13                   -jmp 0x4b0c1c
    goto L_0x004b0c1c;
L_0x004b0c09:
    // 004b0c09  3dccfeffff             +cmp eax, 0xfffffecc
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
    // 004b0c0e  7d07                   -jge 0x4b0c17
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b0c17;
    }
    // 004b0c10  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004b0c15  eb05                   -jmp 0x4b0c1c
    goto L_0x004b0c1c;
L_0x004b0c17:
    // 004b0c17  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004b0c1c:
    // 004b0c1c  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b0c1f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0c20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0c21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0c22  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0c23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b0c24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0c24  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0c25  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b0c27  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0c28  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b0c2b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b0c2d  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0c30  e85bfeffff             -call 0x4b0a90
    cpu.esp -= 4;
    sub_4b0a90(app, cpu);
    if (cpu.terminate) return;
    // 004b0c35  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0c37  7508                   -jne 0x4b0c41
    if (!cpu.flags.zf)
    {
        goto L_0x004b0c41;
    }
    // 004b0c39  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x004b0c3c:
    // 004b0c3c  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004b0c3f  eb59                   -jmp 0x4b0c9a
    goto L_0x004b0c9a;
L_0x004b0c41:
    // 004b0c41  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b0c44  80e47f                 -and ah, 0x7f
    cpu.ah &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004b0c47  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004b0c4c  3dff430000             +cmp eax, 0x43ff
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
    // 004b0c51  7c27                   -jl 0x4b0c7a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0c7a;
    }
    // 004b0c53  e8fd4ffeff             -call 0x495c55
    cpu.esp -= 4;
    sub_495c55(app, cpu);
    if (cpu.terminate) return;
    // 004b0c58  f645f180               +test byte ptr [ebp - 0xf], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */) & 128 /*0x80*/));
    // 004b0c5c  740d                   -je 0x4b0c6b
    if (cpu.flags.zf)
    {
        goto L_0x004b0c6b;
    }
    // 004b0c5e  dd05d4fc4b00           +fld qword ptr [0x4bfcd4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4979924) /* 0x4bfcd4 */)));
    // 004b0c64  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004b0c66  dd5df4                 +fstp qword ptr [ebp - 0xc]
    app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0c69  eb2f                   -jmp 0x4b0c9a
    goto L_0x004b0c9a;
L_0x004b0c6b:
    // 004b0c6b  a1d4fc4b00             -mov eax, dword ptr [0x4bfcd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4979924) /* 0x4bfcd4 */);
    // 004b0c70  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004b0c73  a1d8fc4b00             -mov eax, dword ptr [0x4bfcd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4979928) /* 0x4bfcd8 */);
    // 004b0c78  ebc2                   -jmp 0x4b0c3c
    goto L_0x004b0c3c;
L_0x004b0c7a:
    // 004b0c7a  3dcd3b0000             +cmp eax, 0x3bcd
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
    // 004b0c7f  7d0f                   -jge 0x4b0c90
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b0c90;
    }
    // 004b0c81  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b0c83  e8cd4ffeff             -call 0x495c55
    cpu.esp -= 4;
    sub_495c55(app, cpu);
    if (cpu.terminate) return;
    // 004b0c88  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004b0c8b  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004b0c8e  eb0a                   -jmp 0x4b0c9a
    goto L_0x004b0c9a;
L_0x004b0c90:
    // 004b0c90  8d55f4                 -lea edx, [ebp - 0xc]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b0c93  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0c96  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0c98  dd1a                   -fstp qword ptr [edx]
    app->getMemory<double>(cpu.edx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004b0c9a:
    // 004b0c9a  dd45f4                 -fld qword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 004b0c9d  8d65fc                 -lea esp, [ebp - 4]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b0ca0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0ca1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0ca2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b0cb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0cb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0cb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0cb2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b0cb4  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b0cb6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b0cb8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b0cba  e81183fdff             -call 0x488fd0
    cpu.esp -= 4;
    sub_488fd0(app, cpu);
    if (cpu.terminate) return;
    // 004b0cbf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0cc1  7f59                   -jg 0x4b0d1c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b0d1c;
    }
    // 004b0cc3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b0cc5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b0cc7  e80483fdff             -call 0x488fd0
    cpu.esp -= 4;
    sub_488fd0(app, cpu);
    if (cpu.terminate) return;
    // 004b0ccc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b0cce  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x004b0cd0:
    // 004b0cd0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0cd2  81fa00010000           +cmp edx, 0x100
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
    // 004b0cd8  7e07                   -jle 0x4b0ce1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0ce1;
    }
    // 004b0cda  b800020000             -mov eax, 0x200
    cpu.eax = 512 /*0x200*/;
    // 004b0cdf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x004b0ce1:
    // 004b0ce1  3d80000000             +cmp eax, 0x80
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
    // 004b0ce6  7e45                   -jle 0x4b0d2d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0d2d;
    }
    // 004b0ce8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b0cea  7e3d                   -jle 0x4b0d29
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0d29;
    }
L_0x004b0cec:
    // 004b0cec  c0e407                 +shl ah, 7
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
    // 004b0cef  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b0cf1  00e4                   +add ah, ah
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
    // 004b0cf3  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004b0cf5  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0cf7  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b0cfc  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0cfe  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
L_0x004b0d05:
    // 004b0d05  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b0d07  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b0d09  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b0d0b  c1e30f                 -shl ebx, 0xf
    cpu.ebx <<= 15 /*0xf*/ % 32;
    // 004b0d0e  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 004b0d10  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b0d12  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b0d14  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b0d17  f7f9                   +idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b0d19  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0d1a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0d1b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0d1c:
    // 004b0d1c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b0d1e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b0d20  e8ab82fdff             -call 0x488fd0
    cpu.esp -= 4;
    sub_488fd0(app, cpu);
    if (cpu.terminate) return;
    // 004b0d25  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b0d27  eba7                   -jmp 0x4b0cd0
    goto L_0x004b0cd0;
L_0x004b0d29:
    // 004b0d29  f7db                   +neg ebx
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
    // 004b0d2b  ebbf                   -jmp 0x4b0cec
    goto L_0x004b0cec;
L_0x004b0d2d:
    // 004b0d2d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b0d2f  7e23                   -jle 0x4b0d54
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0d54;
    }
L_0x004b0d31:
    // 004b0d31  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b0d33  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 004b0d39  c0e507                 +shl ch, 7
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
    // 004b0d3c  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b0d3e  00ed                   +add ch, ch
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
    // 004b0d40  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004b0d42  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0d44  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b0d49  29c8                   +sub eax, ecx
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
    // 004b0d4b  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 004b0d52  ebb1                   -jmp 0x4b0d05
    goto L_0x004b0d05;
L_0x004b0d54:
    // 004b0d54  f7d9                   +neg ecx
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
    // 004b0d56  ebd9                   -jmp 0x4b0d31
    goto L_0x004b0d31;
}

/* align: skip  */
void Application::sub_4b0d58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0d58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b0d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0d60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0d61  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0d62  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b0d66  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b0d68  7c3b                   -jl 0x4b0da5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0da5;
    }
L_0x004b0d6a:
    // 004b0d6a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b0d6c  7c3b                   -jl 0x4b0da9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0da9;
    }
L_0x004b0d6e:
    // 004b0d6e  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b0d71  39f2                   +cmp edx, esi
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
    // 004b0d73  7e02                   -jle 0x4b0d77
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0d77;
    }
    // 004b0d75  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x004b0d77:
    // 004b0d77  39f1                   +cmp ecx, esi
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
    // 004b0d79  7e02                   -jle 0x4b0d7d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0d7d;
    }
    // 004b0d7b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x004b0d7d:
    // 004b0d7d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b0d7f  7c2c                   -jl 0x4b0dad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0dad;
    }
L_0x004b0d81:
    // 004b0d81  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b0d83  7c2c                   -jl 0x4b0db1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0db1;
    }
L_0x004b0d85:
    // 004b0d85  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b0d88  39f3                   +cmp ebx, esi
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
    // 004b0d8a  7e02                   -jle 0x4b0d8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0d8e;
    }
    // 004b0d8c  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x004b0d8e:
    // 004b0d8e  39f7                   +cmp edi, esi
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
    // 004b0d90  7e02                   -jle 0x4b0d94
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0d94;
    }
    // 004b0d92  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x004b0d94:
    // 004b0d94  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004b0d97  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004b0d9a  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004b0d9d  897818                 -mov dword ptr [eax + 0x18], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004b0da0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0da1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0da2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004b0da5:
    // 004b0da5  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b0da7  ebc1                   -jmp 0x4b0d6a
    goto L_0x004b0d6a;
L_0x004b0da9:
    // 004b0da9  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004b0dab  ebc1                   -jmp 0x4b0d6e
    goto L_0x004b0d6e;
L_0x004b0dad:
    // 004b0dad  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004b0daf  ebd0                   -jmp 0x4b0d81
    goto L_0x004b0d81;
L_0x004b0db1:
    // 004b0db1  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004b0db3  ebd0                   -jmp 0x4b0d85
    goto L_0x004b0d85;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b0dc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0dc0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0dc1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0dc2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0dc3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b0dc6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b0dc8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b0dca  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b0dce  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004b0dd0  39d8                   +cmp eax, ebx
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
    // 004b0dd2  0f8f84000000           -jg 0x4b0e5c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b0e5c;
    }
L_0x004b0dd8:
    // 004b0dd8  39fd                   +cmp ebp, edi
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
    // 004b0dda  7d06                   -jge 0x4b0de2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b0de2;
    }
    // 004b0ddc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b0dde  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004b0de0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x004b0de2:
    // 004b0de2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b0de6  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b0de8  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b0dec  40                     -inc eax
    (cpu.eax)++;
    // 004b0ded  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004b0def  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b0df2  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b0df4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0df5  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004b0df7  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004b0dfc  48                     -dec eax
    (cpu.eax)--;
    // 004b0dfd  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b0e01  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b0e05  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0e07  47                     -inc edi
    (cpu.edi)++;
    // 004b0e08  e813c4fcff             -call 0x47d220
    cpu.esp -= 4;
    sub_47d220(app, cpu);
    if (cpu.terminate) return;
    // 004b0e0d  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b0e11  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b0e15  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b0e19  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0e1a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004b0e1c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004b0e21  e8fac3fcff             -call 0x47d220
    cpu.esp -= 4;
    sub_47d220(app, cpu);
    if (cpu.terminate) return;
    // 004b0e26  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b0e2a  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b0e2e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004b0e33  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0e34  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004b0e36  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0e38  e8e3c3fcff             -call 0x47d220
    cpu.esp -= 4;
    sub_47d220(app, cpu);
    if (cpu.terminate) return;
    // 004b0e3d  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b0e41  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004b0e46  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b0e49  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0e4a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0e4c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b0e4e  e8cdc3fcff             -call 0x47d220
    cpu.esp -= 4;
    sub_47d220(app, cpu);
    if (cpu.terminate) return;
    // 004b0e53  83c40c                 +add esp, 0xc
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
    // 004b0e56  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e59  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004b0e5c:
    // 004b0e5c  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b0e5e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b0e62  e971ffffff             -jmp 0x4b0dd8
    goto L_0x004b0dd8;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b0e70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0e70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0e71  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0e72  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004b0e78  8d842418010000         -lea eax, [esp + 0x118]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 004b0e7f  8d9c2400010000         -lea ebx, [esp + 0x100]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004b0e86  8b942414010000         -mov edx, dword ptr [esp + 0x114]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004b0e8d  89842400010000         -mov dword ptr [esp + 0x100], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 004b0e94  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b0e96  e87b27feff             -call 0x493616
    cpu.esp -= 4;
    sub_493616(app, cpu);
    if (cpu.terminate) return;
    // 004b0e9b  8b942410010000         -mov edx, dword ptr [esp + 0x110]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004b0ea2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b0ea4  e813000000             -call 0x4b0ebc
    cpu.esp -= 4;
    sub_4b0ebc(app, cpu);
    if (cpu.terminate) return;
    // 004b0ea9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b0eab  89942400010000         -mov dword ptr [esp + 0x100], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edx;
    // 004b0eb2  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004b0eb8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0eb9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0eba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b0ebc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0ebc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0ebd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0ebe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0ebf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0ec0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b0ec2  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b0ec4  e84b54fcff             -call 0x476314
    cpu.esp -= 4;
    sub_476314(app, cpu);
    if (cpu.terminate) return;
    // 004b0ec9  8b15e4814c00           -mov edx, dword ptr [0x4c81e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5013988) /* 0x4c81e4 */);
    // 004b0ecf  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b0ed1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0ed3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b0ed6  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b0ed8  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004b0eda  8b3dcca74c00           -mov edi, dword ptr [0x4ca7cc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5023692) /* 0x4ca7cc */);
    // 004b0ee0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b0ee2  8b35d0a74c00           -mov esi, dword ptr [0x4ca7d0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023696) /* 0x4ca7d0 */);
    // 004b0ee8  e86ba0fcff             -call 0x47af58
    cpu.esp -= 4;
    sub_47af58(app, cpu);
    if (cpu.terminate) return;
    // 004b0eed  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b0eef  e80498fcff             -call 0x47a6f8
    cpu.esp -= 4;
    sub_47a6f8(app, cpu);
    if (cpu.terminate) return;
    // 004b0ef4  893dcca74c00           -mov dword ptr [0x4ca7cc], edi
    app->getMemory<x86::reg32>(x86::reg32(5023692) /* 0x4ca7cc */) = cpu.edi;
    // 004b0efa  8935d0a74c00           -mov dword ptr [0x4ca7d0], esi
    app->getMemory<x86::reg32>(x86::reg32(5023696) /* 0x4ca7d0 */) = cpu.esi;
    // 004b0f00  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b0f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0f10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0f11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0f12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0f13  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b0f16  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b0f19  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0f1a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b0f1c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b0f1e  e83dfeffff             -call 0x4b0d60
    cpu.esp -= 4;
    sub_4b0d60(app, cpu);
    if (cpu.terminate) return;
    // 004b0f23  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f24  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f25  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b0f28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0f28  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b0f2a  781e                   -js 0x4b0f4a
    if (cpu.flags.sf)
    {
        goto L_0x004b0f4a;
    }
    // 004b0f2c  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004b0f2e  7806                   -js 0x4b0f36
    if (cpu.flags.sf)
    {
        goto L_0x004b0f36;
    }
    // 004b0f30  e848000000             -call 0x4b0f7d
    cpu.esp -= 4;
    sub_4b0f7d(app, cpu);
    if (cpu.terminate) return;
    // 004b0f35  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0f36:
    // 004b0f36  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b0f38  f7db                   +neg ebx
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
    // 004b0f3a  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004b0f3d  e83b000000             -call 0x4b0f7d
    cpu.esp -= 4;
    sub_4b0f7d(app, cpu);
    if (cpu.terminate) return;
    // 004b0f42  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004b0f44  f7d8                   +neg eax
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
    // 004b0f46  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004b0f49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0f4a:
    // 004b0f4a  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004b0f4c  f7d8                   +neg eax
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
    // 004b0f4e  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004b0f51  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004b0f53  7914                   -jns 0x4b0f69
    if (!cpu.flags.sf)
    {
        goto L_0x004b0f69;
    }
    // 004b0f55  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b0f57  f7db                   +neg ebx
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
    // 004b0f59  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004b0f5c  e81c000000             -call 0x4b0f7d
    cpu.esp -= 4;
    sub_4b0f7d(app, cpu);
    if (cpu.terminate) return;
    // 004b0f61  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b0f63  f7db                   +neg ebx
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
    // 004b0f65  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004b0f68  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0f69:
    // 004b0f69  e80f000000             -call 0x4b0f7d
    cpu.esp -= 4;
    sub_4b0f7d(app, cpu);
    if (cpu.terminate) return;
    // 004b0f6e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b0f70  f7db                   +neg ebx
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
    // 004b0f72  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004b0f75  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004b0f77  f7d8                   +neg eax
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
    // 004b0f79  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004b0f7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b0f7d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0f7d  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004b0f7f  751a                   -jne 0x4b0f9b
    if (!cpu.flags.zf)
    {
        goto L_0x004b0f9b;
    }
    // 004b0f81  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b0f82  7416                   -je 0x4b0f9a
    if (cpu.flags.zf)
    {
        goto L_0x004b0f9a;
    }
    // 004b0f84  43                     -inc ebx
    (cpu.ebx)++;
    // 004b0f85  39d3                   +cmp ebx, edx
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
    // 004b0f87  7709                   -ja 0x4b0f92
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b0f92;
    }
    // 004b0f89  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b0f8b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0f8d  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b0f8f  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b0f91  91                     -xchg ecx, eax
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.eax;
        cpu.eax = tmp;
    }
L_0x004b0f92:
    // 004b0f92  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b0f94  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b0f96  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b0f98  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004b0f9a:
    // 004b0f9a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0f9b:
    // 004b0f9b  39d1                   +cmp ecx, edx
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
    // 004b0f9d  721c                   -jb 0x4b0fbb
    if (cpu.flags.cf)
    {
        goto L_0x004b0fbb;
    }
    // 004b0f9f  7512                   -jne 0x4b0fb3
    if (!cpu.flags.zf)
    {
        goto L_0x004b0fb3;
    }
    // 004b0fa1  39c3                   +cmp ebx, eax
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
    // 004b0fa3  770e                   -ja 0x4b0fb3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b0fb3;
    }
    // 004b0fa5  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b0fa7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b0fa9  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0fab  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b0fad  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b0fb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0fb3:
    // 004b0fb3  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0fb5  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b0fb7  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004b0fb8  87ca                   -xchg edx, ecx
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.ecx;
        cpu.ecx = tmp;
    }
    // 004b0fba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0fbb:
    // 004b0fbb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0fbc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0fbd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0fbe  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b0fc0  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004b0fc2  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004b0fc4:
    // 004b0fc4  01db                   +add ebx, ebx
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
    // 004b0fc6  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0fc8  7213                   -jb 0x4b0fdd
    if (cpu.flags.cf)
    {
        goto L_0x004b0fdd;
    }
    // 004b0fca  45                     -inc ebp
    (cpu.ebp)++;
    // 004b0fcb  39d1                   +cmp ecx, edx
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
    // 004b0fcd  72f5                   -jb 0x4b0fc4
    if (cpu.flags.cf)
    {
        goto L_0x004b0fc4;
    }
    // 004b0fcf  7704                   -ja 0x4b0fd5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b0fd5;
    }
    // 004b0fd1  39c3                   +cmp ebx, eax
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
    // 004b0fd3  76ef                   -jbe 0x4b0fc4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b0fc4;
    }
L_0x004b0fd5:
    // 004b0fd5  f8                     +clc 
    cpu.flags.cf = 0;
L_0x004b0fd6:
    // 004b0fd6  11f6                   +adc esi, esi
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0fd8  11ff                   +adc edi, edi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0fda  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b0fdb  7822                   -js 0x4b0fff
    if (cpu.flags.sf)
    {
        goto L_0x004b0fff;
    }
L_0x004b0fdd:
    // 004b0fdd  d1d9                   +rcr ecx, 1
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004b0fdf  d1db                   -rcr ebx, 1
    {
        x86::reg32& op = cpu.ebx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004b0fe1  29d8                   +sub eax, ebx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0fe3  19ca                   +sbb edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0fe5  f5                     +cmc 
    cpu.flags.cf ^= 1;
    // 004b0fe6  72ee                   -jb 0x4b0fd6
    if (cpu.flags.cf)
    {
        goto L_0x004b0fd6;
    }
L_0x004b0fe8:
    // 004b0fe8  01f6                   +add esi, esi
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0fea  11ff                   +adc edi, edi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0fec  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b0fed  780c                   -js 0x4b0ffb
    if (cpu.flags.sf)
    {
        goto L_0x004b0ffb;
    }
    // 004b0fef  d1e9                   +shr ecx, 1
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
    // 004b0ff1  d1db                   -rcr ebx, 1
    {
        x86::reg32& op = cpu.ebx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004b0ff3  01d8                   +add eax, ebx
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
    // 004b0ff5  11ca                   +adc edx, ecx
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
    // 004b0ff7  73ef                   -jae 0x4b0fe8
    if (!cpu.flags.cf)
    {
        goto L_0x004b0fe8;
    }
    // 004b0ff9  ebdb                   -jmp 0x4b0fd6
    goto L_0x004b0fd6;
L_0x004b0ffb:
    // 004b0ffb  01d8                   +add eax, ebx
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
    // 004b0ffd  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
L_0x004b0fff:
    // 004b0fff  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b1001  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b1003  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b1005  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004b1007  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1008  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1009  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b100a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b1010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b1010  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b1013  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b1014(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b1014  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b1015  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1018  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b101a  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b101d  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b1020  3b4508                 +cmp eax, dword ptr [ebp + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1023  7328                   -jae 0x4b104d
    if (!cpu.flags.cf)
    {
        goto L_0x004b104d;
    }
    // 004b1025  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b1026  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b102a  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004b102d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b102f  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b1032  895504                 -mov dword ptr [ebp + 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b1035  39ca                   +cmp edx, ecx
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
    // 004b1037  731e                   -jae 0x4b1057
    if (!cpu.flags.cf)
    {
        goto L_0x004b1057;
    }
    // 004b1039  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b103c  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b103f  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b1041  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b1043  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b1045  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1047  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1048  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b104b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b104c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b104d:
    // 004b104d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b1052  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1055  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1056  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1057:
    // 004b1057  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b1058  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b1059  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b105b  8b7d00                 -mov edi, dword ptr [ebp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b105e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1060  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b1063  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b1065  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b1067  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b1069  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b106b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b106d  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b106f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b1071  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b1072  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b1074  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b1077  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b1079  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b107b  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b107e  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b1080  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1081  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b1085  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b1087  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b108a  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b108c  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b108e  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b1090  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b1092  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b1094  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b1096  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1098  e82231fdff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 004b109d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b109e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b109f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b10a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b10a2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b10a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b10a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b10a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b10a8  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b10af  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004b10b1  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 004b10b3  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b10b6  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004b10b9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b10bd  c70014104b00           -mov dword ptr [eax], 0x4b1014
    app->getMemory<x86::reg32>(cpu.eax) = 4919316 /*0x4b1014*/;
    // 004b10c3  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b10c7  c70010104b00           -mov dword ptr [eax], 0x4b1010
    app->getMemory<x86::reg32>(cpu.eax) = 4919312 /*0x4b1010*/;
    // 004b10cd  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004b10d2  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b10e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b10e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b10e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b10e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b10e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b10e4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b10e7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004b10e9  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b10eb  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004b10ee  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b10f1  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b10f4  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004b10f6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b10f8  39f1                   +cmp ecx, esi
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
    // 004b10fa  765c                   -jbe 0x4b1158
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b1158;
    }
L_0x004b10fc:
    // 004b10fc  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b10fe  7e69                   -jle 0x4b1169
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b1169;
    }
    // 004b1100  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004b1103  2b5a04                 -sub ebx, dword ptr [edx + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b1106  43                     -inc ebx
    (cpu.ebx)++;
    // 004b1107  39dd                   +cmp ebp, ebx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1109  7d02                   -jge 0x4b110d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b110d;
    }
    // 004b110b  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
L_0x004b110d:
    // 004b110d  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b110f  8a4a10                 -mov cl, byte ptr [edx + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004b1112  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004b1115  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b1117  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b1119  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004b111b  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004b111e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1120  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b1122  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b1124  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b1125  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b1127  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b112a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b112c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b112e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b1131  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b1133  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1134  015a04                 -add dword ptr [edx + 4], ebx
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1137  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b1139  8a4a10                 -mov cl, byte ptr [edx + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004b113c  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b113e  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1140  8d3407                 -lea esi, [edi + eax]
    cpu.esi = x86::reg32(cpu.edi + cpu.eax * 1);
    // 004b1143  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004b1146  8b7a0c                 -mov edi, dword ptr [edx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004b1149  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004b114c  39f8                   +cmp eax, edi
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
    // 004b114e  76ac                   -jbe 0x4b10fc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b10fc;
    }
    // 004b1150  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b1153  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b1156  eba4                   -jmp 0x4b10fc
    goto L_0x004b10fc;
L_0x004b1158:
    // 004b1158  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b115b  8a4810                 -mov cl, byte ptr [eax + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004b115e  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004b1160  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b1162  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b1164  890b                   -mov dword ptr [ebx], ecx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 004b1166  016804                 -add dword ptr [eax + 4], ebp
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)) += x86::reg32(x86::sreg32(cpu.ebp));
L_0x004b1169:
    // 004b1169  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b116b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b116e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b116f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1170  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1171  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1172  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b1174(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b1174  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b117b  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004b117d  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b1180  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b1184  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004b1187  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004b1189  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004b118c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b1190  c700e0104b00           -mov dword ptr [eax], 0x4b10e0
    app->getMemory<x86::reg32>(cpu.eax) = 4919520 /*0x4b10e0*/;
    // 004b1196  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 004b119b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4b11a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b11a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b11a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b11a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b11a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b11a4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b11a7  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b11ab  833800                 +cmp dword ptr [eax], 0
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
    // 004b11ae  0f8499000000           -je 0x4b124d
    if (cpu.flags.zf)
    {
        goto L_0x004b124d;
    }
    // 004b11b4  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b11b6  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b11ba  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b11be  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b11c1  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b11c4  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b11c6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b11c8  39f2                   +cmp edx, esi
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
    // 004b11ca  0f8e8a000000           -jle 0x4b125a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b125a;
    }
    // 004b11d0  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b11d3  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004b11d6:
    // 004b11d6  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004b11db  0f8e8e000000           -jle 0x4b126f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b126f;
    }
    // 004b11e1  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b11e4  3b4504                 +cmp eax, dword ptr [ebp + 4]
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
    // 004b11e7  0f8d8c000000           -jge 0x4b1279
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b1279;
    }
L_0x004b11ed:
    // 004b11ed  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004b11f0  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b11f3  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b11f7  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b11f9  39f2                   +cmp edx, esi
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
    // 004b11fb  0f8fc1000000           -jg 0x4b12c2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b12c2;
    }
L_0x004b1201:
    // 004b1201  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b1205  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b1207  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b120a  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b120d  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b1210  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004b1212  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b1214  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b1216  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b1218  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b1219  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b121b  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b121e  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b1220  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b1222  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b1225  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b1227  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1228  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b122c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b122e  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b1231  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b1234  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b1236  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b1238  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b123a  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b123e  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b1242  01c1                   +add ecx, eax
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
    // 004b1244  897d08                 -mov dword ptr [ebp + 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004b1247  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b124b  eb89                   -jmp 0x4b11d6
    goto L_0x004b11d6;
L_0x004b124d:
    // 004b124d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b1252  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b1255  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1256  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1257  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1258  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1259  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b125a:
    // 004b125a  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b125d  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b1260  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b1262  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b1264  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b1266  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b1268  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b126c  015008                 -add dword ptr [eax + 8], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004b126f:
    // 004b126f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1271  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b1274  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1275  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1276  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1277  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1278  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1279:
    // 004b1279  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b127c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b127e  ff15b4a14c00           -call dword ptr [0x4ca1b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022132) /* 0x4ca1b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b1284  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b1286  750e                   -jne 0x4b1296
    if (!cpu.flags.zf)
    {
        goto L_0x004b1296;
    }
    // 004b1288  837d0000               +cmp dword ptr [ebp], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b128c  7408                   -je 0x4b1296
    if (cpu.flags.zf)
    {
        goto L_0x004b1296;
    }
    // 004b128e  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b1291  e957ffffff             -jmp 0x4b11ed
    goto L_0x004b11ed;
L_0x004b1296:
    // 004b1296  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b129a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b129e  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b12a1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b12a3  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004b12a5  e8152ffdff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 004b12aa  c7450800000000         -mov dword ptr [ebp + 8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004b12b1  c7450400000000         -mov dword ptr [ebp + 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b12b8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b12ba  83c40c                 +add esp, 0xc
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
    // 004b12bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b12be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b12bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b12c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b12c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b12c2:
    // 004b12c2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b12c4  e938ffffff             -jmp 0x4b1201
    goto L_0x004b1201;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b12cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b12cc  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 004b12d2  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b12d9  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004b12db  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004b12e2  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004b12e5  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004b12ea  c703a0114b00           -mov dword ptr [ebx], 0x4b11a0
    app->getMemory<x86::reg32>(cpu.ebx) = 4919712 /*0x4b11a0*/;
    // 004b12f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b1300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b1300  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b1303  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b1304(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b1304  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b1305  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b1306  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b1307  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b1309  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b130c  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b130f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b1311  39ca                   +cmp edx, ecx
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
    // 004b1313  7338                   -jae 0x4b134d
    if (!cpu.flags.cf)
    {
        goto L_0x004b134d;
    }
    // 004b1315  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b1316  8d0c32                 -lea ecx, [edx + esi]
    cpu.ecx = x86::reg32(cpu.edx + cpu.esi * 1);
    // 004b1319  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b131c  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004b131e  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b1321  39cf                   +cmp edi, ecx
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
    // 004b1323  734d                   -jae 0x4b1372
    if (!cpu.flags.cf)
    {
        goto L_0x004b1372;
    }
    // 004b1325  83781400               +cmp dword ptr [eax + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1329  742b                   -je 0x4b1356
    if (cpu.flags.zf)
    {
        goto L_0x004b1356;
    }
    // 004b132b  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b132d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b132e  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b1331  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b1333  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004b1335  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1337  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b133a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b133b  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b133d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b133e  e8251e0000             -call 0x4b3168
    cpu.esp -= 4;
    sub_4b3168(app, cpu);
    if (cpu.terminate) return;
L_0x004b1343:
    // 004b1343  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b1346  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1348  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1349  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b134a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b134b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b134c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b134d:
    // 004b134d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b1352  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1353  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1354  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1355  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1356:
    // 004b1356  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b1358  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b135b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b135d  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b135f  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004b1361  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b1362  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1364  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b1367  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b1368  d3e6                   +shl esi, cl
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
    // 004b136a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b136b  e8641e0000             -call 0x4b31d4
    cpu.esp -= 4;
    sub_4b31d4(app, cpu);
    if (cpu.terminate) return;
    // 004b1370  ebd1                   -jmp 0x4b1343
    goto L_0x004b1343;
L_0x004b1372:
    // 004b1372  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004b1374  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004b1377  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1379  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b137b  7440                   -je 0x4b13bd
    if (cpu.flags.zf)
    {
        goto L_0x004b13bd;
    }
    // 004b137d  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b137f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b1380  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b1383  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004b1385  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b1387  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1389  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b138c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b138e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b138f  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b1391  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b1392  e8d11d0000             -call 0x4b3168
    cpu.esp -= 4;
    sub_4b3168(app, cpu);
    if (cpu.terminate) return;
L_0x004b1397:
    // 004b1397  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b139a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b139c  8a4d10                 -mov cl, byte ptr [ebp + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b139f  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b13a1  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004b13a3  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004b13a5  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b13a7  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b13a9  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b13ab  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b13ad  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b13af  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b13b1  e8092efdff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 004b13b6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b13b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b13b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b13ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b13bb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b13bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b13bd:
    // 004b13bd  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b13bf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b13c0  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b13c3  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004b13c5  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b13c7  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b13c9  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b13cc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b13ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b13cf  d3e0                   +shl eax, cl
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
    // 004b13d1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b13d2  e8fd1d0000             -call 0x4b31d4
    cpu.esp -= 4;
    sub_4b31d4(app, cpu);
    if (cpu.terminate) return;
    // 004b13d7  ebbe                   -jmp 0x4b1397
    goto L_0x004b1397;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b13dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b13dc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b13dd  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b13e1  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b13e8  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004b13ea  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b13ed  8d1431                 -lea edx, [ecx + esi]
    cpu.edx = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 004b13f0  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004b13f3  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004b13f6  8d5602                 -lea edx, [esi + 2]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004b13f9  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004b13fc  897018                 -mov dword ptr [eax + 0x18], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004b13ff  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b1403  c70004134b00           -mov dword ptr [eax], 0x4b1304
    app->getMemory<x86::reg32>(cpu.eax) = 4920068 /*0x4b1304*/;
    // 004b1409  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b140d  c70000134b00           -mov dword ptr [eax], 0x4b1300
    app->getMemory<x86::reg32>(cpu.eax) = 4920064 /*0x4b1300*/;
    // 004b1413  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 004b1418  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1419  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4b1420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b1420  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b1421  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b1422  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b1423  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b1424  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b1426  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004b1428  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b142a  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b142d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b142f  7e5a                   -jle 0x4b148b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b148b;
    }
L_0x004b1431:
    // 004b1431  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b1434  2b4304                 -sub eax, dword ptr [ebx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 004b1437  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b143a  39f7                   +cmp edi, esi
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
    // 004b143c  7d02                   -jge 0x4b1440
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b1440;
    }
    // 004b143e  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x004b1440:
    // 004b1440  837b1800               +cmp dword ptr [ebx + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1444  744c                   -je 0x4b1492
    if (cpu.flags.zf)
    {
        goto L_0x004b1492;
    }
    // 004b1446  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b1449  8a4b10                 -mov cl, byte ptr [ebx + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b144c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b144e  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b1450  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b1451  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b1453  8a4b1c                 -mov cl, byte ptr [ebx + 0x1c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004b1456  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b1457  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b1459  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b145b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b145c  e8071d0000             -call 0x4b3168
    cpu.esp -= 4;
    sub_4b3168(app, cpu);
    if (cpu.terminate) return;
L_0x004b1461:
    // 004b1461  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b1464  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b1467  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b1469  8a4b14                 -mov cl, byte ptr [ebx + 0x14]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004b146c  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b146f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b1471  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b1473  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b1476  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b1478  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b147b  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b147d  39d0                   +cmp eax, edx
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
    // 004b147f  7606                   -jbe 0x4b1487
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b1487;
    }
    // 004b1481  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b1484  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004b1487:
    // 004b1487  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b1489  7fa6                   -jg 0x4b1431
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b1431;
    }
L_0x004b148b:
    // 004b148b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b148d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b148e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b148f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1490  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1491  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1492:
    // 004b1492  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b1495  8a4b10                 -mov cl, byte ptr [ebx + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b1498  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b149a  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004b149c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b149d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b149f  8a4b1c                 -mov cl, byte ptr [ebx + 0x1c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004b14a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b14a3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b14a5  d3e0                   +shl eax, cl
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
    // 004b14a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b14a8  e8271d0000             -call 0x4b31d4
    cpu.esp -= 4;
    sub_4b31d4(app, cpu);
    if (cpu.terminate) return;
    // 004b14ad  ebb2                   -jmp 0x4b1461
    goto L_0x004b1461;
}

/* align: skip 0x90 */
void Application::sub_4b14b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b14b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b14b1  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b14b5  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b14bc  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004b14be  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b14c1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b14c5  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004b14c8  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b14ca  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004b14cd  8d5602                 -lea edx, [esi + 2]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004b14d0  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004b14d3  89701c                 -mov dword ptr [eax + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 004b14d6  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b14da  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004b14dd  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b14e1  c70020144b00           -mov dword ptr [eax], 0x4b1420
    app->getMemory<x86::reg32>(cpu.eax) = 4920352 /*0x4b1420*/;
    // 004b14e7  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 004b14ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b14ed  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4b14f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b14f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b14f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b14f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b14f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b14f4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b14f7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b14f9  833800                 +cmp dword ptr [eax], 0
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
    // 004b14fc  746e                   -je 0x4b156c
    if (cpu.flags.zf)
    {
        goto L_0x004b156c;
    }
    // 004b14fe  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b1500  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b1503  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b1506  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b1508  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b150a  39ca                   +cmp edx, ecx
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
    // 004b150c  7e6b                   -jle 0x4b1579
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b1579;
    }
    // 004b150e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1511  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004b1514:
    // 004b1514  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b1516  0f8e84000000           -jle 0x4b15a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b15a0;
    }
    // 004b151c  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b151f  3b4604                 +cmp eax, dword ptr [esi + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1522  0f8dad000000           -jge 0x4b15d5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b15d5;
    }
L_0x004b1528:
    // 004b1528  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b152b  2b5e08                 -sub ebx, dword ptr [esi + 8]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 004b152e  39df                   +cmp edi, ebx
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
    // 004b1530  7d02                   -jge 0x4b1534
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b1534;
    }
    // 004b1532  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004b1534:
    // 004b1534  837e1400               +cmp dword ptr [esi + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1538  0f84db000000           -je 0x4b1619
    if (cpu.flags.zf)
    {
        goto L_0x004b1619;
    }
    // 004b153e  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b1541  8a4e0c                 -mov cl, byte ptr [esi + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b1544  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b1546  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b1548  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b1549  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b154b  8a4e18                 -mov cl, byte ptr [esi + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004b154e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b154f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b1551  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b1553  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b1554  e80f1c0000             -call 0x4b3168
    cpu.esp -= 4;
    sub_4b3168(app, cpu);
    if (cpu.terminate) return;
L_0x004b1559:
    // 004b1559  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b155c  015e08                 -add dword ptr [esi + 8], ebx
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b155f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b1561  8a4e10                 -mov cl, byte ptr [esi + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004b1564  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b1566  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1568  01c5                   +add ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b156a  eba8                   -jmp 0x4b1514
    goto L_0x004b1514;
L_0x004b156c:
    // 004b156c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b1571  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1574  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1575  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1576  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1577  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1578  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1579:
    // 004b1579  83781400               +cmp dword ptr [eax + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b157d  742b                   -je 0x4b15aa
    if (cpu.flags.zf)
    {
        goto L_0x004b15aa;
    }
    // 004b157f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b1580  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b1583  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b1586  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b1588  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004b158a  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b158d  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b158f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b1591  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b1592  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b1594  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b1595  e8ce1b0000             -call 0x4b3168
    cpu.esp -= 4;
    sub_4b3168(app, cpu);
    if (cpu.terminate) return;
    // 004b159a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b159d  017e08                 -add dword ptr [esi + 8], edi
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.edi));
L_0x004b15a0:
    // 004b15a0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b15a2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b15a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b15a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b15a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b15a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b15a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b15aa:
    // 004b15aa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b15ab  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b15ae  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b15b1  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b15b3  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004b15b5  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b15b8  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b15ba  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b15bc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b15bd  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b15bf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b15c0  e80f1c0000             -call 0x4b31d4
    cpu.esp -= 4;
    sub_4b31d4(app, cpu);
    if (cpu.terminate) return;
    // 004b15c5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b15c8  017e08                 -add dword ptr [esi + 8], edi
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b15cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b15cd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b15d0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b15d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b15d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b15d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b15d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b15d5:
    // 004b15d5  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b15d8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b15da  ff15b4a14c00           -call dword ptr [0x4ca1b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022132) /* 0x4ca1b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b15e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b15e2  750d                   -jne 0x4b15f1
    if (!cpu.flags.zf)
    {
        goto L_0x004b15f1;
    }
    // 004b15e4  833e00                 +cmp dword ptr [esi], 0
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
    // 004b15e7  7408                   -je 0x4b15f1
    if (cpu.flags.zf)
    {
        goto L_0x004b15f1;
    }
    // 004b15e9  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b15ec  e937ffffff             -jmp 0x4b1528
    goto L_0x004b1528;
L_0x004b15f1:
    // 004b15f1  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004b15f3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b15f5  8a4e10                 -mov cl, byte ptr [esi + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004b15f8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b15fa  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004b15fc  e8be2bfdff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 004b1601  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004b1608  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b160f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1611  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1614  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1615  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1616  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1617  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1618  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1619:
    // 004b1619  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b161c  8a4e0c                 -mov cl, byte ptr [esi + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b161f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b1621  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b1623  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b1624  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b1626  8a4e18                 -mov cl, byte ptr [esi + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004b1629  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b162a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b162c  d3e0                   +shl eax, cl
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
    // 004b162e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b162f  e8a01b0000             -call 0x4b31d4
    cpu.esp -= 4;
    sub_4b31d4(app, cpu);
    if (cpu.terminate) return;
    // 004b1634  e920ffffff             -jmp 0x4b1559
    goto L_0x004b1559;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b163c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b163c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b163d  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 004b1643  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b164a  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004b1651  8d341a                 -lea esi, [edx + ebx]
    cpu.esi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 004b1654  89700c                 -mov dword ptr [eax + 0xc], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004b1657  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004b165a  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004b165d  897010                 -mov dword ptr [eax + 0x10], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 004b1660  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004b1663  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 004b1668  c701f0144b00           -mov dword ptr [ecx], 0x4b14f0
    app->getMemory<x86::reg32>(cpu.ecx) = 4920560 /*0x4b14f0*/;
    // 004b166e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b166f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b1670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b1670  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b1671  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b1673  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b1674  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b1677  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b167a  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b167d  0f6e5e04               -movd mm3, dword ptr [esi + 4]
    cpu.mmx.mm3 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)) };
    // 004b1681  ba0000ff7f             -mov edx, 0x7fff0000
    cpu.edx = 2147418112 /*0x7fff0000*/;
    // 004b1686  b800000080             -mov eax, 0x80000000
    cpu.eax = 2147483648 /*0x80000000*/;
    // 004b168b  0f6ee2                 -movd mm4, edx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004b168e  0f6ee8                 -movd mm5, eax
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004b1691  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004b1693:
    // 004b1693  833e00                 +cmp dword ptr [esi], 0
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
    // 004b1696  0f8ea3000000           -jle 0x4b173f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b173f;
    }
    // 004b169c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b169e  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004b16a0  832e1c                 -sub dword ptr [esi], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi)) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b16a3  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 004b16a6  83c338                 -add ebx, 0x38
    (cpu.ebx) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004b16a9  0f6e0c85a4d54c00       -movd mm1, dword ptr [eax*4 + 0x4cd5a4]
    cpu.mmx.mm1 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(x86::reg32(5035428) /* 0x4cd5a4 */ + cpu.eax * 4)) };
    // 004b16b1  0f6e1485b4d54c00       -movd mm2, dword ptr [eax*4 + 0x4cd5b4]
    cpu.mmx.mm2 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(x86::reg32(5035444) /* 0x4cd5b4 */ + cpu.eax * 4)) };
    // 004b16b9  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004b16bb  b9f2ffffff             -mov ecx, 0xfffffff2
    cpu.ecx = 4294967282 /*0xfffffff2*/;
    // 004b16c0  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004b16c3  83c70f                 -add edi, 0xf
    (cpu.edi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004b16c6  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
L_0x004b16c9:
    // 004b16c9  8a1439                 -mov dl, byte ptr [ecx + edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
    // 004b16cc  0f6ff3                 -movq mm6, mm3
    cpu.mmx.mm6 = cpu.mmx.mm3;
    // 004b16cf  c0ea04                 -shr dl, 4
    cpu.dl >>= 4 /*0x4*/ % 32;
    // 004b16d2  0ff5f1                 -pmaddwd mm6, mm1
    cpu.mmx.mm6 = { _mm_madd_epi16(cpu.mmx.mm6, cpu.mmx.mm1) };
    // 004b16d5  0f6e849014655400       -movd mm0, dword ptr [eax + edx*4 + 0x546514]
    cpu.mmx.mm0 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5530900) /* 0x546514 */ + cpu.edx * 4)) };
    // 004b16dd  0ffef0                 -paddd mm6, mm0
    cpu.mmx.mm6 = { _mm_add_epi32(cpu.mmx.mm6, cpu.mmx.mm0) };
    // 004b16e0  0f7ef5                 -movd ebp, mm6
    cpu.ebp = _mm_cvtsi128_si32(cpu.mmx.mm6);
    // 004b16e3  81fd00ff7f00           +cmp ebp, 0x7fff00
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8388352 /*0x7fff00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b16e9  7f5e                   -jg 0x4b1749
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b1749;
    }
    // 004b16eb  81fd000080ff           +cmp ebp, 0xff800000
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4286578688 /*0xff800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b16f1  7c5b                   -jl 0x4b174e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b174e;
    }
    // 004b16f3  0f72f608               -pslld mm6, 8
    cpu.mmx.mm6 = { _mm_slli_epi32(cpu.mmx.mm6, 8 /*0x8*/) };
L_0x004b16f7:
    // 004b16f7  8a1439                 -mov dl, byte ptr [ecx + edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
    // 004b16fa  0f61f3                 -punpcklwd mm6, mm3
    cpu.mmx.mm6 = { _mm_unpacklo_epi16(cpu.mmx.mm6, cpu.mmx.mm3) };
    // 004b16fd  80e20f                 -and dl, 0xf
    cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004b1700  0f73d620               -psrlq mm6, 0x20
    cpu.mmx.mm6 = { _mm_srli_epi64(cpu.mmx.mm6, 32 /*0x20*/) };
    // 004b1704  0f6fde                 -movq mm3, mm6
    cpu.mmx.mm3 = cpu.mmx.mm6;
    // 004b1707  0ff5f2                 -pmaddwd mm6, mm2
    cpu.mmx.mm6 = { _mm_madd_epi16(cpu.mmx.mm6, cpu.mmx.mm2) };
    // 004b170a  0f6e849014655400       -movd mm0, dword ptr [eax + edx*4 + 0x546514]
    cpu.mmx.mm0 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5530900) /* 0x546514 */ + cpu.edx * 4)) };
    // 004b1712  0ffef0                 -paddd mm6, mm0
    cpu.mmx.mm6 = { _mm_add_epi32(cpu.mmx.mm6, cpu.mmx.mm0) };
    // 004b1715  0f7ef5                 -movd ebp, mm6
    cpu.ebp = _mm_cvtsi128_si32(cpu.mmx.mm6);
    // 004b1718  81fd00ff7f00           +cmp ebp, 0x7fff00
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8388352 /*0x7fff00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b171e  7f33                   -jg 0x4b1753
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b1753;
    }
    // 004b1720  81fd000080ff           +cmp ebp, 0xff800000
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4286578688 /*0xff800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1726  7c30                   -jl 0x4b1758
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1758;
    }
    // 004b1728  0f72f608               -pslld mm6, 8
    cpu.mmx.mm6 = { _mm_slli_epi32(cpu.mmx.mm6, 8 /*0x8*/) };
L_0x004b172c:
    // 004b172c  0f73d610               -psrlq mm6, 0x10
    cpu.mmx.mm6 = { _mm_srli_epi64(cpu.mmx.mm6, 16 /*0x10*/) };
    // 004b1730  0f61de                 -punpcklwd mm3, mm6
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(cpu.mmx.mm3, cpu.mmx.mm6) };
    // 004b1733  0f7e1c8b               -movd dword ptr [ebx + ecx*4], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebx + cpu.ecx * 4), cpu.mmx.mm3);
    // 004b1737  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b1738  7c8f                   -jl 0x4b16c9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b16c9;
    }
    // 004b173a  e954ffffff             -jmp 0x4b1693
    goto L_0x004b1693;
L_0x004b173f:
    // 004b173f  0f7e5e04               -movd dword ptr [esi + 4], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */), cpu.mmx.mm3);
    // 004b1743  895e0c                 -mov dword ptr [esi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004b1746  61                     -popal 
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
    // 004b1747  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1748  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1749:
    // 004b1749  0f6ff4                 -movq mm6, mm4
    cpu.mmx.mm6 = cpu.mmx.mm4;
    // 004b174c  eba9                   -jmp 0x4b16f7
    goto L_0x004b16f7;
L_0x004b174e:
    // 004b174e  0f6ff5                 -movq mm6, mm5
    cpu.mmx.mm6 = cpu.mmx.mm5;
    // 004b1751  eba4                   -jmp 0x4b16f7
    goto L_0x004b16f7;
L_0x004b1753:
    // 004b1753  0f6ff4                 -movq mm6, mm4
    cpu.mmx.mm6 = cpu.mmx.mm4;
    // 004b1756  ebd4                   -jmp 0x4b172c
    goto L_0x004b172c;
L_0x004b1758:
    // 004b1758  0f6ff5                 -movq mm6, mm5
    cpu.mmx.mm6 = cpu.mmx.mm5;
    // 004b175b  ebcf                   -jmp 0x4b172c
    goto L_0x004b172c;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4b1760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b1760  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b1761  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b1762  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b1763  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b1764  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004b1767  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004b176b  8b7304                 -mov esi, dword ptr [ebx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b176e  8b4302                 -mov eax, dword ptr [ebx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004b1771  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b1774  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004b1777  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b1779  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b177d  8b4306                 -mov eax, dword ptr [ebx + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 004b1780  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004b1783  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004b1786  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004b1789  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b178d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b178f  0f8ee5010000           -jle 0x4b197a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b197a;
    }
L_0x004b1795:
    // 004b1795  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b1797  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b179a  83ed1c                 -sub ebp, 0x1c
    (cpu.ebp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b179d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b179f  892b                   -mov dword ptr [ebx], ebp
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ebp;
    // 004b17a1  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b17a3  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 004b17a6  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004b17aa  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b17ac  80e20f                 -and dl, 0xf
    cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004b17af  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b17b5  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004b17b9  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b17bd  8b0c953cda4c00         -mov ecx, dword ptr [edx*4 + 0x4cda3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5036604) /* 0x4cda3c */ + cpu.edx * 4);
    // 004b17c4  8b14954cda4c00         -mov edx, dword ptr [edx*4 + 0x4cda4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5036620) /* 0x4cda4c */ + cpu.edx * 4);
    // 004b17cb  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004b17cf  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b17d3  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004b17d7  8b0c953cda4c00         -mov ecx, dword ptr [edx*4 + 0x4cda3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5036604) /* 0x4cda3c */ + cpu.edx * 4);
    // 004b17de  8b14954cda4c00         -mov edx, dword ptr [edx*4 + 0x4cda4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5036620) /* 0x4cda4c */ + cpu.edx * 4);
    // 004b17e5  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004b17e9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b17eb  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b17ee  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 004b17f1  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b17f4  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004b17f8  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b17fb  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004b17ff  80e20f                 -and dl, 0xf
    cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004b1802  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b1808  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b180b  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b180e  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004b1812  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b1815  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b1818  83c270                 -add edx, 0x70
    (cpu.edx) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004b181b  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b181e  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b1821  39d0                   +cmp eax, edx
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
    // 004b1823  0f8348010000           -jae 0x4b1971
    if (!cpu.flags.cf)
    {
        goto L_0x004b1971;
    }
L_0x004b1829:
    // 004b1829  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b182c  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004b182e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b1833  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b1835  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 004b1838  8a4c2424               -mov cl, byte ptr [esp + 0x24]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b183c  c1e21c                 -shl edx, 0x1c
    cpu.edx <<= 28 /*0x1c*/ % 32;
    // 004b183f  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 004b1841  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b1843  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b1847  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004b184a  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b184e  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b1850  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b1854  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004b1857  c1e01c                 -shl eax, 0x1c
    cpu.eax <<= 28 /*0x1c*/ % 32;
    // 004b185a  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b185c  8a4c2428               -mov cl, byte ptr [esp + 0x28]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b1860  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004b1862  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b1864  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b1868  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b186b  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b186f  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b1871  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b1875  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004b1878  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b187a  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004b1880  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004b1885  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004b1888  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004b188b  81fa0080ffff           +cmp edx, 0xffff8000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294934528 /*0xffff8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1891  0f8d03010000           -jge 0x4b199a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b199a;
    }
    // 004b1897  ba0080ffff             -mov edx, 0xffff8000
    cpu.edx = 4294934528 /*0xffff8000*/;
L_0x004b189c:
    // 004b189c  3d0080ffff             +cmp eax, 0xffff8000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294934528 /*0xffff8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b18a1  0f8d09010000           -jge 0x4b19b0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b19b0;
    }
    // 004b18a7  b80080ffff             -mov eax, 0xffff8000
    cpu.eax = 4294934528 /*0xffff8000*/;
L_0x004b18ac:
    // 004b18ac  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b18af  668911                 -mov word ptr [ecx], dx
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.dx;
    // 004b18b2  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b18b5  66894102               -mov word ptr [ecx + 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 004b18b9  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b18bc  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004b18c0  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b18c4  8a4901                 -mov cl, byte ptr [ecx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b18c7  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b18cd  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b18d1  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 004b18d4  c1e11c                 -shl ecx, 0x1c
    cpu.ecx <<= 28 /*0x1c*/ % 32;
    // 004b18d7  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004b18db  8a4c2424               -mov cl, byte ptr [esp + 0x24]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b18df  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b18e3  d3fd                   -sar ebp, cl
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (cpu.cl % 32));
    // 004b18e5  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004b18e7  0faf542420             -imul edx, dword ptr [esp + 0x20]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */))));
    // 004b18ec  0faf442418             -imul eax, dword ptr [esp + 0x18]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 004b18f1  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b18f3  0faf742414             -imul esi, dword ptr [esp + 0x14]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 004b18f8  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b18fa  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b18fe  8a4c2428               -mov cl, byte ptr [esp + 0x28]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b1902  c1e61c                 -shl esi, 0x1c
    cpu.esi <<= 28 /*0x1c*/ % 32;
    // 004b1905  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 004b1907  0faf7c241c             -imul edi, dword ptr [esp + 0x1c]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))));
    // 004b190c  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b190e  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b1910  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004b1916  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004b191b  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004b191e  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004b1921  81fa0080ffff           +cmp edx, 0xffff8000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294934528 /*0xffff8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1927  0f8d98000000           -jge 0x4b19c5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b19c5;
    }
    // 004b192d  ba0080ffff             -mov edx, 0xffff8000
    cpu.edx = 4294934528 /*0xffff8000*/;
L_0x004b1932:
    // 004b1932  3d0080ffff             +cmp eax, 0xffff8000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294934528 /*0xffff8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1937  0f8d9e000000           -jge 0x4b19db
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b19db;
    }
    // 004b193d  b80080ffff             -mov eax, 0xffff8000
    cpu.eax = 4294934528 /*0xffff8000*/;
L_0x004b1942:
    // 004b1942  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b1945  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 004b1949  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b194b  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b194e  66894206               -mov word ptr [edx + 6], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 004b1952  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b1954  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b1957  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b195a  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b195d  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b1960  894b0c                 -mov dword ptr [ebx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004b1963  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b1966  896b10                 -mov dword ptr [ebx + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004b1969  39d5                   +cmp ebp, edx
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
    // 004b196b  0f82b8feffff           -jb 0x4b1829
    if (cpu.flags.cf)
    {
        goto L_0x004b1829;
    }
L_0x004b1971:
    // 004b1971  833b00                 +cmp dword ptr [ebx], 0
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
    // 004b1974  0f8f1bfeffff           -jg 0x4b1795
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b1795;
    }
L_0x004b197a:
    // 004b197a  66897306               -mov word ptr [ebx + 6], si
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.si;
    // 004b197e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b1982  66897b0a               -mov word ptr [ebx + 0xa], di
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(10) /* 0xa */) = cpu.di;
    // 004b1986  66894304               -mov word ptr [ebx + 4], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 004b198a  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b198e  66894308               -mov word ptr [ebx + 8], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 004b1992  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004b1995  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1996  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1997  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1998  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1999  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b199a:
    // 004b199a  81faff7f0000           +cmp edx, 0x7fff
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b19a0  0f8ef6feffff           -jle 0x4b189c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b189c;
    }
    // 004b19a6  baff7f0000             -mov edx, 0x7fff
    cpu.edx = 32767 /*0x7fff*/;
    // 004b19ab  e9ecfeffff             -jmp 0x4b189c
    goto L_0x004b189c;
L_0x004b19b0:
    // 004b19b0  3dff7f0000             +cmp eax, 0x7fff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b19b5  0f8ef1feffff           -jle 0x4b18ac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b18ac;
    }
    // 004b19bb  b8ff7f0000             -mov eax, 0x7fff
    cpu.eax = 32767 /*0x7fff*/;
    // 004b19c0  e9e7feffff             -jmp 0x4b18ac
    goto L_0x004b18ac;
L_0x004b19c5:
    // 004b19c5  81faff7f0000           +cmp edx, 0x7fff
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b19cb  0f8e61ffffff           -jle 0x4b1932
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b1932;
    }
    // 004b19d1  baff7f0000             -mov edx, 0x7fff
    cpu.edx = 32767 /*0x7fff*/;
    // 004b19d6  e957ffffff             -jmp 0x4b1932
    goto L_0x004b1932;
L_0x004b19db:
    // 004b19db  3dff7f0000             +cmp eax, 0x7fff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b19e0  0f8e5cffffff           -jle 0x4b1942
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b1942;
    }
    // 004b19e6  b8ff7f0000             -mov eax, 0x7fff
    cpu.eax = 32767 /*0x7fff*/;
    // 004b19eb  e952ffffff             -jmp 0x4b1942
    goto L_0x004b1942;
}

/* align: skip  */
void Application::sub_4b19f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b19f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b19f1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b19f3  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b19f4  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b19f7  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b19fa  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004b19fd  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b1a00  89155cda4c00           -mov dword ptr [0x4cda5c], edx
    app->getMemory<x86::reg32>(x86::reg32(5036636) /* 0x4cda5c */) = cpu.edx;
    // 004b1a06  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b1a09  891560da4c00           -mov dword ptr [0x4cda60], edx
    app->getMemory<x86::reg32>(x86::reg32(5036640) /* 0x4cda60 */) = cpu.edx;
L_0x004b1a0f:
    // 004b1a0f  833e00                 +cmp dword ptr [esi], 0
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
    // 004b1a12  0f8ea7000000           -jle 0x4b1abf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b1abf;
    }
    // 004b1a18  832e1c                 -sub dword ptr [esi], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi)) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b1a1b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1a1d  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004b1a1f  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 004b1a22  d9048594d54c00         -fld dword ptr [eax*4 + 0x4cd594]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5035412) /* 0x4cd594 */ + cpu.eax * 4)));
    // 004b1a29  d9048584d54c00         -fld dword ptr [eax*4 + 0x4cd584]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5035396) /* 0x4cd584 */ + cpu.eax * 4)));
    // 004b1a30  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004b1a32  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004b1a35  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 004b1a38  83c701                 -add edi, 1
    (cpu.edi) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004b1a3b  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1a3d  b9f2ffffff             -mov ecx, 0xfffffff2
    cpu.ecx = 4294967282 /*0xfffffff2*/;
    // 004b1a42  d90560da4c00           -fld dword ptr [0x4cda60]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036640) /* 0x4cda60 */)));
    // 004b1a48  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b1a4a  d9055cda4c00           -fld dword ptr [0x4cda5c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036636) /* 0x4cda5c */)));
    // 004b1a50  d9055cda4c00           -fld dword ptr [0x4cda5c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036636) /* 0x4cda5c */)));
    // 004b1a56  d90560da4c00           -fld dword ptr [0x4cda60]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036640) /* 0x4cda60 */)));
    // 004b1a5c  83c70e                 -add edi, 0xe
    (cpu.edi) += x86::reg32(x86::sreg32(14 /*0xe*/));
    // 004b1a5f  83c370                 -add ebx, 0x70
    (cpu.ebx) += x86::reg32(x86::sreg32(112 /*0x70*/));
L_0x004b1a62:
    // 004b1a62  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1a64  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b1a66  8a1439                 -mov dl, byte ptr [ecx + edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
    // 004b1a69  c0ea04                 -shr dl, 4
    cpu.dl >>= 4 /*0x4*/ % 32;
    // 004b1a6c  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b1a6e  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b1a70  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b1a72  d8849014615400         -fadd dword ptr [eax + edx*4 + 0x546114]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(5529876) /* 0x546114 */ + cpu.edx * 4));
    // 004b1a79  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b1a7b  8a1439                 -mov dl, byte ptr [ecx + edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
    // 004b1a7e  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b1a80  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b1a82  d914cb                 -fst dword ptr [ebx + ecx*8]
    app->getMemory<float>(cpu.ebx + cpu.ecx * 8) = float(cpu.fpu.st(0));
    // 004b1a85  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004b1a87  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b1a89  d8cd                   -fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 004b1a8b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b1a8d  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b1a8f  80e20f                 +and dl, 0xf
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/))));
    // 004b1a92  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b1a94  d8849014615400         +fadd dword ptr [eax + edx*4 + 0x546114]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(5529876) /* 0x546114 */ + cpu.edx * 4));
    // 004b1a9b  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b1a9d  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b1a9f  d954cb04               +fst dword ptr [ebx + ecx*8 + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.ecx * 8) = float(cpu.fpu.st(0));
    // 004b1aa3  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b1aa5  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b1aa6  7cba                   -jl 0x4b1a62
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1a62;
    }
    // 004b1aa8  d91d60da4c00           +fstp dword ptr [0x4cda60]
    app->getMemory<float>(x86::reg32(5036640) /* 0x4cda60 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1aae  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1ab0  d91d5cda4c00           +fstp dword ptr [0x4cda5c]
    app->getMemory<float>(x86::reg32(5036636) /* 0x4cda5c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1ab6  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004b1ab8  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1aba  e950ffffff             -jmp 0x4b1a0f
    goto L_0x004b1a0f;
L_0x004b1abf:
    // 004b1abf  8b155cda4c00           -mov edx, dword ptr [0x4cda5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5036636) /* 0x4cda5c */);
    // 004b1ac5  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b1ac8  8b1560da4c00           -mov edx, dword ptr [0x4cda60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5036640) /* 0x4cda60 */);
    // 004b1ace  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b1ad1  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004b1ad4  61                     -popal 
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
    // 004b1ad5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1ad6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b1ad8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b1ad8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b1ad9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b1adb  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b1adc  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b1adf  8b7e14                 -mov edi, dword ptr [esi + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004b1ae2  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004b1ae5  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b1ae8  891564da4c00           -mov dword ptr [0x4cda64], edx
    app->getMemory<x86::reg32>(x86::reg32(5036644) /* 0x4cda64 */) = cpu.edx;
    // 004b1aee  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b1af1  891568da4c00           -mov dword ptr [0x4cda68], edx
    app->getMemory<x86::reg32>(x86::reg32(5036648) /* 0x4cda68 */) = cpu.edx;
    // 004b1af7  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b1afa  89156cda4c00           -mov dword ptr [0x4cda6c], edx
    app->getMemory<x86::reg32>(x86::reg32(5036652) /* 0x4cda6c */) = cpu.edx;
    // 004b1b00  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004b1b03  891570da4c00           -mov dword ptr [0x4cda70], edx
    app->getMemory<x86::reg32>(x86::reg32(5036656) /* 0x4cda70 */) = cpu.edx;
L_0x004b1b09:
    // 004b1b09  833e00                 +cmp dword ptr [esi], 0
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
    // 004b1b0c  0f8e17010000           -jle 0x4b1c29
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b1c29;
    }
    // 004b1b12  832e1c                 -sub dword ptr [esi], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi)) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b1b15  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1b17  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1b19  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004b1b1b  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004b1b1d  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 004b1b20  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004b1b23  d9049d94d54c00         -fld dword ptr [ebx*4 + 0x4cd594]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5035412) /* 0x4cd594 */ + cpu.ebx * 4)));
    // 004b1b2a  d9049d84d54c00         -fld dword ptr [ebx*4 + 0x4cd584]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5035396) /* 0x4cd584 */ + cpu.ebx * 4)));
    // 004b1b31  d9048594d54c00         -fld dword ptr [eax*4 + 0x4cd594]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5035412) /* 0x4cd594 */ + cpu.eax * 4)));
    // 004b1b38  d9048584d54c00         -fld dword ptr [eax*4 + 0x4cd584]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5035396) /* 0x4cd584 */ + cpu.eax * 4)));
    // 004b1b3f  8a4701                 -mov al, byte ptr [edi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b1b42  8a5f01                 -mov bl, byte ptr [edi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b1b45  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 004b1b48  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004b1b4b  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 004b1b4e  c1e306                 -shl ebx, 6
    cpu.ebx <<= 6 /*0x6*/ % 32;
    // 004b1b51  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b1b54  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1b56  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004b1b5b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b1b5c  8bf3                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x004b1b5e:
    // 004b1b5e  d90564da4c00           -fld dword ptr [0x4cda64]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036644) /* 0x4cda64 */)));
    // 004b1b64  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b1b66  d9056cda4c00           -fld dword ptr [0x4cda6c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036652) /* 0x4cda6c */)));
    // 004b1b6c  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004b1b6e  d90568da4c00           -fld dword ptr [0x4cda68]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036648) /* 0x4cda68 */)));
    // 004b1b74  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004b1b76  d90570da4c00           -fld dword ptr [0x4cda70]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036656) /* 0x4cda70 */)));
    // 004b1b7c  d8cf                   -fmul st(7)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(7));
    // 004b1b7e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b1b80  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b1b82  8a17                   -mov dl, byte ptr [edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi);
    // 004b1b84  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004b1b86  c1ea04                 -shr edx, 4
    cpu.edx >>= 4 /*0x4*/ % 32;
    // 004b1b89  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004b1b8c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b1b8e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b1b90  d8849014615400         -fadd dword ptr [eax + edx*4 + 0x546114]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(5529876) /* 0x546114 */ + cpu.edx * 4));
    // 004b1b97  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b1b99  d8849e14615400         -fadd dword ptr [esi + ebx*4 + 0x546114]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(5529876) /* 0x546114 */ + cpu.ebx * 4));
    // 004b1ba0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b1ba2  d95500                 -fst dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    // 004b1ba5  d91d68da4c00           -fstp dword ptr [0x4cda68]
    app->getMemory<float>(x86::reg32(5036648) /* 0x4cda68 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1bab  d95504                 -fst dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    // 004b1bae  d91d70da4c00           -fstp dword ptr [0x4cda70]
    app->getMemory<float>(x86::reg32(5036656) /* 0x4cda70 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1bb4  d90568da4c00           -fld dword ptr [0x4cda68]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036648) /* 0x4cda68 */)));
    // 004b1bba  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b1bbc  d90570da4c00           -fld dword ptr [0x4cda70]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036656) /* 0x4cda70 */)));
    // 004b1bc2  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004b1bc4  d90564da4c00           -fld dword ptr [0x4cda64]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036644) /* 0x4cda64 */)));
    // 004b1bca  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004b1bcc  d9056cda4c00           -fld dword ptr [0x4cda6c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036652) /* 0x4cda6c */)));
    // 004b1bd2  d8cf                   -fmul st(7)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(7));
    // 004b1bd4  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b1bd6  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b1bd8  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b1bdb  8a5f01                 -mov bl, byte ptr [edi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b1bde  c1ea04                 -shr edx, 4
    cpu.edx >>= 4 /*0x4*/ % 32;
    // 004b1be1  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004b1be4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b1be6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b1be8  d8849014615400         -fadd dword ptr [eax + edx*4 + 0x546114]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(5529876) /* 0x546114 */ + cpu.edx * 4));
    // 004b1bef  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b1bf1  d8849e14615400         -fadd dword ptr [esi + ebx*4 + 0x546114]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(5529876) /* 0x546114 */ + cpu.ebx * 4));
    // 004b1bf8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b1bfa  d95508                 -fst dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    // 004b1bfd  d91d64da4c00           -fstp dword ptr [0x4cda64]
    app->getMemory<float>(x86::reg32(5036644) /* 0x4cda64 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1c03  d9550c                 -fst dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    // 004b1c06  d91d6cda4c00           -fstp dword ptr [0x4cda6c]
    app->getMemory<float>(x86::reg32(5036652) /* 0x4cda6c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1c0c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b1c0f  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1c12  83e902                 +sub ecx, 2
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
    // 004b1c15  0f8f43ffffff           -jg 0x4b1b5e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b1b5e;
    }
    // 004b1c1b  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1c1d  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1c1f  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1c21  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1c23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1c24  e9e0feffff             -jmp 0x4b1b09
    goto L_0x004b1b09;
L_0x004b1c29:
    // 004b1c29  896e18                 -mov dword ptr [esi + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004b1c2c  8b1564da4c00           -mov edx, dword ptr [0x4cda64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5036644) /* 0x4cda64 */);
    // 004b1c32  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b1c35  8b1568da4c00           -mov edx, dword ptr [0x4cda68]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5036648) /* 0x4cda68 */);
    // 004b1c3b  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b1c3e  8b156cda4c00           -mov edx, dword ptr [0x4cda6c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5036652) /* 0x4cda6c */);
    // 004b1c44  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004b1c47  8b1570da4c00           -mov edx, dword ptr [0x4cda70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5036656) /* 0x4cda70 */);
    // 004b1c4d  895610                 -mov dword ptr [esi + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004b1c50  61                     -popal 
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
    // 004b1c51  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1c52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b1c60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b1c60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b1c61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b1c62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b1c63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b1c64  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b1c67  8b1c9574da4c00         -mov ebx, dword ptr [edx*4 + 0x4cda74]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5036660) /* 0x4cda74 */ + cpu.edx * 4);
    // 004b1c6e  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b1c71  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b1c74  21cb                   -and ebx, ecx
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1c76  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1c78  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004b1c7a  897808                 -mov dword ptr [eax + 8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004b1c7d  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 004b1c7f  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004b1c82  83ff08                 +cmp edi, 8
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
    // 004b1c85  7c07                   -jl 0x4b1c8e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1c8e;
    }
    // 004b1c87  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b1c89  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1c8a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1c8b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1c8c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1c8d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1c8e:
    // 004b1c8e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b1c90  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 004b1c92  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b1c98  8a4808                 -mov cl, byte ptr [eax + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b1c9b  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004b1c9d  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b1ca0  46                     -inc esi
    (cpu.esi)++;
    // 004b1ca1  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b1ca4  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004b1ca6  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004b1ca8  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b1cab  897808                 -mov dword ptr [eax + 8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004b1cae  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1cb0  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b1cb3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b1cb5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1cb6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1cb7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1cb8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1cb9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b1cbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b1cbc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b1cbd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b1cbe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b1cbf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b1cc0  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004b1cc2  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b1cc5  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b1cc8  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 004b1cca  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1ccc  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b1ccf  897008                 -mov dword ptr [eax + 8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004b1cd2  83fe08                 +cmp esi, 8
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
    // 004b1cd5  7c05                   -jl 0x4b1cdc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1cdc;
    }
    // 004b1cd7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1cd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1cd9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1cda  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1cdb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1cdc:
    // 004b1cdc  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b1cde  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 004b1ce0  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b1ce6  8a4808                 -mov cl, byte ptr [eax + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b1ce9  8b6804                 -mov ebp, dword ptr [eax + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b1cec  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004b1cee  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b1cf1  09d5                   -or ebp, edx
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1cf3  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b1cf6  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b1cf8  896804                 -mov dword ptr [eax + 4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004b1cfb  42                     -inc edx
    (cpu.edx)++;
    // 004b1cfc  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004b1cff  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004b1d01  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1d02  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1d03  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1d04  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1d05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b1d18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004b1d18  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b1d19  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b1d1a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b1d1b  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1d1e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b1d20  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004b1d22  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004b1d24  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b1d26  753a                   -jne 0x4b1d62
    if (!cpu.flags.zf)
    {
        goto L_0x004b1d62;
    }
    // 004b1d28  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1d2a  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
L_0x004b1d2f:
    // 004b1d2f  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b1d32  21d8                   -and eax, ebx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1d34  83f803                 +cmp eax, 3
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
    // 004b1d37  771b                   -ja 0x4b1d54
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b1d54;
    }
    // 004b1d39  ff2485081d4b00         -jmp dword ptr [eax*4 + 0x4b1d08]
    cpu.ip = app->getMemory<x86::reg32>(4922632 + cpu.eax * 4); goto dynamic_jump;
  case 0x004b1d40:
    // 004b1d40  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b1d45  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b1d47  c7448d0000000000       -mov dword ptr [ebp + ecx*4], 0
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = 0 /*0x0*/;
L_0x004b1d4f:
    // 004b1d4f  e868ffffff             -call 0x4b1cbc
    cpu.esp -= 4;
    sub_4b1cbc(app, cpu);
    if (cpu.terminate) return;
L_0x004b1d54:
    // 004b1d54  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b1d56  83f96c                 +cmp ecx, 0x6c
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
    // 004b1d59  7cd4                   -jl 0x4b1d2f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1d2f;
    }
    // 004b1d5b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1d5e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1d5f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1d60  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1d61  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1d62:
    // 004b1d62  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1d64  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1d66  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x004b1d69:
    // 004b1d69  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b1d6c  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b1d6f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b1d74  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b1d77  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1d79  8a9c0298db4c00         -mov bl, byte ptr [edx + eax + 0x4cdb98]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5036952) /* 0x4cdb98 */ + cpu.eax * 1);
    // 004b1d80  6bc30c                 -imul eax, ebx, 0xc
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 004b1d83  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b1d87  8b8098dd4c00           -mov eax, dword ptr [eax + 0x4cdd98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5037464) /* 0x4cdd98 */);
    // 004b1d8d  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b1d91  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b1d94  8b929cdd4c00           -mov edx, dword ptr [edx + 0x4cdd9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5037468) /* 0x4cdd9c */);
    // 004b1d9a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b1d9c  e81bffffff             -call 0x4b1cbc
    cpu.esp -= 4;
    sub_4b1cbc(app, cpu);
    if (cpu.terminate) return;
    // 004b1da1  83fb03                 +cmp ebx, 3
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
    // 004b1da4  7e1c                   -jle 0x4b1dc2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b1dc2;
    }
    // 004b1da6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b1daa  8b82a0dd4c00           -mov eax, dword ptr [edx + 0x4cdda0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5037472) /* 0x4cdda0 */);
    // 004b1db0  89448d00               -mov dword ptr [ebp + ecx*4], eax
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = cpu.eax;
    // 004b1db4  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
L_0x004b1db6:
    // 004b1db6  83f96c                 +cmp ecx, 0x6c
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
    // 004b1db9  7cae                   -jl 0x4b1d69
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1d69;
    }
    // 004b1dbb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1dbe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1dbf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1dc0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1dc1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1dc2:
    // 004b1dc2  83fb01                 +cmp ebx, 1
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
    // 004b1dc5  7f1a                   -jg 0x4b1de1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b1de1;
    }
    // 004b1dc7  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
L_0x004b1dcc:
    // 004b1dcc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b1dd1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b1dd3  e888feffff             -call 0x4b1c60
    cpu.esp -= 4;
    sub_4b1c60(app, cpu);
    if (cpu.terminate) return;
    // 004b1dd8  83f801                 +cmp eax, 1
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
    // 004b1ddb  7560                   -jne 0x4b1e3d
    if (!cpu.flags.zf)
    {
        goto L_0x004b1e3d;
    }
    // 004b1ddd  01c3                   +add ebx, eax
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
    // 004b1ddf  ebeb                   -jmp 0x4b1dcc
    goto L_0x004b1dcc;
L_0x004b1de1:
    // 004b1de1  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 004b1de6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b1de8  e873feffff             -call 0x4b1c60
    cpu.esp -= 4;
    sub_4b1c60(app, cpu);
    if (cpu.terminate) return;
    // 004b1ded  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b1df0  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b1df4  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b1df7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1df9  83f86c                 +cmp eax, 0x6c
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
    // 004b1dfc  7e12                   -jle 0x4b1e10
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b1e10;
    }
    // 004b1dfe  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 004b1e03  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1e05  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b1e07  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b1e0a  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b1e0c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004b1e10:
    // 004b1e10  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b1e14  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1e16  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b1e18  7e9c                   -jle 0x4b1db6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b1db6;
    }
    // 004b1e1a  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x004b1e1e:
    // 004b1e1e  40                     -inc eax
    (cpu.eax)++;
    // 004b1e1f  c7448d0000000000       -mov dword ptr [ebp + ecx*4], 0
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = 0 /*0x0*/;
    // 004b1e27  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b1e29  39d0                   +cmp eax, edx
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
    // 004b1e2b  7cf1                   -jl 0x4b1e1e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1e1e;
    }
    // 004b1e2d  83f96c                 +cmp ecx, 0x6c
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
    // 004b1e30  0f8c33ffffff           -jl 0x4b1d69
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1d69;
    }
    // 004b1e36  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1e39  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1e3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1e3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1e3c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1e3d:
    // 004b1e3d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b1e42  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b1e44  e817feffff             -call 0x4b1c60
    cpu.esp -= 4;
    sub_4b1c60(app, cpu);
    if (cpu.terminate) return;
    // 004b1e49  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 004b1e50  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004b1e52  83f801                 +cmp eax, 1
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
    // 004b1e55  751c                   -jne 0x4b1e73
    if (!cpu.flags.zf)
    {
        goto L_0x004b1e73;
    }
    // 004b1e57  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004b1e5b  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 004b1e5f  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1e61  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b1e63  83f96c                 +cmp ecx, 0x6c
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
    // 004b1e66  0f8cfdfeffff           -jl 0x4b1d69
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1d69;
    }
    // 004b1e6c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1e6f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1e70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1e71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1e72  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1e73:
    // 004b1e73  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 004b1e75  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004b1e79  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 004b1e7d  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1e7f  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b1e81  83f96c                 +cmp ecx, 0x6c
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
    // 004b1e84  0f8cdffeffff           -jl 0x4b1d69
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1d69;
    }
    // 004b1e8a  83c410                 +add esp, 0x10
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
    // 004b1e8d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1e8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1e8f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1e90  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004b1e91:
    // 004b1e91  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004b1e96  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b1e98  c7448d00000000c0       -mov dword ptr [ebp + ecx*4], 0xc0000000
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = 3221225472 /*0xc0000000*/;
    // 004b1ea0  e9aafeffff             -jmp 0x4b1d4f
    goto L_0x004b1d4f;
  case 0x004b1ea5:
    // 004b1ea5  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004b1eaa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b1eac  c7448d0000000040       -mov dword ptr [ebp + ecx*4], 0x40000000
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = 1073741824 /*0x40000000*/;
    // 004b1eb4  e996feffff             -jmp 0x4b1d4f
    goto L_0x004b1d4f;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b1ebc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b1ebc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b1ebd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b1ebf  8d90b0010000           -lea edx, [eax + 0x1b0]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(432) /* 0x1b0 */);
    // 004b1ec5  dd0538fc4b00           -fld qword ptr [0x4bfc38]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4979768) /* 0x4bfc38 */)));
    // 004b1ecb  dd0530fc4b00           -fld qword ptr [0x4bfc30]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4979760) /* 0x4bfc30 */)));
    // 004b1ed1  dd0528fc4b00           -fld qword ptr [0x4bfc28]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4979752) /* 0x4bfc28 */)));
L_0x004b1ed7:
    // 004b1ed7  d940fc                 -fld dword ptr [eax - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */)));
    // 004b1eda  d84004                 -fadd dword ptr [eax + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 004b1edd  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b1edf  d940f4                 -fld dword ptr [eax - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-12) /* -0xc */)));
    // 004b1ee2  d8400c                 -fadd dword ptr [eax + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */));
    // 004b1ee5  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b1ee7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b1ee9  d940ec                 -fld dword ptr [eax - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-20) /* -0x14 */)));
    // 004b1eec  d84014                 -fadd dword ptr [eax + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */));
    // 004b1eef  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004b1ef1  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b1ef3  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b1ef6  d958f8                 -fstp dword ptr [eax - 8]
    app->getMemory<float>(cpu.eax + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1ef9  39d0                   +cmp eax, edx
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
    // 004b1efb  75da                   -jne 0x4b1ed7
    if (!cpu.flags.zf)
    {
        goto L_0x004b1ed7;
    }
    // 004b1efd  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1eff  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1f01  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1f03  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1f04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b1f08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b1f08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b1f09  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b1f0a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b1f0b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b1f0c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b1f0d  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004b1f10  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b1f12  89542464               -mov dword ptr [esp + 0x64], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 004b1f16  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004b1f1b  8d5528                 -lea edx, [ebp + 0x28]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(40) /* 0x28 */);
L_0x004b1f1e:
    // 004b1f1e  48                     -dec eax
    (cpu.eax)--;
    // 004b1f1f  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004b1f21  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1f24  d95c8438               -fstp dword ptr [esp + eax*4 + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */ + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1f28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b1f2a  7df2                   -jge 0x4b1f1e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b1f1e;
    }
    // 004b1f2c  ba0000803f             -mov edx, 0x3f800000
    cpu.edx = 1065353216 /*0x3f800000*/;
    // 004b1f31  8b7c2464               -mov edi, dword ptr [esp + 0x64]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004b1f35  8d4528                 -lea eax, [ebp + 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 004b1f38  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1f3a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004b1f3c  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 004b1f40  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
L_0x004b1f44:
    // 004b1f44  d9452c                 -fld dword ptr [ebp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(44) /* 0x2c */)));
    // 004b1f47  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004b1f49  d84c245c               -fmul dword ptr [esp + 0x5c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(92) /* 0x5c */));
    // 004b1f4d  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004b1f52  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004b1f56  d9542468               -fst dword ptr [esp + 0x68]
    app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */) = float(cpu.fpu.st(0));
L_0x004b1f5a:
    // 004b1f5a  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004b1f5c  d84c8430               -fmul dword ptr [esp + eax*4 + 0x30]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */ + cpu.eax * 4));
    // 004b1f60  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b1f62  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004b1f64  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b1f66  48                     -dec eax
    (cpu.eax)--;
    // 004b1f67  d8448434               -fadd dword ptr [esp + eax*4 + 0x34]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */ + cpu.eax * 4));
    // 004b1f6b  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1f6e  d95c8438               -fstp dword ptr [esp + eax*4 + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */ + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1f72  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b1f74  7de4                   -jge 0x4b1f5a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b1f5a;
    }
    // 004b1f76  d95c2468               -fstp dword ptr [esp + 0x68]
    app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b1f7a  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004b1f7e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1f80  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004b1f84  890434                 -mov dword ptr [esp + esi], eax
    app->getMemory<x86::reg32>(cpu.esp + cpu.esi * 1) = cpu.eax;
    // 004b1f87  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b1f89  7e21                   -jle 0x4b1fac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b1fac;
    }
    // 004b1f8b  d9442468               -fld dword ptr [esp + 0x68]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */)));
    // 004b1f8f  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004b1f93  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004b1f95:
    // 004b1f95  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004b1f97  d84c04fc               -fmul dword ptr [esp + eax - 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1));
    // 004b1f9b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1f9e  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1fa1  41                     -inc ecx
    (cpu.ecx)++;
    // 004b1fa2  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b1fa4  39d9                   +cmp ecx, ebx
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
    // 004b1fa6  7ced                   -jl 0x4b1f95
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1f95;
    }
    // 004b1fa8  d95c2468               -fstp dword ptr [esp + 0x68]
    app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004b1fac:
    // 004b1fac  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004b1fb0  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1fb3  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1fb6  43                     -inc ebx
    (cpu.ebx)++;
    // 004b1fb7  8947fc                 -mov dword ptr [edi - 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004b1fba  83fb0c                 +cmp ebx, 0xc
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
    // 004b1fbd  7c85                   -jl 0x4b1f44
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1f44;
    }
    // 004b1fbf  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004b1fc2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1fc3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1fc4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1fc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1fc6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1fc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b1fc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b1fc8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b1fc9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b1fca  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004b1fcd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b1fcf  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b1fd1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b1fd3  0f859e070000           -jne 0x4b2777
    if (!cpu.flags.zf)
    {
        goto L_0x004b2777;
    }
    // 004b1fd9  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
L_0x004b1fdd:
    // 004b1fdd  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004b1fdf  8d8614010000           -lea eax, [esi + 0x114]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(276) /* 0x114 */);
    // 004b1fe5  e81effffff             -call 0x4b1f08
    cpu.esp -= 4;
    sub_4b1f08(app, cpu);
    if (cpu.terminate) return;
    // 004b1fea  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004b1ff1  8d9684060000           -lea edx, [esi + 0x684]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1668) /* 0x684 */);
    // 004b1ff7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b1ff9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1ffb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b1ffd  0f8e6e070000           -jle 0x4b2771
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2771;
    }
L_0x004b2003:
    // 004b2003  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004b2006  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004b200c  d800                   -fadd dword ptr [eax]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax));
    // 004b200e  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004b2012  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004b2018  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b201a  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004b201e  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004b2024  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2026  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004b202a  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004b2030  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2032  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004b2036  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004b203c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b203e  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004b2042  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004b2048  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b204a  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004b204e  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004b2054  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2056  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004b205a  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004b2060  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2062  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004b2066  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004b206c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b206e  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004b2072  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004b2078  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b207a  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004b207e  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004b2084  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2086  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004b208a  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004b2090  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2092  d99670010000           -fst dword ptr [esi + 0x170]
    app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */) = float(cpu.fpu.st(0));
    // 004b2098  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 004b209c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b209e  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004b20a0  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b20a2  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004b20a5  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004b20ab  d84004                 -fadd dword ptr [eax + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 004b20ae  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004b20b2  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004b20b8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b20ba  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004b20be  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004b20c4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b20c6  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004b20ca  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004b20d0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b20d2  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004b20d6  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004b20dc  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b20de  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004b20e2  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004b20e8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b20ea  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004b20ee  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004b20f4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b20f6  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004b20fa  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004b2100  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2102  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004b2106  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004b210c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b210e  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004b2112  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004b2118  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b211a  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004b211e  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004b2124  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2126  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004b212a  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004b2130  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2132  d9966c010000           -fst dword ptr [esi + 0x16c]
    app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */) = float(cpu.fpu.st(0));
    // 004b2138  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004b213a  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b213d  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004b2140  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004b2146  d84008                 -fadd dword ptr [eax + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */));
    // 004b2149  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004b214d  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004b2153  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2155  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004b2159  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004b215f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2161  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004b2165  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004b216b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b216d  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004b2171  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004b2177  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2179  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004b217d  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004b2183  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2185  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004b2189  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004b218f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2191  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004b2195  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004b219b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b219d  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004b21a1  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004b21a7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b21a9  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004b21ad  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004b21b3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b21b5  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004b21b9  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004b21bf  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b21c1  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004b21c5  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004b21cb  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b21cd  d99668010000           -fst dword ptr [esi + 0x168]
    app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */) = float(cpu.fpu.st(0));
    // 004b21d3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b21d5  d95808                 -fstp dword ptr [eax + 8]
    app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b21d8  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004b21db  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004b21e1  d8400c                 -fadd dword ptr [eax + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */));
    // 004b21e4  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004b21e8  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004b21ee  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b21f0  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004b21f4  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004b21fa  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b21fc  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004b2200  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004b2206  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2208  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004b220c  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004b2212  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2214  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004b2218  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004b221e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2220  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004b2224  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004b222a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b222c  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004b2230  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004b2236  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2238  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004b223c  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004b2242  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2244  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004b2248  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004b224e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2250  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004b2254  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004b225a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b225c  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004b2260  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004b2266  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2268  d99e64010000           -fstp dword ptr [esi + 0x164]
    app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b226e  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 004b2272  d98664010000           -fld dword ptr [esi + 0x164]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */)));
    // 004b2278  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004b227a  d9580c                 -fstp dword ptr [eax + 0xc]
    app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b227d  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004b2280  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004b2286  d84010                 -fadd dword ptr [eax + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */));
    // 004b2289  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004b228d  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004b2293  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2295  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004b2299  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004b229f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b22a1  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004b22a5  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004b22ab  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b22ad  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004b22b1  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004b22b7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b22b9  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004b22bd  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004b22c3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b22c5  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004b22c9  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004b22cf  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b22d1  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004b22d5  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004b22db  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b22dd  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004b22e1  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004b22e7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b22e9  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004b22ed  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004b22f3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b22f5  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004b22f9  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004b22ff  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2301  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004b2305  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004b230b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b230d  d99660010000           -fst dword ptr [esi + 0x160]
    app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */) = float(cpu.fpu.st(0));
    // 004b2313  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004b2315  d95810                 -fstp dword ptr [eax + 0x10]
    app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b2318  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004b231b  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004b2321  d84014                 -fadd dword ptr [eax + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */));
    // 004b2324  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004b2328  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004b232e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2330  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004b2334  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004b233a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b233c  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004b2340  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004b2346  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2348  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004b234c  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004b2352  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2354  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004b2358  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004b235e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2360  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004b2364  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004b236a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b236c  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004b2370  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004b2376  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2378  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004b237c  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004b2382  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2384  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004b2388  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004b238e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2390  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004b2394  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004b239a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b239c  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004b23a0  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004b23a6  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b23a8  d9965c010000           -fst dword ptr [esi + 0x15c]
    app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */) = float(cpu.fpu.st(0));
    // 004b23ae  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004b23b0  d95814                 -fstp dword ptr [eax + 0x14]
    app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b23b3  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004b23b6  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004b23bc  d84018                 -fadd dword ptr [eax + 0x18]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */));
    // 004b23bf  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004b23c3  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004b23c9  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b23cb  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004b23cf  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004b23d5  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b23d7  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004b23db  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004b23e1  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b23e3  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004b23e7  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004b23ed  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b23ef  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004b23f3  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004b23f9  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b23fb  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004b23ff  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004b2405  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2407  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004b240b  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004b2411  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2413  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004b2417  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004b241d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b241f  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004b2423  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004b2429  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b242b  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004b242f  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004b2435  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2437  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004b243b  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004b2441  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2443  d99658010000           -fst dword ptr [esi + 0x158]
    app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */) = float(cpu.fpu.st(0));
    // 004b2449  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b244b  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b244e  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004b2451  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004b2457  d8401c                 -fadd dword ptr [eax + 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */));
    // 004b245a  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004b245e  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004b2464  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2466  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004b246a  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004b2470  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2472  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004b2476  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004b247c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b247e  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004b2482  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004b2488  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b248a  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004b248e  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004b2494  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2496  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004b249a  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004b24a0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b24a2  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004b24a6  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004b24ac  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b24ae  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004b24b2  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004b24b8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b24ba  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004b24be  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004b24c4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b24c6  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004b24ca  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004b24d0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b24d2  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004b24d6  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004b24dc  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b24de  d99654010000           -fst dword ptr [esi + 0x154]
    app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */) = float(cpu.fpu.st(0));
    // 004b24e4  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 004b24e8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b24ea  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004b24ec  d9581c                 -fstp dword ptr [eax + 0x1c]
    app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b24ef  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004b24f2  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004b24f8  d84020                 -fadd dword ptr [eax + 0x20]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */));
    // 004b24fb  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004b24ff  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004b2505  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2507  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004b250b  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004b2511  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2513  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004b2517  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004b251d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b251f  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004b2523  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004b2529  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b252b  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004b252f  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004b2535  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2537  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004b253b  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004b2541  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2543  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004b2547  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004b254d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b254f  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004b2553  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004b2559  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b255b  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004b255f  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004b2565  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2567  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004b256b  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004b2571  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2573  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004b2577  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004b257d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b257f  d99650010000           -fst dword ptr [esi + 0x150]
    app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */) = float(cpu.fpu.st(0));
    // 004b2585  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004b2587  d95820                 -fstp dword ptr [eax + 0x20]
    app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b258a  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004b258d  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004b2593  d84024                 -fadd dword ptr [eax + 0x24]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */));
    // 004b2596  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004b259a  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004b25a0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b25a2  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004b25a6  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004b25ac  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b25ae  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004b25b2  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004b25b8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b25ba  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004b25be  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004b25c4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b25c6  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004b25ca  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004b25d0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b25d2  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004b25d6  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004b25dc  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b25de  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004b25e2  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004b25e8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b25ea  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004b25ee  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004b25f4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b25f6  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004b25fa  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004b2600  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2602  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004b2606  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004b260c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b260e  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004b2612  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004b2618  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b261a  d9964c010000           -fst dword ptr [esi + 0x14c]
    app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */) = float(cpu.fpu.st(0));
    // 004b2620  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2622  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b2625  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004b2628  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004b262e  d84028                 -fadd dword ptr [eax + 0x28]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */));
    // 004b2631  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004b2635  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004b263b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b263d  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004b2641  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004b2647  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2649  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004b264d  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004b2653  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2655  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004b2659  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004b265f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2661  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004b2665  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004b266b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b266d  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004b2671  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004b2677  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2679  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004b267d  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004b2683  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2685  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004b2689  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004b268f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2691  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004b2695  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004b269b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b269d  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004b26a1  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004b26a7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b26a9  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004b26ad  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004b26b3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b26b5  d99e48010000           -fstp dword ptr [esi + 0x148]
    app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b26bb  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 004b26bf  d98648010000           -fld dword ptr [esi + 0x148]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */)));
    // 004b26c5  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004b26c7  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b26ca  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004b26cd  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004b26d3  d8402c                 -fadd dword ptr [eax + 0x2c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */));
    // 004b26d6  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004b26da  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004b26e0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b26e2  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004b26e6  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004b26ec  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b26ee  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004b26f2  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004b26f8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b26fa  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004b26fe  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004b2704  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2706  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004b270a  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004b2710  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2712  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004b2716  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004b271c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b271e  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004b2722  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004b2728  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b272a  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004b272e  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004b2734  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2736  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004b273a  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004b2740  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2742  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004b2746  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004b274c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b274e  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004b2752  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004b2758  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b275a  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004b275d  d99644010000           -fst dword ptr [esi + 0x144]
    app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */) = float(cpu.fpu.st(0));
    // 004b2763  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b2765  42                     -inc edx
    (cpu.edx)++;
    // 004b2766  d958fc                 -fstp dword ptr [eax - 4]
    app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b2769  39da                   +cmp edx, ebx
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
    // 004b276b  0f8c92f8ffff           -jl 0x4b2003
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b2003;
    }
L_0x004b2771:
    // 004b2771  83c434                 +add esp, 0x34
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
    // 004b2774  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2775  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2776  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2777:
    // 004b2777  c74424300000404b       -mov dword ptr [esp + 0x30], 0x4b400000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = 1262485504 /*0x4b400000*/;
    // 004b277f  e959f8ffff             -jmp 0x4b1fdd
    goto L_0x004b1fdd;
}

/* align: skip  */
void Application::sub_4b2784(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2784  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2785  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2786  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b2789  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b278b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b278d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b278e  ff15c8b24c00           -call dword ptr [0x4cb2c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5026504) /* 0x4cb2c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b2794  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2796  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b279b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b279d  c7430808000000         -mov dword ptr [ebx + 8], 8
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 004b27a4  46                     -inc esi
    (cpu.esi)++;
    // 004b27a5  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b27a8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b27aa  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 004b27ac  e8aff4ffff             -call 0x4b1c60
    cpu.esp -= 4;
    sub_4b1c60(app, cpu);
    if (cpu.terminate) return;
    // 004b27b1  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004b27b6  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b27b9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b27bb  e8a0f4ffff             -call 0x4b1c60
    cpu.esp -= 4;
    sub_4b1c60(app, cpu);
    if (cpu.terminate) return;
    // 004b27c0  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004b27c5  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b27c7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b27c9  895310                 -mov dword ptr [ebx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004b27cc  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004b27d1  e88af4ffff             -call 0x4b1c60
    cpu.esp -= 4;
    sub_4b1c60(app, cpu);
    if (cpu.terminate) return;
    // 004b27d6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b27d8  40                     -inc eax
    (cpu.eax)++;
    // 004b27d9  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b27dd  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b27e1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b27e3  df6c2404               -fild qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004b27e7  dc0d40fc4b00           -fmul qword ptr [0x4bfc40]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4979776) /* 0x4bfc40 */));
    // 004b27ed  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004b27f1  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 004b27f6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b27f8  d95b14                 -fstp dword ptr [ebx + 0x14]
    app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b27fb  e860f4ffff             -call 0x4b1c60
    cpu.esp -= 4;
    sub_4b1c60(app, cpu);
    if (cpu.terminate) return;
    // 004b2800  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b2804  df6c2404               -fild qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004b2808  dc0d48fc4b00           -fmul qword ptr [0x4bfc48]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4979784) /* 0x4bfc48 */));
    // 004b280e  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b2811  dc0550fc4b00           -fadd qword ptr [0x4bfc50]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4979792) /* 0x4bfc50 */));
    // 004b2817  8d9300010000           -lea edx, [ebx + 0x100]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(256) /* 0x100 */);
    // 004b281d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004b281e:
    // 004b281e  d94010                 -fld dword ptr [eax + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */)));
    // 004b2821  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b2823  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2826  d95810                 -fstp dword ptr [eax + 0x10]
    app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b2829  39d0                   +cmp eax, edx
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
    // 004b282b  75f1                   -jne 0x4b281e
    if (!cpu.flags.zf)
    {
        goto L_0x004b281e;
    }
    // 004b282d  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b282f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b2831  8d5330                 -lea edx, [ebx + 0x30]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(48) /* 0x30 */);
L_0x004b2834:
    // 004b2834  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2837  c7801001000000000000   -mov dword ptr [eax + 0x110], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(272) /* 0x110 */) = 0 /*0x0*/;
    // 004b2841  c7804001000000000000   -mov dword ptr [eax + 0x140], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(320) /* 0x140 */) = 0 /*0x0*/;
    // 004b284b  39d0                   +cmp eax, edx
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
    // 004b284d  75e5                   -jne 0x4b2834
    if (!cpu.flags.zf)
    {
        goto L_0x004b2834;
    }
    // 004b284f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b2851  81c310050000           -add ebx, 0x510
    (cpu.ebx) += x86::reg32(x86::sreg32(1296 /*0x510*/));
L_0x004b2857:
    // 004b2857  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b285a  c7807001000000000000   -mov dword ptr [eax + 0x170], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(368) /* 0x170 */) = 0 /*0x0*/;
    // 004b2864  39d8                   +cmp eax, ebx
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
    // 004b2866  75ef                   -jne 0x4b2857
    if (!cpu.flags.zf)
    {
        goto L_0x004b2857;
    }
    // 004b2868  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b286b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b286c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b286d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b2870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2870  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2871  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2872  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2873  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b2874  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b2875  81ec30020000           -sub esp, 0x230
    (cpu.esp) -= x86::reg32(x86::sreg32(560 /*0x230*/));
    // 004b287b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b287d  89942414020000         -mov dword ptr [esp + 0x214], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */) = cpu.edx;
    // 004b2884  ff15c8b24c00           -call dword ptr [0x4cb2c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5026504) /* 0x4cb2c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b288a  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 004b288f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2891  e8caf3ffff             -call 0x4b1c60
    cpu.esp -= 4;
    sub_4b1c60(app, cpu);
    if (cpu.terminate) return;
    // 004b2896  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004b2899  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b289b  39c8                   +cmp eax, ecx
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
    // 004b289d  0f838b020000           -jae 0x4b2b2e
    if (!cpu.flags.cf)
    {
        goto L_0x004b2b2e;
    }
    // 004b28a3  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x004b28a8:
    // 004b28a8  d9049598da4c00         -fld dword ptr [edx*4 + 0x4cda98]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036696) /* 0x4cda98 */ + cpu.edx * 4)));
    // 004b28af  d8a614010000           -fsub dword ptr [esi + 0x114]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(276) /* 0x114 */));
    // 004b28b5  dc0d58fc4b00           -fmul qword ptr [0x4bfc58]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4979800) /* 0x4bfc58 */));
    // 004b28bb  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004b28c0  8d7e04                 -lea edi, [esi + 4]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b28c3  d99c24d8010000         -fstp dword ptr [esp + 0x1d8]
    app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b28ca  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
L_0x004b28cf:
    // 004b28cf  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b28d1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b28d3  e888f3ffff             -call 0x4b1c60
    cpu.esp -= 4;
    sub_4b1c60(app, cpu);
    if (cpu.terminate) return;
    // 004b28d8  d9048598da4c00         -fld dword ptr [eax*4 + 0x4cda98]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036696) /* 0x4cda98 */ + cpu.eax * 4)));
    // 004b28df  d8a714010000           -fsub dword ptr [edi + 0x114]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(276) /* 0x114 */));
    // 004b28e5  dc0d58fc4b00           -fmul qword ptr [0x4bfc58]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4979800) /* 0x4bfc58 */));
    // 004b28eb  41                     -inc ecx
    (cpu.ecx)++;
    // 004b28ec  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b28ef  d99c8cd4010000         -fstp dword ptr [esp + ecx*4 + 0x1d4]
    app->getMemory<float>(cpu.esp + x86::reg32(468) /* 0x1d4 */ + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b28f6  83f904                 +cmp ecx, 4
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
    // 004b28f9  7cd4                   -jl 0x4b28cf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b28cf;
    }
    // 004b28fb  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004b2900  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
    // 004b2905  8d7e10                 -lea edi, [esi + 0x10]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
L_0x004b2908:
    // 004b2908  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b290a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b290c  e84ff3ffff             -call 0x4b1c60
    cpu.esp -= 4;
    sub_4b1c60(app, cpu);
    if (cpu.terminate) return;
    // 004b2911  d90485d8da4c00         -fld dword ptr [eax*4 + 0x4cdad8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036760) /* 0x4cdad8 */ + cpu.eax * 4)));
    // 004b2918  d8a714010000           -fsub dword ptr [edi + 0x114]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(276) /* 0x114 */));
    // 004b291e  dc0d58fc4b00           -fmul qword ptr [0x4bfc58]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4979800) /* 0x4bfc58 */));
    // 004b2924  41                     -inc ecx
    (cpu.ecx)++;
    // 004b2925  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2928  d99c8cd4010000         -fstp dword ptr [esp + ecx*4 + 0x1d4]
    app->getMemory<float>(cpu.esp + x86::reg32(468) /* 0x1d4 */ + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b292f  83f90c                 +cmp ecx, 0xc
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
    // 004b2932  7cd4                   -jl 0x4b2908
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b2908;
    }
    // 004b2934  bbd8000000             -mov ebx, 0xd8
    cpu.ebx = 216 /*0xd8*/;
    // 004b2939  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b293b  899c2420020000         -mov dword ptr [esp + 0x220], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.ebx;
L_0x004b2942:
    // 004b2942  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 004b2947  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2949  e812f3ffff             -call 0x4b1c60
    cpu.esp -= 4;
    sub_4b1c60(app, cpu);
    if (cpu.terminate) return;
    // 004b294e  8b942420020000         -mov edx, dword ptr [esp + 0x220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 004b2955  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2957  8994242c020000         -mov dword ptr [esp + 0x22c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(556) /* 0x22c */) = cpu.edx;
    // 004b295e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2960  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004b2965  e8f6f2ffff             -call 0x4b1c60
    cpu.esp -= 4;
    sub_4b1c60(app, cpu);
    if (cpu.terminate) return;
    // 004b296a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b296c  89842408020000         -mov dword ptr [esp + 0x208], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(520) /* 0x208 */) = cpu.eax;
    // 004b2973  8994240c020000         -mov dword ptr [esp + 0x20c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */) = cpu.edx;
    // 004b297a  dfac2408020000         -fild qword ptr [esp + 0x208]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(520) /* 0x208 */))));
    // 004b2981  dc0d60fc4b00           -fmul qword ptr [0x4bfc60]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4979808) /* 0x4bfc60 */));
    // 004b2987  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2989  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 004b298e  d99c2424020000         -fstp dword ptr [esp + 0x224]
    app->getMemory<float>(cpu.esp + x86::reg32(548) /* 0x224 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b2995  e8c6f2ffff             -call 0x4b1c60
    cpu.esp -= 4;
    sub_4b1c60(app, cpu);
    if (cpu.terminate) return;
    // 004b299a  8b448614               -mov eax, dword ptr [esi + eax*4 + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */ + cpu.eax * 4);
    // 004b299e  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b29a1  89842428020000         -mov dword ptr [esp + 0x228], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(552) /* 0x228 */) = cpu.eax;
    // 004b29a8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b29aa  0f8585010000           -jne 0x4b2b35
    if (!cpu.flags.zf)
    {
        goto L_0x004b2b35;
    }
    // 004b29b0  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004b29b5  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b29b9  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b29bb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b29bd  e856f3ffff             -call 0x4b1d18
    cpu.esp -= 4;
    sub_4b1d18(app, cpu);
    if (cpu.terminate) return;
L_0x004b29c2:
    // 004b29c2  8b94242c020000         -mov edx, dword ptr [esp + 0x22c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(556) /* 0x22c */);
    // 004b29c9  8d0c3e                 -lea ecx, [esi + edi]
    cpu.ecx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 004b29cc  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004b29cf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b29d1  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b29d3  d9842428020000         -fld dword ptr [esp + 0x228]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(552) /* 0x228 */)));
    // 004b29da  d9842424020000         -fld dword ptr [esp + 0x224]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(548) /* 0x224 */)));
L_0x004b29e1:
    // 004b29e1  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b29e3  d88a74010000           -fmul dword ptr [edx + 0x174]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(372) /* 0x174 */));
    // 004b29e9  d9c2                   -fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 004b29eb  d84c0414               -fmul dword ptr [esp + eax + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */ + cpu.eax * 1));
    // 004b29ef  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b29f2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b29f5  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b29f7  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b29fa  d99980060000           -fstp dword ptr [ecx + 0x680]
    app->getMemory<float>(cpu.ecx + x86::reg32(1664) /* 0x680 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b2a00  3db0010000             +cmp eax, 0x1b0
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
    // 004b2a05  75da                   -jne 0x4b29e1
    if (!cpu.flags.zf)
    {
        goto L_0x004b29e1;
    }
    // 004b2a07  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b2a09  8b9c2420020000         -mov ebx, dword ptr [esp + 0x220]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 004b2a10  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b2a12  83c36c                 -add ebx, 0x6c
    (cpu.ebx) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004b2a15  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b2a17  899c2420020000         -mov dword ptr [esp + 0x220], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.ebx;
    // 004b2a1e  81ffc0060000           +cmp edi, 0x6c0
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
    // 004b2a24  0f8518ffffff           -jne 0x4b2942
    if (!cpu.flags.zf)
    {
        goto L_0x004b2942;
    }
    // 004b2a2a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2a2c  8d9610050000           -lea edx, [esi + 0x510]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1296) /* 0x510 */);
L_0x004b2a32:
    // 004b2a32  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2a35  8b8830080000           -mov ecx, dword ptr [eax + 0x830]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2096) /* 0x830 */);
    // 004b2a3b  898870010000           -mov dword ptr [eax + 0x170], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(368) /* 0x170 */) = cpu.ecx;
    // 004b2a41  39d0                   +cmp eax, edx
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
    // 004b2a43  75ed                   -jne 0x4b2a32
    if (!cpu.flags.zf)
    {
        goto L_0x004b2a32;
    }
    // 004b2a45  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2a47  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x004b2a49:
    // 004b2a49  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2a4c  d98484d8010000         -fld dword ptr [esp + eax*4 + 0x1d8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */ + cpu.eax * 4)));
    // 004b2a53  d88210010000           -fadd dword ptr [edx + 0x110]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */));
    // 004b2a59  40                     -inc eax
    (cpu.eax)++;
    // 004b2a5a  d99a10010000           -fstp dword ptr [edx + 0x110]
    app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b2a60  83f80c                 +cmp eax, 0xc
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
    // 004b2a63  7ce4                   -jl 0x4b2a49
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b2a49;
    }
    // 004b2a65  8b8c2414020000         -mov ecx, dword ptr [esp + 0x214]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 004b2a6c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004b2a71  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2a73  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2a75  e84ef5ffff             -call 0x4b1fc8
    cpu.esp -= 4;
    sub_4b1fc8(app, cpu);
    if (cpu.terminate) return;
    // 004b2a7a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2a7c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004b2a7e:
    // 004b2a7e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2a81  d98494d8010000         -fld dword ptr [esp + edx*4 + 0x1d8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */ + cpu.edx * 4)));
    // 004b2a88  d88010010000           -fadd dword ptr [eax + 0x110]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(272) /* 0x110 */));
    // 004b2a8e  42                     -inc edx
    (cpu.edx)++;
    // 004b2a8f  d99810010000           -fstp dword ptr [eax + 0x110]
    app->getMemory<float>(cpu.eax + x86::reg32(272) /* 0x110 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b2a95  83fa0c                 +cmp edx, 0xc
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
    // 004b2a98  7ce4                   -jl 0x4b2a7e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b2a7e;
    }
    // 004b2a9a  8b8c2414020000         -mov ecx, dword ptr [esp + 0x214]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 004b2aa1  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004b2aa6  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 004b2aab  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2aad  e816f5ffff             -call 0x4b1fc8
    cpu.esp -= 4;
    sub_4b1fc8(app, cpu);
    if (cpu.terminate) return;
    // 004b2ab2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b2ab4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b2ab6:
    // 004b2ab6  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2ab9  d98484d8010000         -fld dword ptr [esp + eax*4 + 0x1d8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */ + cpu.eax * 4)));
    // 004b2ac0  d88210010000           -fadd dword ptr [edx + 0x110]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */));
    // 004b2ac6  40                     -inc eax
    (cpu.eax)++;
    // 004b2ac7  d99a10010000           -fstp dword ptr [edx + 0x110]
    app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b2acd  83f80c                 +cmp eax, 0xc
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
    // 004b2ad0  7ce4                   -jl 0x4b2ab6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b2ab6;
    }
    // 004b2ad2  8b8c2414020000         -mov ecx, dword ptr [esp + 0x214]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 004b2ad9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004b2ade  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 004b2ae3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2ae5  e8def4ffff             -call 0x4b1fc8
    cpu.esp -= 4;
    sub_4b1fc8(app, cpu);
    if (cpu.terminate) return;
    // 004b2aea  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b2aec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b2aee:
    // 004b2aee  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2af1  d98484d8010000         -fld dword ptr [esp + eax*4 + 0x1d8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */ + cpu.eax * 4)));
    // 004b2af8  d88210010000           -fadd dword ptr [edx + 0x110]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */));
    // 004b2afe  40                     -inc eax
    (cpu.eax)++;
    // 004b2aff  d99a10010000           -fstp dword ptr [edx + 0x110]
    app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b2b05  83f80c                 +cmp eax, 0xc
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
    // 004b2b08  7ce4                   -jl 0x4b2aee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b2aee;
    }
    // 004b2b0a  8b8c2414020000         -mov ecx, dword ptr [esp + 0x214]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 004b2b11  bb21000000             -mov ebx, 0x21
    cpu.ebx = 33 /*0x21*/;
    // 004b2b16  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 004b2b1b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2b1d  e8a6f4ffff             -call 0x4b1fc8
    cpu.esp -= 4;
    sub_4b1fc8(app, cpu);
    if (cpu.terminate) return;
    // 004b2b22  81c430020000           -add esp, 0x230
    (cpu.esp) += x86::reg32(x86::sreg32(560 /*0x230*/));
    // 004b2b28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2b29  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2b2a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2b2b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2b2c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2b2d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2b2e:
    // 004b2b2e  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004b2b30  e973fdffff             -jmp 0x4b28a8
    goto L_0x004b28a8;
L_0x004b2b35:
    // 004b2b35  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b2b3a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2b3c  e81ff1ffff             -call 0x4b1c60
    cpu.esp -= 4;
    sub_4b1c60(app, cpu);
    if (cpu.terminate) return;
    // 004b2b41  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b2b46  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b2b48  89842418020000         -mov dword ptr [esp + 0x218], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */) = cpu.eax;
    // 004b2b4f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2b51  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b2b55  e806f1ffff             -call 0x4b1c60
    cpu.esp -= 4;
    sub_4b1c60(app, cpu);
    if (cpu.terminate) return;
    // 004b2b5a  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004b2b5d  89842410020000         -mov dword ptr [esp + 0x210], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */) = cpu.eax;
    // 004b2b64  898c241c020000         -mov dword ptr [esp + 0x21c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = cpu.ecx;
    // 004b2b6b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b2b6d  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2b6f  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004b2b74  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2b76  e89df1ffff             -call 0x4b1d18
    cpu.esp -= 4;
    sub_4b1d18(app, cpu);
    if (cpu.terminate) return;
    // 004b2b7b  83bc241002000000       +cmp dword ptr [esp + 0x210], 0
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
    // 004b2b83  7424                   -je 0x4b2ba9
    if (cpu.flags.zf)
    {
        goto L_0x004b2ba9;
    }
    // 004b2b85  8b94241c020000         -mov edx, dword ptr [esp + 0x21c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */);
    // 004b2b8c  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004b2b8e  8d4218                 -lea eax, [edx + 0x18]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004b2b91  81c2c8010000           -add edx, 0x1c8
    (cpu.edx) += x86::reg32(x86::sreg32(456 /*0x1c8*/));
L_0x004b2b97:
    // 004b2b97  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b2b9a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2b9c  894c04f8               -mov dword ptr [esp + eax - 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-8) /* -0x8 */ + cpu.eax * 1) = cpu.ecx;
    // 004b2ba0  39d0                   +cmp eax, edx
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
    // 004b2ba2  75f3                   -jne 0x4b2b97
    if (!cpu.flags.zf)
    {
        goto L_0x004b2b97;
    }
    // 004b2ba4  e919feffff             -jmp 0x4b29c2
    goto L_0x004b29c2;
L_0x004b2ba9:
    // 004b2ba9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b2bab:
    // 004b2bab  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2bae  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2bb0  894c04fc               -mov dword ptr [esp + eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.ecx;
    // 004b2bb4  83f814                 +cmp eax, 0x14
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
    // 004b2bb7  75f2                   -jne 0x4b2bab
    if (!cpu.flags.zf)
    {
        goto L_0x004b2bab;
    }
    // 004b2bb9  b8c4010000             -mov eax, 0x1c4
    cpu.eax = 452 /*0x1c4*/;
L_0x004b2bbe:
    // 004b2bbe  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2bc1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b2bc3  895c04fc               -mov dword ptr [esp + eax - 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.ebx;
    // 004b2bc7  3dd8010000             +cmp eax, 0x1d8
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
    // 004b2bcc  75f0                   -jne 0x4b2bbe
    if (!cpu.flags.zf)
    {
        goto L_0x004b2bbe;
    }
    // 004b2bce  8b942418020000         -mov edx, dword ptr [esp + 0x218]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 004b2bd5  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b2bd9  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004b2bdc  29d0                   +sub eax, edx
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
    // 004b2bde  e8d9f2ffff             -call 0x4b1ebc
    cpu.esp -= 4;
    sub_4b1ebc(app, cpu);
    if (cpu.terminate) return;
    // 004b2be3  d9842428020000         +fld dword ptr [esp + 0x228]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(552) /* 0x228 */)));
    // 004b2bea  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b2bec  dc0d68fc4b00           +fmul qword ptr [0x4bfc68]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4979816) /* 0x4bfc68 */));
    // 004b2bf2  ddd9                   +fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b2bf4  d99c2428020000         +fstp dword ptr [esp + 0x228]
    app->getMemory<float>(cpu.esp + x86::reg32(552) /* 0x228 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b2bfb  e9c2fdffff             -jmp 0x4b29c2
    goto L_0x004b29c2;
}

/* align: skip  */
void Application::sub_4b2c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2c00  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2c03  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b2c05  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004b2c07  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2c0a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2c0b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2c0b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2c0c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2c0d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2c0e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2c11  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b2c13  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b2c15  ff1560c14c00           -call dword ptr [0x4cc160]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030240) /* 0x4cc160 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b2c1b  b830ac4c00             -mov eax, 0x4cac30
    cpu.eax = 5024816 /*0x4cac30*/;
    // 004b2c20  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004b2c22  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2c24  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004b2c26  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
    // 004b2c29  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b2c2b  e815000000             -call 0x4b2c45
    cpu.esp -= 4;
    sub_4b2c45(app, cpu);
    if (cpu.terminate) return;
    // 004b2c30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b2c32  0f85a8010000           -jne 0x4b2de0
    if (!cpu.flags.zf)
    {
        return sub_4b2de0(app, cpu);
    }
    // 004b2c38  ff1568c14c00           -call dword ptr [0x4cc168]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030248) /* 0x4cc168 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b2c3e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2c40  e9a3010000             -jmp 0x4b2de8
    return sub_4b2de8(app, cpu);
}

/* align: skip  */
void Application::sub_4b2c45(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2c45  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2c46  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b2c47  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b2c48  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b2c4b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b2c4c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b2c4e  8d430b                 -lea eax, [ebx + 0xb]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(11) /* 0xb */);
    // 004b2c51  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004b2c53  39d8                   +cmp eax, ebx
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
    // 004b2c55  7307                   -jae 0x4b2c5e
    if (!cpu.flags.cf)
    {
        goto L_0x004b2c5e;
    }
    // 004b2c57  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b2c5c  eb0a                   -jmp 0x4b2c68
    goto L_0x004b2c68;
L_0x004b2c5e:
    // 004b2c5e  83f810                 +cmp eax, 0x10
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
    // 004b2c61  7305                   -jae 0x4b2c68
    if (!cpu.flags.cf)
    {
        goto L_0x004b2c68;
    }
    // 004b2c63  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
L_0x004b2c68:
    // 004b2c68  8d57fc                 -lea edx, [edi - 4]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 004b2c6b  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b2c6f  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004b2c71  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004b2c74  39d0                   +cmp eax, edx
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
    // 004b2c76  0f86fc000000           -jbe 0x4b2d78
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b2d78;
    }
    // 004b2c7c  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b2c80  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2c82  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004b2c84:
    // 004b2c84  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004b2c86  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b2c88  83fdff                 +cmp ebp, -1
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2c8b  750a                   -jne 0x4b2c97
    if (!cpu.flags.zf)
    {
        goto L_0x004b2c97;
    }
    // 004b2c8d  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 004b2c92  e940010000             -jmp 0x4b2dd7
    goto L_0x004b2dd7;
L_0x004b2c97:
    // 004b2c97  f7c501000000           +test ebp, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & 1 /*0x1*/));
    // 004b2c9d  0f85ce000000           -jne 0x4b2d71
    if (!cpu.flags.zf)
    {
        goto L_0x004b2d71;
    }
    // 004b2ca3  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b2ca6  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b2caa  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b2cad  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004b2caf  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b2cb3  b830ac4c00             -mov eax, 0x4cac30
    cpu.eax = 5024816 /*0x4cac30*/;
    // 004b2cb8  663b1424               +cmp dx, word ptr [esp]
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.esp)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b2cbc  751d                   -jne 0x4b2cdb
    if (!cpu.flags.zf)
    {
        goto L_0x004b2cdb;
    }
    // 004b2cbe  8b3530ac4c00           -mov esi, dword ptr [0x4cac30]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5024816) /* 0x4cac30 */);
    // 004b2cc4  eb0f                   -jmp 0x4b2cd5
    goto L_0x004b2cd5;
L_0x004b2cc6:
    // 004b2cc6  39fe                   +cmp esi, edi
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
    // 004b2cc8  7708                   -ja 0x4b2cd2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b2cd2;
    }
    // 004b2cca  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b2ccc  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b2cce  39f8                   +cmp eax, edi
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
    // 004b2cd0  7709                   -ja 0x4b2cdb
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b2cdb;
    }
L_0x004b2cd2:
    // 004b2cd2  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
L_0x004b2cd5:
    // 004b2cd5  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 004b2cd9  75eb                   -jne 0x4b2cc6
    if (!cpu.flags.zf)
    {
        goto L_0x004b2cc6;
    }
L_0x004b2cdb:
    // 004b2cdb  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b2cde  39d3                   +cmp ebx, edx
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
    // 004b2ce0  7506                   -jne 0x4b2ce8
    if (!cpu.flags.zf)
    {
        goto L_0x004b2ce8;
    }
    // 004b2ce2  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004b2ce5  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004b2ce8:
    // 004b2ce8  3b29                   +cmp ebp, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2cea  720b                   -jb 0x4b2cf7
    if (cpu.flags.cf)
    {
        goto L_0x004b2cf7;
    }
    // 004b2cec  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b2cee  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004b2cf0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2cf2  83f810                 +cmp eax, 0x10
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
    // 004b2cf5  7334                   -jae 0x4b2d2b
    if (!cpu.flags.cf)
    {
        goto L_0x004b2d2b;
    }
L_0x004b2cf7:
    // 004b2cf7  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b2cfb  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b2cff  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b2d02  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2d04  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b2d08  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b2d0b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b2d0f  0128                   -add dword ptr [eax], ebp
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004b2d11  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004b2d14  48                     -dec eax
    (cpu.eax)--;
    // 004b2d15  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004b2d17  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004b2d1a  881511615400           -mov byte ptr [0x546111], dl
    app->getMemory<x86::reg8>(x86::reg32(5529873) /* 0x546111 */) = cpu.dl;
    // 004b2d20  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004b2d22  39d5                   +cmp ebp, edx
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
    // 004b2d24  7240                   -jb 0x4b2d66
    if (cpu.flags.cf)
    {
        goto L_0x004b2d66;
    }
    // 004b2d26  e9aa000000             -jmp 0x4b2dd5
    goto L_0x004b2dd5;
L_0x004b2d2b:
    // 004b2d2b  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b2d2d  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b2d2f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b2d33  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b2d36  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b2d3a  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b2d3d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b2d41  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b2d44  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b2d48  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b2d4b  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b2d4f  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004b2d51  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 004b2d53  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b2d55  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b2d57  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 004b2d59  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 004b2d5b  882511615400           -mov byte ptr [0x546111], ah
    app->getMemory<x86::reg8>(x86::reg32(5529873) /* 0x546111 */) = cpu.ah;
    // 004b2d61  e971000000             -jmp 0x4b2dd7
    goto L_0x004b2dd7;
L_0x004b2d66:
    // 004b2d66  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2d68  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b2d6a  01eb                   +add ebx, ebp
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
    // 004b2d6c  e913ffffff             -jmp 0x4b2c84
    goto L_0x004b2c84;
L_0x004b2d71:
    // 004b2d71  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004b2d76  eb5f                   -jmp 0x4b2dd7
    goto L_0x004b2dd7;
L_0x004b2d78:
    // 004b2d78  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2d7a  83fa10                 +cmp edx, 0x10
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
    // 004b2d7d  7256                   -jb 0x4b2dd5
    if (cpu.flags.cf)
    {
        goto L_0x004b2dd5;
    }
    // 004b2d7f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b2d81  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b2d85  80cb01                 -or bl, 1
    cpu.bl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b2d88  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b2d8b  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 004b2d8d  8d1c01                 -lea ebx, [ecx + eax]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 004b2d90  b830ac4c00             -mov eax, 0x4cac30
    cpu.eax = 5024816 /*0x4cac30*/;
    // 004b2d95  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b2d99  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b2d9b  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004b2d9d  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b2da0  6639da                 +cmp dx, bx
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b2da3  751d                   -jne 0x4b2dc2
    if (!cpu.flags.zf)
    {
        goto L_0x004b2dc2;
    }
    // 004b2da5  8b3530ac4c00           -mov esi, dword ptr [0x4cac30]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5024816) /* 0x4cac30 */);
    // 004b2dab  eb0f                   -jmp 0x4b2dbc
    goto L_0x004b2dbc;
L_0x004b2dad:
    // 004b2dad  39fe                   +cmp esi, edi
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
    // 004b2daf  7708                   -ja 0x4b2db9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b2db9;
    }
    // 004b2db1  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b2db3  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b2db5  39f8                   +cmp eax, edi
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
    // 004b2db7  7709                   -ja 0x4b2dc2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b2dc2;
    }
L_0x004b2db9:
    // 004b2db9  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
L_0x004b2dbc:
    // 004b2dbc  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 004b2dc0  75eb                   -jne 0x4b2dad
    if (!cpu.flags.zf)
    {
        goto L_0x004b2dad;
    }
L_0x004b2dc2:
    // 004b2dc2  8b7e18                 -mov edi, dword ptr [esi + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004b2dc5  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b2dc9  47                     -inc edi
    (cpu.edi)++;
    // 004b2dca  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2dcd  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004b2dd0  e8747efeff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
L_0x004b2dd5:
    // 004b2dd5  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004b2dd7:
    // 004b2dd7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b2dd9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b2ddc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2ddd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2dde  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2ddf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2de0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2de0  ff1568c14c00           -call dword ptr [0x4cc168]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030248) /* 0x4cc168 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b2de6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2de8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2deb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2dec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2ded  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2dee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2de8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b2de8;
    // 004b2de0  ff1568c14c00           -call dword ptr [0x4cc168]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030248) /* 0x4cc168 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b2de6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_entry_0x004b2de8:
    // 004b2de8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2deb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2dec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2ded  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2dee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2def(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2def  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2df1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2df2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2df2  ff15f4de4c00           -call dword ptr [0x4cdef4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5037812) /* 0x4cdef4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b2df8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2df9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2df9  ff15f8de4c00           -call dword ptr [0x4cdef8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5037816) /* 0x4cdef8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b2dff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2e00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2e00  ff15fcde4c00           -call dword ptr [0x4cdefc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5037820) /* 0x4cdefc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b2e06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2e07(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2e07  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2e08  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2e09  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b2e0b  7410                   -je 0x4b2e1d
    if (cpu.flags.zf)
    {
        goto L_0x004b2e1d;
    }
    // 004b2e0d  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b2e0f  8b35f4de4c00           -mov esi, dword ptr [0x4cdef4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5037812) /* 0x4cdef4 */);
    // 004b2e15  890df4de4c00           -mov dword ptr [0x4cdef4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5037812) /* 0x4cdef4 */) = cpu.ecx;
    // 004b2e1b  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
L_0x004b2e1d:
    // 004b2e1d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b2e1f  740f                   -je 0x4b2e30
    if (cpu.flags.zf)
    {
        goto L_0x004b2e30;
    }
    // 004b2e21  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004b2e23  8b0df8de4c00           -mov ecx, dword ptr [0x4cdef8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5037816) /* 0x4cdef8 */);
    // 004b2e29  a3f8de4c00             -mov dword ptr [0x4cdef8], eax
    app->getMemory<x86::reg32>(x86::reg32(5037816) /* 0x4cdef8 */) = cpu.eax;
    // 004b2e2e  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
L_0x004b2e30:
    // 004b2e30  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b2e32  740f                   -je 0x4b2e43
    if (cpu.flags.zf)
    {
        goto L_0x004b2e43;
    }
    // 004b2e34  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b2e36  8b15fcde4c00           -mov edx, dword ptr [0x4cdefc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5037820) /* 0x4cdefc */);
    // 004b2e3c  a3fcde4c00             -mov dword ptr [0x4cdefc], eax
    app->getMemory<x86::reg32>(x86::reg32(5037820) /* 0x4cdefc */) = cpu.eax;
    // 004b2e41  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x004b2e43:
    // 004b2e43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2e44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2e45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2e46(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2e46  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2e47  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2e48  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b2e49  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2e4a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b2e4b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b2e4c  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b2e4f  b870fc4b00             -mov eax, 0x4bfc70
    cpu.eax = 4979824 /*0x4bfc70*/;
    // 004b2e54  e8a06effff             -call 0x4a9cf9
    cpu.esp -= 4;
    sub_4a9cf9(app, cpu);
    if (cpu.terminate) return;
    // 004b2e59  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b2e5b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b2e5d  0f84f9000000           -je 0x4b2f5c
    if (cpu.flags.zf)
    {
        goto L_0x004b2f5c;
    }
L_0x004b2e63:
    // 004b2e63  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2e66  0f84e6000000           -je 0x4b2f52
    if (cpu.flags.zf)
    {
        goto L_0x004b2f52;
    }
    // 004b2e6c  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 004b2e6e  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x004b2e70:
    // 004b2e70  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b2e72  3ac2                   +cmp al, dl
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
    // 004b2e74  7412                   -je 0x4b2e88
    if (cpu.flags.zf)
    {
        goto L_0x004b2e88;
    }
    // 004b2e76  3c00                   +cmp al, 0
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
    // 004b2e78  740c                   -je 0x4b2e86
    if (cpu.flags.zf)
    {
        goto L_0x004b2e86;
    }
    // 004b2e7a  46                     -inc esi
    (cpu.esi)++;
    // 004b2e7b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b2e7d  3ac2                   +cmp al, dl
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
    // 004b2e7f  7407                   -je 0x4b2e88
    if (cpu.flags.zf)
    {
        goto L_0x004b2e88;
    }
    // 004b2e81  46                     -inc esi
    (cpu.esi)++;
    // 004b2e82  3c00                   +cmp al, 0
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
    // 004b2e84  75ea                   -jne 0x4b2e70
    if (!cpu.flags.zf)
    {
        goto L_0x004b2e70;
    }
L_0x004b2e86:
    // 004b2e86  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004b2e88:
    // 004b2e88  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b2e8a  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004b2e8c  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2e8e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b2e90  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b2e92  e86575fcff             -call 0x47a3fc
    cpu.esp -= 4;
    sub_47a3fc(app, cpu);
    if (cpu.terminate) return;
    // 004b2e97  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004b2e9c  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004b2e9e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b2ea0  881434                 -mov byte ptr [esp + esi], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dl;
    // 004b2ea3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2ea5  e898060000             -call 0x4b3542
    cpu.esp -= 4;
    sub_4b3542(app, cpu);
    if (cpu.terminate) return;
    // 004b2eaa  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004b2ead  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 004b2eaf  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b2eb1  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x004b2eb3:
    // 004b2eb3  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b2eb5  3ac2                   +cmp al, dl
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
    // 004b2eb7  7412                   -je 0x4b2ecb
    if (cpu.flags.zf)
    {
        goto L_0x004b2ecb;
    }
    // 004b2eb9  3c00                   +cmp al, 0
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
    // 004b2ebb  740c                   -je 0x4b2ec9
    if (cpu.flags.zf)
    {
        goto L_0x004b2ec9;
    }
    // 004b2ebd  46                     -inc esi
    (cpu.esi)++;
    // 004b2ebe  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b2ec0  3ac2                   +cmp al, dl
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
    // 004b2ec2  7407                   -je 0x4b2ecb
    if (cpu.flags.zf)
    {
        goto L_0x004b2ecb;
    }
    // 004b2ec4  46                     -inc esi
    (cpu.esi)++;
    // 004b2ec5  3c00                   +cmp al, 0
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
    // 004b2ec7  75ea                   -jne 0x4b2eb3
    if (!cpu.flags.zf)
    {
        goto L_0x004b2eb3;
    }
L_0x004b2ec9:
    // 004b2ec9  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004b2ecb:
    // 004b2ecb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b2ecd  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004b2ecf  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2ed1  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b2ed3  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b2ed5  e82275fcff             -call 0x47a3fc
    cpu.esp -= 4;
    sub_47a3fc(app, cpu);
    if (cpu.terminate) return;
    // 004b2eda  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004b2edf  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004b2ee1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b2ee3  883434                 -mov byte ptr [esp + esi], dh
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dh;
    // 004b2ee6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2ee8  e855060000             -call 0x4b3542
    cpu.esp -= 4;
    sub_4b3542(app, cpu);
    if (cpu.terminate) return;
    // 004b2eed  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004b2ef0  b22a                   -mov dl, 0x2a
    cpu.dl = 42 /*0x2a*/;
    // 004b2ef2  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b2ef6  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x004b2ef8:
    // 004b2ef8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b2efa  3ac2                   +cmp al, dl
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
    // 004b2efc  7412                   -je 0x4b2f10
    if (cpu.flags.zf)
    {
        goto L_0x004b2f10;
    }
    // 004b2efe  3c00                   +cmp al, 0
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
    // 004b2f00  740c                   -je 0x4b2f0e
    if (cpu.flags.zf)
    {
        goto L_0x004b2f0e;
    }
    // 004b2f02  46                     -inc esi
    (cpu.esi)++;
    // 004b2f03  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b2f05  3ac2                   +cmp al, dl
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
    // 004b2f07  7407                   -je 0x4b2f10
    if (cpu.flags.zf)
    {
        goto L_0x004b2f10;
    }
    // 004b2f09  46                     -inc esi
    (cpu.esi)++;
    // 004b2f0a  3c00                   +cmp al, 0
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
    // 004b2f0c  75ea                   -jne 0x4b2ef8
    if (!cpu.flags.zf)
    {
        goto L_0x004b2ef8;
    }
L_0x004b2f0e:
    // 004b2f0e  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004b2f10:
    // 004b2f10  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b2f12  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004b2f14  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2f16  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b2f18  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b2f1a  e8dd74fcff             -call 0x47a3fc
    cpu.esp -= 4;
    sub_47a3fc(app, cpu);
    if (cpu.terminate) return;
    // 004b2f1f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b2f21  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004b2f23  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b2f25  881c34                 -mov byte ptr [esp + esi], bl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.bl;
    // 004b2f28  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004b2f2d  e810060000             -call 0x4b3542
    cpu.esp -= 4;
    sub_4b3542(app, cpu);
    if (cpu.terminate) return;
    // 004b2f32  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b2f34  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004b2f36  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b2f3a  e8ef5dffff             -call 0x4a8d2e
    cpu.esp -= 4;
    sub_4a8d2e(app, cpu);
    if (cpu.terminate) return;
    // 004b2f3f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b2f41  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b2f43  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004b2f46  e84260ffff             -call 0x4a8f8d
    cpu.esp -= 4;
    sub_4a8f8d(app, cpu);
    if (cpu.terminate) return;
    // 004b2f4b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b2f4d  e911ffffff             -jmp 0x4b2e63
    goto L_0x004b2e63;
L_0x004b2f52:
    // 004b2f52  b87cfc4b00             -mov eax, 0x4bfc7c
    cpu.eax = 4979836 /*0x4bfc7c*/;
    // 004b2f57  e83f060000             -call 0x4b359b
    cpu.esp -= 4;
    sub_4b359b(app, cpu);
    if (cpu.terminate) return;
L_0x004b2f5c:
    // 004b2f5c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b2f5f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2f60  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2f61  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2f62  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2f63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2f64  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2f65  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2f66(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2f66  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2f67  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2f68  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2f69  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b2f6a  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2f6d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b2f6f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2f71  8a25cc874c00           -mov ah, byte ptr [0x4c87cc]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5015500) /* 0x4c87cc */);
    // 004b2f77  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004b2f7a  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004b2f7c  7426                   -je 0x4b2fa4
    if (cpu.flags.zf)
    {
        goto L_0x004b2fa4;
    }
    // 004b2f7e  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004b2f80  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 004b2f83  9b                     -wait 
    /*nothing*/;
    // 004b2f84  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b2f86  741c                   -je 0x4b2fa4
    if (cpu.flags.zf)
    {
        goto L_0x004b2fa4;
    }
    // 004b2f88  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2f8a  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004b2f8d  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004b2f8f  21da                   -and edx, ebx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b2f91  21f0                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 004b2f93  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2f95  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004b2f97  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b2f9a  36d92f                 -fldcw word ptr ss:[edi]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.ess + cpu.edi);
    // 004b2f9d  9b                     -wait 
    /*nothing*/;
    // 004b2f9e  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004b2fa0  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 004b2fa3  9b                     -wait 
    /*nothing*/;
L_0x004b2fa4:
    // 004b2fa4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2fa6  668b0424               -mov ax, word ptr [esp]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    // 004b2faa  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2fad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2fae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2faf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2fb0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2fb1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2fb2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2fb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b2fb3  803800                 +cmp byte ptr [eax], 0
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
    // 004b2fb6  7507                   -jne 0x4b2fbf
    if (!cpu.flags.zf)
    {
        goto L_0x004b2fbf;
    }
    // 004b2fb8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b2fbd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2fbe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2fbf:
    // 004b2fbf  833d8c70540000         +cmp dword ptr [0x54708c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5533836) /* 0x54708c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2fc6  7422                   -je 0x4b2fea
    if (cpu.flags.zf)
    {
        goto L_0x004b2fea;
    }
    // 004b2fc8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2fca  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2fcc  8a9291705400           -mov dl, byte ptr [edx + 0x547091]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5533841) /* 0x547091 */);
    // 004b2fd2  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b2fd5  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b2fdb  740d                   -je 0x4b2fea
    if (cpu.flags.zf)
    {
        goto L_0x004b2fea;
    }
    // 004b2fdd  80780100               +cmp byte ptr [eax + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2fe1  7507                   -jne 0x4b2fea
    if (!cpu.flags.zf)
    {
        goto L_0x004b2fea;
    }
    // 004b2fe3  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004b2fe8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2fe9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2fea:
    // 004b2fea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2fec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2fed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2fee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2fee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2fef  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2ff0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b2ff3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b2ff5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2ff7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2ff9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b2ffb  e83e090000             -call 0x4b393e
    cpu.esp -= 4;
    sub_4b393e(app, cpu);
    if (cpu.terminate) return;
    // 004b3000  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b3002  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004b3004  e8fcceffff             -call 0x4aff05
    cpu.esp -= 4;
    sub_4aff05(app, cpu);
    if (cpu.terminate) return;
    // 004b3009  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 004b300c  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b3010  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b3012  e827090000             -call 0x4b393e
    cpu.esp -= 4;
    sub_4b393e(app, cpu);
    if (cpu.terminate) return;
    // 004b3017  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3019  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004b301b  e8e5ceffff             -call 0x4aff05
    cpu.esp -= 4;
    sub_4aff05(app, cpu);
    if (cpu.terminate) return;
    // 004b3020  88740404               -mov byte ptr [esp + eax + 4], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.dh;
    // 004b3024  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b3026  e844090000             -call 0x4b396f
    cpu.esp -= 4;
    sub_4b396f(app, cpu);
    if (cpu.terminate) return;
    // 004b302b  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b302f  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b3033  e837090000             -call 0x4b396f
    cpu.esp -= 4;
    sub_4b396f(app, cpu);
    if (cpu.terminate) return;
    // 004b3038  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b303a  e87f090000             -call 0x4b39be
    cpu.esp -= 4;
    sub_4b39be(app, cpu);
    if (cpu.terminate) return;
    // 004b303f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b3042  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3043  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3044  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3045(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3045  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b3046  833d8c70540000         +cmp dword ptr [0x54708c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5533836) /* 0x54708c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b304d  7420                   -je 0x4b306f
    if (cpu.flags.zf)
    {
        goto L_0x004b306f;
    }
    // 004b304f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b3051  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b3053  8a9291705400           -mov dl, byte ptr [edx + 0x547091]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5533841) /* 0x547091 */);
    // 004b3059  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b305c  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b3062  740b                   -je 0x4b306f
    if (cpu.flags.zf)
    {
        goto L_0x004b306f;
    }
    // 004b3064  80780100               +cmp byte ptr [eax + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3068  7405                   -je 0x4b306f
    if (cpu.flags.zf)
    {
        goto L_0x004b306f;
    }
    // 004b306a  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b306d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b306e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b306f:
    // 004b306f  40                     -inc eax
    (cpu.eax)++;
    // 004b3070  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3071  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3072(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3072  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b3073  668b5008               -mov dx, word ptr [eax + 8]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b3077  80e67f                 -and dh, 0x7f
    cpu.dh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004b307a  6681faff7f             +cmp dx, 0x7fff
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32767 /*0x7fff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b307f  751c                   -jne 0x4b309d
    if (!cpu.flags.zf)
    {
        goto L_0x004b309d;
    }
    // 004b3081  81780400000080         +cmp dword ptr [eax + 4], 0x80000000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3088  750c                   -jne 0x4b3096
    if (!cpu.flags.zf)
    {
        goto L_0x004b3096;
    }
    // 004b308a  833800                 +cmp dword ptr [eax], 0
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
    // 004b308d  7507                   -jne 0x4b3096
    if (!cpu.flags.zf)
    {
        goto L_0x004b3096;
    }
    // 004b308f  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004b3094  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3095  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3096:
    // 004b3096  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004b309b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b309c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b309d:
    // 004b309d  66f74008ff7f           +test word ptr [eax + 8], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) & 32767 /*0x7fff*/));
    // 004b30a3  7516                   -jne 0x4b30bb
    if (!cpu.flags.zf)
    {
        goto L_0x004b30bb;
    }
    // 004b30a5  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004b30a9  7509                   -jne 0x4b30b4
    if (!cpu.flags.zf)
    {
        goto L_0x004b30b4;
    }
    // 004b30ab  833800                 +cmp dword ptr [eax], 0
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
    // 004b30ae  7504                   -jne 0x4b30b4
    if (!cpu.flags.zf)
    {
        goto L_0x004b30b4;
    }
    // 004b30b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b30b2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b30b3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b30b4:
    // 004b30b4  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004b30b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b30ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b30bb:
    // 004b30bb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b30c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b30c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b30c2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b30c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b30c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b30c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b30c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b30c6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b30c7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b30c8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b30ca  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b30cc  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b30ce  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b30d0  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b30d2:
    // 004b30d2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b30d4  3c00                   +cmp al, 0
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
    // 004b30d6  742f                   -je 0x4b3107
    if (cpu.flags.zf)
    {
        goto L_0x004b3107;
    }
    // 004b30d8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b30da  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b30dc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b30de  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b30e0  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b30e2  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b30e4  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b30e6  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b30e8  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b30ea  01c5                   +add ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b30ec  11d9                   +adc ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b30ee  11fa                   -adc edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi) + cpu.flags.cf);
    // 004b30f0  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b30f2  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b30f4  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b30f6  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b30f8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b30fa  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004b30fc  01c5                   +add ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b30fe  83d100                 +adc ecx, 0
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b3101  83d200                 +adc edx, 0
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b3104  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b3105  ebcb                   -jmp 0x4b30d2
    goto L_0x004b30d2;
L_0x004b3107:
    // 004b3107  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3109  bf5e400000             -mov edi, 0x405e
    cpu.edi = 16478 /*0x405e*/;
    // 004b310e  e811000000             -call 0x4b3124
    cpu.esp -= 4;
    sub_4b3124(app, cpu);
    if (cpu.terminate) return;
    // 004b3113  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3114  895504                 -mov dword ptr [ebp + 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b3117  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004b311a  66897508               -mov word ptr [ebp + 8], si
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.si;
    // 004b311e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b311f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3120  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3121  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3122  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3123  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3124(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3124  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b3126  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b3128  09d6                   -or esi, edx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b312a  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004b312c  7436                   -je 0x4b3164
    if (cpu.flags.zf)
    {
        goto L_0x004b3164;
    }
    // 004b312e  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b3130  7509                   -jne 0x4b313b
    if (!cpu.flags.zf)
    {
        goto L_0x004b313b;
    }
    // 004b3132  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b3134  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b3136  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b3138  83ef20                 -sub edi, 0x20
    (cpu.edi) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004b313b:
    // 004b313b  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b313d  7509                   -jne 0x4b3148
    if (!cpu.flags.zf)
    {
        goto L_0x004b3148;
    }
    // 004b313f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b3141  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b3143  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b3145  83ef20                 -sub edi, 0x20
    (cpu.edi) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004b3148:
    // 004b3148  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b314a  7809                   -js 0x4b3155
    if (cpu.flags.sf)
    {
        goto L_0x004b3155;
    }
    // 004b314c  4f                     -dec edi
    (cpu.edi)--;
    // 004b314d  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b314f  11c0                   +adc eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b3151  11d2                   +adc edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b3153  ebf3                   -jmp 0x4b3148
    goto L_0x004b3148;
L_0x004b3155:
    // 004b3155  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b3157  83d000                 +adc eax, 0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b315a  83d200                 +adc edx, 0
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b315d  7303                   -jae 0x4b3162
    if (!cpu.flags.cf)
    {
        goto L_0x004b3162;
    }
    // 004b315f  d1da                   -rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004b3161  47                     -inc edi
    (cpu.edi)++;
L_0x004b3162:
    // 004b3162  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x004b3164:
    // 004b3164  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4b3168(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3168  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3169  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b316b  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b316c  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b316f  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b3172  8b6d10                 -mov ebp, dword ptr [ebp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b3175  83f907                 +cmp ecx, 7
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
    // 004b3178  7e42                   -jle 0x4b31bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b31bc;
    }
    // 004b317a  83e907                 -sub ecx, 7
    (cpu.ecx) -= x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x004b317d:
    // 004b317d  df07                   -fild word ptr [edi]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi))));
    // 004b317f  df4702                 -fild word ptr [edi + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(2) /* 0x2 */))));
    // 004b3182  df4704                 -fild word ptr [edi + 4]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */))));
    // 004b3185  df4706                 -fild word ptr [edi + 6]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(6) /* 0x6 */))));
    // 004b3188  df4708                 -fild word ptr [edi + 8]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */))));
    // 004b318b  df470a                 -fild word ptr [edi + 0xa]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(10) /* 0xa */))));
    // 004b318e  df470c                 -fild word ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(12) /* 0xc */))));
    // 004b3191  df470e                 -fild word ptr [edi + 0xe]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(14) /* 0xe */))));
    // 004b3194  d9cf                   -fxch st(7)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(7);
        cpu.fpu.st(7) = tmp;
    }
    // 004b3196  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3199  d95d18                 -fstp dword ptr [ebp + 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b319c  d95d14                 -fstp dword ptr [ebp + 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b319f  d95d10                 -fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b31a2  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b31a5  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b31a8  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b31ab  d95d1c                 -fstp dword ptr [ebp + 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b31ae  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b31b1  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b31b4  83e908                 +sub ecx, 8
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
    // 004b31b7  7fc4                   -jg 0x4b317d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b317d;
    }
    // 004b31b9  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x004b31bc:
    // 004b31bc  83f900                 +cmp ecx, 0
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
    // 004b31bf  7e10                   -jle 0x4b31d1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b31d1;
    }
    // 004b31c1  df07                   -fild word ptr [edi]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi))));
    // 004b31c3  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b31c6  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b31c9  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b31cc  83e901                 +sub ecx, 1
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
    // 004b31cf  7feb                   -jg 0x4b31bc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b31bc;
    }
L_0x004b31d1:
    // 004b31d1  61                     -popal 
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
    // 004b31d2  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b31d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b31d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b31d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b31d5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b31d7  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b31d8  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b31db  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b31de  8b6d10                 -mov ebp, dword ptr [ebp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b31e1  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b31e3  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b31e5  83f903                 +cmp ecx, 3
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
    // 004b31e8  7e44                   -jle 0x4b322e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b322e;
    }
    // 004b31ea  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b31ed:
    // 004b31ed  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004b31ef  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b31f2  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b31f5  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b31f8  8b1c85a0715400         -mov ebx, dword ptr [eax*4 + 0x5471a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5534112) /* 0x5471a0 */ + cpu.eax * 4);
    // 004b31ff  8b3495a0715400         -mov esi, dword ptr [edx*4 + 0x5471a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5534112) /* 0x5471a0 */ + cpu.edx * 4);
    // 004b3206  8a47fe                 -mov al, byte ptr [edi - 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-2) /* -0x2 */);
    // 004b3209  8a57ff                 -mov dl, byte ptr [edi - 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 004b320c  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 004b320f  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 004b3212  8b1c85a0715400         -mov ebx, dword ptr [eax*4 + 0x5471a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5534112) /* 0x5471a0 */ + cpu.eax * 4);
    // 004b3219  8b3495a0715400         -mov esi, dword ptr [edx*4 + 0x5471a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5534112) /* 0x5471a0 */ + cpu.edx * 4);
    // 004b3220  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004b3223  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004b3226  83e904                 +sub ecx, 4
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
    // 004b3229  7fc2                   -jg 0x4b31ed
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b31ed;
    }
    // 004b322b  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b322e:
    // 004b322e  83f900                 +cmp ecx, 0
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
    // 004b3231  7e17                   -jle 0x4b324a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b324a;
    }
    // 004b3233  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004b3235  83c701                 -add edi, 1
    (cpu.edi) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004b3238  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b323b  8b1c85a0715400         -mov ebx, dword ptr [eax*4 + 0x5471a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5534112) /* 0x5471a0 */ + cpu.eax * 4);
    // 004b3242  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004b3245  83e901                 +sub ecx, 1
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
    // 004b3248  7fe4                   -jg 0x4b322e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b322e;
    }
L_0x004b324a:
    // 004b324a  61                     -popal 
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
    // 004b324b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b324c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b324d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b324d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b324e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b324f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3250  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b3251  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004b3253  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004b3255  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3256  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b3258  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b325b  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004b325e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b3260  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004b3263  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004b3266  8b15fc2b5400           -mov edx, dword ptr [0x542bfc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5516284) /* 0x542bfc */);
    // 004b326c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b326e  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b3271  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004b3274  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b3276  753e                   -jne 0x4b32b6
    if (!cpu.flags.zf)
    {
        goto L_0x004b32b6;
    }
    // 004b3278  a190d64c00             -mov eax, dword ptr [0x4cd690]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035664) /* 0x4cd690 */);
    // 004b327d  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b3280  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004b3282  29c4                   -sub esp, eax
    (cpu.esp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b3284  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004b3286  8b1d90d64c00           -mov ebx, dword ptr [0x4cd690]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5035664) /* 0x4cd690 */);
    // 004b328c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b328e  e82c0ffdff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 004b3293  a190d64c00             -mov eax, dword ptr [0x4cd690]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035664) /* 0x4cd690 */);
    // 004b3298  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 004b329e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b32a0  e82460ffff             -call 0x4a92c9
    cpu.esp -= 4;
    sub_4a92c9(app, cpu);
    if (cpu.terminate) return;
    // 004b32a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b32a7  750d                   -jne 0x4b32b6
    if (!cpu.flags.zf)
    {
        goto L_0x004b32b6;
    }
    // 004b32a9  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b32ac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b32ad  2eff1524544b00         -call dword ptr cs:[0x4b5424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936740) /* 0x4b5424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b32b4  eb32                   -jmp 0x4b32e8
    goto L_0x004b32e8;
L_0x004b32b6:
    // 004b32b6  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b32b9  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b32bf  8998de000000           -mov dword ptr [eax + 0xde], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */) = cpu.ebx;
    // 004b32c5  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b32c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b32c9  2eff1558554b00         -call dword ptr cs:[0x4b5558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937048) /* 0x4b5558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b32d0  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b32d3  e8cb67ffff             -call 0x4a9aa3
    cpu.esp -= 4;
    sub_4a9aa3(app, cpu);
    if (cpu.terminate) return;
    // 004b32d8  ff1584c14c00           -call dword ptr [0x4cc184]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030276) /* 0x4cc184 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b32de  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b32e0  ff55f8                 -call dword ptr [ebp - 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b32e3  e811fbffff             -call 0x4b2df9
    cpu.esp -= 4;
    sub_4b2df9(app, cpu);
    if (cpu.terminate) return;
L_0x004b32e8:
    // 004b32e8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004b32ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b32eb  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b32ed  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b32ef  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b32f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b32f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b32f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b32f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b32f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b32f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b32f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b32f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b32f7  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b32f8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b32f9  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004b32fc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b32fe  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004b3300  833d40c14c00ff         +cmp dword ptr [0x4cc140], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3307  7512                   -jne 0x4b331b
    if (!cpu.flags.zf)
    {
        goto L_0x004b331b;
    }
    // 004b3309  e8665fffff             -call 0x4a9274
    cpu.esp -= 4;
    sub_4a9274(app, cpu);
    if (cpu.terminate) return;
    // 004b330e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3310  0f84ae000000           -je 0x4b33c4
    if (cpu.flags.zf)
    {
        goto L_0x004b33c4;
    }
    // 004b3316  e87e60ffff             -call 0x4a9399
    cpu.esp -= 4;
    sub_4a9399(app, cpu);
    if (cpu.terminate) return;
L_0x004b331b:
    // 004b331b  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004b331f  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004b3323  2eff15a0544b00         -call dword ptr cs:[0x4b54a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936864) /* 0x4b54a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b332a  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004b332e  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b3330  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004b3332  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b3334  be8cfc4b00             -mov esi, 0x4bfc8c
    cpu.esi = 4979852 /*0x4bfc8c*/;
    // 004b3339  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004b333e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b333f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b3340  a4                     -movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b3341  2eff159c544b00         -call dword ptr cs:[0x4b549c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936860) /* 0x4b549c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b3348  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b334c  e8608cffff             -call 0x4abfb1
    cpu.esp -= 4;
    sub_4abfb1(app, cpu);
    if (cpu.terminate) return;
    // 004b3351  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b3353  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b3354  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b3356  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b3358  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b335a  2eff1528544b00         -call dword ptr cs:[0x4b5428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936744) /* 0x4b5428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b3361  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004b3365  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004b3369  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004b336d  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004b3371  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b3372  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b3374  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b3378  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b3379  81c5ff0f0000           -add ebp, 0xfff
    (cpu.ebp) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 004b337f  684d324b00             -push 0x4b324d
    app->getMemory<x86::reg32>(cpu.esp-4) = 4928077 /*0x4b324d*/;
    cpu.esp -= 4;
    // 004b3384  81e500f0ffff           -and ebp, 0xfffff000
    cpu.ebp &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 004b338a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b338b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b338d  2eff1538544b00         -call dword ptr cs:[0x4b5438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936760) /* 0x4b5438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b3394  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004b3398  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b339a  750a                   -jne 0x4b33a6
    if (!cpu.flags.zf)
    {
        goto L_0x004b33a6;
    }
    // 004b339c  c7442438ffffffff       -mov dword ptr [esp + 0x38], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = 4294967295 /*0xffffffff*/;
    // 004b33a4  eb0e                   -jmp 0x4b33b4
    goto L_0x004b33b4;
L_0x004b33a6:
    // 004b33a6  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004b33a8  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004b33ac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b33ad  2eff15a4554b00         -call dword ptr cs:[0x4b55a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937124) /* 0x4b55a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b33b4:
    // 004b33b4  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004b33b8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b33b9  2eff1524544b00         -call dword ptr cs:[0x4b5424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936740) /* 0x4b5424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b33c0  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
L_0x004b33c4:
    // 004b33c4  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004b33c7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b33c8  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b33c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b33ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b33cb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b33cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b33cd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b33cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b33ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b33cf  ff1588c14c00           -call dword ptr [0x4cc188]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030280) /* 0x4cc188 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b33d5  e81567ffff             -call 0x4a9aef
    cpu.esp -= 4;
    sub_4a9aef(app, cpu);
    if (cpu.terminate) return;
    // 004b33da  833dfc2b540000         +cmp dword ptr [0x542bfc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5516284) /* 0x542bfc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b33e1  750a                   -jne 0x4b33ed
    if (!cpu.flags.zf)
    {
        goto L_0x004b33ed;
    }
    // 004b33e3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b33e8  e82b5fffff             -call 0x4a9318
    cpu.esp -= 4;
    sub_4a9318(app, cpu);
    if (cpu.terminate) return;
L_0x004b33ed:
    // 004b33ed  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b33ef  2eff1558544b00         -call dword ptr cs:[0x4b5458]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936792) /* 0x4b5458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b33f6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b33f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b33f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b33f9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b33f9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b33fa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b33fb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b33fc  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b33ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b3400  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004b3402  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b3404  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004b3408  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b340a  7402                   -je 0x4b340e
    if (cpu.flags.zf)
    {
        goto L_0x004b340e;
    }
    // 004b340c  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004b340e:
    // 004b340e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
L_0x004b3411:
    // 004b3411  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004b3413  fec0                   -inc al
    (cpu.al)++;
    // 004b3415  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b341a  f68084c84c0002         +test byte ptr [eax + 0x4cc884], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032068) /* 0x4cc884 */) & 2 /*0x2*/));
    // 004b3421  7403                   -je 0x4b3426
    if (cpu.flags.zf)
    {
        goto L_0x004b3426;
    }
    // 004b3423  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b3424  ebeb                   -jmp 0x4b3411
    goto L_0x004b3411;
L_0x004b3426:
    // 004b3426  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 004b3428  80fd2b                 +cmp ch, 0x2b
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
    // 004b342b  7405                   -je 0x4b3432
    if (cpu.flags.zf)
    {
        goto L_0x004b3432;
    }
    // 004b342d  80fd2d                 +cmp ch, 0x2d
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
    // 004b3430  7501                   -jne 0x4b3433
    if (!cpu.flags.zf)
    {
        goto L_0x004b3433;
    }
L_0x004b3432:
    // 004b3432  42                     -inc edx
    (cpu.edx)++;
L_0x004b3433:
    // 004b3433  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b3435  752c                   -jne 0x4b3463
    if (!cpu.flags.zf)
    {
        goto L_0x004b3463;
    }
    // 004b3437  803a30                 +cmp byte ptr [edx], 0x30
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
    // 004b343a  7514                   -jne 0x4b3450
    if (!cpu.flags.zf)
    {
        goto L_0x004b3450;
    }
    // 004b343c  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b343f  80f978                 +cmp cl, 0x78
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
    // 004b3442  7405                   -je 0x4b3449
    if (cpu.flags.zf)
    {
        goto L_0x004b3449;
    }
    // 004b3444  80f958                 +cmp cl, 0x58
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
    // 004b3447  7507                   -jne 0x4b3450
    if (!cpu.flags.zf)
    {
        goto L_0x004b3450;
    }
L_0x004b3449:
    // 004b3449  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 004b344e  eb33                   -jmp 0x4b3483
    goto L_0x004b3483;
L_0x004b3450:
    // 004b3450  803a30                 +cmp byte ptr [edx], 0x30
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
    // 004b3453  7507                   -jne 0x4b345c
    if (!cpu.flags.zf)
    {
        goto L_0x004b345c;
    }
    // 004b3455  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 004b345a  eb3c                   -jmp 0x4b3498
    goto L_0x004b3498;
L_0x004b345c:
    // 004b345c  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
    // 004b3461  eb35                   -jmp 0x4b3498
    goto L_0x004b3498;
L_0x004b3463:
    // 004b3463  83fe02                 +cmp esi, 2
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
    // 004b3466  7c05                   -jl 0x4b346d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b346d;
    }
    // 004b3468  83fe24                 +cmp esi, 0x24
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
    // 004b346b  7e11                   -jle 0x4b347e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b347e;
    }
L_0x004b346d:
    // 004b346d  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 004b3472  e8c927feff             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 004b3477  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b3479  e9b3000000             -jmp 0x4b3531
    goto L_0x004b3531;
L_0x004b347e:
    // 004b347e  83fe10                 +cmp esi, 0x10
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
    // 004b3481  7515                   -jne 0x4b3498
    if (!cpu.flags.zf)
    {
        goto L_0x004b3498;
    }
L_0x004b3483:
    // 004b3483  803a30                 +cmp byte ptr [edx], 0x30
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
    // 004b3486  7510                   -jne 0x4b3498
    if (!cpu.flags.zf)
    {
        goto L_0x004b3498;
    }
    // 004b3488  8a7a01                 -mov bh, byte ptr [edx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b348b  80ff78                 +cmp bh, 0x78
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
    // 004b348e  7405                   -je 0x4b3495
    if (cpu.flags.zf)
    {
        goto L_0x004b3495;
    }
    // 004b3490  80ff58                 +cmp bh, 0x58
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
    // 004b3493  7503                   -jne 0x4b3498
    if (!cpu.flags.zf)
    {
        goto L_0x004b3498;
    }
L_0x004b3495:
    // 004b3495  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004b3498:
    // 004b3498  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b349c  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004b349e  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 004b34a0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b34a2  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
L_0x004b34a5:
    // 004b34a5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b34a7  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004b34a9  e89c000000             -call 0x4b354a
    cpu.esp -= 4;
    sub_4b354a(app, cpu);
    if (cpu.terminate) return;
    // 004b34ae  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b34b2  39f0                   +cmp eax, esi
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
    // 004b34b4  7d1c                   -jge 0x4b34d2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b34d2;
    }
    // 004b34b6  3b9ff8de4c00           +cmp ebx, dword ptr [edi + 0x4cdef8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5037816) /* 0x4cdef8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b34bc  7602                   -jbe 0x4b34c0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b34c0;
    }
    // 004b34be  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x004b34c0:
    // 004b34c0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b34c2  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004b34c5  035c2408               -add ebx, dword ptr [esp + 8]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004b34c9  39c3                   +cmp ebx, eax
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
    // 004b34cb  7302                   -jae 0x4b34cf
    if (!cpu.flags.cf)
    {
        goto L_0x004b34cf;
    }
    // 004b34cd  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x004b34cf:
    // 004b34cf  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b34d0  ebd3                   -jmp 0x4b34a5
    goto L_0x004b34a5;
L_0x004b34d2:
    // 004b34d2  3b542404               +cmp edx, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b34d6  7503                   -jne 0x4b34db
    if (!cpu.flags.zf)
    {
        goto L_0x004b34db;
    }
    // 004b34d8  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
L_0x004b34db:
    // 004b34db  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b34dd  7403                   -je 0x4b34e2
    if (cpu.flags.zf)
    {
        goto L_0x004b34e2;
    }
    // 004b34df  895500                 -mov dword ptr [ebp], edx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
L_0x004b34e2:
    // 004b34e2  837c240c01             +cmp dword ptr [esp + 0xc], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b34e7  750f                   -jne 0x4b34f8
    if (!cpu.flags.zf)
    {
        goto L_0x004b34f8;
    }
    // 004b34e9  81fb00000080           +cmp ebx, 0x80000000
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
    // 004b34ef  7207                   -jb 0x4b34f8
    if (cpu.flags.cf)
    {
        goto L_0x004b34f8;
    }
    // 004b34f1  7509                   -jne 0x4b34fc
    if (!cpu.flags.zf)
    {
        goto L_0x004b34fc;
    }
    // 004b34f3  80fd2d                 +cmp ch, 0x2d
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
    // 004b34f6  7504                   -jne 0x4b34fc
    if (!cpu.flags.zf)
    {
        goto L_0x004b34fc;
    }
L_0x004b34f8:
    // 004b34f8  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b34fa  742c                   -je 0x4b3528
    if (cpu.flags.zf)
    {
        goto L_0x004b3528;
    }
L_0x004b34fc:
    // 004b34fc  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 004b3501  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b3505  e83627feff             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 004b350a  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b350c  7507                   -jne 0x4b3515
    if (!cpu.flags.zf)
    {
        goto L_0x004b3515;
    }
    // 004b350e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b3513  eb1c                   -jmp 0x4b3531
    goto L_0x004b3531;
L_0x004b3515:
    // 004b3515  80fd2d                 +cmp ch, 0x2d
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
    // 004b3518  7507                   -jne 0x4b3521
    if (!cpu.flags.zf)
    {
        goto L_0x004b3521;
    }
    // 004b351a  b800000080             -mov eax, 0x80000000
    cpu.eax = 2147483648 /*0x80000000*/;
    // 004b351f  eb10                   -jmp 0x4b3531
    goto L_0x004b3531;
L_0x004b3521:
    // 004b3521  b8ffffff7f             -mov eax, 0x7fffffff
    cpu.eax = 2147483647 /*0x7fffffff*/;
    // 004b3526  eb09                   -jmp 0x4b3531
    goto L_0x004b3531;
L_0x004b3528:
    // 004b3528  80fd2d                 +cmp ch, 0x2d
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
    // 004b352b  7502                   -jne 0x4b352f
    if (!cpu.flags.zf)
    {
        goto L_0x004b352f;
    }
    // 004b352d  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
L_0x004b352f:
    // 004b352f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004b3531:
    // 004b3531  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b3534  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3535  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3536  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3537  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3538(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3538  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3539  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b353b  e8b9feffff             -call 0x4b33f9
    cpu.esp -= 4;
    sub_4b33f9(app, cpu);
    if (cpu.terminate) return;
    // 004b3540  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3541  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b353b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b353b;
    // 004b3538  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3539  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_entry_0x004b353b:
    // 004b353b  e8b9feffff             -call 0x4b33f9
    cpu.esp -= 4;
    sub_4b33f9(app, cpu);
    if (cpu.terminate) return;
    // 004b3540  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3541  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3542(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3542  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3543  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004b3548  ebf1                   -jmp 0x4b353b
    return sub_4b353b(app, cpu);
}

/* align: skip  */
void Application::sub_4b354a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b354a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b354b  3c30                   +cmp al, 0x30
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
    // 004b354d  720e                   -jb 0x4b355d
    if (cpu.flags.cf)
    {
        goto L_0x004b355d;
    }
    // 004b354f  3c39                   +cmp al, 0x39
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
    // 004b3551  770a                   -ja 0x4b355d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b355d;
    }
    // 004b3553  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b3558  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004b355b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b355c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b355d:
    // 004b355d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b3562  e8c459feff             -call 0x498f2b
    cpu.esp -= 4;
    sub_498f2b(app, cpu);
    if (cpu.terminate) return;
    // 004b3567  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b3569  3c61                   +cmp al, 0x61
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
    // 004b356b  720d                   -jb 0x4b357a
    if (cpu.flags.cf)
    {
        goto L_0x004b357a;
    }
    // 004b356d  3c69                   +cmp al, 0x69
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
    // 004b356f  7709                   -ja 0x4b357a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b357a;
    }
    // 004b3571  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b3573  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004b3575  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 004b3578  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3579  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b357a:
    // 004b357a  3c6a                   +cmp al, 0x6a
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
    // 004b357c  720e                   -jb 0x4b358c
    if (cpu.flags.cf)
    {
        goto L_0x004b358c;
    }
    // 004b357e  3c72                   +cmp al, 0x72
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
    // 004b3580  770a                   -ja 0x4b358c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b358c;
    }
L_0x004b3582:
    // 004b3582  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b3587  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 004b358a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b358b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b358c:
    // 004b358c  3c73                   +cmp al, 0x73
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
    // 004b358e  7204                   -jb 0x4b3594
    if (cpu.flags.cf)
    {
        goto L_0x004b3594;
    }
    // 004b3590  3c7a                   +cmp al, 0x7a
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
    // 004b3592  76ee                   -jbe 0x4b3582
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3582;
    }
L_0x004b3594:
    // 004b3594  b825000000             -mov eax, 0x25
    cpu.eax = 37 /*0x25*/;
    // 004b3599  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b359a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b359b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b359b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b359c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b359d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b359e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b359f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b35a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b35a1  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b35a4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b35a6  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004b35ab  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004b35b0  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b35b3  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 004b35b8  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b35bc  e855040000             -call 0x4b3a16
    cpu.esp -= 4;
    sub_4b3a16(app, cpu);
    if (cpu.terminate) return;
    // 004b35c1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b35c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b35c5  7469                   -je 0x4b3630
    if (cpu.flags.zf)
    {
        goto L_0x004b3630;
    }
    // 004b35c7  39e8                   +cmp eax, ebp
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
    // 004b35c9  7465                   -je 0x4b3630
    if (cpu.flags.zf)
    {
        goto L_0x004b3630;
    }
    // 004b35cb  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b35cd  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b35d1  40                     -inc eax
    (cpu.eax)++;
    // 004b35d2  e87c25feff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b35d7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b35d9  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b35dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b35df  744f                   -je 0x4b3630
    if (cpu.flags.zf)
    {
        goto L_0x004b3630;
    }
    // 004b35e1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b35e5  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004b35e7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b35e9  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b35ea  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b35ec  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b35ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b35ef  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b35f1  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b35f4  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b35f6  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b35f8  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b35fb  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b35fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b35fe  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b35ff  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b3603  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b3606  c6040200               -mov byte ptr [edx + eax], 0
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 004b360a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b360c  e861040000             -call 0x4b3a72
    cpu.esp -= 4;
    sub_4b3a72(app, cpu);
    if (cpu.terminate) return;
    // 004b3611  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b3615  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3617  7446                   -je 0x4b365f
    if (cpu.flags.zf)
    {
        goto L_0x004b365f;
    }
    // 004b3619  40                     -inc eax
    (cpu.eax)++;
    // 004b361a  e83425feff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b361f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b3621  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b3625  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3627  7511                   -jne 0x4b363a
    if (!cpu.flags.zf)
    {
        goto L_0x004b363a;
    }
    // 004b3629  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004b362b:
    // 004b362b  e81976feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
L_0x004b3630:
    // 004b3630  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b3635  e9af000000             -jmp 0x4b36e9
    goto L_0x004b36e9;
L_0x004b363a:
    // 004b363a  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b363e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b3640  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b3641  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b3643  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b3645  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3646  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3648  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b364b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b364d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b364f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b3652  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b3654  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3655  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b3656  035c2414               +add ebx, dword ptr [esp + 0x14]
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
    // 004b365a  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 004b365d  eb04                   -jmp 0x4b3663
    goto L_0x004b3663;
L_0x004b365f:
    // 004b365f  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004b3663:
    // 004b3663  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b3667  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b3668  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b366c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b366d  2eff1550554b00         -call dword ptr cs:[0x4b5550]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937040) /* 0x4b5550 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b3674  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b3676  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b367a  e8ca75feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004b367f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b3683  e8c175feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004b3688  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b368a  74a4                   -je 0x4b3630
    if (cpu.flags.zf)
    {
        goto L_0x004b3630;
    }
    // 004b368c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b368e  e860000000             -call 0x4b36f3
    cpu.esp -= 4;
    sub_4b36f3(app, cpu);
    if (cpu.terminate) return;
    // 004b3693  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3695  7599                   -jne 0x4b3630
    if (!cpu.flags.zf)
    {
        goto L_0x004b3630;
    }
    // 004b3697  833d8070540000         +cmp dword ptr [0x547080], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5533824) /* 0x547080 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b369e  7449                   -je 0x4b36e9
    if (cpu.flags.zf)
    {
        goto L_0x004b36e9;
    }
    // 004b36a0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b36a2  e8cb030000             -call 0x4b3a72
    cpu.esp -= 4;
    sub_4b3a72(app, cpu);
    if (cpu.terminate) return;
    // 004b36a7  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b36aa  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b36ad  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b36b0  e89e24feff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b36b5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b36b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b36b9  750f                   -jne 0x4b36ca
    if (!cpu.flags.zf)
    {
        goto L_0x004b36ca;
    }
    // 004b36bb  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004b36c0  e82c24feff             -call 0x495af1
    cpu.esp -= 4;
    sub_495af1(app, cpu);
    if (cpu.terminate) return;
    // 004b36c5  e966ffffff             -jmp 0x4b3630
    goto L_0x004b3630;
L_0x004b36ca:
    // 004b36ca  0faf5c2404             -imul ebx, dword ptr [esp + 4]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004b36cf  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b36d1  e8be030000             -call 0x4b3a94
    cpu.esp -= 4;
    sub_4b3a94(app, cpu);
    if (cpu.terminate) return;
    // 004b36d6  83f8ff                 +cmp eax, -1
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
    // 004b36d9  7507                   -jne 0x4b36e2
    if (!cpu.flags.zf)
    {
        goto L_0x004b36e2;
    }
    // 004b36db  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b36dd  e949ffffff             -jmp 0x4b362b
    goto L_0x004b362b;
L_0x004b36e2:
    // 004b36e2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b36e4  e849050000             -call 0x4b3c32
    cpu.esp -= 4;
    sub_4b3c32(app, cpu);
    if (cpu.terminate) return;
L_0x004b36e9:
    // 004b36e9  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b36ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b36ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b36ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b36ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b36f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b36f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b36f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b36ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b36ec;
    // 004b359b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b359c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b359d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b359e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b359f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b35a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b35a1  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b35a4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b35a6  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004b35ab  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004b35b0  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b35b3  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 004b35b8  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b35bc  e855040000             -call 0x4b3a16
    cpu.esp -= 4;
    sub_4b3a16(app, cpu);
    if (cpu.terminate) return;
    // 004b35c1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b35c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b35c5  7469                   -je 0x4b3630
    if (cpu.flags.zf)
    {
        goto L_0x004b3630;
    }
    // 004b35c7  39e8                   +cmp eax, ebp
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
    // 004b35c9  7465                   -je 0x4b3630
    if (cpu.flags.zf)
    {
        goto L_0x004b3630;
    }
    // 004b35cb  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b35cd  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b35d1  40                     -inc eax
    (cpu.eax)++;
    // 004b35d2  e87c25feff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b35d7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b35d9  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b35dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b35df  744f                   -je 0x4b3630
    if (cpu.flags.zf)
    {
        goto L_0x004b3630;
    }
    // 004b35e1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b35e5  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004b35e7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b35e9  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b35ea  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b35ec  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b35ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b35ef  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b35f1  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b35f4  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b35f6  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b35f8  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b35fb  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b35fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b35fe  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b35ff  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b3603  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b3606  c6040200               -mov byte ptr [edx + eax], 0
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 004b360a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b360c  e861040000             -call 0x4b3a72
    cpu.esp -= 4;
    sub_4b3a72(app, cpu);
    if (cpu.terminate) return;
    // 004b3611  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b3615  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3617  7446                   -je 0x4b365f
    if (cpu.flags.zf)
    {
        goto L_0x004b365f;
    }
    // 004b3619  40                     -inc eax
    (cpu.eax)++;
    // 004b361a  e83425feff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b361f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b3621  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b3625  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3627  7511                   -jne 0x4b363a
    if (!cpu.flags.zf)
    {
        goto L_0x004b363a;
    }
    // 004b3629  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004b362b:
    // 004b362b  e81976feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
L_0x004b3630:
    // 004b3630  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b3635  e9af000000             -jmp 0x4b36e9
    goto L_0x004b36e9;
L_0x004b363a:
    // 004b363a  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b363e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b3640  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b3641  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b3643  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b3645  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3646  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3648  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b364b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b364d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b364f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b3652  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b3654  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3655  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b3656  035c2414               +add ebx, dword ptr [esp + 0x14]
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
    // 004b365a  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 004b365d  eb04                   -jmp 0x4b3663
    goto L_0x004b3663;
L_0x004b365f:
    // 004b365f  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004b3663:
    // 004b3663  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b3667  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b3668  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b366c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b366d  2eff1550554b00         -call dword ptr cs:[0x4b5550]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937040) /* 0x4b5550 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b3674  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b3676  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b367a  e8ca75feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004b367f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b3683  e8c175feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004b3688  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b368a  74a4                   -je 0x4b3630
    if (cpu.flags.zf)
    {
        goto L_0x004b3630;
    }
    // 004b368c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b368e  e860000000             -call 0x4b36f3
    cpu.esp -= 4;
    sub_4b36f3(app, cpu);
    if (cpu.terminate) return;
    // 004b3693  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3695  7599                   -jne 0x4b3630
    if (!cpu.flags.zf)
    {
        goto L_0x004b3630;
    }
    // 004b3697  833d8070540000         +cmp dword ptr [0x547080], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5533824) /* 0x547080 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b369e  7449                   -je 0x4b36e9
    if (cpu.flags.zf)
    {
        goto L_0x004b36e9;
    }
    // 004b36a0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b36a2  e8cb030000             -call 0x4b3a72
    cpu.esp -= 4;
    sub_4b3a72(app, cpu);
    if (cpu.terminate) return;
    // 004b36a7  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b36aa  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b36ad  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b36b0  e89e24feff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b36b5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b36b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b36b9  750f                   -jne 0x4b36ca
    if (!cpu.flags.zf)
    {
        goto L_0x004b36ca;
    }
    // 004b36bb  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004b36c0  e82c24feff             -call 0x495af1
    cpu.esp -= 4;
    sub_495af1(app, cpu);
    if (cpu.terminate) return;
    // 004b36c5  e966ffffff             -jmp 0x4b3630
    goto L_0x004b3630;
L_0x004b36ca:
    // 004b36ca  0faf5c2404             -imul ebx, dword ptr [esp + 4]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004b36cf  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b36d1  e8be030000             -call 0x4b3a94
    cpu.esp -= 4;
    sub_4b3a94(app, cpu);
    if (cpu.terminate) return;
    // 004b36d6  83f8ff                 +cmp eax, -1
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
    // 004b36d9  7507                   -jne 0x4b36e2
    if (!cpu.flags.zf)
    {
        goto L_0x004b36e2;
    }
    // 004b36db  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b36dd  e949ffffff             -jmp 0x4b362b
    goto L_0x004b362b;
L_0x004b36e2:
    // 004b36e2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b36e4  e849050000             -call 0x4b3c32
    cpu.esp -= 4;
    sub_4b3c32(app, cpu);
    if (cpu.terminate) return;
L_0x004b36e9:
    // 004b36e9  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
L_entry_0x004b36ec:
    // 004b36ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b36ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b36ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b36ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b36f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b36f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b36f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b36f3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b36f3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b36f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b36f5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b36f6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b36f7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b36f8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b36f9  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b36fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b36fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b36ff  750a                   -jne 0x4b370b
    if (!cpu.flags.zf)
    {
        goto L_0x004b370b;
    }
L_0x004b3701:
    // 004b3701  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b3706  e94b010000             -jmp 0x4b3856
    goto L_0x004b3856;
L_0x004b370b:
    // 004b370b  803800                 +cmp byte ptr [eax], 0
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
    // 004b370e  7411                   -je 0x4b3721
    if (cpu.flags.zf)
    {
        goto L_0x004b3721;
    }
    // 004b3710  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b3713  eb06                   -jmp 0x4b371b
    goto L_0x004b371b;
L_0x004b3715:
    // 004b3715  80ff3d                 +cmp bh, 0x3d
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3718  7407                   -je 0x4b3721
    if (cpu.flags.zf)
    {
        goto L_0x004b3721;
    }
    // 004b371a  42                     -inc edx
    (cpu.edx)++;
L_0x004b371b:
    // 004b371b  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 004b371d  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 004b371f  75f4                   -jne 0x4b3715
    if (!cpu.flags.zf)
    {
        goto L_0x004b3715;
    }
L_0x004b3721:
    // 004b3721  803a00                 +cmp byte ptr [edx], 0
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
    // 004b3724  74db                   -je 0x4b3701
    if (cpu.flags.zf)
    {
        goto L_0x004b3701;
    }
    // 004b3726  807a0100               +cmp byte ptr [edx + 1], 0
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
    // 004b372a  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 004b372d  0fb6e8                 -movzx ebp, al
    cpu.ebp = x86::reg32(cpu.al);
    // 004b3730  a17c705400             -mov eax, dword ptr [0x54707c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5533820) /* 0x54707c */);
    // 004b3735  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b3739  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b373b  7531                   -jne 0x4b376e
    if (!cpu.flags.zf)
    {
        goto L_0x004b376e;
    }
    // 004b373d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b373f  0f8511010000           -jne 0x4b3856
    if (!cpu.flags.zf)
    {
        goto L_0x004b3856;
    }
    // 004b3745  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004b374a  e80424feff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b374f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b3753  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3755  74aa                   -je 0x4b3701
    if (cpu.flags.zf)
    {
        goto L_0x004b3701;
    }
    // 004b3757  a37c705400             -mov dword ptr [0x54707c], eax
    app->getMemory<x86::reg32>(x86::reg32(5533820) /* 0x54707c */) = cpu.eax;
    // 004b375c  8928                   -mov dword ptr [eax], ebp
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebp;
    // 004b375e  83c008                 +add eax, 8
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
    // 004b3761  8968fc                 -mov dword ptr [eax - 4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 004b3764  a378705400             -mov dword ptr [0x547078], eax
    app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */) = cpu.eax;
    // 004b3769  e9cd000000             -jmp 0x4b383b
    goto L_0x004b383b;
L_0x004b376e:
    // 004b376e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b3771  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b3773  e8e6000000             -call 0x4b385e
    cpu.esp -= 4;
    sub_4b385e(app, cpu);
    if (cpu.terminate) return;
    // 004b3778  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b377a  0f85d4000000           -jne 0x4b3854
    if (!cpu.flags.zf)
    {
        goto L_0x004b3854;
    }
    // 004b3780  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3782  0f8fb0000000           -jg 0x4b3838
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b3838;
    }
    // 004b3788  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b378a  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 004b378c  8d5d01                 -lea ebx, [ebp + 1]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004b378f  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004b3791  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004b3794  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b3797  8b3578705400           -mov esi, dword ptr [0x547078]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */);
    // 004b379d  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b37a1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b37a3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b37a5  7545                   -jne 0x4b37ec
    if (!cpu.flags.zf)
    {
        goto L_0x004b37ec;
    }
    // 004b37a7  e8a723feff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b37ac  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b37ae  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b37b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b37b4  0f8447ffffff           -je 0x4b3701
    if (cpu.flags.zf)
    {
        goto L_0x004b3701;
    }
    // 004b37ba  8b357c705400           -mov esi, dword ptr [0x54707c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5533820) /* 0x54707c */);
    // 004b37c0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b37c2  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b37c3  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b37c5  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b37c7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b37c8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b37ca  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b37cd  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b37cf  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b37d1  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b37d4  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b37d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b37d7  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b37d8  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b37dc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b37de  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b37e0  a378705400             -mov dword ptr [0x547078], eax
    app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */) = cpu.eax;
    // 004b37e5  e8d509fdff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 004b37ea  eb32                   -jmp 0x4b381e
    goto L_0x004b381e;
L_0x004b37ec:
    // 004b37ec  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b37ee  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b37f2  e8fdbbffff             -call 0x4af3f4
    cpu.esp -= 4;
    sub_4af3f4(app, cpu);
    if (cpu.terminate) return;
    // 004b37f7  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b37fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b37fd  0f84fefeffff           -je 0x4b3701
    if (cpu.flags.zf)
    {
        goto L_0x004b3701;
    }
    // 004b3803  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b3807  8b1578705400           -mov edx, dword ptr [0x547078]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */);
    // 004b380d  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b380f  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004b3811  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3813  e84f060000             -call 0x4b3e67
    cpu.esp -= 4;
    sub_4b3e67(app, cpu);
    if (cpu.terminate) return;
    // 004b3818  890d78705400           -mov dword ptr [0x547078], ecx
    app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */) = cpu.ecx;
L_0x004b381e:
    // 004b381e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b3820  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b3824  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b3827  01f8                   +add eax, edi
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
    // 004b3829  893d7c705400           -mov dword ptr [0x54707c], edi
    app->getMemory<x86::reg32>(x86::reg32(5533820) /* 0x54707c */) = cpu.edi;
    // 004b382f  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b3836  eb03                   -jmp 0x4b383b
    goto L_0x004b383b;
L_0x004b3838:
    // 004b3838  8d68ff                 -lea ebp, [eax - 1]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x004b383b:
    // 004b383b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b383d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b3841  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b3844  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b3846  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b3849  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004b384b  a178705400             -mov eax, dword ptr [0x547078]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */);
    // 004b3850  c6042800               -mov byte ptr [eax + ebp], 0
    app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1) = 0 /*0x0*/;
L_0x004b3854:
    // 004b3854  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b3856:
    // 004b3856  83c40c                 +add esp, 0xc
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
    // 004b3859  e98efeffff             -jmp 0x4b36ec
    return sub_4b36ec(app, cpu);
}

/* align: skip  */
void Application::sub_4b385e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b385e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b385f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3860  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3861  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3862  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3863  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b3865  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004b3867  8b357c705400           -mov esi, dword ptr [0x54707c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5533820) /* 0x54707c */);
    // 004b386d  e9b2000000             -jmp 0x4b3924
    goto L_0x004b3924;
L_0x004b3872:
    // 004b3872  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004b3874  e99f000000             -jmp 0x4b3918
    goto L_0x004b3918;
L_0x004b3879:
    // 004b3879  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b387b  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004b387d  e8c06bfcff             -call 0x47a442
    cpu.esp -= 4;
    sub_47a442(app, cpu);
    if (cpu.terminate) return;
    // 004b3882  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b3884  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b3886  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004b3888  e8b56bfcff             -call 0x47a442
    cpu.esp -= 4;
    sub_47a442(app, cpu);
    if (cpu.terminate) return;
    // 004b388d  39c1                   +cmp ecx, eax
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
    // 004b388f  0f858c000000           -jne 0x4b3921
    if (!cpu.flags.zf)
    {
        goto L_0x004b3921;
    }
    // 004b3895  803a3d                 +cmp byte ptr [edx], 0x3d
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
    // 004b3898  0f8578000000           -jne 0x4b3916
    if (!cpu.flags.zf)
    {
        goto L_0x004b3916;
    }
    // 004b389e  8b157c705400           -mov edx, dword ptr [0x54707c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5533820) /* 0x54707c */);
    // 004b38a4  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004b38a6  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b38a8  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 004b38ab  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b38ad  7462                   -je 0x4b3911
    if (cpu.flags.zf)
    {
        goto L_0x004b3911;
    }
    // 004b38af  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b38b1  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b38b3  eb08                   -jmp 0x4b38bd
    goto L_0x004b38bd;
L_0x004b38b5:
    // 004b38b5  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004b38b8  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004b38ba  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b38bd:
    // 004b38bd  833900                 +cmp dword ptr [ecx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b38c0  75f3                   -jne 0x4b38b5
    if (!cpu.flags.zf)
    {
        goto L_0x004b38b5;
    }
    // 004b38c2  8b3578705400           -mov esi, dword ptr [0x547078]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */);
    // 004b38c8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b38ca  7441                   -je 0x4b390d
    if (cpu.flags.zf)
    {
        goto L_0x004b390d;
    }
    // 004b38cc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b38ce  803c0700               +cmp byte ptr [edi + eax], 0
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
    // 004b38d2  7407                   -je 0x4b38db
    if (cpu.flags.zf)
    {
        goto L_0x004b38db;
    }
    // 004b38d4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b38d6  e86e73feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
L_0x004b38db:
    // 004b38db  8b2d7c705400           -mov ebp, dword ptr [0x54707c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5533820) /* 0x54707c */);
    // 004b38e1  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004b38e3  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b38e5  8b1578705400           -mov edx, dword ptr [0x547078]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */);
    // 004b38eb  c1fe02                 +sar esi, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004b38ee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b38f0  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b38f2  e870050000             -call 0x4b3e67
    cpu.esp -= 4;
    sub_4b3e67(app, cpu);
    if (cpu.terminate) return;
    // 004b38f7  890d78705400           -mov dword ptr [0x547078], ecx
    app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */) = cpu.ecx;
    // 004b38fd  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 004b3900  eb07                   -jmp 0x4b3909
    goto L_0x004b3909;
L_0x004b3902:
    // 004b3902  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b3905  47                     -inc edi
    (cpu.edi)++;
    // 004b3906  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004b3908  40                     -inc eax
    (cpu.eax)++;
L_0x004b3909:
    // 004b3909  39f7                   +cmp edi, esi
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
    // 004b390b  7cf5                   -jl 0x4b3902
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b3902;
    }
L_0x004b390d:
    // 004b390d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b390f  eb27                   -jmp 0x4b3938
    goto L_0x004b3938;
L_0x004b3911:
    // 004b3911  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b3914  eb22                   -jmp 0x4b3938
    goto L_0x004b3938;
L_0x004b3916:
    // 004b3916  42                     -inc edx
    (cpu.edx)++;
    // 004b3917  43                     -inc ebx
    (cpu.ebx)++;
L_0x004b3918:
    // 004b3918  803b00                 +cmp byte ptr [ebx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b391b  0f8558ffffff           -jne 0x4b3879
    if (!cpu.flags.zf)
    {
        goto L_0x004b3879;
    }
L_0x004b3921:
    // 004b3921  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b3924:
    // 004b3924  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b3926  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b3928  0f8544ffffff           -jne 0x4b3872
    if (!cpu.flags.zf)
    {
        goto L_0x004b3872;
    }
    // 004b392e  a17c705400             -mov eax, dword ptr [0x54707c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5533820) /* 0x54707c */);
    // 004b3933  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b3935  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x004b3938:
    // 004b3938  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3939  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b393a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b393b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b393c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b393d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b393e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b393e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b393f  833d8c70540000         +cmp dword ptr [0x54708c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5533836) /* 0x54708c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3946  7421                   -je 0x4b3969
    if (cpu.flags.zf)
    {
        goto L_0x004b3969;
    }
    // 004b3948  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b394a  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 004b394c  8a9b91705400           -mov bl, byte ptr [ebx + 0x547091]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5533841) /* 0x547091 */);
    // 004b3952  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b3955  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b395b  740c                   -je 0x4b3969
    if (cpu.flags.zf)
    {
        goto L_0x004b3969;
    }
    // 004b395d  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 004b395f  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004b3961  8a5201                 -mov dl, byte ptr [edx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b3964  885001                 -mov byte ptr [eax + 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 004b3967  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3968  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3969:
    // 004b3969  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 004b396b  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004b396d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b396e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b396f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b396f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3970  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3971  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b3972  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3975  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004b3977:
    // 004b3977  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b3979  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b397b  e832f6ffff             -call 0x4b2fb2
    cpu.esp -= 4;
    sub_4b2fb2(app, cpu);
    if (cpu.terminate) return;
    // 004b3980  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3982  7531                   -jne 0x4b39b5
    if (!cpu.flags.zf)
    {
        goto L_0x004b39b5;
    }
    // 004b3984  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b3986  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004b3988  e827050000             -call 0x4b3eb4
    cpu.esp -= 4;
    sub_4b3eb4(app, cpu);
    if (cpu.terminate) return;
    // 004b398d  e85d050000             -call 0x4b3eef
    cpu.esp -= 4;
    sub_4b3eef(app, cpu);
    if (cpu.terminate) return;
    // 004b3992  e8c1050000             -call 0x4b3f58
    cpu.esp -= 4;
    sub_4b3f58(app, cpu);
    if (cpu.terminate) return;
    // 004b3997  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b3999  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 004b399b  e865c5ffff             -call 0x4aff05
    cpu.esp -= 4;
    sub_4aff05(app, cpu);
    if (cpu.terminate) return;
    // 004b39a0  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 004b39a3  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004b39a5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b39a7  e892ffffff             -call 0x4b393e
    cpu.esp -= 4;
    sub_4b393e(app, cpu);
    if (cpu.terminate) return;
    // 004b39ac  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b39ae  e892f6ffff             -call 0x4b3045
    cpu.esp -= 4;
    sub_4b3045(app, cpu);
    if (cpu.terminate) return;
    // 004b39b3  ebc2                   -jmp 0x4b3977
    goto L_0x004b3977;
L_0x004b39b5:
    // 004b39b5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b39b7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b39ba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b39bb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b39bc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b39bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b39be(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b39be  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b39bf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b39c0  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b39c2  3a1a                   +cmp bl, byte ptr [edx]
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
    // 004b39c4  7541                   -jne 0x4b3a07
    if (!cpu.flags.zf)
    {
        goto L_0x004b3a07;
    }
    // 004b39c6  833d8c70540000         +cmp dword ptr [0x54708c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5533836) /* 0x54708c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b39cd  741f                   -je 0x4b39ee
    if (cpu.flags.zf)
    {
        goto L_0x004b39ee;
    }
    // 004b39cf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b39d1  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b39d3  8a9b91705400           -mov bl, byte ptr [ebx + 0x547091]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5533841) /* 0x547091 */);
    // 004b39d9  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b39dc  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b39e2  740a                   -je 0x4b39ee
    if (cpu.flags.zf)
    {
        goto L_0x004b39ee;
    }
    // 004b39e4  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b39e7  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b39ea  38cb                   +cmp bl, cl
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
    // 004b39ec  7505                   -jne 0x4b39f3
    if (!cpu.flags.zf)
    {
        goto L_0x004b39f3;
    }
L_0x004b39ee:
    // 004b39ee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b39f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b39f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b39f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b39f3:
    // 004b39f3  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004b39f5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b39fa  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 004b39fc  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b3a02  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b3a04  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3a05  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3a06  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3a07:
    // 004b3a07  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b3a09  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b3a0b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b3a0d  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004b3a0f  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b3a11  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b3a13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3a14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3a15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3a16(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3a16  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3a17  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3a18  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3a1b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b3a1d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b3a1f  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004b3a21  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3a23  e830050000             -call 0x4b3f58
    cpu.esp -= 4;
    sub_4b3f58(app, cpu);
    if (cpu.terminate) return;
    // 004b3a28  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b3a2a  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004b3a2c  e8d4c4ffff             -call 0x4aff05
    cpu.esp -= 4;
    sub_4aff05(app, cpu);
    if (cpu.terminate) return;
    // 004b3a31  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
L_0x004b3a34:
    // 004b3a34  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b3a36  e877f5ffff             -call 0x4b2fb2
    cpu.esp -= 4;
    sub_4b2fb2(app, cpu);
    if (cpu.terminate) return;
    // 004b3a3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3a3d  7518                   -jne 0x4b3a57
    if (!cpu.flags.zf)
    {
        goto L_0x004b3a57;
    }
    // 004b3a3f  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004b3a41  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b3a43  e876ffffff             -call 0x4b39be
    cpu.esp -= 4;
    sub_4b39be(app, cpu);
    if (cpu.terminate) return;
    // 004b3a48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3a4a  740b                   -je 0x4b3a57
    if (cpu.flags.zf)
    {
        goto L_0x004b3a57;
    }
    // 004b3a4c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b3a4e  e8f2f5ffff             -call 0x4b3045
    cpu.esp -= 4;
    sub_4b3045(app, cpu);
    if (cpu.terminate) return;
    // 004b3a53  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b3a55  ebdd                   -jmp 0x4b3a34
    goto L_0x004b3a34;
L_0x004b3a57:
    // 004b3a57  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b3a59  e854f5ffff             -call 0x4b2fb2
    cpu.esp -= 4;
    sub_4b2fb2(app, cpu);
    if (cpu.terminate) return;
    // 004b3a5e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3a60  7404                   -je 0x4b3a66
    if (cpu.flags.zf)
    {
        goto L_0x004b3a66;
    }
    // 004b3a62  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b3a64  7504                   -jne 0x4b3a6a
    if (!cpu.flags.zf)
    {
        goto L_0x004b3a6a;
    }
L_0x004b3a66:
    // 004b3a66  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b3a68  eb02                   -jmp 0x4b3a6c
    goto L_0x004b3a6c;
L_0x004b3a6a:
    // 004b3a6a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b3a6c:
    // 004b3a6c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3a6f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3a70  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3a71  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3a72(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3a72  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3a73  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b3a74  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b3a76  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b3a78:
    // 004b3a78  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b3a7a  e833f5ffff             -call 0x4b2fb2
    cpu.esp -= 4;
    sub_4b2fb2(app, cpu);
    if (cpu.terminate) return;
    // 004b3a7f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3a81  750c                   -jne 0x4b3a8f
    if (!cpu.flags.zf)
    {
        goto L_0x004b3a8f;
    }
    // 004b3a83  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b3a85  e8bbf5ffff             -call 0x4b3045
    cpu.esp -= 4;
    sub_4b3045(app, cpu);
    if (cpu.terminate) return;
    // 004b3a8a  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b3a8b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b3a8d  ebe9                   -jmp 0x4b3a78
    goto L_0x004b3a78;
L_0x004b3a8f:
    // 004b3a8f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b3a91  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3a92  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3a93  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3a94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3a94  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3a95  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3a96  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3a97  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3a98  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b3a9a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b3a9c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004b3a9e  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b3aa0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3aa2  7438                   -je 0x4b3adc
    if (cpu.flags.zf)
    {
        goto L_0x004b3adc;
    }
L_0x004b3aa4:
    // 004b3aa4  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b3aa6  7658                   -jbe 0x4b3b00
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3b00;
    }
    // 004b3aa8  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3aab  7418                   -je 0x4b3ac5
    if (cpu.flags.zf)
    {
        goto L_0x004b3ac5;
    }
    // 004b3aad  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004b3ab2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b3ab4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b3ab6  e8cf60ffff             -call 0x4a9b8a
    cpu.esp -= 4;
    sub_4a9b8a(app, cpu);
    if (cpu.terminate) return;
    // 004b3abb  83f8ff                 +cmp eax, -1
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
    // 004b3abe  750c                   -jne 0x4b3acc
    if (!cpu.flags.zf)
    {
        goto L_0x004b3acc;
    }
    // 004b3ac0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3ac1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3ac2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3ac3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3ac4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3ac5:
    // 004b3ac5  66c7060000             -mov word ptr [esi], 0
    app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
    // 004b3aca  eb34                   -jmp 0x4b3b00
    goto L_0x004b3b00;
L_0x004b3acc:
    // 004b3acc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3ace  4d                     -dec ebp
    (cpu.ebp)--;
    // 004b3acf  e871f5ffff             -call 0x4b3045
    cpu.esp -= 4;
    sub_4b3045(app, cpu);
    if (cpu.terminate) return;
    // 004b3ad4  83c602                 +add esi, 2
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
    // 004b3ad7  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b3ad8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b3ada  ebc8                   -jmp 0x4b3aa4
    goto L_0x004b3aa4;
L_0x004b3adc:
    // 004b3adc  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3adf  741f                   -je 0x4b3b00
    if (cpu.flags.zf)
    {
        goto L_0x004b3b00;
    }
    // 004b3ae1  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004b3ae6  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b3ae8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b3aea  e89b60ffff             -call 0x4a9b8a
    cpu.esp -= 4;
    sub_4a9b8a(app, cpu);
    if (cpu.terminate) return;
    // 004b3aef  83f8ff                 +cmp eax, -1
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
    // 004b3af2  740e                   -je 0x4b3b02
    if (cpu.flags.zf)
    {
        goto L_0x004b3b02;
    }
    // 004b3af4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3af6  e84af5ffff             -call 0x4b3045
    cpu.esp -= 4;
    sub_4b3045(app, cpu);
    if (cpu.terminate) return;
    // 004b3afb  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b3afc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b3afe  ebdc                   -jmp 0x4b3adc
    goto L_0x004b3adc;
L_0x004b3b00:
    // 004b3b00  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004b3b02:
    // 004b3b02  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3b03  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3b04  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3b05  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3b06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3b07(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3b07  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3b08  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3b09  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b3b0a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3b0b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3b0c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3b0d  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b3b10  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b3b12  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004b3b17  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b3b1b  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b3b1e  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 004b3b23  e84a040000             -call 0x4b3f72
    cpu.esp -= 4;
    sub_4b3f72(app, cpu);
    if (cpu.terminate) return;
    // 004b3b28  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b3b2a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3b2c  7458                   -je 0x4b3b86
    if (cpu.flags.zf)
    {
        goto L_0x004b3b86;
    }
    // 004b3b2e  39c8                   +cmp eax, ecx
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
    // 004b3b30  7454                   -je 0x4b3b86
    if (cpu.flags.zf)
    {
        goto L_0x004b3b86;
    }
    // 004b3b32  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b3b34  29cd                   -sub ebp, ecx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b3b36  d1fd                   -sar ebp, 1
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (1 /*0x1*/ % 32));
    // 004b3b38  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004b3b3a  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 004b3b3d  e81120feff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b3b42  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b3b44  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b3b48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3b4a  743a                   -je 0x4b3b86
    if (cpu.flags.zf)
    {
        goto L_0x004b3b86;
    }
    // 004b3b4c  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004b3b4e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b3b50  e837bcffff             -call 0x4af78c
    cpu.esp -= 4;
    sub_4af78c(app, cpu);
    if (cpu.terminate) return;
    // 004b3b55  8d5702                 -lea edx, [edi + 2]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004b3b58  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b3b5a  66c7042e0000           -mov word ptr [esi + ebp], 0
    app->getMemory<x86::reg16>(cpu.esi + cpu.ebp * 1) = 0 /*0x0*/;
    // 004b3b60  e814bcffff             -call 0x4af779
    cpu.esp -= 4;
    sub_4af779(app, cpu);
    if (cpu.terminate) return;
    // 004b3b65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3b67  743d                   -je 0x4b3ba6
    if (cpu.flags.zf)
    {
        goto L_0x004b3ba6;
    }
    // 004b3b69  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b3b6b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b3b6f  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b3b72  e8dc1ffeff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b3b77  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b3b79  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b3b7b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3b7d  7511                   -jne 0x4b3b90
    if (!cpu.flags.zf)
    {
        goto L_0x004b3b90;
    }
L_0x004b3b7f:
    // 004b3b7f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b3b81  e8c370feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
L_0x004b3b86:
    // 004b3b86  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b3b8b  e998000000             -jmp 0x4b3c28
    goto L_0x004b3c28;
L_0x004b3b90:
    // 004b3b90  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b3b94  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b3b98  01f7                   +add edi, esi
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
    // 004b3b9a  e8edbbffff             -call 0x4af78c
    cpu.esp -= 4;
    sub_4af78c(app, cpu);
    if (cpu.terminate) return;
    // 004b3b9f  66c7070000             -mov word ptr [edi], 0
    app->getMemory<x86::reg16>(cpu.edi) = 0 /*0x0*/;
    // 004b3ba4  eb02                   -jmp 0x4b3ba8
    goto L_0x004b3ba8;
L_0x004b3ba6:
    // 004b3ba6  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004b3ba8:
    // 004b3ba8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b3bac  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b3bae  e8d5030000             -call 0x4b3f88
    cpu.esp -= 4;
    sub_4b3f88(app, cpu);
    if (cpu.terminate) return;
    // 004b3bb3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b3bb5  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b3bb9  e88b70feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004b3bbe  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b3bc0  e88470feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004b3bc5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b3bc7  74bd                   -je 0x4b3b86
    if (cpu.flags.zf)
    {
        goto L_0x004b3b86;
    }
    // 004b3bc9  833d8070540000         +cmp dword ptr [0x547080], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5533824) /* 0x547080 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3bd0  7505                   -jne 0x4b3bd7
    if (!cpu.flags.zf)
    {
        goto L_0x004b3bd7;
    }
    // 004b3bd2  e877040000             -call 0x4b404e
    cpu.esp -= 4;
    sub_4b404e(app, cpu);
    if (cpu.terminate) return;
L_0x004b3bd7:
    // 004b3bd7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3bd9  e854000000             -call 0x4b3c32
    cpu.esp -= 4;
    sub_4b3c32(app, cpu);
    if (cpu.terminate) return;
    // 004b3bde  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3be0  75a4                   -jne 0x4b3b86
    if (!cpu.flags.zf)
    {
        goto L_0x004b3b86;
    }
    // 004b3be2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3be4  e890bbffff             -call 0x4af779
    cpu.esp -= 4;
    sub_4af779(app, cpu);
    if (cpu.terminate) return;
    // 004b3be9  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b3bec  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b3bf0  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b3bf3  e85b1ffeff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b3bf8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b3bfa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3bfc  750f                   -jne 0x4b3c0d
    if (!cpu.flags.zf)
    {
        goto L_0x004b3c0d;
    }
    // 004b3bfe  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004b3c03  e8e91efeff             -call 0x495af1
    cpu.esp -= 4;
    sub_495af1(app, cpu);
    if (cpu.terminate) return;
    // 004b3c08  e979ffffff             -jmp 0x4b3b86
    goto L_0x004b3b86;
L_0x004b3c0d:
    // 004b3c0d  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004b3c11  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b3c13  e8cc85ffff             -call 0x4ac1e4
    cpu.esp -= 4;
    sub_4ac1e4(app, cpu);
    if (cpu.terminate) return;
    // 004b3c18  83f8ff                 +cmp eax, -1
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
    // 004b3c1b  0f845effffff           -je 0x4b3b7f
    if (cpu.flags.zf)
    {
        goto L_0x004b3b7f;
    }
    // 004b3c21  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b3c23  e8cbfaffff             -call 0x4b36f3
    cpu.esp -= 4;
    sub_4b36f3(app, cpu);
    if (cpu.terminate) return;
L_0x004b3c28:
    // 004b3c28  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b3c2b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3c2c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3c2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3c2e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3c2f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3c30  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3c31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3c2b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b3c2b;
    // 004b3b07  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3b08  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3b09  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b3b0a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3b0b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3b0c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3b0d  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b3b10  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b3b12  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004b3b17  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b3b1b  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b3b1e  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 004b3b23  e84a040000             -call 0x4b3f72
    cpu.esp -= 4;
    sub_4b3f72(app, cpu);
    if (cpu.terminate) return;
    // 004b3b28  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b3b2a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3b2c  7458                   -je 0x4b3b86
    if (cpu.flags.zf)
    {
        goto L_0x004b3b86;
    }
    // 004b3b2e  39c8                   +cmp eax, ecx
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
    // 004b3b30  7454                   -je 0x4b3b86
    if (cpu.flags.zf)
    {
        goto L_0x004b3b86;
    }
    // 004b3b32  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b3b34  29cd                   -sub ebp, ecx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b3b36  d1fd                   -sar ebp, 1
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (1 /*0x1*/ % 32));
    // 004b3b38  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004b3b3a  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 004b3b3d  e81120feff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b3b42  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b3b44  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b3b48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3b4a  743a                   -je 0x4b3b86
    if (cpu.flags.zf)
    {
        goto L_0x004b3b86;
    }
    // 004b3b4c  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004b3b4e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b3b50  e837bcffff             -call 0x4af78c
    cpu.esp -= 4;
    sub_4af78c(app, cpu);
    if (cpu.terminate) return;
    // 004b3b55  8d5702                 -lea edx, [edi + 2]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004b3b58  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b3b5a  66c7042e0000           -mov word ptr [esi + ebp], 0
    app->getMemory<x86::reg16>(cpu.esi + cpu.ebp * 1) = 0 /*0x0*/;
    // 004b3b60  e814bcffff             -call 0x4af779
    cpu.esp -= 4;
    sub_4af779(app, cpu);
    if (cpu.terminate) return;
    // 004b3b65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3b67  743d                   -je 0x4b3ba6
    if (cpu.flags.zf)
    {
        goto L_0x004b3ba6;
    }
    // 004b3b69  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b3b6b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b3b6f  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b3b72  e8dc1ffeff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b3b77  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b3b79  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b3b7b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3b7d  7511                   -jne 0x4b3b90
    if (!cpu.flags.zf)
    {
        goto L_0x004b3b90;
    }
L_0x004b3b7f:
    // 004b3b7f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b3b81  e8c370feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
L_0x004b3b86:
    // 004b3b86  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b3b8b  e998000000             -jmp 0x4b3c28
    goto L_0x004b3c28;
L_0x004b3b90:
    // 004b3b90  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b3b94  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b3b98  01f7                   +add edi, esi
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
    // 004b3b9a  e8edbbffff             -call 0x4af78c
    cpu.esp -= 4;
    sub_4af78c(app, cpu);
    if (cpu.terminate) return;
    // 004b3b9f  66c7070000             -mov word ptr [edi], 0
    app->getMemory<x86::reg16>(cpu.edi) = 0 /*0x0*/;
    // 004b3ba4  eb02                   -jmp 0x4b3ba8
    goto L_0x004b3ba8;
L_0x004b3ba6:
    // 004b3ba6  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004b3ba8:
    // 004b3ba8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b3bac  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b3bae  e8d5030000             -call 0x4b3f88
    cpu.esp -= 4;
    sub_4b3f88(app, cpu);
    if (cpu.terminate) return;
    // 004b3bb3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b3bb5  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b3bb9  e88b70feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004b3bbe  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b3bc0  e88470feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004b3bc5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b3bc7  74bd                   -je 0x4b3b86
    if (cpu.flags.zf)
    {
        goto L_0x004b3b86;
    }
    // 004b3bc9  833d8070540000         +cmp dword ptr [0x547080], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5533824) /* 0x547080 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3bd0  7505                   -jne 0x4b3bd7
    if (!cpu.flags.zf)
    {
        goto L_0x004b3bd7;
    }
    // 004b3bd2  e877040000             -call 0x4b404e
    cpu.esp -= 4;
    sub_4b404e(app, cpu);
    if (cpu.terminate) return;
L_0x004b3bd7:
    // 004b3bd7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3bd9  e854000000             -call 0x4b3c32
    cpu.esp -= 4;
    sub_4b3c32(app, cpu);
    if (cpu.terminate) return;
    // 004b3bde  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3be0  75a4                   -jne 0x4b3b86
    if (!cpu.flags.zf)
    {
        goto L_0x004b3b86;
    }
    // 004b3be2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3be4  e890bbffff             -call 0x4af779
    cpu.esp -= 4;
    sub_4af779(app, cpu);
    if (cpu.terminate) return;
    // 004b3be9  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b3bec  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b3bf0  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b3bf3  e85b1ffeff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b3bf8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b3bfa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3bfc  750f                   -jne 0x4b3c0d
    if (!cpu.flags.zf)
    {
        goto L_0x004b3c0d;
    }
    // 004b3bfe  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004b3c03  e8e91efeff             -call 0x495af1
    cpu.esp -= 4;
    sub_495af1(app, cpu);
    if (cpu.terminate) return;
    // 004b3c08  e979ffffff             -jmp 0x4b3b86
    goto L_0x004b3b86;
L_0x004b3c0d:
    // 004b3c0d  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004b3c11  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b3c13  e8cc85ffff             -call 0x4ac1e4
    cpu.esp -= 4;
    sub_4ac1e4(app, cpu);
    if (cpu.terminate) return;
    // 004b3c18  83f8ff                 +cmp eax, -1
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
    // 004b3c1b  0f845effffff           -je 0x4b3b7f
    if (cpu.flags.zf)
    {
        goto L_0x004b3b7f;
    }
    // 004b3c21  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b3c23  e8cbfaffff             -call 0x4b36f3
    cpu.esp -= 4;
    sub_4b36f3(app, cpu);
    if (cpu.terminate) return;
L_0x004b3c28:
    // 004b3c28  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_entry_0x004b3c2b:
    // 004b3c2b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3c2c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3c2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3c2e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3c2f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3c30  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3c31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3c32(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3c32  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3c33  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3c34  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b3c35  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3c36  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3c37  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3c38  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b3c3b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b3c3d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3c3f  750a                   -jne 0x4b3c4b
    if (!cpu.flags.zf)
    {
        goto L_0x004b3c4b;
    }
L_0x004b3c41:
    // 004b3c41  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b3c46  e92b010000             -jmp 0x4b3d76
    goto L_0x004b3d76;
L_0x004b3c4b:
    // 004b3c4b  66833800               +cmp word ptr [eax], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b3c4f  7416                   -je 0x4b3c67
    if (cpu.flags.zf)
    {
        goto L_0x004b3c67;
    }
    // 004b3c51  8d5002                 -lea edx, [eax + 2]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004b3c54  eb09                   -jmp 0x4b3c5f
    goto L_0x004b3c5f;
L_0x004b3c56:
    // 004b3c56  6683f93d               +cmp cx, 0x3d
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b3c5a  740b                   -je 0x4b3c67
    if (cpu.flags.zf)
    {
        goto L_0x004b3c67;
    }
    // 004b3c5c  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004b3c5f:
    // 004b3c5f  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004b3c62  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 004b3c65  75ef                   -jne 0x4b3c56
    if (!cpu.flags.zf)
    {
        goto L_0x004b3c56;
    }
L_0x004b3c67:
    // 004b3c67  66833a00               +cmp word ptr [edx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b3c6b  74d4                   -je 0x4b3c41
    if (cpu.flags.zf)
    {
        goto L_0x004b3c41;
    }
    // 004b3c6d  66837a0200             +cmp word ptr [edx + 2], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b3c72  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 004b3c75  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b3c77  8b0d80705400           -mov ecx, dword ptr [0x547080]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5533824) /* 0x547080 */);
    // 004b3c7d  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 004b3c7f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b3c81  7531                   -jne 0x4b3cb4
    if (!cpu.flags.zf)
    {
        goto L_0x004b3cb4;
    }
    // 004b3c83  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b3c85  0f85e9000000           -jne 0x4b3d74
    if (!cpu.flags.zf)
    {
        goto L_0x004b3d74;
    }
    // 004b3c8b  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004b3c90  e8be1efeff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b3c95  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b3c97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3c99  74a6                   -je 0x4b3c41
    if (cpu.flags.zf)
    {
        goto L_0x004b3c41;
    }
    // 004b3c9b  a380705400             -mov dword ptr [0x547080], eax
    app->getMemory<x86::reg32>(x86::reg32(5533824) /* 0x547080 */) = cpu.eax;
    // 004b3ca0  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004b3ca2  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b3ca5  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004b3ca7  8958fc                 -mov dword ptr [eax - 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004b3caa  a378705400             -mov dword ptr [0x547078], eax
    app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */) = cpu.eax;
    // 004b3caf  e9b2000000             -jmp 0x4b3d66
    goto L_0x004b3d66;
L_0x004b3cb4:
    // 004b3cb4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b3cb6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b3cb8  e8c1000000             -call 0x4b3d7e
    cpu.esp -= 4;
    sub_4b3d7e(app, cpu);
    if (cpu.terminate) return;
    // 004b3cbd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b3cbf  0f85af000000           -jne 0x4b3d74
    if (!cpu.flags.zf)
    {
        goto L_0x004b3d74;
    }
    // 004b3cc5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3cc7  0f8f96000000           -jg 0x4b3d63
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b3d63;
    }
    // 004b3ccd  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004b3ccf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b3cd1  8b2d78705400           -mov ebp, dword ptr [0x547078]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */);
    // 004b3cd7  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b3cd9  40                     -inc eax
    (cpu.eax)++;
    // 004b3cda  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004b3cdd  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b3ce1  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b3ce4  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b3ce8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b3ceb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b3ced  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b3cef  7533                   -jne 0x4b3d24
    if (!cpu.flags.zf)
    {
        goto L_0x004b3d24;
    }
    // 004b3cf1  e85d1efeff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b3cf6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b3cf8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b3cfa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3cfc  0f843fffffff           -je 0x4b3c41
    if (cpu.flags.zf)
    {
        goto L_0x004b3c41;
    }
    // 004b3d02  8b1580705400           -mov edx, dword ptr [0x547080]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5533824) /* 0x547080 */);
    // 004b3d08  e87fbaffff             -call 0x4af78c
    cpu.esp -= 4;
    sub_4af78c(app, cpu);
    if (cpu.terminate) return;
    // 004b3d0d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b3d10  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b3d14  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004b3d16  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b3d18  a378705400             -mov dword ptr [0x547078], eax
    app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */) = cpu.eax;
    // 004b3d1d  e89d04fdff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 004b3d22  eb2d                   -jmp 0x4b3d51
    goto L_0x004b3d51;
L_0x004b3d24:
    // 004b3d24  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b3d26  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3d28  e8c7b6ffff             -call 0x4af3f4
    cpu.esp -= 4;
    sub_4af3f4(app, cpu);
    if (cpu.terminate) return;
    // 004b3d2d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b3d2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3d31  0f840affffff           -je 0x4b3c41
    if (cpu.flags.zf)
    {
        goto L_0x004b3c41;
    }
    // 004b3d37  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004b3d3a  8b1578705400           -mov edx, dword ptr [0x547078]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */);
    // 004b3d40  01c5                   +add ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b3d42  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b3d44  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b3d46  e81c010000             -call 0x4b3e67
    cpu.esp -= 4;
    sub_4b3e67(app, cpu);
    if (cpu.terminate) return;
    // 004b3d4b  892d78705400           -mov dword ptr [0x547078], ebp
    app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */) = cpu.ebp;
L_0x004b3d51:
    // 004b3d51  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b3d53  890d80705400           -mov dword ptr [0x547080], ecx
    app->getMemory<x86::reg32>(x86::reg32(5533824) /* 0x547080 */) = cpu.ecx;
    // 004b3d59  c744810400000000       -mov dword ptr [ecx + eax*4 + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) = 0 /*0x0*/;
    // 004b3d61  eb03                   -jmp 0x4b3d66
    goto L_0x004b3d66;
L_0x004b3d63:
    // 004b3d63  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x004b3d66:
    // 004b3d66  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b3d68  893c81                 -mov dword ptr [ecx + eax*4], edi
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4) = cpu.edi;
    // 004b3d6b  a178705400             -mov eax, dword ptr [0x547078]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */);
    // 004b3d70  c6040600               -mov byte ptr [esi + eax], 0
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
L_0x004b3d74:
    // 004b3d74  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b3d76:
    // 004b3d76  83c408                 +add esp, 8
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
    // 004b3d79  e9adfeffff             -jmp 0x4b3c2b
    return sub_4b3c2b(app, cpu);
}

/* align: skip  */
void Application::sub_4b3d7e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3d7e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3d7f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3d80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3d81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3d82  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3d83  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b3d85  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004b3d87  8b3580705400           -mov esi, dword ptr [0x547080]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5533824) /* 0x547080 */);
    // 004b3d8d  e9bb000000             -jmp 0x4b3e4d
    goto L_0x004b3e4d;
L_0x004b3d92:
    // 004b3d92  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004b3d94  e9a7000000             -jmp 0x4b3e40
    goto L_0x004b3e40;
L_0x004b3d99:
    // 004b3d99  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b3d9b  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 004b3d9e  e8fb020000             -call 0x4b409e
    cpu.esp -= 4;
    sub_4b409e(app, cpu);
    if (cpu.terminate) return;
    // 004b3da3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b3da5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b3da7  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 004b3daa  e8ef020000             -call 0x4b409e
    cpu.esp -= 4;
    sub_4b409e(app, cpu);
    if (cpu.terminate) return;
    // 004b3daf  6639c1                 +cmp cx, ax
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.ax));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b3db2  0f8592000000           -jne 0x4b3e4a
    if (!cpu.flags.zf)
    {
        goto L_0x004b3e4a;
    }
    // 004b3db8  66833a3d               +cmp word ptr [edx], 0x3d
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b3dbc  0f8578000000           -jne 0x4b3e3a
    if (!cpu.flags.zf)
    {
        goto L_0x004b3e3a;
    }
    // 004b3dc2  8b1580705400           -mov edx, dword ptr [0x547080]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5533824) /* 0x547080 */);
    // 004b3dc8  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004b3dca  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b3dcc  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 004b3dcf  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b3dd1  7462                   -je 0x4b3e35
    if (cpu.flags.zf)
    {
        goto L_0x004b3e35;
    }
    // 004b3dd3  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b3dd5  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b3dd7  eb08                   -jmp 0x4b3de1
    goto L_0x004b3de1;
L_0x004b3dd9:
    // 004b3dd9  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004b3ddc  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004b3dde  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b3de1:
    // 004b3de1  833900                 +cmp dword ptr [ecx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3de4  75f3                   -jne 0x4b3dd9
    if (!cpu.flags.zf)
    {
        goto L_0x004b3dd9;
    }
    // 004b3de6  8b3578705400           -mov esi, dword ptr [0x547078]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */);
    // 004b3dec  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b3dee  7441                   -je 0x4b3e31
    if (cpu.flags.zf)
    {
        goto L_0x004b3e31;
    }
    // 004b3df0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b3df2  803c0700               +cmp byte ptr [edi + eax], 0
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
    // 004b3df6  7407                   -je 0x4b3dff
    if (cpu.flags.zf)
    {
        goto L_0x004b3dff;
    }
    // 004b3df8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b3dfa  e84a6efeff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
L_0x004b3dff:
    // 004b3dff  8b2d80705400           -mov ebp, dword ptr [0x547080]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5533824) /* 0x547080 */);
    // 004b3e05  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004b3e07  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b3e09  8b1578705400           -mov edx, dword ptr [0x547078]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */);
    // 004b3e0f  c1fe02                 +sar esi, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004b3e12  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3e14  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b3e16  e84c000000             -call 0x4b3e67
    cpu.esp -= 4;
    sub_4b3e67(app, cpu);
    if (cpu.terminate) return;
    // 004b3e1b  890d78705400           -mov dword ptr [0x547078], ecx
    app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */) = cpu.ecx;
    // 004b3e21  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 004b3e24  eb07                   -jmp 0x4b3e2d
    goto L_0x004b3e2d;
L_0x004b3e26:
    // 004b3e26  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b3e29  47                     -inc edi
    (cpu.edi)++;
    // 004b3e2a  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004b3e2c  40                     -inc eax
    (cpu.eax)++;
L_0x004b3e2d:
    // 004b3e2d  39f7                   +cmp edi, esi
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
    // 004b3e2f  7cf5                   -jl 0x4b3e26
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b3e26;
    }
L_0x004b3e31:
    // 004b3e31  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b3e33  eb2c                   -jmp 0x4b3e61
    goto L_0x004b3e61;
L_0x004b3e35:
    // 004b3e35  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b3e38  eb27                   -jmp 0x4b3e61
    goto L_0x004b3e61;
L_0x004b3e3a:
    // 004b3e3a  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b3e3d  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004b3e40:
    // 004b3e40  66833b00               +cmp word ptr [ebx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b3e44  0f854fffffff           -jne 0x4b3d99
    if (!cpu.flags.zf)
    {
        goto L_0x004b3d99;
    }
L_0x004b3e4a:
    // 004b3e4a  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b3e4d:
    // 004b3e4d  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b3e4f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b3e51  0f853bffffff           -jne 0x4b3d92
    if (!cpu.flags.zf)
    {
        goto L_0x004b3d92;
    }
    // 004b3e57  a180705400             -mov eax, dword ptr [0x547080]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5533824) /* 0x547080 */);
    // 004b3e5c  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b3e5e  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x004b3e61:
    // 004b3e61  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3e62  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3e63  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3e64  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3e65  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3e66  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3e67(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3e67  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3e68  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3e69  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3e6a  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b3e6c  39c2                   +cmp edx, eax
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
    // 004b3e6e  7440                   -je 0x4b3eb0
    if (cpu.flags.zf)
    {
        goto L_0x004b3eb0;
    }
    // 004b3e70  7328                   -jae 0x4b3e9a
    if (!cpu.flags.cf)
    {
        goto L_0x004b3e9a;
    }
    // 004b3e72  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 004b3e75  39c7                   +cmp edi, eax
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
    // 004b3e77  7621                   -jbe 0x4b3e9a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3e9a;
    }
    // 004b3e79  8d77ff                 -lea esi, [edi - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 004b3e7c  8d3c18                 -lea edi, [eax + ebx]
    cpu.edi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004b3e7f  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004b3e81  4f                     -dec edi
    (cpu.edi)--;
    // 004b3e82  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b3e83  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004b3e85  fd                     -std 
    cpu.flags.df = 1;
    // 004b3e86  4e                     -dec esi
    (cpu.esi)--;
    // 004b3e87  4f                     -dec edi
    (cpu.edi)--;
    // 004b3e88  d1e9                   +shr ecx, 1
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
    // 004b3e8a  66f3a5                 -rep movsw word ptr es:[edi], word ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg16>(cpu.ees + cpu.edi) = app->getMemory<x86::reg16>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 2;
            cpu.esi -= 2;
        }
        else
        {
            cpu.edi += 2;
            cpu.esi += 2;
        }
        --cpu.ecx;
    }
    // 004b3e8d  11c9                   -adc ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004b3e8f  46                     -inc esi
    (cpu.esi)++;
    // 004b3e90  47                     -inc edi
    (cpu.edi)++;
    // 004b3e91  66f3a4                 -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b3e94  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b3e95  fc                     -cld 
    cpu.flags.df = 0;
    // 004b3e96  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3e97  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3e98  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3e99  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3e9a:
    // 004b3e9a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b3e9c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b3e9e  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004b3ea0  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b3ea1  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004b3ea3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3ea4  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b3ea7  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b3ea9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3eaa  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b3ead  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b3eaf  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x004b3eb0:
    // 004b3eb0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3eb1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3eb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3eb3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3eb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3eb4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b3eb5  833d8c70540000         +cmp dword ptr [0x54708c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5533836) /* 0x54708c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3ebc  7428                   -je 0x4b3ee6
    if (cpu.flags.zf)
    {
        goto L_0x004b3ee6;
    }
    // 004b3ebe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b3ec0  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b3ec2  8a9291705400           -mov dl, byte ptr [edx + 0x547091]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5533841) /* 0x547091 */);
    // 004b3ec8  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b3ecb  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b3ed1  7413                   -je 0x4b3ee6
    if (cpu.flags.zf)
    {
        goto L_0x004b3ee6;
    }
    // 004b3ed3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b3ed5  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b3ed7  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b3eda  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b3edd  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b3ee2  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b3ee4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3ee5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3ee6:
    // 004b3ee6  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004b3ee8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b3eed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3eee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3eef(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3eef  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3ef0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3ef1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b3ef2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3ef5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b3ef7  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004b3ef9  e85a000000             -call 0x4b3f58
    cpu.esp -= 4;
    sub_4b3f58(app, cpu);
    if (cpu.terminate) return;
    // 004b3efe  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b3f00  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004b3f02  e8febfffff             -call 0x4aff05
    cpu.esp -= 4;
    sub_4aff05(app, cpu);
    if (cpu.terminate) return;
    // 004b3f07  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 004b3f0a  813dacd94c00a4030000   +cmp dword ptr [0x4cd9ac], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5036460) /* 0x4cd9ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3f14  7526                   -jne 0x4b3f3c
    if (!cpu.flags.zf)
    {
        goto L_0x004b3f3c;
    }
    // 004b3f16  833d8c70540000         +cmp dword ptr [0x54708c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5533836) /* 0x54708c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3f1d  741d                   -je 0x4b3f3c
    if (cpu.flags.zf)
    {
        goto L_0x004b3f3c;
    }
    // 004b3f1f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b3f21  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004b3f24  8a8091705400           -mov al, byte ptr [eax + 0x547091]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5533841) /* 0x547091 */);
    // 004b3f2a  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b3f2c  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b3f31  7409                   -je 0x4b3f3c
    if (cpu.flags.zf)
    {
        goto L_0x004b3f3c;
    }
    // 004b3f33  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b3f35  e874010000             -call 0x4b40ae
    cpu.esp -= 4;
    sub_4b40ae(app, cpu);
    if (cpu.terminate) return;
    // 004b3f3a  eb15                   -jmp 0x4b3f51
    goto L_0x004b3f51;
L_0x004b3f3c:
    // 004b3f3c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004b3f3e  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b3f42  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b3f43  2eff1594534b00         -call dword ptr cs:[0x4b5394]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936596) /* 0x4b5394 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b3f4a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b3f4c  e863ffffff             -call 0x4b3eb4
    cpu.esp -= 4;
    sub_4b3eb4(app, cpu);
    if (cpu.terminate) return;
L_0x004b3f51:
    // 004b3f51  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3f54  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3f55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3f56  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3f57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3f58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3f58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3f59  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b3f5b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b3f5d  f6c7ff                 +test bh, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 255 /*0xff*/));
    // 004b3f60  740c                   -je 0x4b3f6e
    if (cpu.flags.zf)
    {
        goto L_0x004b3f6e;
    }
    // 004b3f62  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b3f64  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004b3f67  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 004b3f6a  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004b3f6c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3f6d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3f6e:
    // 004b3f6e  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 004b3f70  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3f71  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3f72(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3f72  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3f73  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x004b3f75:
    // 004b3f75  663b18                 +cmp bx, word ptr [eax]
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
    // 004b3f78  740c                   -je 0x4b3f86
    if (cpu.flags.zf)
    {
        goto L_0x004b3f86;
    }
    // 004b3f7a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b3f7c  40                     -inc eax
    (cpu.eax)++;
    // 004b3f7d  40                     -inc eax
    (cpu.eax)++;
    // 004b3f7e  66833a00               +cmp word ptr [edx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b3f82  75f1                   -jne 0x4b3f75
    if (!cpu.flags.zf)
    {
        goto L_0x004b3f75;
    }
    // 004b3f84  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b3f86:
    // 004b3f86  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3f87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3f88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3f88  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3f89  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3f8a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3f8b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3f8c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3f8d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b3f8e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b3f90  66813d05ac4c000080     +cmp word ptr [0x4cac05], 0x8000
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5024773) /* 0x4cac05 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b3f99  730e                   -jae 0x4b3fa9
    if (!cpu.flags.cf)
    {
        goto L_0x004b3fa9;
    }
    // 004b3f9b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3f9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b3f9d  2eff1554554b00         -call dword ptr cs:[0x4b5554]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937044) /* 0x4b5554 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b3fa4  e99c000000             -jmp 0x4b4045
    goto L_0x004b4045;
L_0x004b3fa9:
    // 004b3fa9  e8cbb7ffff             -call 0x4af779
    cpu.esp -= 4;
    sub_4af779(app, cpu);
    if (cpu.terminate) return;
    // 004b3fae  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b3fb0  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b3fb3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3fb5  e8991bfeff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b3fba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b3fbc  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b3fbe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3fc0  0f847f000000           -je 0x4b4045
    if (cpu.flags.zf)
    {
        goto L_0x004b4045;
    }
    // 004b3fc6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b3fc8  7504                   -jne 0x4b3fce
    if (!cpu.flags.zf)
    {
        goto L_0x004b3fce;
    }
    // 004b3fca  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004b3fcc  eb1d                   -jmp 0x4b3feb
    goto L_0x004b3feb;
L_0x004b3fce:
    // 004b3fce  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b3fd0  e8a4b7ffff             -call 0x4af779
    cpu.esp -= 4;
    sub_4af779(app, cpu);
    if (cpu.terminate) return;
    // 004b3fd5  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b3fd7  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b3fda  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3fdc  e8721bfeff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b3fe1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b3fe3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3fe5  7504                   -jne 0x4b3feb
    if (!cpu.flags.zf)
    {
        goto L_0x004b3feb;
    }
    // 004b3fe7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b3fe9  eb1e                   -jmp 0x4b4009
    goto L_0x004b4009;
L_0x004b3feb:
    // 004b3feb  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b3fee  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b3ff0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b3ff2  e8ed81ffff             -call 0x4ac1e4
    cpu.esp -= 4;
    sub_4ac1e4(app, cpu);
    if (cpu.terminate) return;
    // 004b3ff7  83f8ff                 +cmp eax, -1
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
    // 004b3ffa  7516                   -jne 0x4b4012
    if (!cpu.flags.zf)
    {
        goto L_0x004b4012;
    }
    // 004b3ffc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b3ffe  e8466cfeff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004b4003  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b4005  7407                   -je 0x4b400e
    if (cpu.flags.zf)
    {
        goto L_0x004b400e;
    }
L_0x004b4007:
    // 004b4007  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004b4009:
    // 004b4009  e83b6cfeff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
L_0x004b400e:
    // 004b400e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b4010  eb33                   -jmp 0x4b4045
    goto L_0x004b4045;
L_0x004b4012:
    // 004b4012  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b4014  7410                   -je 0x4b4026
    if (cpu.flags.zf)
    {
        goto L_0x004b4026;
    }
    // 004b4016  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b4018  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004b401a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b401c  e8c381ffff             -call 0x4ac1e4
    cpu.esp -= 4;
    sub_4ac1e4(app, cpu);
    if (cpu.terminate) return;
    // 004b4021  83f8ff                 +cmp eax, -1
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
    // 004b4024  74e1                   -je 0x4b4007
    if (cpu.flags.zf)
    {
        goto L_0x004b4007;
    }
L_0x004b4026:
    // 004b4026  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4027  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4028  2eff1550554b00         -call dword ptr cs:[0x4b5550]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937040) /* 0x4b5550 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b402f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4031  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b4033  e8116cfeff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004b4038  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b403a  7407                   -je 0x4b4043
    if (cpu.flags.zf)
    {
        goto L_0x004b4043;
    }
    // 004b403c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b403e  e8066cfeff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
L_0x004b4043:
    // 004b4043  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004b4045:
    // 004b4045  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4048  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4049  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b404a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b404b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b404c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b404d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b404e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b404e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b404f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4050  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b4051  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4052  8b357c705400           -mov esi, dword ptr [0x54707c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5533820) /* 0x54707c */);
    // 004b4058  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b405a  743d                   -je 0x4b4099
    if (cpu.flags.zf)
    {
        goto L_0x004b4099;
    }
L_0x004b405c:
    // 004b405c  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b405e  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4061  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b4063  7434                   -je 0x4b4099
    if (cpu.flags.zf)
    {
        goto L_0x004b4099;
    }
    // 004b4065  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b4067  e806faffff             -call 0x4b3a72
    cpu.esp -= 4;
    sub_4b3a72(app, cpu);
    if (cpu.terminate) return;
    // 004b406c  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b406f  8d041b                 -lea eax, [ebx + ebx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 004b4072  e8dc1afeff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b4077  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b4079  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b407b  74df                   -je 0x4b405c
    if (cpu.flags.zf)
    {
        goto L_0x004b405c;
    }
    // 004b407d  e812faffff             -call 0x4b3a94
    cpu.esp -= 4;
    sub_4b3a94(app, cpu);
    if (cpu.terminate) return;
    // 004b4082  83f8ff                 +cmp eax, -1
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
    // 004b4085  7409                   -je 0x4b4090
    if (cpu.flags.zf)
    {
        goto L_0x004b4090;
    }
    // 004b4087  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b4089  e8a4fbffff             -call 0x4b3c32
    cpu.esp -= 4;
    sub_4b3c32(app, cpu);
    if (cpu.terminate) return;
    // 004b408e  ebcc                   -jmp 0x4b405c
    goto L_0x004b405c;
L_0x004b4090:
    // 004b4090  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b4092  e8b26bfeff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004b4097  ebc3                   -jmp 0x4b405c
    goto L_0x004b405c;
L_0x004b4099:
    // 004b4099  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b409a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b409b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b409c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b409d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b409e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b409e  663d6100               +cmp ax, 0x61
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(97 /*0x61*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b40a2  7209                   -jb 0x4b40ad
    if (cpu.flags.cf)
    {
        goto L_0x004b40ad;
    }
    // 004b40a4  663d7a00               +cmp ax, 0x7a
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(122 /*0x7a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b40a8  7703                   -ja 0x4b40ad
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b40ad;
    }
    // 004b40aa  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004b40ad:
    // 004b40ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b40ae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b40ae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b40af  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b40b1  e80b000000             -call 0x4b40c1
    cpu.esp -= 4;
    sub_4b40c1(app, cpu);
    if (cpu.terminate) return;
    // 004b40b6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b40b8  7403                   -je 0x4b40bd
    if (cpu.flags.zf)
    {
        goto L_0x004b40bd;
    }
    // 004b40ba  83ea21                 -sub edx, 0x21
    (cpu.edx) -= x86::reg32(x86::sreg32(33 /*0x21*/));
L_0x004b40bd:
    // 004b40bd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b40bf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b40c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b40c1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b40c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b40c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b40c4  e83b000000             -call 0x4b4104
    cpu.esp -= 4;
    sub_4b4104(app, cpu);
    if (cpu.terminate) return;
    // 004b40c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b40cb  741f                   -je 0x4b40ec
    if (cpu.flags.zf)
    {
        goto L_0x004b40ec;
    }
    // 004b40cd  81fa81820000           +cmp edx, 0x8281
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
    // 004b40d3  7211                   -jb 0x4b40e6
    if (cpu.flags.cf)
    {
        goto L_0x004b40e6;
    }
    // 004b40d5  81fa9a820000           +cmp edx, 0x829a
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
    // 004b40db  7709                   -ja 0x4b40e6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b40e6;
    }
    // 004b40dd  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b40e2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b40e4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b40e5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b40e6:
    // 004b40e6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b40e8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b40ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b40eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b40ec:
    // 004b40ec  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004b40ee  fec0                   -inc al
    (cpu.al)++;
    // 004b40f0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b40f2  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004b40f4  8a8284c84c00           -mov al, byte ptr [edx + 0x4cc884]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5032068) /* 0x4cc884 */);
    // 004b40fa  2480                   -and al, 0x80
    cpu.al &= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 004b40fc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b40fe  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004b4100  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b4102  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4103  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4104(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4104  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b4105  833d8c70540000         +cmp dword ptr [0x54708c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5533836) /* 0x54708c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b410c  7431                   -je 0x4b413f
    if (cpu.flags.zf)
    {
        goto L_0x004b413f;
    }
    // 004b410e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4110  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 004b4113  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b4119  8a9291705400           -mov dl, byte ptr [edx + 0x547091]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5533841) /* 0x547091 */);
    // 004b411f  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b4122  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b4128  7415                   -je 0x4b413f
    if (cpu.flags.zf)
    {
        goto L_0x004b413f;
    }
    // 004b412a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b412f  e80f000000             -call 0x4b4143
    cpu.esp -= 4;
    sub_4b4143(app, cpu);
    if (cpu.terminate) return;
    // 004b4134  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4136  7407                   -je 0x4b413f
    if (cpu.flags.zf)
    {
        goto L_0x004b413f;
    }
    // 004b4138  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b413d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b413e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b413f:
    // 004b413f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b4141  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4142  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4143(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4143  833d8c70540000         +cmp dword ptr [0x54708c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5533836) /* 0x54708c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b414a  7429                   -je 0x4b4175
    if (cpu.flags.zf)
    {
        goto L_0x004b4175;
    }
    // 004b414c  813dacd94c00a4030000   +cmp dword ptr [0x4cd9ac], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5036460) /* 0x4cd9ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4156  740a                   -je 0x4b4162
    if (cpu.flags.zf)
    {
        goto L_0x004b4162;
    }
    // 004b4158  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b415a  741b                   -je 0x4b4177
    if (cpu.flags.zf)
    {
        goto L_0x004b4177;
    }
    // 004b415c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b4161  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b4162:
    // 004b4162  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b4167  8a808ddf4c00           -mov al, byte ptr [eax + 0x4cdf8d]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5037965) /* 0x4cdf8d */);
    // 004b416d  2408                   -and al, 8
    cpu.al &= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004b416f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b4174  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b4175:
    // 004b4175  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b4177:
    // 004b4177  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b4180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4180  833ddce04c0000         +cmp dword ptr [0x4ce0dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5038300) /* 0x4ce0dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4187  751e                   -jne 0x4b41a7
    if (!cpu.flags.zf)
    {
        goto L_0x004b41a7;
    }
    // 004b4189  6888e44c00             -push 0x4ce488
    app->getMemory<x86::reg32>(cpu.esp-4) = 5039240 /*0x4ce488*/;
    cpu.esp -= 4;
    // 004b418e  ff1514554b00           -call dword ptr [0x4b5514]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4936980) /* 0x4b5514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b4194  a3dce04c00             -mov dword ptr [0x4ce0dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5038300) /* 0x4ce0dc */) = cpu.eax;
    // 004b4199  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b419b  750a                   -jne 0x4b41a7
    if (!cpu.flags.zf)
    {
        goto L_0x004b41a7;
    }
    // 004b419d  c705dce04c00ffffffff   -mov dword ptr [0x4ce0dc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5038300) /* 0x4ce0dc */) = 4294967295 /*0xffffffff*/;
L_0x004b41a7:
    // 004b41a7  833ddce04c00ff         +cmp dword ptr [0x4ce0dc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5038300) /* 0x4ce0dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b41ae  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b41b3  7420                   -je 0x4b41d5
    if (cpu.flags.zf)
    {
        goto L_0x004b41d5;
    }
    // 004b41b5  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004b41b9  ff35dce04c00           -push dword ptr [0x4ce0dc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5038300) /* 0x4ce0dc */);
    cpu.esp -= 4;
    // 004b41bf  ff15e4544b00           -call dword ptr [0x4b54e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4936932) /* 0x4b54e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b41c5  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b41c9  83f801                 +cmp eax, 1
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
    // 004b41cc  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004b41ce  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004b41d0  2549000080             -and eax, 0x80000049
    cpu.eax &= x86::reg32(x86::sreg32(2147483721 /*0x80000049*/));
L_0x004b41d5:
    // 004b41d5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

}
