#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_4aad16(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aad16  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aad18  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aad1a  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aad20  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aad23  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aad28  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aad2a  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aad2d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aad33  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aad36  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aad39  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aad3f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aad41  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aad44  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aad4a  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aad4d  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aad50  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aad56  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aad58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aad59(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aad59  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aad5b  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aad60  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aad63  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aad69  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aad6c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aad6e  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aad71  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aad77  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aad7a  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aad80  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aad82  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aad84  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aad87  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aad8d  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aad90  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aad93  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aad99  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aad9b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aad9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aad9c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aad9e  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aada1  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aada7  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aadaa  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aadaf  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aadb1  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aadb4  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aadba  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aadbd  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aadbf  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aadc5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aadc7  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004aadcb  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aadd1  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aadd4  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aadd7  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aaddd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaddf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aade0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aade0  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aade3  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aade8  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aadeb  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aadf1  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aadf4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aadf6  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aadf8  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aadfe  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aae01  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aae07  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aae09  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aae0b  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004aae0f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aae15  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aae18  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aae1b  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aae21  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aae23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aae24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aae24  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aae27  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aae2c  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aae2f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aae35  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aae38  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aae3a  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aae3c  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004aae42  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004aae45  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aae4b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aae4d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aae4f  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004aae53  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aae59  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aae5c  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aae5f  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aae65  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aae67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aae68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aae68  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aae6a  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aae6c  81e3fcfcfcfc           -and ebx, 0xfcfcfcfc
    cpu.ebx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004aae72  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aae75  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aae7a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aae7c  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aae7f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aae85  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aae88  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aae8b  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aae91  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aae93  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aae94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aae94  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aae96  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aae98  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aae9e  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aaea1  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aaea6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaea8  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aaeab  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaeb1  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aaeb4  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aaeb7  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aaebd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaebf  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aaec2  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaec8  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aaecb  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aaece  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aaed4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaed6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aaed7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aaed7  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aaed9  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aaede  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aaee1  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaee7  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aaeea  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aaeed  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aaef3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaef5  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aaef8  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaefe  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aaf01  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aaf04  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aaf0a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaf0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aaf0d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aaf0d  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aaf0f  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aaf14  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aaf17  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaf1d  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aaf20  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aaf23  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aaf29  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaf2b  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aaf2e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaf34  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aaf37  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aaf3a  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aaf40  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaf42  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004aaf46  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaf4c  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aaf4f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aaf52  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aaf58  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaf5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aaf5b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aaf5b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aaf5d  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aaf60  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aaf66  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aaf69  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aaf6e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaf70  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aaf73  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaf79  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aaf7c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aaf7e  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aaf81  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aaf87  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aaf8a  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aaf90  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aaf92  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaf94  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aaf97  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaf9d  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aafa0  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aafa3  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aafa9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aafab  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004aafaf  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aafb5  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aafb8  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aafbb  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aafc1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aafc3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aafc4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aafc4  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aafc7  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aafcc  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aafcf  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aafd5  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aafd8  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aafda  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aafe0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aafe2  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aafe5  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aafeb  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aafee  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aaff1  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aaff7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaff9  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004aaffd  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab003  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab006  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab009  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab00f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab011  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab012(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab012  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ab015  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab01a  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab01d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab023  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab026  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab028  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab02e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab030  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab034  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab03a  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab03d  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab040  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab046  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab048  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab049(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab049  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ab04c  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab051  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab054  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab05a  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab05d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab05f  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab061  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab067  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab06a  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab070  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab072  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab074  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab078  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab07e  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab081  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab084  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab08a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab08c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab08d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab08d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab08f  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ab091  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab097  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab09a  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab09f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab0a1  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab0a4  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab0aa  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab0ad  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab0af  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab0b2  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab0b8  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab0bb  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab0c1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab0c3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab0c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab0c6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab0c6  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ab0c8  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab0cd  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab0d0  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab0d6  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab0d9  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab0dc  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab0e2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab0e4  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab0e7  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab0ed  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab0f0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab0f2  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab0f5  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab0fb  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab0fe  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab104  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab106  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab108  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab109(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab109  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ab10b  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab110  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab113  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab119  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab11c  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab11f  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab125  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab127  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab12a  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab130  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab133  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab136  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab13c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab13e  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab142  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab148  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab14b  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab14e  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab154  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab156  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab157(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab157  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab159  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ab15c  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab162  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab165  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab16a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab16c  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab16f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab175  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab178  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab17b  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab181  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab183  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab186  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab18c  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab18f  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab192  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab198  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab19a  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab19e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab1a4  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab1a7  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab1aa  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab1b0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab1b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab1b3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab1b3  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ab1b6  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab1bb  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab1be  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab1c4  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab1c7  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab1ca  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab1d0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab1d2  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab1d5  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab1db  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab1de  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab1e1  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab1e7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab1e9  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab1ed  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab1f3  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab1f6  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab1f9  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab1ff  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab201  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab202(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab202  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ab205  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab20a  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab20d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab213  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab216  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab218  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab21b  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab221  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab224  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab22a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab22c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab22e  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab231  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab237  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab23a  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab23d  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab243  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab245  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab249  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab24f  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab252  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab255  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab25b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab25d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab25e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab25e  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ab261  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab266  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab269  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab26f  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab272  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab274  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab27a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab27c  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab27f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab285  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab288  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab28b  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab291  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab293  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab297  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab29d  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab2a0  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab2a3  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab2a9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab2ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab2ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab2ac  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ab2af  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab2b4  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab2b7  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab2bd  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab2c0  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab2c2  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab2c8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab2ca  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab2ce  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab2d4  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab2d7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab2d9  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab2dc  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab2e2  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab2e5  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab2eb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab2ed  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab2ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab2f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab2f0  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ab2f2  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab2f7  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab2fa  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab300  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab303  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab305  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab30b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab30d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab30e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab30e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab310  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ab313  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab319  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab31c  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab321  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab323  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab326  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab32c  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab32f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab332  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab338  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab33a  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab33d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab343  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab346  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab348  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab34b  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab351  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab354  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab35a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab35c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab35e  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab362  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab368  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab36b  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab36e  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab374  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab376  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab377(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab377  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ab37a  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab37f  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab382  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab388  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab38b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab38d  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab390  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab396  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab399  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab39f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab3a1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab3a3  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab3a6  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab3ac  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab3af  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab3b2  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab3b8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab3ba  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab3be  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab3c4  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab3c7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab3c9  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab3cc  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab3d2  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab3d5  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab3db  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab3dd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab3df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab3e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab3e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ab3e2  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab3e5  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab3eb  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab3ee  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab3f0  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab3f6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab3f8  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab3fc  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab402  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab405  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab407  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab40d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab40f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab410  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab412  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ab415  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab41b  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab41e  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab423  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab425  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab428  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab42e  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab431  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab433  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab435  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab43b  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab43e  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab444  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab446  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab448  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab449(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab449  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab44b  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ab44e  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab454  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab457  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab45c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab45e  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab461  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab467  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab46a  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab46c  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab472  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab474  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab478  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab47e  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab481  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab484  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab48a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab48c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab48d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab48d  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ab490  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab495  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab498  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab49e  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab4a1  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab4a4  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab4aa  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab4ac  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab4af  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab4b5  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab4b8  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab4ba  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab4c0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab4c2  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab4c6  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab4cc  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab4cf  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab4d2  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab4d8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab4da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab4db(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab4db  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ab4de  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab4e3  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab4e6  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab4ec  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab4ef  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab4f2  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab4f8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab4fa  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab4fd  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab503  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab506  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab508  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab50b  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab511  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab514  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab51a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab51c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab51e  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab522  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab528  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab52b  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab52e  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab534  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab536  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab537(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab537  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ab53a  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab53f  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab542  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab548  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab54b  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab54e  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab554  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab556  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab559  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab55f  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab562  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab565  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab56b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab56d  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab571  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab577  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab57a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab57c  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab57f  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab585  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab588  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab58e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab590  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab592  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab593(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab593  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ab596  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab59b  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab59e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab5a4  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab5a7  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab5aa  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab5b0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab5b2  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab5b5  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab5bb  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab5be  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab5c1  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab5c7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab5c9  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab5cd  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab5d3  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab5d6  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab5d8  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab5de  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab5e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab5e1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab5e1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ab5e3  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab5e6  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab5ec  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab5ef  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab5f1  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab5f4  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab5fa  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab5fd  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab603  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab605  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab607  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab60a  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab610  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab613  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab616  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab61c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab61e  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab622  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab628  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab62b  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab62d  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab633  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab635  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab636(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab636  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ab639  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab63e  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab641  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab647  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab64a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab64c  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab64e  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004ab654  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004ab657  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab65d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab65f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab661  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab662(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab662  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ab665  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab66a  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab66d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab673  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab676  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab678  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab67a  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab680  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab683  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab689  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab68b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab68d  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab691  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab697  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab69a  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab69d  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab6a3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab6a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab6a6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab6a6  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ab6a9  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab6ae  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab6b1  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab6b7  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab6ba  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab6bc  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab6c2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab6c4  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab6c8  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab6ce  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab6d1  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab6d4  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab6da  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab6dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab6dd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab6dd  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ab6e0  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab6e5  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab6e8  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab6ee  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab6f1  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab6f4  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab6fa  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab6fc  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab6ff  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab705  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab708  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab70a  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab710  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab712  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab716  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab71c  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab71f  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab722  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab728  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab72a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab72b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab72b  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ab72e  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab733  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab736  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab73c  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab73f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab742  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab748  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab74a  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab74d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab753  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab756  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab758  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab75b  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab761  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab764  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab76a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab76c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab76e  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab772  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab778  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab77b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab77d  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab780  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab786  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab789  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab78f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab791  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab793  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab794(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab794  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ab797  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab79c  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab79f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab7a5  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab7a8  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab7ab  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab7b1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab7b3  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab7b6  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab7bc  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab7bf  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab7c2  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab7c8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab7ca  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab7ce  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab7d4  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab7d7  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab7d9  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab7df  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab7e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab7e2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab7e2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ab7e4  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab7e7  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab7ed  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab7f0  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab7f3  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab7f9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab7fb  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab7fe  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab804  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab807  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab80a  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab810  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab812  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab816  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab81c  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab81f  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab821  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab827  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab829  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab82a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab82a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ab82c  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab82f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab835  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab838  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab83b  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab841  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab843  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab846  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab84c  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab84f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab852  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab858  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab85a  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab85e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab864  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab867  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab869  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab86b  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab871  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab874  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab87a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab87c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab87e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab87f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab87f  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ab882  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab887  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab88a  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab890  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab893  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab895  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab898  81e21f1f1f1f           -and edx, 0x1f1f1f1f
    cpu.edx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab89e  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ab8a0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab8a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab8a3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab8a3  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ab8a6  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab8ab  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab8ae  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab8b4  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab8b7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab8b9  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab8bb  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004ab8c1  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004ab8c4  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab8ca  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab8cc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab8ce  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab8d2  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab8d8  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab8db  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab8de  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab8e4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab8e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab8e7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab8e7  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ab8ea  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab8ef  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab8f2  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab8f8  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab8fb  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab8fd  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab8ff  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab905  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab908  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab90e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab910  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab912  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab916  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab91c  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab91f  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab922  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab928  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab92a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab92b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab92b  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ab92e  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab933  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab936  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab93c  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab93f  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab941  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab947  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab949  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab94d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab953  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab956  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab958  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab95b  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab961  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab964  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab96a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab96c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab96e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab96f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab96f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ab971  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab974  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab97a  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab97d  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab97f  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab985  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab987  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab98b  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab991  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab994  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab996  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab99c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab99e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab99f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab99f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ab9a1  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab9a4  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab9aa  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab9ad  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ab9b0  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ab9b6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab9b8  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ab9bb  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab9c1  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab9c4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab9c6  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ab9c9  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ab9cf  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ab9d2  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ab9d8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab9da  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab9dc  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ab9e0  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab9e6  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ab9e9  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ab9eb  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ab9f1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab9f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab9f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab9f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ab9f6  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ab9f9  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab9ff  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aba02  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aba05  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aba0b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aba0d  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aba10  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aba16  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aba19  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aba1c  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aba22  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aba24  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004aba28  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aba2e  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aba31  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aba33  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aba35  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aba3b  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aba3e  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aba44  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aba46  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aba48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aba49(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aba49  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aba4b  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aba4e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aba54  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aba57  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aba5a  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aba60  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aba62  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aba65  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aba6b  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aba6e  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aba71  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aba77  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aba79  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004aba7d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aba83  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aba86  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aba88  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aba8a  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004aba90  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004aba93  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aba99  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aba9b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aba9d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4abaa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abaa0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abaa1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004abaa3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004abaa5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004abaa7  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004abaa9  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004abaab  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004abaae  c1e810                 +shr eax, 0x10
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
    // 004abab1  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004abab3  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004abab5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abab6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4abac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abac0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abac1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004abac3  e86ca8fcff             -call 0x476334
    cpu.esp -= 4;
    sub_476334(app, cpu);
    if (cpu.terminate) return;
    // 004abac8  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004abacb  e890bcfcff             -call 0x477760
    cpu.esp -= 4;
    sub_477760(app, cpu);
    if (cpu.terminate) return;
    // 004abad0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abad1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4abad4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abad4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abad5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004abad7  e858a8fcff             -call 0x476334
    cpu.esp -= 4;
    sub_476334(app, cpu);
    if (cpu.terminate) return;
    // 004abadc  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004abadf  e85cbdfcff             -call 0x477840
    cpu.esp -= 4;
    sub_477840(app, cpu);
    if (cpu.terminate) return;
    // 004abae4  e873a8fcff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 004abae9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abaea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4abaec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abaec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004abaed  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004abaee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004abaef  81ec40010000           -sub esp, 0x140
    (cpu.esp) -= x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004abaf5  8bbc2454010000         -mov edi, dword ptr [esp + 0x154]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(340) /* 0x154 */);
    // 004abafc  8984242c010000         -mov dword ptr [esp + 0x12c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */) = cpu.eax;
    // 004abb03  8994243c010000         -mov dword ptr [esp + 0x13c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */) = cpu.edx;
    // 004abb0a  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004abb0c  898c2438010000         -mov dword ptr [esp + 0x138], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */) = cpu.ecx;
    // 004abb13  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004abb18  e8b360feff             -call 0x491bd0
    cpu.esp -= 4;
    sub_491bd0(app, cpu);
    if (cpu.terminate) return;
    // 004abb1d  89842430010000         -mov dword ptr [esp + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */) = cpu.eax;
    // 004abb24  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004abb26  8b942450010000         -mov edx, dword ptr [esp + 0x150]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(336) /* 0x150 */);
    // 004abb2d  e89e60feff             -call 0x491bd0
    cpu.esp -= 4;
    sub_491bd0(app, cpu);
    if (cpu.terminate) return;
    // 004abb32  8b842438010000         -mov eax, dword ptr [esp + 0x138]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    // 004abb39  8b0d50824c00           -mov ecx, dword ptr [0x4c8250]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014096) /* 0x4c8250 */);
    // 004abb3f  8b1dec814c00           -mov ebx, dword ptr [0x4c81ec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5013996) /* 0x4c81ec */);
    // 004abb45  e80650feff             -call 0x490b50
    cpu.esp -= 4;
    sub_490b50(app, cpu);
    if (cpu.terminate) return;
    // 004abb4a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004abb4c  89842434010000         -mov dword ptr [esp + 0x134], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */) = cpu.eax;
    // 004abb53  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004abb5a  e8417afeff             -call 0x4935a0
    cpu.esp -= 4;
    sub_4935a0(app, cpu);
    if (cpu.terminate) return;
    // 004abb5f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004abb61  e8aaf3fcff             -call 0x47af10
    cpu.esp -= 4;
    sub_47af10(app, cpu);
    if (cpu.terminate) return;
    // 004abb66  b8fcca4c00             -mov eax, 0x4ccafc
    cpu.eax = 5032700 /*0x4ccafc*/;
    // 004abb6b  e850f2fcff             -call 0x47adc0
    cpu.esp -= 4;
    sub_47adc0(app, cpu);
    if (cpu.terminate) return;
    // 004abb70  8b842450010000         -mov eax, dword ptr [esp + 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(336) /* 0x150 */);
    // 004abb77  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004abb79  8b8c2438010000         -mov ecx, dword ptr [esp + 0x138]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    // 004abb80  89842424010000         -mov dword ptr [esp + 0x124], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */) = cpu.eax;
    // 004abb87  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004abb88  8b842440010000         -mov eax, dword ptr [esp + 0x140]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 004abb8f  8b942440010000         -mov edx, dword ptr [esp + 0x140]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 004abb96  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004abb98  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004abb9a  8984242c010000         -mov dword ptr [esp + 0x12c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */) = cpu.eax;
    // 004abba1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004abba3  b808854c00             -mov eax, 0x4c8508
    cpu.eax = 5014792 /*0x4c8508*/;
    // 004abba8  e8b3510000             -call 0x4b0d60
    cpu.esp -= 4;
    sub_4b0d60(app, cpu);
    if (cpu.terminate) return;
    // 004abbad  ff15a8824c00           -call dword ptr [0x4c82a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5014184) /* 0x4c82a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abbb3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004abbb5  8b94243c010000         -mov edx, dword ptr [esp + 0x13c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 004abbbc  e887a8fcff             -call 0x476448
    cpu.esp -= 4;
    sub_476448(app, cpu);
    if (cpu.terminate) return;
    // 004abbc1  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004abbc3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004abbc5  8b8c2450010000         -mov ecx, dword ptr [esp + 0x150]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(336) /* 0x150 */);
    // 004abbcc  e8effeffff             -call 0x4abac0
    cpu.esp -= 4;
    sub_4abac0(app, cpu);
    if (cpu.terminate) return;
    // 004abbd1  e85ea7fcff             -call 0x476334
    cpu.esp -= 4;
    sub_476334(app, cpu);
    if (cpu.terminate) return;
    // 004abbd6  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 004abbdb  8b9c2438010000         -mov ebx, dword ptr [esp + 0x138]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    // 004abbe2  e875a9fcff             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 004abbe7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004abbe8  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004abbea  8b842440010000         -mov eax, dword ptr [esp + 0x140]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 004abbf1  e82a16fdff             -call 0x47d220
    cpu.esp -= 4;
    sub_47d220(app, cpu);
    if (cpu.terminate) return;
    // 004abbf6  b80000aaff             -mov eax, 0xffaa0000
    cpu.eax = 4289331200 /*0xffaa0000*/;
    // 004abbfb  8b8c2424010000         -mov ecx, dword ptr [esp + 0x124]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 004abc02  8b9c2428010000         -mov ebx, dword ptr [esp + 0x128]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 004abc09  e84ea9fcff             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 004abc0e  8d5504                 -lea edx, [ebp + 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004abc11  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004abc12  83e904                 -sub ecx, 4
    (cpu.ecx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004abc15  8b842440010000         -mov eax, dword ptr [esp + 0x140]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 004abc1c  83eb05                 -sub ebx, 5
    (cpu.ebx) -= x86::reg32(x86::sreg32(5 /*0x5*/));
    // 004abc1f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004abc22  e899510000             -call 0x4b0dc0
    cpu.esp -= 4;
    sub_4b0dc0(app, cpu);
    if (cpu.terminate) return;
    // 004abc27  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004abc2c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004abc2e  e829a9fcff             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 004abc33  e848e8fcff             -call 0x47a480
    cpu.esp -= 4;
    sub_47a480(app, cpu);
    if (cpu.terminate) return;
    // 004abc38  8b84242c010000         -mov eax, dword ptr [esp + 0x12c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004abc3f  8d5509                 -lea edx, [ebp + 9]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(9) /* 0x9 */);
    // 004abc42  e875520000             -call 0x4b0ebc
    cpu.esp -= 4;
    sub_4b0ebc(app, cpu);
    if (cpu.terminate) return;
    // 004abc47  ff15ac824c00           -call dword ptr [0x4c82ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5014188) /* 0x4c82ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abc4d  b808854c00             -mov eax, 0x4c8508
    cpu.eax = 5014792 /*0x4c8508*/;
    // 004abc52  e8b9520000             -call 0x4b0f10
    cpu.esp -= 4;
    sub_4b0f10(app, cpu);
    if (cpu.terminate) return;
    // 004abc57  e800a7fcff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
L_0x004abc5c:
    // 004abc5c  ff15b0824c00           -call dword ptr [0x4c82b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5014192) /* 0x4c82b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abc62  85f8                   +test eax, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edi));
    // 004abc64  75f6                   -jne 0x4abc5c
    if (!cpu.flags.zf)
    {
        goto L_0x004abc5c;
    }
L_0x004abc66:
    // 004abc66  e82d02fdff             -call 0x47be98
    cpu.esp -= 4;
    sub_47be98(app, cpu);
    if (cpu.terminate) return;
    // 004abc6b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004abc6d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004abc6f  ff15b0824c00           -call dword ptr [0x4c82b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5014192) /* 0x4c82b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abc75  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004abc77  21fe                   -and esi, edi
    cpu.esi &= x86::reg32(x86::sreg32(cpu.edi));
    // 004abc79  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004abc7b  0f8497000000           -je 0x4abd18
    if (cpu.flags.zf)
    {
        goto L_0x004abd18;
    }
L_0x004abc81:
    // 004abc81  80c920                 -or cl, 0x20
    cpu.cl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004abc84  83e601                 -and esi, 1
    cpu.esi &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004abc87  83f979                 +cmp ecx, 0x79
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(121 /*0x79*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abc8a  7505                   -jne 0x4abc91
    if (!cpu.flags.zf)
    {
        goto L_0x004abc91;
    }
    // 004abc8c  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004abc91:
    // 004abc91  8b842450010000         -mov eax, dword ptr [esp + 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(336) /* 0x150 */);
    // 004abc98  8b8c243c010000         -mov ecx, dword ptr [esp + 0x13c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 004abc9f  8b9c2438010000         -mov ebx, dword ptr [esp + 0x138]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    // 004abca6  8b94243c010000         -mov edx, dword ptr [esp + 0x13c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 004abcad  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004abcaf  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004abcb1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004abcb2  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004abcb4  b808854c00             -mov eax, 0x4c8508
    cpu.eax = 5014792 /*0x4c8508*/;
    // 004abcb9  e8a2500000             -call 0x4b0d60
    cpu.esp -= 4;
    sub_4b0d60(app, cpu);
    if (cpu.terminate) return;
    // 004abcbe  ff15a4824c00           -call dword ptr [0x4c82a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5014180) /* 0x4c82a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abcc4  8b94243c010000         -mov edx, dword ptr [esp + 0x13c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 004abccb  8b842434010000         -mov eax, dword ptr [esp + 0x134]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */);
    // 004abcd2  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004abcd4  e8fbfdffff             -call 0x4abad4
    cpu.esp -= 4;
    sub_4abad4(app, cpu);
    if (cpu.terminate) return;
    // 004abcd9  ff15ac824c00           -call dword ptr [0x4c82ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5014188) /* 0x4c82ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abcdf  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004abce1  e842f2fcff             -call 0x47af28
    cpu.esp -= 4;
    sub_47af28(app, cpu);
    if (cpu.terminate) return;
    // 004abce6  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004abced  e8d278feff             -call 0x4935c4
    cpu.esp -= 4;
    sub_4935c4(app, cpu);
    if (cpu.terminate) return;
    // 004abcf2  8b842434010000         -mov eax, dword ptr [esp + 0x134]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */);
    // 004abcf9  e892affcff             -call 0x476c90
    cpu.esp -= 4;
    sub_476c90(app, cpu);
    if (cpu.terminate) return;
    // 004abcfe  8b842430010000         -mov eax, dword ptr [esp + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 004abd05  e8c65efeff             -call 0x491bd0
    cpu.esp -= 4;
    sub_491bd0(app, cpu);
    if (cpu.terminate) return;
    // 004abd0a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004abd0c  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004abd12  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd13  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd15  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004abd18:
    // 004abd18  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004abd1a  0f8561ffffff           -jne 0x4abc81
    if (!cpu.flags.zf)
    {
        goto L_0x004abc81;
    }
    // 004abd20  e941ffffff             -jmp 0x4abc66
    goto L_0x004abc66;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4abd28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abd28  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abd29  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abd2a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abd2b  833dc4814c0000         +cmp dword ptr [0x4c81c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013956) /* 0x4c81c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abd32  7410                   -je 0x4abd44
    if (cpu.flags.zf)
    {
        goto L_0x004abd44;
    }
    // 004abd34  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004abd36  e86d2ffdff             -call 0x47eca8
    cpu.esp -= 4;
    sub_47eca8(app, cpu);
    if (cpu.terminate) return;
    // 004abd3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abd3d  7442                   -je 0x4abd81
    if (cpu.flags.zf)
    {
        goto L_0x004abd81;
    }
    // 004abd3f  e818a6fcff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
L_0x004abd44:
    // 004abd44  a1e8814c00             -mov eax, dword ptr [0x4c81e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013992) /* 0x4c81e8 */);
    // 004abd49  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004abd4b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004abd4e  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004abd50  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004abd52  8d58f8                 -lea ebx, [eax - 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 004abd55  a1e4814c00             -mov eax, dword ptr [0x4c81e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013988) /* 0x4c81e4 */);
    // 004abd5a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004abd5c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004abd5f  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004abd61  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004abd63  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 004abd65  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 004abd67  8d50b0                 -lea edx, [eax - 0x50]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-80) /* -0x50 */);
    // 004abd6a  b9a0000000             -mov ecx, 0xa0
    cpu.ecx = 160 /*0xa0*/;
    // 004abd6f  b82cfb4b00             -mov eax, 0x4bfb2c
    cpu.eax = 4979500 /*0x4bfb2c*/;
    // 004abd74  e873fdffff             -call 0x4abaec
    cpu.esp -= 4;
    sub_4abaec(app, cpu);
    if (cpu.terminate) return;
    // 004abd79  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abd7b  751a                   -jne 0x4abd97
    if (!cpu.flags.zf)
    {
        goto L_0x004abd97;
    }
    // 004abd7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd7f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd80  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004abd81:
    // 004abd81  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 004abd86  e87d32fdff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 004abd8b  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 004abd90  e88b32fdff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004abd95  ebad                   -jmp 0x4abd44
    goto L_0x004abd44;
L_0x004abd97:
    // 004abd97  e885f8fdff             -call 0x48b621
    cpu.esp -= 4;
    sub_48b621(app, cpu);
    if (cpu.terminate) return;
    // 004abd9c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd9e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abda0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abda0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abda1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abda2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004abda3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004abda4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004abda5  81ec28010000           -sub esp, 0x128
    (cpu.esp) -= x86::reg32(x86::sreg32(296 /*0x128*/));
    // 004abdab  89842424010000         -mov dword ptr [esp + 0x124], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */) = cpu.eax;
    // 004abdb2  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004abdb4  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004abdb9  e8125efeff             -call 0x491bd0
    cpu.esp -= 4;
    sub_491bd0(app, cpu);
    if (cpu.terminate) return;
    // 004abdbe  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004abdc0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004abdc2  ba0a000000             -mov edx, 0xa
    cpu.edx = 10 /*0xa*/;
    // 004abdc7  e8045efeff             -call 0x491bd0
    cpu.esp -= 4;
    sub_491bd0(app, cpu);
    if (cpu.terminate) return;
    // 004abdcc  8b0d50824c00           -mov ecx, dword ptr [0x4c8250]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014096) /* 0x4c8250 */);
    // 004abdd2  8b1dec814c00           -mov ebx, dword ptr [0x4c81ec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5013996) /* 0x4c81ec */);
    // 004abdd8  a1e4814c00             -mov eax, dword ptr [0x4c81e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013988) /* 0x4c81e4 */);
    // 004abddd  e86e4dfeff             -call 0x490b50
    cpu.esp -= 4;
    sub_490b50(app, cpu);
    if (cpu.terminate) return;
    // 004abde2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004abde4  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004abdeb  e8b077feff             -call 0x4935a0
    cpu.esp -= 4;
    sub_4935a0(app, cpu);
    if (cpu.terminate) return;
    // 004abdf0  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004abdf2  e819f1fcff             -call 0x47af10
    cpu.esp -= 4;
    sub_47af10(app, cpu);
    if (cpu.terminate) return;
    // 004abdf7  b8fcca4c00             -mov eax, 0x4ccafc
    cpu.eax = 5032700 /*0x4ccafc*/;
    // 004abdfc  e8bfeffcff             -call 0x47adc0
    cpu.esp -= 4;
    sub_47adc0(app, cpu);
    if (cpu.terminate) return;
    // 004abe01  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004abe03  e840a6fcff             -call 0x476448
    cpu.esp -= 4;
    sub_476448(app, cpu);
    if (cpu.terminate) return;
    // 004abe08  8b15e8814c00           -mov edx, dword ptr [0x4c81e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5013992) /* 0x4c81e8 */);
    // 004abe0e  b808854c00             -mov eax, 0x4c8508
    cpu.eax = 5014792 /*0x4c8508*/;
    // 004abe13  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abe14  8d5af6                 -lea ebx, [edx - 0xa]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-10) /* -0xa */);
    // 004abe17  8b0de4814c00           -mov ecx, dword ptr [0x4c81e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5013988) /* 0x4c81e4 */);
    // 004abe1d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004abe1f  e83c4f0000             -call 0x4b0d60
    cpu.esp -= 4;
    sub_4b0d60(app, cpu);
    if (cpu.terminate) return;
    // 004abe24  ff15a8824c00           -call dword ptr [0x4c82a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5014184) /* 0x4c82a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abe2a  8b1de8814c00           -mov ebx, dword ptr [0x4c81e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5013992) /* 0x4c81e8 */);
    // 004abe30  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004abe32  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004abe34  83eb0a                 -sub ebx, 0xa
    (cpu.ebx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004abe37  e884fcffff             -call 0x4abac0
    cpu.esp -= 4;
    sub_4abac0(app, cpu);
    if (cpu.terminate) return;
    // 004abe3c  e8f3a4fcff             -call 0x476334
    cpu.esp -= 4;
    sub_476334(app, cpu);
    if (cpu.terminate) return;
    // 004abe41  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 004abe46  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 004abe4b  e80ca7fcff             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 004abe50  8b1de4814c00           -mov ebx, dword ptr [0x4c81e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5013988) /* 0x4c81e4 */);
    // 004abe56  8b15e8814c00           -mov edx, dword ptr [0x4c81e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5013992) /* 0x4c81e8 */);
    // 004abe5c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004abe5d  83ea0a                 -sub edx, 0xa
    (cpu.edx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004abe60  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004abe62  e8b913fdff             -call 0x47d220
    cpu.esp -= 4;
    sub_47d220(app, cpu);
    if (cpu.terminate) return;
    // 004abe67  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004abe6c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004abe6e  e8e9a6fcff             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 004abe73  e808e6fcff             -call 0x47a480
    cpu.esp -= 4;
    sub_47a480(app, cpu);
    if (cpu.terminate) return;
    // 004abe78  8b15e8814c00           -mov edx, dword ptr [0x4c81e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5013992) /* 0x4c81e8 */);
    // 004abe7e  8b842424010000         -mov eax, dword ptr [esp + 0x124]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 004abe85  83ea09                 -sub edx, 9
    (cpu.edx) -= x86::reg32(x86::sreg32(9 /*0x9*/));
    // 004abe88  e82f500000             -call 0x4b0ebc
    cpu.esp -= 4;
    sub_4b0ebc(app, cpu);
    if (cpu.terminate) return;
    // 004abe8d  ff15ac824c00           -call dword ptr [0x4c82ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5014188) /* 0x4c82ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abe93  e8c4a4fcff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 004abe98  e8bfa4fcff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 004abe9d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004abe9f  e85cb4fcff             -call 0x477300
    cpu.esp -= 4;
    sub_477300(app, cpu);
    if (cpu.terminate) return;
    // 004abea4  e88ba4fcff             -call 0x476334
    cpu.esp -= 4;
    sub_476334(app, cpu);
    if (cpu.terminate) return;
    // 004abea9  ff15a4824c00           -call dword ptr [0x4c82a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5014180) /* 0x4c82a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abeaf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004abeb1  8b1de8814c00           -mov ebx, dword ptr [0x4c81e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5013992) /* 0x4c81e8 */);
    // 004abeb7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004abeb9  83eb0a                 -sub ebx, 0xa
    (cpu.ebx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004abebc  e813fcffff             -call 0x4abad4
    cpu.esp -= 4;
    sub_4abad4(app, cpu);
    if (cpu.terminate) return;
    // 004abec1  ff15ac824c00           -call dword ptr [0x4c82ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5014188) /* 0x4c82ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abec7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004abec9  e85af0fcff             -call 0x47af28
    cpu.esp -= 4;
    sub_47af28(app, cpu);
    if (cpu.terminate) return;
    // 004abece  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004abed5  e8ea76feff             -call 0x4935c4
    cpu.esp -= 4;
    sub_4935c4(app, cpu);
    if (cpu.terminate) return;
    // 004abeda  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004abedc  e8afadfcff             -call 0x476c90
    cpu.esp -= 4;
    sub_476c90(app, cpu);
    if (cpu.terminate) return;
    // 004abee1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004abee3  e8e85cfeff             -call 0x491bd0
    cpu.esp -= 4;
    sub_491bd0(app, cpu);
    if (cpu.terminate) return;
    // 004abee8  81c428010000           -add esp, 0x128
    (cpu.esp) += x86::reg32(x86::sreg32(296 /*0x128*/));
    // 004abeee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abeef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abef0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abef1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abef2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abef3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abef4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abef4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abef5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abef6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abef7  a1e8814c00             -mov eax, dword ptr [0x4c81e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013992) /* 0x4c81e8 */);
    // 004abefc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004abefe  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004abf01  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004abf03  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004abf05  8d58f8                 -lea ebx, [eax - 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 004abf08  a1e4814c00             -mov eax, dword ptr [0x4c81e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013988) /* 0x4c81e4 */);
    // 004abf0d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004abf0f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004abf12  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004abf14  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004abf16  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004abf18  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 004abf1a  8d9070ffffff           -lea edx, [eax - 0x90]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-144) /* -0x90 */);
    // 004abf20  b920010000             -mov ecx, 0x120
    cpu.ecx = 288 /*0x120*/;
    // 004abf25  b838fb4b00             -mov eax, 0x4bfb38
    cpu.eax = 4979512 /*0x4bfb38*/;
    // 004abf2a  e8bdfbffff             -call 0x4abaec
    cpu.esp -= 4;
    sub_4abaec(app, cpu);
    if (cpu.terminate) return;
    // 004abf2f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abf30  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abf31  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abf32  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abf33(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abf33  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abf34  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abf35  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abf37  742a                   -je 0x4abf63
    if (cpu.flags.zf)
    {
        goto L_0x004abf63;
    }
    // 004abf39  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004abf3b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004abf3d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004abf3f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004abf40  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004abf42  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004abf46  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004abf47  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 004abf4c  8b15acd94c00           -mov edx, dword ptr [0x4cd9ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5036460) /* 0x4cd9ac */);
    // 004abf52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abf53  2eff15a8554b00         -call dword ptr cs:[0x4b55a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937128) /* 0x4b55a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abf5a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abf5c  7505                   -jne 0x4abf63
    if (!cpu.flags.zf)
    {
        goto L_0x004abf63;
    }
    // 004abf5e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004abf63:
    // 004abf63  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004abf66  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abf67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abf68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abf68  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abf69  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004abf6a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004abf6b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004abf6c  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004abf6f  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004abf71  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004abf73  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004abf75  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004abf77  8d4c2401               -lea ecx, [esp + 1]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 004abf7b  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
L_0x004abf7e:
    // 004abf7e  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004abf82  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 004abf86  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004abf88  f733                   -div dword ptr [ebx]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebx);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004abf8a  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004abf8c  8a8294d84c00           -mov al, byte ptr [edx + 0x4cd894]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5036180) /* 0x4cd894 */);
    // 004abf92  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 004abf94  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004abf98  41                     -inc ecx
    (cpu.ecx)++;
    // 004abf99  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abf9b  75e1                   -jne 0x4abf7e
    if (!cpu.flags.zf)
    {
        goto L_0x004abf7e;
    }
L_0x004abf9d:
    // 004abf9d  49                     -dec ecx
    (cpu.ecx)--;
    // 004abf9e  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004abfa0  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004abfa2  46                     -inc esi
    (cpu.esi)++;
    // 004abfa3  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004abfa5  75f6                   -jne 0x4abf9d
    if (!cpu.flags.zf)
    {
        goto L_0x004abf9d;
    }
    // 004abfa7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004abfa9  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004abfac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abfad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abfae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abfaf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abfb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abfb1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abfb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abfb2  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004abfb4  83fb0a                 +cmp ebx, 0xa
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
    // 004abfb7  750a                   -jne 0x4abfc3
    if (!cpu.flags.zf)
    {
        goto L_0x004abfc3;
    }
    // 004abfb9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abfbb  7d06                   -jge 0x4abfc3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004abfc3;
    }
    // 004abfbd  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004abfbf  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 004abfc2  42                     -inc edx
    (cpu.edx)++;
L_0x004abfc3:
    // 004abfc3  e8a0ffffff             -call 0x4abf68
    cpu.esp -= 4;
    sub_4abf68(app, cpu);
    if (cpu.terminate) return;
    // 004abfc8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004abfca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abfcb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abfcc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abfcc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abfcd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004abfce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004abfcf  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004abfd0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004abfd1  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004abfd4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004abfd6  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 004abfda  8d7c2434               -lea edi, [esp + 0x34]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004abfde  8d6c2401               -lea ebp, [esp + 1]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 004abfe2  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004abfe4  89542440               -mov dword ptr [esp + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 004abfe8  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004abfea  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004abfec  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004abfee  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004abfef  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004abff0  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004abff4  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004abff8  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x004abffb:
    // 004abffb  8d7c242c               -lea edi, [esp + 0x2c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004abfff  8d742434               -lea esi, [esp + 0x34]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004ac003  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ac007  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004ac00b  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ac00e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ac010  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004ac013  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ac015  e8634f0000             -call 0x4b0f7d
    cpu.esp -= 4;
    sub_4b0f7d(app, cpu);
    if (cpu.terminate) return;
    // 004ac01a  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ac01d  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004ac01f  894f04                 -mov dword ptr [edi + 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004ac022  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 004ac024  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004ac028  8a83bcd84c00           -mov al, byte ptr [ebx + 0x4cd8bc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5036220) /* 0x4cd8bc */);
    // 004ac02e  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 004ac031  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004ac035  45                     -inc ebp
    (cpu.ebp)++;
    // 004ac036  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ac038  75c1                   -jne 0x4abffb
    if (!cpu.flags.zf)
    {
        goto L_0x004abffb;
    }
    // 004ac03a  837c243800             +cmp dword ptr [esp + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ac03f  75ba                   -jne 0x4abffb
    if (!cpu.flags.zf)
    {
        goto L_0x004abffb;
    }
L_0x004ac041:
    // 004ac041  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004ac045  4d                     -dec ebp
    (cpu.ebp)--;
    // 004ac046  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004ac049  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 004ac04c  89742440               -mov dword ptr [esp + 0x40], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 004ac050  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004ac052  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004ac054  75eb                   -jne 0x4ac041
    if (!cpu.flags.zf)
    {
        goto L_0x004ac041;
    }
    // 004ac056  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004ac05a  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004ac05d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac05e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ac05f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac060  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac061  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac062  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac063(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac063  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac064  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac065  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ac066  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004ac067  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ac06a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ac06c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004ac06e  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004ac070  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004ac072  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004ac074  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004ac075  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004ac076  83fb0a                 +cmp ebx, 0xa
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
    // 004ac079  752d                   -jne 0x4ac0a8
    if (!cpu.flags.zf)
    {
        goto L_0x004ac0a8;
    }
    // 004ac07b  f644240780             +test byte ptr [esp + 7], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) & 128 /*0x80*/));
    // 004ac080  7426                   -je 0x4ac0a8
    if (cpu.flags.zf)
    {
        goto L_0x004ac0a8;
    }
    // 004ac082  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 004ac085  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004ac088  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ac08c  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 004ac08e  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
    // 004ac090  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004ac093  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004ac097  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004ac09a  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004ac09d  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ac09e  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004ac0a1  7501                   -jne 0x4ac0a4
    if (!cpu.flags.zf)
    {
        goto L_0x004ac0a4;
    }
    // 004ac0a3  46                     -inc esi
    (cpu.esi)++;
L_0x004ac0a4:
    // 004ac0a4  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
L_0x004ac0a8:
    // 004ac0a8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ac0aa  e81dffffff             -call 0x4abfcc
    cpu.esp -= 4;
    sub_4abfcc(app, cpu);
    if (cpu.terminate) return;
    // 004ac0af  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ac0b1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ac0b4  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ac0b5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac0b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac0b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac0b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac0b9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac0b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac0ba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac0bb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ac0bc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac0bd  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004ac0c0  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004ac0c2  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004ac0c4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ac0c6  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004ac0c8  8d4c2401               -lea ecx, [esp + 1]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 004ac0cc  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
L_0x004ac0cf:
    // 004ac0cf  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ac0d3  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 004ac0d7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac0d9  f733                   -div dword ptr [ebx]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebx);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004ac0db  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004ac0dd  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ac0e1  8a92e4d84c00           -mov dl, byte ptr [edx + 0x4cd8e4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5036260) /* 0x4cd8e4 */);
    // 004ac0e7  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 004ac0e9  41                     -inc ecx
    (cpu.ecx)++;
    // 004ac0ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac0ec  75e1                   -jne 0x4ac0cf
    if (!cpu.flags.zf)
    {
        goto L_0x004ac0cf;
    }
L_0x004ac0ee:
    // 004ac0ee  49                     -dec ecx
    (cpu.ecx)--;
    // 004ac0ef  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004ac0f1  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004ac0f3  46                     -inc esi
    (cpu.esi)++;
    // 004ac0f4  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004ac0f6  75f6                   -jne 0x4ac0ee
    if (!cpu.flags.zf)
    {
        goto L_0x004ac0ee;
    }
    // 004ac0f8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004ac0fa  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004ac0fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac0fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac0ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac100  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac101  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac102(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac102  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac103  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004ac105  83fb0a                 +cmp ebx, 0xa
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
    // 004ac108  750a                   -jne 0x4ac114
    if (!cpu.flags.zf)
    {
        goto L_0x004ac114;
    }
    // 004ac10a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac10c  7d06                   -jge 0x4ac114
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ac114;
    }
    // 004ac10e  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004ac110  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 004ac113  42                     -inc edx
    (cpu.edx)++;
L_0x004ac114:
    // 004ac114  e8a0ffffff             -call 0x4ac0b9
    cpu.esp -= 4;
    sub_4ac0b9(app, cpu);
    if (cpu.terminate) return;
    // 004ac119  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ac11b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac11c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac11d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac11d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ac11e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac11f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ac120  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac121  ff1560c14c00           -call dword ptr [0x4cc160]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030240) /* 0x4cc160 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ac127  a130ac4c00             -mov eax, dword ptr [0x4cac30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024816) /* 0x4cac30 */);
    // 004ac12c  e9a2000000             -jmp 0x4ac1d3
    return sub_4ac1d3(app, cpu);
}

/* align: skip  */
void Application::sub_4ac131(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac131  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ac132  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac133  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ac134  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac135  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ac136  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ac138  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 004ac13d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ac13f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ac140  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ac143  2eff1598554b00         -call dword ptr cs:[0x4b5598]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937112) /* 0x4b5598 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ac14a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac14c  7507                   -jne 0x4ac155
    if (!cpu.flags.zf)
    {
        goto L_0x004ac155;
    }
    // 004ac14e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004ac153  eb36                   -jmp 0x4ac18b
    goto L_0x004ac18b;
L_0x004ac155:
    // 004ac155  3b1d34ac4c00           +cmp ebx, dword ptr [0x4cac34]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5024820) /* 0x4cac34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ac15b  751c                   -jne 0x4ac179
    if (!cpu.flags.zf)
    {
        goto L_0x004ac179;
    }
    // 004ac15d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ac15f  7408                   -je 0x4ac169
    if (cpu.flags.zf)
    {
        goto L_0x004ac169;
    }
    // 004ac161  893534ac4c00           -mov dword ptr [0x4cac34], esi
    app->getMemory<x86::reg32>(x86::reg32(5024820) /* 0x4cac34 */) = cpu.esi;
    // 004ac167  eb10                   -jmp 0x4ac179
    goto L_0x004ac179;
L_0x004ac169:
    // 004ac169  a130ac4c00             -mov eax, dword ptr [0x4cac30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024816) /* 0x4cac30 */);
    // 004ac16e  893538ac4c00           -mov dword ptr [0x4cac38], esi
    app->getMemory<x86::reg32>(x86::reg32(5024824) /* 0x4cac38 */) = cpu.esi;
    // 004ac174  a334ac4c00             -mov dword ptr [0x4cac34], eax
    app->getMemory<x86::reg32>(x86::reg32(5024820) /* 0x4cac34 */) = cpu.eax;
L_0x004ac179:
    // 004ac179  3b1d042c5400           +cmp ebx, dword ptr [0x542c04]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5516292) /* 0x542c04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ac17f  7508                   -jne 0x4ac189
    if (!cpu.flags.zf)
    {
        goto L_0x004ac189;
    }
    // 004ac181  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004ac183  893d042c5400           -mov dword ptr [0x542c04], edi
    app->getMemory<x86::reg32>(x86::reg32(5516292) /* 0x542c04 */) = cpu.edi;
L_0x004ac189:
    // 004ac189  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004ac18b:
    // 004ac18b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac18c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac18d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac18e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac18f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac190  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac191(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac191  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ac192  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ac193  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ac196  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ac199  e893ffffff             -call 0x4ac131
    cpu.esp -= 4;
    sub_4ac131(app, cpu);
    if (cpu.terminate) return;
    // 004ac19e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac1a0  7516                   -jne 0x4ac1b8
    if (!cpu.flags.zf)
    {
        goto L_0x004ac1b8;
    }
    // 004ac1a2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ac1a4  7508                   -jne 0x4ac1ae
    if (!cpu.flags.zf)
    {
        goto L_0x004ac1ae;
    }
    // 004ac1a6  891530ac4c00           -mov dword ptr [0x4cac30], edx
    app->getMemory<x86::reg32>(x86::reg32(5024816) /* 0x4cac30 */) = cpu.edx;
    // 004ac1ac  eb03                   -jmp 0x4ac1b1
    goto L_0x004ac1b1;
L_0x004ac1ae:
    // 004ac1ae  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x004ac1b1:
    // 004ac1b1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ac1b3  7403                   -je 0x4ac1b8
    if (cpu.flags.zf)
    {
        goto L_0x004ac1b8;
    }
    // 004ac1b5  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x004ac1b8:
    // 004ac1b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac1b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac1ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac1bb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x004ac1bb:
    // 004ac1bb  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ac1bd  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004ac1c0  83e92c                 -sub ecx, 0x2c
    (cpu.ecx) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004ac1c3  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004ac1c5  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ac1c8  39f1                   +cmp ecx, esi
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
    // 004ac1ca  7505                   -jne 0x4ac1d1
    if (!cpu.flags.zf)
    {
        goto L_0x004ac1d1;
    }
    // 004ac1cc  e8c0ffffff             -call 0x4ac191
    cpu.esp -= 4;
    sub_4ac191(app, cpu);
    if (cpu.terminate) return;
L_0x004ac1d1:
    // 004ac1d1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ac1d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac1d5  75e4                   -jne 0x4ac1bb
    if (!cpu.flags.zf)
    {
        goto L_0x004ac1bb;
    }
    // 004ac1d7  ff1568c14c00           -call dword ptr [0x4cc168]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030248) /* 0x4cc168 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ac1dd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac1df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac1e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac1e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac1e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac1e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac1d3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004ac1d3;
L_0x004ac1bb:
    // 004ac1bb  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ac1bd  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004ac1c0  83e92c                 -sub ecx, 0x2c
    (cpu.ecx) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004ac1c3  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004ac1c5  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ac1c8  39f1                   +cmp ecx, esi
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
    // 004ac1ca  7505                   -jne 0x4ac1d1
    if (!cpu.flags.zf)
    {
        goto L_0x004ac1d1;
    }
    // 004ac1cc  e8c0ffffff             -call 0x4ac191
    cpu.esp -= 4;
    sub_4ac191(app, cpu);
    if (cpu.terminate) return;
L_0x004ac1d1:
    // 004ac1d1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_entry_0x004ac1d3:
    // 004ac1d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac1d5  75e4                   -jne 0x4ac1bb
    if (!cpu.flags.zf)
    {
        goto L_0x004ac1bb;
    }
    // 004ac1d7  ff1568c14c00           -call dword ptr [0x4cc168]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030248) /* 0x4cc168 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ac1dd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac1df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac1e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac1e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac1e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac1e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac1e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac1e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac1e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac1e6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ac1e7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac1e8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ac1eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ac1ec  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004ac1ee  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004ac1f2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac1f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac1f6  0f8472000000           -je 0x4ac26e
    if (cpu.flags.zf)
    {
        goto L_0x004ac26e;
    }
L_0x004ac1fc:
    // 004ac1fc  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004ac201  0f8689000000           -jbe 0x4ac290
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ac290;
    }
    // 004ac207  668b4d00               -mov cx, word ptr [ebp]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp);
    // 004ac20b  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 004ac20e  7421                   -je 0x4ac231
    if (cpu.flags.zf)
    {
        goto L_0x004ac231;
    }
    // 004ac210  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac212  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac216  6689ca                 -mov dx, cx
    cpu.dx = cpu.cx;
    // 004ac219  e815fdffff             -call 0x4abf33
    cpu.esp -= 4;
    sub_4abf33(app, cpu);
    if (cpu.terminate) return;
    // 004ac21e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ac220  83f8ff                 +cmp eax, -1
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
    // 004ac223  0f8469000000           -je 0x4ac292
    if (cpu.flags.zf)
    {
        goto L_0x004ac292;
    }
    // 004ac229  3b442404               +cmp eax, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ac22d  7761                   -ja 0x4ac290
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ac290;
    }
    // 004ac22f  eb08                   -jmp 0x4ac239
    goto L_0x004ac239;
L_0x004ac231:
    // 004ac231  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ac234  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004ac237  eb57                   -jmp 0x4ac290
    goto L_0x004ac290;
L_0x004ac239:
    // 004ac239  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac23d  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004ac240  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ac242  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004ac243  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004ac245  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004ac247  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ac248  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ac24a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004ac24d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004ac24f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004ac251  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004ac254  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004ac256  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac257  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ac258  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ac25b  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ac25d  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ac261  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ac263  29d0                   +sub eax, edx
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
    // 004ac265  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004ac268  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ac26c  eb8e                   -jmp 0x4ac1fc
    goto L_0x004ac1fc;
L_0x004ac26e:
    // 004ac26e  66837d0000             +cmp word ptr [ebp], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004ac273  741b                   -je 0x4ac290
    if (cpu.flags.zf)
    {
        goto L_0x004ac290;
    }
    // 004ac275  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac277  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac27b  668b5500               -mov dx, word ptr [ebp]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp);
    // 004ac27f  e8affcffff             -call 0x4abf33
    cpu.esp -= 4;
    sub_4abf33(app, cpu);
    if (cpu.terminate) return;
    // 004ac284  83f8ff                 +cmp eax, -1
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
    // 004ac287  7409                   -je 0x4ac292
    if (cpu.flags.zf)
    {
        goto L_0x004ac292;
    }
    // 004ac289  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ac28c  01c3                   +add ebx, eax
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
    // 004ac28e  ebde                   -jmp 0x4ac26e
    goto L_0x004ac26e;
L_0x004ac290:
    // 004ac290  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004ac292:
    // 004ac292  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ac295  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac296  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac297  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac298  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac299  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4ac29c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac29c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac29d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ac29f  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004ac2a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac2a1  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004ac2a4  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004ac2a7  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004ac2aa  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004ac2ad  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004ac2b0  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ac2b3  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ac2b5  891d1cd94c00           -mov dword ptr [0x4cd91c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5036316) /* 0x4cd91c */) = cpu.ebx;
    // 004ac2bb  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ac2be  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004ac2c1  83f901                 +cmp ecx, 1
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
    // 004ac2c4  7e7a                   -jle 0x4ac340
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ac340;
    }
    // 004ac2c6  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004ac2c9:
    // 004ac2c9  db051ed94c00           -fild dword ptr [0x4cd91e]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5036318) /* 0x4cd91e */))));
    // 004ac2cf  d904ae                 -fld dword ptr [esi + ebp*4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.ebp * 4)));
    // 004ac2d2  d944ae04               -fld dword ptr [esi + ebp*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 4)));
    // 004ac2d6  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ac2d9  03da                   +add ebx, edx
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
    // 004ac2db  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ac2dd  891d1cd94c00           -mov dword ptr [0x4cd91c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5036316) /* 0x4cd91c */) = cpu.ebx;
    // 004ac2e3  db051ed94c00           -fild dword ptr [0x4cd91e]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5036318) /* 0x4cd91e */))));
    // 004ac2e9  d904ae                 -fld dword ptr [esi + ebp*4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.ebp * 4)));
    // 004ac2ec  d944ae04               -fld dword ptr [esi + ebp*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 4)));
    // 004ac2f0  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004ac2f2  d80d18d94c00           -fmul dword ptr [0x4cd918]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5036312) /* 0x4cd918 */));
    // 004ac2f8  d90514d94c00           -fld dword ptr [0x4cd914]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036308) /* 0x4cd914 */)));
    // 004ac2fe  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004ac300  d80d18d94c00           -fmul dword ptr [0x4cd918]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5036312) /* 0x4cd918 */));
    // 004ac306  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ac308  dceb                   -fsub st(3), st(0)
    cpu.fpu.st(3) -= x86::Float(cpu.fpu.st(0));
    // 004ac30a  d90514d94c00           -fld dword ptr [0x4cd914]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036308) /* 0x4cd914 */)));
    // 004ac310  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004ac312  dcea                   -fsub st(2), st(0)
    cpu.fpu.st(2) -= x86::Float(cpu.fpu.st(0));
    // 004ac314  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004ac316  dece                   -fmulp st(6)
    cpu.fpu.st(6) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ac318  03da                   +add ebx, edx
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
    // 004ac31a  decc                   +fmulp st(4)
    cpu.fpu.st(4) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ac31c  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ac31e  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ac320  decc                   +fmulp st(4)
    cpu.fpu.st(4) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ac322  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004ac324  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ac326  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ac328  dec2                   +faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ac32a  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ac32c  891d1cd94c00           -mov dword ptr [0x4cd91c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5036316) /* 0x4cd91c */) = cpu.ebx;
    // 004ac332  d95ff8                 -fstp dword ptr [edi - 8]
    app->getMemory<float>(cpu.edi + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ac335  d95ffc                 -fstp dword ptr [edi - 4]
    app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ac338  83e902                 +sub ecx, 2
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
    // 004ac33b  7f8c                   -jg 0x4ac2c9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ac2c9;
    }
    // 004ac33d  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004ac340:
    // 004ac340  83f900                 +cmp ecx, 0
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
    // 004ac343  7e36                   -jle 0x4ac37b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ac37b;
    }
    // 004ac345  db051ed94c00           -fild dword ptr [0x4cd91e]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5036318) /* 0x4cd91e */))));
    // 004ac34b  d90514d94c00           -fld dword ptr [0x4cd914]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036308) /* 0x4cd914 */)));
    // 004ac351  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ac353  d80d18d94c00           -fmul dword ptr [0x4cd918]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5036312) /* 0x4cd918 */));
    // 004ac359  dce9                   -fsub st(1), st(0)
    cpu.fpu.st(1) -= x86::Float(cpu.fpu.st(0));
    // 004ac35b  d84cae04               -fmul dword ptr [esi + ebp*4 + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 4));
    // 004ac35f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ac361  d80cae                 -fmul dword ptr [esi + ebp*4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + cpu.ebp * 4));
    // 004ac364  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ac366  03da                   +add ebx, edx
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
    // 004ac368  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ac36a  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ac36d  891d1cd94c00           -mov dword ptr [0x4cd91c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5036316) /* 0x4cd91c */) = cpu.ebx;
    // 004ac373  d95ffc                 -fstp dword ptr [edi - 4]
    app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ac376  83e901                 +sub ecx, 1
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
    // 004ac379  7fc5                   -jg 0x4ac340
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ac340;
    }
L_0x004ac37b:
    // 004ac37b  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ac37d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac37e  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ac381  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004ac383  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ac386  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004ac388  61                     -popal 
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
    // 004ac389  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac38a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4ac38c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac38c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac38d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ac38f  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004ac390  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac391  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004ac394  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004ac397  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004ac39a  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004ac39d  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004ac3a0  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ac3a3  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ac3a5  891d2cd94c00           -mov dword ptr [0x4cd92c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5036332) /* 0x4cd92c */) = cpu.ebx;
    // 004ac3ab  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ac3ae  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004ac3b1  eb06                   -jmp 0x4ac3b9
    goto L_0x004ac3b9;
L_0x004ac3b3:
    // 004ac3b3  d95ff8                 -fstp dword ptr [edi - 8]
    app->getMemory<float>(cpu.edi + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ac3b6  d95ffc                 -fstp dword ptr [edi - 4]
    app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004ac3b9:
    // 004ac3b9  db052ed94c00           -fild dword ptr [0x4cd92e]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5036334) /* 0x4cd92e */))));
    // 004ac3bf  d90524d94c00           -fld dword ptr [0x4cd924]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5036324) /* 0x4cd924 */)));
    // 004ac3c5  d904ee                 -fld dword ptr [esi + ebp*8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.ebp * 8)));
    // 004ac3c8  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004ac3ca  d80d28d94c00           -fmul dword ptr [0x4cd928]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5036328) /* 0x4cd928 */));
    // 004ac3d0  d944ee04               -fld dword ptr [esi + ebp*8 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 8)));
    // 004ac3d4  d944ee08               -fld dword ptr [esi + ebp*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.ebp * 8)));
    // 004ac3d8  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004ac3da  dceb                   -fsub st(3), st(0)
    cpu.fpu.st(3) -= x86::Float(cpu.fpu.st(0));
    // 004ac3dc  dcca                   -fmul st(2), st(0)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    // 004ac3de  d944ee0c               -fld dword ptr [esi + ebp*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.ebp * 8)));
    // 004ac3e2  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004ac3e4  dccd                   -fmul st(5), st(0)
    cpu.fpu.st(5) *= cpu.fpu.st(0);
    // 004ac3e6  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ac3e9  03da                   +add ebx, edx
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
    // 004ac3eb  deca                   +fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ac3ed  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ac3ef  891d2cd94c00           -mov dword ptr [0x4cd92c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5036332) /* 0x4cd92c */) = cpu.ebx;
    // 004ac3f5  decb                   -fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ac3f7  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004ac3f9  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ac3fb  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ac3fd  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ac3ff  83e901                 +sub ecx, 1
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
    // 004ac402  7faf                   -jg 0x4ac3b3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ac3b3;
    }
    // 004ac404  d95ff8                 -fstp dword ptr [edi - 8]
    app->getMemory<float>(cpu.edi + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ac407  d95ffc                 -fstp dword ptr [edi - 4]
    app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ac40a  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ac40c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac40d  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ac410  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004ac412  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ac415  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004ac417  61                     -popal 
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
    // 004ac418  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac419  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4ac41c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac41c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac41d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ac41f  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004ac420  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac421  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 004ac426  0f6edb                 -movd mm3, ebx
    cpu.mmx.mm3 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ac429  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004ac42c  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004ac42f  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004ac432  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004ac435  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004ac438  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ac43b  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ac43d  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ac440  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004ac443  0f6ecb                 -movd mm1, ebx
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ac446  0f6ed3                 -movd mm2, ebx
    cpu.mmx.mm2 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ac449  0f72d110               -psrld mm1, 0x10
    cpu.mmx.mm1 = { _mm_srli_epi32(cpu.mmx.mm1, 16 /*0x10*/) };
    // 004ac44d  0febca                 -por mm1, mm2
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm2) };
    // 004ac450  0fefcb                 -pxor mm1, mm3
    cpu.mmx.mm1 = { _mm_xor_si128(cpu.mmx.mm1, cpu.mmx.mm3) };
    // 004ac453  4a                     -dec edx
    (cpu.edx)--;
    // 004ac454  0f6ee2                 -movd mm4, edx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004ac457  42                     -inc edx
    (cpu.edx)++;
    // 004ac458  0f6eea                 -movd mm5, edx
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004ac45b  0f72d410               -psrld mm4, 0x10
    cpu.mmx.mm4 = { _mm_srli_epi32(cpu.mmx.mm4, 16 /*0x10*/) };
    // 004ac45f  0febe5                 -por mm4, mm5
    cpu.mmx.mm4 = { _mm_or_si128(cpu.mmx.mm4, cpu.mmx.mm5) };
    // 004ac462  0fefe3                 -pxor mm4, mm3
    cpu.mmx.mm4 = { _mm_xor_si128(cpu.mmx.mm4, cpu.mmx.mm3) };
L_0x004ac465:
    // 004ac465  0f60443500             -punpcklbw mm0, dword ptr [ebp + esi]
    cpu.mmx.mm0 = { _mm_unpacklo_epi8(cpu.mmx.mm0, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + cpu.esi * 1))) };
    // 004ac46a  0f6fd1                 -movq mm2, mm1
    cpu.mmx.mm2 = cpu.mmx.mm1;
    // 004ac46d  0f71d201               -psrlw mm2, 1
    cpu.mmx.mm2 = { _mm_srli_epi16(cpu.mmx.mm2, 1 /*0x1*/) };
    // 004ac471  0ff5c2                 -pmaddwd mm0, mm2
    cpu.mmx.mm0 = { _mm_madd_epi16(cpu.mmx.mm0, cpu.mmx.mm2) };
    // 004ac474  0f73d017               -psrlq mm0, 0x17
    cpu.mmx.mm0 = { _mm_srli_epi64(cpu.mmx.mm0, 23 /*0x17*/) };
    // 004ac478  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac479  0f7ec1                 -movd ecx, mm0
    cpu.ecx = _mm_cvtsi128_si32(cpu.mmx.mm0);
    // 004ac47c  0ffdcc                 -paddw mm1, mm4
    cpu.mmx.mm1 = { _mm_add_epi16(cpu.mmx.mm1, cpu.mmx.mm4) };
    // 004ac47f  880f                   -mov byte ptr [edi], cl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.cl;
    // 004ac481  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac482  03da                   +add ebx, edx
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
    // 004ac484  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ac486  83c701                 +add edi, 1
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ac489  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ac48a  7fd9                   -jg 0x4ac465
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ac465;
    }
    // 004ac48c  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ac48e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac48f  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ac492  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004ac494  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ac497  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004ac499  61                     -popal 
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
    // 004ac49a  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac49b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac49c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac49c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac49d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ac49f  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004ac4a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac4a1  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 004ac4a6  0f6ee3                 -movd mm4, ebx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ac4a9  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004ac4ac  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004ac4af  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004ac4b2  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004ac4b5  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004ac4b8  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ac4bb  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ac4bd  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ac4c0  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004ac4c3  0f6ed3                 -movd mm2, ebx
    cpu.mmx.mm2 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ac4c6  0f6edb                 -movd mm3, ebx
    cpu.mmx.mm3 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ac4c9  0f72d210               -psrld mm2, 0x10
    cpu.mmx.mm2 = { _mm_srli_epi32(cpu.mmx.mm2, 16 /*0x10*/) };
    // 004ac4cd  0febd3                 -por mm2, mm3
    cpu.mmx.mm2 = { _mm_or_si128(cpu.mmx.mm2, cpu.mmx.mm3) };
    // 004ac4d0  0fefd4                 -pxor mm2, mm4
    cpu.mmx.mm2 = { _mm_xor_si128(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004ac4d3  0f6fea                 -movq mm5, mm2
    cpu.mmx.mm5 = cpu.mmx.mm2;
    // 004ac4d6  0f73f220               -psllq mm2, 0x20
    cpu.mmx.mm2 = { _mm_slli_epi64(cpu.mmx.mm2, 32 /*0x20*/) };
    // 004ac4da  0febd5                 -por mm2, mm5
    cpu.mmx.mm2 = { _mm_or_si128(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 004ac4dd  4a                     -dec edx
    (cpu.edx)--;
    // 004ac4de  0f6eea                 -movd mm5, edx
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004ac4e1  42                     -inc edx
    (cpu.edx)++;
    // 004ac4e2  0f6ef2                 -movd mm6, edx
    cpu.mmx.mm6 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004ac4e5  0f72d510               -psrld mm5, 0x10
    cpu.mmx.mm5 = { _mm_srli_epi32(cpu.mmx.mm5, 16 /*0x10*/) };
    // 004ac4e9  0febee                 -por mm5, mm6
    cpu.mmx.mm5 = { _mm_or_si128(cpu.mmx.mm5, cpu.mmx.mm6) };
    // 004ac4ec  0fefec                 -pxor mm5, mm4
    cpu.mmx.mm5 = { _mm_xor_si128(cpu.mmx.mm5, cpu.mmx.mm4) };
    // 004ac4ef  0f6fe5                 -movq mm4, mm5
    cpu.mmx.mm4 = cpu.mmx.mm5;
    // 004ac4f2  0f73f520               -psllq mm5, 0x20
    cpu.mmx.mm5 = { _mm_slli_epi64(cpu.mmx.mm5, 32 /*0x20*/) };
    // 004ac4f6  0febec                 -por mm5, mm4
    cpu.mmx.mm5 = { _mm_or_si128(cpu.mmx.mm5, cpu.mmx.mm4) };
L_0x004ac4f9:
    // 004ac4f9  0f6e0c6e               -movd mm1, dword ptr [esi + ebp*2]
    cpu.mmx.mm1 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.esi + cpu.ebp * 2)) };
    // 004ac4fd  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004ac500  0f71d301               -psrlw mm3, 1
    cpu.mmx.mm3 = { _mm_srli_epi16(cpu.mmx.mm3, 1 /*0x1*/) };
    // 004ac504  0f604c6e02             -punpcklbw mm1, dword ptr [esi + ebp*2 + 2]
    cpu.mmx.mm1 = { _mm_unpacklo_epi8(cpu.mmx.mm1, x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.ebp * 2))) };
    // 004ac509  0f60c1                 -punpcklbw mm0, mm1
    cpu.mmx.mm0 = { _mm_unpacklo_epi8(cpu.mmx.mm0, cpu.mmx.mm1) };
    // 004ac50c  0ff5c3                 -pmaddwd mm0, mm3
    cpu.mmx.mm0 = { _mm_madd_epi16(cpu.mmx.mm0, cpu.mmx.mm3) };
    // 004ac50f  0f72e017               -psrad mm0, 0x17
    cpu.mmx.mm0 = { _mm_srai_epi32(cpu.mmx.mm0, 23 /*0x17*/) };
    // 004ac513  0ffdd5                 -paddw mm2, mm5
    cpu.mmx.mm2 = { _mm_add_epi16(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 004ac516  0f6bc1                 -packssdw mm0, mm1
    { __m128i _packed = _mm_packs_epi32(cpu.mmx.mm0, cpu.mmx.mm1); cpu.mmx.mm0 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004ac519  0f63c1                 -packsswb mm0, mm1
    { __m128i _packed = _mm_packs_epi16(cpu.mmx.mm0, cpu.mmx.mm1); cpu.mmx.mm0 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004ac51c  03da                   +add ebx, edx
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
    // 004ac51e  0f7e07                 -movd dword ptr [edi], mm0
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.edi), cpu.mmx.mm0);
    // 004ac521  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ac523  83c702                 +add edi, 2
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ac526  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ac527  7fd0                   -jg 0x4ac4f9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ac4f9;
    }
    // 004ac529  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ac52b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac52c  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ac52f  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004ac531  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ac534  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004ac536  61                     -popal 
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
    // 004ac537  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac538  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4ac53c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac53c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac53d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ac53f  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004ac540  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac541  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 004ac546  0f6edb                 -movd mm3, ebx
    cpu.mmx.mm3 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ac549  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004ac54c  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004ac54f  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004ac552  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004ac555  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004ac558  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ac55b  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ac55d  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ac560  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004ac563  0f6ecb                 -movd mm1, ebx
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ac566  0f6ed3                 -movd mm2, ebx
    cpu.mmx.mm2 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ac569  0f72d110               -psrld mm1, 0x10
    cpu.mmx.mm1 = { _mm_srli_epi32(cpu.mmx.mm1, 16 /*0x10*/) };
    // 004ac56d  0febca                 -por mm1, mm2
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm2) };
    // 004ac570  0fefcb                 -pxor mm1, mm3
    cpu.mmx.mm1 = { _mm_xor_si128(cpu.mmx.mm1, cpu.mmx.mm3) };
    // 004ac573  4a                     -dec edx
    (cpu.edx)--;
    // 004ac574  0f6ee2                 -movd mm4, edx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004ac577  42                     -inc edx
    (cpu.edx)++;
    // 004ac578  0f6eea                 -movd mm5, edx
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004ac57b  0f72d410               -psrld mm4, 0x10
    cpu.mmx.mm4 = { _mm_srli_epi32(cpu.mmx.mm4, 16 /*0x10*/) };
    // 004ac57f  0febe5                 -por mm4, mm5
    cpu.mmx.mm4 = { _mm_or_si128(cpu.mmx.mm4, cpu.mmx.mm5) };
    // 004ac582  0fefe3                 -pxor mm4, mm3
    cpu.mmx.mm4 = { _mm_xor_si128(cpu.mmx.mm4, cpu.mmx.mm3) };
