#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_440040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440040  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440041  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440042  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440043  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440044  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440046  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 0044004b  e800180900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00440050  a39c405f00             -mov dword ptr [0x5f409c], eax
    app->getMemory<x86::reg32>(x86::reg32(6242460) /* 0x5f409c */) = cpu.eax;
    // 00440055  b8f9000000             -mov eax, 0xf9
    cpu.eax = 249 /*0xf9*/;
    // 0044005a  e8f1170900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044005f  a3a8405f00             -mov dword ptr [0x5f40a8], eax
    app->getMemory<x86::reg32>(x86::reg32(6242472) /* 0x5f40a8 */) = cpu.eax;
    // 00440064  b8c6000000             -mov eax, 0xc6
    cpu.eax = 198 /*0xc6*/;
    // 00440069  e8e2170900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044006e  6840f64300             -push 0x43f640
    app->getMemory<x86::reg32>(cpu.esp-4) = 4453952 /*0x43f640*/;
    cpu.esp -= 4;
    // 00440073  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00440075  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 00440077  b9a8405f00             -mov ecx, 0x5f40a8
    cpu.ecx = 6242472 /*0x5f40a8*/;
    // 0044007c  68fcd26f00             -push 0x6fd2fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 7328508 /*0x6fd2fc*/;
    cpu.esp -= 4;
    // 00440081  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00440086  ba9c405f00             -mov edx, 0x5f409c
    cpu.edx = 6242460 /*0x5f409c*/;
    // 0044008b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044008d  a3ac405f00             -mov dword ptr [0x5f40ac], eax
    app->getMemory<x86::reg32>(x86::reg32(6242476) /* 0x5f40ac */) = cpu.eax;
    // 00440092  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00440097  e8844b0000             -call 0x444c20
    cpu.esp -= 4;
    sub_444c20(app, cpu);
    if (cpu.terminate) return;
    // 0044009c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044009e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044009f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004400a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004400a1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004400a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4400b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004400b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004400b1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004400b2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004400b4  8b15c8565500           -mov edx, dword ptr [0x5556c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592776) /* 0x5556c8 */);
    // 004400ba  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004400bc  7407                   -je 0x4400c5
    if (cpu.flags.zf)
    {
        goto L_0x004400c5;
    }
    // 004400be  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004400c0  e85bf1ffff             -call 0x43f220
    cpu.esp -= 4;
    sub_43f220(app, cpu);
    if (cpu.terminate) return;
L_0x004400c5:
    // 004400c5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004400c7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004400c8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004400c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4400d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004400d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004400d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004400d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004400d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004400d4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004400d6  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004400dd  750a                   -jne 0x4400e9
    if (!cpu.flags.zf)
    {
        goto L_0x004400e9;
    }
    // 004400df  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004400e4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004400e5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004400e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004400e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004400e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004400e9:
    // 004400e9  b801010000             -mov eax, 0x101
    cpu.eax = 257 /*0x101*/;
    // 004400ee  e85d170900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004400f3  a3b0405f00             -mov dword ptr [0x5f40b0], eax
    app->getMemory<x86::reg32>(x86::reg32(6242480) /* 0x5f40b0 */) = cpu.eax;
    // 004400f8  b8c4000000             -mov eax, 0xc4
    cpu.eax = 196 /*0xc4*/;
    // 004400fd  e84e170900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00440102  a3b4405f00             -mov dword ptr [0x5f40b4], eax
    app->getMemory<x86::reg32>(x86::reg32(6242484) /* 0x5f40b4 */) = cpu.eax;
    // 00440107  b8c5000000             -mov eax, 0xc5
    cpu.eax = 197 /*0xc5*/;
    // 0044010c  e83f170900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00440111  68b0fc4300             -push 0x43fcb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4455600 /*0x43fcb0*/;
    cpu.esp -= 4;
    // 00440116  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00440118  b9b4405f00             -mov ecx, 0x5f40b4
    cpu.ecx = 6242484 /*0x5f40b4*/;
    // 0044011d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044011f  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00440124  bab0405f00             -mov edx, 0x5f40b0
    cpu.edx = 6242480 /*0x5f40b0*/;
    // 00440129  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044012b  a3b8405f00             -mov dword ptr [0x5f40b8], eax
    app->getMemory<x86::reg32>(x86::reg32(6242488) /* 0x5f40b8 */) = cpu.eax;
    // 00440130  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00440135  e896450000             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 0044013a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044013c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044013d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044013e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044013f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440140  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_440160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00440160  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440161  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440162  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440163  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440164  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440165  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440166  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440168  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044016a  a1d8565500             -mov eax, dword ptr [0x5556d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592792) /* 0x5556d8 */);
    // 0044016f  83f805                 +cmp eax, 5
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
    // 00440172  0f876f000000           -ja 0x4401e7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004401e7;
    }
    // 00440178  ff248544014400         -jmp dword ptr [eax*4 + 0x440144]
    cpu.ip = app->getMemory<x86::reg32>(4456772 + cpu.eax * 4); goto dynamic_jump;
  case 0x0044017f:
    // 0044017f  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00440181  8915b8d36f00           -mov dword ptr [0x6fd3b8], edx
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.edx;
    // 00440187  eb5e                   -jmp 0x4401e7
    goto L_0x004401e7;
  case 0x00440189:
    // 00440189  c705b8d36f0003000000   -mov dword ptr [0x6fd3b8], 3
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = 3 /*0x3*/;
    // 00440193  eb52                   -jmp 0x4401e7
    goto L_0x004401e7;
  case 0x00440195:
    // 00440195  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00440197  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 0044019c  893d70d46f00           -mov dword ptr [0x6fd470], edi
    app->getMemory<x86::reg32>(x86::reg32(7328880) /* 0x6fd470 */) = cpu.edi;
    // 004401a2  8935b8d36f00           -mov dword ptr [0x6fd3b8], esi
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.esi;
    // 004401a8  eb3d                   -jmp 0x4401e7
    goto L_0x004401e7;
  case 0x004401aa:
    // 004401aa  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004401af  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004401b4  891570d46f00           -mov dword ptr [0x6fd470], edx
    app->getMemory<x86::reg32>(x86::reg32(7328880) /* 0x6fd470 */) = cpu.edx;
    // 004401ba  a3b8d36f00             -mov dword ptr [0x6fd3b8], eax
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.eax;
    // 004401bf  eb26                   -jmp 0x4401e7
    goto L_0x004401e7;
  case 0x004401c1:
    // 004401c1  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004401c3  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004401c8  893570d46f00           -mov dword ptr [0x6fd470], esi
    app->getMemory<x86::reg32>(x86::reg32(7328880) /* 0x6fd470 */) = cpu.esi;
    // 004401ce  891db8d36f00           -mov dword ptr [0x6fd3b8], ebx
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.ebx;
    // 004401d4  eb11                   -jmp 0x4401e7
    goto L_0x004401e7;
  case 0x004401d6:
    // 004401d6  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004401db  893d70d46f00           -mov dword ptr [0x6fd470], edi
    app->getMemory<x86::reg32>(x86::reg32(7328880) /* 0x6fd470 */) = cpu.edi;
    // 004401e1  893db8d36f00           -mov dword ptr [0x6fd3b8], edi
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.edi;
L_0x004401e7:
    // 004401e7  ba4c785300             -mov edx, 0x53784c
    cpu.edx = 5470284 /*0x53784c*/;
    // 004401ec  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004401ee  e84d280000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004401f3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004401f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004401f7  7424                   -je 0x44021d
    if (cpu.flags.zf)
    {
        goto L_0x0044021d;
    }
    // 004401f9  66833dda227a0000       +cmp word ptr [0x7a22da], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440201  7410                   -je 0x440213
    if (cpu.flags.zf)
    {
        goto L_0x00440213;
    }
    // 00440203  8b1db8d36f00           -mov ebx, dword ptr [0x6fd3b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 00440209  83fb01                 +cmp ebx, 1
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
    // 0044020c  7405                   -je 0x440213
    if (cpu.flags.zf)
    {
        goto L_0x00440213;
    }
    // 0044020e  83fb02                 +cmp ebx, 2
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
    // 00440211  7506                   -jne 0x440219
    if (!cpu.flags.zf)
    {
        goto L_0x00440219;
    }
L_0x00440213:
    // 00440213  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00440217  eb04                   -jmp 0x44021d
    goto L_0x0044021d;
L_0x00440219:
    // 00440219  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x0044021d:
    // 0044021d  ba64785300             -mov edx, 0x537864
    cpu.edx = 5470308 /*0x537864*/;
    // 00440222  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440224  e817280000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440229  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044022b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044022d  7424                   -je 0x440253
    if (cpu.flags.zf)
    {
        goto L_0x00440253;
    }
    // 0044022f  66833dda227a0000       +cmp word ptr [0x7a22da], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440237  7410                   -je 0x440249
    if (cpu.flags.zf)
    {
        goto L_0x00440249;
    }
    // 00440239  8b3db8d36f00           -mov edi, dword ptr [0x6fd3b8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0044023f  83ff01                 +cmp edi, 1
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
    // 00440242  7405                   -je 0x440249
    if (cpu.flags.zf)
    {
        goto L_0x00440249;
    }
    // 00440244  83ff02                 +cmp edi, 2
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440247  7506                   -jne 0x44024f
    if (!cpu.flags.zf)
    {
        goto L_0x0044024f;
    }
L_0x00440249:
    // 00440249  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0044024d  eb04                   -jmp 0x440253
    goto L_0x00440253;
L_0x0044024f:
    // 0044024f  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00440253:
    // 00440253  ba7c785300             -mov edx, 0x53787c
    cpu.edx = 5470332 /*0x53787c*/;
    // 00440258  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044025a  e8e1270000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044025f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440261  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440263  7424                   -je 0x440289
    if (cpu.flags.zf)
    {
        goto L_0x00440289;
    }
    // 00440265  66833dda227a0000       +cmp word ptr [0x7a22da], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044026d  7410                   -je 0x44027f
    if (cpu.flags.zf)
    {
        goto L_0x0044027f;
    }
    // 0044026f  8b35b8d36f00           -mov esi, dword ptr [0x6fd3b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 00440275  83fe01                 +cmp esi, 1
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
    // 00440278  7405                   -je 0x44027f
    if (cpu.flags.zf)
    {
        goto L_0x0044027f;
    }
    // 0044027a  83fe02                 +cmp esi, 2
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
    // 0044027d  7506                   -jne 0x440285
    if (!cpu.flags.zf)
    {
        goto L_0x00440285;
    }
L_0x0044027f:
    // 0044027f  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00440283  eb04                   -jmp 0x440289
    goto L_0x00440289;
L_0x00440285:
    // 00440285  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00440289:
    // 00440289  ba94785300             -mov edx, 0x537894
    cpu.edx = 5470356 /*0x537894*/;
    // 0044028e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440290  e8ab270000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440295  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440297  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440299  7424                   -je 0x4402bf
    if (cpu.flags.zf)
    {
        goto L_0x004402bf;
    }
    // 0044029b  66833dda227a0000       +cmp word ptr [0x7a22da], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004402a3  7410                   -je 0x4402b5
    if (cpu.flags.zf)
    {
        goto L_0x004402b5;
    }
    // 004402a5  8b1db8d36f00           -mov ebx, dword ptr [0x6fd3b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 004402ab  83fb01                 +cmp ebx, 1
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
    // 004402ae  7405                   -je 0x4402b5
    if (cpu.flags.zf)
    {
        goto L_0x004402b5;
    }
    // 004402b0  83fb02                 +cmp ebx, 2
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
    // 004402b3  7506                   -jne 0x4402bb
    if (!cpu.flags.zf)
    {
        goto L_0x004402bb;
    }
L_0x004402b5:
    // 004402b5  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004402b9  eb04                   -jmp 0x4402bf
    goto L_0x004402bf;
L_0x004402bb:
    // 004402bb  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x004402bf:
    // 004402bf  baac785300             -mov edx, 0x5378ac
    cpu.edx = 5470380 /*0x5378ac*/;
    // 004402c4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004402c6  e875270000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004402cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004402cd  7413                   -je 0x4402e2
    if (cpu.flags.zf)
    {
        goto L_0x004402e2;
    }
    // 004402cf  833db8d36f0000         +cmp dword ptr [0x6fd3b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004402d6  7406                   -je 0x4402de
    if (cpu.flags.zf)
    {
        goto L_0x004402de;
    }
    // 004402d8  80480401               +or byte ptr [eax + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004402dc  eb04                   -jmp 0x4402e2
    goto L_0x004402e2;
L_0x004402de:
    // 004402de  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x004402e2:
    // 004402e2  babc785300             -mov edx, 0x5378bc
    cpu.edx = 5470396 /*0x5378bc*/;
    // 004402e7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004402e9  e852270000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004402ee  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004402f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004402f2  0f8471000000           -je 0x440369
    if (cpu.flags.zf)
    {
        goto L_0x00440369;
    }
    // 004402f8  833db8d36f0000         +cmp dword ptr [0x6fd3b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004402ff  0f854e000000           -jne 0x440353
    if (!cpu.flags.zf)
    {
        goto L_0x00440353;
    }
    // 00440305  833d74d46f0000         +cmp dword ptr [0x6fd474], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328884) /* 0x6fd474 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044030c  752d                   -jne 0x44033b
    if (!cpu.flags.zf)
    {
        goto L_0x0044033b;
    }
    // 0044030e  833d84d46f0000         +cmp dword ptr [0x6fd484], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328900) /* 0x6fd484 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440315  7524                   -jne 0x44033b
    if (!cpu.flags.zf)
    {
        goto L_0x0044033b;
    }
    // 00440317  833d78d46f0000         +cmp dword ptr [0x6fd478], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328888) /* 0x6fd478 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044031e  751b                   -jne 0x44033b
    if (!cpu.flags.zf)
    {
        goto L_0x0044033b;
    }
    // 00440320  833d88d46f0000         +cmp dword ptr [0x6fd488], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328904) /* 0x6fd488 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440327  7512                   -jne 0x44033b
    if (!cpu.flags.zf)
    {
        goto L_0x0044033b;
    }
    // 00440329  833d7cd46f0000         +cmp dword ptr [0x6fd47c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328892) /* 0x6fd47c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440330  7509                   -jne 0x44033b
    if (!cpu.flags.zf)
    {
        goto L_0x0044033b;
    }
    // 00440332  833d80d46f0000         +cmp dword ptr [0x6fd480], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328896) /* 0x6fd480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440339  7418                   -je 0x440353
    if (cpu.flags.zf)
    {
        goto L_0x00440353;
    }
L_0x0044033b:
    // 0044033b  b896010000             -mov eax, 0x196
    cpu.eax = 406 /*0x196*/;
    // 00440340  e80b150900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00440345  8a5904                 -mov bl, byte ptr [ecx + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00440348  89413c                 -mov dword ptr [ecx + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0044034b  80e3fe                 +and bl, 0xfe
    cpu.clear_co();
    cpu.set_szp((cpu.bl &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 0044034e  885904                 -mov byte ptr [ecx + 4], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.bl;
    // 00440351  eb16                   -jmp 0x440369
    goto L_0x00440369;
L_0x00440353:
    // 00440353  b897010000             -mov eax, 0x197
    cpu.eax = 407 /*0x197*/;
    // 00440358  e8f3140900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044035d  8a7904                 -mov bh, byte ptr [ecx + 4]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00440360  89413c                 -mov dword ptr [ecx + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 00440363  80cf01                 -or bh, 1
    cpu.bh |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00440366  887904                 -mov byte ptr [ecx + 4], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.bh;
L_0x00440369:
    // 00440369  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044036b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044036c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044036d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044036e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044036f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440370  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440371  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_440390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00440390  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440391  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440392  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440394  8b15d8565500           -mov edx, dword ptr [0x5556d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592792) /* 0x5556d8 */);
    // 0044039a  a1b8d36f00             -mov eax, dword ptr [0x6fd3b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0044039f  83f803                 +cmp eax, 3
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
    // 004403a2  773e                   -ja 0x4403e2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004403e2;
    }
    // 004403a4  ff248574034400         -jmp dword ptr [eax*4 + 0x440374]
    cpu.ip = app->getMemory<x86::reg32>(4457332 + cpu.eax * 4); goto dynamic_jump;
  case 0x004403ab:
    // 004403ab  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004403ad  eb33                   -jmp 0x4403e2
    goto L_0x004403e2;
  case 0x004403af:
    // 004403af  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004403b4  eb2c                   -jmp 0x4403e2
    goto L_0x004403e2;
  case 0x004403b6:
    // 004403b6  833d70d46f0000         +cmp dword ptr [0x6fd470], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328880) /* 0x6fd470 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004403bd  7507                   -jne 0x4403c6
    if (!cpu.flags.zf)
    {
        goto L_0x004403c6;
    }
    // 004403bf  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004403c4  eb1c                   -jmp 0x4403e2
    goto L_0x004403e2;
L_0x004403c6:
    // 004403c6  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 004403cb  eb15                   -jmp 0x4403e2
    goto L_0x004403e2;
  case 0x004403cd:
    // 004403cd  833d70d46f0000         +cmp dword ptr [0x6fd470], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328880) /* 0x6fd470 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004403d4  7507                   -jne 0x4403dd
    if (!cpu.flags.zf)
    {
        goto L_0x004403dd;
    }
    // 004403d6  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004403db  eb05                   -jmp 0x4403e2
    goto L_0x004403e2;
L_0x004403dd:
    // 004403dd  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
L_0x004403e2:
    // 004403e2  8915d8565500           -mov dword ptr [0x5556d8], edx
    app->getMemory<x86::reg32>(x86::reg32(5592792) /* 0x5556d8 */) = cpu.edx;
    // 004403e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004403e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004403ea  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4403f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004403f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004403f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004403f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004403f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004403f4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004403f6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004403f8  66833dda227a0000       +cmp word ptr [0x7a22da], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440400  7505                   -jne 0x440407
    if (!cpu.flags.zf)
    {
        goto L_0x00440407;
    }
    // 00440402  e889ffffff             -call 0x440390
    cpu.esp -= 4;
    sub_440390(app, cpu);
    if (cpu.terminate) return;
L_0x00440407:
    // 00440407  8b15d8565500           -mov edx, dword ptr [0x5556d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592792) /* 0x5556d8 */);
    // 0044040d  3b15dc565500           +cmp edx, dword ptr [0x5556dc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5592796) /* 0x5556dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440413  740d                   -je 0x440422
    if (cpu.flags.zf)
    {
        goto L_0x00440422;
    }
    // 00440415  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440417  8915dc565500           -mov dword ptr [0x5556dc], edx
    app->getMemory<x86::reg32>(x86::reg32(5592796) /* 0x5556dc */) = cpu.edx;
    // 0044041d  e83efdffff             -call 0x440160
    cpu.esp -= 4;
    sub_440160(app, cpu);
    if (cpu.terminate) return;
L_0x00440422:
    // 00440422  8b1db8d36f00           -mov ebx, dword ptr [0x6fd3b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 00440428  83fb01                 +cmp ebx, 1
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
    // 0044042b  7405                   -je 0x440432
    if (cpu.flags.zf)
    {
        goto L_0x00440432;
    }
    // 0044042d  83fb02                 +cmp ebx, 2
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
    // 00440430  7519                   -jne 0x44044b
    if (!cpu.flags.zf)
    {
        goto L_0x0044044b;
    }
L_0x00440432:
    // 00440432  ba7c785300             -mov edx, 0x53787c
    cpu.edx = 5470332 /*0x53787c*/;
    // 00440437  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440439  e802260000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044043e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440440  7420                   -je 0x440462
    if (cpu.flags.zf)
    {
        goto L_0x00440462;
    }
    // 00440442  c740583e575500         -mov dword ptr [eax + 0x58], 0x55573e
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */) = 5592894 /*0x55573e*/;
    // 00440449  eb17                   -jmp 0x440462
    goto L_0x00440462;
L_0x0044044b:
    // 0044044b  ba7c785300             -mov edx, 0x53787c
    cpu.edx = 5470332 /*0x53787c*/;
    // 00440450  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440452  e8e9250000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440457  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440459  7407                   -je 0x440462
    if (cpu.flags.zf)
    {
        goto L_0x00440462;
    }
    // 0044045b  c7405800000000         -mov dword ptr [eax + 0x58], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */) = 0 /*0x0*/;
L_0x00440462:
    // 00440462  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00440464  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440465  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440466  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440467  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440468  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_440470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440470  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440471  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440472  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440473  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440474  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440475  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440477  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00440479  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044047b  40                     -inc eax
    (cpu.eax)++;
    // 0044047c  66c704452e5755000100   -mov word ptr [eax*2 + 0x55572e], 1
    app->getMemory<x86::reg16>(x86::reg32(5592878) /* 0x55572e */ + cpu.eax * 2) = 1 /*0x1*/;
L_0x00440486:
    // 00440486  83f807                 +cmp eax, 7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440489  730d                   -jae 0x440498
    if (!cpu.flags.cf)
    {
        goto L_0x00440498;
    }
    // 0044048b  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044048c  66c704452e5755000100   -mov word ptr [eax*2 + 0x55572e], 1
    app->getMemory<x86::reg16>(x86::reg32(5592878) /* 0x55572e */ + cpu.eax * 2) = 1 /*0x1*/;
    // 00440496  ebee                   -jmp 0x440486
    goto L_0x00440486;
L_0x00440498:
    // 00440498  833d0cd56f0000         +cmp dword ptr [0x6fd50c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7329036) /* 0x6fd50c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044049f  0f8471000000           -je 0x440516
    if (cpu.flags.zf)
    {
        goto L_0x00440516;
    }
    // 004404a5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004404a7  66891d32575500         -mov word ptr [0x555732], bx
    app->getMemory<x86::reg16>(x86::reg32(5592882) /* 0x555732 */) = cpu.bx;
    // 004404ae  833db8d36f0003         +cmp dword ptr [0x6fd3b8], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004404b5  750e                   -jne 0x4404c5
    if (!cpu.flags.zf)
    {
        goto L_0x004404c5;
    }
    // 004404b7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004404b9  8935d8565500           -mov dword ptr [0x5556d8], esi
    app->getMemory<x86::reg32>(x86::reg32(5592792) /* 0x5556d8 */) = cpu.esi;
    // 004404bf  8935b8d36f00           -mov dword ptr [0x6fd3b8], esi
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.esi;
L_0x004404c5:
    // 004404c5  833de4227a0002         +cmp dword ptr [0x7a22e4], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004404cc  7548                   -jne 0x440516
    if (!cpu.flags.zf)
    {
        goto L_0x00440516;
    }
    // 004404ce  ba0e000000             -mov edx, 0xe
    cpu.edx = 14 /*0xe*/;
    // 004404d3  b830575500             -mov eax, 0x555730
    cpu.eax = 5592880 /*0x555730*/;
    // 004404d8  8b1db8d36f00           -mov ebx, dword ptr [0x6fd3b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 004404de  e829020a00             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004404e3  8b15b8d36f00           -mov edx, dword ptr [0x6fd3b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 004404e9  83fa01                 +cmp edx, 1
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
    // 004404ec  7504                   -jne 0x4404f2
    if (!cpu.flags.zf)
    {
        goto L_0x004404f2;
    }
    // 004404ee  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004404f0  eb02                   -jmp 0x4404f4
    goto L_0x004404f4;
L_0x004404f2:
    // 004404f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004404f4:
    // 004404f4  8b35b8d36f00           -mov esi, dword ptr [0x6fd3b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 004404fa  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004404fc  83fe02                 +cmp esi, 2
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
    // 004404ff  7c07                   -jl 0x440508
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00440508;
    }
    // 00440501  a170d46f00             -mov eax, dword ptr [0x6fd470]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328880) /* 0x6fd470 */);
    // 00440506  eb02                   -jmp 0x44050a
    goto L_0x0044050a;
L_0x00440508:
    // 00440508  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044050a:
    // 0044050a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044050c  66c7045d305755000100   -mov word ptr [ebx*2 + 0x555730], 1
    app->getMemory<x86::reg16>(x86::reg32(5592880) /* 0x555730 */ + cpu.ebx * 2) = 1 /*0x1*/;
L_0x00440516:
    // 00440516  e875feffff             -call 0x440390
    cpu.esp -= 4;
    sub_440390(app, cpu);
    if (cpu.terminate) return;
    // 0044051b  a1d8565500             -mov eax, dword ptr [0x5556d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592792) /* 0x5556d8 */);
    // 00440520  a3dc565500             -mov dword ptr [0x5556dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5592796) /* 0x5556dc */) = cpu.eax;
    // 00440525  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440527  bac4785300             -mov edx, 0x5378c4
    cpu.edx = 5470404 /*0x5378c4*/;
    // 0044052c  e82ffcffff             -call 0x440160
    cpu.esp -= 4;
    sub_440160(app, cpu);
    if (cpu.terminate) return;
    // 00440531  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440533  e808250000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440538  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044053a  7407                   -je 0x440543
    if (cpu.flags.zf)
    {
        goto L_0x00440543;
    }
    // 0044053c  c74064f0ce4500         -mov dword ptr [eax + 0x64], 0x45cef0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4574960 /*0x45cef0*/;
L_0x00440543:
    // 00440543  bad4785300             -mov edx, 0x5378d4
    cpu.edx = 5470420 /*0x5378d4*/;
    // 00440548  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044054a  e8f1240000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044054f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440551  7407                   -je 0x44055a
    if (cpu.flags.zf)
    {
        goto L_0x0044055a;
    }
    // 00440553  c7403cfcd26f00         -mov dword ptr [eax + 0x3c], 0x6fd2fc
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = 7328508 /*0x6fd2fc*/;
L_0x0044055a:
    // 0044055a  bae8785300             -mov edx, 0x5378e8
    cpu.edx = 5470440 /*0x5378e8*/;
    // 0044055f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440561  e8da240000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440566  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440568  7407                   -je 0x440571
    if (cpu.flags.zf)
    {
        goto L_0x00440571;
    }
    // 0044056a  c74064d0004400         -mov dword ptr [eax + 0x64], 0x4400d0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4456656 /*0x4400d0*/;
L_0x00440571:
    // 00440571  baf0785300             -mov edx, 0x5378f0
    cpu.edx = 5470448 /*0x5378f0*/;
    // 00440576  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440578  e8c3240000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044057d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044057f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440581  7424                   -je 0x4405a7
    if (cpu.flags.zf)
    {
        goto L_0x004405a7;
    }
    // 00440583  b8b1050000             -mov eax, 0x5b1
    cpu.eax = 1457 /*0x5b1*/;
    // 00440588  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 0044058d  e8be120900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00440592  e8891a0100             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00440597  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440599  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0044059c  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044059e  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004405a0  83c076                 -add eax, 0x76
    (cpu.eax) += x86::reg32(x86::sreg32(118 /*0x76*/));
    // 004405a3  66894106               -mov word ptr [ecx + 6], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.ax;
L_0x004405a7:
    // 004405a7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004405a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004405aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004405ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004405ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004405ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004405ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4405b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004405b0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004405b1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004405b3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004405b5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004405b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4405c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004405c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004405c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004405c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004405c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004405c4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004405c6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004405c8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004405ca  668915cc565500         -mov word ptr [0x5556cc], dx
    app->getMemory<x86::reg16>(x86::reg32(5592780) /* 0x5556cc */) = cpu.dx;
    // 004405d1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004405d3  891508d56f00           -mov dword ptr [0x6fd508], edx
    app->getMemory<x86::reg32>(x86::reg32(7329032) /* 0x6fd508 */) = cpu.edx;
    // 004405d9  8915b8d36f00           -mov dword ptr [0x6fd3b8], edx
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.edx;
    // 004405df  baf8785300             -mov edx, 0x5378f8
    cpu.edx = 5470456 /*0x5378f8*/;
    // 004405e4  e857240000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004405e9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004405eb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004405ed  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004405f2  e869dd0500             -call 0x49e360
    cpu.esp -= 4;
    sub_49e360(app, cpu);
    if (cpu.terminate) return;
    // 004405f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004405f9  7508                   -jne 0x440603
    if (!cpu.flags.zf)
    {
        goto L_0x00440603;
    }
    // 004405fb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004405fd  7404                   -je 0x440603
    if (cpu.flags.zf)
    {
        goto L_0x00440603;
    }
    // 004405ff  804a0401               -or byte ptr [edx + 4], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00440603:
    // 00440603  66833dce56550000       +cmp word ptr [0x5556ce], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5592782) /* 0x5556ce */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044060b  740a                   -je 0x440617
    if (cpu.flags.zf)
    {
        goto L_0x00440617;
    }
    // 0044060d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044060f  7406                   -je 0x440617
    if (cpu.flags.zf)
    {
        goto L_0x00440617;
    }
    // 00440611  66814b040110           -or word ptr [ebx + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x00440617:
    // 00440617  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044061c  e83fdd0500             -call 0x49e360
    cpu.esp -= 4;
    sub_49e360(app, cpu);
    if (cpu.terminate) return;
    // 00440621  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440623  7514                   -jne 0x440639
    if (!cpu.flags.zf)
    {
        goto L_0x00440639;
    }
    // 00440625  ba00795300             -mov edx, 0x537900
    cpu.edx = 5470464 /*0x537900*/;
    // 0044062a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044062c  e80f240000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440631  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440633  7404                   -je 0x440639
    if (cpu.flags.zf)
    {
        goto L_0x00440639;
    }
    // 00440635  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00440639:
    // 00440639  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0044063e  e81ddd0500             -call 0x49e360
    cpu.esp -= 4;
    sub_49e360(app, cpu);
    if (cpu.terminate) return;
    // 00440643  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440645  7514                   -jne 0x44065b
    if (!cpu.flags.zf)
    {
        goto L_0x0044065b;
    }
    // 00440647  ba04795300             -mov edx, 0x537904
    cpu.edx = 5470468 /*0x537904*/;
    // 0044064c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044064e  e8ed230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440653  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440655  7404                   -je 0x44065b
    if (cpu.flags.zf)
    {
        goto L_0x0044065b;
    }
    // 00440657  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044065b:
    // 0044065b  b8f03d5f00             -mov eax, 0x5f3df0
    cpu.eax = 6241776 /*0x5f3df0*/;
    // 00440660  e86b3b0800             -call 0x4c41d0
    cpu.esp -= 4;
    sub_4c41d0(app, cpu);
    if (cpu.terminate) return;
    // 00440665  833df03d5f0000         +cmp dword ptr [0x5f3df0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6241776) /* 0x5f3df0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044066c  7514                   -jne 0x440682
    if (!cpu.flags.zf)
    {
        goto L_0x00440682;
    }
    // 0044066e  ba08795300             -mov edx, 0x537908
    cpu.edx = 5470472 /*0x537908*/;
    // 00440673  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440675  e8c6230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044067a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044067c  7404                   -je 0x440682
    if (cpu.flags.zf)
    {
        goto L_0x00440682;
    }
    // 0044067e  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00440682:
    // 00440682  833d54bb6f0000         +cmp dword ptr [0x6fbb54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7322452) /* 0x6fbb54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440689  743c                   -je 0x4406c7
    if (cpu.flags.zf)
    {
        goto L_0x004406c7;
    }
    // 0044068b  baf8785300             -mov edx, 0x5378f8
    cpu.edx = 5470456 /*0x5378f8*/;
    // 00440690  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440692  e8a9230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440697  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440699  7404                   -je 0x44069f
    if (cpu.flags.zf)
    {
        goto L_0x0044069f;
    }
    // 0044069b  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044069f:
    // 0044069f  ba08795300             -mov edx, 0x537908
    cpu.edx = 5470472 /*0x537908*/;
    // 004406a4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004406a6  e895230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004406ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004406ad  7404                   -je 0x4406b3
    if (cpu.flags.zf)
    {
        goto L_0x004406b3;
    }
    // 004406af  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004406b3:
    // 004406b3  ba10795300             -mov edx, 0x537910
    cpu.edx = 5470480 /*0x537910*/;
    // 004406b8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004406ba  e881230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004406bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004406c1  7404                   -je 0x4406c7
    if (cpu.flags.zf)
    {
        goto L_0x004406c7;
    }
    // 004406c3  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004406c7:
    // 004406c7  baf8785300             -mov edx, 0x5378f8
    cpu.edx = 5470456 /*0x5378f8*/;
    // 004406cc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004406ce  e86d230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004406d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004406d5  7407                   -je 0x4406de
    if (cpu.flags.zf)
    {
        goto L_0x004406de;
    }
    // 004406d7  c7406410fd4300         -mov dword ptr [eax + 0x64], 0x43fd10
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4455696 /*0x43fd10*/;
L_0x004406de:
    // 004406de  ba04795300             -mov edx, 0x537904
    cpu.edx = 5470468 /*0x537904*/;
    // 004406e3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004406e5  e856230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004406ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004406ec  7407                   -je 0x4406f5
    if (cpu.flags.zf)
    {
        goto L_0x004406f5;
    }
    // 004406ee  c7406450fe4300         -mov dword ptr [eax + 0x64], 0x43fe50
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4456016 /*0x43fe50*/;
L_0x004406f5:
    // 004406f5  ba08795300             -mov edx, 0x537908
    cpu.edx = 5470472 /*0x537908*/;
    // 004406fa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004406fc  e83f230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440701  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440703  7407                   -je 0x44070c
    if (cpu.flags.zf)
    {
        goto L_0x0044070c;
    }
    // 00440705  c7406450ff4300         -mov dword ptr [eax + 0x64], 0x43ff50
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4456272 /*0x43ff50*/;
L_0x0044070c:
    // 0044070c  ba10795300             -mov edx, 0x537910
    cpu.edx = 5470480 /*0x537910*/;
    // 00440711  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440713  e828230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440718  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044071a  7407                   -je 0x440723
    if (cpu.flags.zf)
    {
        goto L_0x00440723;
    }
    // 0044071c  c74064e0fe4300         -mov dword ptr [eax + 0x64], 0x43fee0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4456160 /*0x43fee0*/;
L_0x00440723:
    // 00440723  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00440725  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440726  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440727  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440728  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440729  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_440730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440730  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440731  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440732  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440733  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440734  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440735  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440737  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0044073a  8b4016                 -mov eax, dword ptr [eax + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0044073d  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00440740  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00440743  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00440745  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0044074c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044074e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00440751  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00440753  b9e04e6000             -mov ecx, 0x604ee0
    cpu.ecx = 6311648 /*0x604ee0*/;
    // 00440758  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044075b  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044075d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044075f  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00440761  8915b0d36f00           -mov dword ptr [0x6fd3b0], edx
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = cpu.edx;
    // 00440767  83fb05                 +cmp ebx, 5
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044076a  0f8591000000           -jne 0x440801
    if (!cpu.flags.zf)
    {
        goto L_0x00440801;
    }
    // 00440770  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00440773  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00440775  0f8486000000           -je 0x440801
    if (cpu.flags.zf)
    {
        goto L_0x00440801;
    }
    // 0044077b  ba08795300             -mov edx, 0x537908
    cpu.edx = 5470472 /*0x537908*/;
    // 00440780  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00440782  e839220000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 00440787  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440789  740a                   -je 0x440795
    if (cpu.flags.zf)
    {
        goto L_0x00440795;
    }
    // 0044078b  c705b0d36f0002000000   -mov dword ptr [0x6fd3b0], 2
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = 2 /*0x2*/;
L_0x00440795:
    // 00440795  ba10795300             -mov edx, 0x537910
    cpu.edx = 5470480 /*0x537910*/;
    // 0044079a  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0044079d  e81e220000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 004407a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004407a4  740a                   -je 0x4407b0
    if (cpu.flags.zf)
    {
        goto L_0x004407b0;
    }
    // 004407a6  c705b0d36f0003000000   -mov dword ptr [0x6fd3b0], 3
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = 3 /*0x3*/;
L_0x004407b0:
    // 004407b0  ba00795300             -mov edx, 0x537900
    cpu.edx = 5470464 /*0x537900*/;
    // 004407b5  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004407b8  e803220000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 004407bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004407bf  740a                   -je 0x4407cb
    if (cpu.flags.zf)
    {
        goto L_0x004407cb;
    }
    // 004407c1  c705b0d36f0004000000   -mov dword ptr [0x6fd3b0], 4
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = 4 /*0x4*/;
L_0x004407cb:
    // 004407cb  ba04795300             -mov edx, 0x537904
    cpu.edx = 5470468 /*0x537904*/;
    // 004407d0  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004407d3  e8e8210000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 004407d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004407da  740a                   -je 0x4407e6
    if (cpu.flags.zf)
    {
        goto L_0x004407e6;
    }
    // 004407dc  c705b0d36f0004000000   -mov dword ptr [0x6fd3b0], 4
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = 4 /*0x4*/;
L_0x004407e6:
    // 004407e6  baf8785300             -mov edx, 0x5378f8
    cpu.edx = 5470456 /*0x5378f8*/;
    // 004407eb  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004407ee  e8cd210000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 004407f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004407f5  740a                   -je 0x440801
    if (cpu.flags.zf)
    {
        goto L_0x00440801;
    }
    // 004407f7  c705b0d36f0004000000   -mov dword ptr [0x6fd3b0], 4
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = 4 /*0x4*/;
L_0x00440801:
    // 00440801  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00440803  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440804  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440805  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440806  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440807  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440808  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_440810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440810  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440811  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440812  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440813  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440814  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440815  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440816  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440818  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044081a  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 0044081f  8b1dec3f5f00           -mov ebx, dword ptr [0x5f3fec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6242284) /* 0x5f3fec */);
    // 00440825  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440827  39d8                   +cmp eax, ebx
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
    // 00440829  7e26                   -jle 0x440851
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00440851;
    }
    // 0044082b  e880300000             -call 0x4438b0
    cpu.esp -= 4;
    sub_4438b0(app, cpu);
    if (cpu.terminate) return;
    // 00440830  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00440832  751d                   -jne 0x440851
    if (!cpu.flags.zf)
    {
        goto L_0x00440851;
    }
    // 00440834  81c200050000           -add edx, 0x500
    (cpu.edx) += x86::reg32(x86::sreg32(1280 /*0x500*/));
    // 0044083a  8b35c8565500           -mov esi, dword ptr [0x5556c8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5592776) /* 0x5556c8 */);
    // 00440840  8915ec3f5f00           -mov dword ptr [0x5f3fec], edx
    app->getMemory<x86::reg32>(x86::reg32(6242284) /* 0x5f3fec */) = cpu.edx;
    // 00440846  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00440848  7407                   -je 0x440851
    if (cpu.flags.zf)
    {
        goto L_0x00440851;
    }
    // 0044084a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044084c  e8cfe9ffff             -call 0x43f220
    cpu.esp -= 4;
    sub_43f220(app, cpu);
    if (cpu.terminate) return;
L_0x00440851:
    // 00440851  ba18795300             -mov edx, 0x537918
    cpu.edx = 5470488 /*0x537918*/;
    // 00440856  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440858  e8e3210000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044085d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044085f  741a                   -je 0x44087b
    if (cpu.flags.zf)
    {
        goto L_0x0044087b;
    }
    // 00440861  8b3df03f5f00           -mov edi, dword ptr [0x5f3ff0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6242288) /* 0x5f3ff0 */);
    // 00440867  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00440869  740c                   -je 0x440877
    if (cpu.flags.zf)
    {
        goto L_0x00440877;
    }
    // 0044086b  66833f00               +cmp word ptr [edi], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edi);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044086f  7406                   -je 0x440877
    if (cpu.flags.zf)
    {
        goto L_0x00440877;
    }
    // 00440871  806004fe               +and byte ptr [eax + 4], 0xfe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 00440875  eb04                   -jmp 0x44087b
    goto L_0x0044087b;
L_0x00440877:
    // 00440877  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044087b:
    // 0044087b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044087d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044087e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044087f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440880  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440881  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440882  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440883  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_440890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440890  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440891  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440892  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440893  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440894  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440895  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440897  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00440899  ba40785300             -mov edx, 0x537840
    cpu.edx = 5470272 /*0x537840*/;
    // 0044089e  e89d210000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004408a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004408a5  7411                   -je 0x4408b8
    if (cpu.flags.zf)
    {
        goto L_0x004408b8;
    }
    // 004408a7  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 004408ac  ba9dbb6f00             -mov edx, 0x6fbb9d
    cpu.edx = 7322525 /*0x6fbb9d*/;
    // 004408b1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004408b3  e8987b0100             -call 0x458450
    cpu.esp -= 4;
    sub_458450(app, cpu);
    if (cpu.terminate) return;
L_0x004408b8:
    // 004408b8  ba24795300             -mov edx, 0x537924
    cpu.edx = 5470500 /*0x537924*/;
    // 004408bd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004408bf  e87c210000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004408c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004408c6  7407                   -je 0x4408cf
    if (cpu.flags.zf)
    {
        goto L_0x004408cf;
    }
    // 004408c8  c7406440004400         -mov dword ptr [eax + 0x64], 0x440040
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4456512 /*0x440040*/;
L_0x004408cf:
    // 004408cf  ba18795300             -mov edx, 0x537918
    cpu.edx = 5470488 /*0x537918*/;
    // 004408d4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004408d6  e865210000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004408db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004408dd  7421                   -je 0x440900
    if (cpu.flags.zf)
    {
        goto L_0x00440900;
    }
    // 004408df  8b15f03f5f00           -mov edx, dword ptr [0x5f3ff0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6242288) /* 0x5f3ff0 */);
    // 004408e5  c74064d0fd4300         -mov dword ptr [eax + 0x64], 0x43fdd0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4455888 /*0x43fdd0*/;
    // 004408ec  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004408ee  740c                   -je 0x4408fc
    if (cpu.flags.zf)
    {
        goto L_0x004408fc;
    }
    // 004408f0  66833a00               +cmp word ptr [edx], 0
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
    // 004408f4  7406                   -je 0x4408fc
    if (cpu.flags.zf)
    {
        goto L_0x004408fc;
    }
    // 004408f6  806004fe               +and byte ptr [eax + 4], 0xfe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 004408fa  eb04                   -jmp 0x440900
    goto L_0x00440900;
L_0x004408fc:
    // 004408fc  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00440900:
    // 00440900  ba30795300             -mov edx, 0x537930
    cpu.edx = 5470512 /*0x537930*/;
    // 00440905  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00440907  e834210000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044090c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044090e  740f                   -je 0x44091f
    if (cpu.flags.zf)
    {
        goto L_0x0044091f;
    }
    // 00440910  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00440912  c74064b0004400         -mov dword ptr [eax + 0x64], 0x4400b0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4456624 /*0x4400b0*/;
    // 00440919  890dec3f5f00           -mov dword ptr [0x5f3fec], ecx
    app->getMemory<x86::reg32>(x86::reg32(6242284) /* 0x5f3fec */) = cpu.ecx;
L_0x0044091f:
    // 0044091f  bae8785300             -mov edx, 0x5378e8
    cpu.edx = 5470440 /*0x5378e8*/;
    // 00440924  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00440926  e815210000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044092b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044092d  7407                   -je 0x440936
    if (cpu.flags.zf)
    {
        goto L_0x00440936;
    }
    // 0044092f  c74064d0004400         -mov dword ptr [eax + 0x64], 0x4400d0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4456656 /*0x4400d0*/;
L_0x00440936:
    // 00440936  833d54bb6f0000         +cmp dword ptr [0x6fbb54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7322452) /* 0x6fbb54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044093d  7414                   -je 0x440953
    if (cpu.flags.zf)
    {
        goto L_0x00440953;
    }
    // 0044093f  ba24795300             -mov edx, 0x537924
    cpu.edx = 5470500 /*0x537924*/;
    // 00440944  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00440946  e8f5200000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044094b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044094d  7404                   -je 0x440953
    if (cpu.flags.zf)
    {
        goto L_0x00440953;
    }
    // 0044094f  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00440953:
    // 00440953  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00440955  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440956  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440957  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440958  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440959  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044095a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_440960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440960  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440961  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440963  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00440965  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440966  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_440970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440970  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440971  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440972  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440973  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440974  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440975  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440976  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440978  ba51020000             -mov edx, 0x251
    cpu.edx = 593 /*0x251*/;
    // 0044097d  b987000000             -mov ecx, 0x87
    cpu.ecx = 135 /*0x87*/;
    // 00440982  8915cc3f5f00           -mov dword ptr [0x5f3fcc], edx
    app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */) = cpu.edx;
    // 00440988  890dc83f5f00           -mov dword ptr [0x5f3fc8], ecx
    app->getMemory<x86::reg32>(x86::reg32(6242248) /* 0x5f3fc8 */) = cpu.ecx;
    // 0044098e  e86da40000             -call 0x44ae00
    cpu.esp -= 4;
    sub_44ae00(app, cpu);
    if (cpu.terminate) return;
    // 00440993  8b1d34925500           -mov ebx, dword ptr [0x559234]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00440999  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044099b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044099d  7428                   -je 0x4409c7
    if (cpu.flags.zf)
    {
        goto L_0x004409c7;
    }
    // 0044099f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004409a1  7455                   -je 0x4409f8
    if (cpu.flags.zf)
    {
        goto L_0x004409f8;
    }
    // 004409a3  ba3c795300             -mov edx, 0x53793c
    cpu.edx = 5470524 /*0x53793c*/;
    // 004409a8  e863d90a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004409ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004409af  750c                   -jne 0x4409bd
    if (!cpu.flags.zf)
    {
        goto L_0x004409bd;
    }
    // 004409b1  c7054857550001000000   -mov dword ptr [0x555748], 1
    app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */) = 1 /*0x1*/;
    // 004409bb  eb3b                   -jmp 0x4409f8
    goto L_0x004409f8;
L_0x004409bd:
    // 004409bd  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004409bf  893d48575500           -mov dword ptr [0x555748], edi
    app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */) = cpu.edi;
    // 004409c5  eb31                   -jmp 0x4409f8
    goto L_0x004409f8;
L_0x004409c7:
    // 004409c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004409c9  742d                   -je 0x4409f8
    if (cpu.flags.zf)
    {
        goto L_0x004409f8;
    }
    // 004409cb  ba44795300             -mov edx, 0x537944
    cpu.edx = 5470532 /*0x537944*/;
    // 004409d0  e83bd90a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004409d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004409d7  750a                   -jne 0x4409e3
    if (!cpu.flags.zf)
    {
        goto L_0x004409e3;
    }
    // 004409d9  c7054857550001000000   -mov dword ptr [0x555748], 1
    app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */) = 1 /*0x1*/;
L_0x004409e3:
    // 004409e3  ba50795300             -mov edx, 0x537950
    cpu.edx = 5470544 /*0x537950*/;
    // 004409e8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004409ea  e821d90a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004409ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004409f1  7505                   -jne 0x4409f8
    if (!cpu.flags.zf)
    {
        goto L_0x004409f8;
    }
    // 004409f3  a348575500             -mov dword ptr [0x555748], eax
    app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */) = cpu.eax;
L_0x004409f8:
    // 004409f8  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004409ff  0f85a9000000           -jne 0x440aae
    if (!cpu.flags.zf)
    {
        goto L_0x00440aae;
    }
    // 00440a05  b85c795300             -mov eax, 0x53795c
    cpu.eax = 5470556 /*0x53795c*/;
    // 00440a0a  e8a1530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440a0f  66a3cc565500           -mov word ptr [0x5556cc], ax
    app->getMemory<x86::reg16>(x86::reg32(5592780) /* 0x5556cc */) = cpu.ax;
    // 00440a15  b864795300             -mov eax, 0x537964
    cpu.eax = 5470564 /*0x537964*/;
    // 00440a1a  e891530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440a1f  66a302405f00           -mov word ptr [0x5f4002], ax
    app->getMemory<x86::reg16>(x86::reg32(6242306) /* 0x5f4002 */) = cpu.ax;
    // 00440a25  b86c795300             -mov eax, 0x53796c
    cpu.eax = 5470572 /*0x53796c*/;
    // 00440a2a  e881530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440a2f  66a3fe3f5f00           -mov word ptr [0x5f3ffe], ax
    app->getMemory<x86::reg16>(x86::reg32(6242302) /* 0x5f3ffe */) = cpu.ax;
    // 00440a35  b874795300             -mov eax, 0x537974
    cpu.eax = 5470580 /*0x537974*/;
    // 00440a3a  e871530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440a3f  66a3f83f5f00           -mov word ptr [0x5f3ff8], ax
    app->getMemory<x86::reg16>(x86::reg32(6242296) /* 0x5f3ff8 */) = cpu.ax;
    // 00440a45  b87c795300             -mov eax, 0x53797c
    cpu.eax = 5470588 /*0x53797c*/;
    // 00440a4a  e861530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440a4f  66a3f43f5f00           -mov word ptr [0x5f3ff4], ax
    app->getMemory<x86::reg16>(x86::reg32(6242292) /* 0x5f3ff4 */) = cpu.ax;
    // 00440a55  b884795300             -mov eax, 0x537984
    cpu.eax = 5470596 /*0x537984*/;
    // 00440a5a  e851530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440a5f  66a3fc3f5f00           -mov word ptr [0x5f3ffc], ax
    app->getMemory<x86::reg16>(x86::reg32(6242300) /* 0x5f3ffc */) = cpu.ax;
    // 00440a65  b88c795300             -mov eax, 0x53798c
    cpu.eax = 5470604 /*0x53798c*/;
    // 00440a6a  e841530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440a6f  66a300405f00           -mov word ptr [0x5f4000], ax
    app->getMemory<x86::reg16>(x86::reg32(6242304) /* 0x5f4000 */) = cpu.ax;
    // 00440a75  b894795300             -mov eax, 0x537994
    cpu.eax = 5470612 /*0x537994*/;
    // 00440a7a  e831530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440a7f  66a3fa3f5f00           -mov word ptr [0x5f3ffa], ax
    app->getMemory<x86::reg16>(x86::reg32(6242298) /* 0x5f3ffa */) = cpu.ax;
    // 00440a85  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00440a8c  7520                   -jne 0x440aae
    if (!cpu.flags.zf)
    {
        goto L_0x00440aae;
    }
    // 00440a8e  b89c795300             -mov eax, 0x53799c
    cpu.eax = 5470620 /*0x53799c*/;
    // 00440a93  e818530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440a98  66a304405f00           -mov word ptr [0x5f4004], ax
    app->getMemory<x86::reg16>(x86::reg32(6242308) /* 0x5f4004 */) = cpu.ax;
    // 00440a9e  b8a4795300             -mov eax, 0x5379a4
    cpu.eax = 5470628 /*0x5379a4*/;
    // 00440aa3  e808530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440aa8  66a3f63f5f00           -mov word ptr [0x5f3ff6], ax
    app->getMemory<x86::reg16>(x86::reg32(6242294) /* 0x5f3ff6 */) = cpu.ax;
L_0x00440aae:
    // 00440aae  8b1ddc3f5f00           -mov ebx, dword ptr [0x5f3fdc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */);
    // 00440ab4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00440ab6  7407                   -je 0x440abf
    if (cpu.flags.zf)
    {
        goto L_0x00440abf;
    }
    // 00440ab8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00440aba  e8d10d0a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x00440abf:
    // 00440abf  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 00440ac4  b830785300             -mov eax, 0x537830
    cpu.eax = 5470256 /*0x537830*/;
    // 00440ac9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00440acb  e8500b0a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 00440ad0  a3dc3f5f00             -mov dword ptr [0x5f3fdc], eax
    app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */) = cpu.eax;
    // 00440ad5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440ad7  740c                   -je 0x440ae5
    if (cpu.flags.zf)
    {
        goto L_0x00440ae5;
    }
    // 00440ad9  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 00440ade  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00440ae0  e85bfb0900             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x00440ae5:
    // 00440ae5  8b35d03f5f00           -mov esi, dword ptr [0x5f3fd0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6242256) /* 0x5f3fd0 */);
    // 00440aeb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00440aed  7407                   -je 0x440af6
    if (cpu.flags.zf)
    {
        goto L_0x00440af6;
    }
    // 00440aef  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00440af1  e89a0d0a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x00440af6:
    // 00440af6  ba84030000             -mov edx, 0x384
    cpu.edx = 900 /*0x384*/;
    // 00440afb  b830785300             -mov eax, 0x537830
    cpu.eax = 5470256 /*0x537830*/;
    // 00440b00  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00440b02  e8190b0a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 00440b07  bb84030000             -mov ebx, 0x384
    cpu.ebx = 900 /*0x384*/;
    // 00440b0c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00440b0e  a3d03f5f00             -mov dword ptr [0x5f3fd0], eax
    app->getMemory<x86::reg32>(x86::reg32(6242256) /* 0x5f3fd0 */) = cpu.eax;
    // 00440b13  e828fb0900             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00440b18  8b3d34925500           -mov edi, dword ptr [0x559234]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00440b1e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00440b20  7506                   -jne 0x440b28
    if (!cpu.flags.zf)
    {
        goto L_0x00440b28;
    }
    // 00440b22  893d08d56f00           -mov dword ptr [0x6fd508], edi
    app->getMemory<x86::reg32>(x86::reg32(7329032) /* 0x6fd508 */) = cpu.edi;
L_0x00440b28:
    // 00440b28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b29  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b2a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b2b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b2c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b2d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_440b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440b30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440b31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440b32  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440b33  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440b35  8b0df83f5f00           -mov ecx, dword ptr [0x5f3ff8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6242296) /* 0x5f3ff8 */);
    // 00440b3b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00440b3d  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00440b40  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440b42  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440b44  e8476e0900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00440b49  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b4b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_440b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440b50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440b51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440b52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440b53  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440b55  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00440b58  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00440b5b  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00440b5e  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00440b60  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00440b62  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00440b67  8d1400                 -lea edx, [eax + eax]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00440b6a  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 00440b6f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00440b71  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00440b74  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00440b76  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00440b79  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00440b7e  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00440b80  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 00440b83  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00440b85  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00440b87  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00440b8a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00440b8c  81fa00010000           +cmp edx, 0x100
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
    // 00440b92  7c09                   -jl 0x440b9d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00440b9d;
    }
    // 00440b94  b8ff010000             -mov eax, 0x1ff
    cpu.eax = 511 /*0x1ff*/;
    // 00440b99  29d0                   +sub eax, edx
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
    // 00440b9b  eb02                   -jmp 0x440b9f
    goto L_0x00440b9f;
L_0x00440b9d:
    // 00440b9d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00440b9f:
    // 00440b9f  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 00440ba2  05ffffff00             -add eax, 0xffffff
    (cpu.eax) += x86::reg32(x86::sreg32(16777215 /*0xffffff*/));
    // 00440ba7  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00440baa  8d5efb                 -lea ebx, [esi - 5]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(-5) /* -0x5 */);
    // 00440bad  8d57fa                 -lea edx, [edi - 6]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-6) /* -0x6 */);
    // 00440bb0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00440bb2  743f                   -je 0x440bf3
    if (cpu.flags.zf)
    {
        goto L_0x00440bf3;
    }
    // 00440bb4  66833d04405f0000       +cmp word ptr [0x5f4004], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(6242308) /* 0x5f4004 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440bbc  7416                   -je 0x440bd4
    if (cpu.flags.zf)
    {
        goto L_0x00440bd4;
    }
    // 00440bbe  8b0d02405f00           -mov ecx, dword ptr [0x5f4002]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6242306) /* 0x5f4002 */);
    // 00440bc4  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00440bc7  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00440bca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00440bcc  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00440bcf  e88c650900             -call 0x4d7160
    cpu.esp -= 4;
    sub_4d7160(app, cpu);
    if (cpu.terminate) return;
L_0x00440bd4:
    // 00440bd4  66833df43f5f0000       +cmp word ptr [0x5f3ff4], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(6242292) /* 0x5f3ff4 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440bdc  7450                   -je 0x440c2e
    if (cpu.flags.zf)
    {
        goto L_0x00440c2e;
    }
    // 00440bde  a1f23f5f00             -mov eax, dword ptr [0x5f3ff2]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242290) /* 0x5f3ff2 */);
    // 00440be3  8d5e01                 -lea ebx, [esi + 1]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00440be6  8d57ff                 -lea edx, [edi - 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 00440be9  c1f810                 +sar eax, 0x10
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
    // 00440bec  e89f6d0900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00440bf1  eb3b                   -jmp 0x440c2e
    goto L_0x00440c2e;
L_0x00440bf3:
    // 00440bf3  66833df63f5f0000       +cmp word ptr [0x5f3ff6], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(6242294) /* 0x5f3ff6 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440bfb  7416                   -je 0x440c13
    if (cpu.flags.zf)
    {
        goto L_0x00440c13;
    }
    // 00440bfd  8b0df43f5f00           -mov ecx, dword ptr [0x5f3ff4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6242292) /* 0x5f3ff4 */);
    // 00440c03  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00440c06  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00440c09  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00440c0b  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00440c0e  e84d650900             -call 0x4d7160
    cpu.esp -= 4;
    sub_4d7160(app, cpu);
    if (cpu.terminate) return;
L_0x00440c13:
    // 00440c13  66833df83f5f0000       +cmp word ptr [0x5f3ff8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(6242296) /* 0x5f3ff8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440c1b  7411                   -je 0x440c2e
    if (cpu.flags.zf)
    {
        goto L_0x00440c2e;
    }
    // 00440c1d  a1f63f5f00             -mov eax, dword ptr [0x5f3ff6]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242294) /* 0x5f3ff6 */);
    // 00440c22  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00440c24  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00440c26  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00440c29  e8626d0900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
L_0x00440c2e:
    // 00440c2e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00440c30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440c31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440c32  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440c33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_440c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440c40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440c41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440c42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440c43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440c44  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440c45  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440c47  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00440c4a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00440c4c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00440c4e  8b154c575500           -mov edx, dword ptr [0x55574c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592908) /* 0x55574c */);
    // 00440c54  83c20b                 -add edx, 0xb
    (cpu.edx) += x86::reg32(x86::sreg32(11 /*0xb*/));
    // 00440c57  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 00440c5c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00440c5e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00440c61  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00440c63  89154c575500           -mov dword ptr [0x55574c], edx
    app->getMemory<x86::reg32>(x86::reg32(5592908) /* 0x55574c */) = cpu.edx;
    // 00440c69  81fa00010000           +cmp edx, 0x100
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
    // 00440c6f  7c09                   -jl 0x440c7a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00440c7a;
    }
    // 00440c71  b8ff010000             -mov eax, 0x1ff
    cpu.eax = 511 /*0x1ff*/;
    // 00440c76  29d0                   +sub eax, edx
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
    // 00440c78  eb02                   -jmp 0x440c7c
    goto L_0x00440c7c;
L_0x00440c7a:
    // 00440c7a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00440c7c:
    // 00440c7c  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 00440c7f  05ffffff00             -add eax, 0xffffff
    (cpu.eax) += x86::reg32(x86::sreg32(16777215 /*0xffffff*/));
    // 00440c84  8b0d08d56f00           -mov ecx, dword ptr [0x6fd508]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7329032) /* 0x6fd508 */);
    // 00440c8a  8d5ffb                 -lea ebx, [edi - 5]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(-5) /* -0x5 */);
    // 00440c8d  8d56fa                 -lea edx, [esi - 6]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(-6) /* -0x6 */);
    // 00440c90  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00440c92  743f                   -je 0x440cd3
    if (cpu.flags.zf)
    {
        goto L_0x00440cd3;
    }
    // 00440c94  66833d04405f0000       +cmp word ptr [0x5f4004], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(6242308) /* 0x5f4004 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440c9c  7416                   -je 0x440cb4
    if (cpu.flags.zf)
    {
        goto L_0x00440cb4;
    }
    // 00440c9e  8b0d02405f00           -mov ecx, dword ptr [0x5f4002]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6242306) /* 0x5f4002 */);
    // 00440ca4  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00440ca7  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00440caa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00440cac  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00440caf  e8ac640900             -call 0x4d7160
    cpu.esp -= 4;
    sub_4d7160(app, cpu);
    if (cpu.terminate) return;
L_0x00440cb4:
    // 00440cb4  66833df43f5f0000       +cmp word ptr [0x5f3ff4], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(6242292) /* 0x5f3ff4 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440cbc  7450                   -je 0x440d0e
    if (cpu.flags.zf)
    {
        goto L_0x00440d0e;
    }
    // 00440cbe  a1f23f5f00             -mov eax, dword ptr [0x5f3ff2]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242290) /* 0x5f3ff2 */);
    // 00440cc3  8d5f01                 -lea ebx, [edi + 1]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00440cc6  8d56ff                 -lea edx, [esi - 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 00440cc9  c1f810                 +sar eax, 0x10
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
    // 00440ccc  e8bf6c0900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00440cd1  eb3b                   -jmp 0x440d0e
    goto L_0x00440d0e;
L_0x00440cd3:
    // 00440cd3  66833df63f5f0000       +cmp word ptr [0x5f3ff6], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(6242294) /* 0x5f3ff6 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440cdb  7416                   -je 0x440cf3
    if (cpu.flags.zf)
    {
        goto L_0x00440cf3;
    }
    // 00440cdd  8b0df43f5f00           -mov ecx, dword ptr [0x5f3ff4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6242292) /* 0x5f3ff4 */);
    // 00440ce3  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00440ce6  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00440ce9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00440ceb  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00440cee  e86d640900             -call 0x4d7160
    cpu.esp -= 4;
    sub_4d7160(app, cpu);
    if (cpu.terminate) return;
L_0x00440cf3:
    // 00440cf3  66833df83f5f0000       +cmp word ptr [0x5f3ff8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(6242296) /* 0x5f3ff8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440cfb  7411                   -je 0x440d0e
    if (cpu.flags.zf)
    {
        goto L_0x00440d0e;
    }
    // 00440cfd  a1f63f5f00             -mov eax, dword ptr [0x5f3ff6]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242294) /* 0x5f3ff6 */);
    // 00440d02  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00440d04  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00440d06  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00440d09  e8826c0900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
L_0x00440d0e:
    // 00440d0e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00440d10  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d11  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d12  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_440d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440d20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440d21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440d22  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440d24  833d4857550000         +cmp dword ptr [0x555748], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440d2b  742a                   -je 0x440d57
    if (cpu.flags.zf)
    {
        goto L_0x00440d57;
    }
    // 00440d2d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00440d2f  890d48575500           -mov dword ptr [0x555748], ecx
    app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */) = cpu.ecx;
L_0x00440d35:
    // 00440d35  813dcc3f5f0051020000   +cmp dword ptr [0x5f3fcc], 0x251
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(593 /*0x251*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440d3f  7d16                   -jge 0x440d57
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00440d57;
    }
    // 00440d41  e8da830900             -call 0x4d9120
    cpu.esp -= 4;
    sub_4d9120(app, cpu);
    if (cpu.terminate) return;
    // 00440d46  e865a10000             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 00440d4b  e8a0970000             -call 0x44a4f0
    cpu.esp -= 4;
    sub_44a4f0(app, cpu);
    if (cpu.terminate) return;
    // 00440d50  e8eb830900             -call 0x4d9140
    cpu.esp -= 4;
    sub_4d9140(app, cpu);
    if (cpu.terminate) return;
    // 00440d55  ebde                   -jmp 0x440d35
    goto L_0x00440d35;
L_0x00440d57:
    // 00440d57  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d59  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_440d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440d60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440d61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440d62  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440d64  8b15c43f5f00           -mov edx, dword ptr [0x5f3fc4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6242244) /* 0x5f3fc4 */);
    // 00440d6a  a1bc3f5f00             -mov eax, dword ptr [0x5f3fbc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242236) /* 0x5f3fbc */);
    // 00440d6f  83c20a                 -add edx, 0xa
    (cpu.edx) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00440d72  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00440d75  e846b20500             -call 0x49bfc0
    cpu.esp -= 4;
    sub_49bfc0(app, cpu);
    if (cpu.terminate) return;
    // 00440d7a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d7b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_440d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440d80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440d81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440d82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440d83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440d84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440d85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440d86  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440d88  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00440d8b  be40222280             -mov esi, 0x80222240
    cpu.esi = 2149720640 /*0x80222240*/;
    // 00440d90  bf400000ff             -mov edi, 0xff000040
    cpu.edi = 4278190144 /*0xff000040*/;
    // 00440d95  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00440d98  8d4dd8                 -lea ecx, [ebp - 0x28]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00440d9b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00440d9d  8d5dd4                 -lea ebx, [ebp - 0x2c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00440da0  8955d4                 -mov dword ptr [ebp - 0x2c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.edx;
    // 00440da3  8955d8                 -mov dword ptr [ebp - 0x28], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.edx;
    // 00440da6  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 00440da9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00440daa  8d55d4                 -lea edx, [ebp - 0x2c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00440dad  b8c0da7c00             -mov eax, 0x7cdac0
    cpu.eax = 8182464 /*0x7cdac0*/;
    // 00440db2  8975ec                 -mov dword ptr [ebp - 0x14], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.esi;
    // 00440db5  e866dd0700             -call 0x4beb20
    cpu.esp -= 4;
    sub_4beb20(app, cpu);
    if (cpu.terminate) return;
    // 00440dba  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00440dbd  be207080ff             -mov esi, 0xff807020
    cpu.esi = 4286607392 /*0xff807020*/;
    // 00440dc2  3d80020000             +cmp eax, 0x280
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(640 /*0x280*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440dc7  7d16                   -jge 0x440ddf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00440ddf;
    }
    // 00440dc9  b918010000             -mov ecx, 0x118
    cpu.ecx = 280 /*0x118*/;
    // 00440dce  bb40020000             -mov ebx, 0x240
    cpu.ebx = 576 /*0x240*/;
    // 00440dd3  b8a6010000             -mov eax, 0x1a6
    cpu.eax = 422 /*0x1a6*/;
    // 00440dd8  ba40000000             -mov edx, 0x40
    cpu.edx = 64 /*0x40*/;
    // 00440ddd  eb14                   -jmp 0x440df3
    goto L_0x00440df3;
L_0x00440ddf:
    // 00440ddf  b918010000             -mov ecx, 0x118
    cpu.ecx = 280 /*0x118*/;
    // 00440de4  bb01020000             -mov ebx, 0x201
    cpu.ebx = 513 /*0x201*/;
    // 00440de9  b8a6010000             -mov eax, 0x1a6
    cpu.eax = 422 /*0x1a6*/;
    // 00440dee  ba80000000             -mov edx, 0x80
    cpu.edx = 128 /*0x80*/;
L_0x00440df3:
    // 00440df3  890dc43f5f00           -mov dword ptr [0x5f3fc4], ecx
    app->getMemory<x86::reg32>(x86::reg32(6242244) /* 0x5f3fc4 */) = cpu.ecx;
    // 00440df9  891db83f5f00           -mov dword ptr [0x5f3fb8], ebx
    app->getMemory<x86::reg32>(x86::reg32(6242232) /* 0x5f3fb8 */) = cpu.ebx;
    // 00440dff  a3c03f5f00             -mov dword ptr [0x5f3fc0], eax
    app->getMemory<x86::reg32>(x86::reg32(6242240) /* 0x5f3fc0 */) = cpu.eax;
    // 00440e04  8915bc3f5f00           -mov dword ptr [0x5f3fbc], edx
    app->getMemory<x86::reg32>(x86::reg32(6242236) /* 0x5f3fbc */) = cpu.edx;
    // 00440e0a  a1bc3f5f00             -mov eax, dword ptr [0x5f3fbc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242236) /* 0x5f3fbc */);
    // 00440e0f  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00440e12  a1c43f5f00             -mov eax, dword ptr [0x5f3fc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242244) /* 0x5f3fc4 */);
    // 00440e17  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00440e1a  a1b83f5f00             -mov eax, dword ptr [0x5f3fb8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242232) /* 0x5f3fb8 */);
    // 00440e1f  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00440e22  a1c03f5f00             -mov eax, dword ptr [0x5f3fc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242240) /* 0x5f3fc0 */);
    // 00440e27  8b1548575500           -mov edx, dword ptr [0x555748]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */);
    // 00440e2d  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00440e30  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00440e32  0f84ca010000           -je 0x441002
    if (cpu.flags.zf)
    {
        goto L_0x00441002;
    }
    // 00440e38  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00440e3b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440e3c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440e3d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440e3e  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00440e41  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00440e44  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440e45  8d4802                 -lea ecx, [eax + 2]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00440e48  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00440e4b  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00440e4e  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00440e51  48                     -dec eax
    (cpu.eax)--;
    // 00440e52  e859730900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 00440e57  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00440e5a  2b45f4                 -sub eax, dword ptr [ebp - 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 00440e5d  8d48fd                 -lea ecx, [eax - 3]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-3) /* -0x3 */);
    // 00440e60  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00440e63  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00440e66  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00440e68  8d58fc                 -lea ebx, [eax - 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00440e6b  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00440e6e  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00440e71  e8cab30500             -call 0x49c240
    cpu.esp -= 4;
    sub_49c240(app, cpu);
    if (cpu.terminate) return;
    // 00440e76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440e78  0f84ca000000           -je 0x440f48
    if (cpu.flags.zf)
    {
        goto L_0x00440f48;
    }
    // 00440e7e  e82d2a0000             -call 0x4438b0
    cpu.esp -= 4;
    sub_4438b0(app, cpu);
    if (cpu.terminate) return;
    // 00440e83  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00440e85  0f85bd000000           -jne 0x440f48
    if (!cpu.flags.zf)
    {
        goto L_0x00440f48;
    }
    // 00440e8b  66833ddc227a0000       +cmp word ptr [0x7a22dc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440e93  7509                   -jne 0x440e9e
    if (!cpu.flags.zf)
    {
        goto L_0x00440e9e;
    }
    // 00440e95  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440e9c  750e                   -jne 0x440eac
    if (!cpu.flags.zf)
    {
        goto L_0x00440eac;
    }
L_0x00440e9e:
    // 00440e9e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00440ea0  a348575500             -mov dword ptr [0x555748], eax
    app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */) = cpu.eax;
    // 00440ea5  a3d0565500             -mov dword ptr [0x5556d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5592784) /* 0x5556d0 */) = cpu.eax;
    // 00440eaa  eb0a                   -jmp 0x440eb6
    goto L_0x00440eb6;
L_0x00440eac:
    // 00440eac  c705d056550001000000   -mov dword ptr [0x5556d0], 1
    app->getMemory<x86::reg32>(x86::reg32(5592784) /* 0x5556d0 */) = 1 /*0x1*/;
L_0x00440eb6:
    // 00440eb6  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00440eb9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440eba  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00440ebd  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00440ec0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440ec1  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00440ec4  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00440ec7  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00440eca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440ecb  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00440ece  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00440ed0  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00440ed3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440ed4  48                     -dec eax
    (cpu.eax)--;
    // 00440ed5  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00440ed8  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00440edb  e8d0720900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 00440ee0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440ee1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440ee2  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00440ee5  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00440ee8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440ee9  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00440eec  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00440eef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440ef0  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00440ef3  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00440ef6  e8b5720900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 00440efb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440efc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440efd  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00440f00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440f01  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00440f04  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00440f07  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440f08  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00440f0a  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00440f0d  e89e720900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 00440f12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440f13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440f14  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00440f17  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00440f1a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440f1b  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00440f1e  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00440f20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440f21  83e910                 -sub ecx, 0x10
    (cpu.ecx) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00440f24  83ea12                 -sub edx, 0x12
    (cpu.edx) -= x86::reg32(x86::sreg32(18 /*0x12*/));
    // 00440f27  e884720900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 00440f2c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440f2d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440f2e  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00440f31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440f32  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00440f35  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00440f38  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440f39  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00440f3b  83c102                 +add ecx, 2
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
    // 00440f3e  e86d720900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 00440f43  e995000000             -jmp 0x440fdd
    goto L_0x00440fdd;
L_0x00440f48:
    // 00440f48  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00440f4b  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00440f4e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440f4f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00440f51  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00440f54  891dd0565500           -mov dword ptr [0x5556d0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5592784) /* 0x5556d0 */) = cpu.ebx;
    // 00440f5a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440f5b  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00440f5e  83ee02                 -sub esi, 2
    (cpu.esi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00440f61  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00440f64  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440f65  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00440f68  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00440f6a  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00440f6d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440f6e  48                     -dec eax
    (cpu.eax)--;
    // 00440f6f  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00440f72  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00440f75  e836720900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 00440f7a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440f7b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440f7c  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00440f7f  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00440f82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440f83  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00440f86  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00440f89  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440f8a  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00440f8d  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00440f90  e81b720900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 00440f95  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440f96  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440f97  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00440f9a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440f9b  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00440f9e  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00440fa1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440fa2  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00440fa4  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00440fa7  e804720900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 00440fac  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440fad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440fae  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00440fb1  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00440fb4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440fb5  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00440fb8  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00440fba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440fbb  83e910                 -sub ecx, 0x10
    (cpu.ecx) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00440fbe  83ea12                 -sub edx, 0x12
    (cpu.edx) -= x86::reg32(x86::sreg32(18 /*0x12*/));
    // 00440fc1  e8ea710900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 00440fc6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440fc7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440fc8  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00440fcb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440fcc  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00440fcf  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00440fd2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440fd3  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00440fd5  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00440fd8  e8d3710900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
L_0x00440fdd:
    // 00440fdd  e81e040900             -call 0x4d1400
    cpu.esp -= 4;
    sub_4d1400(app, cpu);
    if (cpu.terminate) return;
    // 00440fe2  689a99193f             -push 0x3f19999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058642330 /*0x3f19999a*/;
    cpu.esp -= 4;
    // 00440fe7  e844050100             -call 0x451530
    cpu.esp -= 4;
    sub_451530(app, cpu);
    if (cpu.terminate) return;
    // 00440fec  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00440fef  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00440ff2  83c203                 +add edx, 3
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00440ff5  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00440ff6  e855090000             -call 0x441950
    cpu.esp -= 4;
    sub_441950(app, cpu);
    if (cpu.terminate) return;
    // 00440ffb  e810040900             -call 0x4d1410
    cpu.esp -= 4;
    sub_4d1410(app, cpu);
    if (cpu.terminate) return;
    // 00441000  eb06                   -jmp 0x441008
    goto L_0x00441008;
L_0x00441002:
    // 00441002  8915d0565500           -mov dword ptr [0x5556d0], edx
    app->getMemory<x86::reg32>(x86::reg32(5592784) /* 0x5556d0 */) = cpu.edx;
L_0x00441008:
    // 00441008  66833ddc227a0000       +cmp word ptr [0x7a22dc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00441010  7509                   -jne 0x44101b
    if (!cpu.flags.zf)
    {
        goto L_0x0044101b;
    }
    // 00441012  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441019  7514                   -jne 0x44102f
    if (!cpu.flags.zf)
    {
        goto L_0x0044102f;
    }
L_0x0044101b:
    // 0044101b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044101d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00441022  a348575500             -mov dword ptr [0x555748], eax
    app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */) = cpu.eax;
    // 00441027  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 0044102a  a3d0565500             -mov dword ptr [0x5556d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5592784) /* 0x5556d0 */) = cpu.eax;
L_0x0044102f:
    // 0044102f  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00441032  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00441034  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441035  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441036  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441037  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441038  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441039  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044103a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_441040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00441040  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00441041  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00441042  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00441043  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00441044  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00441045  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00441046  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00441048  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0044104b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044104d  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00441050  66833ddc227a0000       +cmp word ptr [0x7a22dc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00441058  7509                   -jne 0x441063
    if (!cpu.flags.zf)
    {
        goto L_0x00441063;
    }
    // 0044105a  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441061  750e                   -jne 0x441071
    if (!cpu.flags.zf)
    {
        goto L_0x00441071;
    }
L_0x00441063:
    // 00441063  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00441065  891d48575500           -mov dword ptr [0x555748], ebx
    app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */) = cpu.ebx;
    // 0044106b  891dd0565500           -mov dword ptr [0x5556d0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5592784) /* 0x5556d0 */) = cpu.ebx;
L_0x00441071:
    // 00441071  8b3d34925500           -mov edi, dword ptr [0x559234]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00441077  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00441079  740a                   -je 0x441085
    if (cpu.flags.zf)
    {
        goto L_0x00441085;
    }
    // 0044107b  e800fdffff             -call 0x440d80
    cpu.esp -= 4;
    sub_440d80(app, cpu);
    if (cpu.terminate) return;
    // 00441080  e9eb050000             -jmp 0x441670
    goto L_0x00441670;
L_0x00441085:
    // 00441085  66833dcc56550000       +cmp word ptr [0x5556cc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5592780) /* 0x5556cc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044108d  0f84da050000           -je 0x44166d
    if (cpu.flags.zf)
    {
        goto L_0x0044166d;
    }
    // 00441093  833d4857550000         +cmp dword ptr [0x555748], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044109a  7438                   -je 0x4410d4
    if (cpu.flags.zf)
    {
        goto L_0x004410d4;
    }
    // 0044109c  8b0dcc3f5f00           -mov ecx, dword ptr [0x5f3fcc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */);
    // 004410a2  897dec                 -mov dword ptr [ebp - 0x14], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edi;
    // 004410a5  81f910010000           +cmp ecx, 0x110
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(272 /*0x110*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004410ab  7e0f                   -jle 0x4410bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004410bc;
    }
    // 004410ad  8d71d8                 -lea esi, [ecx - 0x28]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-40) /* -0x28 */);
    // 004410b0  893dd83f5f00           -mov dword ptr [0x5f3fd8], edi
    app->getMemory<x86::reg32>(x86::reg32(6242264) /* 0x5f3fd8 */) = cpu.edi;
    // 004410b6  8935cc3f5f00           -mov dword ptr [0x5f3fcc], esi
    app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */) = cpu.esi;
L_0x004410bc:
    // 004410bc  813dcc3f5f0010010000   +cmp dword ptr [0x5f3fcc], 0x110
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(272 /*0x110*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004410c6  7d41                   -jge 0x441109
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00441109;
    }
    // 004410c8  c705cc3f5f0010010000   -mov dword ptr [0x5f3fcc], 0x110
    app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */) = 272 /*0x110*/;
    // 004410d2  eb35                   -jmp 0x441109
    goto L_0x00441109;
L_0x004410d4:
    // 004410d4  bab4000000             -mov edx, 0xb4
    cpu.edx = 180 /*0xb4*/;
    // 004410d9  8b0dcc3f5f00           -mov ecx, dword ptr [0x5f3fcc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */);
    // 004410df  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 004410e2  81f951020000           +cmp ecx, 0x251
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(593 /*0x251*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004410e8  7d09                   -jge 0x4410f3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004410f3;
    }
    // 004410ea  8d5928                 -lea ebx, [ecx + 0x28]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004410ed  891dcc3f5f00           -mov dword ptr [0x5f3fcc], ebx
    app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */) = cpu.ebx;
L_0x004410f3:
    // 004410f3  813dcc3f5f0051020000   +cmp dword ptr [0x5f3fcc], 0x251
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(593 /*0x251*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004410fd  7e0a                   -jle 0x441109
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00441109;
    }
    // 004410ff  c705cc3f5f0051020000   -mov dword ptr [0x5f3fcc], 0x251
    app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */) = 593 /*0x251*/;
L_0x00441109:
    // 00441109  8b1dc83f5f00           -mov ebx, dword ptr [0x5f3fc8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6242248) /* 0x5f3fc8 */);
    // 0044110f  a1ca565500             -mov eax, dword ptr [0x5556ca]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592778) /* 0x5556ca */);
    // 00441114  8b15cc3f5f00           -mov edx, dword ptr [0x5f3fcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */);
    // 0044111a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044111d  e86e680900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00441122  684a0f0fff             -push 0xff0f0f4a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279177034 /*0xff0f0f4a*/;
    cpu.esp -= 4;
    // 00441127  b9b0010000             -mov ecx, 0x1b0
    cpu.ecx = 432 /*0x1b0*/;
    // 0044112c  ba87000000             -mov edx, 0x87
    cpu.edx = 135 /*0x87*/;
    // 00441131  684a0f0fff             -push 0xff0f0f4a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279177034 /*0xff0f0f4a*/;
    cpu.esp -= 4;
    // 00441136  8b35cc3f5f00           -mov esi, dword ptr [0x5f3fcc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */);
    // 0044113c  8b1dcc3f5f00           -mov ebx, dword ptr [0x5f3fcc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */);
    // 00441142  684a0f0fff             -push 0xff0f0f4a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279177034 /*0xff0f0f4a*/;
    cpu.esp -= 4;
    // 00441147  83c62f                 -add esi, 0x2f
    (cpu.esi) += x86::reg32(x86::sreg32(47 /*0x2f*/));
    // 0044114a  83c331                 -add ebx, 0x31
    (cpu.ebx) += x86::reg32(x86::sreg32(49 /*0x31*/));
    // 0044114d  684a0f0fff             -push 0xff0f0f4a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279177034 /*0xff0f0f4a*/;
    cpu.esp -= 4;
    // 00441152  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00441154  8b3dcc3f5f00           -mov edi, dword ptr [0x5f3fcc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */);
    // 0044115a  e851700900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 0044115f  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 00441164  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 00441169  81c770010000           -add edi, 0x170
    (cpu.edi) += x86::reg32(x86::sreg32(368 /*0x170*/));
    // 0044116f  b9b0010000             -mov ecx, 0x1b0
    cpu.ecx = 432 /*0x1b0*/;
    // 00441174  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 00441179  ba87000000             -mov edx, 0x87
    cpu.edx = 135 /*0x87*/;
    // 0044117e  8d47fc                 -lea eax, [edi - 4]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 00441181  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 00441186  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00441188  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0044118b  e820700900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 00441190  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 00441195  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 0044119a  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 0044119f  b98b000000             -mov ecx, 0x8b
    cpu.ecx = 139 /*0x8b*/;
    // 004411a4  ba87000000             -mov edx, 0x87
    cpu.edx = 135 /*0x87*/;
    // 004411a9  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 004411ae  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004411b0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004411b2  e8f96f0900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 004411b7  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 004411bc  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 004411c1  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 004411c6  b921010000             -mov ecx, 0x121
    cpu.ecx = 289 /*0x121*/;
    // 004411cb  ba1d010000             -mov edx, 0x11d
    cpu.edx = 285 /*0x11d*/;
    // 004411d0  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 004411d5  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004411d7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004411d9  e8d26f0900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 004411de  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 004411e3  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 004411e8  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 004411ed  b99d010000             -mov ecx, 0x19d
    cpu.ecx = 413 /*0x19d*/;
    // 004411f2  ba99010000             -mov edx, 0x199
    cpu.edx = 409 /*0x199*/;
    // 004411f7  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 004411fc  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004411fe  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00441200  e8ab6f0900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 00441205  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 0044120a  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 0044120f  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 00441214  b9b0010000             -mov ecx, 0x1b0
    cpu.ecx = 432 /*0x1b0*/;
    // 00441219  baac010000             -mov edx, 0x1ac
    cpu.edx = 428 /*0x1ac*/;
    // 0044121e  68731a1cff             -push 0xff1c1a73
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280031859 /*0xff1c1a73*/;
    cpu.esp -= 4;
    // 00441223  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00441225  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00441227  e8846f0900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 0044122c  684a0f0fff             -push 0xff0f0f4a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279177034 /*0xff0f0f4a*/;
    cpu.esp -= 4;
    // 00441231  684a0f0fff             -push 0xff0f0f4a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279177034 /*0xff0f0f4a*/;
    cpu.esp -= 4;
    // 00441236  684a0f0fff             -push 0xff0f0f4a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279177034 /*0xff0f0f4a*/;
    cpu.esp -= 4;
    // 0044123b  b98d000000             -mov ecx, 0x8d
    cpu.ecx = 141 /*0x8d*/;
    // 00441240  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00441243  684a0f0fff             -push 0xff0f0f4a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279177034 /*0xff0f0f4a*/;
    cpu.esp -= 4;
    // 00441248  ba8b000000             -mov edx, 0x8b
    cpu.edx = 139 /*0x8b*/;
    // 0044124d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044124f  e85c6f0900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 00441254  684a0f0fff             -push 0xff0f0f4a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279177034 /*0xff0f0f4a*/;
    cpu.esp -= 4;
    // 00441259  684a0f0fff             -push 0xff0f0f4a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279177034 /*0xff0f0f4a*/;
    cpu.esp -= 4;
    // 0044125e  684a0f0fff             -push 0xff0f0f4a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279177034 /*0xff0f0f4a*/;
    cpu.esp -= 4;
    // 00441263  b923010000             -mov ecx, 0x123
    cpu.ecx = 291 /*0x123*/;
    // 00441268  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044126b  684a0f0fff             -push 0xff0f0f4a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279177034 /*0xff0f0f4a*/;
    cpu.esp -= 4;
    // 00441270  ba21010000             -mov edx, 0x121
    cpu.edx = 289 /*0x121*/;
    // 00441275  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00441277  e8346f0900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 0044127c  684a0f0fff             -push 0xff0f0f4a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279177034 /*0xff0f0f4a*/;
    cpu.esp -= 4;
    // 00441281  684a0f0fff             -push 0xff0f0f4a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279177034 /*0xff0f0f4a*/;
    cpu.esp -= 4;
    // 00441286  684a0f0fff             -push 0xff0f0f4a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279177034 /*0xff0f0f4a*/;
    cpu.esp -= 4;
    // 0044128b  b99f010000             -mov ecx, 0x19f
    cpu.ecx = 415 /*0x19f*/;
    // 00441290  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00441293  684a0f0fff             -push 0xff0f0f4a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279177034 /*0xff0f0f4a*/;
    cpu.esp -= 4;
    // 00441298  ba9d010000             -mov edx, 0x19d
    cpu.edx = 413 /*0x19d*/;
    // 0044129d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044129f  e80c6f0900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 004412a4  683a0505ff             -push 0xff05053a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4278519098 /*0xff05053a*/;
    cpu.esp -= 4;
    // 004412a9  683a0505ff             -push 0xff05053a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4278519098 /*0xff05053a*/;
    cpu.esp -= 4;
    // 004412ae  b91d010000             -mov ecx, 0x11d
    cpu.ecx = 285 /*0x11d*/;
    // 004412b3  68581314ff             -push 0xff141358
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279505752 /*0xff141358*/;
    cpu.esp -= 4;
    // 004412b8  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004412bb  8d4602                 -lea eax, [esi + 2]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004412be  68581314ff             -push 0xff141358
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279505752 /*0xff141358*/;
    cpu.esp -= 4;
    // 004412c3  ba8d000000             -mov edx, 0x8d
    cpu.edx = 141 /*0x8d*/;
    // 004412c8  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004412cb  e8e06e0900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 004412d0  68581314ff             -push 0xff141358
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279505752 /*0xff141358*/;
    cpu.esp -= 4;
    // 004412d5  68581314ff             -push 0xff141358
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279505752 /*0xff141358*/;
    cpu.esp -= 4;
    // 004412da  683a0505ff             -push 0xff05053a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4278519098 /*0xff05053a*/;
    cpu.esp -= 4;
    // 004412df  b999010000             -mov ecx, 0x199
    cpu.ecx = 409 /*0x199*/;
    // 004412e4  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004412e7  683a0505ff             -push 0xff05053a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4278519098 /*0xff05053a*/;
    cpu.esp -= 4;
    // 004412ec  ba23010000             -mov edx, 0x123
    cpu.edx = 291 /*0x123*/;
    // 004412f1  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004412f4  e8b76e0900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 004412f9  683a0505ff             -push 0xff05053a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4278519098 /*0xff05053a*/;
    cpu.esp -= 4;
    // 004412fe  683a0505ff             -push 0xff05053a
    app->getMemory<x86::reg32>(cpu.esp-4) = 4278519098 /*0xff05053a*/;
    cpu.esp -= 4;
    // 00441303  68581314ff             -push 0xff141358
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279505752 /*0xff141358*/;
    cpu.esp -= 4;
    // 00441308  b9ac010000             -mov ecx, 0x1ac
    cpu.ecx = 428 /*0x1ac*/;
    // 0044130d  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00441310  68581314ff             -push 0xff141358
    app->getMemory<x86::reg32>(cpu.esp-4) = 4279505752 /*0xff141358*/;
    cpu.esp -= 4;
    // 00441315  ba9f010000             -mov edx, 0x19f
    cpu.edx = 415 /*0x19f*/;
    // 0044131a  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0044131d  e88e6e0900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 00441322  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 00441327  a1cc3f5f00             -mov eax, dword ptr [0x5f3fcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */);
    // 0044132c  ba8b010000             -mov edx, 0x18b
    cpu.edx = 395 /*0x18b*/;
    // 00441331  83c00d                 -add eax, 0xd
    (cpu.eax) += x86::reg32(x86::sreg32(13 /*0xd*/));
    // 00441334  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00441336  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00441339  e802af0500             -call 0x49c240
    cpu.esp -= 4;
    sub_49c240(app, cpu);
    if (cpu.terminate) return;
    // 0044133e  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00441341  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00441344  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00441347  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00441349  7470                   -je 0x4413bb
    if (cpu.flags.zf)
    {
        goto L_0x004413bb;
    }
    // 0044134b  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00441352  741a                   -je 0x44136e
    if (cpu.flags.zf)
    {
        goto L_0x0044136e;
    }
    // 00441354  bb8b010000             -mov ebx, 0x18b
    cpu.ebx = 395 /*0x18b*/;
    // 00441359  a1fc3f5f00             -mov eax, dword ptr [0x5f3ffc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242300) /* 0x5f3ffc */);
    // 0044135e  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00441361  c1f810                 +sar eax, 0x10
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
    // 00441364  e827660900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00441369  e9b7000000             -jmp 0x441425
    goto L_0x00441425;
L_0x0044136e:
    // 0044136e  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 00441373  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00441376  bb9b010000             -mov ebx, 0x19b
    cpu.ebx = 411 /*0x19b*/;
    // 0044137b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044137c  a1fe3f5f00             -mov eax, dword ptr [0x5f3ffe]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242302) /* 0x5f3ffe */);
    // 00441381  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00441383  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00441386  e8a5530900             -call 0x4d6730
    cpu.esp -= 4;
    sub_4d6730(app, cpu);
    if (cpu.terminate) return;
    // 0044138b  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 00441390  bb9b010000             -mov ebx, 0x19b
    cpu.ebx = 411 /*0x19b*/;
    // 00441395  8b1550575500           -mov edx, dword ptr [0x555750]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592912) /* 0x555750 */);
    // 0044139b  a1fc3f5f00             -mov eax, dword ptr [0x5f3ffc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242300) /* 0x5f3ffc */);
    // 004413a0  83c20a                 -add edx, 0xa
    (cpu.edx) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004413a3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004413a6  891550575500           -mov dword ptr [0x555750], edx
    app->getMemory<x86::reg32>(x86::reg32(5592912) /* 0x555750 */) = cpu.edx;
    // 004413ac  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004413ae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004413af  31d1                   +xor ecx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004413b1  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004413b4  e877530900             -call 0x4d6730
    cpu.esp -= 4;
    sub_4d6730(app, cpu);
    if (cpu.terminate) return;
    // 004413b9  eb6a                   -jmp 0x441425
    goto L_0x00441425;
L_0x004413bb:
    // 004413bb  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 004413c2  7417                   -je 0x4413db
    if (cpu.flags.zf)
    {
        goto L_0x004413db;
    }
    // 004413c4  bb8b010000             -mov ebx, 0x18b
    cpu.ebx = 395 /*0x18b*/;
    // 004413c9  a100405f00             -mov eax, dword ptr [0x5f4000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242304) /* 0x5f4000 */);
    // 004413ce  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004413d1  c1f810                 +sar eax, 0x10
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
    // 004413d4  e8b7650900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 004413d9  eb4a                   -jmp 0x441425
    goto L_0x00441425;
L_0x004413db:
    // 004413db  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 004413e0  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004413e3  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004413e6  a1fa3f5f00             -mov eax, dword ptr [0x5f3ffa]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242298) /* 0x5f3ffa */);
    // 004413eb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004413ed  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004413ee  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004413f1  bb9b010000             -mov ebx, 0x19b
    cpu.ebx = 411 /*0x19b*/;
    // 004413f6  e835530900             -call 0x4d6730
    cpu.esp -= 4;
    sub_4d6730(app, cpu);
    if (cpu.terminate) return;
    // 004413fb  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 00441400  a150575500             -mov eax, dword ptr [0x555750]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592912) /* 0x555750 */);
    // 00441405  bb9b010000             -mov ebx, 0x19b
    cpu.ebx = 411 /*0x19b*/;
    // 0044140a  83c005                 -add eax, 5
    (cpu.eax) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 0044140d  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00441410  a350575500             -mov dword ptr [0x555750], eax
    app->getMemory<x86::reg32>(x86::reg32(5592912) /* 0x555750 */) = cpu.eax;
    // 00441415  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00441416  a100405f00             -mov eax, dword ptr [0x5f4000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242304) /* 0x5f4000 */);
    // 0044141b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044141d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00441420  e80b530900             -call 0x4d6730
    cpu.esp -= 4;
    sub_4d6730(app, cpu);
    if (cpu.terminate) return;
L_0x00441425:
    // 00441425  a1cc3f5f00             -mov eax, dword ptr [0x5f3fcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */);
    // 0044142a  8b15c83f5f00           -mov edx, dword ptr [0x5f3fc8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6242248) /* 0x5f3fc8 */);
    // 00441430  83c02f                 -add eax, 0x2f
    (cpu.eax) += x86::reg32(x86::sreg32(47 /*0x2f*/));
    // 00441433  e8f8990500             -call 0x49ae30
    cpu.esp -= 4;
    sub_49ae30(app, cpu);
    if (cpu.terminate) return;
    // 00441438  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0044143a  b920010000             -mov ecx, 0x120
    cpu.ecx = 288 /*0x120*/;
    // 0044143f  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00441441  ba20010000             -mov edx, 0x120
    cpu.edx = 288 /*0x120*/;
    // 00441446  8d58fc                 -lea ebx, [eax - 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00441449  8935bc3f5f00           -mov dword ptr [0x5f3fbc], esi
    app->getMemory<x86::reg32>(x86::reg32(6242236) /* 0x5f3fbc */) = cpu.esi;
    // 0044144f  8d041e                 -lea eax, [esi + ebx]
    cpu.eax = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 00441452  890dc43f5f00           -mov dword ptr [0x5f3fc4], ecx
    app->getMemory<x86::reg32>(x86::reg32(6242244) /* 0x5f3fc4 */) = cpu.ecx;
    // 00441458  a3b83f5f00             -mov dword ptr [0x5f3fb8], eax
    app->getMemory<x86::reg32>(x86::reg32(6242232) /* 0x5f3fb8 */) = cpu.eax;
    // 0044145d  b8ac010000             -mov eax, 0x1ac
    cpu.eax = 428 /*0x1ac*/;
    // 00441462  b98c000000             -mov ecx, 0x8c
    cpu.ecx = 140 /*0x8c*/;
    // 00441467  a3c03f5f00             -mov dword ptr [0x5f3fc0], eax
    app->getMemory<x86::reg32>(x86::reg32(6242240) /* 0x5f3fc0 */) = cpu.eax;
    // 0044146c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044146e  e8cdad0500             -call 0x49c240
    cpu.esp -= 4;
    sub_49c240(app, cpu);
    if (cpu.terminate) return;
    // 00441473  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00441475  0f8414010000           -je 0x44158f
    if (cpu.flags.zf)
    {
        goto L_0x0044158f;
    }
    // 0044147b  e830240000             -call 0x4438b0
    cpu.esp -= 4;
    sub_4438b0(app, cpu);
    if (cpu.terminate) return;
    // 00441480  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00441482  0f8507010000           -jne 0x44158f
    if (!cpu.flags.zf)
    {
        goto L_0x0044158f;
    }
    // 00441488  66833ddc227a0000       +cmp word ptr [0x7a22dc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00441490  7509                   -jne 0x44149b
    if (!cpu.flags.zf)
    {
        goto L_0x0044149b;
    }
    // 00441492  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441499  7510                   -jne 0x4414ab
    if (!cpu.flags.zf)
    {
        goto L_0x004414ab;
    }
L_0x0044149b:
    // 0044149b  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0044149d  890d48575500           -mov dword ptr [0x555748], ecx
    app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */) = cpu.ecx;
    // 004414a3  890dd0565500           -mov dword ptr [0x5556d0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5592784) /* 0x5556d0 */) = cpu.ecx;
    // 004414a9  eb0a                   -jmp 0x4414b5
    goto L_0x004414b5;
L_0x004414ab:
    // 004414ab  c705d056550001000000   -mov dword ptr [0x5556d0], 1
    app->getMemory<x86::reg32>(x86::reg32(5592784) /* 0x5556d0 */) = 1 /*0x1*/;
L_0x004414b5:
    // 004414b5  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 004414ba  b921010000             -mov ecx, 0x121
    cpu.ecx = 289 /*0x121*/;
    // 004414bf  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 004414c4  ba1f010000             -mov edx, 0x11f
    cpu.edx = 287 /*0x11f*/;
    // 004414c9  8d47fe                 -lea eax, [edi - 2]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(-2) /* -0x2 */);
    // 004414cc  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 004414d1  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 004414d4  8d46ff                 -lea eax, [esi - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 004414d7  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 004414dc  8b5ddc                 -mov ebx, dword ptr [ebp - 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004414df  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 004414e2  e8c96c0900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 004414e7  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 004414ec  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 004414f1  b9ac010000             -mov ecx, 0x1ac
    cpu.ecx = 428 /*0x1ac*/;
    // 004414f6  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 004414fb  ba1f010000             -mov edx, 0x11f
    cpu.edx = 287 /*0x11f*/;
    // 00441500  8d46fe                 -lea eax, [esi - 2]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 00441503  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 00441508  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0044150a  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 0044150d  e89e6c0900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 00441512  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 00441517  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 0044151c  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 00441521  b9ac010000             -mov ecx, 0x1ac
    cpu.ecx = 428 /*0x1ac*/;
    // 00441526  8b5ddc                 -mov ebx, dword ptr [ebp - 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00441529  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 0044152e  ba1f010000             -mov edx, 0x11f
    cpu.edx = 287 /*0x11f*/;
    // 00441533  8d47fc                 -lea eax, [edi - 4]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 00441536  e8756c0900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 0044153b  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 00441540  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 00441545  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 0044154a  b99c010000             -mov ecx, 0x19c
    cpu.ecx = 412 /*0x19c*/;
    // 0044154f  8b5ddc                 -mov ebx, dword ptr [ebp - 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00441552  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 00441557  ba9a010000             -mov edx, 0x19a
    cpu.edx = 410 /*0x19a*/;
    // 0044155c  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0044155f  e84c6c0900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 00441564  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 00441569  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 0044156e  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 00441573  b9ae010000             -mov ecx, 0x1ae
    cpu.ecx = 430 /*0x1ae*/;
    // 00441578  8b5ddc                 -mov ebx, dword ptr [ebp - 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0044157b  68207080ff             -push 0xff807020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286607392 /*0xff807020*/;
    cpu.esp -= 4;
    // 00441580  baac010000             -mov edx, 0x1ac
    cpu.edx = 428 /*0x1ac*/;
    // 00441585  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00441588  e8236c0900             -call 0x4d81b0
    cpu.esp -= 4;
    sub_4d81b0(app, cpu);
    if (cpu.terminate) return;
    // 0044158d  eb08                   -jmp 0x441597
    goto L_0x00441597;
L_0x0044158f:
    // 0044158f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00441591  8915d0565500           -mov dword ptr [0x5556d0], edx
    app->getMemory<x86::reg32>(x86::reg32(5592784) /* 0x5556d0 */) = cpu.edx;
L_0x00441597:
    // 00441597  a1cc3f5f00             -mov eax, dword ptr [0x5f3fcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */);
    // 0044159c  ba1f010000             -mov edx, 0x11f
    cpu.edx = 287 /*0x11f*/;
    // 004415a1  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004415a4  e8a7030000             -call 0x441950
    cpu.esp -= 4;
    sub_441950(app, cpu);
    if (cpu.terminate) return;
    // 004415a9  66833dda227a0000       +cmp word ptr [0x7a22da], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004415b1  7536                   -jne 0x4415e9
    if (!cpu.flags.zf)
    {
        goto L_0x004415e9;
    }
    // 004415b3  66833ddc227a0000       +cmp word ptr [0x7a22dc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004415bb  752c                   -jne 0x4415e9
    if (!cpu.flags.zf)
    {
        goto L_0x004415e9;
    }
    // 004415bd  66833d9c227a0021       +cmp word ptr [0x7a229c], 0x21
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004252) /* 0x7a229c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(33 /*0x21*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004415c5  7522                   -jne 0x4415e9
    if (!cpu.flags.zf)
    {
        goto L_0x004415e9;
    }
    // 004415c7  ba21000000             -mov edx, 0x21
    cpu.edx = 33 /*0x21*/;
    // 004415cc  b828000000             -mov eax, 0x28
    cpu.eax = 40 /*0x28*/;
    // 004415d1  e83a540600             -call 0x4a6a10
    cpu.esp -= 4;
    sub_4a6a10(app, cpu);
    if (cpu.terminate) return;
    // 004415d6  e835490000             -call 0x445f10
    cpu.esp -= 4;
    sub_445f10(app, cpu);
    if (cpu.terminate) return;
    // 004415db  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 004415e0  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004415e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004415e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004415e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004415e5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004415e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004415e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004415e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004415e9:
    // 004415e9  833ddc3f5f0000         +cmp dword ptr [0x5f3fdc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004415f0  7456                   -je 0x441648
    if (cpu.flags.zf)
    {
        goto L_0x00441648;
    }
    // 004415f2  e8298f0500             -call 0x49a520
    cpu.esp -= 4;
    sub_49a520(app, cpu);
    if (cpu.terminate) return;
    // 004415f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004415f9  754d                   -jne 0x441648
    if (!cpu.flags.zf)
    {
        goto L_0x00441648;
    }
    // 004415fb  e8d0950500             -call 0x49abd0
    cpu.esp -= 4;
    sub_49abd0(app, cpu);
    if (cpu.terminate) return;
    // 00441600  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00441602  7444                   -je 0x441648
    if (cpu.flags.zf)
    {
        goto L_0x00441648;
    }
    // 00441604  8b1ddc3f5f00           -mov ebx, dword ptr [0x5f3fdc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */);
    // 0044160a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044160c  740f                   -je 0x44161d
    if (cpu.flags.zf)
    {
        goto L_0x0044161d;
    }
    // 0044160e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00441610  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00441612  e879020a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00441617  8935dc3f5f00           -mov dword ptr [0x5f3fdc], esi
    app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */) = cpu.esi;
L_0x0044161d:
    // 0044161d  8b3dd03f5f00           -mov edi, dword ptr [0x5f3fd0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6242256) /* 0x5f3fd0 */);
    // 00441623  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00441625  740e                   -je 0x441635
    if (cpu.flags.zf)
    {
        goto L_0x00441635;
    }
    // 00441627  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00441629  e862020a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0044162e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441630  a3d03f5f00             -mov dword ptr [0x5f3fd0], eax
    app->getMemory<x86::reg32>(x86::reg32(6242256) /* 0x5f3fd0 */) = cpu.eax;
L_0x00441635:
    // 00441635  e896960500             -call 0x49acd0
    cpu.esp -= 4;
    sub_49acd0(app, cpu);
    if (cpu.terminate) return;
    // 0044163a  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 0044163f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00441641  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441642  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441643  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441644  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441645  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441646  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441647  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00441648:
    // 00441648  66833ddc227a0000       +cmp word ptr [0x7a22dc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00441650  741b                   -je 0x44166d
    if (cpu.flags.zf)
    {
        goto L_0x0044166d;
    }
    // 00441652  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00441657  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00441659  ba51020000             -mov edx, 0x251
    cpu.edx = 593 /*0x251*/;
    // 0044165e  890d48575500           -mov dword ptr [0x555748], ecx
    app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */) = cpu.ecx;
    // 00441664  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 00441667  8915cc3f5f00           -mov dword ptr [0x5f3fcc], edx
    app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */) = cpu.edx;
L_0x0044166d:
    // 0044166d  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
L_0x00441670:
    // 00441670  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00441672  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441673  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441674  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441675  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441676  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441677  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441678  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_441680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00441680  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00441681  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00441682  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00441683  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00441684  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00441686  66833ddc227a0000       +cmp word ptr [0x7a22dc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044168e  7509                   -jne 0x441699
    if (!cpu.flags.zf)
    {
        goto L_0x00441699;
    }
    // 00441690  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441697  7510                   -jne 0x4416a9
    if (!cpu.flags.zf)
    {
        goto L_0x004416a9;
    }
L_0x00441699:
    // 00441699  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0044169b  890d48575500           -mov dword ptr [0x555748], ecx
    app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */) = cpu.ecx;
    // 004416a1  890dd0565500           -mov dword ptr [0x5556d0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5592784) /* 0x5556d0 */) = cpu.ecx;
    // 004416a7  eb43                   -jmp 0x4416ec
    goto L_0x004416ec;
L_0x004416a9:
    // 004416a9  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004416b0  753a                   -jne 0x4416ec
    if (!cpu.flags.zf)
    {
        goto L_0x004416ec;
    }
    // 004416b2  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004416b7  a1cc3f5f00             -mov eax, dword ptr [0x5f3fcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */);
    // 004416bc  ba8b010000             -mov edx, 0x18b
    cpu.edx = 395 /*0x18b*/;
    // 004416c1  83c00d                 -add eax, 0xd
    (cpu.eax) += x86::reg32(x86::sreg32(13 /*0xd*/));
    // 004416c4  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004416c6  e875ab0500             -call 0x49c240
    cpu.esp -= 4;
    sub_49c240(app, cpu);
    if (cpu.terminate) return;
    // 004416cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004416cd  740a                   -je 0x4416d9
    if (cpu.flags.zf)
    {
        goto L_0x004416d9;
    }
    // 004416cf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004416d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004416d5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004416d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004416d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004416d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004416d9:
    // 004416d9  833dd056550000         +cmp dword ptr [0x5556d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5592784) /* 0x5556d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004416e0  740a                   -je 0x4416ec
    if (cpu.flags.zf)
    {
        goto L_0x004416ec;
    }
    // 004416e2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004416e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004416e8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004416e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004416ea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004416eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004416ec:
    // 004416ec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004416ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004416ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004416f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004416f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004416f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_441700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00441700  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00441701  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00441702  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00441703  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00441704  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00441705  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00441707  668b15dc227a00         -mov dx, word ptr [0x7a22dc]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */);
    // 0044170e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00441710  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 00441713  7509                   -jne 0x44171e
    if (!cpu.flags.zf)
    {
        goto L_0x0044171e;
    }
    // 00441715  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044171c  750e                   -jne 0x44172c
    if (!cpu.flags.zf)
    {
        goto L_0x0044172c;
    }
L_0x0044171e:
    // 0044171e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00441720  890d48575500           -mov dword ptr [0x555748], ecx
    app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */) = cpu.ecx;
    // 00441726  890dd0565500           -mov dword ptr [0x5556d0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5592784) /* 0x5556d0 */) = cpu.ecx;
L_0x0044172c:
    // 0044172c  66833dcc56550000       +cmp word ptr [0x5556cc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5592780) /* 0x5556cc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00441734  0f84ad000000           -je 0x4417e7
    if (cpu.flags.zf)
    {
        goto L_0x004417e7;
    }
    // 0044173a  663d0d00               +cmp ax, 0xd
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044173e  754c                   -jne 0x44178c
    if (!cpu.flags.zf)
    {
        goto L_0x0044178c;
    }
    // 00441740  833d5846660000         +cmp dword ptr [0x664658], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6702680) /* 0x664658 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441747  7443                   -je 0x44178c
    if (cpu.flags.zf)
    {
        goto L_0x0044178c;
    }
    // 00441749  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441750  753a                   -jne 0x44178c
    if (!cpu.flags.zf)
    {
        goto L_0x0044178c;
    }
    // 00441752  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 00441757  a1cc3f5f00             -mov eax, dword ptr [0x5f3fcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */);
    // 0044175c  ba8b010000             -mov edx, 0x18b
    cpu.edx = 395 /*0x18b*/;
    // 00441761  83c00d                 -add eax, 0xd
    (cpu.eax) += x86::reg32(x86::sreg32(13 /*0xd*/));
    // 00441764  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00441766  e8d5aa0500             -call 0x49c240
    cpu.esp -= 4;
    sub_49c240(app, cpu);
    if (cpu.terminate) return;
    // 0044176b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044176d  741d                   -je 0x44178c
    if (cpu.flags.zf)
    {
        goto L_0x0044178c;
    }
    // 0044176f  8b1548575500           -mov edx, dword ptr [0x555748]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */);
    // 00441775  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 0044177a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044177c  7507                   -jne 0x441785
    if (!cpu.flags.zf)
    {
        goto L_0x00441785;
    }
    // 0044177e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00441783  eb02                   -jmp 0x441787
    goto L_0x00441787;
L_0x00441785:
    // 00441785  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00441787:
    // 00441787  a348575500             -mov dword ptr [0x555748], eax
    app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */) = cpu.eax;
L_0x0044178c:
    // 0044178c  833dd056550000         +cmp dword ptr [0x5556d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5592784) /* 0x5556d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441793  7543                   -jne 0x4417d8
    if (!cpu.flags.zf)
    {
        goto L_0x004417d8;
    }
    // 00441795  833d4857550000         +cmp dword ptr [0x555748], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044179c  7449                   -je 0x4417e7
    if (cpu.flags.zf)
    {
        goto L_0x004417e7;
    }
    // 0044179e  a154466600             -mov eax, dword ptr [0x664654]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702676) /* 0x664654 */);
    // 004417a3  3d00480000             +cmp eax, 0x4800
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18432 /*0x4800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004417a8  721d                   -jb 0x4417c7
    if (cpu.flags.cf)
    {
        goto L_0x004417c7;
    }
    // 004417aa  763b                   -jbe 0x4417e7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004417e7;
    }
    // 004417ac  3d004d0000             +cmp eax, 0x4d00
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19712 /*0x4d00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004417b1  720b                   -jb 0x4417be
    if (cpu.flags.cf)
    {
        goto L_0x004417be;
    }
    // 004417b3  7632                   -jbe 0x4417e7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004417e7;
    }
    // 004417b5  3d00500000             +cmp eax, 0x5000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20480 /*0x5000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004417ba  742b                   -je 0x4417e7
    if (cpu.flags.zf)
    {
        goto L_0x004417e7;
    }
    // 004417bc  eb15                   -jmp 0x4417d3
    goto L_0x004417d3;
L_0x004417be:
    // 004417be  3d004b0000             +cmp eax, 0x4b00
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19200 /*0x4b00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004417c3  7422                   -je 0x4417e7
    if (cpu.flags.zf)
    {
        goto L_0x004417e7;
    }
    // 004417c5  eb0c                   -jmp 0x4417d3
    goto L_0x004417d3;
L_0x004417c7:
    // 004417c7  83f80d                 +cmp eax, 0xd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004417ca  7207                   -jb 0x4417d3
    if (cpu.flags.cf)
    {
        goto L_0x004417d3;
    }
    // 004417cc  7619                   -jbe 0x4417e7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004417e7;
    }
    // 004417ce  83f81b                 +cmp eax, 0x1b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(27 /*0x1b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004417d1  7414                   -je 0x4417e7
    if (cpu.flags.zf)
    {
        goto L_0x004417e7;
    }
L_0x004417d3:
    // 004417d3  e888f5ffff             -call 0x440d60
    cpu.esp -= 4;
    sub_440d60(app, cpu);
    if (cpu.terminate) return;
L_0x004417d8:
    // 004417d8  a154466600             -mov eax, dword ptr [0x664654]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702676) /* 0x664654 */);
    // 004417dd  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 004417e2  e839030000             -call 0x441b20
    cpu.esp -= 4;
    sub_441b20(app, cpu);
    if (cpu.terminate) return;
L_0x004417e7:
    // 004417e7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004417e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004417ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004417eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004417ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004417ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004417ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4417f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004417f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004417f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004417f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004417f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004417f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004417f5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004417f7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004417f9  8b15d03f5f00           -mov edx, dword ptr [0x5f3fd0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6242256) /* 0x5f3fd0 */);
    // 004417ff  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00441801  0f84c8000000           -je 0x4418cf
    if (cpu.flags.zf)
    {
        goto L_0x004418cf;
    }
    // 00441807  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00441809  0f84c0000000           -je 0x4418cf
    if (cpu.flags.zf)
    {
        goto L_0x004418cf;
    }
    // 0044180f  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 00441814  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 00441819  8a9220030000           -mov dl, byte ptr [edx + 0x320]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(800) /* 0x320 */);
    // 0044181f  891dd43f5f00           -mov dword ptr [0x5f3fd4], ebx
    app->getMemory<x86::reg32>(x86::reg32(6242260) /* 0x5f3fd4 */) = cpu.ebx;
    // 00441825  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00441827  7547                   -jne 0x441870
    if (!cpu.flags.zf)
    {
        goto L_0x00441870;
    }
L_0x00441829:
    // 00441829  8d56ff                 -lea edx, [esi - 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 0044182c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00441833  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00441835  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00441838  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044183a  a1d03f5f00             -mov eax, dword ptr [0x5f3fd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242256) /* 0x5f3fd0 */);
    // 0044183f  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00441842  803c0200               +cmp byte ptr [edx + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00441846  7507                   -jne 0x44184f
    if (!cpu.flags.zf)
    {
        goto L_0x0044184f;
    }
    // 00441848  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044184a  7403                   -je 0x44184f
    if (cpu.flags.zf)
    {
        goto L_0x0044184f;
    }
    // 0044184c  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044184d  ebda                   -jmp 0x441829
    goto L_0x00441829;
L_0x0044184f:
    // 0044184f  8d14b500000000         -lea edx, [esi*4]
    cpu.edx = x86::reg32(cpu.esi * 4);
    // 00441856  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00441858  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0044185b  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0044185d  a1d03f5f00             -mov eax, dword ptr [0x5f3fd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242256) /* 0x5f3fd0 */);
    // 00441862  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00441865  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0044186a  01d0                   +add eax, edx
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
    // 0044186c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044186e  eb5a                   -jmp 0x4418ca
    goto L_0x004418ca;
L_0x00441870:
    // 00441870  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00441875  eb05                   -jmp 0x44187c
    goto L_0x0044187c;
L_0x00441877:
    // 00441877  83fe09                 +cmp esi, 9
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044187a  7d3d                   -jge 0x4418b9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004418b9;
    }
L_0x0044187c:
    // 0044187c  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044187f  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00441886  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00441888  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0044188b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044188d  8b1dd03f5f00           -mov ebx, dword ptr [0x5f3fd0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6242256) /* 0x5f3fd0 */);
    // 00441893  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00441896  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00441899  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004418a0  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004418a2  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004418a5  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004418a7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004418aa  01d8                   +add eax, ebx
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
    // 004418ac  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 004418b1  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004418b2  e879f50900             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004418b7  ebbe                   -jmp 0x441877
    goto L_0x00441877;
L_0x004418b9:
    // 004418b9  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 004418be  a1d03f5f00             -mov eax, dword ptr [0x5f3fd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242256) /* 0x5f3fd0 */);
    // 004418c3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004418c5  0520030000             -add eax, 0x320
    (cpu.eax) += x86::reg32(x86::sreg32(800 /*0x320*/));
L_0x004418ca:
    // 004418ca  e861f50900             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
L_0x004418cf:
    // 004418cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004418d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004418d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004418d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004418d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004418d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4418e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004418e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004418e1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004418e2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004418e4  8b15bc3f5f00           -mov edx, dword ptr [0x5f3fbc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6242236) /* 0x5f3fbc */);
    // 004418ea  a1b83f5f00             -mov eax, dword ptr [0x5f3fb8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242232) /* 0x5f3fb8 */);
    // 004418ef  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004418f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004418f3  7f02                   -jg 0x4418f7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004418f7;
    }
    // 004418f5  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004418f7:
    // 004418f7  83e814                 -sub eax, 0x14
    (cpu.eax) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004418fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004418fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004418fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_441900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00441900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00441901  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00441902  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00441903  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00441904  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00441906  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00441908  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044190a  7405                   -je 0x441911
    if (cpu.flags.zf)
    {
        goto L_0x00441911;
    }
    // 0044190c  803800                 +cmp byte ptr [eax], 0
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
    // 0044190f  750a                   -jne 0x44191b
    if (!cpu.flags.zf)
    {
        goto L_0x0044191b;
    }
L_0x00441911:
    // 00441911  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00441916  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441917  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441918  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441919  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044191a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044191b:
    // 0044191b  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00441920  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00441925  e8d6070100             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 0044192a  e8b1ffffff             -call 0x4418e0
    cpu.esp -= 4;
    sub_4418e0(app, cpu);
    if (cpu.terminate) return;
    // 0044192f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00441931  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00441933  e8e8060100             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00441938  39d8                   +cmp eax, ebx
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
    // 0044193a  7f0a                   -jg 0x441946
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00441946;
    }
    // 0044193c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00441941  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441942  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441943  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441944  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441945  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00441946:
    // 00441946  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441948  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441949  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044194a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044194b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044194c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_441950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00441950  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00441951  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00441952  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00441953  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00441954  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00441955  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00441957  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 0044195a  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0044195d  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00441960  b919000000             -mov ecx, 0x19
    cpu.ecx = 25 /*0x19*/;
    // 00441965  8d7d84                 -lea edi, [ebp - 0x7c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-124) /* -0x7c */);
    // 00441968  be80f14300             -mov esi, 0x43f180
    cpu.esi = 4452736 /*0x43f180*/;
    // 0044196d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044196f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00441971  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00441974  8b0ddc3f5f00           -mov ecx, dword ptr [0x5f3fdc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */);
    // 0044197a  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0044197d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044197f  0f8493010000           -je 0x441b18
    if (cpu.flags.zf)
    {
        goto L_0x00441b18;
    }
    // 00441985  833dd03f5f0000         +cmp dword ptr [0x5f3fd0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6242256) /* 0x5f3fd0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044198c  0f8486010000           -je 0x441b18
    if (cpu.flags.zf)
    {
        goto L_0x00441b18;
    }
    // 00441992  e819c0feff             -call 0x42d9b0
    cpu.esp -= 4;
    sub_42d9b0(app, cpu);
    if (cpu.terminate) return;
    // 00441997  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441999  e8e256ffff             -call 0x437080
    cpu.esp -= 4;
    sub_437080(app, cpu);
    if (cpu.terminate) return;
    // 0044199e  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 004419a1  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
L_0x004419a4:
    // 004419a4  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004419a7  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004419aa  3b02                   +cmp eax, dword ptr [edx]
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
    // 004419ac  0f8d6b000000           -jge 0x441a1d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00441a1d;
    }
    // 004419b2  6bd065                 -imul edx, eax, 0x65
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(101 /*0x65*/)));
    // 004419b5  bb40e4ff00             -mov ebx, 0xffe440
    cpu.ebx = 16770112 /*0xffe440*/;
    // 004419ba  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004419bd  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 004419c0  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004419c3  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 004419c8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004419ca  8d4584                 -lea eax, [ebp - 0x7c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-124) /* -0x7c */);
    // 004419cd  e85ef40900             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
L_0x004419d2:
    // 004419d2  8d4584                 -lea eax, [ebp - 0x7c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-124) /* -0x7c */);
    // 004419d5  e826ffffff             -call 0x441900
    cpu.esp -= 4;
    sub_441900(app, cpu);
    if (cpu.terminate) return;
    // 004419da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004419dc  751b                   -jne 0x4419f9
    if (!cpu.flags.zf)
    {
        goto L_0x004419f9;
    }
    // 004419de  807d8400               +cmp byte ptr [ebp - 0x7c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-124) /* -0x7c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004419e2  7415                   -je 0x4419f9
    if (cpu.flags.zf)
    {
        goto L_0x004419f9;
    }
    // 004419e4  8d7d84                 -lea edi, [ebp - 0x7c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-124) /* -0x7c */);
    // 004419e7  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004419e9  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004419eb  49                     -dec ecx
    (cpu.ecx)--;
    // 004419ec  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004419ee  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 004419f0  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004419f2  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004419f3  88542983               -mov byte ptr [ecx + ebp - 0x7d], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-125) /* -0x7d */ + cpu.ebp * 1) = cpu.dl;
    // 004419f7  ebd9                   -jmp 0x4419d2
    goto L_0x004419d2;
L_0x004419f9:
    // 004419f9  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004419fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004419fd  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00441a02  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00441a05  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00441a07  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00441a09  8d4584                 -lea eax, [ebp - 0x7c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-124) /* -0x7c */);
    // 00441a0c  e87f070100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00441a11  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00441a14  42                     -inc edx
    (cpu.edx)++;
    // 00441a15  83c60d                 +add esi, 0xd
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00441a18  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 00441a1b  eb87                   -jmp 0x4419a4
    goto L_0x004419a4;
L_0x00441a1d:
    // 00441a1d  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00441a22  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00441a25  e8d6060100             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 00441a2a  8b0ddc3f5f00           -mov ecx, dword ptr [0x5f3fdc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */);
    // 00441a30  83c67c                 -add esi, 0x7c
    (cpu.esi) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00441a33  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00441a35  0f84dd000000           -je 0x441b18
    if (cpu.flags.zf)
    {
        goto L_0x00441b18;
    }
    // 00441a3b  e8a0feffff             -call 0x4418e0
    cpu.esp -= 4;
    sub_4418e0(app, cpu);
    if (cpu.terminate) return;
    // 00441a40  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00441a42  b823000000             -mov eax, 0x23
    cpu.eax = 35 /*0x23*/;
    // 00441a47  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00441a4c  e8fffd0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00441a51  e8ca050100             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00441a56  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00441a58  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00441a5a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00441a5c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00441a5e  7f02                   -jg 0x441a62
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00441a62;
    }
    // 00441a60  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x00441a62:
    // 00441a62  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00441a64:
    // 00441a64  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00441a67  a1dc3f5f00             -mov eax, dword ptr [0x5f3fdc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */);
    // 00441a6c  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00441a71  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00441a73  e8a8050100             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00441a78  39c8                   +cmp eax, ecx
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
    // 00441a7a  7e08                   -jle 0x441a84
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00441a84;
    }
    // 00441a7c  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00441a7f  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00441a82  ebe0                   -jmp 0x441a64
    goto L_0x00441a64;
L_0x00441a84:
    // 00441a84  68fd9d64ff             -push 0xff649dfd
    app->getMemory<x86::reg32>(cpu.esp-4) = 4284784125 /*0xff649dfd*/;
    cpu.esp -= 4;
    // 00441a89  b823000000             -mov eax, 0x23
    cpu.eax = 35 /*0x23*/;
    // 00441a8e  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00441a93  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00441a95  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00441a98  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00441a9a  e8b1fd0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00441a9f  e8ec060100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00441aa4  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00441aa7  6840e4ff00             -push 0xffe440
    app->getMemory<x86::reg32>(cpu.esp-4) = 16770112 /*0xffe440*/;
    cpu.esp -= 4;
    // 00441aac  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00441aaf  a1dc3f5f00             -mov eax, dword ptr [0x5f3fdc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */);
    // 00441ab4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00441ab6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00441ab8  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00441aba  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00441abc  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00441ac1  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00441ac4  e8c7060100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00441ac9  8b15bc405f00           -mov edx, dword ptr [0x5f40bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6242492) /* 0x5f40bc */);
    // 00441acf  42                     -inc edx
    (cpu.edx)++;
    // 00441ad0  b91e000000             -mov ecx, 0x1e
    cpu.ecx = 30 /*0x1e*/;
    // 00441ad5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00441ad7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00441ada  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00441adc  8915bc405f00           -mov dword ptr [0x5f40bc], edx
    app->getMemory<x86::reg32>(x86::reg32(6242492) /* 0x5f40bc */) = cpu.edx;
    // 00441ae2  83fa0f                 +cmp edx, 0xf
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441ae5  7d31                   -jge 0x441b18
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00441b18;
    }
    // 00441ae7  6840e4ff00             -push 0xffe440
    app->getMemory<x86::reg32>(cpu.esp-4) = 16770112 /*0xffe440*/;
    cpu.esp -= 4;
    // 00441aec  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00441aef  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00441af4  a1dc3f5f00             -mov eax, dword ptr [0x5f3fdc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */);
    // 00441af9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00441afb  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00441afd  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00441b02  e819050100             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00441b07  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00441b0a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00441b0c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00441b0e  b8ac795300             -mov eax, 0x5379ac
    cpu.eax = 5470636 /*0x5379ac*/;
    // 00441b13  e878060100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
L_0x00441b18:
    // 00441b18  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00441b1a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441b1b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441b1c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441b1d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441b1e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441b1f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_441b20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00441b20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00441b21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00441b22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00441b23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00441b24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00441b25  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00441b26  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00441b28  83ec64                 -sub esp, 0x64
    (cpu.esp) -= x86::reg32(x86::sreg32(100 /*0x64*/));
    // 00441b2b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00441b2d  8b15dc3f5f00           -mov edx, dword ptr [0x5f3fdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */);
    // 00441b33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441b35  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00441b37  0f8441010000           -je 0x441c7e
    if (cpu.flags.zf)
    {
        goto L_0x00441c7e;
    }
    // 00441b3d  833d4857550000         +cmp dword ptr [0x555748], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441b44  0f8434010000           -je 0x441c7e
    if (cpu.flags.zf)
    {
        goto L_0x00441c7e;
    }
    // 00441b4a  833d5846660000         +cmp dword ptr [0x664658], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6702680) /* 0x664658 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441b51  0f8527010000           -jne 0x441c7e
    if (!cpu.flags.zf)
    {
        goto L_0x00441c7e;
    }
    // 00441b57  6683fb0d               +cmp bx, 0xd
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00441b5b  7222                   -jb 0x441b7f
    if (cpu.flags.cf)
    {
        goto L_0x00441b7f;
    }
    // 00441b5d  762f                   -jbe 0x441b8e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00441b8e;
    }
    // 00441b5f  6683fb1b               +cmp bx, 0x1b
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00441b63  0f82dc000000           -jb 0x441c45
    if (cpu.flags.cf)
    {
        goto L_0x00441c45;
    }
    // 00441b69  0f860a010000           -jbe 0x441c79
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00441c79;
    }
    // 00441b6f  6681fb0053             +cmp bx, 0x5300
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21248 /*0x5300*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00441b74  0f849f000000           -je 0x441c19
    if (cpu.flags.zf)
    {
        goto L_0x00441c19;
    }
    // 00441b7a  e9c6000000             -jmp 0x441c45
    goto L_0x00441c45;
L_0x00441b7f:
    // 00441b7f  6683fb08               +cmp bx, 8
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00441b83  0f8490000000           -je 0x441c19
    if (cpu.flags.zf)
    {
        goto L_0x00441c19;
    }
    // 00441b89  e9b7000000             -jmp 0x441c45
    goto L_0x00441c45;
L_0x00441b8e:
    // 00441b8e  befcd26f00             -mov esi, 0x6fd2fc
    cpu.esi = 7328508 /*0x6fd2fc*/;
    // 00441b93  8d7d9c                 -lea edi, [ebp - 0x64]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00441b96  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00441b97:
    // 00441b97  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00441b99  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00441b9b  3c00                   +cmp al, 0
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
    // 00441b9d  7410                   -je 0x441baf
    if (cpu.flags.zf)
    {
        goto L_0x00441baf;
    }
    // 00441b9f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00441ba2  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00441ba5  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00441ba8  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00441bab  3c00                   +cmp al, 0
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
    // 00441bad  75e8                   -jne 0x441b97
    if (!cpu.flags.zf)
    {
        goto L_0x00441b97;
    }
L_0x00441baf:
    // 00441baf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441bb0  be34785300             -mov esi, 0x537834
    cpu.esi = 5470260 /*0x537834*/;
    // 00441bb5  8d7d9c                 -lea edi, [ebp - 0x64]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00441bb8  bb57000000             -mov ebx, 0x57
    cpu.ebx = 87 /*0x57*/;
    // 00441bbd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00441bbe  2bc9                   +sub ecx, ecx
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
    // 00441bc0  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00441bc1  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00441bc3  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00441bc5  4f                     -dec edi
    (cpu.edi)--;
L_0x00441bc6:
    // 00441bc6  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00441bc8  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00441bca  3c00                   +cmp al, 0
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
    // 00441bcc  7410                   -je 0x441bde
    if (cpu.flags.zf)
    {
        goto L_0x00441bde;
    }
    // 00441bce  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00441bd1  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00441bd4  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00441bd7  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00441bda  3c00                   +cmp al, 0
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
    // 00441bdc  75e8                   -jne 0x441bc6
    if (!cpu.flags.zf)
    {
        goto L_0x00441bc6;
    }
L_0x00441bde:
    // 00441bde  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441bdf  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00441be2  8b15dc3f5f00           -mov edx, dword ptr [0x5f3fdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */);
    // 00441be8  e803d20a00             -call 0x4eedf0
    cpu.esp -= 4;
    sub_4eedf0(app, cpu);
    if (cpu.terminate) return;
    // 00441bed  8d559c                 -lea edx, [ebp - 0x64]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00441bf0  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 00441bf5  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 00441bfa  e811bcfeff             -call 0x42d810
    cpu.esp -= 4;
    sub_42d810(app, cpu);
    if (cpu.terminate) return;
    // 00441bff  a1dc3f5f00             -mov eax, dword ptr [0x5f3fdc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */);
    // 00441c04  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00441c06  e835ea0900             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00441c0b  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00441c10  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00441c12  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c13  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00441c19:
    // 00441c19  8b3ddc3f5f00           -mov edi, dword ptr [0x5f3fdc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */);
    // 00441c1f  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00441c21  49                     -dec ecx
    (cpu.ecx)--;
    // 00441c22  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00441c24  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00441c26  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00441c28  49                     -dec ecx
    (cpu.ecx)--;
    // 00441c29  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00441c2b  744c                   -je 0x441c79
    if (cpu.flags.zf)
    {
        goto L_0x00441c79;
    }
    // 00441c2d  a1dc3f5f00             -mov eax, dword ptr [0x5f3fdc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */);
    // 00441c32  c64401ff00             -mov byte ptr [ecx + eax - 1], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */ + cpu.eax * 1) = 0 /*0x0*/;
    // 00441c37  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00441c3c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00441c3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c41  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c43  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c44  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00441c45:
    // 00441c45  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441c47  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00441c4c  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00441c4e  e8bd1b0000             -call 0x443810
    cpu.esp -= 4;
    sub_443810(app, cpu);
    if (cpu.terminate) return;
    // 00441c53  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00441c55  7422                   -je 0x441c79
    if (cpu.flags.zf)
    {
        goto L_0x00441c79;
    }
    // 00441c57  8b3ddc3f5f00           -mov edi, dword ptr [0x5f3fdc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */);
    // 00441c5d  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00441c5f  49                     -dec ecx
    (cpu.ecx)--;
    // 00441c60  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00441c62  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00441c64  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00441c66  49                     -dec ecx
    (cpu.ecx)--;
    // 00441c67  83f956                 +cmp ecx, 0x56
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(86 /*0x56*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441c6a  7d0d                   -jge 0x441c79
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00441c79;
    }
    // 00441c6c  a1dc3f5f00             -mov eax, dword ptr [0x5f3fdc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */);
    // 00441c71  c644010100             -mov byte ptr [ecx + eax + 1], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */ + cpu.eax * 1) = 0 /*0x0*/;
    // 00441c76  881c01                 -mov byte ptr [ecx + eax], bl
    app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 1) = cpu.bl;
L_0x00441c79:
    // 00441c79  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00441c7e:
    // 00441c7e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00441c80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c81  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c83  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c85  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_441cb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00441cb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00441cb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00441cb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00441cb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00441cb4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00441cb5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00441cb6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00441cb8  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00441cbb  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00441cbe  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00441cc3  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 00441cc8  b860020000             -mov eax, 0x260
    cpu.eax = 608 /*0x260*/;
    // 00441ccd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00441ccf  e8bcd40a00             -call 0x4ef190
    cpu.esp -= 4;
    sub_4ef190(app, cpu);
    if (cpu.terminate) return;
    // 00441cd4  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00441cd7  e8c4900a00             -call 0x4eada0
    cpu.esp -= 4;
    sub_4eada0(app, cpu);
    if (cpu.terminate) return;
    // 00441cdc  803d1050560008         +cmp byte ptr [0x565010], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00441ce3  7507                   -jne 0x441cec
    if (!cpu.flags.zf)
    {
        goto L_0x00441cec;
    }
    // 00441ce5  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00441cea  eb02                   -jmp 0x441cee
    goto L_0x00441cee;
L_0x00441cec:
    // 00441cec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00441cee:
    // 00441cee  e8bdd40a00             -call 0x4ef1b0
    cpu.esp -= 4;
    sub_4ef1b0(app, cpu);
    if (cpu.terminate) return;
    // 00441cf3  a1285c5500             -mov eax, dword ptr [0x555c28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */);
    // 00441cf8  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00441cfb  8b9058575500           -mov edx, dword ptr [eax + 0x555758]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5592920) /* 0x555758 */);
    // 00441d01  83fa04                 +cmp edx, 4
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
    // 00441d04  0f87ae040000           -ja 0x4421b8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004421b8;
    }
    // 00441d0a  ff2495901c4400         -jmp dword ptr [edx*4 + 0x441c90]
    cpu.ip = app->getMemory<x86::reg32>(4463760 + cpu.edx * 4); goto dynamic_jump;
  case 0x00441d11:
    // 00441d11  8b1554575500           -mov edx, dword ptr [0x555754]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592916) /* 0x555754 */);
    // 00441d17  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00441d19  0f84eb000000           -je 0x441e0a
    if (cpu.flags.zf)
    {
        goto L_0x00441e0a;
    }
    // 00441d1f  a1285c5500             -mov eax, dword ptr [0x555c28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */);
    // 00441d24  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00441d27  8b8858575500           -mov ecx, dword ptr [eax + 0x555758]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5592920) /* 0x555758 */);
    // 00441d2d  83f901                 +cmp ecx, 1
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
    // 00441d30  7509                   -jne 0x441d3b
    if (!cpu.flags.zf)
    {
        goto L_0x00441d3b;
    }
    // 00441d32  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00441d34  ba907b5300             -mov edx, 0x537b90
    cpu.edx = 5471120 /*0x537b90*/;
    // 00441d39  eb0b                   -jmp 0x441d46
    goto L_0x00441d46;
L_0x00441d3b:
    // 00441d3b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00441d3d  750e                   -jne 0x441d4d
    if (!cpu.flags.zf)
    {
        goto L_0x00441d4d;
    }
    // 00441d3f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00441d41  ba987b5300             -mov edx, 0x537b98
    cpu.edx = 5471128 /*0x537b98*/;
L_0x00441d46:
    // 00441d46  e895d40a00             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00441d4b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00441d4d:
    // 00441d4d  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00441d50  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 00441d55  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00441d58  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00441d5a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00441d5c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00441d5f  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00441d61  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00441d63  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00441d65  8b4602                 -mov eax, dword ptr [esi + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00441d68  ba60020000             -mov edx, 0x260
    cpu.edx = 608 /*0x260*/;
    // 00441d6d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00441d70  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00441d72  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00441d74  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00441d77  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00441d79  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00441d7b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00441d7d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00441d7f  e86cd60a00             -call 0x4ef3f0
    cpu.esp -= 4;
    sub_4ef3f0(app, cpu);
    if (cpu.terminate) return;
    // 00441d84  a1285c5500             -mov eax, dword ptr [0x555c28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */);
    // 00441d89  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00441d8c  8b9064575500           -mov edx, dword ptr [eax + 0x555764]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5592932) /* 0x555764 */);
    // 00441d92  a154575500             -mov eax, dword ptr [0x555754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592916) /* 0x555754 */);
    // 00441d97  e8d4d40a00             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 00441d9c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00441d9e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00441da0  7511                   -jne 0x441db3
    if (!cpu.flags.zf)
    {
        goto L_0x00441db3;
    }
    // 00441da2  baa07b5300             -mov edx, 0x537ba0
    cpu.edx = 5471136 /*0x537ba0*/;
    // 00441da7  a154575500             -mov eax, dword ptr [0x555754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592916) /* 0x555754 */);
    // 00441dac  e8bfd40a00             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 00441db1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00441db3:
    // 00441db3  bb4c000000             -mov ebx, 0x4c
    cpu.ebx = 76 /*0x4c*/;
    // 00441db8  ba9c010000             -mov edx, 0x19c
    cpu.edx = 412 /*0x19c*/;
    // 00441dbd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00441dbf  e82cd60a00             -call 0x4ef3f0
    cpu.esp -= 4;
    sub_4ef3f0(app, cpu);
    if (cpu.terminate) return;
    // 00441dc4  a1285c5500             -mov eax, dword ptr [0x555c28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */);
    // 00441dc9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00441dcb  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 00441dd0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00441dd3  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00441dd5  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00441dd8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00441dd9  68a87b5300             -push 0x537ba8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5471144 /*0x537ba8*/;
    cpu.esp -= 4;
    // 00441dde  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00441de1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00441de2  e8a9d80900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00441de7  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00441dea  8d55d4                 -lea edx, [ebp - 0x2c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00441ded  a154575500             -mov eax, dword ptr [0x555754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592916) /* 0x555754 */);
    // 00441df2  e879d40a00             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 00441df7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00441df9  740f                   -je 0x441e0a
    if (cpu.flags.zf)
    {
        goto L_0x00441e0a;
    }
    // 00441dfb  bbfa000000             -mov ebx, 0xfa
    cpu.ebx = 250 /*0xfa*/;
    // 00441e00  ba9c010000             -mov edx, 0x19c
    cpu.edx = 412 /*0x19c*/;
    // 00441e05  e8e6d50a00             -call 0x4ef3f0
    cpu.esp -= 4;
    sub_4ef3f0(app, cpu);
    if (cpu.terminate) return;
L_0x00441e0a:
    // 00441e0a  a1285c5500             -mov eax, dword ptr [0x555c28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */);
    // 00441e0f  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00441e12  8b354cbb6f00           -mov esi, dword ptr [0x6fbb4c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 00441e18  8b885c575500           -mov ecx, dword ptr [eax + 0x55575c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5592924) /* 0x55575c */);
    // 00441e1e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00441e20  0f8462010000           -je 0x441f88
    if (cpu.flags.zf)
    {
        goto L_0x00441f88;
    }
    // 00441e26  a1405c5500             -mov eax, dword ptr [0x555c40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594176) /* 0x555c40 */);
    // 00441e2b  e8f0d60a00             -call 0x4ef520
    cpu.esp -= 4;
    sub_4ef520(app, cpu);
    if (cpu.terminate) return;
    // 00441e30  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00441e32  eb05                   -jmp 0x441e39
    goto L_0x00441e39;
L_0x00441e34:
    // 00441e34  83ff05                 +cmp edi, 5
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441e37  7d6b                   -jge 0x441ea4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00441ea4;
    }
L_0x00441e39:
    // 00441e39  8d87c8010000           -lea eax, [edi + 0x1c8]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(456) /* 0x1c8 */);
    // 00441e3f  e80cfa0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00441e44  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00441e46  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441e48  e813d90a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00441e4d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00441e4f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441e51  e80ad90a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00441e56  e8d5d90a00             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 00441e5b  8d043f                 -lea eax, [edi + edi]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 1);
    // 00441e5e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00441e60  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00441e63  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00441e65  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00441e68  8d587e                 -lea ebx, [eax + 0x7e]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(126) /* 0x7e */);
    // 00441e6b  ba33000000             -mov edx, 0x33
    cpu.edx = 51 /*0x33*/;
    // 00441e70  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00441e72  e8b9df0a00             -call 0x4efe30
    cpu.esp -= 4;
    sub_4efe30(app, cpu);
    if (cpu.terminate) return;
    // 00441e77  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441e79  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00441e7c  e8dfd80a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00441e81  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00441e83  b840e4ff00             -mov eax, 0xffe440
    cpu.eax = 16770112 /*0xffe440*/;
    // 00441e88  83c37d                 +add ebx, 0x7d
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(125 /*0x7d*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00441e8b  e8d0d80a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00441e90  e89bd90a00             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 00441e95  ba32000000             -mov edx, 0x32
    cpu.edx = 50 /*0x32*/;
    // 00441e9a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00441e9c  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00441e9d  e88edf0a00             -call 0x4efe30
    cpu.esp -= 4;
    sub_4efe30(app, cpu);
    if (cpu.terminate) return;
    // 00441ea2  eb90                   -jmp 0x441e34
    goto L_0x00441e34;
L_0x00441ea4:
    // 00441ea4  a13c5c5500             -mov eax, dword ptr [0x555c3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594172) /* 0x555c3c */);
    // 00441ea9  e872d60a00             -call 0x4ef520
    cpu.esp -= 4;
    sub_4ef520(app, cpu);
    if (cpu.terminate) return;
    // 00441eae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441eb0  e8abd80a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00441eb5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00441eb7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441eb9  bb65000000             -mov ebx, 0x65
    cpu.ebx = 101 /*0x65*/;
    // 00441ebe  e89dd80a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00441ec3  e868d90a00             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 00441ec8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00441eca  ba33000000             -mov edx, 0x33
    cpu.edx = 51 /*0x33*/;
    // 00441ecf  e87cf90800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00441ed4  e857df0a00             -call 0x4efe30
    cpu.esp -= 4;
    sub_4efe30(app, cpu);
    if (cpu.terminate) return;
    // 00441ed9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441edb  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00441edd  e87ed80a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00441ee2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00441ee4  b840dfff00             -mov eax, 0xffdf40
    cpu.eax = 16768832 /*0xffdf40*/;
    // 00441ee9  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 00441eee  e86dd80a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00441ef3  e838d90a00             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 00441ef8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00441efa  ba32000000             -mov edx, 0x32
    cpu.edx = 50 /*0x32*/;
    // 00441eff  e84cf90800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00441f04  e827df0a00             -call 0x4efe30
    cpu.esp -= 4;
    sub_4efe30(app, cpu);
    if (cpu.terminate) return;
    // 00441f09  eb09                   -jmp 0x441f14
    goto L_0x00441f14;
L_0x00441f0b:
    // 00441f0b  83fe05                 +cmp esi, 5
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
    // 00441f0e  0f8da4020000           -jge 0x4421b8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004421b8;
    }
L_0x00441f14:
    // 00441f14  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 00441f17  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00441f19  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00441f1c  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00441f1e  8d838a000000           -lea eax, [ebx + 0x8a]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(138) /* 0x8a */);
    // 00441f24  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00441f27  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441f29  e832d80a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00441f2e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00441f30  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441f32  e829d80a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00441f37  e8f4d80a00             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 00441f3c  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00441f3f  8d3c30                 -lea edi, [eax + esi]
    cpu.edi = x86::reg32(cpu.eax + cpu.esi * 1);
    // 00441f42  81c38b000000           -add ebx, 0x8b
    (cpu.ebx) += x86::reg32(x86::sreg32(139 /*0x8b*/));
    // 00441f48  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00441f4a  ba51000000             -mov edx, 0x51
    cpu.edx = 81 /*0x51*/;
    // 00441f4f  e8fcf80800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00441f54  e8d7de0a00             -call 0x4efe30
    cpu.esp -= 4;
    sub_4efe30(app, cpu);
    if (cpu.terminate) return;
    // 00441f59  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00441f5b  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00441f5c  e8ffd70a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00441f61  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00441f63  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
    // 00441f68  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00441f6b  e8f0d70a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00441f70  e8bbd80a00             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 00441f75  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00441f77  ba50000000             -mov edx, 0x50
    cpu.edx = 80 /*0x50*/;
    // 00441f7c  e8cff80800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00441f81  e8aade0a00             -call 0x4efe30
    cpu.esp -= 4;
    sub_4efe30(app, cpu);
    if (cpu.terminate) return;
    // 00441f86  eb83                   -jmp 0x441f0b
    goto L_0x00441f0b;
L_0x00441f88:
    // 00441f88  a1405c5500             -mov eax, dword ptr [0x555c40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594176) /* 0x555c40 */);
    // 00441f8d  e88ed50a00             -call 0x4ef520
    cpu.esp -= 4;
    sub_4ef520(app, cpu);
    if (cpu.terminate) return;
    // 00441f92  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00441f94  eb09                   -jmp 0x441f9f
    goto L_0x00441f9f;
L_0x00441f96:
    // 00441f96  83ff05                 +cmp edi, 5
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441f99  0f8d83000000           -jge 0x442022
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00442022;
    }
L_0x00441f9f:
    // 00441f9f  8d87c8010000           -lea eax, [edi + 0x1c8]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(456) /* 0x1c8 */);
    // 00441fa5  e8a6f80800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00441faa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00441fac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441fae  e8add70a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00441fb3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00441fb5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441fb7  e8a4d70a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00441fbc  e86fd80a00             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 00441fc1  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 00441fc8  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00441fca  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00441fcd  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00441fcf  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00441fd2  8d988d000000           -lea ebx, [eax + 0x8d]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(141) /* 0x8d */);
    // 00441fd8  ba33000000             -mov edx, 0x33
    cpu.edx = 51 /*0x33*/;
    // 00441fdd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00441fdf  e84cde0a00             -call 0x4efe30
    cpu.esp -= 4;
    sub_4efe30(app, cpu);
    if (cpu.terminate) return;
    // 00441fe4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441fe6  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00441fe9  e872d70a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00441fee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00441ff0  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
    // 00441ff5  81c38c000000           +add ebx, 0x8c
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(140 /*0x8c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00441ffb  e860d70a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00442000  e82bd80a00             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 00442005  ba32000000             -mov edx, 0x32
    cpu.edx = 50 /*0x32*/;
    // 0044200a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044200c  e81fde0a00             -call 0x4efe30
    cpu.esp -= 4;
    sub_4efe30(app, cpu);
    if (cpu.terminate) return;
    // 00442011  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00442013  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00442014  e8d7de0a00             -call 0x4efef0
    cpu.esp -= 4;
    sub_4efef0(app, cpu);
    if (cpu.terminate) return;
    // 00442019  8944bdbc               -mov dword ptr [ebp + edi*4 - 0x44], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */ + cpu.edi * 4) = cpu.eax;
    // 0044201d  e974ffffff             -jmp 0x441f96
    goto L_0x00441f96;
L_0x00442022:
    // 00442022  a13c5c5500             -mov eax, dword ptr [0x555c3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594172) /* 0x555c3c */);
    // 00442027  e8f4d40a00             -call 0x4ef520
    cpu.esp -= 4;
    sub_4ef520(app, cpu);
    if (cpu.terminate) return;
    // 0044202c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044202e  e82dd70a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00442033  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00442035  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00442037  bb74000000             -mov ebx, 0x74
    cpu.ebx = 116 /*0x74*/;
    // 0044203c  e81fd70a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00442041  e8ead70a00             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 00442046  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442048  ba33000000             -mov edx, 0x33
    cpu.edx = 51 /*0x33*/;
    // 0044204d  e8fef70800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00442052  e8d9dd0a00             -call 0x4efe30
    cpu.esp -= 4;
    sub_4efe30(app, cpu);
    if (cpu.terminate) return;
    // 00442057  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00442059  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0044205b  e800d70a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00442060  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00442062  b840dfff00             -mov eax, 0xffdf40
    cpu.eax = 16768832 /*0xffdf40*/;
    // 00442067  bb73000000             -mov ebx, 0x73
    cpu.ebx = 115 /*0x73*/;
    // 0044206c  e8efd60a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00442071  e8bad70a00             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 00442076  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442078  ba32000000             -mov edx, 0x32
    cpu.edx = 50 /*0x32*/;
    // 0044207d  e8cef70800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00442082  e8a9dd0a00             -call 0x4efe30
    cpu.esp -= 4;
    sub_4efe30(app, cpu);
    if (cpu.terminate) return;
    // 00442087  eb09                   -jmp 0x442092
    goto L_0x00442092;
L_0x00442089:
    // 00442089  83fe05                 +cmp esi, 5
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
    // 0044208c  0f8d26010000           -jge 0x4421b8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004421b8;
    }
L_0x00442092:
    // 00442092  8b44b5c0               -mov eax, dword ptr [ebp + esi*4 - 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */ + cpu.esi * 4);
    // 00442096  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00442099  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 0044209c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044209e  e8bdd60a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 004420a3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004420a5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004420a7  e8b4d60a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 004420ac  e87fd70a00             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 004420b1  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004420b8  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004420ba  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004420bd  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004420bf  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 004420c2  8d988d000000           -lea ebx, [eax + 0x8d]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(141) /* 0x8d */);
    // 004420c8  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004420cb  8d3c30                 -lea edi, [eax + esi]
    cpu.edi = x86::reg32(cpu.eax + cpu.esi * 1);
    // 004420ce  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004420d1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004420d3  42                     -inc edx
    (cpu.edx)++;
    // 004420d4  e877f70800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004420d9  e852dd0a00             -call 0x4efe30
    cpu.esp -= 4;
    sub_4efe30(app, cpu);
    if (cpu.terminate) return;
    // 004420de  46                     -inc esi
    (cpu.esi)++;
    // 004420df  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004420e1  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004420e4  e877d60a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 004420e9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004420eb  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
    // 004420f0  81c38c000000           +add ebx, 0x8c
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(140 /*0x8c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004420f6  e865d60a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 004420fb  e830d70a00             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 00442100  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00442102  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00442105  e846f70800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044210a  e821dd0a00             -call 0x4efe30
    cpu.esp -= 4;
    sub_4efe30(app, cpu);
    if (cpu.terminate) return;
    // 0044210f  e975ffffff             -jmp 0x442089
    goto L_0x00442089;
  case 0x00442114:
    // 00442114  8b3d54575500           -mov edi, dword ptr [0x555754]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5592916) /* 0x555754 */);
    // 0044211a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0044211c  0f8496000000           -je 0x4421b8
    if (cpu.flags.zf)
    {
        goto L_0x004421b8;
    }
    // 00442122  ba907b5300             -mov edx, 0x537b90
    cpu.edx = 5471120 /*0x537b90*/;
    // 00442127  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00442129  e8b2d00a00             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 0044212e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00442130  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00442133  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 00442138  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044213b  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0044213d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044213f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00442142  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00442144  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00442146  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00442148  8b4102                 -mov eax, dword ptr [ecx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0044214b  ba60020000             -mov edx, 0x260
    cpu.edx = 608 /*0x260*/;
    // 00442150  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00442153  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00442155  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00442157  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0044215a  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044215c  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0044215e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00442160  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442162  e889d20a00             -call 0x4ef3f0
    cpu.esp -= 4;
    sub_4ef3f0(app, cpu);
    if (cpu.terminate) return;
    // 00442167  a1285c5500             -mov eax, dword ptr [0x555c28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */);
    // 0044216c  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044216f  8b9064575500           -mov edx, dword ptr [eax + 0x555764]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5592932) /* 0x555764 */);
    // 00442175  a154575500             -mov eax, dword ptr [0x555754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592916) /* 0x555754 */);
    // 0044217a  e861d00a00             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 0044217f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00442181  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00442184  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 00442189  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044218c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0044218e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00442190  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00442193  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00442195  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00442197  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00442199  8b4102                 -mov eax, dword ptr [ecx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0044219c  ba60020000             -mov edx, 0x260
    cpu.edx = 608 /*0x260*/;
    // 004421a1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004421a4  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004421a6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004421a8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004421ab  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004421ad  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004421af  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004421b1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004421b3  e838d20a00             -call 0x4ef3f0
    cpu.esp -= 4;
    sub_4ef3f0(app, cpu);
    if (cpu.terminate) return;
L_0x004421b8:
    // 004421b8  e8d38b0a00             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 004421bd  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004421c0  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004421c3  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004421c6  e8c5410900             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 004421cb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004421cd  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004421d0  e82bdd0a00             -call 0x4eff00
    cpu.esp -= 4;
    sub_4eff00(app, cpu);
    if (cpu.terminate) return;
    // 004421d5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004421d7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004421d9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004421da  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004421db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004421dc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004421dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004421de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004421df  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004421e0:
    // 004421e0  be14000000             -mov esi, 0x14
    cpu.esi = 20 /*0x14*/;
    // 004421e5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004421e7  8bb85c575500           -mov edi, dword ptr [eax + 0x55575c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5592924) /* 0x55575c */);
    // 004421ed  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
L_0x004421f0:
    // 004421f0  a1285c5500             -mov eax, dword ptr [0x555c28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */);
    // 004421f5  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004421f8  3bb860575500           +cmp edi, dword ptr [eax + 0x555760]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5592928) /* 0x555760 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004421fe  7fb8                   -jg 0x4421b8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004421b8;
    }
    // 00442200  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00442202  bbffffff00             -mov ebx, 0xffffff
    cpu.ebx = 16777215 /*0xffffff*/;
    // 00442207  e844f60800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044220c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044220e  a13c5c5500             -mov eax, dword ptr [0x555c3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594172) /* 0x555c3c */);
    // 00442213  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00442216  e805d30a00             -call 0x4ef520
    cpu.esp -= 4;
    sub_4ef520(app, cpu);
    if (cpu.terminate) return;
    // 0044221b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044221d  bb1e000000             -mov ebx, 0x1e
    cpu.ebx = 30 /*0x1e*/;
    // 00442222  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
L_0x00442225:
    // 00442225  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00442227  80fa23                 +cmp dl, 0x23
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(35 /*0x23*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044222a  740a                   -je 0x442236
    if (cpu.flags.zf)
    {
        goto L_0x00442236;
    }
    // 0044222c  80fa40                 +cmp dl, 0x40
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(64 /*0x40*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044222f  7405                   -je 0x442236
    if (cpu.flags.zf)
    {
        goto L_0x00442236;
    }
    // 00442231  80fa24                 +cmp dl, 0x24
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(36 /*0x24*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00442234  753b                   -jne 0x442271
    if (!cpu.flags.zf)
    {
        goto L_0x00442271;
    }
L_0x00442236:
    // 00442236  803924                 +cmp byte ptr [ecx], 0x24
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(36 /*0x24*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00442239  750d                   -jne 0x442248
    if (!cpu.flags.zf)
    {
        goto L_0x00442248;
    }
    // 0044223b  ba30010000             -mov edx, 0x130
    cpu.edx = 304 /*0x130*/;
    // 00442240  be14000000             -mov esi, 0x14
    cpu.esi = 20 /*0x14*/;
    // 00442245  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
L_0x00442248:
    // 00442248  803923                 +cmp byte ptr [ecx], 0x23
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(35 /*0x23*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044224b  7512                   -jne 0x44225f
    if (!cpu.flags.zf)
    {
        goto L_0x0044225f;
    }
    // 0044224d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00442252  b840e4ff00             -mov eax, 0xffe440
    cpu.eax = 16770112 /*0xffe440*/;
    // 00442257  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 0044225a  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0044225d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0044225f:
    // 0044225f  803940                 +cmp byte ptr [ecx], 0x40
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(64 /*0x40*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00442262  750a                   -jne 0x44226e
    if (!cpu.flags.zf)
    {
        goto L_0x0044226e;
    }
    // 00442264  ba40e4ff00             -mov edx, 0xffe440
    cpu.edx = 16770112 /*0xffe440*/;
    // 00442269  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0044226b  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
L_0x0044226e:
    // 0044226e  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044226f  ebb4                   -jmp 0x442225
    goto L_0x00442225;
L_0x00442271:
    // 00442271  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00442273  e8e8d40a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00442278  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044227a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044227c  e8dfd40a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00442281  e8aad50a00             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 00442286  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00442289  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0044228b  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 0044228e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00442290  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00442292  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442294  e897db0a00             -call 0x4efe30
    cpu.esp -= 4;
    sub_4efe30(app, cpu);
    if (cpu.terminate) return;
    // 00442299  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044229b  e8c0d40a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 004422a0  8d5e01                 -lea ebx, [esi + 1]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004422a3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004422a5  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004422a8  83c614                 -add esi, 0x14
    (cpu.esi) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004422ab  e8b0d40a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 004422b0  e87bd50a00             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 004422b5  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004422b8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004422ba  42                     -inc edx
    (cpu.edx)++;
    // 004422bb  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004422be  e86ddb0a00             -call 0x4efe30
    cpu.esp -= 4;
    sub_4efe30(app, cpu);
    if (cpu.terminate) return;
    // 004422c3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004422c5  7403                   -je 0x4422ca
    if (cpu.flags.zf)
    {
        goto L_0x004422ca;
    }
    // 004422c7  83c614                 +add esi, 0x14
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004422ca:
    // 004422ca  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004422cb  e920ffffff             -jmp 0x4421f0
    goto L_0x004421f0;
  case 0x004422d0:
    // 004422d0  be14000000             -mov esi, 0x14
    cpu.esi = 20 /*0x14*/;
    // 004422d5  8bb85c575500           -mov edi, dword ptr [eax + 0x55575c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5592924) /* 0x55575c */);
L_0x004422db:
    // 004422db  a1285c5500             -mov eax, dword ptr [0x555c28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */);
    // 004422e0  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004422e3  3bb860575500           +cmp edi, dword ptr [eax + 0x555760]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5592928) /* 0x555760 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004422e9  0f8fc9feffff           -jg 0x4421b8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004421b8;
    }
    // 004422ef  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004422f1  e85af50800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004422f6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004422f8  a13c5c5500             -mov eax, dword ptr [0x555c3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594172) /* 0x555c3c */);
    // 004422fd  e81ed20a00             -call 0x4ef520
    cpu.esp -= 4;
    sub_4ef520(app, cpu);
    if (cpu.terminate) return;
    // 00442302  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442304  e8e7db0a00             -call 0x4efef0
    cpu.esp -= 4;
    sub_4efef0(app, cpu);
    if (cpu.terminate) return;
    // 00442309  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044230b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0044230e  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00442310  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00442312  ba30010000             -mov edx, 0x130
    cpu.edx = 304 /*0x130*/;
    // 00442317  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00442319  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044231b  8955e4                 -mov dword ptr [ebp - 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edx;
    // 0044231e  e83dd40a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00442323  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00442325  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00442327  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00442329  e832d40a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 0044232e  e8fdd40a00             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 00442333  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00442336  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442338  e8f3da0a00             -call 0x4efe30
    cpu.esp -= 4;
    sub_4efe30(app, cpu);
    if (cpu.terminate) return;
    // 0044233d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044233f  47                     -inc edi
    (cpu.edi)++;
    // 00442340  e81bd40a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00442345  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00442347  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
    // 0044234c  8d5e01                 -lea ebx, [esi + 1]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044234f  e80cd40a00             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00442354  e8d7d40a00             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 00442359  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0044235c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044235e  42                     -inc edx
    (cpu.edx)++;
    // 0044235f  83c614                 +add esi, 0x14
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00442362  e8c9da0a00             -call 0x4efe30
    cpu.esp -= 4;
    sub_4efe30(app, cpu);
    if (cpu.terminate) return;
    // 00442367  e96fffffff             -jmp 0x4422db
    goto L_0x004422db;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_442370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442370  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00442371  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00442372  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442373  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442375  833dc0405f0004         +cmp dword ptr [0x5f40c0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6242496) /* 0x5f40c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044237c  754f                   -jne 0x4423cd
    if (!cpu.flags.zf)
    {
        goto L_0x004423cd;
    }
    // 0044237e  8b0d285c5500           -mov ecx, dword ptr [0x555c28]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */);
    // 00442384  41                     -inc ecx
    (cpu.ecx)++;
    // 00442385  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442387  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044238a  8b985c575500           -mov ebx, dword ptr [eax + 0x55575c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5592924) /* 0x55575c */);
    // 00442390  890d285c5500           -mov dword ptr [0x555c28], ecx
    app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */) = cpu.ecx;
    // 00442396  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00442398  7506                   -jne 0x4423a0
    if (!cpu.flags.zf)
    {
        goto L_0x004423a0;
    }
    // 0044239a  891d285c5500           -mov dword ptr [0x555c28], ebx
    app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */) = cpu.ebx;
L_0x004423a0:
    // 004423a0  e83b79ffff             -call 0x439ce0
    cpu.esp -= 4;
    sub_439ce0(app, cpu);
    if (cpu.terminate) return;
    // 004423a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004423a7  751a                   -jne 0x4423c3
    if (!cpu.flags.zf)
    {
        goto L_0x004423c3;
    }
    // 004423a9  a1285c5500             -mov eax, dword ptr [0x555c28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */);
    // 004423ae  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004423b1  81b85c5755006a040000   +cmp dword ptr [eax + 0x55575c], 0x46a
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5592924) /* 0x55575c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1130 /*0x46a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004423bb  7506                   -jne 0x4423c3
    if (!cpu.flags.zf)
    {
        goto L_0x004423c3;
    }
    // 004423bd  ff05285c5500           -inc dword ptr [0x555c28]
    (app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */))++;
L_0x004423c3:
    // 004423c3  c705c0405f0002000000   -mov dword ptr [0x5f40c0], 2
    app->getMemory<x86::reg32>(x86::reg32(6242496) /* 0x5f40c0 */) = 2 /*0x2*/;
L_0x004423cd:
    // 004423cd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004423cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004423d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004423d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004423d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4423e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004423e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004423e1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004423e2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004423e4  8b15285c5500           -mov edx, dword ptr [0x555c28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */);
    // 004423ea  833dc0405f0004         +cmp dword ptr [0x5f40c0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6242496) /* 0x5f40c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004423f1  754a                   -jne 0x44243d
    if (!cpu.flags.zf)
    {
        goto L_0x0044243d;
    }
    // 004423f3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004423f5  742a                   -je 0x442421
    if (cpu.flags.zf)
    {
        goto L_0x00442421;
    }
    // 004423f7  4a                     -dec edx
    (cpu.edx)--;
    // 004423f8  8915285c5500           -mov dword ptr [0x555c28], edx
    app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */) = cpu.edx;
    // 004423fe  e8dd78ffff             -call 0x439ce0
    cpu.esp -= 4;
    sub_439ce0(app, cpu);
    if (cpu.terminate) return;
    // 00442403  8b15285c5500           -mov edx, dword ptr [0x555c28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */);
    // 00442409  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044240b  7526                   -jne 0x442433
    if (!cpu.flags.zf)
    {
        goto L_0x00442433;
    }
    // 0044240d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044240f  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00442412  81b85c5755006a040000   +cmp dword ptr [eax + 0x55575c], 0x46a
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5592924) /* 0x55575c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1130 /*0x46a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044241c  7515                   -jne 0x442433
    if (!cpu.flags.zf)
    {
        goto L_0x00442433;
    }
    // 0044241e  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044241f  eb12                   -jmp 0x442433
    goto L_0x00442433;
L_0x00442421:
    // 00442421  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00442423  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00442426  83b85c57550000         +cmp dword ptr [eax + 0x55575c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5592924) /* 0x55575c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044242d  7403                   -je 0x442432
    if (cpu.flags.zf)
    {
        goto L_0x00442432;
    }
    // 0044242f  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00442430  ebef                   -jmp 0x442421
    goto L_0x00442421;
L_0x00442432:
    // 00442432  4a                     -dec edx
    (cpu.edx)--;
L_0x00442433:
    // 00442433  c705c0405f0003000000   -mov dword ptr [0x5f40c0], 3
    app->getMemory<x86::reg32>(x86::reg32(6242496) /* 0x5f40c0 */) = 3 /*0x3*/;
L_0x0044243d:
    // 0044243d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044243f  8915285c5500           -mov dword ptr [0x555c28], edx
    app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */) = cpu.edx;
    // 00442445  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442446  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442447  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_442450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442450  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00442451  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00442452  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442453  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00442454  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442455  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
L_0x00442457:
    // 00442457  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 0044245c  8b15c4405f00           -mov edx, dword ptr [0x5f40c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6242500) /* 0x5f40c4 */);
    // 00442462  83c205                 -add edx, 5
    (cpu.edx) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 00442465  39d0                   +cmp eax, edx
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
    // 00442467  7d02                   -jge 0x44246b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044246b;
    }
    // 00442469  ebec                   -jmp 0x442457
    goto L_0x00442457;
L_0x0044246b:
    // 0044246b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044246d  a3c4405f00             -mov dword ptr [0x5f40c4], eax
    app->getMemory<x86::reg32>(x86::reg32(6242500) /* 0x5f40c4 */) = cpu.eax;
    // 00442472  8a25583a7a00           -mov ah, byte ptr [0x7a3a58]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */);
    // 00442478  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 0044247b  0f85bc000000           -jne 0x44253d
    if (!cpu.flags.zf)
    {
        goto L_0x0044253d;
    }
    // 00442481  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 00442484  0f85b3000000           -jne 0x44253d
    if (!cpu.flags.zf)
    {
        goto L_0x0044253d;
    }
    // 0044248a  a1345c5500             -mov eax, dword ptr [0x555c34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594164) /* 0x555c34 */);
    // 0044248f  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00442492  8b9058575500           -mov edx, dword ptr [eax + 0x555758]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5592920) /* 0x555758 */);
    // 00442498  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044249a  7409                   -je 0x4424a5
    if (cpu.flags.zf)
    {
        goto L_0x004424a5;
    }
    // 0044249c  83fa01                 +cmp edx, 1
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
    // 0044249f  0f8598000000           -jne 0x44253d
    if (!cpu.flags.zf)
    {
        goto L_0x0044253d;
    }
L_0x004424a5:
    // 004424a5  833dc0405f0003         +cmp dword ptr [0x5f40c0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6242496) /* 0x5f40c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004424ac  7540                   -jne 0x4424ee
    if (!cpu.flags.zf)
    {
        goto L_0x004424ee;
    }
    // 004424ae  a12c5c5500             -mov eax, dword ptr [0x555c2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594156) /* 0x555c2c */);
    // 004424b3  8b1d2c5c5500           -mov ebx, dword ptr [0x555c2c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5594156) /* 0x555c2c */);
    // 004424b9  2d12010000             -sub eax, 0x112
    (cpu.eax) -= x86::reg32(x86::sreg32(274 /*0x112*/));
    // 004424be  83c32e                 -add ebx, 0x2e
    (cpu.ebx) += x86::reg32(x86::sreg32(46 /*0x2e*/));
    // 004424c1  83f82e                 +cmp eax, 0x2e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004424c4  7d05                   -jge 0x4424cb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004424cb;
    }
    // 004424c6  b82e000000             -mov eax, 0x2e
    cpu.eax = 46 /*0x2e*/;
L_0x004424cb:
    // 004424cb  68a0606010             -push 0x106060a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 274751648 /*0x106060a0*/;
    cpu.esp -= 4;
    // 004424d0  68a06060ff             -push 0xff6060a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4284506272 /*0xff6060a0*/;
    cpu.esp -= 4;
    // 004424d5  68a06060ff             -push 0xff6060a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4284506272 /*0xff6060a0*/;
    cpu.esp -= 4;
    // 004424da  68a0606010             -push 0x106060a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 274751648 /*0x106060a0*/;
    cpu.esp -= 4;
    // 004424df  b965010000             -mov ecx, 0x165
    cpu.ecx = 357 /*0x165*/;
    // 004424e4  ba49000000             -mov edx, 0x49
    cpu.edx = 73 /*0x49*/;
    // 004424e9  e802640900             -call 0x4d88f0
    cpu.esp -= 4;
    sub_4d88f0(app, cpu);
    if (cpu.terminate) return;
L_0x004424ee:
    // 004424ee  833dc0405f0002         +cmp dword ptr [0x5f40c0], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6242496) /* 0x5f40c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004424f5  7546                   -jne 0x44253d
    if (!cpu.flags.zf)
    {
        goto L_0x0044253d;
    }
    // 004424f7  8b1d2c5c5500           -mov ebx, dword ptr [0x555c2c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5594156) /* 0x555c2c */);
    // 004424fd  a12c5c5500             -mov eax, dword ptr [0x555c2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594156) /* 0x555c2c */);
    // 00442502  81c392030000           -add ebx, 0x392
    (cpu.ebx) += x86::reg32(x86::sreg32(914 /*0x392*/));
    // 00442508  0552020000             -add eax, 0x252
    (cpu.eax) += x86::reg32(x86::sreg32(594 /*0x252*/));
    // 0044250d  81fb52020000           +cmp ebx, 0x252
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(594 /*0x252*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442513  7e05                   -jle 0x44251a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044251a;
    }
    // 00442515  bb52020000             -mov ebx, 0x252
    cpu.ebx = 594 /*0x252*/;
L_0x0044251a:
    // 0044251a  68a06060ff             -push 0xff6060a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4284506272 /*0xff6060a0*/;
    cpu.esp -= 4;
    // 0044251f  68a0606010             -push 0x106060a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 274751648 /*0x106060a0*/;
    cpu.esp -= 4;
    // 00442524  68a0606010             -push 0x106060a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 274751648 /*0x106060a0*/;
    cpu.esp -= 4;
    // 00442529  68a06060ff             -push 0xff6060a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4284506272 /*0xff6060a0*/;
    cpu.esp -= 4;
    // 0044252e  b965010000             -mov ecx, 0x165
    cpu.ecx = 357 /*0x165*/;
    // 00442533  ba49000000             -mov edx, 0x49
    cpu.edx = 73 /*0x49*/;
    // 00442538  e8b3630900             -call 0x4d88f0
    cpu.esp -= 4;
    sub_4d88f0(app, cpu);
    if (cpu.terminate) return;
L_0x0044253d:
    // 0044253d  8b3d385c5500           -mov edi, dword ptr [0x555c38]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5594168) /* 0x555c38 */);
    // 00442543  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00442545  7415                   -je 0x44255c
    if (cpu.flags.zf)
    {
        goto L_0x0044255c;
    }
    // 00442547  bb39000000             -mov ebx, 0x39
    cpu.ebx = 57 /*0x39*/;
    // 0044254c  8b152c5c5500           -mov edx, dword ptr [0x555c2c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5594156) /* 0x555c2c */);
    // 00442552  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00442554  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00442557  e834540900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
L_0x0044255c:
    // 0044255c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044255e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044255f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442560  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442561  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442562  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442563  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_442580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00442580  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00442581  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00442582  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442583  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00442584  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00442585  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442586  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442588  81ec14010000           -sub esp, 0x114
    (cpu.esp) -= x86::reg32(x86::sreg32(276 /*0x114*/));
    // 0044258e  8b35305c5500           -mov esi, dword ptr [0x555c30]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5594160) /* 0x555c30 */);
    // 00442594  8b3d2c5c5500           -mov edi, dword ptr [0x555c2c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5594156) /* 0x555c2c */);
    // 0044259a  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0044259d  833d5457550000         +cmp dword ptr [0x555754], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5592916) /* 0x555754 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004425a4  7535                   -jne 0x4425db
    if (!cpu.flags.zf)
    {
        goto L_0x004425db;
    }
    // 004425a6  68b42d7a00             -push 0x7a2db4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007092 /*0x7a2db4*/;
    cpu.esp -= 4;
    // 004425ab  68b07b5300             -push 0x537bb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5471152 /*0x537bb0*/;
    cpu.esp -= 4;
    // 004425b0  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 004425b6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004425b7  e8d4d00900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004425bc  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004425bf  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 004425c5  e8c6860000             -call 0x44ac90
    cpu.esp -= 4;
    sub_44ac90(app, cpu);
    if (cpu.terminate) return;
    // 004425ca  a354575500             -mov dword ptr [0x555754], eax
    app->getMemory<x86::reg32>(x86::reg32(5592916) /* 0x555754 */) = cpu.eax;
    // 004425cf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004425d1  e8daf6ffff             -call 0x441cb0
    cpu.esp -= 4;
    sub_441cb0(app, cpu);
    if (cpu.terminate) return;
    // 004425d6  a3385c5500             -mov dword ptr [0x555c38], eax
    app->getMemory<x86::reg32>(x86::reg32(5594168) /* 0x555c38 */) = cpu.eax;
L_0x004425db:
    // 004425db  8d5df4                 -lea ebx, [ebp - 0xc]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004425de  8d55f0                 -lea edx, [ebp - 0x10]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004425e1  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004425e4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004425e6  e8252dffff             -call 0x435310
    cpu.esp -= 4;
    sub_435310(app, cpu);
    if (cpu.terminate) return;
    // 004425eb  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004425ee  668b501a               -mov dx, word ptr [eax + 0x1a]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */);
    // 004425f2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004425f4  6683fa64               +cmp dx, 0x64
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004425f8  0f847a000000           -je 0x442678
    if (cpu.flags.zf)
    {
        goto L_0x00442678;
    }
    // 004425fe  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00442601  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00442604  8b5216                 -mov edx, dword ptr [edx + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(22) /* 0x16 */);
    // 00442607  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044260a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044260d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044260f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00442611  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00442614  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00442616  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00442619  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044261b  bae04e6000             -mov edx, 0x604ee0
    cpu.edx = 6311648 /*0x604ee0*/;
    // 00442620  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00442623  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00442625  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00442628  833a05                 +cmp dword ptr [edx], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044262b  754b                   -jne 0x442678
    if (!cpu.flags.zf)
    {
        goto L_0x00442678;
    }
    // 0044262d  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00442630  babc7b5300             -mov edx, 0x537bbc
    cpu.edx = 5471164 /*0x537bbc*/;
    // 00442635  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00442638  e883030000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 0044263d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044263f  7514                   -jne 0x442655
    if (!cpu.flags.zf)
    {
        goto L_0x00442655;
    }
    // 00442641  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00442644  bac47b5300             -mov edx, 0x537bc4
    cpu.edx = 5471172 /*0x537bc4*/;
    // 00442649  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0044264c  e86f030000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 00442651  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00442653  7423                   -je 0x442678
    if (cpu.flags.zf)
    {
        goto L_0x00442678;
    }
L_0x00442655:
    // 00442655  8b3d2c5c5500           -mov edi, dword ptr [0x555c2c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5594156) /* 0x555c2c */);
    // 0044265b  8b35305c5500           -mov esi, dword ptr [0x555c30]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5594160) /* 0x555c30 */);
    // 00442661  837dec00               +cmp dword ptr [ebp - 0x14], 0
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
    // 00442665  7405                   -je 0x44266c
    if (cpu.flags.zf)
    {
        goto L_0x0044266c;
    }
    // 00442667  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x0044266c:
    // 0044266c  8935305c5500           -mov dword ptr [0x555c30], esi
    app->getMemory<x86::reg32>(x86::reg32(5594160) /* 0x555c30 */) = cpu.esi;
    // 00442672  893d2c5c5500           -mov dword ptr [0x555c2c], edi
    app->getMemory<x86::reg32>(x86::reg32(5594156) /* 0x555c2c */) = cpu.edi;
L_0x00442678:
    // 00442678  8b3d2c5c5500           -mov edi, dword ptr [0x555c2c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5594156) /* 0x555c2c */);
    // 0044267e  8b35305c5500           -mov esi, dword ptr [0x555c30]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5594160) /* 0x555c30 */);
    // 00442684  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00442686  740f                   -je 0x442697
    if (cpu.flags.zf)
    {
        goto L_0x00442697;
    }
    // 00442688  8b1d445c5500           -mov ebx, dword ptr [0x555c44]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5594180) /* 0x555c44 */);
    // 0044268e  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044268f  891d445c5500           -mov dword ptr [0x555c44], ebx
    app->getMemory<x86::reg32>(x86::reg32(5594180) /* 0x555c44 */) = cpu.ebx;
    // 00442695  eb08                   -jmp 0x44269f
    goto L_0x0044269f;
L_0x00442697:
    // 00442697  891d445c5500           -mov dword ptr [0x555c44], ebx
    app->getMemory<x86::reg32>(x86::reg32(5594180) /* 0x555c44 */) = cpu.ebx;
    // 0044269d  eb27                   -jmp 0x4426c6
    goto L_0x004426c6;
L_0x0044269f:
    // 0044269f  83fb0a                 +cmp ebx, 0xa
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004426a2  7e22                   -jle 0x4426c6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004426c6;
    }
    // 004426a4  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004426a7  babc7b5300             -mov edx, 0x537bbc
    cpu.edx = 5471164 /*0x537bbc*/;
    // 004426ac  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004426af  e80c030000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 004426b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004426b6  7409                   -je 0x4426c1
    if (cpu.flags.zf)
    {
        goto L_0x004426c1;
    }
    // 004426b8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004426ba  e8b1fcffff             -call 0x442370
    cpu.esp -= 4;
    sub_442370(app, cpu);
    if (cpu.terminate) return;
    // 004426bf  eb05                   -jmp 0x4426c6
    goto L_0x004426c6;
L_0x004426c1:
    // 004426c1  e81afdffff             -call 0x4423e0
    cpu.esp -= 4;
    sub_4423e0(app, cpu);
    if (cpu.terminate) return;
L_0x004426c6:
    // 004426c6  8b3d2c5c5500           -mov edi, dword ptr [0x555c2c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5594156) /* 0x555c2c */);
    // 004426cc  a1c0405f00             -mov eax, dword ptr [0x5f40c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242496) /* 0x5f40c0 */);
    // 004426d1  8b35305c5500           -mov esi, dword ptr [0x555c30]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5594160) /* 0x555c30 */);
    // 004426d7  83f803                 +cmp eax, 3
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
    // 004426da  0f874d010000           -ja 0x44282d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0044282d;
    }
    // 004426e0  ff248564254400         -jmp dword ptr [eax*4 + 0x442564]
    cpu.ip = app->getMemory<x86::reg32>(4466020 + cpu.eax * 4); goto dynamic_jump;
  case 0x004426e7:
    // 004426e7  81ff40fcffff           +cmp edi, 0xfffffc40
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294966336 /*0xfffffc40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004426ed  7f47                   -jg 0x442736
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00442736;
    }
    // 004426ef  8b0d285c5500           -mov ecx, dword ptr [0x555c28]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */);
    // 004426f5  a1345c5500             -mov eax, dword ptr [0x555c34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594164) /* 0x555c34 */);
    // 004426fa  8935305c5500           -mov dword ptr [0x555c30], esi
    app->getMemory<x86::reg32>(x86::reg32(5594160) /* 0x555c30 */) = cpu.esi;
    // 00442700  893d2c5c5500           -mov dword ptr [0x555c2c], edi
    app->getMemory<x86::reg32>(x86::reg32(5594156) /* 0x555c2c */) = cpu.edi;
    // 00442706  39c8                   +cmp eax, ecx
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
    // 00442708  7415                   -je 0x44271f
    if (cpu.flags.zf)
    {
        goto L_0x0044271f;
    }
    // 0044270a  a1385c5500             -mov eax, dword ptr [0x555c38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594168) /* 0x555c38 */);
    // 0044270f  890d345c5500           -mov dword ptr [0x555c34], ecx
    app->getMemory<x86::reg32>(x86::reg32(5594164) /* 0x555c34 */) = cpu.ecx;
    // 00442715  e896f5ffff             -call 0x441cb0
    cpu.esp -= 4;
    sub_441cb0(app, cpu);
    if (cpu.terminate) return;
    // 0044271a  a3385c5500             -mov dword ptr [0x555c38], eax
    app->getMemory<x86::reg32>(x86::reg32(5594168) /* 0x555c38 */) = cpu.eax;
L_0x0044271f:
    // 0044271f  bf80020000             -mov edi, 0x280
    cpu.edi = 640 /*0x280*/;
    // 00442724  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00442726  be3f000000             -mov esi, 0x3f
    cpu.esi = 63 /*0x3f*/;
    // 0044272b  891dc0405f00           -mov dword ptr [0x5f40c0], ebx
    app->getMemory<x86::reg32>(x86::reg32(6242496) /* 0x5f40c0 */) = cpu.ebx;
    // 00442731  e9f7000000             -jmp 0x44282d
    goto L_0x0044282d;
L_0x00442736:
    // 00442736  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00442738  7510                   -jne 0x44274a
    if (!cpu.flags.zf)
    {
        goto L_0x0044274a;
    }
    // 0044273a  833d445c55000a         +cmp dword ptr [0x555c44], 0xa
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5594180) /* 0x555c44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442741  7e07                   -jle 0x44274a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044274a;
    }
    // 00442743  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
    // 00442748  eb05                   -jmp 0x44274f
    goto L_0x0044274f;
L_0x0044274a:
    // 0044274a  83fe3c                 +cmp esi, 0x3c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044274d  7d03                   -jge 0x442752
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00442752;
    }
L_0x0044274f:
    // 0044274f  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x00442752:
    // 00442752  8b15445c5500           -mov edx, dword ptr [0x555c44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5594180) /* 0x555c44 */);
    // 00442758  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0044275a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044275c  0f84cb000000           -je 0x44282d
    if (cpu.flags.zf)
    {
        goto L_0x0044282d;
    }
    // 00442762  29f7                   +sub edi, esi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00442764  e9c4000000             -jmp 0x44282d
    goto L_0x0044282d;
  case 0x00442769:
    // 00442769  81ffc0030000           +cmp edi, 0x3c0
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(960 /*0x3c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044276f  7c3d                   -jl 0x4427ae
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004427ae;
    }
    // 00442771  8b0d285c5500           -mov ecx, dword ptr [0x555c28]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */);
    // 00442777  3b0d345c5500           +cmp ecx, dword ptr [0x555c34]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5594164) /* 0x555c34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044277d  7415                   -je 0x442794
    if (cpu.flags.zf)
    {
        goto L_0x00442794;
    }
    // 0044277f  a1385c5500             -mov eax, dword ptr [0x555c38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594168) /* 0x555c38 */);
    // 00442784  890d345c5500           -mov dword ptr [0x555c34], ecx
    app->getMemory<x86::reg32>(x86::reg32(5594164) /* 0x555c34 */) = cpu.ecx;
    // 0044278a  e821f5ffff             -call 0x441cb0
    cpu.esp -= 4;
    sub_441cb0(app, cpu);
    if (cpu.terminate) return;
    // 0044278f  a3385c5500             -mov dword ptr [0x555c38], eax
    app->getMemory<x86::reg32>(x86::reg32(5594168) /* 0x555c38 */) = cpu.eax;
L_0x00442794:
    // 00442794  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00442799  bf80fdffff             -mov edi, 0xfffffd80
    cpu.edi = 4294966656 /*0xfffffd80*/;
    // 0044279e  be3f000000             -mov esi, 0x3f
    cpu.esi = 63 /*0x3f*/;
    // 004427a3  891dc0405f00           -mov dword ptr [0x5f40c0], ebx
    app->getMemory<x86::reg32>(x86::reg32(6242496) /* 0x5f40c0 */) = cpu.ebx;
    // 004427a9  e97f000000             -jmp 0x44282d
    goto L_0x0044282d;
L_0x004427ae:
    // 004427ae  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004427b0  7510                   -jne 0x4427c2
    if (!cpu.flags.zf)
    {
        goto L_0x004427c2;
    }
    // 004427b2  833d445c550000         +cmp dword ptr [0x555c44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5594180) /* 0x555c44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004427b9  7407                   -je 0x4427c2
    if (cpu.flags.zf)
    {
        goto L_0x004427c2;
    }
    // 004427bb  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
    // 004427c0  eb05                   -jmp 0x4427c7
    goto L_0x004427c7;
L_0x004427c2:
    // 004427c2  83fe3c                 +cmp esi, 0x3c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004427c5  7d03                   -jge 0x4427ca
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004427ca;
    }
L_0x004427c7:
    // 004427c7  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004427ca:
    // 004427ca  8b15445c5500           -mov edx, dword ptr [0x555c44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5594180) /* 0x555c44 */);
    // 004427d0  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004427d2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004427d4  7457                   -je 0x44282d
    if (cpu.flags.zf)
    {
        goto L_0x0044282d;
    }
    // 004427d6  01f7                   +add edi, esi
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
    // 004427d8  eb53                   -jmp 0x44282d
    goto L_0x0044282d;
  case 0x004427da:
    // 004427da  83fe03                 +cmp esi, 3
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004427dd  7e03                   -jle 0x4427e2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004427e2;
    }
    // 004427df  83ee03                 -sub esi, 3
    (cpu.esi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004427e2:
    // 004427e2  8b0d445c5500           -mov ecx, dword ptr [0x555c44]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5594180) /* 0x555c44 */);
    // 004427e8  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004427ea  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004427ec  7402                   -je 0x4427f0
    if (cpu.flags.zf)
    {
        goto L_0x004427f0;
    }
    // 004427ee  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004427f0:
    // 004427f0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004427f2  7f39                   -jg 0x44282d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0044282d;
    }
    // 004427f4  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004427f9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004427fb  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004427fd  891dc0405f00           -mov dword ptr [0x5f40c0], ebx
    app->getMemory<x86::reg32>(x86::reg32(6242496) /* 0x5f40c0 */) = cpu.ebx;
    // 00442803  eb28                   -jmp 0x44282d
    goto L_0x0044282d;
  case 0x00442805:
    // 00442805  83fe03                 +cmp esi, 3
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442808  7e03                   -jle 0x44280d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044280d;
    }
    // 0044280a  83ee03                 -sub esi, 3
    (cpu.esi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0044280d:
    // 0044280d  a1445c5500             -mov eax, dword ptr [0x555c44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594180) /* 0x555c44 */);
    // 00442812  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00442814  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00442816  7402                   -je 0x44281a
    if (cpu.flags.zf)
    {
        goto L_0x0044281a;
    }
    // 00442818  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
L_0x0044281a:
    // 0044281a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0044281c  7c0f                   -jl 0x44282d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044282d;
    }
    // 0044281e  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00442823  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00442825  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00442827  8915c0405f00           -mov dword ptr [0x5f40c0], edx
    app->getMemory<x86::reg32>(x86::reg32(6242496) /* 0x5f40c0 */) = cpu.edx;
L_0x0044282d:
    // 0044282d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044282f  893d2c5c5500           -mov dword ptr [0x555c2c], edi
    app->getMemory<x86::reg32>(x86::reg32(5594156) /* 0x555c2c */) = cpu.edi;
    // 00442835  8935305c5500           -mov dword ptr [0x555c30], esi
    app->getMemory<x86::reg32>(x86::reg32(5594160) /* 0x555c30 */) = cpu.esi;
    // 0044283b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044283d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044283e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044283f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442840  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442841  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442842  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442843  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_442850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442850  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00442851  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00442852  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442853  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00442854  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442855  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442857  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0044285d  81ed7e010000           -sub ebp, 0x17e
    (cpu.ebp) -= x86::reg32(x86::sreg32(382 /*0x17e*/));
    // 00442863  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00442865  bf80020000             -mov edi, 0x280
    cpu.edi = 640 /*0x280*/;
    // 0044286a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044286c  b83f000000             -mov eax, 0x3f
    cpu.eax = 63 /*0x3f*/;
    // 00442871  8915345c5500           -mov dword ptr [0x555c34], edx
    app->getMemory<x86::reg32>(x86::reg32(5594164) /* 0x555c34 */) = cpu.edx;
    // 00442877  8915285c5500           -mov dword ptr [0x555c28], edx
    app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */) = cpu.edx;
    // 0044287d  8915c0405f00           -mov dword ptr [0x5f40c0], edx
    app->getMemory<x86::reg32>(x86::reg32(6242496) /* 0x5f40c0 */) = cpu.edx;
    // 00442883  a3305c5500             -mov dword ptr [0x555c30], eax
    app->getMemory<x86::reg32>(x86::reg32(5594160) /* 0x555c30 */) = cpu.eax;
    // 00442888  891554575500           -mov dword ptr [0x555754], edx
    app->getMemory<x86::reg32>(x86::reg32(5592916) /* 0x555754 */) = cpu.edx;
    // 0044288e  bad07b5300             -mov edx, 0x537bd0
    cpu.edx = 5471184 /*0x537bd0*/;
    // 00442893  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442895  893d2c5c5500           -mov dword ptr [0x555c2c], edi
    app->getMemory<x86::reg32>(x86::reg32(5594156) /* 0x555c2c */) = cpu.edi;
    // 0044289b  e8a0010000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004428a0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004428a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004428a4  7434                   -je 0x4428da
    if (cpu.flags.zf)
    {
        goto L_0x004428da;
    }
    // 004428a6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004428a8  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 004428ad  68d87b5300             -push 0x537bd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5471192 /*0x537bd8*/;
    cpu.esp -= 4;
    // 004428b2  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004428b5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004428b6  e8d5cd0900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004428bb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004428be  bae47b5300             -mov edx, 0x537be4
    cpu.edx = 5471204 /*0x537be4*/;
    // 004428c3  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004428c6  e81db70a00             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 004428cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004428cd  7407                   -je 0x4428d6
    if (cpu.flags.zf)
    {
        goto L_0x004428d6;
    }
    // 004428cf  e82cb80a00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
    // 004428d4  eb04                   -jmp 0x4428da
    goto L_0x004428da;
L_0x004428d6:
    // 004428d6  804b0401               -or byte ptr [ebx + 4], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004428da:
    // 004428da  babc7b5300             -mov edx, 0x537bbc
    cpu.edx = 5471164 /*0x537bbc*/;
    // 004428df  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004428e1  e85a010000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004428e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004428e8  7407                   -je 0x4428f1
    if (cpu.flags.zf)
    {
        goto L_0x004428f1;
    }
    // 004428ea  c7406470234400         -mov dword ptr [eax + 0x64], 0x442370
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4465520 /*0x442370*/;
L_0x004428f1:
    // 004428f1  bac47b5300             -mov edx, 0x537bc4
    cpu.edx = 5471172 /*0x537bc4*/;
    // 004428f6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004428f8  e843010000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004428fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004428ff  7407                   -je 0x442908
    if (cpu.flags.zf)
    {
        goto L_0x00442908;
    }
    // 00442901  c74064e0234400         -mov dword ptr [eax + 0x64], 0x4423e0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4465632 /*0x4423e0*/;
L_0x00442908:
    // 00442908  68342e7a00             -push 0x7a2e34
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007220 /*0x7a2e34*/;
    cpu.esp -= 4;
    // 0044290d  68e87b5300             -push 0x537be8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5471208 /*0x537be8*/;
    cpu.esp -= 4;
    // 00442912  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00442915  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00442916  e875cd0900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0044291b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0044291e  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00442923  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00442926  e895e50900             -call 0x4e0ec0
    cpu.esp -= 4;
    sub_4e0ec0(app, cpu);
    if (cpu.terminate) return;
    // 0044292b  8b0d4cbb6f00           -mov ecx, dword ptr [0x6fbb4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 00442931  a33c5c5500             -mov dword ptr [0x555c3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5594172) /* 0x555c3c */) = cpu.eax;
    // 00442936  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00442938  750c                   -jne 0x442946
    if (!cpu.flags.zf)
    {
        goto L_0x00442946;
    }
    // 0044293a  68342e7a00             -push 0x7a2e34
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007220 /*0x7a2e34*/;
    cpu.esp -= 4;
    // 0044293f  68f47b5300             -push 0x537bf4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5471220 /*0x537bf4*/;
    cpu.esp -= 4;
    // 00442944  eb0a                   -jmp 0x442950
    goto L_0x00442950;
L_0x00442946:
    // 00442946  68342e7a00             -push 0x7a2e34
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007220 /*0x7a2e34*/;
    cpu.esp -= 4;
    // 0044294b  68007c5300             -push 0x537c00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5471232 /*0x537c00*/;
    cpu.esp -= 4;
L_0x00442950:
    // 00442950  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00442953  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00442954  e837cd0900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00442959  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0044295c  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00442961  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00442964  e857e50900             -call 0x4e0ec0
    cpu.esp -= 4;
    sub_4e0ec0(app, cpu);
    if (cpu.terminate) return;
    // 00442969  a3405c5500             -mov dword ptr [0x555c40], eax
    app->getMemory<x86::reg32>(x86::reg32(5594176) /* 0x555c40 */) = cpu.eax;
    // 0044296e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00442970  8da57e010000           -lea esp, [ebp + 0x17e]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(382) /* 0x17e */);
    // 00442976  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442977  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442978  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442979  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044297a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044297b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_442980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442980  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00442981  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442982  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442983  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442985  8b1554575500           -mov edx, dword ptr [0x555754]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592916) /* 0x555754 */);
    // 0044298b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044298d  740f                   -je 0x44299e
    if (cpu.flags.zf)
    {
        goto L_0x0044299e;
    }
    // 0044298f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00442991  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00442993  e8f8ee0900             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00442998  890d54575500           -mov dword ptr [0x555754], ecx
    app->getMemory<x86::reg32>(x86::reg32(5592916) /* 0x555754 */) = cpu.ecx;
L_0x0044299e:
    // 0044299e  a1405c5500             -mov eax, dword ptr [0x555c40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594176) /* 0x555c40 */);
    // 004429a3  e8e8ee0900             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004429a8  a13c5c5500             -mov eax, dword ptr [0x555c3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594172) /* 0x555c3c */);
    // 004429ad  e8deee0900             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004429b2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004429b4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004429b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004429b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004429b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4429c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004429c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004429c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004429c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004429c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004429c4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004429c6  81ec00020000           -sub esp, 0x200
    (cpu.esp) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004429cc  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004429ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004429d0  7459                   -je 0x442a2b
    if (cpu.flags.zf)
    {
        goto L_0x00442a2b;
    }
    // 004429d2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004429d4  7504                   -jne 0x4429da
    if (!cpu.flags.zf)
    {
        goto L_0x004429da;
    }
    // 004429d6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004429d8  eb51                   -jmp 0x442a2b
    goto L_0x00442a2b;
L_0x004429da:
    // 004429da  8dbd00feffff           -lea edi, [ebp - 0x200]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-512) /* -0x200 */);
    // 004429e0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004429e2  bae8895300             -mov edx, 0x5389e8
    cpu.edx = 5474792 /*0x5389e8*/;
    // 004429e7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004429e8:
    // 004429e8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004429ea  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004429ec  3c00                   +cmp al, 0
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
    // 004429ee  7410                   -je 0x442a00
    if (cpu.flags.zf)
    {
        goto L_0x00442a00;
    }
    // 004429f0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004429f3  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004429f6  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004429f9  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004429fc  3c00                   +cmp al, 0
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
    // 004429fe  75e8                   -jne 0x4429e8
    if (!cpu.flags.zf)
    {
        goto L_0x004429e8;
    }
L_0x00442a00:
    // 00442a00  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442a01  8d8500feffff           -lea eax, [ebp - 0x200]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-512) /* -0x200 */);
L_0x00442a07:
    // 00442a07  e854d50a00             -call 0x4eff60
    cpu.esp -= 4;
    sub_4eff60(app, cpu);
    if (cpu.terminate) return;
    // 00442a0c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00442a0e  741b                   -je 0x442a2b
    if (cpu.flags.zf)
    {
        goto L_0x00442a2b;
    }
    // 00442a10  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00442a12  e8f9b80a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00442a17  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00442a19  7507                   -jne 0x442a22
    if (!cpu.flags.zf)
    {
        goto L_0x00442a22;
    }
    // 00442a1b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00442a20  eb09                   -jmp 0x442a2b
    goto L_0x00442a2b;
L_0x00442a22:
    // 00442a22  bae8895300             -mov edx, 0x5389e8
    cpu.edx = 5474792 /*0x5389e8*/;
    // 00442a27  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00442a29  ebdc                   -jmp 0x442a07
    goto L_0x00442a07;
L_0x00442a2b:
    // 00442a2b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00442a2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442a2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442a2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442a30  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442a31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_442a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442a40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00442a41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00442a42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00442a43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00442a44  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442a45  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442a47  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00442a49  8b7016                 -mov esi, dword ptr [eax + 0x16]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 00442a4c  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
L_0x00442a4f:
    // 00442a4f  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00442a56  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00442a58  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00442a5b  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00442a5d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00442a60  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442a67  7424                   -je 0x442a8d
    if (cpu.flags.zf)
    {
        goto L_0x00442a8d;
    }
    // 00442a69  b9e04e6000             -mov ecx, 0x604ee0
    cpu.ecx = 6311648 /*0x604ee0*/;
    // 00442a6e  01c1                   +add ecx, eax
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
    // 00442a70  7418                   -je 0x442a8a
    if (cpu.flags.zf)
    {
        goto L_0x00442a8a;
    }
    // 00442a72  8b7910                 -mov edi, dword ptr [ecx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00442a75  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00442a77  7411                   -je 0x442a8a
    if (cpu.flags.zf)
    {
        goto L_0x00442a8a;
    }
    // 00442a79  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00442a7b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00442a7d  e83effffff             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 00442a82  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00442a84  7404                   -je 0x442a8a
    if (cpu.flags.zf)
    {
        goto L_0x00442a8a;
    }
    // 00442a86  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442a88  eb05                   -jmp 0x442a8f
    goto L_0x00442a8f;
L_0x00442a8a:
    // 00442a8a  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00442a8b  ebc2                   -jmp 0x442a4f
    goto L_0x00442a4f;
L_0x00442a8d:
    // 00442a8d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00442a8f:
    // 00442a8f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442a90  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442a91  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442a92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442a93  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442a94  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_442aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442aa0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00442aa1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442aa2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442aa3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442aa5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00442aa7  baec895300             -mov edx, 0x5389ec
    cpu.edx = 5474796 /*0x5389ec*/;
    // 00442aac  e88fffffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00442ab1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00442ab3  740d                   -je 0x442ac2
    if (cpu.flags.zf)
    {
        goto L_0x00442ac2;
    }
    // 00442ab5  833d54bb6f0000         +cmp dword ptr [0x6fbb54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7322452) /* 0x6fbb54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442abc  7404                   -je 0x442ac2
    if (cpu.flags.zf)
    {
        goto L_0x00442ac2;
    }
    // 00442abe  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00442ac2:
    // 00442ac2  baf4895300             -mov edx, 0x5389f4
    cpu.edx = 5474804 /*0x5389f4*/;
    // 00442ac7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442ac9  e872ffffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00442ace  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00442ad0  740f                   -je 0x442ae1
    if (cpu.flags.zf)
    {
        goto L_0x00442ae1;
    }
    // 00442ad2  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442ad9  7e06                   -jle 0x442ae1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00442ae1;
    }
    // 00442adb  668148040110           -or word ptr [eax + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x00442ae1:
    // 00442ae1  ba8c7d5300             -mov edx, 0x537d8c
    cpu.edx = 5471628 /*0x537d8c*/;
    // 00442ae6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442ae8  e853ffffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00442aed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00442aef  740d                   -je 0x442afe
    if (cpu.flags.zf)
    {
        goto L_0x00442afe;
    }
    // 00442af1  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442af8  7e04                   -jle 0x442afe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00442afe;
    }
    // 00442afa  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00442afe:
    // 00442afe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00442b00  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442b01  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442b02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442b03  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_442b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442b10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00442b11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00442b12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442b13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442b14  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442b16  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00442b18  b9485c5500             -mov ecx, 0x555c48
    cpu.ecx = 5594184 /*0x555c48*/;
L_0x00442b1d:
    // 00442b1d  833900                 +cmp dword ptr [ecx], 0
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
    // 00442b20  7435                   -je 0x442b57
    if (cpu.flags.zf)
    {
        goto L_0x00442b57;
    }
    // 00442b22  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00442b25  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00442b27  e894730a00             -call 0x4e9ec0
    cpu.esp -= 4;
    sub_4e9ec0(app, cpu);
    if (cpu.terminate) return;
    // 00442b2c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00442b2e  7522                   -jne 0x442b52
    if (!cpu.flags.zf)
    {
        goto L_0x00442b52;
    }
    // 00442b30  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00442b33  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00442b35  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00442b38  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00442b3b  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00442b3e  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00442b41  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00442b44  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00442b47  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00442b4a  894310                 -mov dword ptr [ebx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00442b4d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442b4e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442b4f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442b50  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442b51  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442b52:
    // 00442b52  83c118                 +add ecx, 0x18
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00442b55  ebc6                   -jmp 0x442b1d
    goto L_0x00442b1d;
L_0x00442b57:
    // 00442b57  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442b58  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442b59  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442b5a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442b5b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_442b60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442b60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00442b61  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442b62  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442b63  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442b65  8d1400                 -lea edx, [eax + eax]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00442b68  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00442b6d  0566000000             -add eax, 0x66
    (cpu.eax) += x86::reg32(x86::sreg32(102 /*0x66*/));
    // 00442b72  66899a82635500         -mov word ptr [edx + 0x556382], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5596034) /* 0x556382 */) = cpu.bx;
    // 00442b79  6689826e635500         -mov word ptr [edx + 0x55636e], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5596014) /* 0x55636e */) = cpu.ax;
    // 00442b80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442b81  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442b82  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442b83  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_442b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442b90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00442b91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00442b92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442b93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442b94  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442b96  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00442b98  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00442b9a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00442b9c  7446                   -je 0x442be4
    if (cpu.flags.zf)
    {
        goto L_0x00442be4;
    }
L_0x00442b9e:
    // 00442b9e  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00442ba5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00442ba7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00442baa  8b90e8635500           -mov edx, dword ptr [eax + 0x5563e8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5596136) /* 0x5563e8 */);
    // 00442bb0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00442bb2  740e                   -je 0x442bc2
    if (cpu.flags.zf)
    {
        goto L_0x00442bc2;
    }
    // 00442bb4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442bb6  e855b70a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00442bbb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00442bbd  7403                   -je 0x442bc2
    if (cpu.flags.zf)
    {
        goto L_0x00442bc2;
    }
    // 00442bbf  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00442bc0  ebdc                   -jmp 0x442b9e
    goto L_0x00442b9e;
L_0x00442bc2:
    // 00442bc2  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00442bc9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00442bcb  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00442bce  83b8e863550000         +cmp dword ptr [eax + 0x5563e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5596136) /* 0x5563e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442bd5  740b                   -je 0x442be2
    if (cpu.flags.zf)
    {
        goto L_0x00442be2;
    }
    // 00442bd7  8b80f4635500           -mov eax, dword ptr [eax + 0x5563f4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5596148) /* 0x5563f4 */);
    // 00442bdd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442bde  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442bdf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442be0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442be1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442be2:
    // 00442be2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00442be4:
    // 00442be4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442be5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442be6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442be7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442be8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_442bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442bf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00442bf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00442bf2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442bf3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442bf4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442bf6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00442bf8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00442bfa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00442bfc  7446                   -je 0x442c44
    if (cpu.flags.zf)
    {
        goto L_0x00442c44;
    }
L_0x00442bfe:
    // 00442bfe  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00442c05  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00442c07  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00442c0a  8b90e8635500           -mov edx, dword ptr [eax + 0x5563e8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5596136) /* 0x5563e8 */);
    // 00442c10  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00442c12  740e                   -je 0x442c22
    if (cpu.flags.zf)
    {
        goto L_0x00442c22;
    }
    // 00442c14  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442c16  e8f5b60a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00442c1b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00442c1d  7403                   -je 0x442c22
    if (cpu.flags.zf)
    {
        goto L_0x00442c22;
    }
    // 00442c1f  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00442c20  ebdc                   -jmp 0x442bfe
    goto L_0x00442bfe;
L_0x00442c22:
    // 00442c22  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00442c29  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00442c2b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00442c2e  83b8e863550000         +cmp dword ptr [eax + 0x5563e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5596136) /* 0x5563e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442c35  740b                   -je 0x442c42
    if (cpu.flags.zf)
    {
        goto L_0x00442c42;
    }
    // 00442c37  8b80f0635500           -mov eax, dword ptr [eax + 0x5563f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5596144) /* 0x5563f0 */);
    // 00442c3d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442c3e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442c3f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442c40  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442c41  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442c42:
    // 00442c42  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00442c44:
    // 00442c44  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442c45  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442c46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442c47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442c48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_442c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442c50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00442c51  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442c52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442c53  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442c55  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00442c58  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00442c5b  e820000000             -call 0x442c80
    cpu.esp -= 4;
    sub_442c80(app, cpu);
    if (cpu.terminate) return;
    // 00442c60  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00442c62  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00442c64:
    // 00442c64  66833c4100             +cmp word ptr [ecx + eax*2], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00442c69  7403                   -je 0x442c6e
    if (cpu.flags.zf)
    {
        goto L_0x00442c6e;
    }
    // 00442c6b  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00442c6c  ebf6                   -jmp 0x442c64
    goto L_0x00442c64;
L_0x00442c6e:
    // 00442c6e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00442c70  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442c71  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442c72  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442c73  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_442c80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442c80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00442c81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00442c82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00442c83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442c84  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442c86  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00442c88  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00442c8a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00442c8c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00442c8e  7461                   -je 0x442cf1
    if (cpu.flags.zf)
    {
        goto L_0x00442cf1;
    }
L_0x00442c90:
    // 00442c90  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00442c97  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00442c99  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00442c9c  8b90e8635500           -mov edx, dword ptr [eax + 0x5563e8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5596136) /* 0x5563e8 */);
    // 00442ca2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00442ca4  740e                   -je 0x442cb4
    if (cpu.flags.zf)
    {
        goto L_0x00442cb4;
    }
    // 00442ca6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442ca8  e863b60a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00442cad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00442caf  7403                   -je 0x442cb4
    if (cpu.flags.zf)
    {
        goto L_0x00442cb4;
    }
    // 00442cb1  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00442cb2  ebdc                   -jmp 0x442c90
    goto L_0x00442c90;
L_0x00442cb4:
    // 00442cb4  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00442cbb  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00442cbd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00442cc0  83b8e863550000         +cmp dword ptr [eax + 0x5563e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5596136) /* 0x5563e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442cc7  7413                   -je 0x442cdc
    if (cpu.flags.zf)
    {
        goto L_0x00442cdc;
    }
    // 00442cc9  8b90f8635500           -mov edx, dword ptr [eax + 0x5563f8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5596152) /* 0x5563f8 */);
    // 00442ccf  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00442cd1  8b80ec635500           -mov eax, dword ptr [eax + 0x5563ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5596140) /* 0x5563ec */);
    // 00442cd7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442cd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442cd9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442cda  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442cdb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442cdc:
    // 00442cdc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00442cdd  68fc895300             -push 0x5389fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5474812 /*0x5389fc*/;
    cpu.esp -= 4;
    // 00442ce2  e819a8feff             -call 0x42d500
    cpu.esp -= 4;
    sub_42d500(app, cpu);
    if (cpu.terminate) return;
    // 00442ce7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00442cea  e831d40a00             -call 0x4f0120
    cpu.esp -= 4;
    sub_4f0120(app, cpu);
    if (cpu.terminate) return;
    // 00442cef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00442cf1:
    // 00442cf1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442cf2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442cf3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442cf4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442cf5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_442d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442d00  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442d01  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442d02  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442d04  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00442d06  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00442d09  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00442d0b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00442d0e  05d0406000             -add eax, 0x6040d0
    (cpu.eax) += x86::reg32(x86::sreg32(6308048 /*0x6040d0*/));
    // 00442d13  e808000000             -call 0x442d20
    cpu.esp -= 4;
    sub_442d20(app, cpu);
    if (cpu.terminate) return;
    // 00442d18  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442d19  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442d1a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_442d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442d20  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442d21  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442d23  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00442d26  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00442d29  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442d2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_442d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442d30  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442d31  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442d32  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442d34  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00442d36  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00442d39  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00442d3b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00442d3e  05d0406000             -add eax, 0x6040d0
    (cpu.eax) += x86::reg32(x86::sreg32(6308048 /*0x6040d0*/));
    // 00442d43  e808000000             -call 0x442d50
    cpu.esp -= 4;
    sub_442d50(app, cpu);
    if (cpu.terminate) return;
    // 00442d48  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442d49  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442d4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_442d50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442d50  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442d51  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442d53  66c7401e0100           -mov word ptr [eax + 0x1e], 1
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(30) /* 0x1e */) = 1 /*0x1*/;
    // 00442d59  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442d5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_442d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442d60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442d61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442d62  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442d64  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00442d66  83fa05                 +cmp edx, 5
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
    // 00442d69  7213                   -jb 0x442d7e
    if (cpu.flags.cf)
    {
        goto L_0x00442d7e;
    }
    // 00442d6b  761b                   -jbe 0x442d88
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00442d88;
    }
    // 00442d6d  83fa11                 +cmp edx, 0x11
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17 /*0x11*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442d70  722e                   -jb 0x442da0
    if (cpu.flags.cf)
    {
        goto L_0x00442da0;
    }
    // 00442d72  7620                   -jbe 0x442d94
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00442d94;
    }
    // 00442d74  83fa1d                 +cmp edx, 0x1d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(29 /*0x1d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442d77  7421                   -je 0x442d9a
    if (cpu.flags.zf)
    {
        goto L_0x00442d9a;
    }
    // 00442d79  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00442d7b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442d7c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442d7d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442d7e:
    // 00442d7e  83fa03                 +cmp edx, 3
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
    // 00442d81  740b                   -je 0x442d8e
    if (cpu.flags.zf)
    {
        goto L_0x00442d8e;
    }
    // 00442d83  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00442d85  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442d86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442d87  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442d88:
    // 00442d88  8b4058                 -mov eax, dword ptr [eax + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 00442d8b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442d8c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442d8d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442d8e:
    // 00442d8e  8b4050                 -mov eax, dword ptr [eax + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 00442d91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442d92  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442d93  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442d94:
    // 00442d94  8b4060                 -mov eax, dword ptr [eax + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */);
    // 00442d97  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442d98  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442d99  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442d9a:
    // 00442d9a  8b4064                 -mov eax, dword ptr [eax + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    // 00442d9d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442d9e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442d9f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442da0:
    // 00442da0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00442da2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442da3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442da4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_442db0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442db0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00442db1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442db2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442db4  6683fb0d               +cmp bx, 0xd
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00442db8  7508                   -jne 0x442dc2
    if (!cpu.flags.zf)
    {
        goto L_0x00442dc2;
    }
    // 00442dba  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00442dbc  890dc00f6600           -mov dword ptr [0x660fc0], ecx
    app->getMemory<x86::reg32>(x86::reg32(6688704) /* 0x660fc0 */) = cpu.ecx;
L_0x00442dc2:
    // 00442dc2  0fbfdb                 -movsx ebx, bx
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 00442dc5  e8a6e40100             -call 0x461270
    cpu.esp -= 4;
    sub_461270(app, cpu);
    if (cpu.terminate) return;
    // 00442dca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442dcb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442dcc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_442dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442dd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00442dd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00442dd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442dd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00442dd4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00442dd5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442dd6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442dd8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00442ddb  8b7d24                 -mov edi, dword ptr [ebp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 00442dde  d905108a5300           -fld dword ptr [0x538a10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5474832) /* 0x538a10 */)));
    // 00442de4  d9451c                 -fld dword ptr [ebp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    // 00442de7  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00442de9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00442deb  d94520                 -fld dword ptr [ebp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */)));
    // 00442dee  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00442df1  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00442df3  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00442df5  8b7528                 -mov esi, dword ptr [ebp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00442df8  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00442dfb  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 00442dfe  0570c96f00             -add eax, 0x6fc970
    (cpu.eax) += x86::reg32(x86::sreg32(7326064 /*0x6fc970*/));
    // 00442e03  e84ecf0900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00442e08  83c048                 -add eax, 0x48
    (cpu.eax) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00442e0b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00442e0d  e844cf0900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00442e12  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00442e14  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00442e16  db5df8                 -fistp dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00442e19  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00442e1c  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00442e1f  db5dfc                 -fistp dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00442e22  39d0                   +cmp eax, edx
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
    // 00442e24  7414                   -je 0x442e3a
    if (cpu.flags.zf)
    {
        goto L_0x00442e3a;
    }
    // 00442e26  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00442e2b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00442e2d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00442e2f  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00442e32  8b5528                 -mov edx, dword ptr [ebp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00442e35  e8062dffff             -call 0x435b40
    cpu.esp -= 4;
    sub_435b40(app, cpu);
    if (cpu.terminate) return;
L_0x00442e3a:
    // 00442e3a  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00442e3d  3b0e                   +cmp ecx, dword ptr [esi]
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
    // 00442e3f  740e                   -je 0x442e4f
    if (cpu.flags.zf)
    {
        goto L_0x00442e4f;
    }
    // 00442e41  8b5528                 -mov edx, dword ptr [ebp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00442e44  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00442e46  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00442e48  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00442e4a  e8f12cffff             -call 0x435b40
    cpu.esp -= 4;
    sub_435b40(app, cpu);
    if (cpu.terminate) return;
L_0x00442e4f:
    // 00442e4f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00442e51  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442e52  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442e53  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442e54  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442e55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442e56  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442e57  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_442e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442e60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442e61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442e62  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442e64  8b15108a5500           -mov edx, dword ptr [0x558a10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5605904) /* 0x558a10 */);
    // 00442e6a  39d0                   +cmp eax, edx
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
    // 00442e6c  7505                   -jne 0x442e73
    if (!cpu.flags.zf)
    {
        goto L_0x00442e73;
    }
    // 00442e6e  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00442e70  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442e71  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442e72  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442e73:
    // 00442e73  3b05148a5500           +cmp eax, dword ptr [0x558a14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5605908) /* 0x558a14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442e79  7508                   -jne 0x442e83
    if (!cpu.flags.zf)
    {
        goto L_0x00442e83;
    }
    // 00442e7b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00442e80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442e81  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442e82  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442e83:
    // 00442e83  3b05188a5500           +cmp eax, dword ptr [0x558a18]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5605912) /* 0x558a18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442e89  7508                   -jne 0x442e93
    if (!cpu.flags.zf)
    {
        goto L_0x00442e93;
    }
    // 00442e8b  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00442e90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442e91  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442e92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442e93:
    // 00442e93  3b051c8a5500           +cmp eax, dword ptr [0x558a1c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5605916) /* 0x558a1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442e99  7508                   -jne 0x442ea3
    if (!cpu.flags.zf)
    {
        goto L_0x00442ea3;
    }
    // 00442e9b  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00442ea0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442ea1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442ea2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442ea3:
    // 00442ea3  3b05208a5500           +cmp eax, dword ptr [0x558a20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5605920) /* 0x558a20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442ea9  7508                   -jne 0x442eb3
    if (!cpu.flags.zf)
    {
        goto L_0x00442eb3;
    }
    // 00442eab  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00442eb0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442eb1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442eb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442eb3:
    // 00442eb3  3b05248a5500           +cmp eax, dword ptr [0x558a24]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5605924) /* 0x558a24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442eb9  7508                   -jne 0x442ec3
    if (!cpu.flags.zf)
    {
        goto L_0x00442ec3;
    }
    // 00442ebb  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00442ec0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442ec1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442ec2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442ec3:
    // 00442ec3  3b05288a5500           +cmp eax, dword ptr [0x558a28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5605928) /* 0x558a28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442ec9  7508                   -jne 0x442ed3
    if (!cpu.flags.zf)
    {
        goto L_0x00442ed3;
    }
    // 00442ecb  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00442ed0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442ed1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442ed2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442ed3:
    // 00442ed3  3b052c8a5500           +cmp eax, dword ptr [0x558a2c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5605932) /* 0x558a2c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442ed9  7508                   -jne 0x442ee3
    if (!cpu.flags.zf)
    {
        goto L_0x00442ee3;
    }
    // 00442edb  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00442ee0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442ee1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442ee2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442ee3:
    // 00442ee3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00442ee5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442ee6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442ee7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_442ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442ef0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00442ef1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00442ef2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442ef3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00442ef4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442ef5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442ef7  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00442efa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00442efc  8b7078                 -mov esi, dword ptr [eax + 0x78]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */);
    // 00442eff  e85cffffff             -call 0x442e60
    cpu.esp -= 4;
    sub_442e60(app, cpu);
    if (cpu.terminate) return;
    // 00442f04  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00442f06  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00442f08  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442f0a  e8a19a0200             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 00442f0f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00442f14  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442f16  d95df8                 +fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00442f19  e8929a0200             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 00442f1e  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 00442f20  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00442f22  d95dfc                 +fstp dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00442f25  d865f8                 +fsub dword ptr [ebp - 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
    // 00442f28  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00442f2a  d865fc                 +fsub dword ptr [ebp - 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    // 00442f2d  d9e1                   +fabs 
    cpu.fpu.st(0) = cpu.fpu.abs(cpu.fpu.st(0));
    // 00442f2f  d95df4                 +fstp dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00442f32  d85dfc                 +fcomp dword ptr [ebp - 4]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    cpu.fpu.pop();
    // 00442f35  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00442f37  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00442f38  720e                   -jb 0x442f48
    if (cpu.flags.cf)
    {
        goto L_0x00442f48;
    }
    // 00442f3a  d945f4                 +fld dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 00442f3d  d81d148a5300           +fcomp dword ptr [0x538a14]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(x86::reg32(5474836) /* 0x538a14 */));
    cpu.fpu.pop();
    // 00442f43  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00442f45  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00442f46  7358                   -jae 0x442fa0
    if (!cpu.flags.cf)
    {
        goto L_0x00442fa0;
    }
L_0x00442f48:
    // 00442f48  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442f4a  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00442f4c  e86f9b0200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00442f51  8d14dd00000000         -lea edx, [ebx*8]
    cpu.edx = x86::reg32(cpu.ebx * 8);
    // 00442f58  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00442f5b  d89a308a5500           +fcomp dword ptr [edx + 0x558a30]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(cpu.edx + x86::reg32(5605936) /* 0x558a30 */));
    cpu.fpu.pop();
    // 00442f61  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00442f63  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00442f64  7409                   -je 0x442f6f
    if (cpu.flags.zf)
    {
        goto L_0x00442f6f;
    }
    // 00442f66  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 00442f68  d865fc                 +fsub dword ptr [ebp - 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    // 00442f6b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00442f6d  eb15                   -jmp 0x442f84
    goto L_0x00442f84;
L_0x00442f6f:
    // 00442f6f  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00442f72  d89a348a5500           +fcomp dword ptr [edx + 0x558a34]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(cpu.edx + x86::reg32(5605940) /* 0x558a34 */));
    cpu.fpu.pop();
    // 00442f78  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00442f7a  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00442f7b  741a                   -je 0x442f97
    if (cpu.flags.zf)
    {
        goto L_0x00442f97;
    }
    // 00442f7d  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00442f7f  d865f8                 -fsub dword ptr [ebp - 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
    // 00442f82  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
L_0x00442f84:
    // 00442f84  d805188a5300           -fadd dword ptr [0x538a18]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5474840) /* 0x538a18 */));
    // 00442f8a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442f8c  d95df0                 -fstp dword ptr [ebp - 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00442f8f  ff75f0                 -push dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    cpu.esp -= 4;
    // 00442f92  e8b9990200             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
L_0x00442f97:
    // 00442f97  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00442f99  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442f9b  e8209b0200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
L_0x00442fa0:
    // 00442fa0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442fa2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00442fa4  e8079a0200             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 00442fa9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00442fae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00442fb0  d95dec                 -fstp dword ptr [ebp - 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00442fb3  e8f8990200             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 00442fb8  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00442fbb  d95df0                 -fstp dword ptr [ebp - 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00442fbe  8914dd308a5500         -mov dword ptr [ebx*8 + 0x558a30], edx
    app->getMemory<x86::reg32>(x86::reg32(5605936) /* 0x558a30 */ + cpu.ebx * 8) = cpu.edx;
    // 00442fc5  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00442fc8  8914dd348a5500         -mov dword ptr [ebx*8 + 0x558a34], edx
    app->getMemory<x86::reg32>(x86::reg32(5605940) /* 0x558a34 */ + cpu.ebx * 8) = cpu.edx;
    // 00442fcf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00442fd0  8b15748a5500           -mov edx, dword ptr [0x558a74]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606004) /* 0x558a74 */);
    // 00442fd6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442fd7  ff75f0                 -push dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    cpu.esp -= 4;
    // 00442fda  ff75ec                 -push dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    cpu.esp -= 4;
    // 00442fdd  e8eefdffff             -call 0x442dd0
    cpu.esp -= 4;
    sub_442dd0(app, cpu);
    if (cpu.terminate) return;
    // 00442fe2  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00442fe4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442fe5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442fe6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442fe7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442fe8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442fe9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_442ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442ff0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00442ff1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00442ff2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00442ff3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00442ff4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00442ff5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00442ff7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00442ffa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00442ffc  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00442ffe  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00443003  e858760000             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00443008  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044300a  7456                   -je 0x443062
    if (cpu.flags.zf)
    {
        goto L_0x00443062;
    }
    // 0044300c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044300e  e84dfeffff             -call 0x442e60
    cpu.esp -= 4;
    sub_442e60(app, cpu);
    if (cpu.terminate) return;
    // 00443013  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00443015  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00443017  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00443019  8b7978                 -mov edi, dword ptr [ecx + 0x78]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 0044301c  e89f9a0200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00443021  ba788a5500             -mov edx, 0x558a78
    cpu.edx = 5606008 /*0x558a78*/;
    // 00443026  a1748a5500             -mov eax, dword ptr [0x558a74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606004) /* 0x558a74 */);
    // 0044302b  e8c028ffff             -call 0x4358f0
    cpu.esp -= 4;
    sub_4358f0(app, cpu);
    if (cpu.terminate) return;
    // 00443030  db04b5c88a5500         -fild dword ptr [esi*4 + 0x558ac8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606088) /* 0x558ac8 */ + cpu.esi * 4))));
    // 00443037  d80d1c8a5300           -fmul dword ptr [0x538a1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5474844) /* 0x538a1c */));
    // 0044303d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0044303f  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00443041  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00443043  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00443045  d95dfc                 -fstp dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00443048  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 0044304b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0044304d  e8fe980200             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
    // 00443052  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00443054  e8679a0200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00443059  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0044305b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044305d  e87e9a0200             -call 0x46cae0
    cpu.esp -= 4;
    sub_46cae0(app, cpu);
    if (cpu.terminate) return;
L_0x00443062:
    // 00443062  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00443064  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443065  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443066  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443067  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443068  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443069  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_443070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00443070  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00443071  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00443072  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00443073  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00443074  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00443075  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00443077  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0044307a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044307c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0044307e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00443080  0f84ce010000           -je 0x443254
    if (cpu.flags.zf)
    {
        goto L_0x00443254;
    }
    // 00443086  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00443088  8915708a5500           -mov dword ptr [0x558a70], edx
    app->getMemory<x86::reg32>(x86::reg32(5606000) /* 0x558a70 */) = cpu.edx;
    // 0044308e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00443091  8915748a5500           -mov dword ptr [0x558a74], edx
    app->getMemory<x86::reg32>(x86::reg32(5606004) /* 0x558a74 */) = cpu.edx;
    // 00443097  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00443099  ba70c96f00             -mov edx, 0x6fc970
    cpu.edx = 7326064 /*0x6fc970*/;
    // 0044309e  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004430a1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004430a3  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004430a6  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004430a8  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004430ab  e90d010000             -jmp 0x4431bd
    goto L_0x004431bd;
L_0x004430b0:
    // 004430b0  c6473d01               -mov byte ptr [edi + 0x3d], 1
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(61) /* 0x3d */) = 1 /*0x1*/;
L_0x004430b4:
    // 004430b4  837df800               +cmp dword ptr [ebp - 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004430b8  0f84cc000000           -je 0x44318a
    if (cpu.flags.zf)
    {
        goto L_0x0044318a;
    }
    // 004430be  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004430c1  8a4dfc                 -mov cl, byte ptr [ebp - 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004430c4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004430c9  8b7a40                 -mov edi, dword ptr [edx + 0x40]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 004430cc  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004430ce  85f8                   +test eax, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edi));
    // 004430d0  0f84b4000000           -je 0x44318a
    if (cpu.flags.zf)
    {
        goto L_0x0044318a;
    }
    // 004430d6  8b15748a5500           -mov edx, dword ptr [0x558a74]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606004) /* 0x558a74 */);
    // 004430dc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004430de  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004430e1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004430e3  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004430e6  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004430e9  0570c96f00             -add eax, 0x6fc970
    (cpu.eax) += x86::reg32(x86::sreg32(7326064 /*0x6fc970*/));
    // 004430ee  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004430f1  83c048                 -add eax, 0x48
    (cpu.eax) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 004430f4  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004430f7  8d3c10                 -lea edi, [eax + edx]
    cpu.edi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 004430fa  baf02e4400             -mov edx, 0x442ef0
    cpu.edx = 4468464 /*0x442ef0*/;
    // 004430ff  8b048d108a5500         -mov eax, dword ptr [ecx*4 + 0x558a10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5605904) /* 0x558a10 */ + cpu.ecx * 4);
    // 00443106  e8b5990200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 0044310b  8b048d108a5500         -mov eax, dword ptr [ecx*4 + 0x558a10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5605904) /* 0x558a10 */ + cpu.ecx * 4);
    // 00443112  c7402cf02f4400         -mov dword ptr [eax + 0x2c], 0x442ff0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 4468720 /*0x442ff0*/;
    // 00443119  8b048d108a5500         -mov eax, dword ptr [ecx*4 + 0x558a10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5605904) /* 0x558a10 */ + cpu.ecx * 4);
    // 00443120  806005ef               -and byte ptr [eax + 5], 0xef
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00443124  8b048d108a5500         -mov eax, dword ptr [ecx*4 + 0x558a10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5605904) /* 0x558a10 */ + cpu.ecx * 4);
    // 0044312b  66897040               -mov word ptr [eax + 0x40], si
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(64) /* 0x40 */) = cpu.si;
    // 0044312f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00443131  8b048d108a5500         -mov eax, dword ptr [ecx*4 + 0x558a10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5605904) /* 0x558a10 */ + cpu.ecx * 4);
    // 00443138  e883990200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 0044313d  db4704                 -fild dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */))));
    // 00443140  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00443142  d80d408a5300           -fmul dword ptr [0x538a40]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5474880) /* 0x538a40 */));
    // 00443148  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0044314b  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0044314e  8b048d108a5500         -mov eax, dword ptr [ecx*4 + 0x558a10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5605904) /* 0x558a10 */ + cpu.ecx * 4);
    // 00443155  e8f6970200             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
    // 0044315a  db07                   -fild dword ptr [edi]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi))));
    // 0044315c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0044315e  d80d408a5300           -fmul dword ptr [0x538a40]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5474880) /* 0x538a40 */));
    // 00443164  83ec04                 +sub esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00443167  d91c24                 +fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0044316a  8b048d108a5500         -mov eax, dword ptr [ecx*4 + 0x558a10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5605904) /* 0x558a10 */ + cpu.ecx * 4);
    // 00443171  baf02e4400             -mov edx, 0x442ef0
    cpu.edx = 4468464 /*0x442ef0*/;
    // 00443176  e8d5970200             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
    // 0044317b  8b048d108a5500         -mov eax, dword ptr [ecx*4 + 0x558a10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5605904) /* 0x558a10 */ + cpu.ecx * 4);
    // 00443182  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00443183  e838990200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00443188  eb2a                   -jmp 0x4431b4
    goto L_0x004431b4;
L_0x0044318a:
    // 0044318a  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044318d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044318f  8b048d108a5500         -mov eax, dword ptr [ecx*4 + 0x558a10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5605904) /* 0x558a10 */ + cpu.ecx * 4);
    // 00443196  e825990200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 0044319b  8b048d108a5500         -mov eax, dword ptr [ecx*4 + 0x558a10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5605904) /* 0x558a10 */ + cpu.ecx * 4);
    // 004431a2  c7402ce0ca4600         -mov dword ptr [eax + 0x2c], 0x46cae0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 4639456 /*0x46cae0*/;
    // 004431a9  8b048d108a5500         -mov eax, dword ptr [ecx*4 + 0x558a10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5605904) /* 0x558a10 */ + cpu.ecx * 4);
    // 004431b0  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x004431b4:
    // 004431b4  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 004431b7  837dfc08               +cmp dword ptr [ebp - 4], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004431bb  7d47                   -jge 0x443204
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00443204;
    }
L_0x004431bd:
    // 004431bd  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004431c0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004431c3  8bb8108a5500           -mov edi, dword ptr [eax + 0x558a10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5605904) /* 0x558a10 */);
    // 004431c9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004431cb  74e7                   -je 0x4431b4
    if (cpu.flags.zf)
    {
        goto L_0x004431b4;
    }
    // 004431cd  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004431d4  0f84d6feffff           -je 0x4430b0
    if (cpu.flags.zf)
    {
        goto L_0x004430b0;
    }
    // 004431da  66c74706f200           -mov word ptr [edi + 6], 0xf2
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(6) /* 0x6 */) = 242 /*0xf2*/;
    // 004431e0  0fbfd6                 -movsx edx, si
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.si));
    // 004431e3  8b88108a5500           -mov ecx, dword ptr [eax + 0x558a10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5605904) /* 0x558a10 */);
    // 004431e9  668b1495949c5500       -mov dx, word ptr [edx*4 + 0x559c94]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5610644) /* 0x559c94 */ + cpu.edx * 4);
    // 004431f1  66895108               -mov word ptr [ecx + 8], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.dx;
    // 004431f5  8b80108a5500           -mov eax, dword ptr [eax + 0x558a10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5605904) /* 0x558a10 */);
    // 004431fb  c6403d00               -mov byte ptr [eax + 0x3d], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(61) /* 0x3d */) = 0 /*0x0*/;
    // 004431ff  e9b0feffff             -jmp 0x4430b4
    goto L_0x004430b4;
L_0x00443204:
    // 00443204  ba208a5300             -mov edx, 0x538a20
    cpu.edx = 5474848 /*0x538a20*/;
    // 00443209  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044320b  e830f8ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00443210  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00443212  7404                   -je 0x443218
    if (cpu.flags.zf)
    {
        goto L_0x00443218;
    }
    // 00443214  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00443218:
    // 00443218  ba288a5300             -mov edx, 0x538a28
    cpu.edx = 5474856 /*0x538a28*/;
    // 0044321d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044321f  e81cf8ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00443224  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00443226  7404                   -je 0x44322c
    if (cpu.flags.zf)
    {
        goto L_0x0044322c;
    }
    // 00443228  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044322c:
    // 0044322c  ba308a5300             -mov edx, 0x538a30
    cpu.edx = 5474864 /*0x538a30*/;
    // 00443231  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00443233  e808f8ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00443238  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044323a  7404                   -je 0x443240
    if (cpu.flags.zf)
    {
        goto L_0x00443240;
    }
    // 0044323c  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00443240:
    // 00443240  ba388a5300             -mov edx, 0x538a38
    cpu.edx = 5474872 /*0x538a38*/;
    // 00443245  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00443247  e8f4f7ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044324c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044324e  7404                   -je 0x443254
    if (cpu.flags.zf)
    {
        goto L_0x00443254;
    }
    // 00443250  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00443254:
    // 00443254  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00443256  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443257  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443258  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443259  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044325a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044325b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_443260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00443260  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00443261  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00443262  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00443264  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00443266  0fbfdb                 -movsx ebx, bx
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 00443269  e8820d0200             -call 0x463ff0
    cpu.esp -= 4;
    sub_463ff0(app, cpu);
    if (cpu.terminate) return;
    // 0044326e  8b15748a5500           -mov edx, dword ptr [0x558a74]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606004) /* 0x558a74 */);
    // 00443274  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00443276  3b15708a5500           +cmp edx, dword ptr [0x558a70]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606000) /* 0x558a70 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044327c  7407                   -je 0x443285
    if (cpu.flags.zf)
    {
        goto L_0x00443285;
    }
    // 0044327e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00443280  e8ebfdffff             -call 0x443070
    cpu.esp -= 4;
    sub_443070(app, cpu);
    if (cpu.terminate) return;
L_0x00443285:
    // 00443285  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00443287  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443288  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443289  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_443290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00443290  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00443291  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00443292  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00443294  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00443296  0fbfdb                 -movsx ebx, bx
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 00443299  e8d2df0100             -call 0x461270
    cpu.esp -= 4;
    sub_461270(app, cpu);
    if (cpu.terminate) return;
    // 0044329e  8b15748a5500           -mov edx, dword ptr [0x558a74]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606004) /* 0x558a74 */);
    // 004432a4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004432a6  3b15708a5500           +cmp edx, dword ptr [0x558a70]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606000) /* 0x558a70 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004432ac  7407                   -je 0x4432b5
    if (cpu.flags.zf)
    {
        goto L_0x004432b5;
    }
    // 004432ae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004432b0  e8bbfdffff             -call 0x443070
    cpu.esp -= 4;
    sub_443070(app, cpu);
    if (cpu.terminate) return;
L_0x004432b5:
    // 004432b5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004432b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004432b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004432b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4432c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004432c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004432c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004432c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004432c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004432c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004432c5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004432c7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004432c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004432cb  0f8457010000           -je 0x443428
    if (cpu.flags.zf)
    {
        goto L_0x00443428;
    }
    // 004432d1  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004432d8  740a                   -je 0x4432e4
    if (cpu.flags.zf)
    {
        goto L_0x004432e4;
    }
    // 004432da  689a99193f             -push 0x3f19999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058642330 /*0x3f19999a*/;
    cpu.esp -= 4;
    // 004432df  e84ce20000             -call 0x451530
    cpu.esp -= 4;
    sub_451530(app, cpu);
    if (cpu.terminate) return;
L_0x004432e4:
    // 004432e4  e8b7a6ffff             -call 0x43d9a0
    cpu.esp -= 4;
    sub_43d9a0(app, cpu);
    if (cpu.terminate) return;
    // 004432e9  ba448a5300             -mov edx, 0x538a44
    cpu.edx = 5474884 /*0x538a44*/;
    // 004432ee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004432f0  e84bf7ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004432f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004432f7  740d                   -je 0x443306
    if (cpu.flags.zf)
    {
        goto L_0x00443306;
    }
    // 004432f9  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443300  7e04                   -jle 0x443306
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00443306;
    }
    // 00443302  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00443306:
    // 00443306  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0044330b  ba4c8a5300             -mov edx, 0x538a4c
    cpu.edx = 5474892 /*0x538a4c*/;
    // 00443310  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00443312  8935c00f6600           -mov dword ptr [0x660fc0], esi
    app->getMemory<x86::reg32>(x86::reg32(6688704) /* 0x660fc0 */) = cpu.esi;
    // 00443318  e823f7ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044331d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044331f  7407                   -je 0x443328
    if (cpu.flags.zf)
    {
        goto L_0x00443328;
    }
    // 00443321  c74030b02d4400         -mov dword ptr [eax + 0x30], 0x442db0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 4468144 /*0x442db0*/;
L_0x00443328:
    // 00443328  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0044332a:
    // 0044332a  3b3504d26f00           +cmp esi, dword ptr [0x6fd204]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328260) /* 0x6fd204 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443330  7d2b                   -jge 0x44335d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044335d;
    }
    // 00443332  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00443334  bac00b6600             -mov edx, 0x660bc0
    cpu.edx = 6687680 /*0x660bc0*/;
    // 00443339  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0044333c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044333e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00443340  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00443343  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00443345  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00443348  0570c96f00             -add eax, 0x6fc970
    (cpu.eax) += x86::reg32(x86::sreg32(7326064 /*0x6fc970*/));
    // 0044334d  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 00443352  83c048                 +add eax, 0x48
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(72 /*0x48*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00443355  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00443356  e895710a00             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 0044335b  ebcd                   -jmp 0x44332a
    goto L_0x0044332a;
L_0x0044335d:
    // 0044335d  baec000000             -mov edx, 0xec
    cpu.edx = 236 /*0xec*/;
    // 00443362  b8108a5500             -mov eax, 0x558a10
    cpu.eax = 5605904 /*0x558a10*/;
    // 00443367  e8a0d30900             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 0044336c  ba588a5300             -mov edx, 0x538a58
    cpu.edx = 5474904 /*0x538a58*/;
    // 00443371  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00443373  e8c8f6ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00443378  ba648a5300             -mov edx, 0x538a64
    cpu.edx = 5474916 /*0x538a64*/;
    // 0044337d  a3108a5500             -mov dword ptr [0x558a10], eax
    app->getMemory<x86::reg32>(x86::reg32(5605904) /* 0x558a10 */) = cpu.eax;
    // 00443382  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00443384  e8b7f6ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00443389  ba708a5300             -mov edx, 0x538a70
    cpu.edx = 5474928 /*0x538a70*/;
    // 0044338e  a3148a5500             -mov dword ptr [0x558a14], eax
    app->getMemory<x86::reg32>(x86::reg32(5605908) /* 0x558a14 */) = cpu.eax;
    // 00443393  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00443395  e8a6f6ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044339a  ba7c8a5300             -mov edx, 0x538a7c
    cpu.edx = 5474940 /*0x538a7c*/;
    // 0044339f  a3188a5500             -mov dword ptr [0x558a18], eax
    app->getMemory<x86::reg32>(x86::reg32(5605912) /* 0x558a18 */) = cpu.eax;
    // 004433a4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004433a6  e895f6ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004433ab  ba8c8a5300             -mov edx, 0x538a8c
    cpu.edx = 5474956 /*0x538a8c*/;
    // 004433b0  a31c8a5500             -mov dword ptr [0x558a1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5605916) /* 0x558a1c */) = cpu.eax;
    // 004433b5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004433b7  e884f6ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004433bc  ba9c8a5300             -mov edx, 0x538a9c
    cpu.edx = 5474972 /*0x538a9c*/;
    // 004433c1  a3208a5500             -mov dword ptr [0x558a20], eax
    app->getMemory<x86::reg32>(x86::reg32(5605920) /* 0x558a20 */) = cpu.eax;
    // 004433c6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004433c8  e873f6ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004433cd  baac8a5300             -mov edx, 0x538aac
    cpu.edx = 5474988 /*0x538aac*/;
    // 004433d2  a3248a5500             -mov dword ptr [0x558a24], eax
    app->getMemory<x86::reg32>(x86::reg32(5605924) /* 0x558a24 */) = cpu.eax;
    // 004433d7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004433d9  e862f6ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004433de  babc8a5300             -mov edx, 0x538abc
    cpu.edx = 5475004 /*0x538abc*/;
    // 004433e3  a3288a5500             -mov dword ptr [0x558a28], eax
    app->getMemory<x86::reg32>(x86::reg32(5605928) /* 0x558a28 */) = cpu.eax;
    // 004433e8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004433ea  e851f6ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004433ef  a32c8a5500             -mov dword ptr [0x558a2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5605932) /* 0x558a2c */) = cpu.eax;
    // 004433f4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004433f6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004433f8  e873fcffff             -call 0x443070
    cpu.esp -= 4;
    sub_443070(app, cpu);
    if (cpu.terminate) return;
    // 004433fd  bacc8a5300             -mov edx, 0x538acc
    cpu.edx = 5475020 /*0x538acc*/;
    // 00443402  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00443404  e837f6ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00443409  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044340b  7419                   -je 0x443426
    if (cpu.flags.zf)
    {
        goto L_0x00443426;
    }
    // 0044340d  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443414  7409                   -je 0x44341f
    if (cpu.flags.zf)
    {
        goto L_0x0044341f;
    }
    // 00443416  c7403090324400         -mov dword ptr [eax + 0x30], 0x443290
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 4469392 /*0x443290*/;
    // 0044341d  eb07                   -jmp 0x443426
    goto L_0x00443426;
L_0x0044341f:
    // 0044341f  c7403060324400         -mov dword ptr [eax + 0x30], 0x443260
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 4469344 /*0x443260*/;
L_0x00443426:
    // 00443426  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00443428:
    // 00443428  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443429  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044342a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044342b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044342c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044342d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_443430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00443430  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00443431  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00443432  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00443433  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00443434  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00443435  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00443436  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00443438  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0044343b  833dc00f660000         +cmp dword ptr [0x660fc0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6688704) /* 0x660fc0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443442  0f859c000000           -jne 0x4434e4
    if (!cpu.flags.zf)
    {
        goto L_0x004434e4;
    }
    // 00443448  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0044344a:
    // 0044344a  3b3504d26f00           +cmp esi, dword ptr [0x6fd204]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328260) /* 0x6fd204 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443450  0f8d8e000000           -jge 0x4434e4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004434e4;
    }
    // 00443456  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00443458  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044345b  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0044345d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00443460  0570c96f00             -add eax, 0x6fc970
    (cpu.eax) += x86::reg32(x86::sreg32(7326064 /*0x6fc970*/));
    // 00443465  8d5048                 -lea edx, [eax + 0x48]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00443468  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044346a  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0044346d  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 00443472  05c00b6600             -add eax, 0x660bc0
    (cpu.eax) += x86::reg32(x86::sreg32(6687680 /*0x660bc0*/));
    // 00443477  e874700a00             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 0044347c  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0044347e  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00443481  eb06                   -jmp 0x443489
    goto L_0x00443489;
L_0x00443483:
    // 00443483  837dfc08               +cmp dword ptr [ebp - 4], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443487  7d55                   -jge 0x4434de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004434de;
    }
L_0x00443489:
    // 00443489  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0044348b  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0044348e  8a4dfc                 -mov cl, byte ptr [ebp - 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00443491  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00443493  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00443498  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0044349b  d3e0                   +shl eax, cl
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
    // 0044349d  8582b0c96f00           -test dword ptr [edx + 0x6fc9b0], eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(7326128) /* 0x6fc9b0 */) & cpu.eax));
    // 004434a3  7434                   -je 0x4434d9
    if (cpu.flags.zf)
    {
        goto L_0x004434d9;
    }
    // 004434a5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004434a7  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004434aa  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 004434ad  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 004434b0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004434b5  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004434b7  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004434ba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004434bc  8b8fc40b6600           -mov ecx, dword ptr [edi + 0x660bc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6687684) /* 0x660bc4 */);
    // 004434c2  e87926ffff             -call 0x435b40
    cpu.esp -= 4;
    sub_435b40(app, cpu);
    if (cpu.terminate) return;
    // 004434c7  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004434ca  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004434cc  8b8fc00b6600           -mov ecx, dword ptr [edi + 0x660bc0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6687680) /* 0x660bc0 */);
    // 004434d2  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004434d4  e86726ffff             -call 0x435b40
    cpu.esp -= 4;
    sub_435b40(app, cpu);
    if (cpu.terminate) return;
L_0x004434d9:
    // 004434d9  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004434dc  eba5                   -jmp 0x443483
    goto L_0x00443483;
L_0x004434de:
    // 004434de  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004434df  e966ffffff             -jmp 0x44344a
    goto L_0x0044344a;
L_0x004434e4:
    // 004434e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004434e6  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004434e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004434e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004434ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004434eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004434ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004434ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004434ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4434f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004434f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004434f1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004434f3  83f820                 +cmp eax, 0x20
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
    // 004434f6  7c0b                   -jl 0x443503
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00443503;
    }
    // 004434f8  3dff000000             +cmp eax, 0xff
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
    // 004434fd  7f04                   -jg 0x443503
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00443503;
    }
    // 004434ff  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00443501  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443502  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00443503:
    // 00443503  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00443505  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443506  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_443510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00443510  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00443511  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00443513  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00443518  e8d3ffffff             -call 0x4434f0
    cpu.esp -= 4;
    sub_4434f0(app, cpu);
    if (cpu.terminate) return;
    // 0044351d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044351e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_443520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00443520  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00443521  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00443522  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00443523  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00443525  b301                   -mov bl, 1
    cpu.bl = 1 /*0x1*/;
    // 00443527  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00443529  7405                   -je 0x443530
    if (cpu.flags.zf)
    {
        goto L_0x00443530;
    }
    // 0044352b  803800                 +cmp byte ptr [eax], 0
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
    // 0044352e  7506                   -jne 0x443536
    if (!cpu.flags.zf)
    {
        goto L_0x00443536;
    }
L_0x00443530:
    // 00443530  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00443532  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443533  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443534  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443535  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00443536:
    // 00443536  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00443538:
    // 00443538  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 0044353a  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 0044353c  7414                   -je 0x443552
    if (cpu.flags.zf)
    {
        goto L_0x00443552;
    }
    // 0044353e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00443540  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 00443542  e8c9ffffff             -call 0x443510
    cpu.esp -= 4;
    sub_443510(app, cpu);
    if (cpu.terminate) return;
    // 00443547  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00443549  7504                   -jne 0x44354f
    if (!cpu.flags.zf)
    {
        goto L_0x0044354f;
    }
    // 0044354b  30db                   +xor bl, bl
    cpu.clear_co();
    cpu.set_szp((cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl))));
    // 0044354d  eb03                   -jmp 0x443552
    goto L_0x00443552;
L_0x0044354f:
    // 0044354f  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00443550  ebe6                   -jmp 0x443538
    goto L_0x00443538;
L_0x00443552:
    // 00443552  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00443554  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443555  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443556  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443557  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4435c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004435c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004435c1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004435c2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004435c4  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 004435c6  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 004435c8  80ec20                 -sub ah, 0x20
    (cpu.ah) -= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004435cb  80fc19                 +cmp ah, 0x19
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(25 /*0x19*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004435ce  770d                   -ja 0x4435dd
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004435dd;
    }
    // 004435d0  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004435d2  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004435d4  ff249558354400         -jmp dword ptr [edx*4 + 0x443558]
    cpu.ip = app->getMemory<x86::reg32>(4470104 + cpu.edx * 4); goto dynamic_jump;
  case 0x004435db:
    // 004435db  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
  [[fallthrough]];
  case 0x004435dd:
L_0x004435dd:
    // 004435dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004435de  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004435df  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4435e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004435e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004435e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004435e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004435e3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004435e5  b301                   -mov bl, 1
    cpu.bl = 1 /*0x1*/;
    // 004435e7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004435e9  7405                   -je 0x4435f0
    if (cpu.flags.zf)
    {
        goto L_0x004435f0;
    }
    // 004435eb  803800                 +cmp byte ptr [eax], 0
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
    // 004435ee  7506                   -jne 0x4435f6
    if (!cpu.flags.zf)
    {
        goto L_0x004435f6;
    }
L_0x004435f0:
    // 004435f0  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 004435f2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004435f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004435f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004435f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004435f6:
    // 004435f6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004435f8:
    // 004435f8  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 004435fa  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 004435fc  7414                   -je 0x443612
    if (cpu.flags.zf)
    {
        goto L_0x00443612;
    }
    // 004435fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00443600  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 00443602  e8b9ffffff             -call 0x4435c0
    cpu.esp -= 4;
    sub_4435c0(app, cpu);
    if (cpu.terminate) return;
    // 00443607  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00443609  7504                   -jne 0x44360f
    if (!cpu.flags.zf)
    {
        goto L_0x0044360f;
    }
    // 0044360b  30db                   +xor bl, bl
    cpu.clear_co();
    cpu.set_szp((cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl))));
    // 0044360d  eb03                   -jmp 0x443612
    goto L_0x00443612;
L_0x0044360f:
    // 0044360f  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00443610  ebe6                   -jmp 0x4435f8
    goto L_0x004435f8;
L_0x00443612:
    // 00443612  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00443614  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443615  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443616  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443617  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_443620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00443620  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00443621  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00443623  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00443628  e8c3feffff             -call 0x4434f0
    cpu.esp -= 4;
    sub_4434f0(app, cpu);
    if (cpu.terminate) return;
    // 0044362d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044362e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_443630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00443630  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00443631  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00443632  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00443634  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 00443636  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00443638  fec4                   -inc ah
    (cpu.ah)++;
    // 0044363a  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 0044363c  f682f04e5600e0         +test byte ptr [edx + 0x564ef0], 0xe0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5656304) /* 0x564ef0 */) & 224 /*0xe0*/));
    // 00443643  7405                   -je 0x44364a
    if (cpu.flags.zf)
    {
        goto L_0x0044364a;
    }
    // 00443645  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00443647  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443648  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443649  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044364a:
    // 0044364a  3c5f                   +cmp al, 0x5f
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(95 /*0x5f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044364c  7404                   -je 0x443652
    if (cpu.flags.zf)
    {
        goto L_0x00443652;
    }
    // 0044364e  3c2d                   +cmp al, 0x2d
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
    // 00443650  7505                   -jne 0x443657
    if (!cpu.flags.zf)
    {
        goto L_0x00443657;
    }
L_0x00443652:
    // 00443652  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00443654  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443655  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443656  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00443657:
    // 00443657  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00443659  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044365a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044365b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_443660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00443660  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00443661  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00443662  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00443663  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00443664  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00443665  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00443667  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00443669  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044366b  7504                   -jne 0x443671
    if (!cpu.flags.zf)
    {
        goto L_0x00443671;
    }
    // 0044366d  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0044366f  eb43                   -jmp 0x4436b4
    goto L_0x004436b4;
L_0x00443671:
    // 00443671  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00443673  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00443675  49                     -dec ecx
    (cpu.ecx)--;
    // 00443676  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00443678  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0044367a  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0044367c  49                     -dec ecx
    (cpu.ecx)--;
    // 0044367d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0044367f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00443681  7c05                   -jl 0x443688
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00443688;
    }
    // 00443683  83f908                 +cmp ecx, 8
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
    // 00443686  7e08                   -jle 0x443690
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00443690;
    }
L_0x00443688:
    // 00443688  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0044368a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044368b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044368c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044368d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044368e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044368f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00443690:
    // 00443690  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00443692:
    // 00443692  39d9                   +cmp ecx, ebx
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
    // 00443694  7d1c                   -jge 0x4436b2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004436b2;
    }
    // 00443696  8d040a                 -lea eax, [edx + ecx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 00443699  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0044369b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004436a0  e88bffffff             -call 0x443630
    cpu.esp -= 4;
    sub_443630(app, cpu);
    if (cpu.terminate) return;
    // 004436a5  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004436a7  7506                   -jne 0x4436af
    if (!cpu.flags.zf)
    {
        goto L_0x004436af;
    }
    // 004436a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004436aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004436ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004436ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004436ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004436ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004436af:
    // 004436af  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004436b0  ebe0                   -jmp 0x443692
    goto L_0x00443692;
L_0x004436b2:
    // 004436b2  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x004436b4:
    // 004436b4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004436b5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004436b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004436b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004436b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004436b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4436c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004436c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004436c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004436c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004436c3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004436c5  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004436c7  8b0d4cbb6f00           -mov ecx, dword ptr [0x6fbb4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 004436cd  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004436d4  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004436d6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004436d9  83b87c8c550000         +cmp dword ptr [eax + 0x558c7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5606524) /* 0x558c7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004436e0  7410                   -je 0x4436f2
    if (cpu.flags.zf)
    {
        goto L_0x004436f2;
    }
    // 004436e2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004436e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004436e6  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004436e8  ff917c8c5500           -call dword ptr [ecx + 0x558c7c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5606524) /* 0x558c7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004436ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004436ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004436f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004436f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004436f2:
    // 004436f2  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004436f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004436f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004436f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004436f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_443700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00443700  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00443701  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00443702  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00443703  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00443705  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00443707  8b0d4cbb6f00           -mov ecx, dword ptr [0x6fbb4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 0044370d  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00443714  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00443716  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00443719  83b8808c550000         +cmp dword ptr [eax + 0x558c80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5606528) /* 0x558c80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443720  740e                   -je 0x443730
    if (cpu.flags.zf)
    {
        goto L_0x00443730;
    }
    // 00443722  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00443724  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00443726  ff91808c5500           -call dword ptr [ecx + 0x558c80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5606528) /* 0x558c80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044372c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044372d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044372e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044372f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00443730:
    // 00443730  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00443732  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443733  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443734  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443735  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_443740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00443740  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00443741  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00443742  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00443743  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00443745  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00443747  8b0d4cbb6f00           -mov ecx, dword ptr [0x6fbb4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 0044374d  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00443754  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00443756  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00443759  83b8848c550000         +cmp dword ptr [eax + 0x558c84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5606532) /* 0x558c84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443760  7410                   -je 0x443772
    if (cpu.flags.zf)
    {
        goto L_0x00443772;
    }
    // 00443762  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00443764  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00443766  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00443768  ff91848c5500           -call dword ptr [ecx + 0x558c84]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5606532) /* 0x558c84 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044376e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044376f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443770  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443771  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00443772:
    // 00443772  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00443774  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443775  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443776  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443777  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_443780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00443780  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00443781  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00443782  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00443783  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00443785  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00443787  8b0d4cbb6f00           -mov ecx, dword ptr [0x6fbb4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 0044378d  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00443794  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00443796  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00443799  83b8888c550000         +cmp dword ptr [eax + 0x558c88], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5606536) /* 0x558c88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004437a0  740e                   -je 0x4437b0
    if (cpu.flags.zf)
    {
        goto L_0x004437b0;
    }
    // 004437a2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004437a4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004437a6  ff91888c5500           -call dword ptr [ecx + 0x558c88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5606536) /* 0x558c88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004437ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004437ad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004437ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004437af  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004437b0:
    // 004437b0  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004437b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004437b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004437b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004437b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4437c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004437c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004437c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004437c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004437c3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004437c5  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004437c7  8b0d4cbb6f00           -mov ecx, dword ptr [0x6fbb4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 004437cd  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004437d4  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004437d6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004437d9  83b88c8c550000         +cmp dword ptr [eax + 0x558c8c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5606540) /* 0x558c8c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004437e0  7410                   -je 0x4437f2
    if (cpu.flags.zf)
    {
        goto L_0x004437f2;
    }
    // 004437e2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004437e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004437e6  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004437e8  ff918c8c5500           -call dword ptr [ecx + 0x558c8c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5606540) /* 0x558c8c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004437ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004437ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004437f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004437f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004437f2:
    // 004437f2  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004437f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004437f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004437f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004437f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_443810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00443810  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00443811  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00443813  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 00443815  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00443817  83fa03                 +cmp edx, 3
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
    // 0044381a  773d                   -ja 0x443859
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00443859;
    }
    // 0044381c  ff2495f8374400         -jmp dword ptr [edx*4 + 0x4437f8]
    cpu.ip = app->getMemory<x86::reg32>(4470776 + cpu.edx * 4); goto dynamic_jump;
  case 0x00443823:
    // 00443823  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 00443825  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0044382a  e801feffff             -call 0x443630
    cpu.esp -= 4;
    sub_443630(app, cpu);
    if (cpu.terminate) return;
    // 0044382f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443830  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00443831:
    // 00443831  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 00443833  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00443838  e883feffff             -call 0x4436c0
    cpu.esp -= 4;
    sub_4436c0(app, cpu);
    if (cpu.terminate) return;
    // 0044383d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044383e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0044383f:
    // 0044383f  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 00443841  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00443846  e8f5feffff             -call 0x443740
    cpu.esp -= 4;
    sub_443740(app, cpu);
    if (cpu.terminate) return;
    // 0044384b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044384c  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0044384d:
    // 0044384d  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 0044384f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00443854  e867ffffff             -call 0x4437c0
    cpu.esp -= 4;
    sub_4437c0(app, cpu);
    if (cpu.terminate) return;
L_0x00443859:
    // 00443859  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044385a  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_443860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00443860  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00443861  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00443862  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00443864  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00443866  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00443868  7405                   -je 0x44386f
    if (cpu.flags.zf)
    {
        goto L_0x0044386f;
    }
    // 0044386a  803800                 +cmp byte ptr [eax], 0
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
    // 0044386d  7505                   -jne 0x443874
    if (!cpu.flags.zf)
    {
        goto L_0x00443874;
    }
L_0x0044386f:
    // 0044386f  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00443871  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443872  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443873  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00443874:
    // 00443874  83fa01                 +cmp edx, 1
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
    // 00443877  720c                   -jb 0x443885
    if (cpu.flags.cf)
    {
        goto L_0x00443885;
    }
    // 00443879  761a                   -jbe 0x443895
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00443895;
    }
    // 0044387b  83fa02                 +cmp edx, 2
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
    // 0044387e  741c                   -je 0x44389c
    if (cpu.flags.zf)
    {
        goto L_0x0044389c;
    }
    // 00443880  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00443882  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443883  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443884  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00443885:
    // 00443885  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00443887  7405                   -je 0x44388e
    if (cpu.flags.zf)
    {
        goto L_0x0044388e;
    }
    // 00443889  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0044388b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044388c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044388d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044388e:
    // 0044388e  e8cdfdffff             -call 0x443660
    cpu.esp -= 4;
    sub_443660(app, cpu);
    if (cpu.terminate) return;
    // 00443893  eb0c                   -jmp 0x4438a1
    goto L_0x004438a1;
L_0x00443895:
    // 00443895  e866feffff             -call 0x443700
    cpu.esp -= 4;
    sub_443700(app, cpu);
    if (cpu.terminate) return;
    // 0044389a  eb05                   -jmp 0x4438a1
    goto L_0x004438a1;
L_0x0044389c:
    // 0044389c  e8dffeffff             -call 0x443780
    cpu.esp -= 4;
    sub_443780(app, cpu);
    if (cpu.terminate) return;
L_0x004438a1:
    // 004438a1  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 004438a3  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004438a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004438a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004438a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4438b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004438b0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004438b1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004438b3  a0108b5500             -mov al, byte ptr [0x558b10]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5606160) /* 0x558b10 */);
    // 004438b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004438b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4438c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004438c0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004438c1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004438c3  a1148b5500             -mov eax, dword ptr [0x558b14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606164) /* 0x558b14 */);
    // 004438c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004438c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4438d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004438d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004438d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004438d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004438d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004438d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004438d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004438d6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004438d8  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004438db  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004438de  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004438e0  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004438e3  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004438e6  8b1564106600           -mov edx, dword ptr [0x661064]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */);
    // 004438ec  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004438ee  e863c40900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 004438f3  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004438f5  e85cc40900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 004438fa  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004438fc  db5df0                 -fistp dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004438ff  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00443901  db5df4                 -fistp dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00443904  d86004                 -fsub dword ptr [eax + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 00443907  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00443909  d820                   -fsub dword ptr [eax]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax));
    // 0044390b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0044390d  e844c40900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00443912  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00443914  e83dc40900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00443919  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0044391b  db5de8                 -fistp dword ptr [ebp - 0x18]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0044391e  db5dec                 -fistp dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00443921  81faff000000           +cmp edx, 0xff
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443927  7d62                   -jge 0x44398b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044398b;
    }
    // 00443929  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00443930  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00443932  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00443935  b9ff000000             -mov ecx, 0xff
    cpu.ecx = 255 /*0xff*/;
    // 0044393a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044393c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0044393f  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00443941  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 00443944  8b1564106600           -mov edx, dword ptr [0x661064]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */);
    // 0044394a  8d5860                 -lea ebx, [eax + 0x60]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(96) /* 0x60 */);
    // 0044394d  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00443950  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00443952  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00443955  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00443957  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0044395a  8b1564106600           -mov edx, dword ptr [0x661064]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */);
    // 00443960  8d4850                 -lea ecx, [eax + 0x50]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 00443963  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044396a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044396c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044396f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00443971  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00443974  beff000000             -mov esi, 0xff
    cpu.esi = 255 /*0xff*/;
    // 00443979  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044397b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0044397e  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00443980  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 00443983  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00443986  83c010                 +add eax, 0x10
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
    // 00443989  eb14                   -jmp 0x44399f
    goto L_0x0044399f;
L_0x0044398b:
    // 0044398b  b9500000a0             -mov ecx, 0xa0000050
    cpu.ecx = 2684354640 /*0xa0000050*/;
    // 00443990  ba200000d0             -mov edx, 0xd0000020
    cpu.edx = 3489660960 /*0xd0000020*/;
    // 00443995  b8100000d0             -mov eax, 0xd0000010
    cpu.eax = 3489660944 /*0xd0000010*/;
    // 0044399a  bb600000a0             -mov ebx, 0xa0000060
    cpu.ebx = 2684354656 /*0xa0000060*/;
L_0x0044399f:
    // 0044399f  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004439a2  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004439a5  83ef0e                 -sub edi, 0xe
    (cpu.edi) -= x86::reg32(x86::sreg32(14 /*0xe*/));
    // 004439a8  83ee07                 -sub esi, 7
    (cpu.esi) -= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004439ab  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004439b2  0f849a000000           -je 0x443a52
    if (cpu.flags.zf)
    {
        goto L_0x00443a52;
    }
    // 004439b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004439b9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004439ba  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004439bb  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004439be  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004439c1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004439c2  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004439c5  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004439c8  e8934e0900             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
    // 004439cd  a164106600             -mov eax, dword ptr [0x661064]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */);
    // 004439d2  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004439d5  05ffffff00             -add eax, 0xffffff
    (cpu.eax) += x86::reg32(x86::sreg32(16777215 /*0xffffff*/));
    // 004439da  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004439db  8b0d389a7400           -mov ecx, dword ptr [0x749a38]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7641656) /* 0x749a38 */);
    // 004439e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004439e2  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
    // 004439e5  680000fe3e             -push 0x3efe0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1056833536 /*0x3efe0000*/;
    cpu.esp -= 4;
    // 004439ea  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004439ed  680000003f             -push 0x3f000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1056964608 /*0x3f000000*/;
    cpu.esp -= 4;
    // 004439f2  db45f8                 -fild dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */))));
    // 004439f5  680000fe3e             -push 0x3efe0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1056833536 /*0x3efe0000*/;
    cpu.esp -= 4;
    // 004439fa  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004439fd  6800007f3f             -push 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065287680 /*0x3f7f0000*/;
    cpu.esp -= 4;
    // 00443a02  d805dc8a5300           -fadd dword ptr [0x538adc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475036) /* 0x538adc */));
    // 00443a08  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 00443a0d  e844c30900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00443a12  6800007f3f             -push 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065287680 /*0x3f7f0000*/;
    cpu.esp -= 4;
    // 00443a17  db5de4                 -fistp dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00443a1a  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 00443a1f  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00443a22  680000003f             -push 0x3f000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1056964608 /*0x3f000000*/;
    cpu.esp -= 4;
    // 00443a27  d805d88a5300           -fadd dword ptr [0x538ad8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475032) /* 0x538ad8 */));
    // 00443a2d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00443a2e  e823c30900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00443a33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00443a34  db5de0                 -fistp dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00443a37  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00443a3a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00443a3b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00443a3d  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00443a3f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00443a40  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00443a42  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00443a44  e8b7750900             -call 0x4db000
    cpu.esp -= 4;
    sub_4db000(app, cpu);
    if (cpu.terminate) return;
    // 00443a49  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00443a4b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443a4c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443a4d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443a4e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443a4f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443a50  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443a51  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00443a52:
    // 00443a52  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00443a53  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00443a54  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00443a55  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00443a58  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00443a5b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00443a5c  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00443a5f  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00443a62  e8f94d0900             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
    // 00443a67  a164106600             -mov eax, dword ptr [0x661064]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */);
    // 00443a6c  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 00443a6f  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00443a71  8d88ffffff00           -lea ecx, [eax + 0xffffff]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(16777215) /* 0xffffff */);
    // 00443a77  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00443a79  a18c106600             -mov eax, dword ptr [0x66108c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6688908) /* 0x66108c */);
    // 00443a7e  e8dd360900             -call 0x4d7160
    cpu.esp -= 4;
    sub_4d7160(app, cpu);
    if (cpu.terminate) return;
    // 00443a83  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00443a85  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443a86  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443a87  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443a88  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443a89  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443a8a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443a8b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_443a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00443a90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00443a91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00443a92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00443a93  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00443a95  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00443a98  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00443a9a  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 00443a9d  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00443aa0  894de4                 -mov dword ptr [ebp - 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ecx;
    // 00443aa3  be80020000             -mov esi, 0x280
    cpu.esi = 640 /*0x280*/;
    // 00443aa8  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00443aad  bbe0010000             -mov ebx, 0x1e0
    cpu.ebx = 480 /*0x1e0*/;
    // 00443ab2  e849e60000             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 00443ab7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00443ab9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00443abb  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00443abe  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00443ac1  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
L_0x00443ac4:
    // 00443ac4  39f9                   +cmp ecx, edi
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
    // 00443ac6  7d23                   -jge 0x443aeb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00443aeb;
    }
    // 00443ac8  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00443acb  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00443ad2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00443ad4  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00443ad9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00443adb  e840e50000             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00443ae0  3b45f8                 +cmp eax, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443ae3  7e03                   -jle 0x443ae8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00443ae8;
    }
    // 00443ae5  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x00443ae8:
    // 00443ae8  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00443ae9  ebd9                   -jmp 0x443ac4
    goto L_0x00443ac4;
L_0x00443aeb:
    // 00443aeb  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443af2  741d                   -je 0x443b11
    if (cpu.flags.zf)
    {
        goto L_0x00443b11;
    }
    // 00443af4  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00443af7  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00443afa  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00443afd  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00443aff  dc05e08a5300           +fadd qword ptr [0x538ae0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5475040) /* 0x538ae0 */));
    // 00443b05  ddd9                   +fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00443b07  e84ac20900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00443b0c  db5df8                 +fistp dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00443b0f  eb04                   -jmp 0x443b15
    goto L_0x00443b15;
L_0x00443b11:
    // 00443b11  8345f833               -add dword ptr [ebp - 8], 0x33
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)) += x86::reg32(x86::sreg32(51 /*0x33*/));
L_0x00443b15:
    // 00443b15  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00443b17  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00443b1a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00443b1c  83c21e                 -add edx, 0x1e
    (cpu.edx) += x86::reg32(x86::sreg32(30 /*0x1e*/));
    // 00443b1f  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00443b22  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00443b25  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00443b27  8b7de8                 -mov edi, dword ptr [ebp - 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00443b2a  8d481e                 -lea ecx, [eax + 0x1e]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(30) /* 0x1e */);
    // 00443b2d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00443b2f  7403                   -je 0x443b34
    if (cpu.flags.zf)
    {
        goto L_0x00443b34;
    }
    // 00443b31  83c12d                 -add ecx, 0x2d
    (cpu.ecx) += x86::reg32(x86::sreg32(45 /*0x2d*/));
L_0x00443b34:
    // 00443b34  837de400               +cmp dword ptr [ebp - 0x1c], 0
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
    // 00443b38  7403                   -je 0x443b3d
    if (cpu.flags.zf)
    {
        goto L_0x00443b3d;
    }
    // 00443b3a  83c12d                 -add ecx, 0x2d
    (cpu.ecx) += x86::reg32(x86::sreg32(45 /*0x2d*/));
L_0x00443b3d:
    // 00443b3d  3b75f8                 +cmp esi, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443b40  7f06                   -jg 0x443b48
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00443b48;
    }
    // 00443b42  8d46ff                 -lea eax, [esi - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 00443b45  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x00443b48:
    // 00443b48  39d9                   +cmp ecx, ebx
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
    // 00443b4a  7c03                   -jl 0x443b4f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00443b4f;
    }
    // 00443b4c  8d4bff                 -lea ecx, [ebx - 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
L_0x00443b4f:
    // 00443b4f  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443b56  7510                   -jne 0x443b68
    if (!cpu.flags.zf)
    {
        goto L_0x00443b68;
    }
    // 00443b58  817df8be000000         +cmp dword ptr [ebp - 8], 0xbe
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(190 /*0xbe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443b5f  7d07                   -jge 0x443b68
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00443b68;
    }
    // 00443b61  c745f8be000000         -mov dword ptr [ebp - 8], 0xbe
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 190 /*0xbe*/;
L_0x00443b68:
    // 00443b68  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00443b6a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00443b6c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00443b6f  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00443b71  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00443b73  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00443b76  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00443b78  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00443b7b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00443b7d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00443b80  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00443b82  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00443b84  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00443b86  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00443b88  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00443b8a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00443b8d  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00443b8f  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00443b91  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00443b94  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00443b96  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00443b98  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00443b9a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00443b9d  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00443b9f  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00443ba1  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00443ba4  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00443ba6  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00443ba9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00443bab  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00443bae  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00443bb1  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00443bb4  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00443bb6  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00443bb8  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00443bbb  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00443bbe  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00443bc0  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00443bc3  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00443bc6  8a25583a7a00           -mov ah, byte ptr [0x7a3a58]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */);
    // 00443bcc  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00443bce  890d64106600           -mov dword ptr [0x661064], ecx
    app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */) = cpu.ecx;
    // 00443bd4  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00443bd7  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00443bda  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00443bdd  d95b0c                 -fstp dword ptr [ebx + 0xc]
    app->getMemory<float>(cpu.ebx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00443be0  d95b08                 -fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00443be3  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00443be6  7405                   -je 0x443bed
    if (cpu.flags.zf)
    {
        goto L_0x00443bed;
    }
    // 00443be8  e813230000             -call 0x445f00
    cpu.esp -= 4;
    sub_445f00(app, cpu);
    if (cpu.terminate) return;
L_0x00443bed:
    // 00443bed  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00443bef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443bf0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443bf1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443bf2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_443c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00443c00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00443c01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00443c02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00443c03  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00443c04  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00443c06  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00443c09  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00443c0c  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 00443c0f  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00443c12  be80020000             -mov esi, 0x280
    cpu.esi = 640 /*0x280*/;
    // 00443c17  bfe0010000             -mov edi, 0x1e0
    cpu.edi = 480 /*0x1e0*/;
    // 00443c1c  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00443c21  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 00443c26  e8d5e40000             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 00443c2b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00443c2d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00443c2f  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00443c32  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
L_0x00443c35:
    // 00443c35  3b4de8                 +cmp ecx, dword ptr [ebp - 0x18]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443c38  7d24                   -jge 0x443c5e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00443c5e;
    }
    // 00443c3a  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00443c3d  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00443c44  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00443c46  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00443c48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00443c4a  740f                   -je 0x443c5b
    if (cpu.flags.zf)
    {
        goto L_0x00443c5b;
    }
    // 00443c4c  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00443c51  e8cae30000             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00443c56  83c00f                 -add eax, 0xf
    (cpu.eax) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00443c59  01c3                   +add ebx, eax
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
L_0x00443c5b:
    // 00443c5b  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00443c5c  ebd7                   -jmp 0x443c35
    goto L_0x00443c35;
L_0x00443c5e:
    // 00443c5e  b93c000000             -mov ecx, 0x3c
    cpu.ecx = 60 /*0x3c*/;
    // 00443c63  39f3                   +cmp ebx, esi
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
    // 00443c65  7c03                   -jl 0x443c6a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00443c6a;
    }
    // 00443c67  8d5eff                 -lea ebx, [esi - 1]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
L_0x00443c6a:
    // 00443c6a  39f9                   +cmp ecx, edi
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
    // 00443c6c  7c03                   -jl 0x443c71
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00443c71;
    }
    // 00443c6e  8d4fff                 -lea ecx, [edi - 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
L_0x00443c71:
    // 00443c71  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443c78  750d                   -jne 0x443c87
    if (!cpu.flags.zf)
    {
        goto L_0x00443c87;
    }
    // 00443c7a  81fbbe000000           +cmp ebx, 0xbe
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(190 /*0xbe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443c80  7d05                   -jge 0x443c87
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00443c87;
    }
    // 00443c82  bbbe000000             -mov ebx, 0xbe
    cpu.ebx = 190 /*0xbe*/;
L_0x00443c87:
    // 00443c87  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00443c89  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00443c8b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00443c8e  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00443c90  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00443c92  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00443c95  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00443c97  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00443c99  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00443c9b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00443c9e  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00443ca0  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00443ca2  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00443ca4  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00443ca6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00443ca8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00443cab  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00443cad  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00443caf  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00443cb2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00443cb4  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00443cb6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00443cb8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00443cbb  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00443cbd  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00443cbf  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00443cc2  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00443cc4  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00443cc7  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00443cca  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00443ccd  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00443cd0  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00443cd2  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00443cd4  d95a04                 -fstp dword ptr [edx + 4]
    app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00443cd7  d95a0c                 -fstp dword ptr [edx + 0xc]
    app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00443cda  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 00443cdd  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 00443ce0  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00443ce3  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00443ce6  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00443ce8  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00443ceb  d95a08                 -fstp dword ptr [edx + 8]
    app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00443cee  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00443cf0  8a25583a7a00           -mov ah, byte ptr [0x7a3a58]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */);
    // 00443cf6  891564106600           -mov dword ptr [0x661064], edx
    app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */) = cpu.edx;
    // 00443cfc  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00443cff  740a                   -je 0x443d0b
    if (cpu.flags.zf)
    {
        goto L_0x00443d0b;
    }
    // 00443d01  c70564106600ff000000   -mov dword ptr [0x661064], 0xff
    app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */) = 255 /*0xff*/;
L_0x00443d0b:
    // 00443d0b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00443d0d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443d0e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443d0f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443d10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443d11  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_443d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00443d20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00443d21  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00443d22  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00443d23  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00443d25  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00443d28  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00443d2a  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00443d2d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00443d2f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00443d31  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00443d36  e8c5e30000             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 00443d3b  a1408b5500             -mov eax, dword ptr [0x558b40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606208) /* 0x558b40 */);
    // 00443d40  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00443d43  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00443d45  0f84eb000000           -je 0x443e36
    if (cpu.flags.zf)
    {
        goto L_0x00443e36;
    }
    // 00443d4b  d94108                 -fld dword ptr [ecx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 00443d4e  bf80020000             -mov edi, 0x280
    cpu.edi = 640 /*0x280*/;
    // 00443d53  d805e88a5300           -fadd dword ptr [0x538ae8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475048) /* 0x538ae8 */));
    // 00443d59  8d4eff                 -lea ecx, [esi - 1]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 00443d5c  e8f5bf0900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00443d61  db5df8                 -fistp dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
L_0x00443d64:
    // 00443d64  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00443d66  0f8c9d000000           -jl 0x443e09
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00443e09;
    }
    // 00443d6c  83fe0a                 +cmp esi, 0xa
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443d6f  0f8d8e000000           -jge 0x443e03
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00443e03;
    }
    // 00443d75  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00443d78  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00443d7f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00443d81  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00443d83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00443d85  0f8478000000           -je 0x443e03
    if (cpu.flags.zf)
    {
        goto L_0x00443e03;
    }
    // 00443d8b  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00443d8e  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00443d93  83eb1e                 -sub ebx, 0x1e
    (cpu.ebx) -= x86::reg32(x86::sreg32(30 /*0x1e*/));
    // 00443d96  e885e20000             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00443d9b  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00443d9e  8d5805                 -lea ebx, [eax + 5]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00443da1  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00443da3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00443da5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00443da8  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00443daa  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00443dac  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00443daf  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00443db1  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00443db4  668914cd02106600       -mov word ptr [ecx*8 + 0x661002], dx
    app->getMemory<x86::reg16>(x86::reg32(6688770) /* 0x661002 */ + cpu.ecx * 8) = cpu.dx;
    // 00443dbc  8b04cd00106600         -mov eax, dword ptr [ecx*8 + 0x661000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6688768) /* 0x661000 */ + cpu.ecx * 8);
    // 00443dc3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00443dc6  39f8                   +cmp eax, edi
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
    // 00443dc8  7d02                   -jge 0x443dcc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00443dcc;
    }
    // 00443dca  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00443dcc:
    // 00443dcc  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 00443dd3  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00443dd9  66899804106600         -mov word ptr [eax + 0x661004], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6688772) /* 0x661004 */) = cpu.bx;
    // 00443de0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00443de2  740b                   -je 0x443def
    if (cpu.flags.zf)
    {
        goto L_0x00443def;
    }
    // 00443de4  66c780061066001e00     -mov word ptr [eax + 0x661006], 0x1e
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6688774) /* 0x661006 */) = 30 /*0x1e*/;
    // 00443ded  eb09                   -jmp 0x443df8
    goto L_0x00443df8;
L_0x00443def:
    // 00443def  66c780061066001100     -mov word ptr [eax + 0x661006], 0x11
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6688774) /* 0x661006 */) = 17 /*0x11*/;
L_0x00443df8:
    // 00443df8  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00443dfb  668904cd00106600       -mov word ptr [ecx*8 + 0x661000], ax
    app->getMemory<x86::reg16>(x86::reg32(6688768) /* 0x661000 */ + cpu.ecx * 8) = cpu.ax;
L_0x00443e03:
    // 00443e03  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00443e04  e95bffffff             -jmp 0x443d64
    goto L_0x00443d64;
L_0x00443e09:
    // 00443e09  8d4eff                 -lea ecx, [esi - 1]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
L_0x00443e0c:
    // 00443e0c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00443e0e  0f8c20010000           -jl 0x443f34
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00443f34;
    }
    // 00443e14  83fe0a                 +cmp esi, 0xa
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443e17  7d1a                   -jge 0x443e33
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00443e33;
    }
    // 00443e19  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00443e1c  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00443e23  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00443e25  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00443e27  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00443e29  7408                   -je 0x443e33
    if (cpu.flags.zf)
    {
        goto L_0x00443e33;
    }
    // 00443e2b  66893ccd02106600       -mov word ptr [ecx*8 + 0x661002], di
    app->getMemory<x86::reg16>(x86::reg32(6688770) /* 0x661002 */ + cpu.ecx * 8) = cpu.di;
L_0x00443e33:
    // 00443e33  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00443e34  ebd6                   -jmp 0x443e0c
    goto L_0x00443e0c;
L_0x00443e36:
    // 00443e36  d9430c                 -fld dword ptr [ebx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(12) /* 0xc */)));
    // 00443e39  d86104                 -fsub dword ptr [ecx + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */));
    // 00443e3c  e815bf0900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00443e41  db5dec                 -fistp dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00443e44  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00443e47  d94108                 -fld dword ptr [ecx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 00443e4a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00443e4c  8d4e01                 -lea ecx, [esi + 1]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00443e4f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00443e52  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00443e54  d805e88a5300           -fadd dword ptr [0x538ae8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475048) /* 0x538ae8 */));
    // 00443e5a  d805ec8a5300           -fadd dword ptr [0x538aec]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475052) /* 0x538aec */));
    // 00443e60  e8f1be0900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00443e65  db5df8                 -fistp dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00443e68  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00443e6b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00443e6d:
    // 00443e6d  39f1                   +cmp ecx, esi
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
    // 00443e6f  0f8d91000000           -jge 0x443f06
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00443f06;
    }
    // 00443e75  83fe0a                 +cmp esi, 0xa
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443e78  0f8d82000000           -jge 0x443f00
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00443f00;
    }
    // 00443e7e  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00443e81  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00443e88  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00443e8a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00443e8c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00443e8e  7470                   -je 0x443f00
    if (cpu.flags.zf)
    {
        goto L_0x00443f00;
    }
    // 00443e90  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00443e95  e886e10000             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00443e9a  668904cd04106600       -mov word ptr [ecx*8 + 0x661004], ax
    app->getMemory<x86::reg16>(x86::reg32(6688772) /* 0x661004 */ + cpu.ecx * 8) = cpu.ax;
    // 00443ea2  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00443ea5  d94304                 -fld dword ptr [ebx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 00443ea8  e8a9be0900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00443ead  db5dec                 -fistp dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00443eb0  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00443eb3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00443eb5  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00443eb8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00443eba  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00443ebd  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00443ec0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00443ec2  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 00443ec5  8b14cd02106600         -mov edx, dword ptr [ecx*8 + 0x661002]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688770) /* 0x661002 */ + cpu.ecx * 8);
    // 00443ecc  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00443ecf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00443ed1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00443ed4  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00443ed6  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00443ed8  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00443edb  bf1e000000             -mov edi, 0x1e
    cpu.edi = 30 /*0x1e*/;
    // 00443ee0  29c2                   +sub edx, eax
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
    // 00443ee2  66893ccd06106600       -mov word ptr [ecx*8 + 0x661006], di
    app->getMemory<x86::reg16>(x86::reg32(6688774) /* 0x661006 */ + cpu.ecx * 8) = cpu.di;
    // 00443eea  8d4208                 -lea eax, [edx + 8]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00443eed  668904cd02106600       -mov word ptr [ecx*8 + 0x661002], ax
    app->getMemory<x86::reg16>(x86::reg32(6688770) /* 0x661002 */ + cpu.ecx * 8) = cpu.ax;
    // 00443ef5  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00443ef8  668904cd00106600       -mov word ptr [ecx*8 + 0x661000], ax
    app->getMemory<x86::reg16>(x86::reg32(6688768) /* 0x661000 */ + cpu.ecx * 8) = cpu.ax;
L_0x00443f00:
    // 00443f00  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00443f01  e967ffffff             -jmp 0x443e6d
    goto L_0x00443e6d;
L_0x00443f06:
    // 00443f06  833d4cbb6f0003         +cmp dword ptr [0x6fbb4c], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443f0d  7525                   -jne 0x443f34
    if (!cpu.flags.zf)
    {
        goto L_0x00443f34;
    }
    // 00443f0f  83fe02                 +cmp esi, 2
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
    // 00443f12  7520                   -jne 0x443f34
    if (!cpu.flags.zf)
    {
        goto L_0x00443f34;
    }
    // 00443f14  668b150a106600         -mov dx, word ptr [0x66100a]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(6688778) /* 0x66100a */);
    // 00443f1b  66a102106600           -mov ax, word ptr [0x661002]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(6688770) /* 0x661002 */);
    // 00443f21  83c205                 -add edx, 5
    (cpu.edx) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 00443f24  83e805                 -sub eax, 5
    (cpu.eax) -= x86::reg32(x86::sreg32(5 /*0x5*/));
    // 00443f27  6689150a106600         -mov word ptr [0x66100a], dx
    app->getMemory<x86::reg16>(x86::reg32(6688778) /* 0x66100a */) = cpu.dx;
    // 00443f2e  66a302106600           -mov word ptr [0x661002], ax
    app->getMemory<x86::reg16>(x86::reg32(6688770) /* 0x661002 */) = cpu.ax;
L_0x00443f34:
    // 00443f34  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00443f36  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443f37  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443f38  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443f39  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_443f40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00443f40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00443f41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00443f42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00443f43  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00443f44  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00443f46  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00443f49  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00443f4c  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 00443f4f  d9430c                 -fld dword ptr [ebx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(12) /* 0xc */)));
    // 00443f52  d86304                 -fsub dword ptr [ebx + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */));
    // 00443f55  dc0df08a5300           -fmul qword ptr [0x538af0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5475056) /* 0x538af0 */));
    // 00443f5b  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 00443f5d  e8f4bd0900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00443f62  db5dfc                 -fistp dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00443f65  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00443f68  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00443f6a  83c013                 -add eax, 0x13
    (cpu.eax) += x86::reg32(x86::sreg32(19 /*0x13*/));
    // 00443f6d  d94304                 -fld dword ptr [ebx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 00443f70  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00443f73  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00443f75  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00443f7a  e8d7bd0900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00443f7f  db5df4                 -fistp dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00443f82  e879e10000             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
L_0x00443f87:
    // 00443f87  3b75e8                 +cmp esi, dword ptr [ebp - 0x18]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443f8a  7d6b                   -jge 0x443ff7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00443ff7;
    }
    // 00443f8c  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00443f8f  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00443f96  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00443f98  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 00443f9a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00443f9c  7456                   -je 0x443ff4
    if (cpu.flags.zf)
    {
        goto L_0x00443ff4;
    }
    // 00443f9e  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00443fa5  741e                   -je 0x443fc5
    if (cpu.flags.zf)
    {
        goto L_0x00443fc5;
    }
    // 00443fa7  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00443faa  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00443fad  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00443fb0  d805f88a5300           +fadd dword ptr [0x538af8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475064) /* 0x538af8 */));
    // 00443fb6  b8fd9d64ff             -mov eax, 0xff649dfd
    cpu.eax = 4284784125 /*0xff649dfd*/;
    // 00443fbb  e896bd0900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00443fc0  db5df8                 +fistp dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00443fc3  eb0e                   -jmp 0x443fd3
    goto L_0x00443fd3;
L_0x00443fc5:
    // 00443fc5  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00443fc8  83c019                 -add eax, 0x19
    (cpu.eax) += x86::reg32(x86::sreg32(25 /*0x19*/));
    // 00443fcb  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00443fce  b8fd9d6400             -mov eax, 0x649dfd
    cpu.eax = 6594045 /*0x649dfd*/;
L_0x00443fd3:
    // 00443fd3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00443fd4  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 00443fd7  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00443fdc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00443fde  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00443fe1  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00443fe4  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00443fe6  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00443fe9  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00443feb  01c3                   +add ebx, eax
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
    // 00443fed  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00443fef  e89ce10000             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
L_0x00443ff4:
    // 00443ff4  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00443ff5  eb90                   -jmp 0x443f87
    goto L_0x00443f87;
L_0x00443ff7:
    // 00443ff7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00443ff9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443ffa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443ffb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443ffc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00443ffd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_444000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00444000  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00444001  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00444002  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00444003  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00444004  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00444005  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00444007  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0044400a  8955cc                 -mov dword ptr [ebp - 0x34], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.edx;
    // 0044400d  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00444012  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00444014  e8e7e00000             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 00444019  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
L_0x0044401c:
    // 0044401c  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0044401f  3b05308b5500           +cmp eax, dword ptr [0x558b30]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00444025  0f8d1d030000           -jge 0x444348
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00444348;
    }
    // 0044402b  8b15348b5500           -mov edx, dword ptr [0x558b34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606196) /* 0x558b34 */);
    // 00444031  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00444034  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00444037  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00444039  0f8401030000           -je 0x444340
    if (cpu.flags.zf)
    {
        goto L_0x00444340;
    }
    // 0044403f  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00444042  8b14c500106600         -mov edx, dword ptr [eax*8 + 0x661000]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688768) /* 0x661000 */ + cpu.eax * 8);
    // 00444049  8b0cc502106600         -mov ecx, dword ptr [eax*8 + 0x661002]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6688770) /* 0x661002 */ + cpu.eax * 8);
    // 00444050  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00444053  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00444056  8955e0                 -mov dword ptr [ebp - 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edx;
    // 00444059  8b14c5fe0f6600         -mov edx, dword ptr [eax*8 + 0x660ffe]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688766) /* 0x660ffe */ + cpu.eax * 8);
    // 00444060  8d7908                 -lea edi, [ecx + 8]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00444063  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00444066  83c105                 -add ecx, 5
    (cpu.ecx) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 00444069  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 0044406c  8b1564106600           -mov edx, dword ptr [0x661064]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */);
    // 00444072  894dd0                 -mov dword ptr [ebp - 0x30], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.ecx;
    // 00444075  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 00444078  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0044407b  8d824bd8ff00           -lea eax, [edx + 0xffd84b]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(16767051) /* 0xffd84b */);
    // 00444081  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00444084  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00444087  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0044408a  46                     -inc esi
    (cpu.esi)++;
    // 0044408b  83e807                 -sub eax, 7
    (cpu.eax) -= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0044408e  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00444091  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 00444094  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00444097  895dd4                 -mov dword ptr [ebp - 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ebx;
    // 0044409a  83e803                 -sub eax, 3
    (cpu.eax) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0044409d  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004440a0  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 004440a3  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004440a6  8d8affffff00           -lea ecx, [edx + 0xffffff]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(16777215) /* 0xffffff */);
    // 004440ac  83e811                 -sub eax, 0x11
    (cpu.eax) -= x86::reg32(x86::sreg32(17 /*0x11*/));
    // 004440af  3b5dcc                 +cmp ebx, dword ptr [ebp - 0x34]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004440b2  0f853e010000           -jne 0x4441f6
    if (!cpu.flags.zf)
    {
        goto L_0x004441f6;
    }
    // 004440b8  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004440bf  0f84d0000000           -je 0x444195
    if (cpu.flags.zf)
    {
        goto L_0x00444195;
    }
    // 004440c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004440c6  8b0d389a7400           -mov ecx, dword ptr [0x749a38]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7641656) /* 0x749a38 */);
    // 004440cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004440cd  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004440d0  680000273f             -push 0x3f270000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059520512 /*0x3f270000*/;
    cpu.esp -= 4;
    // 004440d5  8975f8                 -mov dword ptr [ebp - 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 004440d8  6800000d3f             -push 0x3f0d0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1057816576 /*0x3f0d0000*/;
    cpu.esp -= 4;
    // 004440dd  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004440e0  680000273f             -push 0x3f270000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059520512 /*0x3f270000*/;
    cpu.esp -= 4;
    // 004440e5  db45f8                 +fild dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */))));
    // 004440e8  6800001d3f             -push 0x3f1d0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058865152 /*0x3f1d0000*/;
    cpu.esp -= 4;
    // 004440ed  d805008b5300           +fadd dword ptr [0x538b00]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475072) /* 0x538b00 */));
    // 004440f3  680000143f             -push 0x3f140000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058275328 /*0x3f140000*/;
    cpu.esp -= 4;
    // 004440f8  e859bc0900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 004440fd  6800001d3f             -push 0x3f1d0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058865152 /*0x3f1d0000*/;
    cpu.esp -= 4;
    // 00444102  db5dc8                 +fistp dword ptr [ebp - 0x38]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00444105  680000143f             -push 0x3f140000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058275328 /*0x3f140000*/;
    cpu.esp -= 4;
    // 0044410a  8b5dc8                 -mov ebx, dword ptr [ebp - 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0044410d  6800000d3f             -push 0x3f0d0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1057816576 /*0x3f0d0000*/;
    cpu.esp -= 4;
    // 00444112  d805fc8a5300           +fadd dword ptr [0x538afc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475068) /* 0x538afc */));
    // 00444118  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00444119  e838bc0900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 0044411e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044411f  db5dc4                 +fistp dword ptr [ebp - 0x3c]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00444122  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00444123  8b4dc4                 -mov ecx, dword ptr [ebp - 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 00444126  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00444128  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00444129  8b5dc4                 -mov ebx, dword ptr [ebp - 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 0044412c  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0044412e  e8cd6e0900             -call 0x4db000
    cpu.esp -= 4;
    sub_4db000(app, cpu);
    if (cpu.terminate) return;
    // 00444133  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00444136  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00444137  684bd8ff00             -push 0xffd84b
    app->getMemory<x86::reg32>(cpu.esp-4) = 16767051 /*0xffd84b*/;
    cpu.esp -= 4;
    // 0044413c  684bd8ff00             -push 0xffd84b
    app->getMemory<x86::reg32>(cpu.esp-4) = 16767051 /*0xffd84b*/;
    cpu.esp -= 4;
    // 00444141  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00444146  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00444149  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044414a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0044414c  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0044414e  e80d470900             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
    // 00444153  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00444156  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00444159  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0044415e  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00444160  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00444163  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00444164  db45f8                 +fild dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */))));
    // 00444167  684bd8ff00             -push 0xffd84b
    app->getMemory<x86::reg32>(cpu.esp-4) = 16767051 /*0xffd84b*/;
    cpu.esp -= 4;
    // 0044416c  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0044416f  d805008b5300           +fadd dword ptr [0x538b00]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475072) /* 0x538b00 */));
    // 00444175  684bd8ff00             -push 0xffd84b
    app->getMemory<x86::reg32>(cpu.esp-4) = 16767051 /*0xffd84b*/;
    cpu.esp -= 4;
    // 0044417a  e8d7bb0900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 0044417f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00444180  db5df8                 +fistp dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00444183  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00444186  e8d5460900             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
    // 0044418b  6840e4ff00             -push 0xffe440
    app->getMemory<x86::reg32>(cpu.esp-4) = 16770112 /*0xffe440*/;
    cpu.esp -= 4;
    // 00444190  e996010000             -jmp 0x44432b
    goto L_0x0044432b;
L_0x00444195:
    // 00444195  8b1560106600           -mov edx, dword ptr [0x661060]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688864) /* 0x661060 */);
    // 0044419b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0044419d  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004441a0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004441a2  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004441a5  e8b62f0900             -call 0x4d7160
    cpu.esp -= 4;
    sub_4d7160(app, cpu);
    if (cpu.terminate) return;
    // 004441aa  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004441ad  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004441ae  684bd8ff00             -push 0xffd84b
    app->getMemory<x86::reg32>(cpu.esp-4) = 16767051 /*0xffd84b*/;
    cpu.esp -= 4;
    // 004441b3  684bd8ff00             -push 0xffd84b
    app->getMemory<x86::reg32>(cpu.esp-4) = 16767051 /*0xffd84b*/;
    cpu.esp -= 4;
    // 004441b8  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004441bd  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004441c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004441c1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004441c3  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004441c5  e896460900             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
    // 004441ca  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004441cd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004441ce  684bd8ff00             -push 0xffd84b
    app->getMemory<x86::reg32>(cpu.esp-4) = 16767051 /*0xffd84b*/;
    cpu.esp -= 4;
    // 004441d3  684bd8ff00             -push 0xffd84b
    app->getMemory<x86::reg32>(cpu.esp-4) = 16767051 /*0xffd84b*/;
    cpu.esp -= 4;
    // 004441d8  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004441dd  8b5dd0                 -mov ebx, dword ptr [ebp - 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004441e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004441e1  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004441e4  8b55d4                 -mov edx, dword ptr [ebp - 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004441e7  e874460900             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
    // 004441ec  6840e4ff00             -push 0xffe440
    app->getMemory<x86::reg32>(cpu.esp-4) = 16770112 /*0xffe440*/;
    cpu.esp -= 4;
    // 004441f1  e935010000             -jmp 0x44432b
    goto L_0x0044432b;
L_0x004441f6:
    // 004441f6  81c2b37e7200           -add edx, 0x727eb3
    (cpu.edx) += x86::reg32(x86::sreg32(7503539 /*0x727eb3*/));
    // 004441fc  8b1d34925500           -mov ebx, dword ptr [0x559234]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00444202  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00444205  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00444207  0f84c2000000           -je 0x4442cf
    if (cpu.flags.zf)
    {
        goto L_0x004442cf;
    }
    // 0044420d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044420e  8b15389a7400           -mov edx, dword ptr [0x749a38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7641656) /* 0x749a38 */);
    // 00444214  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00444215  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00444218  680000273f             -push 0x3f270000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059520512 /*0x3f270000*/;
    cpu.esp -= 4;
    // 0044421d  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00444220  680000f83e             -push 0x3ef80000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1056440320 /*0x3ef80000*/;
    cpu.esp -= 4;
    // 00444225  db45f8                 +fild dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */))));
    // 00444228  680000273f             -push 0x3f270000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059520512 /*0x3f270000*/;
    cpu.esp -= 4;
    // 0044422d  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00444230  6800000c3f             -push 0x3f0c0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1057751040 /*0x3f0c0000*/;
    cpu.esp -= 4;
    // 00444235  d805008b5300           +fadd dword ptr [0x538b00]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475072) /* 0x538b00 */));
    // 0044423b  680000143f             -push 0x3f140000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058275328 /*0x3f140000*/;
    cpu.esp -= 4;
    // 00444240  e811bb0900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00444245  6800000c3f             -push 0x3f0c0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1057751040 /*0x3f0c0000*/;
    cpu.esp -= 4;
    // 0044424a  db5dc8                 +fistp dword ptr [ebp - 0x38]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0044424d  680000143f             -push 0x3f140000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058275328 /*0x3f140000*/;
    cpu.esp -= 4;
    // 00444252  8b4dc8                 -mov ecx, dword ptr [ebp - 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 00444255  680000f83e             -push 0x3ef80000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1056440320 /*0x3ef80000*/;
    cpu.esp -= 4;
    // 0044425a  d805fc8a5300           +fadd dword ptr [0x538afc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475068) /* 0x538afc */));
    // 00444260  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00444261  e8f0ba0900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00444266  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00444267  db5dc4                 +fistp dword ptr [ebp - 0x3c]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0044426a  8b55c4                 -mov edx, dword ptr [ebp - 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 0044426d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044426e  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00444270  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00444271  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00444273  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00444275  e8866d0900             -call 0x4db000
    cpu.esp -= 4;
    sub_4db000(app, cpu);
    if (cpu.terminate) return;
    // 0044427a  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0044427d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044427e  68b37e7200             -push 0x727eb3
    app->getMemory<x86::reg32>(cpu.esp-4) = 7503539 /*0x727eb3*/;
    cpu.esp -= 4;
    // 00444283  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00444286  68b37e7200             -push 0x727eb3
    app->getMemory<x86::reg32>(cpu.esp-4) = 7503539 /*0x727eb3*/;
    cpu.esp -= 4;
    // 0044428b  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0044428d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0044428f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00444290  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00444295  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00444298  e8c3450900             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
    // 0044429d  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004442a0  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004442a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004442a6  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004442a8  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004442ab  68b37e7200             -push 0x727eb3
    app->getMemory<x86::reg32>(cpu.esp-4) = 7503539 /*0x727eb3*/;
    cpu.esp -= 4;
    // 004442b0  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004442b3  68b37e7200             -push 0x727eb3
    app->getMemory<x86::reg32>(cpu.esp-4) = 7503539 /*0x727eb3*/;
    cpu.esp -= 4;
    // 004442b8  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004442bb  d805008b5300           +fadd dword ptr [0x538b00]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475072) /* 0x538b00 */));
    // 004442c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004442c2  e88fba0900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 004442c7  db5df8                 +fistp dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004442ca  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004442cd  eb52                   -jmp 0x444321
    goto L_0x00444321;
L_0x004442cf:
    // 004442cf  8b1568106600           -mov edx, dword ptr [0x661068]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688872) /* 0x661068 */);
    // 004442d5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004442d7  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004442da  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004442dc  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004442df  e87c2e0900             -call 0x4d7160
    cpu.esp -= 4;
    sub_4d7160(app, cpu);
    if (cpu.terminate) return;
    // 004442e4  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004442e7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004442e8  68b37e7200             -push 0x727eb3
    app->getMemory<x86::reg32>(cpu.esp-4) = 7503539 /*0x727eb3*/;
    cpu.esp -= 4;
    // 004442ed  68b37e7200             -push 0x727eb3
    app->getMemory<x86::reg32>(cpu.esp-4) = 7503539 /*0x727eb3*/;
    cpu.esp -= 4;
    // 004442f2  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004442f7  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004442fa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004442fb  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004442fd  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004442ff  e85c450900             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
    // 00444304  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00444307  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00444308  68b37e7200             -push 0x727eb3
    app->getMemory<x86::reg32>(cpu.esp-4) = 7503539 /*0x727eb3*/;
    cpu.esp -= 4;
    // 0044430d  68b37e7200             -push 0x727eb3
    app->getMemory<x86::reg32>(cpu.esp-4) = 7503539 /*0x727eb3*/;
    cpu.esp -= 4;
    // 00444312  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00444317  8b55d4                 -mov edx, dword ptr [ebp - 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0044431a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044431b  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0044431e  8b5dd0                 -mov ebx, dword ptr [ebp - 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
L_0x00444321:
    // 00444321  e83a450900             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
    // 00444326  68fd9d6400             -push 0x649dfd
    app->getMemory<x86::reg32>(cpu.esp-4) = 6594045 /*0x649dfd*/;
    cpu.esp -= 4;
L_0x0044432b:
    // 0044432b  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00444330  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00444333  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00444335  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00444338  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0044433b  e850de0000             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
L_0x00444340:
    // 00444340  ff45ec                 +inc dword ptr [ebp - 0x14]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00444343  e9d4fcffff             -jmp 0x44401c
    goto L_0x0044401c;
L_0x00444348:
    // 00444348  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044434a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044434b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044434c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044434d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044434e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044434f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_444350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00444350  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00444351  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00444352  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00444353  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00444354  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00444355  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00444356  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00444358  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0044435b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044435d  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00444362  b8588b5500             -mov eax, 0x558b58
    cpu.eax = 5606232 /*0x558b58*/;
    // 00444367  e8b4dc0000             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 0044436c  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0044436f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00444371  d8460c                 -fadd dword ptr [esi + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */));
    // 00444374  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00444377  e8dab90900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 0044437c  db5dec                 -fistp dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0044437f  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00444382  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00444384  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00444387  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00444389  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0044438b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044438d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044438f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00444391  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00444394  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00444396  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00444398  d94608                 -fld dword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 0044439b  d805088b5300           -fadd dword ptr [0x538b08]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475080) /* 0x538b08 */));
    // 004443a1  d8050c8b5300           -fadd dword ptr [0x538b0c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475084) /* 0x538b0c */));
    // 004443a7  e8aab90900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 004443ac  db5dfc                 -fistp dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004443af  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004443b1  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 004443b7  8d7bfd                 -lea edi, [ebx - 3]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(-3) /* -0x3 */);
    // 004443ba  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004443bc  0f857d000000           -jne 0x44443f
    if (!cpu.flags.zf)
    {
        goto L_0x0044443f;
    }
    // 004443c2  d9460c                 -fld dword ptr [esi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 004443c5  d86604                 -fsub dword ptr [esi + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */));
    // 004443c8  8b0d70106600           -mov ecx, dword ptr [0x661070]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6688880) /* 0x661070 */);
    // 004443ce  e883b90900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 004443d3  db5dec                 -fistp dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004443d6  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004443d9  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004443db  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004443dd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004443e0  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004443e2  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004443e4  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004443e7  e86ab90900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 004443ec  db5dec                 -fistp dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004443ef  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004443f2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004443f4  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004443f7  48                     -dec eax
    (cpu.eax)--;
    // 004443f8  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004443fb  a164106600             -mov eax, dword ptr [0x661064]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */);
    // 00444400  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00444403  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00444406  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00444408  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044440b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044440d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0044440f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00444411  b9ff000000             -mov ecx, 0xff
    cpu.ecx = 255 /*0xff*/;
    // 00444416  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00444419  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0044441b  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0044441e  8b1564106600           -mov edx, dword ptr [0x661064]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */);
    // 00444424  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00444427  39ca                   +cmp edx, ecx
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
    // 00444429  7c14                   -jl 0x44443f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044443f;
    }
    // 0044442b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044442c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044442d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044442e  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00444433  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00444434  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00444437  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0044443a  e881460900             -call 0x4d8ac0
    cpu.esp -= 4;
    sub_4d8ac0(app, cpu);
    if (cpu.terminate) return;
L_0x0044443f:
    // 0044443f  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00444444  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00444449  e8b2dc0000             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 0044444e  b8588b5500             -mov eax, 0x558b58
    cpu.eax = 5606232 /*0x558b58*/;
    // 00444453  e8c8db0000             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00444458  8b1d70106600           -mov ebx, dword ptr [0x661070]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6688880) /* 0x661070 */);
    // 0044445e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00444460  39d8                   +cmp eax, ebx
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
    // 00444462  7e51                   -jle 0x4444b5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004444b5;
    }
    // 00444464  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00444467  d8460c                 -fadd dword ptr [esi + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */));
    // 0044446a  e8e7b80900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 0044446f  db5dec                 -fistp dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00444472  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00444475  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00444477  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0044447a  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044447c  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0044447e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00444480  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00444482  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00444484  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00444487  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00444489  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0044448b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044448d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044448f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00444491  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00444493  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00444495  8b3534925500           -mov esi, dword ptr [0x559234]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 0044449b  8d7af9                 -lea edi, [edx - 7]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(-7) /* -0x7 */);
    // 0044449e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004444a0  7513                   -jne 0x4444b5
    if (!cpu.flags.zf)
    {
        goto L_0x004444b5;
    }
    // 004444a2  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 004444a7  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 004444ac  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004444ae  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004444b0  e82ba70700             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
L_0x004444b5:
    // 004444b5  6840e4ff00             -push 0xffe440
    app->getMemory<x86::reg32>(cpu.esp-4) = 16770112 /*0xffe440*/;
    cpu.esp -= 4;
    // 004444ba  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 004444bf  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004444c2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004444c4  b8588b5500             -mov eax, 0x558b58
    cpu.eax = 5606232 /*0x558b58*/;
    // 004444c9  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004444cb  e8c0dc0000             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 004444d0  8b15088d5500           -mov edx, dword ptr [0x558d08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606664) /* 0x558d08 */);
    // 004444d6  42                     -inc edx
    (cpu.edx)++;
    // 004444d7  b919000000             -mov ecx, 0x19
    cpu.ecx = 25 /*0x19*/;
    // 004444dc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004444de  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004444e1  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004444e3  8915088d5500           -mov dword ptr [0x558d08], edx
    app->getMemory<x86::reg32>(x86::reg32(5606664) /* 0x558d08 */) = cpu.edx;
    // 004444e9  83fa0c                 +cmp edx, 0xc
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
    // 004444ec  7e54                   -jle 0x444542
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00444542;
    }
    // 004444ee  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004444f1  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 004444f7  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004444f9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004444fb  741d                   -je 0x44451a
    if (cpu.flags.zf)
    {
        goto L_0x0044451a;
    }
    // 004444fd  6840e4ff00             -push 0xffe440
    app->getMemory<x86::reg32>(cpu.esp-4) = 16770112 /*0xffe440*/;
    cpu.esp -= 4;
    // 00444502  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00444507  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044450a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044450c  b8048b5300             -mov eax, 0x538b04
    cpu.eax = 5475076 /*0x538b04*/;
    // 00444511  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00444513  e878dc0000             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00444518  eb28                   -jmp 0x444542
    goto L_0x00444542;
L_0x0044451a:
    // 0044451a  a164106600             -mov eax, dword ptr [0x661064]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */);
    // 0044451f  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 00444522  0540e4ff00             -add eax, 0xffe440
    (cpu.eax) += x86::reg32(x86::sreg32(16770112 /*0xffe440*/));
    // 00444527  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00444528  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00444529  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044452c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044452d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00444532  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 00444537  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00444538  83c20d                 -add edx, 0xd
    (cpu.edx) += x86::reg32(x86::sreg32(13 /*0xd*/));
    // 0044453b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044453d  e81e430900             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
L_0x00444542:
    // 00444542  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00444549  7513                   -jne 0x44455e
    if (!cpu.flags.zf)
    {
        goto L_0x0044455e;
    }
    // 0044454b  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 00444550  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 00444555  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00444557  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00444559  e882a60700             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
L_0x0044455e:
    // 0044455e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00444560  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444561  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444562  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444563  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444564  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444565  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444566  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_444570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00444570  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00444571  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00444572  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00444573  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00444575  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00444577  7c51                   -jl 0x4445ca
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004445ca;
    }
    // 00444579  3b05308b5500           +cmp eax, dword ptr [0x558b30]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044457f  7d49                   -jge 0x4445ca
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004445ca;
    }
    // 00444581  8b0cc500106600         -mov ecx, dword ptr [eax*8 + 0x661000]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6688768) /* 0x661000 */ + cpu.eax * 8);
    // 00444588  8b14c502106600         -mov edx, dword ptr [eax*8 + 0x661002]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688770) /* 0x661002 */ + cpu.eax * 8);
    // 0044458f  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00444592  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00444595  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00444597  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044459a  8915e4e55500           -mov dword ptr [0x55e5e4], edx
    app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */) = cpu.edx;
    // 004445a0  8b14c504106600         -mov edx, dword ptr [eax*8 + 0x661004]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688772) /* 0x661004 */ + cpu.eax * 8);
    // 004445a7  8b04c5fe0f6600         -mov eax, dword ptr [eax*8 + 0x660ffe]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6688766) /* 0x660ffe */ + cpu.eax * 8);
    // 004445ae  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004445b1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004445b4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004445b6  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004445b9  a3e8e55500             -mov dword ptr [0x55e5e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */) = cpu.eax;
    // 004445be  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004445c0  a1e4e55500             -mov eax, dword ptr [0x55e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 004445c5  e8f6790500             -call 0x49bfc0
    cpu.esp -= 4;
    sub_49bfc0(app, cpu);
    if (cpu.terminate) return;
L_0x004445ca:
    // 004445ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004445cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004445cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004445cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4445d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004445d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004445d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004445d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004445d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004445d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004445d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004445d6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004445d8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004445db  8b35e8e55500           -mov esi, dword ptr [0x55e5e8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 004445e1  8b3de4e55500           -mov edi, dword ptr [0x55e5e4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 004445e7  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004445ee  7454                   -je 0x444644
    if (cpu.flags.zf)
    {
        goto L_0x00444644;
    }
    // 004445f0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004445f2:
    // 004445f2  3b05308b5500           +cmp eax, dword ptr [0x558b30]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004445f8  0f8da0000000           -jge 0x44469e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044469e;
    }
    // 004445fe  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 00444605  8b8afe0f6600           -mov ecx, dword ptr [edx + 0x660ffe]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6688766) /* 0x660ffe */);
    // 0044460b  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0044460e  39ce                   +cmp esi, ecx
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
    // 00444610  7e2f                   -jle 0x444641
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00444641;
    }
    // 00444612  8b9a04106600           -mov ebx, dword ptr [edx + 0x661004]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6688772) /* 0x661004 */);
    // 00444618  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0044461b  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0044461d  39ce                   +cmp esi, ecx
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
    // 0044461f  7d20                   -jge 0x444641
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00444641;
    }
    // 00444621  8b8a00106600           -mov ecx, dword ptr [edx + 0x661000]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6688768) /* 0x661000 */);
    // 00444627  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0044462a  39cf                   +cmp edi, ecx
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
    // 0044462c  7e13                   -jle 0x444641
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00444641;
    }
    // 0044462e  8b9202106600           -mov edx, dword ptr [edx + 0x661002]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6688770) /* 0x661002 */);
    // 00444634  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00444637  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00444639  39d7                   +cmp edi, edx
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
    // 0044463b  0f8c62000000           -jl 0x4446a3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004446a3;
    }
L_0x00444641:
    // 00444641  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00444642  ebae                   -jmp 0x4445f2
    goto L_0x004445f2;
L_0x00444644:
    // 00444644  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00444646:
    // 00444646  3b05308b5500           +cmp eax, dword ptr [0x558b30]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044464c  7d50                   -jge 0x44469e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044469e;
    }
    // 0044464e  8b0cc500106600         -mov ecx, dword ptr [eax*8 + 0x661000]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6688768) /* 0x661000 */ + cpu.eax * 8);
    // 00444655  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00444658  8d59f1                 -lea ebx, [ecx - 0xf]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(-15) /* -0xf */);
    // 0044465b  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 0044465e  8b1cc502106600         -mov ebx, dword ptr [eax*8 + 0x661002]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6688770) /* 0x661002 */ + cpu.eax * 8);
    // 00444665  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00444668  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0044466a  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0044466d  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00444670  8b0cc5fe0f6600         -mov ecx, dword ptr [eax*8 + 0x660ffe]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6688766) /* 0x660ffe */ + cpu.eax * 8);
    // 00444677  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0044467a  8b14c504106600         -mov edx, dword ptr [eax*8 + 0x661004]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688772) /* 0x661004 */ + cpu.eax * 8);
    // 00444681  8d59ff                 -lea ebx, [ecx - 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00444684  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00444687  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00444689  39de                   +cmp esi, ebx
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
    // 0044468b  7e0e                   -jle 0x44469b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044469b;
    }
    // 0044468d  39d6                   +cmp esi, edx
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
    // 0044468f  7d0a                   -jge 0x44469b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044469b;
    }
    // 00444691  3b7df8                 +cmp edi, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00444694  7e05                   -jle 0x44469b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044469b;
    }
    // 00444696  3b7dfc                 +cmp edi, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00444699  7c08                   -jl 0x4446a3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004446a3;
    }
L_0x0044469b:
    // 0044469b  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044469c  eba8                   -jmp 0x444646
    goto L_0x00444646;
L_0x0044469e:
    // 0044469e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004446a3:
    // 004446a3  893de4e55500           -mov dword ptr [0x55e5e4], edi
    app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */) = cpu.edi;
    // 004446a9  8935e8e55500           -mov dword ptr [0x55e5e8], esi
    app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */) = cpu.esi;
    // 004446af  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004446b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004446b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004446b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004446b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004446b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004446b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004446b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4446c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004446c0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004446c1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004446c3  a13c8b5500             -mov eax, dword ptr [0x558b3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */);
    // 004446c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004446c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4446d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004446d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004446d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004446d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004446d3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004446d5  83ec48                 -sub esp, 0x48
    (cpu.esp) -= x86::reg32(x86::sreg32(72 /*0x48*/));
    // 004446d8  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004446db  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004446dd  893d0c8b5500           -mov dword ptr [0x558b0c], edi
    app->getMemory<x86::reg32>(x86::reg32(5606156) /* 0x558b0c */) = cpu.edi;
    // 004446e3  893d388b5500           -mov dword ptr [0x558b38], edi
    app->getMemory<x86::reg32>(x86::reg32(5606200) /* 0x558b38 */) = cpu.edi;
    // 004446e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004446eb  0f8414020000           -je 0x444905
    if (cpu.flags.zf)
    {
        goto L_0x00444905;
    }
    // 004446f1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004446f3  0f840c020000           -je 0x444905
    if (cpu.flags.zf)
    {
        goto L_0x00444905;
    }
    // 004446f9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004446fb  0f8404020000           -je 0x444905
    if (cpu.flags.zf)
    {
        goto L_0x00444905;
    }
    // 00444701  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00444703  0f84fc010000           -je 0x444905
    if (cpu.flags.zf)
    {
        goto L_0x00444905;
    }
    // 00444709  83fb0a                 +cmp ebx, 0xa
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044470c  0f8df3010000           -jge 0x444905
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00444905;
    }
    // 00444712  a31c8b5500             -mov dword ptr [0x558b1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5606172) /* 0x558b1c */) = cpu.eax;
    // 00444717  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044471c  8915208b5500           -mov dword ptr [0x558b20], edx
    app->getMemory<x86::reg32>(x86::reg32(5606176) /* 0x558b20 */) = cpu.edx;
    // 00444722  a3148b5500             -mov dword ptr [0x558b14], eax
    app->getMemory<x86::reg32>(x86::reg32(5606164) /* 0x558b14 */) = cpu.eax;
    // 00444727  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 00444729  891d308b5500           -mov dword ptr [0x558b30], ebx
    app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */) = cpu.ebx;
    // 0044472f  8825108b5500           -mov byte ptr [0x558b10], ah
    app->getMemory<x86::reg8>(x86::reg32(5606160) /* 0x558b10 */) = cpu.ah;
    // 00444735  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00444738  890d348b5500           -mov dword ptr [0x558b34], ecx
    app->getMemory<x86::reg32>(x86::reg32(5606196) /* 0x558b34 */) = cpu.ecx;
    // 0044473e  a33c8b5500             -mov dword ptr [0x558b3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.eax;
    // 00444743  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00444746  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00444749  a3388b5500             -mov dword ptr [0x558b38], eax
    app->getMemory<x86::reg32>(x86::reg32(5606200) /* 0x558b38 */) = cpu.eax;
    // 0044474e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00444750  7d08                   -jge 0x44475a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044475a;
    }
    // 00444752  893d3c8b5500           -mov dword ptr [0x558b3c], edi
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.edi;
    // 00444758  eb0b                   -jmp 0x444765
    goto L_0x00444765;
L_0x0044475a:
    // 0044475a  4b                     -dec ebx
    (cpu.ebx)--;
    // 0044475b  39d3                   +cmp ebx, edx
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
    // 0044475d  7d06                   -jge 0x444765
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00444765;
    }
    // 0044475f  891d3c8b5500           -mov dword ptr [0x558b3c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.ebx;
L_0x00444765:
    // 00444765  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00444767  7432                   -je 0x44479b
    if (cpu.flags.zf)
    {
        goto L_0x0044479b;
    }
    // 00444769  8d45c8                 -lea eax, [ebp - 0x38]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0044476c  8b15208b5500           -mov edx, dword ptr [0x558b20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606176) /* 0x558b20 */);
    // 00444772  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00444774  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00444775  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00444777  a11c8b5500             -mov eax, dword ptr [0x558b1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606172) /* 0x558b1c */);
    // 0044477c  e80ff3ffff             -call 0x443a90
    cpu.esp -= 4;
    sub_443a90(app, cpu);
    if (cpu.terminate) return;
    // 00444781  8d45b8                 -lea eax, [ebp - 0x48]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-72) /* -0x48 */);
    // 00444784  8b15348b5500           -mov edx, dword ptr [0x558b34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606196) /* 0x558b34 */);
    // 0044478a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044478c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044478d  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0044478f  a1308b5500             -mov eax, dword ptr [0x558b30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */);
    // 00444794  e8f7f2ffff             -call 0x443a90
    cpu.esp -= 4;
    sub_443a90(app, cpu);
    if (cpu.terminate) return;
    // 00444799  eb2e                   -jmp 0x4447c9
    goto L_0x004447c9;
L_0x0044479b:
    // 0044479b  8d45c8                 -lea eax, [ebp - 0x38]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0044479e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004447a3  8b15208b5500           -mov edx, dword ptr [0x558b20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606176) /* 0x558b20 */);
    // 004447a9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004447aa  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004447ac  a11c8b5500             -mov eax, dword ptr [0x558b1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606172) /* 0x558b1c */);
    // 004447b1  e8daf2ffff             -call 0x443a90
    cpu.esp -= 4;
    sub_443a90(app, cpu);
    if (cpu.terminate) return;
    // 004447b6  8d5db8                 -lea ebx, [ebp - 0x48]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-72) /* -0x48 */);
    // 004447b9  8b15348b5500           -mov edx, dword ptr [0x558b34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606196) /* 0x558b34 */);
    // 004447bf  a1308b5500             -mov eax, dword ptr [0x558b30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */);
    // 004447c4  e837f4ffff             -call 0x443c00
    cpu.esp -= 4;
    sub_443c00(app, cpu);
    if (cpu.terminate) return;
L_0x004447c9:
    // 004447c9  d945d4                 -fld dword ptr [ebp - 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */)));
    // 004447cc  d945d0                 -fld dword ptr [ebp - 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-48) /* -0x30 */)));
    // 004447cf  d945cc                 -fld dword ptr [ebp - 0x34]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-52) /* -0x34 */)));
    // 004447d2  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004447d4  d865cc                 -fsub dword ptr [ebp - 0x34]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-52) /* -0x34 */));
    // 004447d7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004447d9  d865c8                 -fsub dword ptr [ebp - 0x38]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-56) /* -0x38 */));
    // 004447dc  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004447de  d955fc                 -fst dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    // 004447e1  dd05108b5300           -fld qword ptr [0x538b10]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5475088) /* 0x538b10 */)));
    // 004447e7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004447e9  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004447eb  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004447ed  d955ec                 -fst dword ptr [ebp - 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = float(cpu.fpu.st(0));
    // 004447f0  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004447f2  d945c0                 -fld dword ptr [ebp - 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-64) /* -0x40 */)));
    // 004447f5  d945c4                 -fld dword ptr [ebp - 0x3c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-60) /* -0x3c */)));
    // 004447f8  d865bc                 -fsub dword ptr [ebp - 0x44]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-68) /* -0x44 */));
    // 004447fb  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004447fd  d865b8                 -fsub dword ptr [ebp - 0x48]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-72) /* -0x48 */));
    // 00444800  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00444802  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00444805  d95de0                 -fstp dword ptr [ebp - 0x20]
    app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00444808  d945c8                 -fld dword ptr [ebp - 0x38]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-56) /* -0x38 */)));
    // 0044480b  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0044480d  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0044480f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00444811  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00444813  d95df4                 -fstp dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00444816  d95de8                 -fstp dword ptr [ebp - 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00444819  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044481b  7437                   -je 0x444854
    if (cpu.flags.zf)
    {
        goto L_0x00444854;
    }
    // 0044481d  d945ec                 +fld dword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 00444820  d845e0                 +fadd dword ptr [ebp - 0x20]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */));
    // 00444823  d805188b5300           +fadd dword ptr [0x538b18]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475096) /* 0x538b18 */));
    // 00444829  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0044482c  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0044482e  d95de4                 +fstp dword ptr [ebp - 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00444831  d85dfc                 +fcomp dword ptr [ebp - 4]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    cpu.fpu.pop();
    // 00444834  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00444836  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00444837  7605                   -jbe 0x44483e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0044483e;
    }
    // 00444839  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0044483c  eb03                   -jmp 0x444841
    goto L_0x00444841;
L_0x0044483e:
    // 0044483e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x00444841:
    // 00444841  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00444844  d945f4                 +fld dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 00444847  e80ab50900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 0044484c  db1d408b5500           +fistp dword ptr [0x558b40]
    app->getMemory<x86::reg32>(x86::reg32(5606208) /* 0x558b40 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00444852  eb38                   -jmp 0x44488c
    goto L_0x0044488c;
L_0x00444854:
    // 00444854  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00444857  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00444859  dc05208b5300           +fadd qword ptr [0x538b20]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5475104) /* 0x538b20 */));
    // 0044485f  dc0d108b5300           +fmul qword ptr [0x538b10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5475088) /* 0x538b10 */));
    // 00444865  d86df4                 +fsubr dword ptr [ebp - 0xc]
    cpu.fpu.st(0) = app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) - cpu.fpu.st(0);
    // 00444868  e8e9b40900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 0044486d  db1d408b5500           +fistp dword ptr [0x558b40]
    app->getMemory<x86::reg32>(x86::reg32(5606208) /* 0x558b40 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00444873  d85dfc                 +fcomp dword ptr [ebp - 4]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    cpu.fpu.pop();
    // 00444876  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00444878  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00444879  7605                   -jbe 0x444880
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00444880;
    }
    // 0044487b  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0044487e  eb03                   -jmp 0x444883
    goto L_0x00444883;
L_0x00444880:
    // 00444880  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x00444883:
    // 00444883  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00444886  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00444889  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
L_0x0044488c:
    // 0044488c  d905288b5300           -fld dword ptr [0x538b28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5475112) /* 0x538b28 */)));
    // 00444892  d945e4                 -fld dword ptr [ebp - 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */)));
    // 00444895  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00444897  d945f0                 -fld dword ptr [ebp - 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 0044489a  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0044489c  d945e8                 -fld dword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 0044489f  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004448a1  d945f4                 -fld dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 004448a4  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004448a6  b950106600             -mov ecx, 0x661050
    cpu.ecx = 6688848 /*0x661050*/;
    // 004448ab  8b15348b5500           -mov edx, dword ptr [0x558b34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606196) /* 0x558b34 */);
    // 004448b1  a1308b5500             -mov eax, dword ptr [0x558b30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */);
    // 004448b6  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004448b8  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004448ba  d8e4                   -fsub st(4)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(4));
    // 004448bc  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004448be  d8e5                   -fsub st(5)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(5));
    // 004448c0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004448c2  dec5                   -faddp st(5)
    cpu.fpu.st(5) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004448c4  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004448c6  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004448c8  d91d50106600           -fstp dword ptr [0x661050]
    app->getMemory<float>(x86::reg32(6688848) /* 0x661050 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004448ce  d91d54106600           -fstp dword ptr [0x661054]
    app->getMemory<float>(x86::reg32(6688852) /* 0x661054 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004448d4  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004448d6  d91d5c106600           -fstp dword ptr [0x66105c]
    app->getMemory<float>(x86::reg32(6688860) /* 0x66105c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004448dc  d91d58106600           -fstp dword ptr [0x661058]
    app->getMemory<float>(x86::reg32(6688856) /* 0x661058 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004448e2  e839f4ffff             -call 0x443d20
    cpu.esp -= 4;
    sub_443d20(app, cpu);
    if (cpu.terminate) return;
    // 004448e7  a13c8b5500             -mov eax, dword ptr [0x558b3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */);
    // 004448ec  e87ffcffff             -call 0x444570
    cpu.esp -= 4;
    sub_444570(app, cpu);
    if (cpu.terminate) return;
    // 004448f1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004448f3  8b551c                 -mov edx, dword ptr [ebp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004448f6  a3188b5500             -mov dword ptr [0x558b18], eax
    app->getMemory<x86::reg32>(x86::reg32(5606168) /* 0x558b18 */) = cpu.eax;
    // 004448fb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004448fd  7406                   -je 0x444905
    if (cpu.flags.zf)
    {
        goto L_0x00444905;
    }
    // 004448ff  8915188b5500           -mov dword ptr [0x558b18], edx
    app->getMemory<x86::reg32>(x86::reg32(5606168) /* 0x558b18 */) = cpu.edx;
L_0x00444905:
    // 00444905  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00444907  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444908  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444909  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044490a  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_444910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00444910  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00444911  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00444912  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00444913  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00444915  8b0d3c8b5500           -mov ecx, dword ptr [0x558b3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */);
    // 0044491b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044491d  663d0048               +cmp ax, 0x4800
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18432 /*0x4800*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00444921  7220                   -jb 0x444943
    if (cpu.flags.cf)
    {
        goto L_0x00444943;
    }
    // 00444923  7632                   -jbe 0x444957
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00444957;
    }
    // 00444925  663d004d               +cmp ax, 0x4d00
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19712 /*0x4d00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00444929  720d                   -jb 0x444938
    if (cpu.flags.cf)
    {
        goto L_0x00444938;
    }
    // 0044492b  764b                   -jbe 0x444978
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00444978;
    }
    // 0044492d  663d0050               +cmp ax, 0x5000
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(20480 /*0x5000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00444931  7445                   -je 0x444978
    if (cpu.flags.zf)
    {
        goto L_0x00444978;
    }
    // 00444933  e982000000             -jmp 0x4449ba
    goto L_0x004449ba;
L_0x00444938:
    // 00444938  663d004b               +cmp ax, 0x4b00
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19200 /*0x4b00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044493c  7419                   -je 0x444957
    if (cpu.flags.zf)
    {
        goto L_0x00444957;
    }
    // 0044493e  e977000000             -jmp 0x4449ba
    goto L_0x004449ba;
L_0x00444943:
    // 00444943  663d0d00               +cmp ax, 0xd
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00444947  0f826d000000           -jb 0x4449ba
    if (cpu.flags.cf)
    {
        goto L_0x004449ba;
    }
    // 0044494d  7655                   -jbe 0x4449a4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004449a4;
    }
    // 0044494f  663d1b00               +cmp ax, 0x1b
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00444953  7460                   -je 0x4449b5
    if (cpu.flags.zf)
    {
        goto L_0x004449b5;
    }
    // 00444955  eb63                   -jmp 0x4449ba
    goto L_0x004449ba;
L_0x00444957:
    // 00444957  49                     -dec ecx
    (cpu.ecx)--;
    // 00444958  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044495a  7d07                   -jge 0x444963
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00444963;
    }
    // 0044495c  8b0d308b5500           -mov ecx, dword ptr [0x558b30]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */);
    // 00444962  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
L_0x00444963:
    // 00444963  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00444965  890d3c8b5500           -mov dword ptr [0x558b3c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.ecx;
    // 0044496b  e800fcffff             -call 0x444570
    cpu.esp -= 4;
    sub_444570(app, cpu);
    if (cpu.terminate) return;
    // 00444970  8b0d3c8b5500           -mov ecx, dword ptr [0x558b3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */);
    // 00444976  eb42                   -jmp 0x4449ba
    goto L_0x004449ba;
L_0x00444978:
    // 00444978  a1308b5500             -mov eax, dword ptr [0x558b30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */);
    // 0044497d  41                     -inc ecx
    (cpu.ecx)++;
    // 0044497e  48                     -dec eax
    (cpu.eax)--;
    // 0044497f  39c1                   +cmp ecx, eax
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
    // 00444981  7e02                   -jle 0x444985
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00444985;
    }
    // 00444983  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00444985:
    // 00444985  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00444987  890d3c8b5500           -mov dword ptr [0x558b3c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.ecx;
    // 0044498d  e8defbffff             -call 0x444570
    cpu.esp -= 4;
    sub_444570(app, cpu);
    if (cpu.terminate) return;
    // 00444992  8b0d3c8b5500           -mov ecx, dword ptr [0x558b3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */);
    // 00444998  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044499a  890d3c8b5500           -mov dword ptr [0x558b3c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.ecx;
    // 004449a0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004449a1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004449a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004449a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004449a4:
    // 004449a4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004449a9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004449ab  890d3c8b5500           -mov dword ptr [0x558b3c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.ecx;
    // 004449b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004449b2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004449b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004449b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004449b5:
    // 004449b5  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
L_0x004449ba:
    // 004449ba  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004449bc  890d3c8b5500           -mov dword ptr [0x558b3c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.ecx;
    // 004449c2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004449c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004449c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004449c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4449d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004449d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004449d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004449d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004449d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004449d4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004449d6  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004449db  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004449dd  8915608c5500           -mov dword ptr [0x558c60], edx
    app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */) = cpu.edx;
    // 004449e3  e8e8fbffff             -call 0x4445d0
    cpu.esp -= 4;
    sub_4445d0(app, cpu);
    if (cpu.terminate) return;
    // 004449e8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004449ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004449ec  7c24                   -jl 0x444a12
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00444a12;
    }
    // 004449ee  3b05308b5500           +cmp eax, dword ptr [0x558b30]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004449f4  7d1c                   -jge 0x444a12
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00444a12;
    }
    // 004449f6  3b053c8b5500           +cmp eax, dword ptr [0x558b3c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004449fc  740c                   -je 0x444a0a
    if (cpu.flags.zf)
    {
        goto L_0x00444a0a;
    }
    // 004449fe  ba2d000000             -mov edx, 0x2d
    cpu.edx = 45 /*0x2d*/;
    // 00444a03  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00444a05  e8c637fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
L_0x00444a0a:
    // 00444a0a  891d3c8b5500           -mov dword ptr [0x558b3c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.ebx;
    // 00444a10  eb0a                   -jmp 0x444a1c
    goto L_0x00444a1c;
L_0x00444a12:
    // 00444a12  c7053c8b5500ffffffff   -mov dword ptr [0x558b3c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = 4294967295 /*0xffffffff*/;
L_0x00444a1c:
    // 00444a1c  b850106600             -mov eax, 0x661050
    cpu.eax = 6688848 /*0x661050*/;
    // 00444a21  bb50106600             -mov ebx, 0x661050
    cpu.ebx = 6688848 /*0x661050*/;
    // 00444a26  e8a5eeffff             -call 0x4438d0
    cpu.esp -= 4;
    sub_4438d0(app, cpu);
    if (cpu.terminate) return;
    // 00444a2b  8b15208b5500           -mov edx, dword ptr [0x558b20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606176) /* 0x558b20 */);
    // 00444a31  a11c8b5500             -mov eax, dword ptr [0x558b1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606172) /* 0x558b1c */);
    // 00444a36  e805f5ffff             -call 0x443f40
    cpu.esp -= 4;
    sub_443f40(app, cpu);
    if (cpu.terminate) return;
    // 00444a3b  b850106600             -mov eax, 0x661050
    cpu.eax = 6688848 /*0x661050*/;
    // 00444a40  8b153c8b5500           -mov edx, dword ptr [0x558b3c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */);
    // 00444a46  e8b5f5ffff             -call 0x444000
    cpu.esp -= 4;
    sub_444000(app, cpu);
    if (cpu.terminate) return;
    // 00444a4b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00444a4d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444a4e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444a4f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444a50  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444a51  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_444a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00444a60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00444a61  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00444a62  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00444a63  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00444a65  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00444a6a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00444a6c  890d488b5500           -mov dword ptr [0x558b48], ecx
    app->getMemory<x86::reg32>(x86::reg32(5606216) /* 0x558b48 */) = cpu.ecx;
    // 00444a72  8915448b5500           -mov dword ptr [0x558b44], edx
    app->getMemory<x86::reg32>(x86::reg32(5606212) /* 0x558b44 */) = cpu.edx;
    // 00444a78  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444a79  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444a7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444a7b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_444a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00444a80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00444a81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00444a82  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00444a83  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00444a85  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00444a88  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00444a8a  893d0c8b5500           -mov dword ptr [0x558b0c], edi
    app->getMemory<x86::reg32>(x86::reg32(5606156) /* 0x558b0c */) = cpu.edi;
    // 00444a90  893d388b5500           -mov dword ptr [0x558b38], edi
    app->getMemory<x86::reg32>(x86::reg32(5606200) /* 0x558b38 */) = cpu.edi;
    // 00444a96  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00444a98  0f8479000000           -je 0x444b17
    if (cpu.flags.zf)
    {
        goto L_0x00444b17;
    }
    // 00444a9e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00444aa0  0f8471000000           -je 0x444b17
    if (cpu.flags.zf)
    {
        goto L_0x00444b17;
    }
    // 00444aa6  a31c8b5500             -mov dword ptr [0x558b1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5606172) /* 0x558b1c */) = cpu.eax;
    // 00444aab  c705148b550002000000   -mov dword ptr [0x558b14], 2
    app->getMemory<x86::reg32>(x86::reg32(5606164) /* 0x558b14 */) = 2 /*0x2*/;
    // 00444ab5  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 00444ab7  8915208b5500           -mov dword ptr [0x558b20], edx
    app->getMemory<x86::reg32>(x86::reg32(5606176) /* 0x558b20 */) = cpu.edx;
    // 00444abd  8825108b5500           -mov byte ptr [0x558b10], ah
    app->getMemory<x86::reg8>(x86::reg32(5606160) /* 0x558b10 */) = cpu.ah;
    // 00444ac3  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00444ac8  a3448b5500             -mov dword ptr [0x558b44], eax
    app->getMemory<x86::reg32>(x86::reg32(5606212) /* 0x558b44 */) = cpu.eax;
    // 00444acd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00444acf  7f02                   -jg 0x444ad3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00444ad3;
    }
    // 00444ad1  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
L_0x00444ad3:
    // 00444ad3  891d488b5500           -mov dword ptr [0x558b48], ebx
    app->getMemory<x86::reg32>(x86::reg32(5606216) /* 0x558b48 */) = cpu.ebx;
    // 00444ad9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00444adb  7f09                   -jg 0x444ae6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00444ae6;
    }
    // 00444add  c6054c8b550001         -mov byte ptr [0x558b4c], 1
    app->getMemory<x86::reg8>(x86::reg32(5606220) /* 0x558b4c */) = 1 /*0x1*/;
    // 00444ae4  eb06                   -jmp 0x444aec
    goto L_0x00444aec;
L_0x00444ae6:
    // 00444ae6  880d4c8b5500           -mov byte ptr [0x558b4c], cl
    app->getMemory<x86::reg8>(x86::reg32(5606220) /* 0x558b4c */) = cpu.cl;
L_0x00444aec:
    // 00444aec  6850106600             -push 0x661050
    app->getMemory<x86::reg32>(cpu.esp-4) = 6688848 /*0x661050*/;
    cpu.esp -= 4;
    // 00444af1  8b15208b5500           -mov edx, dword ptr [0x558b20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606176) /* 0x558b20 */);
    // 00444af7  a11c8b5500             -mov eax, dword ptr [0x558b1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606172) /* 0x558b1c */);
    // 00444afc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00444afe  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00444b00  e88befffff             -call 0x443a90
    cpu.esp -= 4;
    sub_443a90(app, cpu);
    if (cpu.terminate) return;
    // 00444b05  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00444b07  8915188b5500           -mov dword ptr [0x558b18], edx
    app->getMemory<x86::reg32>(x86::reg32(5606168) /* 0x558b18 */) = cpu.edx;
    // 00444b0d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00444b0f  7406                   -je 0x444b17
    if (cpu.flags.zf)
    {
        goto L_0x00444b17;
    }
    // 00444b11  8935188b5500           -mov dword ptr [0x558b18], esi
    app->getMemory<x86::reg32>(x86::reg32(5606168) /* 0x558b18 */) = cpu.esi;
L_0x00444b17:
    // 00444b17  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444b18  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444b19  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444b1a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_444b20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00444b20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00444b21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00444b22  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00444b23  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00444b25  8a1d4c8b5500           -mov bl, byte ptr [0x558b4c]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5606220) /* 0x558b4c */);
    // 00444b2b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00444b2d  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00444b2f  7429                   -je 0x444b5a
    if (cpu.flags.zf)
    {
        goto L_0x00444b5a;
    }
    // 00444b31  663d1b00               +cmp ax, 0x1b
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00444b35  720a                   -jb 0x444b41
    if (cpu.flags.cf)
    {
        goto L_0x00444b41;
    }
    // 00444b37  7615                   -jbe 0x444b4e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00444b4e;
    }
    // 00444b39  663d2000               +cmp ax, 0x20
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32 /*0x20*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00444b3d  7416                   -je 0x444b55
    if (cpu.flags.zf)
    {
        goto L_0x00444b55;
    }
    // 00444b3f  eb19                   -jmp 0x444b5a
    goto L_0x00444b5a;
L_0x00444b41:
    // 00444b41  663d0d00               +cmp ax, 0xd
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00444b45  7513                   -jne 0x444b5a
    if (!cpu.flags.zf)
    {
        goto L_0x00444b5a;
    }
    // 00444b47  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00444b4c  eb0c                   -jmp 0x444b5a
    goto L_0x00444b5a;
L_0x00444b4e:
    // 00444b4e  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00444b53  eb05                   -jmp 0x444b5a
    goto L_0x00444b5a;
L_0x00444b55:
    // 00444b55  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x00444b5a:
    // 00444b5a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00444b5c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444b5d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444b5e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444b5f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_444b60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00444b60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00444b61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00444b62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00444b63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00444b64  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00444b66  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00444b6b  b850106600             -mov eax, 0x661050
    cpu.eax = 6688848 /*0x661050*/;
    // 00444b70  bb50106600             -mov ebx, 0x661050
    cpu.ebx = 6688848 /*0x661050*/;
    // 00444b75  8915608c5500           -mov dword ptr [0x558c60], edx
    app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */) = cpu.edx;
    // 00444b7b  e850edffff             -call 0x4438d0
    cpu.esp -= 4;
    sub_4438d0(app, cpu);
    if (cpu.terminate) return;
    // 00444b80  8b15208b5500           -mov edx, dword ptr [0x558b20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606176) /* 0x558b20 */);
    // 00444b86  a11c8b5500             -mov eax, dword ptr [0x558b1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606172) /* 0x558b1c */);
    // 00444b8b  e8b0f3ffff             -call 0x443f40
    cpu.esp -= 4;
    sub_443f40(app, cpu);
    if (cpu.terminate) return;
    // 00444b90  8b1d488b5500           -mov ebx, dword ptr [0x558b48]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5606216) /* 0x558b48 */);
    // 00444b96  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00444b98  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00444b9a  7e36                   -jle 0x444bd2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00444bd2;
    }
    // 00444b9c  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00444ba1  2b05448b5500           -sub eax, dword ptr [0x558b44]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606212) /* 0x558b44 */)));
    // 00444ba7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00444ba9  7e0d                   -jle 0x444bb8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00444bb8;
    }
    // 00444bab  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00444bb0  2b05448b5500           +sub eax, dword ptr [0x558b44]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606212) /* 0x558b44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00444bb6  eb0d                   -jmp 0x444bc5
    goto L_0x00444bc5;
L_0x00444bb8:
    // 00444bb8  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00444bbd  2b05448b5500           -sub eax, dword ptr [0x558b44]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606212) /* 0x558b44 */)));
    // 00444bc3  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x00444bc5:
    // 00444bc5  3b05488b5500           +cmp eax, dword ptr [0x558b48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606216) /* 0x558b48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00444bcb  7c05                   -jl 0x444bd2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00444bd2;
    }
    // 00444bcd  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
L_0x00444bd2:
    // 00444bd2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00444bd4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444bd5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444bd6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444bd7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444bd8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_444be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00444be0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00444be1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00444be2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00444be3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00444be4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00444be6  e865cc0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00444beb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00444bed  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00444bf2  bb26020000             -mov ebx, 0x226
    cpu.ebx = 550 /*0x226*/;
    // 00444bf7  ba90106600             -mov edx, 0x661090
    cpu.edx = 6688912 /*0x661090*/;
    // 00444bfc  a390106600             -mov dword ptr [0x661090], eax
    app->getMemory<x86::reg32>(x86::reg32(6688912) /* 0x661090 */) = cpu.eax;
    // 00444c01  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00444c03  e878feffff             -call 0x444a80
    cpu.esp -= 4;
    sub_444a80(app, cpu);
    if (cpu.terminate) return;
    // 00444c08  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444c09  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444c0a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444c0b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444c0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_444c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00444c10  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00444c11  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00444c13  b8588b5500             -mov eax, 0x558b58
    cpu.eax = 5606232 /*0x558b58*/;
    // 00444c18  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444c19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_444c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00444c20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00444c21  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00444c22  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00444c23  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00444c25  83ec5c                 -sub esp, 0x5c
    (cpu.esp) -= x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 00444c28  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00444c2b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00444c2d  893d0c8b5500           -mov dword ptr [0x558b0c], edi
    app->getMemory<x86::reg32>(x86::reg32(5606156) /* 0x558b0c */) = cpu.edi;
    // 00444c33  893d388b5500           -mov dword ptr [0x558b38], edi
    app->getMemory<x86::reg32>(x86::reg32(5606200) /* 0x558b38 */) = cpu.edi;
    // 00444c39  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00444c3b  0f84ff020000           -je 0x444f40
    if (cpu.flags.zf)
    {
        goto L_0x00444f40;
    }
    // 00444c41  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00444c43  0f84f7020000           -je 0x444f40
    if (cpu.flags.zf)
    {
        goto L_0x00444f40;
    }
    // 00444c49  833d5c8c550004         +cmp dword ptr [0x558c5c], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5606492) /* 0x558c5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00444c50  0f8dea020000           -jge 0x444f40
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00444f40;
    }
    // 00444c56  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00444c58  0f84e2020000           -je 0x444f40
    if (cpu.flags.zf)
    {
        goto L_0x00444f40;
    }
    // 00444c5e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00444c60  0f84da020000           -je 0x444f40
    if (cpu.flags.zf)
    {
        goto L_0x00444f40;
    }
    // 00444c66  83fb0a                 +cmp ebx, 0xa
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00444c69  0f8dd1020000           -jge 0x444f40
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00444f40;
    }
    // 00444c6f  a31c8b5500             -mov dword ptr [0x558b1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5606172) /* 0x558b1c */) = cpu.eax;
    // 00444c74  8915208b5500           -mov dword ptr [0x558b20], edx
    app->getMemory<x86::reg32>(x86::reg32(5606176) /* 0x558b20 */) = cpu.edx;
    // 00444c7a  891d308b5500           -mov dword ptr [0x558b30], ebx
    app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */) = cpu.ebx;
    // 00444c80  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00444c85  890d348b5500           -mov dword ptr [0x558b34], ecx
    app->getMemory<x86::reg32>(x86::reg32(5606196) /* 0x558b34 */) = cpu.ecx;
    // 00444c8b  a3148b5500             -mov dword ptr [0x558b14], eax
    app->getMemory<x86::reg32>(x86::reg32(5606164) /* 0x558b14 */) = cpu.eax;
    // 00444c90  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 00444c92  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00444c97  8825108b5500           -mov byte ptr [0x558b10], ah
    app->getMemory<x86::reg8>(x86::reg32(5606160) /* 0x558b10 */) = cpu.ah;
    // 00444c9d  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00444ca0  89152c8b5500           -mov dword ptr [0x558b2c], edx
    app->getMemory<x86::reg32>(x86::reg32(5606188) /* 0x558b2c */) = cpu.edx;
    // 00444ca6  a33c8b5500             -mov dword ptr [0x558b3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.eax;
    // 00444cab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00444cad  7d04                   -jge 0x444cb3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00444cb3;
    }
    // 00444caf  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00444cb1  eb06                   -jmp 0x444cb9
    goto L_0x00444cb9;
L_0x00444cb3:
    // 00444cb3  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00444cb5  39c3                   +cmp ebx, eax
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
    // 00444cb7  7d06                   -jge 0x444cbf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00444cbf;
    }
L_0x00444cb9:
    // 00444cb9  891d3c8b5500           -mov dword ptr [0x558b3c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.ebx;
L_0x00444cbf:
    // 00444cbf  8d45b4                 -lea eax, [ebp - 0x4c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00444cc2  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00444cc7  8b15208b5500           -mov edx, dword ptr [0x558b20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606176) /* 0x558b20 */);
    // 00444ccd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00444cce  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00444cd0  a11c8b5500             -mov eax, dword ptr [0x558b1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606172) /* 0x558b1c */);
    // 00444cd5  e8b6edffff             -call 0x443a90
    cpu.esp -= 4;
    sub_443a90(app, cpu);
    if (cpu.terminate) return;
    // 00444cda  8d5da4                 -lea ebx, [ebp - 0x5c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-92) /* -0x5c */);
    // 00444cdd  8b15348b5500           -mov edx, dword ptr [0x558b34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606196) /* 0x558b34 */);
    // 00444ce3  a1308b5500             -mov eax, dword ptr [0x558b30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */);
    // 00444ce8  e813efffff             -call 0x443c00
    cpu.esp -= 4;
    sub_443c00(app, cpu);
    if (cpu.terminate) return;
    // 00444ced  d945c0                 +fld dword ptr [ebp - 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-64) /* -0x40 */)));
    // 00444cf0  d865b8                 +fsub dword ptr [ebp - 0x48]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-72) /* -0x48 */));
    // 00444cf3  d945b8                 +fld dword ptr [ebp - 0x48]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-72) /* -0x48 */)));
    // 00444cf6  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00444cf8  d955ec                 +fst dword ptr [ebp - 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = float(cpu.fpu.st(0));
    // 00444cfb  dd05308b5300           +fld qword ptr [0x538b30]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5475120) /* 0x538b30 */)));
    // 00444d01  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00444d03  d8c9                   +fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00444d05  d945b0                 +fld dword ptr [ebp - 0x50]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-80) /* -0x50 */)));
    // 00444d08  d945bc                 +fld dword ptr [ebp - 0x44]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-68) /* -0x44 */)));
    // 00444d0b  d865b4                 +fsub dword ptr [ebp - 0x4c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-76) /* -0x4c */));
    // 00444d0e  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00444d10  d865a8                 +fsub dword ptr [ebp - 0x58]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-88) /* -0x58 */));
    // 00444d13  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00444d15  d955e4                 +fst dword ptr [ebp - 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = float(cpu.fpu.st(0));
    // 00444d18  d8cb                   +fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 00444d1a  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00444d1c  d955f0                 +fst dword ptr [ebp - 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    // 00444d1f  dc05388b5300           +fadd qword ptr [0x538b38]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5475128) /* 0x538b38 */));
    // 00444d25  decb                   +fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00444d27  d945f0                 +fld dword ptr [ebp - 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 00444d2a  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00444d2c  dec4                   +faddp st(4)
    cpu.fpu.st(4) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00444d2e  d945b4                 +fld dword ptr [ebp - 0x4c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-76) /* -0x4c */)));
    // 00444d31  d9cc                   +fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00444d33  d95df4                 +fstp dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00444d36  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00444d38  d945f4                 +fld dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 00444d3b  dee2                   +fsubrp st(2)
    cpu.fpu.st(2) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(2));
    cpu.fpu.pop();
    // 00444d3d  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00444d3f  d95de0                 +fstp dword ptr [ebp - 0x20]
    app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00444d42  e80fb00900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00444d47  db1d408b5500           +fistp dword ptr [0x558b40]
    app->getMemory<x86::reg32>(x86::reg32(5606208) /* 0x558b40 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00444d4d  d85dec                 +fcomp dword ptr [ebp - 0x14]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */));
    cpu.fpu.pop();
    // 00444d50  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00444d52  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00444d53  7605                   -jbe 0x444d5a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00444d5a;
    }
    // 00444d55  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00444d58  eb03                   -jmp 0x444d5d
    goto L_0x00444d5d;
L_0x00444d5a:
    // 00444d5a  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
L_0x00444d5d:
    // 00444d5d  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00444d60  d905408b5300           -fld dword ptr [0x538b40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5475136) /* 0x538b40 */)));
    // 00444d66  d945e4                 -fld dword ptr [ebp - 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */)));
    // 00444d69  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00444d6b  d945e8                 -fld dword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 00444d6e  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00444d70  d945e0                 -fld dword ptr [ebp - 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
    // 00444d73  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00444d75  d945f4                 -fld dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 00444d78  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00444d7a  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00444d7f  b8588b5500             -mov eax, 0x558b58
    cpu.eax = 5606232 /*0x558b58*/;
    // 00444d84  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00444d86  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00444d88  d8e4                   -fsub st(4)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(4));
    // 00444d8a  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00444d8c  d8e5                   -fsub st(5)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(5));
    // 00444d8e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00444d90  dec5                   -faddp st(5)
    cpu.fpu.st(5) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00444d92  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00444d94  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00444d96  d91d50106600           -fstp dword ptr [0x661050]
    app->getMemory<float>(x86::reg32(6688848) /* 0x661050 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00444d9c  d91d54106600           -fstp dword ptr [0x661054]
    app->getMemory<float>(x86::reg32(6688852) /* 0x661054 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00444da2  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00444da4  d91d5c106600           -fstp dword ptr [0x66105c]
    app->getMemory<float>(x86::reg32(6688860) /* 0x66105c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00444daa  d91d58106600           -fstp dword ptr [0x661058]
    app->getMemory<float>(x86::reg32(6688856) /* 0x661058 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00444db0  e88bb80900             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00444db5  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00444db8  a3588c5500             -mov dword ptr [0x558c58], eax
    app->getMemory<x86::reg32>(x86::reg32(5606488) /* 0x558c58 */) = cpu.eax;
    // 00444dbd  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00444dc0  a35c8c5500             -mov dword ptr [0x558c5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5606492) /* 0x558c5c */) = cpu.eax;
    // 00444dc5  81fe00010000           +cmp esi, 0x100
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
    // 00444dcb  730c                   -jae 0x444dd9
    if (!cpu.flags.cf)
    {
        goto L_0x00444dd9;
    }
    // 00444dcd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00444dcf  7608                   -jbe 0x444dd9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00444dd9;
    }
    // 00444dd1  8935548b5500           -mov dword ptr [0x558b54], esi
    app->getMemory<x86::reg32>(x86::reg32(5606228) /* 0x558b54 */) = cpu.esi;
    // 00444dd7  eb0a                   -jmp 0x444de3
    goto L_0x00444de3;
L_0x00444dd9:
    // 00444dd9  c705548b5500ff000000   -mov dword ptr [0x558b54], 0xff
    app->getMemory<x86::reg32>(x86::reg32(5606228) /* 0x558b54 */) = 255 /*0xff*/;
L_0x00444de3:
    // 00444de3  8b155c8c5500           -mov edx, dword ptr [0x558c5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606492) /* 0x558c5c */);
    // 00444de9  a1588c5500             -mov eax, dword ptr [0x558c58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606488) /* 0x558c58 */);
    // 00444dee  e86deaffff             -call 0x443860
    cpu.esp -= 4;
    sub_443860(app, cpu);
    if (cpu.terminate) return;
    // 00444df3  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00444df5  742d                   -je 0x444e24
    if (cpu.flags.zf)
    {
        goto L_0x00444e24;
    }
    // 00444df7  b8588b5500             -mov eax, 0x558b58
    cpu.eax = 5606232 /*0x558b58*/;
    // 00444dfc  8b1d548b5500           -mov ebx, dword ptr [0x558b54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5606228) /* 0x558b54 */);
    // 00444e02  8b15588c5500           -mov edx, dword ptr [0x558c58]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606488) /* 0x558c58 */);
    // 00444e08  bf588b5500             -mov edi, 0x558b58
    cpu.edi = 5606232 /*0x558b58*/;
    // 00444e0d  e81ec00900             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 00444e12  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00444e14  49                     -dec ecx
    (cpu.ecx)--;
    // 00444e15  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00444e17  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 00444e19  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00444e1b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00444e1c  890d508b5500           -mov dword ptr [0x558b50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5606224) /* 0x558b50 */) = cpu.ecx;
    // 00444e22  eb08                   -jmp 0x444e2c
    goto L_0x00444e2c;
L_0x00444e24:
    // 00444e24  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00444e26  8915508b5500           -mov dword ptr [0x558b50], edx
    app->getMemory<x86::reg32>(x86::reg32(5606224) /* 0x558b50 */) = cpu.edx;
L_0x00444e2c:
    // 00444e2c  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00444e31  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00444e36  e8c5d20000             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 00444e3b  b82c8b5300             -mov eax, 0x538b2c
    cpu.eax = 5475116 /*0x538b2c*/;
    // 00444e40  e8dbd10000             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00444e45  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00444e48  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00444e4b  db05548b5500           +fild dword ptr [0x558b54]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606228) /* 0x558b54 */))));
    // 00444e51  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00444e53  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00444e58  b8048b5300             -mov eax, 0x538b04
    cpu.eax = 5475076 /*0x538b04*/;
    // 00444e5d  d95dd8                 +fstp dword ptr [ebp - 0x28]
    app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00444e60  e8bbd10000             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00444e65  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00444e68  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00444e6b  d845d8                 +fadd dword ptr [ebp - 0x28]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */));
    // 00444e6e  d805448b5300           +fadd dword ptr [0x538b44]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475140) /* 0x538b44 */));
    // 00444e74  d955f8                 +fst dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    // 00444e77  d81d488b5300           +fcomp dword ptr [0x538b48]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(x86::reg32(5475144) /* 0x538b48 */));
    cpu.fpu.pop();
    // 00444e7d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00444e7f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00444e80  7607                   -jbe 0x444e89
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00444e89;
    }
    // 00444e82  c745f800007043         -mov dword ptr [ebp - 8], 0x43700000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 1131413504 /*0x43700000*/;
L_0x00444e89:
    // 00444e89  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00444e8c  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00444e8e  e8c3ae0900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00444e93  d9c1                   +fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 00444e95  dc05508b5300           +fadd qword ptr [0x538b50]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5475152) /* 0x538b50 */));
    // 00444e9b  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00444e9d  db1d70106600           +fistp dword ptr [0x661070]
    app->getMemory<x86::reg32>(x86::reg32(6688880) /* 0x661070 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00444ea3  ddd9                   +fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00444ea5  d955f8                 +fst dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    // 00444ea8  d85de8                 +fcomp dword ptr [ebp - 0x18]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */));
    cpu.fpu.pop();
    // 00444eab  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00444ead  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00444eae  765a                   -jbe 0x444f0a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00444f0a;
    }
    // 00444eb0  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00444eb3  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
    // 00444eb8  d81d588b5300           +fcomp dword ptr [0x538b58]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(x86::reg32(5475160) /* 0x538b58 */));
    cpu.fpu.pop();
    // 00444ebe  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00444ec0  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00444ec1  7207                   -jb 0x444eca
    if (cpu.flags.cf)
    {
        goto L_0x00444eca;
    }
    // 00444ec3  c745f800c01f44         -mov dword ptr [ebp - 8], 0x441fc000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 1142931456 /*0x441fc000*/;
L_0x00444eca:
    // 00444eca  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00444ecd  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00444ed0  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00444ed3  d95ddc                 +fstp dword ptr [ebp - 0x24]
    app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00444ed6  d85ddc                 +fcomp dword ptr [ebp - 0x24]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */));
    cpu.fpu.pop();
    // 00444ed9  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00444edb  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00444edc  720c                   -jb 0x444eea
    if (cpu.flags.cf)
    {
        goto L_0x00444eea;
    }
    // 00444ede  d945dc                 -fld dword ptr [ebp - 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */)));
    // 00444ee1  d8055c8b5300           -fadd dword ptr [0x538b5c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475164) /* 0x538b5c */));
    // 00444ee7  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00444eea:
    // 00444eea  d945f8                 -fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00444eed  dc0d308b5300           -fmul qword ptr [0x538b30]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5475120) /* 0x538b30 */));
    // 00444ef3  d945f4                 -fld dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 00444ef6  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00444ef8  d8e2                   -fsub st(2)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(2));
    // 00444efa  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00444efc  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00444efe  d91d54106600           -fstp dword ptr [0x661054]
    app->getMemory<float>(x86::reg32(6688852) /* 0x661054 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00444f04  d91d5c106600           -fstp dword ptr [0x66105c]
    app->getMemory<float>(x86::reg32(6688860) /* 0x66105c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00444f0a:
    // 00444f0a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00444f0c  8b7d20                 -mov edi, dword ptr [ebp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00444f0f  8935188b5500           -mov dword ptr [0x558b18], esi
    app->getMemory<x86::reg32>(x86::reg32(5606168) /* 0x558b18 */) = cpu.esi;
    // 00444f15  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00444f17  7406                   -je 0x444f1f
    if (cpu.flags.zf)
    {
        goto L_0x00444f1f;
    }
    // 00444f19  893d188b5500           -mov dword ptr [0x558b18], edi
    app->getMemory<x86::reg32>(x86::reg32(5606168) /* 0x558b18 */) = cpu.edi;
L_0x00444f1f:
    // 00444f1f  b950106600             -mov ecx, 0x661050
    cpu.ecx = 6688848 /*0x661050*/;
    // 00444f24  8b15348b5500           -mov edx, dword ptr [0x558b34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606196) /* 0x558b34 */);
    // 00444f2a  a1308b5500             -mov eax, dword ptr [0x558b30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */);
    // 00444f2f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00444f31  e8eaedffff             -call 0x443d20
    cpu.esp -= 4;
    sub_443d20(app, cpu);
    if (cpu.terminate) return;
    // 00444f36  a13c8b5500             -mov eax, dword ptr [0x558b3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */);
    // 00444f3b  e830f6ffff             -call 0x444570
    cpu.esp -= 4;
    sub_444570(app, cpu);
    if (cpu.terminate) return;
L_0x00444f40:
    // 00444f40  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00444f42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444f43  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444f44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00444f45  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_444f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00444f50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00444f51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00444f52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00444f53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00444f54  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00444f55  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00444f56  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00444f58  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00444f5a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00444f5c  663d1b00               +cmp ax, 0x1b
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00444f60  722d                   -jb 0x444f8f
    if (cpu.flags.cf)
    {
        goto L_0x00444f8f;
    }
    // 00444f62  7642                   -jbe 0x444fa6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00444fa6;
    }
    // 00444f64  a1308b5500             -mov eax, dword ptr [0x558b30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */);
    // 00444f69  48                     -dec eax
    (cpu.eax)--;
    // 00444f6a  6681f9004d             +cmp cx, 0x4d00
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19712 /*0x4d00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00444f6f  7212                   -jb 0x444f83
    if (cpu.flags.cf)
    {
        goto L_0x00444f83;
    }
    // 00444f71  766c                   -jbe 0x444fdf
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00444fdf;
    }
    // 00444f73  6681f90053             +cmp cx, 0x5300
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21248 /*0x5300*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00444f78  0f84af000000           -je 0x44502d
    if (cpu.flags.zf)
    {
        goto L_0x0044502d;
    }
    // 00444f7e  e9cc000000             -jmp 0x44504f
    goto L_0x0044504f;
L_0x00444f83:
    // 00444f83  6681f9004b             +cmp cx, 0x4b00
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19200 /*0x4b00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00444f88  7430                   -je 0x444fba
    if (cpu.flags.zf)
    {
        goto L_0x00444fba;
    }
    // 00444f8a  e9c0000000             -jmp 0x44504f
    goto L_0x0044504f;
L_0x00444f8f:
    // 00444f8f  663d0800               +cmp ax, 8
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00444f93  0f82b6000000           -jb 0x44504f
    if (cpu.flags.cf)
    {
        goto L_0x0044504f;
    }
    // 00444f99  766a                   -jbe 0x445005
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00445005;
    }
    // 00444f9b  663d0d00               +cmp ax, 0xd
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00444f9f  740f                   -je 0x444fb0
    if (cpu.flags.zf)
    {
        goto L_0x00444fb0;
    }
    // 00444fa1  e9a9000000             -jmp 0x44504f
    goto L_0x0044504f;
L_0x00444fa6:
    // 00444fa6  be03000000             -mov esi, 3
    cpu.esi = 3 /*0x3*/;
    // 00444fab  e904010000             -jmp 0x4450b4
    goto L_0x004450b4;
L_0x00444fb0:
    // 00444fb0  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00444fb5  e9fa000000             -jmp 0x4450b4
    goto L_0x004450b4;
L_0x00444fba:
    // 00444fba  8b153c8b5500           -mov edx, dword ptr [0x558b3c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */);
    // 00444fc0  4a                     -dec edx
    (cpu.edx)--;
    // 00444fc1  89153c8b5500           -mov dword ptr [0x558b3c], edx
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.edx;
    // 00444fc7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00444fc9  7d05                   -jge 0x444fd0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00444fd0;
    }
    // 00444fcb  a33c8b5500             -mov dword ptr [0x558b3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.eax;
L_0x00444fd0:
    // 00444fd0  a13c8b5500             -mov eax, dword ptr [0x558b3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */);
    // 00444fd5  e896f5ffff             -call 0x444570
    cpu.esp -= 4;
    sub_444570(app, cpu);
    if (cpu.terminate) return;
    // 00444fda  e9d5000000             -jmp 0x4450b4
    goto L_0x004450b4;
L_0x00444fdf:
    // 00444fdf  8b1d3c8b5500           -mov ebx, dword ptr [0x558b3c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */);
    // 00444fe5  43                     -inc ebx
    (cpu.ebx)++;
    // 00444fe6  891d3c8b5500           -mov dword ptr [0x558b3c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.ebx;
    // 00444fec  39d8                   +cmp eax, ebx
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
    // 00444fee  7d06                   -jge 0x444ff6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00444ff6;
    }
    // 00444ff0  89353c8b5500           -mov dword ptr [0x558b3c], esi
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.esi;
L_0x00444ff6:
    // 00444ff6  a13c8b5500             -mov eax, dword ptr [0x558b3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */);
    // 00444ffb  e870f5ffff             -call 0x444570
    cpu.esp -= 4;
    sub_444570(app, cpu);
    if (cpu.terminate) return;
    // 00445000  e9af000000             -jmp 0x4450b4
    goto L_0x004450b4;
L_0x00445005:
    // 00445005  8b15508b5500           -mov edx, dword ptr [0x558b50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606224) /* 0x558b50 */);
    // 0044500b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044500d  0f8ea1000000           -jle 0x4450b4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004450b4;
    }
    // 00445013  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00445016  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00445018  890d508b5500           -mov dword ptr [0x558b50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5606224) /* 0x558b50 */) = cpu.ecx;
    // 0044501e  8891588b5500           -mov byte ptr [ecx + 0x558b58], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5606232) /* 0x558b58 */) = cpu.dl;
    // 00445024  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00445026  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445027  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445028  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445029  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044502a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044502b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044502c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044502d:
    // 0044502d  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00445032  b8588b5500             -mov eax, 0x558b58
    cpu.eax = 5606232 /*0x558b58*/;
    // 00445037  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00445039  e802b60900             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0044503e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00445040  891d508b5500           -mov dword ptr [0x558b50], ebx
    app->getMemory<x86::reg32>(x86::reg32(5606224) /* 0x558b50 */) = cpu.ebx;
    // 00445046  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00445048  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445049  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044504a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044504b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044504c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044504d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044504e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044504f:
    // 0044504f  8b3d548b5500           -mov edi, dword ptr [0x558b54]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5606228) /* 0x558b54 */);
    // 00445055  3b3d508b5500           +cmp edi, dword ptr [0x558b50]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606224) /* 0x558b50 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044505b  7f09                   -jg 0x445066
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00445066;
    }
    // 0044505d  833d2c8b550000         +cmp dword ptr [0x558b2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5606188) /* 0x558b2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445064  744e                   -je 0x4450b4
    if (cpu.flags.zf)
    {
        goto L_0x004450b4;
    }
L_0x00445066:
    // 00445066  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00445068  8b155c8c5500           -mov edx, dword ptr [0x558c5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606492) /* 0x558c5c */);
    // 0044506e  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 00445070  e89be7ffff             -call 0x443810
    cpu.esp -= 4;
    sub_443810(app, cpu);
    if (cpu.terminate) return;
    // 00445075  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00445077  743b                   -je 0x4450b4
    if (cpu.flags.zf)
    {
        goto L_0x004450b4;
    }
    // 00445079  833d2c8b550000         +cmp dword ptr [0x558b2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5606188) /* 0x558b2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445080  7421                   -je 0x4450a3
    if (cpu.flags.zf)
    {
        goto L_0x004450a3;
    }
    // 00445082  b8588b5500             -mov eax, 0x558b58
    cpu.eax = 5606232 /*0x558b58*/;
    // 00445087  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00445089  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044508b  891d2c8b5500           -mov dword ptr [0x558b2c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5606188) /* 0x558b2c */) = cpu.ebx;
    // 00445091  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00445096  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00445098  e8a3b50900             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0044509d  893d508b5500           -mov dword ptr [0x558b50], edi
    app->getMemory<x86::reg32>(x86::reg32(5606224) /* 0x558b50 */) = cpu.edi;
L_0x004450a3:
    // 004450a3  a1508b5500             -mov eax, dword ptr [0x558b50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606224) /* 0x558b50 */);
    // 004450a8  40                     -inc eax
    (cpu.eax)++;
    // 004450a9  8888578b5500           -mov byte ptr [eax + 0x558b57], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5606231) /* 0x558b57 */) = cpu.cl;
    // 004450af  a3508b5500             -mov dword ptr [0x558b50], eax
    app->getMemory<x86::reg32>(x86::reg32(5606224) /* 0x558b50 */) = cpu.eax;
L_0x004450b4:
    // 004450b4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004450b6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004450b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004450b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004450b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004450ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004450bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004450bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4450c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004450c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004450c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004450c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004450c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004450c4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004450c6  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004450cb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004450cd  8915608c5500           -mov dword ptr [0x558c60], edx
    app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */) = cpu.edx;
    // 004450d3  e8f8f4ffff             -call 0x4445d0
    cpu.esp -= 4;
    sub_4445d0(app, cpu);
    if (cpu.terminate) return;
    // 004450d8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004450da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004450dc  7c24                   -jl 0x445102
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00445102;
    }
    // 004450de  3b05308b5500           +cmp eax, dword ptr [0x558b30]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004450e4  7d1c                   -jge 0x445102
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00445102;
    }
    // 004450e6  3b053c8b5500           +cmp eax, dword ptr [0x558b3c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004450ec  740c                   -je 0x4450fa
    if (cpu.flags.zf)
    {
        goto L_0x004450fa;
    }
    // 004450ee  ba2d000000             -mov edx, 0x2d
    cpu.edx = 45 /*0x2d*/;
    // 004450f3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004450f5  e8d630fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
L_0x004450fa:
    // 004450fa  891d3c8b5500           -mov dword ptr [0x558b3c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.ebx;
    // 00445100  eb0a                   -jmp 0x44510c
    goto L_0x0044510c;
L_0x00445102:
    // 00445102  c7053c8b5500ffffffff   -mov dword ptr [0x558b3c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = 4294967295 /*0xffffffff*/;
L_0x0044510c:
    // 0044510c  b850106600             -mov eax, 0x661050
    cpu.eax = 6688848 /*0x661050*/;
    // 00445111  bb50106600             -mov ebx, 0x661050
    cpu.ebx = 6688848 /*0x661050*/;
    // 00445116  e8b5e7ffff             -call 0x4438d0
    cpu.esp -= 4;
    sub_4438d0(app, cpu);
    if (cpu.terminate) return;
    // 0044511b  8b15208b5500           -mov edx, dword ptr [0x558b20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606176) /* 0x558b20 */);
    // 00445121  a11c8b5500             -mov eax, dword ptr [0x558b1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606172) /* 0x558b1c */);
    // 00445126  e815eeffff             -call 0x443f40
    cpu.esp -= 4;
    sub_443f40(app, cpu);
    if (cpu.terminate) return;
    // 0044512b  b850106600             -mov eax, 0x661050
    cpu.eax = 6688848 /*0x661050*/;
    // 00445130  e81bf2ffff             -call 0x444350
    cpu.esp -= 4;
    sub_444350(app, cpu);
    if (cpu.terminate) return;
    // 00445135  b850106600             -mov eax, 0x661050
    cpu.eax = 6688848 /*0x661050*/;
    // 0044513a  8b153c8b5500           -mov edx, dword ptr [0x558b3c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */);
    // 00445140  e8bbeeffff             -call 0x444000
    cpu.esp -= 4;
    sub_444000(app, cpu);
    if (cpu.terminate) return;
    // 00445145  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00445147  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445148  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445149  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044514a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044514b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_445150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00445150  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00445151  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00445153  a1608c5500             -mov eax, dword ptr [0x558c60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */);
    // 00445158  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445159  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_445160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00445160  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00445161  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00445162  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00445163  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00445165  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00445167  7c55                   -jl 0x4451be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004451be;
    }
    // 00445169  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044516b  8a15648c5500           -mov dl, byte ptr [0x558c64]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5606500) /* 0x558c64 */);
    // 00445171  39d0                   +cmp eax, edx
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
    // 00445173  7d49                   -jge 0x4451be
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004451be;
    }
    // 00445175  8b0cc5d00f6600         -mov ecx, dword ptr [eax*8 + 0x660fd0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6688720) /* 0x660fd0 */ + cpu.eax * 8);
    // 0044517c  8b14c5d20f6600         -mov edx, dword ptr [eax*8 + 0x660fd2]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688722) /* 0x660fd2 */ + cpu.eax * 8);
    // 00445183  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00445186  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00445189  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0044518b  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044518e  8915e4e55500           -mov dword ptr [0x55e5e4], edx
    app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */) = cpu.edx;
    // 00445194  8b14c5d40f6600         -mov edx, dword ptr [eax*8 + 0x660fd4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688724) /* 0x660fd4 */ + cpu.eax * 8);
    // 0044519b  8b04c5ce0f6600         -mov eax, dword ptr [eax*8 + 0x660fce]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6688718) /* 0x660fce */ + cpu.eax * 8);
    // 004451a2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004451a5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004451a8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004451aa  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004451ad  a3e8e55500             -mov dword ptr [0x55e5e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */) = cpu.eax;
    // 004451b2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004451b4  a1e4e55500             -mov eax, dword ptr [0x55e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 004451b9  e8026e0500             -call 0x49bfc0
    cpu.esp -= 4;
    sub_49bfc0(app, cpu);
    if (cpu.terminate) return;
L_0x004451be:
    // 004451be  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004451bf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004451c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004451c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