L_0x004ac585:
    // 004ac585  0f6e046e               -movd mm0, dword ptr [esi + ebp*2]
    cpu.mmx.mm0 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.esi + cpu.ebp * 2)) };
    // 004ac589  0f6fd1                 -movq mm2, mm1
    cpu.mmx.mm2 = cpu.mmx.mm1;
    // 004ac58c  0f71d201               -psrlw mm2, 1
    cpu.mmx.mm2 = { _mm_srli_epi16(cpu.mmx.mm2, 1 /*0x1*/) };
    // 004ac590  0ff5c2                 -pmaddwd mm0, mm2
    cpu.mmx.mm0 = { _mm_madd_epi16(cpu.mmx.mm0, cpu.mmx.mm2) };
    // 004ac593  0f73d00f               -psrlq mm0, 0xf
    cpu.mmx.mm0 = { _mm_srli_epi64(cpu.mmx.mm0, 15 /*0xf*/) };
    // 004ac597  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac598  0f7ec1                 -movd ecx, mm0
    cpu.ecx = _mm_cvtsi128_si32(cpu.mmx.mm0);
    // 004ac59b  0ffdcc                 -paddw mm1, mm4
    cpu.mmx.mm1 = { _mm_add_epi16(cpu.mmx.mm1, cpu.mmx.mm4) };
    // 004ac59e  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 004ac5a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac5a2  03da                   +add ebx, edx
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
    // 004ac5a4  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ac5a6  83c702                 +add edi, 2
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ac5a9  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ac5aa  7fd9                   -jg 0x4ac585
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ac585;
    }
    // 004ac5ac  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ac5ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac5af  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ac5b2  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004ac5b4  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ac5b7  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004ac5b9  61                     -popal 
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
    // 004ac5ba  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac5bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac5bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac5bc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac5bd  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ac5bf  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004ac5c0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac5c1  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 004ac5c6  0f6ee3                 -movd mm4, ebx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ac5c9  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004ac5cc  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004ac5cf  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004ac5d2  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004ac5d5  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004ac5d8  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ac5db  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ac5dd  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ac5e0  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004ac5e3  0f6ed3                 -movd mm2, ebx
    cpu.mmx.mm2 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ac5e6  0f6edb                 -movd mm3, ebx
    cpu.mmx.mm3 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ac5e9  0f72d210               -psrld mm2, 0x10
    cpu.mmx.mm2 = { _mm_srli_epi32(cpu.mmx.mm2, 16 /*0x10*/) };
    // 004ac5ed  0febd3                 -por mm2, mm3
    cpu.mmx.mm2 = { _mm_or_si128(cpu.mmx.mm2, cpu.mmx.mm3) };
    // 004ac5f0  0fefd4                 -pxor mm2, mm4
    cpu.mmx.mm2 = { _mm_xor_si128(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004ac5f3  0f6fea                 -movq mm5, mm2
    cpu.mmx.mm5 = cpu.mmx.mm2;
    // 004ac5f6  0f73f220               -psllq mm2, 0x20
    cpu.mmx.mm2 = { _mm_slli_epi64(cpu.mmx.mm2, 32 /*0x20*/) };
    // 004ac5fa  0febd5                 -por mm2, mm5
    cpu.mmx.mm2 = { _mm_or_si128(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 004ac5fd  4a                     -dec edx
    (cpu.edx)--;
    // 004ac5fe  0f6eea                 -movd mm5, edx
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004ac601  42                     -inc edx
    (cpu.edx)++;
    // 004ac602  0f6ef2                 -movd mm6, edx
    cpu.mmx.mm6 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004ac605  0f72d510               -psrld mm5, 0x10
    cpu.mmx.mm5 = { _mm_srli_epi32(cpu.mmx.mm5, 16 /*0x10*/) };
    // 004ac609  0febee                 -por mm5, mm6
    cpu.mmx.mm5 = { _mm_or_si128(cpu.mmx.mm5, cpu.mmx.mm6) };
    // 004ac60c  0fefec                 -pxor mm5, mm4
    cpu.mmx.mm5 = { _mm_xor_si128(cpu.mmx.mm5, cpu.mmx.mm4) };
    // 004ac60f  0f6fe5                 -movq mm4, mm5
    cpu.mmx.mm4 = cpu.mmx.mm5;
    // 004ac612  0f73f520               -psllq mm5, 0x20
    cpu.mmx.mm5 = { _mm_slli_epi64(cpu.mmx.mm5, 32 /*0x20*/) };
    // 004ac616  0febec                 -por mm5, mm4
    cpu.mmx.mm5 = { _mm_or_si128(cpu.mmx.mm5, cpu.mmx.mm4) };
L_0x004ac619:
    // 004ac619  0f6e04ae               -movd mm0, dword ptr [esi + ebp*4]
    cpu.mmx.mm0 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.esi + cpu.ebp * 4)) };
    // 004ac61d  0f6144ae04             -punpcklwd mm0, dword ptr [esi + ebp*4 + 4]
    cpu.mmx.mm0 = { _mm_unpacklo_epi16(cpu.mmx.mm0, x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 4))) };
    // 004ac622  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004ac625  0f71d301               -psrlw mm3, 1
    cpu.mmx.mm3 = { _mm_srli_epi16(cpu.mmx.mm3, 1 /*0x1*/) };
    // 004ac629  0ff5c3                 -pmaddwd mm0, mm3
    cpu.mmx.mm0 = { _mm_madd_epi16(cpu.mmx.mm0, cpu.mmx.mm3) };
    // 004ac62c  0f72e00f               -psrad mm0, 0xf
    cpu.mmx.mm0 = { _mm_srai_epi32(cpu.mmx.mm0, 15 /*0xf*/) };
    // 004ac630  0ffdd5                 -paddw mm2, mm5
    cpu.mmx.mm2 = { _mm_add_epi16(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 004ac633  0f6bc1                 -packssdw mm0, mm1
    { __m128i _packed = _mm_packs_epi32(cpu.mmx.mm0, cpu.mmx.mm1); cpu.mmx.mm0 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004ac636  03da                   +add ebx, edx
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
    // 004ac638  0f7e07                 -movd dword ptr [edi], mm0
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.edi), cpu.mmx.mm0);
    // 004ac63b  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ac63d  83c704                 +add edi, 4
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
    // 004ac640  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ac641  7fd6                   -jg 0x4ac619
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ac619;
    }
    // 004ac643  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ac645  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac646  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ac649  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004ac64b  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ac64e  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004ac650  61                     -popal 
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
    // 004ac651  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac652  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac660  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac661  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac665  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac666  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac66a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac66b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004ac670  e8334a0000             -call 0x4b10a8
    cpu.esp -= 4;
    sub_4b10a8(app, cpu);
    if (cpu.terminate) return;
    // 004ac675  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac676  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac680  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac681  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ac683  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac687  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac68b  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004ac691  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ac695  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac696  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ac698  e8d74a0000             -call 0x4b1174
    cpu.esp -= 4;
    sub_4b1174(app, cpu);
    if (cpu.terminate) return;
    // 004ac69d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac69e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac6b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac6b0  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac6b4  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ac6b8  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004ac6be  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004ac6c3  e8044c0000             -call 0x4b12cc
    cpu.esp -= 4;
    sub_4b12cc(app, cpu);
    if (cpu.terminate) return;
    // 004ac6c8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac6d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac6d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac6d1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac6d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac6d6  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac6da  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac6db  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004ac6e0  e8c3490000             -call 0x4b10a8
    cpu.esp -= 4;
    sub_4b10a8(app, cpu);
    if (cpu.terminate) return;
    // 004ac6e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac6e6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac6f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac6f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac6f1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ac6f3  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac6f7  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac6fb  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004ac701  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ac705  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac706  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004ac708  e8674a0000             -call 0x4b1174
    cpu.esp -= 4;
    sub_4b1174(app, cpu);
    if (cpu.terminate) return;
    // 004ac70d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac70e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac720  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac724  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ac728  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004ac72e  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004ac733  e8944b0000             -call 0x4b12cc
    cpu.esp -= 4;
    sub_4b12cc(app, cpu);
    if (cpu.terminate) return;
    // 004ac738  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac740  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ac743  b880ffffff             -mov eax, 0xffffff80
    cpu.eax = 4294967168 /*0xffffff80*/;
    // 004ac748  dd0558fb4b00           -fld qword ptr [0x4bfb58]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4979544) /* 0x4bfb58 */)));
L_0x004ac74e:
    // 004ac74e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004ac751  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac753  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004ac756  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004ac758  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004ac75a  40                     -inc eax
    (cpu.eax)++;
    // 004ac75b  d91c95a0715400         -fstp dword ptr [edx*4 + 0x5471a0]
    app->getMemory<float>(x86::reg32(5534112) /* 0x5471a0 */ + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ac762  83f87f                 +cmp eax, 0x7f
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
    // 004ac765  7ee7                   -jle 0x4ac74e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ac74e;
    }
    // 004ac767  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ac769  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ac76c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4ac770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac770  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac771  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac775  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac776  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac77a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac77b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ac77d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ac77f  e8584c0000             -call 0x4b13dc
    cpu.esp -= 4;
    sub_4b13dc(app, cpu);
    if (cpu.terminate) return;
    // 004ac784  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac785  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac790  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac791  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ac793  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac797  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac79b  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004ac7a1  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ac7a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac7a6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ac7a8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ac7aa  e8014d0000             -call 0x4b14b0
    cpu.esp -= 4;
    sub_4b14b0(app, cpu);
    if (cpu.terminate) return;
    // 004ac7af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac7b0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac7c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac7c0  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac7c4  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ac7c8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac7ca  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004ac7d0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac7d2  e8654e0000             -call 0x4b163c
    cpu.esp -= 4;
    sub_4b163c(app, cpu);
    if (cpu.terminate) return;
    // 004ac7d7  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac7e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac7e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac7e1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac7e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac7e6  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac7ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac7eb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ac7ed  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ac7ef  e8e84b0000             -call 0x4b13dc
    cpu.esp -= 4;
    sub_4b13dc(app, cpu);
    if (cpu.terminate) return;
    // 004ac7f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac7f5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac800  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac801  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ac803  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac807  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac80b  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004ac811  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ac815  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac816  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ac818  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ac81a  e8914c0000             -call 0x4b14b0
    cpu.esp -= 4;
    sub_4b14b0(app, cpu);
    if (cpu.terminate) return;
    // 004ac81f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac820  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac830  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac834  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ac838  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004ac83d  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004ac843  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac845  e8f24d0000             -call 0x4b163c
    cpu.esp -= 4;
    sub_4b163c(app, cpu);
    if (cpu.terminate) return;
    // 004ac84a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4ac850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac850  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac851  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac855  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac856  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac85a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac85b  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004ac860  e843480000             -call 0x4b10a8
    cpu.esp -= 4;
    sub_4b10a8(app, cpu);
    if (cpu.terminate) return;
    // 004ac865  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac866  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac870  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac871  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ac873  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac877  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac87b  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004ac881  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ac885  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac886  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004ac888  e8e7480000             -call 0x4b1174
    cpu.esp -= 4;
    sub_4b1174(app, cpu);
    if (cpu.terminate) return;
    // 004ac88d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac88e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac8a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac8a0  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac8a4  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ac8a8  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004ac8ae  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004ac8b3  e8144a0000             -call 0x4b12cc
    cpu.esp -= 4;
    sub_4b12cc(app, cpu);
    if (cpu.terminate) return;
    // 004ac8b8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac8c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac8c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac8c1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac8c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac8c6  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac8ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac8cb  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004ac8d0  e8d3470000             -call 0x4b10a8
    cpu.esp -= 4;
    sub_4b10a8(app, cpu);
    if (cpu.terminate) return;
    // 004ac8d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac8d6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac8e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac8e1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ac8e3  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac8e7  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac8eb  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004ac8f1  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ac8f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac8f6  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004ac8f8  e877480000             -call 0x4b1174
    cpu.esp -= 4;
    sub_4b1174(app, cpu);
    if (cpu.terminate) return;
    // 004ac8fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac8fe  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac910  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac914  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ac918  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004ac91e  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004ac923  e8a4490000             -call 0x4b12cc
    cpu.esp -= 4;
    sub_4b12cc(app, cpu);
    if (cpu.terminate) return;
    // 004ac928  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac930  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac931  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac935  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac936  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac93a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac93b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ac93d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004ac942  e8954a0000             -call 0x4b13dc
    cpu.esp -= 4;
    sub_4b13dc(app, cpu);
    if (cpu.terminate) return;
    // 004ac947  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac948  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac950  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac951  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ac953  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac957  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac95b  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004ac961  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ac965  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac966  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ac968  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ac96a  e8414b0000             -call 0x4b14b0
    cpu.esp -= 4;
    sub_4b14b0(app, cpu);
    if (cpu.terminate) return;
    // 004ac96f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac970  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac980  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac984  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ac988  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac98a  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004ac990  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004ac995  e8a24c0000             -call 0x4b163c
    cpu.esp -= 4;
    sub_4b163c(app, cpu);
    if (cpu.terminate) return;
    // 004ac99a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4ac9a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac9a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac9a1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac9a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac9a6  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac9aa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac9ab  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ac9ad  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004ac9b2  e8254a0000             -call 0x4b13dc
    cpu.esp -= 4;
    sub_4b13dc(app, cpu);
    if (cpu.terminate) return;
    // 004ac9b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac9b8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac9c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac9c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac9c1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ac9c3  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac9c7  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ac9cb  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004ac9d1  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ac9d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac9d6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ac9d8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ac9da  e8d14a0000             -call 0x4b14b0
    cpu.esp -= 4;
    sub_4b14b0(app, cpu);
    if (cpu.terminate) return;
    // 004ac9df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac9e0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ac9f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac9f0  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ac9f4  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ac9f8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004ac9fd  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004aca03  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aca05  e8324c0000             -call 0x4b163c
    cpu.esp -= 4;
    sub_4b163c(app, cpu);
    if (cpu.terminate) return;
    // 004aca0a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4aca10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aca10  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004aca13  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
