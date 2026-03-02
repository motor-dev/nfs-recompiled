#include "voodoo2a.h"
#include <lib/thread.h>

namespace voodoo2a
{

/* align: skip  */
void sub_a83200(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x00a83200:
    // 00a83200  cc                     -int3 
    NFS2_ASSERT(false);
    // 00a83201  ebfd                   -jmp 0xa83200
    goto L_0x00a83200;
}

/* align: skip 0x90 */
/* data blob: 909090000000000000000000 */
void sub_a83210(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a83210  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a83215  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a83220(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a83220  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a83221  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a83222  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a83223  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a83224  8b15341fa900           -mov edx, dword ptr [0xa91f34]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083572) /* 0xa91f34 */);
    // 00a8322a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8322c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8322e  750a                   -jne 0xa8323a
    if (!cpu.flags.zf)
    {
        goto L_0x00a8323a;
    }
    // 00a83230  c705341fa900803aa800   -mov dword ptr [0xa91f34], 0xa83a80
    *app->getMemory<x86::reg32>(x86::reg32(11083572) /* 0xa91f34 */) = 11025024 /*0xa83a80*/;
L_0x00a8323a:
    // 00a8323a  680412a900             -push 0xa91204
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080196 /*0xa91204*/;
    cpu.esp -= 4;
    // 00a8323f  2eff15ec03a900         -call dword ptr cs:[0xa903ec]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076588) /* 0xa903ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83246  a3501fa900             -mov dword ptr [0xa91f50], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */) = cpu.eax;
    // 00a8324b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8324d  7507                   -jne 0xa83256
    if (!cpu.flags.zf)
    {
        goto L_0x00a83256;
    }
    // 00a8324f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a83251  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83252  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83253  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83254  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83255  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a83256:
    // 00a83256  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a83257  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a83258  681012a900             -push 0xa91210
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080208 /*0xa91210*/;
    cpu.esp -= 4;
    // 00a8325d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8325e  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83265  682012a900             -push 0xa91220
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080224 /*0xa91220*/;
    cpu.esp -= 4;
    // 00a8326a  8b1d501fa900           -mov ebx, dword ptr [0xa91f50]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83270  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a83271  a31436a900             -mov dword ptr [0xa93614], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089428) /* 0xa93614 */) = cpu.eax;
    // 00a83276  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8327d  683812a900             -push 0xa91238
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080248 /*0xa91238*/;
    cpu.esp -= 4;
    // 00a83282  8b35501fa900           -mov esi, dword ptr [0xa91f50]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83288  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a83289  a31836a900             -mov dword ptr [0xa93618], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089432) /* 0xa93618 */) = cpu.eax;
    // 00a8328e  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83295  684c12a900             -push 0xa9124c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080268 /*0xa9124c*/;
    cpu.esp -= 4;
    // 00a8329a  8b3d501fa900           -mov edi, dword ptr [0xa91f50]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a832a0  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a832a1  a31c36a900             -mov dword ptr [0xa9361c], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089436) /* 0xa9361c */) = cpu.eax;
    // 00a832a6  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a832ad  686012a900             -push 0xa91260
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080288 /*0xa91260*/;
    cpu.esp -= 4;
    // 00a832b2  8b2d501fa900           -mov ebp, dword ptr [0xa91f50]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a832b8  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a832b9  a32036a900             -mov dword ptr [0xa93620], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089440) /* 0xa93620 */) = cpu.eax;
    // 00a832be  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a832c5  687012a900             -push 0xa91270
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080304 /*0xa91270*/;
    cpu.esp -= 4;
    // 00a832ca  a32436a900             -mov dword ptr [0xa93624], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089444) /* 0xa93624 */) = cpu.eax;
    // 00a832cf  a1501fa900             -mov eax, dword ptr [0xa91f50]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a832d4  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a832d5  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a832dc  688412a900             -push 0xa91284
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080324 /*0xa91284*/;
    cpu.esp -= 4;
    // 00a832e1  8b15501fa900           -mov edx, dword ptr [0xa91f50]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a832e7  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a832e8  a32836a900             -mov dword ptr [0xa93628], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089448) /* 0xa93628 */) = cpu.eax;
    // 00a832ed  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a832f4  689812a900             -push 0xa91298
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080344 /*0xa91298*/;
    cpu.esp -= 4;
    // 00a832f9  8b0d501fa900           -mov ecx, dword ptr [0xa91f50]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a832ff  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a83300  a32c36a900             -mov dword ptr [0xa9362c], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089452) /* 0xa9362c */) = cpu.eax;
    // 00a83305  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8330c  68b012a900             -push 0xa912b0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080368 /*0xa912b0*/;
    cpu.esp -= 4;
    // 00a83311  8b1d501fa900           -mov ebx, dword ptr [0xa91f50]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83317  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a83318  a33036a900             -mov dword ptr [0xa93630], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089456) /* 0xa93630 */) = cpu.eax;
    // 00a8331d  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83324  68c412a900             -push 0xa912c4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080388 /*0xa912c4*/;
    cpu.esp -= 4;
    // 00a83329  8b35501fa900           -mov esi, dword ptr [0xa91f50]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a8332f  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a83330  a33436a900             -mov dword ptr [0xa93634], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089460) /* 0xa93634 */) = cpu.eax;
    // 00a83335  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8333c  68e412a900             -push 0xa912e4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080420 /*0xa912e4*/;
    cpu.esp -= 4;
    // 00a83341  8b3d501fa900           -mov edi, dword ptr [0xa91f50]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83347  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a83348  a33836a900             -mov dword ptr [0xa93638], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089464) /* 0xa93638 */) = cpu.eax;
    // 00a8334d  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83354  68fc12a900             -push 0xa912fc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080444 /*0xa912fc*/;
    cpu.esp -= 4;
    // 00a83359  8b2d501fa900           -mov ebp, dword ptr [0xa91f50]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a8335f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a83360  a33c36a900             -mov dword ptr [0xa9363c], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089468) /* 0xa9363c */) = cpu.eax;
    // 00a83365  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8336c  681013a900             -push 0xa91310
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080464 /*0xa91310*/;
    cpu.esp -= 4;
    // 00a83371  a34036a900             -mov dword ptr [0xa93640], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089472) /* 0xa93640 */) = cpu.eax;
    // 00a83376  a1501fa900             -mov eax, dword ptr [0xa91f50]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a8337b  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8337c  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83383  a34436a900             -mov dword ptr [0xa93644], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089476) /* 0xa93644 */) = cpu.eax;
    // 00a83388  682413a900             -push 0xa91324
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080484 /*0xa91324*/;
    cpu.esp -= 4;
    // 00a8338d  8b15501fa900           -mov edx, dword ptr [0xa91f50]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83393  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a83394  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8339b  683413a900             -push 0xa91334
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080500 /*0xa91334*/;
    cpu.esp -= 4;
    // 00a833a0  8b0d501fa900           -mov ecx, dword ptr [0xa91f50]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a833a6  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a833a7  a34836a900             -mov dword ptr [0xa93648], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089480) /* 0xa93648 */) = cpu.eax;
    // 00a833ac  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a833b3  684413a900             -push 0xa91344
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080516 /*0xa91344*/;
    cpu.esp -= 4;
    // 00a833b8  8b1d501fa900           -mov ebx, dword ptr [0xa91f50]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a833be  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a833bf  a34c36a900             -mov dword ptr [0xa9364c], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089484) /* 0xa9364c */) = cpu.eax;
    // 00a833c4  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a833cb  685813a900             -push 0xa91358
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080536 /*0xa91358*/;
    cpu.esp -= 4;
    // 00a833d0  8b35501fa900           -mov esi, dword ptr [0xa91f50]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a833d6  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a833d7  a35036a900             -mov dword ptr [0xa93650], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089488) /* 0xa93650 */) = cpu.eax;
    // 00a833dc  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a833e3  686813a900             -push 0xa91368
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080552 /*0xa91368*/;
    cpu.esp -= 4;
    // 00a833e8  8b3d501fa900           -mov edi, dword ptr [0xa91f50]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a833ee  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a833ef  a35436a900             -mov dword ptr [0xa93654], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089492) /* 0xa93654 */) = cpu.eax;
    // 00a833f4  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a833fb  687813a900             -push 0xa91378
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080568 /*0xa91378*/;
    cpu.esp -= 4;
    // 00a83400  8b2d501fa900           -mov ebp, dword ptr [0xa91f50]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83406  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a83407  a35836a900             -mov dword ptr [0xa93658], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089496) /* 0xa93658 */) = cpu.eax;
    // 00a8340c  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83413  688c13a900             -push 0xa9138c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080588 /*0xa9138c*/;
    cpu.esp -= 4;
    // 00a83418  a35c36a900             -mov dword ptr [0xa9365c], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089500) /* 0xa9365c */) = cpu.eax;
    // 00a8341d  a1501fa900             -mov eax, dword ptr [0xa91f50]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83422  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a83423  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8342a  68a013a900             -push 0xa913a0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080608 /*0xa913a0*/;
    cpu.esp -= 4;
    // 00a8342f  8b15501fa900           -mov edx, dword ptr [0xa91f50]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83435  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a83436  a36036a900             -mov dword ptr [0xa93660], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089504) /* 0xa93660 */) = cpu.eax;
    // 00a8343b  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83442  68b413a900             -push 0xa913b4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080628 /*0xa913b4*/;
    cpu.esp -= 4;
    // 00a83447  8b0d501fa900           -mov ecx, dword ptr [0xa91f50]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a8344d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8344e  a36436a900             -mov dword ptr [0xa93664], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089508) /* 0xa93664 */) = cpu.eax;
    // 00a83453  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8345a  68d013a900             -push 0xa913d0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080656 /*0xa913d0*/;
    cpu.esp -= 4;
    // 00a8345f  8b1d501fa900           -mov ebx, dword ptr [0xa91f50]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83465  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a83466  a36836a900             -mov dword ptr [0xa93668], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089512) /* 0xa93668 */) = cpu.eax;
    // 00a8346b  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83472  68e013a900             -push 0xa913e0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080672 /*0xa913e0*/;
    cpu.esp -= 4;
    // 00a83477  8b35501fa900           -mov esi, dword ptr [0xa91f50]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a8347d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8347e  a36c36a900             -mov dword ptr [0xa9366c], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089516) /* 0xa9366c */) = cpu.eax;
    // 00a83483  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8348a  68f413a900             -push 0xa913f4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080692 /*0xa913f4*/;
    cpu.esp -= 4;
    // 00a8348f  8b3d501fa900           -mov edi, dword ptr [0xa91f50]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83495  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a83496  a37036a900             -mov dword ptr [0xa93670], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089520) /* 0xa93670 */) = cpu.eax;
    // 00a8349b  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a834a2  680414a900             -push 0xa91404
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080708 /*0xa91404*/;
    cpu.esp -= 4;
    // 00a834a7  8b2d501fa900           -mov ebp, dword ptr [0xa91f50]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a834ad  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a834ae  a37436a900             -mov dword ptr [0xa93674], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089524) /* 0xa93674 */) = cpu.eax;
    // 00a834b3  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a834ba  a37836a900             -mov dword ptr [0xa93678], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089528) /* 0xa93678 */) = cpu.eax;
    // 00a834bf  681814a900             -push 0xa91418
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080728 /*0xa91418*/;
    cpu.esp -= 4;
    // 00a834c4  a1501fa900             -mov eax, dword ptr [0xa91f50]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a834c9  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a834ca  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a834d1  683014a900             -push 0xa91430
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080752 /*0xa91430*/;
    cpu.esp -= 4;
    // 00a834d6  8b15501fa900           -mov edx, dword ptr [0xa91f50]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a834dc  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a834dd  a37c36a900             -mov dword ptr [0xa9367c], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089532) /* 0xa9367c */) = cpu.eax;
    // 00a834e2  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a834e9  684814a900             -push 0xa91448
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080776 /*0xa91448*/;
    cpu.esp -= 4;
    // 00a834ee  8b0d501fa900           -mov ecx, dword ptr [0xa91f50]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a834f4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a834f5  a38036a900             -mov dword ptr [0xa93680], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089536) /* 0xa93680 */) = cpu.eax;
    // 00a834fa  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83501  686414a900             -push 0xa91464
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080804 /*0xa91464*/;
    cpu.esp -= 4;
    // 00a83506  8b1d501fa900           -mov ebx, dword ptr [0xa91f50]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a8350c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8350d  a38436a900             -mov dword ptr [0xa93684], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089540) /* 0xa93684 */) = cpu.eax;
    // 00a83512  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83519  687414a900             -push 0xa91474
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080820 /*0xa91474*/;
    cpu.esp -= 4;
    // 00a8351e  8b35501fa900           -mov esi, dword ptr [0xa91f50]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83524  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a83525  a38836a900             -mov dword ptr [0xa93688], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089544) /* 0xa93688 */) = cpu.eax;
    // 00a8352a  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83531  688814a900             -push 0xa91488
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080840 /*0xa91488*/;
    cpu.esp -= 4;
    // 00a83536  8b3d501fa900           -mov edi, dword ptr [0xa91f50]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a8353c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8353d  a38c36a900             -mov dword ptr [0xa9368c], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089548) /* 0xa9368c */) = cpu.eax;
    // 00a83542  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83549  689814a900             -push 0xa91498
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080856 /*0xa91498*/;
    cpu.esp -= 4;
    // 00a8354e  8b2d501fa900           -mov ebp, dword ptr [0xa91f50]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83554  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a83555  a39036a900             -mov dword ptr [0xa93690], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089552) /* 0xa93690 */) = cpu.eax;
    // 00a8355a  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83561  68a814a900             -push 0xa914a8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080872 /*0xa914a8*/;
    cpu.esp -= 4;
    // 00a83566  a39436a900             -mov dword ptr [0xa93694], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089556) /* 0xa93694 */) = cpu.eax;
    // 00a8356b  a1501fa900             -mov eax, dword ptr [0xa91f50]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83570  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a83571  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83578  68b814a900             -push 0xa914b8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080888 /*0xa914b8*/;
    cpu.esp -= 4;
    // 00a8357d  8b15501fa900           -mov edx, dword ptr [0xa91f50]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83583  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a83584  a39836a900             -mov dword ptr [0xa93698], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089560) /* 0xa93698 */) = cpu.eax;
    // 00a83589  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83590  68c814a900             -push 0xa914c8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080904 /*0xa914c8*/;
    cpu.esp -= 4;
    // 00a83595  8b0d501fa900           -mov ecx, dword ptr [0xa91f50]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a8359b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8359c  a39c36a900             -mov dword ptr [0xa9369c], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089564) /* 0xa9369c */) = cpu.eax;
    // 00a835a1  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a835a8  68e014a900             -push 0xa914e0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080928 /*0xa914e0*/;
    cpu.esp -= 4;
    // 00a835ad  8b1d501fa900           -mov ebx, dword ptr [0xa91f50]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a835b3  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a835b4  a3a036a900             -mov dword ptr [0xa936a0], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089568) /* 0xa936a0 */) = cpu.eax;
    // 00a835b9  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a835c0  68f414a900             -push 0xa914f4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080948 /*0xa914f4*/;
    cpu.esp -= 4;
    // 00a835c5  8b35501fa900           -mov esi, dword ptr [0xa91f50]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a835cb  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a835cc  a3a436a900             -mov dword ptr [0xa936a4], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089572) /* 0xa936a4 */) = cpu.eax;
    // 00a835d1  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a835d8  680815a900             -push 0xa91508
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080968 /*0xa91508*/;
    cpu.esp -= 4;
    // 00a835dd  8b3d501fa900           -mov edi, dword ptr [0xa91f50]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a835e3  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a835e4  a3a836a900             -mov dword ptr [0xa936a8], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089576) /* 0xa936a8 */) = cpu.eax;
    // 00a835e9  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a835f0  a3ac36a900             -mov dword ptr [0xa936ac], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089580) /* 0xa936ac */) = cpu.eax;
    // 00a835f5  681815a900             -push 0xa91518
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11080984 /*0xa91518*/;
    cpu.esp -= 4;
    // 00a835fa  8b2d501fa900           -mov ebp, dword ptr [0xa91f50]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83600  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a83601  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83608  682815a900             -push 0xa91528
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081000 /*0xa91528*/;
    cpu.esp -= 4;
    // 00a8360d  a3b036a900             -mov dword ptr [0xa936b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089584) /* 0xa936b0 */) = cpu.eax;
    // 00a83612  a1501fa900             -mov eax, dword ptr [0xa91f50]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83617  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a83618  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8361f  684415a900             -push 0xa91544
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081028 /*0xa91544*/;
    cpu.esp -= 4;
    // 00a83624  8b15501fa900           -mov edx, dword ptr [0xa91f50]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a8362a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8362b  a3b436a900             -mov dword ptr [0xa936b4], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089588) /* 0xa936b4 */) = cpu.eax;
    // 00a83630  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83637  685815a900             -push 0xa91558
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081048 /*0xa91558*/;
    cpu.esp -= 4;
    // 00a8363c  8b0d501fa900           -mov ecx, dword ptr [0xa91f50]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83642  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a83643  a3b836a900             -mov dword ptr [0xa936b8], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089592) /* 0xa936b8 */) = cpu.eax;
    // 00a83648  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8364f  686c15a900             -push 0xa9156c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081068 /*0xa9156c*/;
    cpu.esp -= 4;
    // 00a83654  8b1d501fa900           -mov ebx, dword ptr [0xa91f50]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a8365a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8365b  a3bc36a900             -mov dword ptr [0xa936bc], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089596) /* 0xa936bc */) = cpu.eax;
    // 00a83660  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83667  688015a900             -push 0xa91580
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081088 /*0xa91580*/;
    cpu.esp -= 4;
    // 00a8366c  8b35501fa900           -mov esi, dword ptr [0xa91f50]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83672  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a83673  a3c036a900             -mov dword ptr [0xa936c0], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089600) /* 0xa936c0 */) = cpu.eax;
    // 00a83678  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8367f  689c15a900             -push 0xa9159c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081116 /*0xa9159c*/;
    cpu.esp -= 4;
    // 00a83684  8b3d501fa900           -mov edi, dword ptr [0xa91f50]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a8368a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8368b  a3c436a900             -mov dword ptr [0xa936c4], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089604) /* 0xa936c4 */) = cpu.eax;
    // 00a83690  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83697  68b415a900             -push 0xa915b4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081140 /*0xa915b4*/;
    cpu.esp -= 4;
    // 00a8369c  8b2d501fa900           -mov ebp, dword ptr [0xa91f50]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a836a2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a836a3  a3c836a900             -mov dword ptr [0xa936c8], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089608) /* 0xa936c8 */) = cpu.eax;
    // 00a836a8  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a836af  68c815a900             -push 0xa915c8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081160 /*0xa915c8*/;
    cpu.esp -= 4;
    // 00a836b4  a3cc36a900             -mov dword ptr [0xa936cc], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089612) /* 0xa936cc */) = cpu.eax;
    // 00a836b9  a1501fa900             -mov eax, dword ptr [0xa91f50]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a836be  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a836bf  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a836c6  68dc15a900             -push 0xa915dc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081180 /*0xa915dc*/;
    cpu.esp -= 4;
    // 00a836cb  8b15501fa900           -mov edx, dword ptr [0xa91f50]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a836d1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a836d2  a3d036a900             -mov dword ptr [0xa936d0], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089616) /* 0xa936d0 */) = cpu.eax;
    // 00a836d7  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a836de  68ec15a900             -push 0xa915ec
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081196 /*0xa915ec*/;
    cpu.esp -= 4;
    // 00a836e3  8b0d501fa900           -mov ecx, dword ptr [0xa91f50]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a836e9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a836ea  a3d436a900             -mov dword ptr [0xa936d4], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089620) /* 0xa936d4 */) = cpu.eax;
    // 00a836ef  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a836f6  680016a900             -push 0xa91600
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081216 /*0xa91600*/;
    cpu.esp -= 4;
    // 00a836fb  8b1d501fa900           -mov ebx, dword ptr [0xa91f50]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83701  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a83702  a3d836a900             -mov dword ptr [0xa936d8], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089624) /* 0xa936d8 */) = cpu.eax;
    // 00a83707  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8370e  681816a900             -push 0xa91618
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081240 /*0xa91618*/;
    cpu.esp -= 4;
    // 00a83713  8b35501fa900           -mov esi, dword ptr [0xa91f50]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83719  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8371a  a3dc36a900             -mov dword ptr [0xa936dc], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089628) /* 0xa936dc */) = cpu.eax;
    // 00a8371f  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83726  a3e036a900             -mov dword ptr [0xa936e0], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089632) /* 0xa936e0 */) = cpu.eax;
    // 00a8372b  683016a900             -push 0xa91630
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081264 /*0xa91630*/;
    cpu.esp -= 4;
    // 00a83730  8b3d501fa900           -mov edi, dword ptr [0xa91f50]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83736  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a83737  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8373e  684016a900             -push 0xa91640
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081280 /*0xa91640*/;
    cpu.esp -= 4;
    // 00a83743  8b2d501fa900           -mov ebp, dword ptr [0xa91f50]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83749  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8374a  a3e436a900             -mov dword ptr [0xa936e4], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089636) /* 0xa936e4 */) = cpu.eax;
    // 00a8374f  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83756  684c16a900             -push 0xa9164c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081292 /*0xa9164c*/;
    cpu.esp -= 4;
    // 00a8375b  a3e836a900             -mov dword ptr [0xa936e8], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089640) /* 0xa936e8 */) = cpu.eax;
    // 00a83760  a1501fa900             -mov eax, dword ptr [0xa91f50]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83765  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a83766  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8376d  686416a900             -push 0xa91664
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081316 /*0xa91664*/;
    cpu.esp -= 4;
    // 00a83772  8b15501fa900           -mov edx, dword ptr [0xa91f50]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83778  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a83779  a3ec36a900             -mov dword ptr [0xa936ec], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089644) /* 0xa936ec */) = cpu.eax;
    // 00a8377e  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83785  687816a900             -push 0xa91678
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081336 /*0xa91678*/;
    cpu.esp -= 4;
    // 00a8378a  8b0d501fa900           -mov ecx, dword ptr [0xa91f50]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83790  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a83791  a3f036a900             -mov dword ptr [0xa936f0], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089648) /* 0xa936f0 */) = cpu.eax;
    // 00a83796  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8379d  689016a900             -push 0xa91690
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081360 /*0xa91690*/;
    cpu.esp -= 4;
    // 00a837a2  8b1d501fa900           -mov ebx, dword ptr [0xa91f50]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a837a8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a837a9  a3f436a900             -mov dword ptr [0xa936f4], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089652) /* 0xa936f4 */) = cpu.eax;
    // 00a837ae  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a837b5  68a816a900             -push 0xa916a8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081384 /*0xa916a8*/;
    cpu.esp -= 4;
    // 00a837ba  8b35501fa900           -mov esi, dword ptr [0xa91f50]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a837c0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a837c1  a3f836a900             -mov dword ptr [0xa936f8], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089656) /* 0xa936f8 */) = cpu.eax;
    // 00a837c6  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a837cd  a3fc36a900             -mov dword ptr [0xa936fc], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089660) /* 0xa936fc */) = cpu.eax;
    // 00a837d2  a1a836a900             -mov eax, dword ptr [0xa936a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11089576) /* 0xa936a8 */);
    // 00a837d7  a31037a900             -mov dword ptr [0xa93710], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089680) /* 0xa93710 */) = cpu.eax;
    // 00a837dc  a30c37a900             -mov dword ptr [0xa9370c], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089676) /* 0xa9370c */) = cpu.eax;
    // 00a837e1  a1ac36a900             -mov eax, dword ptr [0xa936ac]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11089580) /* 0xa936ac */);
    // 00a837e6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a837eb  a31036a900             -mov dword ptr [0xa93610], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089424) /* 0xa93610 */) = cpu.eax;
    // 00a837f0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a837f1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a837f2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a837f4  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a837f5  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a837f6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a837f7  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a837f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void sub_a83800(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a83800  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a83801  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a83802  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a83803  8b15501fa900           -mov edx, dword ptr [0xa91f50]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */);
    // 00a83809  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8380b  750c                   -jne 0xa83819
    if (!cpu.flags.zf)
    {
        goto L_0x00a83819;
    }
    // 00a8380d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8380f  891d501fa900           -mov dword ptr [0xa91f50], ebx
    *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */) = cpu.ebx;
    // 00a83815  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83816  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83817  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83818  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a83819:
    // 00a83819  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8381a  2eff159003a900         -call dword ptr cs:[0xa90390]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076496) /* 0xa90390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83821  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a83823  891d501fa900           -mov dword ptr [0xa91f50], ebx
    *app->getMemory<x86::reg32>(x86::reg32(11083600) /* 0xa91f50 */) = cpu.ebx;
    // 00a83829  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8382a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8382b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8382c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a83830(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a83830  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a83831  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a83834  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a83836  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00a83839  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a8383c  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp))));
    // 00a8383f  dc05bc16a900           -fadd qword ptr [0xa916bc]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<double>(x86::reg32(11081404) /* 0xa916bc */));
    // 00a83845  dd05c416a900           -fld qword ptr [0xa916c4]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(x86::reg32(11081412) /* 0xa916c4 */)));
    // 00a8384b  e852300000             -call 0xa868a2
    cpu.esp -= 4;
    sub_a868a2(app, cpu);
    if (cpu.terminate) return;
    // 00a83850  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a83852  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00a83857  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a8385a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8385c  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a8385f  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp))));
    // 00a83862  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a83864  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a83867  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83868  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void sub_a83870(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a83870  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a83871  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a83872  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a83873  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a83874  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a83877  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a83879  b83f000000             -mov eax, 0x3f
    cpu.eax = 63 /*0x3f*/;
    // 00a8387e  e8adffffff             -call 0xa83830
    cpu.esp -= 4;
    sub_a83830(app, cpu);
    if (cpu.terminate) return;
    // 00a83883  d84c2420               -fmul dword ptr [esp + 0x20]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 00a83887  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00a83889  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00a8388b  d9ea                   -fldl2e 
    cpu.fpu.push(1.4426950408889634);
    // 00a8388d  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 00a8388f  ddd2                   -fst st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    // 00a83891  d9f8                   -fprem 
    cpu.fpu.st(0) = cpu.fpu.rem(cpu.fpu.st(0), cpu.fpu.st(1));
    // 00a83893  d9f0                   -f2xm1 
    cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));
    // 00a83895  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a83897  d9fd                   -fscale 
    cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));
    // 00a83899  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8389b  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00a8389d  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00a8389f  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00a838a1  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00a838a3  bf0000803f             -mov edi, 0x3f800000
    cpu.edi = 1065353216 /*0x3f800000*/;
    // 00a838a8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a838aa  d95c2408               -fstp dword ptr [esp + 8]
    *app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a838ae:
    // 00a838ae  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a838b0  e87bffffff             -call 0xa83830
    cpu.esp -= 4;
    sub_a83830(app, cpu);
    if (cpu.terminate) return;
    // 00a838b5  d84c2420               -fmul dword ptr [esp + 0x20]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 00a838b9  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00a838bb  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00a838bd  d9ea                   -fldl2e 
    cpu.fpu.push(1.4426950408889634);
    // 00a838bf  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 00a838c1  ddd2                   -fst st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    // 00a838c3  d9f8                   -fprem 
    cpu.fpu.st(0) = cpu.fpu.rem(cpu.fpu.st(0), cpu.fpu.st(1));
    // 00a838c5  d9f0                   -f2xm1 
    cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));
    // 00a838c7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a838c9  d9fd                   -fscale 
    cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));
    // 00a838cb  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a838cd  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00a838cf  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00a838d1  d84c2408               -fmul dword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00a838d5  d95c2404               -fstp dword ptr [esp + 4]
    *app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a838d9  817c24040000803f       +cmp dword ptr [esp + 4], 0x3f800000
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1065353216 /*0x3f800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a838e1  7f3a                   -jg 0xa8391d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8391d;
    }
    // 00a838e3  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00a838e5  d85c2404               +fcomp dword ptr [esp + 4]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */));
    cpu.fpu.pop();
    // 00a838e9  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00a838eb  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a838ec  7606                   -jbe 0xa838f4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a838f4;
    }
    // 00a838ee  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a838f0  89742404               -mov dword ptr [esp + 4], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
L_0x00a838f4:
    // 00a838f4  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00a838f8  d80dcc16a900           -fmul dword ptr [0xa916cc]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11081420) /* 0xa916cc */));
    // 00a838fe  41                     -inc ecx
    (cpu.ecx)++;
    // 00a838ff  42                     -inc edx
    (cpu.edx)++;
    // 00a83900  d9542404               -fst dword ptr [esp + 4]
    *app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    // 00a83904  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a83907  db1c24                 -fistp dword ptr [esp]
    *app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00a8390a  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8390b  8841ff                 -mov byte ptr [ecx - 1], al
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00a8390e  83fa40                 +cmp edx, 0x40
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
    // 00a83911  7c9b                   -jl 0xa838ae
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a838ae;
    }
    // 00a83913  83c40c                 +add esp, 0xc
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
    // 00a83916  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83917  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83918  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83919  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8391a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a8391d:
    // 00a8391d  897c2404               -mov dword ptr [esp + 4], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00a83921  ebd1                   -jmp 0xa838f4
    goto L_0x00a838f4;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void sub_a83930(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a83930  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a83931  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a83932  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a83933  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a83935  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a83937  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a83939  6a04                   -push 4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00a8393b  ff156836a900           -call dword ptr [0xa93668]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089512) /* 0xa93668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83941  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a83943  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a83945  6a05                   -push 5
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00a83947  6a09                   -push 9
    *app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00a83949  6a05                   -push 5
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00a8394b  6a09                   -push 9
    *app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00a8394d  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8394f  ff15c036a900           -call dword ptr [0xa936c0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089600) /* 0xa936c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83955  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a83959  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8395a  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a8395e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8395f  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a83963  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a83964  ff150837a900           -call dword ptr [0xa93708]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089672) /* 0xa93708 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8396a  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8396c  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8396e  6a04                   -push 4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00a83970  6a04                   -push 4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00a83972  ff156836a900           -call dword ptr [0xa93668]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089512) /* 0xa93668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83978  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8397a  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8397c  6a0d                   -push 0xd
    *app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 00a8397e  6a09                   -push 9
    *app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00a83980  6a0d                   -push 0xd
    *app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 00a83982  6a09                   -push 9
    *app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00a83984  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a83986  8b742434               -mov esi, dword ptr [esp + 0x34]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a8398a  ff15c036a900           -call dword ptr [0xa936c0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089600) /* 0xa936c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83990  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a83991  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a83995  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a83996  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a83997  ff150837a900           -call dword ptr [0xa93708]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089672) /* 0xa93708 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8399d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8399e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8399f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a839a0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void sub_a839b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a839b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a839b1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a839b2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a839b3  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a839b5  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a839b7  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a839b9  6a04                   -push 4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00a839bb  ff156836a900           -call dword ptr [0xa93668]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089512) /* 0xa93668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a839c1  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a839c3  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a839c5  6a05                   -push 5
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00a839c7  6a09                   -push 9
    *app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00a839c9  6a05                   -push 5
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00a839cb  6a09                   -push 9
    *app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00a839cd  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a839cf  ff15c036a900           -call dword ptr [0xa936c0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089600) /* 0xa936c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a839d5  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a839d9  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a839da  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a839de  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a839df  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a839e3  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a839e4  ff150037a900           -call dword ptr [0xa93700]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089664) /* 0xa93700 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a839ea  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a839ec  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a839ee  6a04                   -push 4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00a839f0  6a04                   -push 4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00a839f2  ff156836a900           -call dword ptr [0xa93668]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089512) /* 0xa93668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a839f8  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a839fa  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a839fc  6a0d                   -push 0xd
    *app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 00a839fe  6a09                   -push 9
    *app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00a83a00  6a0d                   -push 0xd
    *app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 00a83a02  6a09                   -push 9
    *app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00a83a04  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a83a06  8b742434               -mov esi, dword ptr [esp + 0x34]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a83a0a  ff15c036a900           -call dword ptr [0xa936c0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089600) /* 0xa936c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83a10  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a83a11  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a83a15  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a83a16  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a83a17  ff150037a900           -call dword ptr [0xa93700]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089664) /* 0xa93700 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83a1d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83a1e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83a1f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83a20  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void sub_a83a30(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a83a30  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void sub_a83a40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a83a40  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a83a41  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a83a43  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a83a45  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a83a47  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a83a4b  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a83a4c  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a83a50  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a83a51  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a83a55  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a83a56  ff15e036a900           -call dword ptr [0xa936e0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089632) /* 0xa936e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83a5c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83a5d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void sub_a83a60(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a83a60  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a83a61  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a83a63  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a83a65  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a83a67  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a83a6b  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a83a6c  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a83a70  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a83a71  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a83a75  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a83a76  ff15e036a900           -call dword ptr [0xa936e0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089632) /* 0xa936e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83a7c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83a7d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void sub_a83a80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a83a80  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a83a84  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a83a85  68d016a900             -push 0xa916d0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11081424 /*0xa916d0*/;
    cpu.esp -= 4;
    // 00a83a8a  e8812f0000             -call 0xa86a10
    cpu.esp -= 4;
    sub_a86a10(app, cpu);
    if (cpu.terminate) return;
    // 00a83a8f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a83a92  b87a23a900             -mov eax, 0xa9237a
    cpu.eax = 11084666 /*0xa9237a*/;
    // 00a83a97  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a83a9b  e8a02f0000             -call 0xa86a40
    cpu.esp -= 4;
    sub_a86a40(app, cpu);
    if (cpu.terminate) return;
    // 00a83aa0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a83aa2  7403                   -je 0xa83aa7
    if (cpu.flags.zf)
    {
        goto L_0x00a83aa7;
    }
    // 00a83aa4  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a83aa7:
    // 00a83aa7  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00a83aac  e8a32f0000             -call 0xa86a54
    cpu.esp -= 4;
    sub_a86a54(app, cpu);
    if (cpu.terminate) return;
    // 00a83ab1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void sub_a83ac0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a83ac0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a83ac1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a83ac2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a83ac3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a83ac4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a83ac5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a83ac6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a83ac9  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a83acc  b94020a900             -mov ecx, 0xa92040
    cpu.ecx = 11083840 /*0xa92040*/;
    // 00a83ad1  8b1d1c37a900           -mov ebx, dword ptr [0xa9371c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11089692) /* 0xa9371c */);
    // 00a83ad7  8b151837a900           -mov edx, dword ptr [0xa93718]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11089688) /* 0xa93718 */);
    // 00a83add  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a83adf  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00a83ae2  83fa01                 +cmp edx, 1
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
    // 00a83ae5  0f8548010000           -jne 0xa83c33
    if (!cpu.flags.zf)
    {
        goto L_0x00a83c33;
    }
    // 00a83aeb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a83aed:
    // 00a83aed  a3f81ea900             -mov dword ptr [0xa91ef8], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083512) /* 0xa91ef8 */) = cpu.eax;
    // 00a83af2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a83af4  7506                   -jne 0xa83afc
    if (!cpu.flags.zf)
    {
        goto L_0x00a83afc;
    }
    // 00a83af6  8b2d2837a900           -mov ebp, dword ptr [0xa93728]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(11089704) /* 0xa93728 */);
L_0x00a83afc:
    // 00a83afc  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a83afe  0f8536010000           -jne 0xa83c3a
    if (!cpu.flags.zf)
    {
        goto L_0x00a83c3a;
    }
L_0x00a83b04:
    // 00a83b04  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x00a83b09:
    // 00a83b09  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a83b0c  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a83b0e  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00a83b11  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a83b14  c1ff03                 -sar edi, 3
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (3 /*0x3*/ % 32));
    // 00a83b17  0faff8                 -imul edi, eax
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00a83b1a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a83b1c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a83b1f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a83b21  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a83b23  894114                 -mov dword ptr [ecx + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00a83b26  8139c0030000           +cmp dword ptr [ecx], 0x3c0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(960 /*0x3c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a83b2c  7507                   -jne 0xa83b35
    if (!cpu.flags.zf)
    {
        goto L_0x00a83b35;
    }
    // 00a83b2e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a83b30  7503                   -jne 0xa83b35
    if (!cpu.flags.zf)
    {
        goto L_0x00a83b35;
    }
    // 00a83b32  896914                 -mov dword ptr [ecx + 0x14], ebp
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ebp;
L_0x00a83b35:
    // 00a83b35  813920030000           +cmp dword ptr [ecx], 0x320
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(800 /*0x320*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a83b3b  7e10                   -jle 0xa83b4d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a83b4d;
    }
    // 00a83b3d  833df81ea90000         +cmp dword ptr [0xa91ef8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11083512) /* 0xa91ef8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a83b44  7407                   -je 0xa83b4d
    if (cpu.flags.zf)
    {
        goto L_0x00a83b4d;
    }
    // 00a83b46  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x00a83b4d:
    // 00a83b4d  83791000               +cmp dword ptr [ecx + 0x10], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a83b51  0f84ea000000           -je 0xa83c41
    if (cpu.flags.zf)
    {
        goto L_0x00a83c41;
    }
    // 00a83b57  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00a83b5a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a83b5c  0f8edf000000           -jle 0xa83c41
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a83c41;
    }
    // 00a83b62  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00a83b65  8b7914                 -mov edi, dword ptr [ecx + 0x14]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00a83b68  894118                 -mov dword ptr [ecx + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00a83b6b  83ff03                 +cmp edi, 3
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a83b6e  7e07                   -jle 0xa83b77
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a83b77;
    }
    // 00a83b70  c7411403000000         -mov dword ptr [ecx + 0x14], 3
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 3 /*0x3*/;
L_0x00a83b77:
    // 00a83b77  83791803               +cmp dword ptr [ecx + 0x18], 3
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a83b7b  7e07                   -jle 0xa83b84
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a83b84;
    }
    // 00a83b7d  c7411803000000         -mov dword ptr [ecx + 0x18], 3
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 3 /*0x3*/;
L_0x00a83b84:
    // 00a83b84  46                     -inc esi
    (cpu.esi)++;
    // 00a83b85  83c128                 -add ecx, 0x28
    (cpu.ecx) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00a83b88  83fe10                 +cmp esi, 0x10
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
    // 00a83b8b  0f8e78ffffff           -jle 0xa83b09
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a83b09;
    }
    // 00a83b91  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a83b94  a11837a900             -mov eax, dword ptr [0xa93718]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11089688) /* 0xa93718 */);
    // 00a83b99  89416c                 -mov dword ptr [ecx + 0x6c], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 00a83b9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a83b9e  754c                   -jne 0xa83bec
    if (!cpu.flags.zf)
    {
        goto L_0x00a83bec;
    }
    // 00a83ba0  a12037a900             -mov eax, dword ptr [0xa93720]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11089696) /* 0xa93720 */);
    // 00a83ba5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a83ba7  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00a83baa  83f901                 +cmp ecx, 1
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
    // 00a83bad  750a                   -jne 0xa83bb9
    if (!cpu.flags.zf)
    {
        goto L_0x00a83bb9;
    }
    // 00a83baf  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a83bb2  c7416c02000000         -mov dword ptr [ecx + 0x6c], 2
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */) = 2 /*0x2*/;
L_0x00a83bb9:
    // 00a83bb9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a83bbb  c1f90c                 -sar ecx, 0xc
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (12 /*0xc*/ % 32));
    // 00a83bbe  83f901                 +cmp ecx, 1
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
    // 00a83bc1  750a                   -jne 0xa83bcd
    if (!cpu.flags.zf)
    {
        goto L_0x00a83bcd;
    }
    // 00a83bc3  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a83bc6  c7416c03000000         -mov dword ptr [ecx + 0x6c], 3
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */) = 3 /*0x3*/;
L_0x00a83bcd:
    // 00a83bcd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a83bcf  751b                   -jne 0xa83bec
    if (!cpu.flags.zf)
    {
        goto L_0x00a83bec;
    }
    // 00a83bd1  833d1c37a90006         +cmp dword ptr [0xa9371c], 6
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11089692) /* 0xa9371c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a83bd8  7c12                   -jl 0xa83bec
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a83bec;
    }
    // 00a83bda  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a83bdc  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a83bdf  891d101fa900           -mov dword ptr [0xa91f10], ebx
    *app->getMemory<x86::reg32>(x86::reg32(11083536) /* 0xa91f10 */) = cpu.ebx;
    // 00a83be5  c7406c03000000         -mov dword ptr [eax + 0x6c], 3
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = 3 /*0x3*/;
L_0x00a83bec:
    // 00a83bec  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a83bee  ff15d036a900           -call dword ptr [0xa936d0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089616) /* 0xa936d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83bf4  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a83bf6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a83bf8  ff15cc36a900           -call dword ptr [0xa936cc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089612) /* 0xa936cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83bfe  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a83c00  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a83c02  ff15cc36a900           -call dword ptr [0xa936cc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089612) /* 0xa936cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83c08  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a83c0a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a83c0d  895870                 -mov dword ptr [eax + 0x70], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = cpu.ebx;
    // 00a83c10  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a83c12  7e0b                   -jle 0xa83c1f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a83c1f;
    }
    // 00a83c14  8d430f                 -lea eax, [ebx + 0xf]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 00a83c17  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a83c1a  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00a83c1c  894170                 -mov dword ptr [ecx + 0x70], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */) = cpu.eax;
L_0x00a83c1f:
    // 00a83c1f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a83c22  c7407401000000         -mov dword ptr [eax + 0x74], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = 1 /*0x1*/;
    // 00a83c29  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a83c2c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83c2d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83c2e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83c2f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83c30  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83c31  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83c32  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a83c33:
    // 00a83c33  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a83c35  e9b3feffff             -jmp 0xa83aed
    goto L_0x00a83aed;
L_0x00a83c3a:
    // 00a83c3a  01db                   +add ebx, ebx
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
    // 00a83c3c  e9c3feffff             -jmp 0xa83b04
    goto L_0x00a83b04;
L_0x00a83c41:
    // 00a83c41  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00a83c48  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00a83c4b  894114                 -mov dword ptr [ecx + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00a83c4e  e931ffffff             -jmp 0xa83b84
    goto L_0x00a83b84;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void sub_a83c60(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a83c60  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a83c61  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a83c62  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a83c63  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a83c64  8b15541fa900           -mov edx, dword ptr [0xa91f54]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083604) /* 0xa91f54 */);
    // 00a83c6a  bd541fa900             -mov ebp, 0xa91f54
    cpu.ebp = 11083604 /*0xa91f54*/;
    // 00a83c6f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a83c71  7407                   -je 0xa83c7a
    if (cpu.flags.zf)
    {
        goto L_0x00a83c7a;
    }
L_0x00a83c73:
    // 00a83c73  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a83c75  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83c76  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83c77  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83c78  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83c79  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a83c7a:
    // 00a83c7a  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 00a83c7f  b958464433             -mov ecx, 0x33444658
    cpu.ecx = 860112472 /*0x33444658*/;
    // 00a83c84  be68000000             -mov esi, 0x68
    cpu.esi = 104 /*0x68*/;
    // 00a83c89  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a83c8b  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a83c90  e81b2e0000             -call 0xa86ab0
    cpu.esp -= 4;
    sub_a86ab0(app, cpu);
    if (cpu.terminate) return;
    // 00a83c95  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 00a83c9a  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 00a83c9f  890d541fa900           -mov dword ptr [0xa91f54], ecx
    *app->getMemory<x86::reg32>(x86::reg32(11083604) /* 0xa91f54 */) = cpu.ecx;
    // 00a83ca5  89355c1fa900           -mov dword ptr [0xa91f5c], esi
    *app->getMemory<x86::reg32>(x86::reg32(11083612) /* 0xa91f5c */) = cpu.esi;
    // 00a83cab  893d641fa900           -mov dword ptr [0xa91f64], edi
    *app->getMemory<x86::reg32>(x86::reg32(11083620) /* 0xa91f64 */) = cpu.edi;
    // 00a83cb1  893d6c1fa900           -mov dword ptr [0xa91f6c], edi
    *app->getMemory<x86::reg32>(x86::reg32(11083628) /* 0xa91f6c */) = cpu.edi;
    // 00a83cb7  893d701fa900           -mov dword ptr [0xa91f70], edi
    *app->getMemory<x86::reg32>(x86::reg32(11083632) /* 0xa91f70 */) = cpu.edi;
    // 00a83cbd  893d781fa900           -mov dword ptr [0xa91f78], edi
    *app->getMemory<x86::reg32>(x86::reg32(11083640) /* 0xa91f78 */) = cpu.edi;
    // 00a83cc3  893d7c1fa900           -mov dword ptr [0xa91f7c], edi
    *app->getMemory<x86::reg32>(x86::reg32(11083644) /* 0xa91f7c */) = cpu.edi;
    // 00a83cc9  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00a83cce  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 00a83cd3  bf1820a900             -mov edi, 0xa92018
    cpu.edi = 11083800 /*0xa92018*/;
    // 00a83cd8  891d581fa900           -mov dword ptr [0xa91f58], ebx
    *app->getMemory<x86::reg32>(x86::reg32(11083608) /* 0xa91f58 */) = cpu.ebx;
    // 00a83cde  a3681fa900             -mov dword ptr [0xa91f68], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083624) /* 0xa91f68 */) = cpu.eax;
    // 00a83ce3  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00a83ce8  8a25601fa900           -mov ah, byte ptr [0xa91f60]
    cpu.ah = *app->getMemory<x86::reg8>(x86::reg32(11083616) /* 0xa91f60 */);
    // 00a83cee  890d881fa900           -mov dword ptr [0xa91f88], ecx
    *app->getMemory<x86::reg32>(x86::reg32(11083656) /* 0xa91f88 */) = cpu.ecx;
    // 00a83cf4  8935901fa900           -mov dword ptr [0xa91f90], esi
    *app->getMemory<x86::reg32>(x86::reg32(11083664) /* 0xa91f90 */) = cpu.esi;
    // 00a83cfa  893d941fa900           -mov dword ptr [0xa91f94], edi
    *app->getMemory<x86::reg32>(x86::reg32(11083668) /* 0xa91f94 */) = cpu.edi;
    // 00a83d00  bed416a900             -mov esi, 0xa916d4
    cpu.esi = 11081428 /*0xa916d4*/;
    // 00a83d05  80cc0e                 -or ah, 0xe
    cpu.ah |= x86::reg8(x86::sreg8(14 /*0xe*/));
    // 00a83d08  891d741fa900           -mov dword ptr [0xa91f74], ebx
    *app->getMemory<x86::reg32>(x86::reg32(11083636) /* 0xa91f74 */) = cpu.ebx;
    // 00a83d0e  8d7d4c                 -lea edi, [ebp + 0x4c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(76) /* 0x4c */);
    // 00a83d11  bb0020a900             -mov ebx, 0xa92000
    cpu.ebx = 11083776 /*0xa92000*/;
    // 00a83d16  8825601fa900           -mov byte ptr [0xa91f60], ah
    *app->getMemory<x86::reg8>(x86::reg32(11083616) /* 0xa91f60 */) = cpu.ah;
    // 00a83d1c  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 00a83d1e  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a83d23  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a83d26  891d8c1fa900           -mov dword ptr [0xa91f8c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(11083660) /* 0xa91f8c */) = cpu.ebx;
    // 00a83d2c  8815601fa900           -mov byte ptr [0xa91f60], dl
    *app->getMemory<x86::reg8>(x86::reg32(11083616) /* 0xa91f60 */) = cpu.dl;
    // 00a83d32  bad41fa900             -mov edx, 0xa91fd4
    cpu.edx = 11083732 /*0xa91fd4*/;
    // 00a83d37  a3801fa900             -mov dword ptr [0xa91f80], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083648) /* 0xa91f80 */) = cpu.eax;
    // 00a83d3c  8915841fa900           -mov dword ptr [0xa91f84], edx
    *app->getMemory<x86::reg32>(x86::reg32(11083652) /* 0xa91f84 */) = cpu.edx;
    // 00a83d42  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00a83d43:
    // 00a83d43  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00a83d45  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00a83d47  3c00                   +cmp al, 0
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
    // 00a83d49  7410                   -je 0xa83d5b
    if (cpu.flags.zf)
    {
        goto L_0x00a83d5b;
    }
    // 00a83d4b  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a83d4e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a83d51  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a83d54  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a83d57  3c00                   +cmp al, 0
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
    // 00a83d59  75e8                   -jne 0xa83d43
    if (!cpu.flags.zf)
    {
        goto L_0x00a83d43;
    }
L_0x00a83d5b:
    // 00a83d5b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83d5c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a83d5e  8a35f41ea900           -mov dh, byte ptr [0xa91ef4]
    cpu.dh = *app->getMemory<x86::reg8>(x86::reg32(11083508) /* 0xa91ef4 */);
    // 00a83d64  a3c01fa900             -mov dword ptr [0xa91fc0], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083712) /* 0xa91fc0 */) = cpu.eax;
    // 00a83d69  f6c601                 +test dh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 1 /*0x1*/));
    // 00a83d6c  0f856d000000           -jne 0xa83ddf
    if (!cpu.flags.zf)
    {
        goto L_0x00a83ddf;
    }
    // 00a83d72  e8a9f4ffff             -call 0xa83220
    cpu.esp -= 4;
    sub_a83220(app, cpu);
    if (cpu.terminate) return;
    // 00a83d77  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a83d79  0f84f4feffff           -je 0xa83c73
    if (cpu.flags.zf)
    {
        goto L_0x00a83c73;
    }
    // 00a83d7f  833d1436a90000         +cmp dword ptr [0xa93614], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11089428) /* 0xa93614 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a83d86  744b                   -je 0xa83dd3
    if (cpu.flags.zf)
    {
        goto L_0x00a83dd3;
    }
    // 00a83d88  833d1c36a90000         +cmp dword ptr [0xa9361c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11089436) /* 0xa9361c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a83d8f  7442                   -je 0xa83dd3
    if (cpu.flags.zf)
    {
        goto L_0x00a83dd3;
    }
    // 00a83d91  833d1836a90000         +cmp dword ptr [0xa93618], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11089432) /* 0xa93618 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a83d98  7439                   -je 0xa83dd3
    if (cpu.flags.zf)
    {
        goto L_0x00a83dd3;
    }
    // 00a83d9a  681437a900             -push 0xa93714
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11089684 /*0xa93714*/;
    cpu.esp -= 4;
    // 00a83d9f  ff151c36a900           -call dword ptr [0xa9361c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089436) /* 0xa9361c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83da5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a83da7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a83da9  7406                   -je 0xa83db1
    if (cpu.flags.zf)
    {
        goto L_0x00a83db1;
    }
    // 00a83dab  8b3d1437a900           -mov edi, dword ptr [0xa93714]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(11089684) /* 0xa93714 */);
L_0x00a83db1:
    // 00a83db1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a83db3  7e1e                   -jle 0xa83dd3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a83dd3;
    }
    // 00a83db5  ff151436a900           -call dword ptr [0xa93614]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089428) /* 0xa93614 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83dbb  681437a900             -push 0xa93714
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11089684 /*0xa93714*/;
    cpu.esp -= 4;
    // 00a83dc0  ff151836a900           -call dword ptr [0xa93618]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089432) /* 0xa93618 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83dc6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a83dc8  e8f3fcffff             -call 0xa83ac0
    cpu.esp -= 4;
    sub_a83ac0(app, cpu);
    if (cpu.terminate) return;
    // 00a83dcd  ff152036a900           -call dword ptr [0xa93620]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089440) /* 0xa93620 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a83dd3:
    // 00a83dd3  e828faffff             -call 0xa83800
    cpu.esp -= 4;
    sub_a83800(app, cpu);
    if (cpu.terminate) return;
    // 00a83dd8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a83dda  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83ddb  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83ddc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83ddd  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83dde  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a83ddf:
    // 00a83ddf  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a83de1  e8dafcffff             -call 0xa83ac0
    cpu.esp -= 4;
    sub_a83ac0(app, cpu);
    if (cpu.terminate) return;
    // 00a83de6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a83de8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83de9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83dea  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83deb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83dec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a83df0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a83df0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a83df1  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00a83df4  b8e016a900             -mov eax, 0xa916e0
    cpu.eax = 11081440 /*0xa916e0*/;
    // 00a83df9  e8d22c0000             -call 0xa86ad0
    cpu.esp -= 4;
    sub_a86ad0(app, cpu);
    if (cpu.terminate) return;
    // 00a83dfe  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a83e00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a83e02  0f85cb000000           -jne 0xa83ed3
    if (!cpu.flags.zf)
    {
        goto L_0x00a83ed3;
    }
    // 00a83e08  e813f4ffff             -call 0xa83220
    cpu.esp -= 4;
    sub_a83220(app, cpu);
    if (cpu.terminate) return;
    // 00a83e0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a83e0f  0f84b7000000           -je 0xa83ecc
    if (cpu.flags.zf)
    {
        goto L_0x00a83ecc;
    }
    // 00a83e15  833d1436a90000         +cmp dword ptr [0xa93614], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11089428) /* 0xa93614 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a83e1c  0f84a5000000           -je 0xa83ec7
    if (cpu.flags.zf)
    {
        goto L_0x00a83ec7;
    }
    // 00a83e22  833d1c36a90000         +cmp dword ptr [0xa9361c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11089436) /* 0xa9361c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a83e29  0f8498000000           -je 0xa83ec7
    if (cpu.flags.zf)
    {
        goto L_0x00a83ec7;
    }
    // 00a83e2f  833d1836a90000         +cmp dword ptr [0xa93618], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11089432) /* 0xa93618 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a83e36  0f848b000000           -je 0xa83ec7
    if (cpu.flags.zf)
    {
        goto L_0x00a83ec7;
    }
    // 00a83e3c  681437a900             -push 0xa93714
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11089684 /*0xa93714*/;
    cpu.esp -= 4;
    // 00a83e41  ff151c36a900           -call dword ptr [0xa9361c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089436) /* 0xa9361c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83e47  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a83e49  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a83e4b  7406                   -je 0xa83e53
    if (cpu.flags.zf)
    {
        goto L_0x00a83e53;
    }
    // 00a83e4d  8b1d1437a900           -mov ebx, dword ptr [0xa93714]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11089684) /* 0xa93714 */);
L_0x00a83e53:
    // 00a83e53  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a83e55  0f8e6c000000           -jle 0xa83ec7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a83ec7;
    }
    // 00a83e5b  ff151436a900           -call dword ptr [0xa93614]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089428) /* 0xa93614 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83e61  681437a900             -push 0xa93714
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11089684 /*0xa93714*/;
    cpu.esp -= 4;
    // 00a83e66  ff151836a900           -call dword ptr [0xa93618]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089432) /* 0xa93618 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83e6c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a83e6e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a83e70  744f                   -je 0xa83ec1
    if (cpu.flags.zf)
    {
        goto L_0x00a83ec1;
    }
    // 00a83e72  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a83e74  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a83e75  ff15dc36a900           -call dword ptr [0xa936dc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089628) /* 0xa936dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83e7b  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esp);
    // 00a83e7e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a83e80  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00a83e82  7414                   -je 0xa83e98
    if (cpu.flags.zf)
    {
        goto L_0x00a83e98;
    }
L_0x00a83e84:
    // 00a83e84  8a1404                 -mov dl, byte ptr [esp + eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1);
    // 00a83e87  fec2                   -inc dl
    (cpu.dl)++;
    // 00a83e89  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a83e8f  f6827825a90020         +test byte ptr [edx + 0xa92578], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11085176) /* 0xa92578 */) & 32 /*0x20*/));
    // 00a83e96  7444                   -je 0xa83edc
    if (cpu.flags.zf)
    {
        goto L_0x00a83edc;
    }
L_0x00a83e98:
    // 00a83e98  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00a83e9a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a83e9c  baec16a900             -mov edx, 0xa916ec
    cpu.edx = 11081452 /*0xa916ec*/;
    // 00a83ea1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a83ea3  e8882c0000             -call 0xa86b30
    cpu.esp -= 4;
    sub_a86b30(app, cpu);
    if (cpu.terminate) return;
    // 00a83ea8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a83eaa  7c3b                   -jl 0xa83ee7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a83ee7;
    }
    // 00a83eac  baf416a900             -mov edx, 0xa916f4
    cpu.edx = 11081460 /*0xa916f4*/;
    // 00a83eb1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a83eb3  e8782c0000             -call 0xa86b30
    cpu.esp -= 4;
    sub_a86b30(app, cpu);
    if (cpu.terminate) return;
    // 00a83eb8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a83eba  7e2f                   -jle 0xa83eeb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a83eeb;
    }
    // 00a83ebc  bb5f000000             -mov ebx, 0x5f
    cpu.ebx = 95 /*0x5f*/;
L_0x00a83ec1:
    // 00a83ec1  ff152036a900           -call dword ptr [0xa93620]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089440) /* 0xa93620 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a83ec7:
    // 00a83ec7  e834f9ffff             -call 0xa83800
    cpu.esp -= 4;
    sub_a83800(app, cpu);
    if (cpu.terminate) return;
L_0x00a83ecc:
    // 00a83ecc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a83ece  83c450                 +add esp, 0x50
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a83ed1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83ed2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a83ed3:
    // 00a83ed3  e8082d0000             -call 0xa86be0
    cpu.esp -= 4;
    sub_a86be0(app, cpu);
    if (cpu.terminate) return;
    // 00a83ed8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a83eda  ebf0                   -jmp 0xa83ecc
    goto L_0x00a83ecc;
L_0x00a83edc:
    // 00a83edc  8a740401               -mov dh, byte ptr [esp + eax + 1]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 00a83ee0  40                     -inc eax
    (cpu.eax)++;
    // 00a83ee1  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00a83ee3  759f                   -jne 0xa83e84
    if (!cpu.flags.zf)
    {
        goto L_0x00a83e84;
    }
    // 00a83ee5  ebb1                   -jmp 0xa83e98
    goto L_0x00a83e98;
L_0x00a83ee7:
    // 00a83ee7  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a83ee9  ebd6                   -jmp 0xa83ec1
    goto L_0x00a83ec1;
L_0x00a83eeb:
    // 00a83eeb  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 00a83ef0  ff152036a900           -call dword ptr [0xa93620]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089440) /* 0xa93620 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83ef6  e805f9ffff             -call 0xa83800
    cpu.esp -= 4;
    sub_a83800(app, cpu);
    if (cpu.terminate) return;
    // 00a83efb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a83efd  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00a83f00  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83f01  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void sub_a83f10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a83f10  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a83f14  8b151437a900           -mov edx, dword ptr [0xa93714]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11089684) /* 0xa93714 */);
    // 00a83f1a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a83f1c  39d1                   +cmp ecx, edx
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
    // 00a83f1e  7c03                   -jl 0xa83f23
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a83f23;
    }
    // 00a83f20  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a83f23:
    // 00a83f23  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a83f24  ff152436a900           -call dword ptr [0xa93624]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089444) /* 0xa93624 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83f2a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a83f2f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void sub_a83f40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a83f40  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a83f41  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a83f42  e8b9010000             -call 0xa84100
    cpu.esp -= 4;
    sub_a84100(app, cpu);
    if (cpu.terminate) return;
    // 00a83f47  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83f48  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83f49  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void sub_a83f50(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a83f50  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a83f51  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a83f52  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a83f55  8a25f41ea900           -mov ah, byte ptr [0xa91ef4]
    cpu.ah = *app->getMemory<x86::reg8>(x86::reg32(11083508) /* 0xa91ef4 */);
    // 00a83f5b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a83f5d  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 00a83f60  7547                   -jne 0xa83fa9
    if (!cpu.flags.zf)
    {
        goto L_0x00a83fa9;
    }
    // 00a83f62  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a83f64  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a83f66:
    // 00a83f66  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a83f69  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a83f6c  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp))));
    // 00a83f6f  40                     -inc eax
    (cpu.eax)++;
    // 00a83f70  d99a0c32a900           -fstp dword ptr [edx + 0xa9320c]
    *app->getMemory<float>(cpu.edx + x86::reg32(11088396) /* 0xa9320c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a83f76  3d00010000             +cmp eax, 0x100
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
    // 00a83f7b  7ce9                   -jl 0xa83f66
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a83f66;
    }
    // 00a83f7d  833d341fa90000         +cmp dword ptr [0xa91f34], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11083572) /* 0xa91f34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a83f84  742b                   -je 0xa83fb1
    if (cpu.flags.zf)
    {
        goto L_0x00a83fb1;
    }
L_0x00a83f86:
    // 00a83f86  8b35401fa900           -mov esi, dword ptr [0xa91f40]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(11083584) /* 0xa91f40 */);
    // 00a83f8c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a83f8e  7510                   -jne 0xa83fa0
    if (!cpu.flags.zf)
    {
        goto L_0x00a83fa0;
    }
    // 00a83f90  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a83f91  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a83f92  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a83f93  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a83f94  2eff156803a900         -call dword ptr cs:[0xa90368]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076456) /* 0xa90368 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83f9b  a3401fa900             -mov dword ptr [0xa91f40], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083584) /* 0xa91f40 */) = cpu.eax;
L_0x00a83fa0:
    // 00a83fa0  e87bf2ffff             -call 0xa83220
    cpu.esp -= 4;
    sub_a83220(app, cpu);
    if (cpu.terminate) return;
    // 00a83fa5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a83fa7  7514                   -jne 0xa83fbd
    if (!cpu.flags.zf)
    {
        goto L_0x00a83fbd;
    }
L_0x00a83fa9:
    // 00a83fa9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a83fab  83c404                 +add esp, 4
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
    // 00a83fae  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83faf  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a83fb0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a83fb1:
    // 00a83fb1  c705341fa900803aa800   -mov dword ptr [0xa91f34], 0xa83a80
    *app->getMemory<x86::reg32>(x86::reg32(11083572) /* 0xa91f34 */) = 11025024 /*0xa83a80*/;
    // 00a83fbb  ebc9                   -jmp 0xa83f86
    goto L_0x00a83f86;
L_0x00a83fbd:
    // 00a83fbd  ff151436a900           -call dword ptr [0xa93614]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089428) /* 0xa93614 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83fc3  681437a900             -push 0xa93714
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11089684 /*0xa93714*/;
    cpu.esp -= 4;
    // 00a83fc8  ff151836a900           -call dword ptr [0xa93618]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089432) /* 0xa93618 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a83fce  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a83fd0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a83fd2  74d5                   -je 0xa83fa9
    if (cpu.flags.zf)
    {
        goto L_0x00a83fa9;
    }
    // 00a83fd4  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a83fd6  e835ffffff             -call 0xa83f10
    cpu.esp -= 4;
    sub_a83f10(app, cpu);
    if (cpu.terminate) return;
    // 00a83fdb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a83fdd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a83fdf  74c8                   -je 0xa83fa9
    if (cpu.flags.zf)
    {
        goto L_0x00a83fa9;
    }
    // 00a83fe1  b8541fa900             -mov eax, 0xa91f54
    cpu.eax = 11083604 /*0xa91f54*/;
    // 00a83fe6  8b1d1437a900           -mov ebx, dword ptr [0xa93714]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11089684) /* 0xa93714 */);
    // 00a83fec  e8cffaffff             -call 0xa83ac0
    cpu.esp -= 4;
    sub_a83ac0(app, cpu);
    if (cpu.terminate) return;
    // 00a83ff1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a83ff3  74b4                   -je 0xa83fa9
    if (cpu.flags.zf)
    {
        goto L_0x00a83fa9;
    }
    // 00a83ff5  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a83ff6  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a83ffb  b8403fa800             -mov eax, 0xa83f40
    cpu.eax = 11026240 /*0xa83f40*/;
    // 00a84000  893df41ea900           -mov dword ptr [0xa91ef4], edi
    *app->getMemory<x86::reg32>(x86::reg32(11083508) /* 0xa91ef4 */) = cpu.edi;
    // 00a84006  e8352c0000             -call 0xa86c40
    cpu.esp -= 4;
    sub_a86c40(app, cpu);
    if (cpu.terminate) return;
    // 00a8400b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8400c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8400e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a84011  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84012  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84013  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void sub_a84020(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a84020  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84021  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a84022  8b15481fa900           -mov edx, dword ptr [0xa91f48]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083592) /* 0xa91f48 */);
    // 00a84028  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8402a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8402c  7512                   -jne 0xa84040
    if (!cpu.flags.zf)
    {
        goto L_0x00a84040;
    }
    // 00a8402e  833df81ea90000         +cmp dword ptr [0xa91ef8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11083512) /* 0xa91ef8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a84035  7509                   -jne 0xa84040
    if (!cpu.flags.zf)
    {
        goto L_0x00a84040;
    }
    // 00a84037  833d101fa90000         +cmp dword ptr [0xa91f10], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11083536) /* 0xa91f10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8403e  7505                   -jne 0xa84045
    if (!cpu.flags.zf)
    {
        goto L_0x00a84045;
    }
L_0x00a84040:
    // 00a84040  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84042  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84043  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84044  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a84045:
    // 00a84045  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84046  68481fa900             -push 0xa91f48
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11083592 /*0xa91f48*/;
    cpu.esp -= 4;
    // 00a8404b  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8404c  e867bc0000             -call 0xa8fcb8
    cpu.esp -= 4;
    sub_a8fcb8(app, cpu);
    if (cpu.terminate) return;
    // 00a84051  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a84053  75eb                   -jne 0xa84040
    if (!cpu.flags.zf)
    {
        goto L_0x00a84040;
    }
    // 00a84055  833d441fa90000         +cmp dword ptr [0xa91f44], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11083588) /* 0xa91f44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8405c  7426                   -je 0xa84084
    if (cpu.flags.zf)
    {
        goto L_0x00a84084;
    }
    // 00a8405e  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
L_0x00a84063:
    // 00a84063  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a84064  8b2d081fa900           -mov ebp, dword ptr [0xa91f08]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(11083528) /* 0xa91f08 */);
    // 00a8406a  a1481fa900             -mov eax, dword ptr [0xa91f48]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083592) /* 0xa91f48 */);
    // 00a8406f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a84070  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a84072  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a84073  ff5150                 -call dword ptr [ecx + 0x50]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84076  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a84078  7511                   -jne 0xa8408b
    if (!cpu.flags.zf)
    {
        goto L_0x00a8408b;
    }
    // 00a8407a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a8407f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84081  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84082  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84083  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a84084:
    // 00a84084  ba11000000             -mov edx, 0x11
    cpu.edx = 17 /*0x11*/;
    // 00a84089  ebd8                   -jmp 0xa84063
    goto L_0x00a84063;
L_0x00a8408b:
    // 00a8408b  a1481fa900             -mov eax, dword ptr [0xa91f48]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083592) /* 0xa91f48 */);
    // 00a84090  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a84091  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a84093  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84096  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a84098  a3481fa900             -mov dword ptr [0xa91f48], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083592) /* 0xa91f48 */) = cpu.eax;
    // 00a8409d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8409f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a840a0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a840a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void sub_a840b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a840b0  8b15481fa900           -mov edx, dword ptr [0xa91f48]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083592) /* 0xa91f48 */);
    // 00a840b6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a840b8  7506                   -jne 0xa840c0
    if (!cpu.flags.zf)
    {
        goto L_0x00a840c0;
    }
    // 00a840ba  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a840bf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a840c0:
    // 00a840c0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a840c2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a840c3  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a840c5  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a840c8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a840ca  890d481fa900           -mov dword ptr [0xa91f48], ecx
    *app->getMemory<x86::reg32>(x86::reg32(11083592) /* 0xa91f48 */) = cpu.ecx;
    // 00a840d0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a840d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void sub_a840e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a840e0  f605f41ea90002         +test byte ptr [0xa91ef4], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(x86::reg32(11083508) /* 0xa91ef4 */) & 2 /*0x2*/));
    // 00a840e7  7501                   -jne 0xa840ea
    if (!cpu.flags.zf)
    {
        goto L_0x00a840ea;
    }
    // 00a840e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a840ea:
    // 00a840ea  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a840eb  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a840ec  ff152836a900           -call dword ptr [0xa93628]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089448) /* 0xa93628 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a840f2  8025f41ea900fd         -and byte ptr [0xa91ef4], 0xfd
    *app->getMemory<x86::reg8>(x86::reg32(11083508) /* 0xa91ef4 */) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 00a840f9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a840fa  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a840fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void sub_a84100(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a84100  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84101  8b15f41ea900           -mov edx, dword ptr [0xa91ef4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083508) /* 0xa91ef4 */);
    // 00a84107  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a8410c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8410e  7450                   -je 0xa84160
    if (cpu.flags.zf)
    {
        goto L_0x00a84160;
    }
    // 00a84110  f605f41ea90002         +test byte ptr [0xa91ef4], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(x86::reg32(11083508) /* 0xa91ef4 */) & 2 /*0x2*/));
    // 00a84117  754b                   -jne 0xa84164
    if (!cpu.flags.zf)
    {
        goto L_0x00a84164;
    }
L_0x00a84119:
    // 00a84119  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8411a  833d3c1fa90000         +cmp dword ptr [0xa91f3c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11083580) /* 0xa91f3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a84121  740a                   -je 0xa8412d
    if (cpu.flags.zf)
    {
        goto L_0x00a8412d;
    }
    // 00a84123  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a84124  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a84126  89353c1fa900           -mov dword ptr [0xa91f3c], esi
    *app->getMemory<x86::reg32>(x86::reg32(11083580) /* 0xa91f3c */) = cpu.esi;
    // 00a8412c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a8412d:
    // 00a8412d  8b3d401fa900           -mov edi, dword ptr [0xa91f40]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(11083584) /* 0xa91f40 */);
    // 00a84133  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a84135  740f                   -je 0xa84146
    if (cpu.flags.zf)
    {
        goto L_0x00a84146;
    }
    // 00a84137  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a84138  2eff156403a900         -call dword ptr cs:[0xa90364]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076452) /* 0xa90364 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8413f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a84141  a3401fa900             -mov dword ptr [0xa91f40], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083584) /* 0xa91f40 */) = cpu.eax;
L_0x00a84146:
    // 00a84146  ff152036a900           -call dword ptr [0xa93620]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089440) /* 0xa93620 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8414c  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8414e  e8adf6ffff             -call 0xa83800
    cpu.esp -= 4;
    sub_a83800(app, cpu);
    if (cpu.terminate) return;
    // 00a84153  8915341fa900           -mov dword ptr [0xa91f34], edx
    *app->getMemory<x86::reg32>(x86::reg32(11083572) /* 0xa91f34 */) = cpu.edx;
    // 00a84159  8915f41ea900           -mov dword ptr [0xa91ef4], edx
    *app->getMemory<x86::reg32>(x86::reg32(11083508) /* 0xa91ef4 */) = cpu.edx;
    // 00a8415f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a84160:
    // 00a84160  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84162  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84163  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a84164:
    // 00a84164  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84166  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84168  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8416a  e861020000             -call 0xa843d0
    cpu.esp -= 4;
    sub_a843d0(app, cpu);
    if (cpu.terminate) return;
    // 00a8416f  e83cffffff             -call 0xa840b0
    cpu.esp -= 4;
    sub_a840b0(app, cpu);
    if (cpu.terminate) return;
    // 00a84174  eba3                   -jmp 0xa84119
    goto L_0x00a84119;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void sub_a84180(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a84180  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84181  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a84182  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a84183  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a84184  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a84188  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a8418c  e84fffffff             -call 0xa840e0
    cpu.esp -= 4;
    sub_a840e0(app, cpu);
    if (cpu.terminate) return;
    // 00a84191  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a84193  0f8492010000           -je 0xa8432b
    if (cpu.flags.zf)
    {
        goto L_0x00a8432b;
    }
    // 00a84199  833df81ea90000         +cmp dword ptr [0xa91ef8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11083512) /* 0xa91ef8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a841a0  0f848e010000           -je 0xa84334
    if (cpu.flags.zf)
    {
        goto L_0x00a84334;
    }
    // 00a841a6  833d441fa90000         +cmp dword ptr [0xa91f44], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11083588) /* 0xa91f44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a841ad  0f8481010000           -je 0xa84334
    if (cpu.flags.zf)
    {
        goto L_0x00a84334;
    }
    // 00a841b3  bfff000000             -mov edi, 0xff
    cpu.edi = 255 /*0xff*/;
L_0x00a841b8:
    // 00a841b8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a841ba  7418                   -je 0xa841d4
    if (cpu.flags.zf)
    {
        goto L_0x00a841d4;
    }
    // 00a841bc  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a841c0  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00a841c7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a841c9  3b2cc53020a900         +cmp ebp, dword ptr [eax*8 + 0xa92030]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(11083824) /* 0xa92030 */ + cpu.eax * 8)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a841d0  7e02                   -jle 0xa841d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a841d4;
    }
    // 00a841d2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a841d4:
    // 00a841d4  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a841d5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a841d6  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a841d8  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a841da  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a841dc  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a841dd  a1081fa900             -mov eax, dword ptr [0xa91f08]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083528) /* 0xa91f08 */);
    // 00a841e2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a841e3  ff152c36a900           -call dword ptr [0xa9362c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089452) /* 0xa9362c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a841e9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a841eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a841ed  7528                   -jne 0xa84217
    if (!cpu.flags.zf)
    {
        goto L_0x00a84217;
    }
    // 00a841ef  81ffff000000           +cmp edi, 0xff
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a841f5  7520                   -jne 0xa84217
    if (!cpu.flags.zf)
    {
        goto L_0x00a84217;
    }
    // 00a841f7  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a841f8  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a841f9  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a841fa  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a841fb  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a841ff  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84200  8b0485e822a900         -mov eax, dword ptr [eax*4 + 0xa922e8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11084520) /* 0xa922e8 */ + cpu.eax * 4);
    // 00a84207  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a84208  8b15081fa900           -mov edx, dword ptr [0xa91f08]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083528) /* 0xa91f08 */);
    // 00a8420e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8420f  ff152c36a900           -call dword ptr [0xa9362c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089452) /* 0xa9362c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84215  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a84217:
    // 00a84217  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a84219  0f840c010000           -je 0xa8432b
    if (cpu.flags.zf)
    {
        goto L_0x00a8432b;
    }
    // 00a8421f  833df81ea90000         +cmp dword ptr [0xa91ef8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11083512) /* 0xa91ef8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a84226  0f8418010000           -je 0xa84344
    if (cpu.flags.zf)
    {
        goto L_0x00a84344;
    }
    // 00a8422c  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a84230  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00a84237  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a84239  8b14c51820a900         -mov edx, dword ptr [eax*8 + 0xa92018]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083800) /* 0xa92018 */ + cpu.eax * 8);
    // 00a84240  8b04c51c20a900         -mov eax, dword ptr [eax*8 + 0xa9201c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083804) /* 0xa9201c */ + cpu.eax * 8);
    // 00a84247  8915181fa900           -mov dword ptr [0xa91f18], edx
    *app->getMemory<x86::reg32>(x86::reg32(11083544) /* 0xa91f18 */) = cpu.edx;
L_0x00a8424d:
    // 00a8424d  a31c1fa900             -mov dword ptr [0xa91f1c], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083548) /* 0xa91f1c */) = cpu.eax;
    // 00a84252  e839040000             -call 0xa84690
    cpu.esp -= 4;
    sub_a84690(app, cpu);
    if (cpu.terminate) return;
    // 00a84257  6a10                   -push 0x10
    *app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00a84259  ff153836a900           -call dword ptr [0xa93638]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089464) /* 0xa93638 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8425f  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84261  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84263  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84265  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a84267  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84269  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a8426b  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8426d  ff15c036a900           -call dword ptr [0xa936c0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089600) /* 0xa936c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84273  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a84275  6a03                   -push 3
    *app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00a84277  ff15e836a900           -call dword ptr [0xa936e8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089640) /* 0xa936e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8427d  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8427f  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a84281  e80a070000             -call 0xa84990
    cpu.esp -= 4;
    sub_a84990(app, cpu);
    if (cpu.terminate) return;
    // 00a84286  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a84288  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a8428a  e801070000             -call 0xa84990
    cpu.esp -= 4;
    sub_a84990(app, cpu);
    if (cpu.terminate) return;
    // 00a8428f  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a84291  6a07                   -push 7
    *app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 00a84293  e8f8060000             -call 0xa84990
    cpu.esp -= 4;
    sub_a84990(app, cpu);
    if (cpu.terminate) return;
    // 00a84298  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a8429a  6a06                   -push 6
    *app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 00a8429c  e8ef060000             -call 0xa84990
    cpu.esp -= 4;
    sub_a84990(app, cpu);
    if (cpu.terminate) return;
    // 00a842a1  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a842a3  6a0a                   -push 0xa
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 00a842a5  e8e6060000             -call 0xa84990
    cpu.esp -= 4;
    sub_a84990(app, cpu);
    if (cpu.terminate) return;
    // 00a842aa  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a842ac  6a0b                   -push 0xb
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11 /*0xb*/;
    cpu.esp -= 4;
    // 00a842ae  e8dd060000             -call 0xa84990
    cpu.esp -= 4;
    sub_a84990(app, cpu);
    if (cpu.terminate) return;
    // 00a842b3  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a842b5  6a03                   -push 3
    *app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00a842b7  e8d4060000             -call 0xa84990
    cpu.esp -= 4;
    sub_a84990(app, cpu);
    if (cpu.terminate) return;
    // 00a842bc  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a842be  6a0c                   -push 0xc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 00a842c0  e8cb060000             -call 0xa84990
    cpu.esp -= 4;
    sub_a84990(app, cpu);
    if (cpu.terminate) return;
    // 00a842c5  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a842c7  6a05                   -push 5
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00a842c9  e8c2060000             -call 0xa84990
    cpu.esp -= 4;
    sub_a84990(app, cpu);
    if (cpu.terminate) return;
    // 00a842ce  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a842d0  6a0e                   -push 0xe
    *app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 00a842d2  e8b9060000             -call 0xa84990
    cpu.esp -= 4;
    sub_a84990(app, cpu);
    if (cpu.terminate) return;
    // 00a842d7  6aff                   -push -1
    *app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a842d9  6a0f                   -push 0xf
    *app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 00a842db  e8b0060000             -call 0xa84990
    cpu.esp -= 4;
    sub_a84990(app, cpu);
    if (cpu.terminate) return;
    // 00a842e0  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a842e2  6a68                   -push 0x68
    *app->getMemory<x86::reg32>(cpu.esp-4) = 104 /*0x68*/;
    cpu.esp -= 4;
    // 00a842e4  e8a7060000             -call 0xa84990
    cpu.esp -= 4;
    sub_a84990(app, cpu);
    if (cpu.terminate) return;
    // 00a842e9  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a842eb  6a0d                   -push 0xd
    *app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 00a842ed  e89e060000             -call 0xa84990
    cpu.esp -= 4;
    sub_a84990(app, cpu);
    if (cpu.terminate) return;
    // 00a842f2  ba0000803f             -mov edx, 0x3f800000
    cpu.edx = 1065353216 /*0x3f800000*/;
    // 00a842f7  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a842f8  6a65                   -push 0x65
    *app->getMemory<x86::reg32>(cpu.esp-4) = 101 /*0x65*/;
    cpu.esp -= 4;
    // 00a842fa  e891060000             -call 0xa84990
    cpu.esp -= 4;
    sub_a84990(app, cpu);
    if (cpu.terminate) return;
    // 00a842ff  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84301  6a18                   -push 0x18
    *app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 00a84303  e888060000             -call 0xa84990
    cpu.esp -= 4;
    sub_a84990(app, cpu);
    if (cpu.terminate) return;
    // 00a84308  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8430a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8430b  6a08                   -push 8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00a8430d  e87e060000             -call 0xa84990
    cpu.esp -= 4;
    sub_a84990(app, cpu);
    if (cpu.terminate) return;
    // 00a84312  83fe01                 +cmp esi, 1
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
    // 00a84315  7c43                   -jl 0xa8435a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8435a;
    }
    // 00a84317  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00a8431c:
    // 00a8431c  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8431d  6a04                   -push 4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00a8431f  e86c060000             -call 0xa84990
    cpu.esp -= 4;
    sub_a84990(app, cpu);
    if (cpu.terminate) return;
    // 00a84324  800df41ea90002         +or byte ptr [0xa91ef4], 2
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(x86::reg32(11083508) /* 0xa91ef4 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
L_0x00a8432b:
    // 00a8432b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8432d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8432e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8432f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84330  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84331  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a84334:
    // 00a84334  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a84338  8b3cbde822a900         -mov edi, dword ptr [edi*4 + 0xa922e8]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(11084520) /* 0xa922e8 */ + cpu.edi * 4);
    // 00a8433f  e974feffff             -jmp 0xa841b8
    goto L_0x00a841b8;
L_0x00a84344:
    // 00a84344  ff15f036a900           -call dword ptr [0xa936f0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089648) /* 0xa936f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8434a  a3181fa900             -mov dword ptr [0xa91f18], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083544) /* 0xa91f18 */) = cpu.eax;
    // 00a8434f  ff15f436a900           -call dword ptr [0xa936f4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089652) /* 0xa936f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84355  e9f3feffff             -jmp 0xa8424d
    goto L_0x00a8424d;
L_0x00a8435a:
    // 00a8435a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8435c  ebbe                   -jmp 0xa8431c
    goto L_0x00a8431c;
}

/* align: skip 0x8b 0xc0 */
void sub_a84360(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a84360  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84361  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a84362  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a84366  833d3423a90000         +cmp dword ptr [0xa92334], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11084596) /* 0xa92334 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8436d  750a                   -jne 0xa84379
    if (!cpu.flags.zf)
    {
        goto L_0x00a84379;
    }
L_0x00a8436f:
    // 00a8436f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a84374  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84375  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84376  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00a84379:
    // 00a84379  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8437b  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00a8437e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8437f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a84384  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a84385  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a84389  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8438a  e8f1fdffff             -call 0xa84180
    cpu.esp -= 4;
    sub_a84180(app, cpu);
    if (cpu.terminate) return;
    // 00a8438f  a3141fa900             -mov dword ptr [0xa91f14], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083540) /* 0xa91f14 */) = cpu.eax;
    // 00a84394  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a84396  7527                   -jne 0xa843bf
    if (!cpu.flags.zf)
    {
        goto L_0x00a843bf;
    }
    // 00a84398  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a8439d:
    // 00a8439d  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a843a1  8b35401fa900           -mov esi, dword ptr [0xa91f40]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(11083584) /* 0xa91f40 */);
    // 00a843a7  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a843a9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a843ab  74c2                   -je 0xa8436f
    if (cpu.flags.zf)
    {
        goto L_0x00a8436f;
    }
    // 00a843ad  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a843ae  2eff150404a900         -call dword ptr cs:[0xa90404]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076612) /* 0xa90404 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a843b5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a843ba  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a843bb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a843bc  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00a843bf:
    // 00a843bf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a843c1  ebda                   -jmp 0xa8439d
    goto L_0x00a8439d;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void sub_a843d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a843d0  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a843d1  833d301fa90000         +cmp dword ptr [0xa91f30], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11083568) /* 0xa91f30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a843d8  0f85a1000000           -jne 0xa8447f
    if (!cpu.flags.zf)
    {
        goto L_0x00a8447f;
    }
L_0x00a843de:
    // 00a843de  e83dfcffff             -call 0xa84020
    cpu.esp -= 4;
    sub_a84020(app, cpu);
    if (cpu.terminate) return;
    // 00a843e3  8b0d081fa900           -mov ecx, dword ptr [0xa91f08]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11083528) /* 0xa91f08 */);
    // 00a843e9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a843eb  7408                   -je 0xa843f5
    if (cpu.flags.zf)
    {
        goto L_0x00a843f5;
    }
    // 00a843ed  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a843ee  2eff155c03a900         -call dword ptr cs:[0xa9035c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076444) /* 0xa9035c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a843f5:
    // 00a843f5  833d3c1fa90000         +cmp dword ptr [0xa91f3c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11083580) /* 0xa91f3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a843fc  0f848d000000           -je 0xa8448f
    if (cpu.flags.zf)
    {
        goto L_0x00a8448f;
    }
    // 00a84402  833d081fa90000         +cmp dword ptr [0xa91f08], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11083528) /* 0xa91f08 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a84409  0f8480000000           -je 0xa8448f
    if (cpu.flags.zf)
    {
        goto L_0x00a8448f;
    }
    // 00a8440f  833d401fa90000         +cmp dword ptr [0xa91f40], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11083584) /* 0xa91f40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a84416  7477                   -je 0xa8448f
    if (cpu.flags.zf)
    {
        goto L_0x00a8448f;
    }
    // 00a84418  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a84419  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8441a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8441b  686043a800             -push 0xa84360
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11027296 /*0xa84360*/;
    cpu.esp -= 4;
    // 00a84420  6865040000             -push 0x465
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1125 /*0x465*/;
    cpu.esp -= 4;
    // 00a84425  ff153c1fa900           -call dword ptr [0xa91f3c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11083580) /* 0xa91f3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8442b  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a8442f  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a84433  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00a84436  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a84438  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a84439  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a8443d  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8443e  6865040000             -push 0x465
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1125 /*0x465*/;
    cpu.esp -= 4;
    // 00a84443  8b2d081fa900           -mov ebp, dword ptr [0xa91f08]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(11083528) /* 0xa91f08 */);
    // 00a84449  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a8444e  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8444f  891d3423a900           -mov dword ptr [0xa92334], ebx
    *app->getMemory<x86::reg32>(x86::reg32(11084596) /* 0xa92334 */) = cpu.ebx;
    // 00a84455  2eff155803a900         -call dword ptr cs:[0xa90358]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076440) /* 0xa90358 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8445c  6aff                   -push -1
    *app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a8445e  a1401fa900             -mov eax, dword ptr [0xa91f40]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083584) /* 0xa91f40 */);
    // 00a84463  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a84464  2eff153804a900         -call dword ptr cs:[0xa90438]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076664) /* 0xa90438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8446b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8446d  a1141fa900             -mov eax, dword ptr [0xa91f14]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083540) /* 0xa91f14 */);
    // 00a84472  89153423a900           -mov dword ptr [0xa92334], edx
    *app->getMemory<x86::reg32>(x86::reg32(11084596) /* 0xa92334 */) = cpu.edx;
    // 00a84478  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84479  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8447a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8447b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8447c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a8447f:
    // 00a8447f  ff15301fa900           -call dword ptr [0xa91f30]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11083568) /* 0xa91f30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84485  a3081fa900             -mov dword ptr [0xa91f08], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083528) /* 0xa91f08 */) = cpu.eax;
    // 00a8448a  e94fffffff             -jmp 0xa843de
    goto L_0x00a843de;
L_0x00a8448f:
    // 00a8448f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a84493  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a84494  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a84498  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a84499  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a8449d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8449e  e8ddfcffff             -call 0xa84180
    cpu.esp -= 4;
    sub_a84180(app, cpu);
    if (cpu.terminate) return;
    // 00a844a3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a844a4  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void sub_a844b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a844b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a844b1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a844b2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a844b3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a844b4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a844b7  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a844bb  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a844bf  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a844c0  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp))));
    // 00a844c3  d91c24                 -fstp dword ptr [esp]
    *app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a844c6  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a844c7  2d0000803f             -sub eax, 0x3f800000
    (cpu.eax) -= x86::reg32(x86::sreg32(1065353216 /*0x3f800000*/));
    // 00a844cc  c1f817                 -sar eax, 0x17
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (23 /*0x17*/ % 32));
    // 00a844cf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a844d1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a844d3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a844d5  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a844d7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a844d8  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp))));
    // 00a844db  d91c24                 -fstp dword ptr [esp]
    *app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a844de  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a844df  2d0000803f             -sub eax, 0x3f800000
    (cpu.eax) -= x86::reg32(x86::sreg32(1065353216 /*0x3f800000*/));
    // 00a844e4  c1f817                 -sar eax, 0x17
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (23 /*0x17*/ % 32));
    // 00a844e7  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a844e9  39c2                   +cmp edx, eax
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
    // 00a844eb  7e02                   -jle 0xa844ef
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a844ef;
    }
    // 00a844ed  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a844ef:
    // 00a844ef  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a844f3  0fb6b83823a900         -movzx edi, byte ptr [eax + 0xa92338]
    cpu.edi = x86::reg32(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11084600) /* 0xa92338 */));
    // 00a844fa  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a844fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a844fe  0f8cab000000           -jl 0xa845af
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a845af;
    }
L_0x00a84504:
    // 00a84504  8a803823a900           -mov al, byte ptr [eax + 0xa92338]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11084600) /* 0xa92338 */);
    // 00a8450a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8450f  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a84511  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a84515  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a84517  8a834423a900           -mov al, byte ptr [ebx + 0xa92344]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11084612) /* 0xa92344 */);
    // 00a8451d  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a84521  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a84525  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a84527  8a824823a900           -mov al, byte ptr [edx + 0xa92348]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11084616) /* 0xa92348 */);
    // 00a8452d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8452e  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a84532  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a84533  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a84534  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a84538  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84539  ff15c436a900           -call dword ptr [0xa936c4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089604) /* 0xa936c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8453f  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84541  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a84543  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a84545  ff15cc36a900           -call dword ptr [0xa936cc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089612) /* 0xa936cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8454b  8b15a837a900           -mov edx, dword ptr [0xa937a8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11089832) /* 0xa937a8 */);
    // 00a84551  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a84553  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a84555  250000e0ff             -and eax, 0xffe00000
    cpu.eax &= x86::reg32(x86::sreg32(4292870144 /*0xffe00000*/));
    // 00a8455a  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a8455d  031da837a900           -add ebx, dword ptr [0xa937a8]
    (cpu.ebx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(11089832) /* 0xa937a8 */)));
    // 00a84563  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84565  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a84566  ff15cc36a900           -call dword ptr [0xa936cc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089612) /* 0xa936cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8456c  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8456e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a84571  81e30000e0ff           -and ebx, 0xffe00000
    cpu.ebx &= x86::reg32(x86::sreg32(4292870144 /*0xffe00000*/));
    // 00a84577  39d3                   +cmp ebx, edx
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
    // 00a84579  740f                   -je 0xa8458a
    if (cpu.flags.zf)
    {
        goto L_0x00a8458a;
    }
    // 00a8457b  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8457d  ff15cc36a900           -call dword ptr [0xa936cc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089612) /* 0xa936cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84583  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a84585  a3a837a900             -mov dword ptr [0xa937a8], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089832) /* 0xa937a8 */) = cpu.eax;
L_0x00a8458a:
    // 00a8458a  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8458c  ff15d036a900           -call dword ptr [0xa936d0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089616) /* 0xa936d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84592  83c00f                 -add eax, 0xf
    (cpu.eax) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a84595  8b0da837a900           -mov ecx, dword ptr [0xa937a8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11089832) /* 0xa937a8 */);
    // 00a8459b  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00a8459d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8459f  39e8                   +cmp eax, ebp
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
    // 00a845a1  7d13                   -jge 0xa845b6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a845b6;
    }
L_0x00a845a3:
    // 00a845a3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a845a5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a845a8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a845a9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a845aa  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a845ab  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a845ac  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x00a845af:
    // 00a845af  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a845b1  e94effffff             -jmp 0xa84504
    goto L_0x00a84504;
L_0x00a845b6:
    // 00a845b6  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 00a845bb  e8f0260000             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a845c0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a845c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a845c4  74dd                   -je 0xa845a3
    if (cpu.flags.zf)
    {
        goto L_0x00a845a3;
    }
    // 00a845c6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a845ca  897804                 -mov dword ptr [eax + 4], edi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00a845cd  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a845cf  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a845d3  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a845d7  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a845da  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a845dc  8a934823a900           -mov dl, byte ptr [ebx + 0xa92348]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11084616) /* 0xa92348 */);
    // 00a845e2  c7401000000000         -mov dword ptr [eax + 0x10], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00a845e9  c7401803000000         -mov dword ptr [eax + 0x18], 3
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 3 /*0x3*/;
    // 00a845f0  8b1da837a900           -mov ebx, dword ptr [0xa937a8]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11089832) /* 0xa937a8 */);
    // 00a845f6  89500c                 -mov dword ptr [eax + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a845f9  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a845fb  8b15a837a900           -mov edx, dword ptr [0xa937a8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11089832) /* 0xa937a8 */);
    // 00a84601  891da837a900           -mov dword ptr [0xa937a8], ebx
    *app->getMemory<x86::reg32>(x86::reg32(11089832) /* 0xa937a8 */) = cpu.ebx;
    // 00a84607  895014                 -mov dword ptr [eax + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00a8460a  8b15281fa900           -mov edx, dword ptr [0xa91f28]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083560) /* 0xa91f28 */);
    // 00a84610  a3281fa900             -mov dword ptr [0xa91f28], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083560) /* 0xa91f28 */) = cpu.eax;
    // 00a84615  89501c                 -mov dword ptr [eax + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a84618  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8461a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a8461d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8461e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8461f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84620  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84621  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void sub_a84630(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a84630  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84631  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a84632  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a84636  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a8463a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8463c  750f                   -jne 0xa8464d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8464d;
    }
    // 00a8463e  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a84642  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a84644  752a                   -jne 0xa84670
    if (!cpu.flags.zf)
    {
        goto L_0x00a84670;
    }
    // 00a84646  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84648  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84649  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8464a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a8464d:
    // 00a8464d  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8464e  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00a84651  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a84652  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00a84655  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a84656  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84658  894310                 -mov dword ptr [ebx + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00a8465b  ff15c836a900           -call dword ptr [0xa936c8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089608) /* 0xa936c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84661  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a84665  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a84667  7507                   -jne 0xa84670
    if (!cpu.flags.zf)
    {
        goto L_0x00a84670;
    }
    // 00a84669  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8466b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8466c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8466d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a84670:
    // 00a84670  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a84671  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a84673  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84675  ff153c36a900           -call dword ptr [0xa9363c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089468) /* 0xa9363c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8467b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8467d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8467e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8467f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void sub_a84690(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a84690  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84692  ff15cc36a900           -call dword ptr [0xa936cc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089612) /* 0xa936cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84698  8b15281fa900           -mov edx, dword ptr [0xa91f28]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083560) /* 0xa91f28 */);
    // 00a8469e  a3a837a900             -mov dword ptr [0xa937a8], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089832) /* 0xa937a8 */) = cpu.eax;
    // 00a846a3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a846a5  7419                   -je 0xa846c0
    if (cpu.flags.zf)
    {
        goto L_0x00a846c0;
    }
L_0x00a846a7:
    // 00a846a7  a1281fa900             -mov eax, dword ptr [0xa91f28]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083560) /* 0xa91f28 */);
    // 00a846ac  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00a846af  e8ec260000             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a846b4  8915281fa900           -mov dword ptr [0xa91f28], edx
    *app->getMemory<x86::reg32>(x86::reg32(11083560) /* 0xa91f28 */) = cpu.edx;
    // 00a846ba  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a846bc  75e9                   -jne 0xa846a7
    if (!cpu.flags.zf)
    {
        goto L_0x00a846a7;
    }
    // 00a846be  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00a846c0:
    // 00a846c0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a846c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void sub_a846d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a846d0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a846d1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a846d2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a846d3  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a846d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a846d9  7514                   -jne 0xa846ef
    if (!cpu.flags.zf)
    {
        goto L_0x00a846ef;
    }
    // 00a846db  833d5423a90000         +cmp dword ptr [0xa92354], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11084628) /* 0xa92354 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a846e2  755c                   -jne 0xa84740
    if (!cpu.flags.zf)
    {
        goto L_0x00a84740;
    }
L_0x00a846e4:
    // 00a846e4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a846e9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a846ea  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a846eb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a846ec  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a846ef:
    // 00a846ef  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a846f0  8b7818                 -mov edi, dword ptr [eax + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00a846f3  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a846f4  8b6814                 -mov ebp, dword ptr [eax + 0x14]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00a846f7  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a846f8  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a846fa  ff15d436a900           -call dword ptr [0xa936d4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089620) /* 0xa936d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84700  833d5423a90001         +cmp dword ptr [0xa92354], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11084628) /* 0xa92354 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a84707  74db                   -je 0xa846e4
    if (cpu.flags.zf)
    {
        goto L_0x00a846e4;
    }
    // 00a84709  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8470b  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a8470d  8b152c1fa900           -mov edx, dword ptr [0xa91f2c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083564) /* 0xa91f2c */);
    // 00a84713  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a84714  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a84716  6a03                   -push 3
    *app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00a84718  ff156036a900           -call dword ptr [0xa93660]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089504) /* 0xa93660 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8471e  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84720  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a84722  8b0d2c1fa900           -mov ecx, dword ptr [0xa91f2c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11083564) /* 0xa91f2c */);
    // 00a84728  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a84729  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a8472b  6a03                   -push 3
    *app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00a8472d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84732  ff156436a900           -call dword ptr [0xa93664]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089508) /* 0xa93664 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84738  891d5423a900           -mov dword ptr [0xa92354], ebx
    *app->getMemory<x86::reg32>(x86::reg32(11084628) /* 0xa92354 */) = cpu.ebx;
    // 00a8473e  eba4                   -jmp 0xa846e4
    goto L_0x00a846e4;
L_0x00a84740:
    // 00a84740  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a84741  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a84742  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a84744  8b0d2c1fa900           -mov ecx, dword ptr [0xa91f2c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11083564) /* 0xa91f2c */);
    // 00a8474a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8474b  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8474c  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a8474e  ff156036a900           -call dword ptr [0xa93660]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089504) /* 0xa93660 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84754  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84756  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a84758  8b1d2c1fa900           -mov ebx, dword ptr [0xa91f2c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11083564) /* 0xa91f2c */);
    // 00a8475e  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8475f  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84761  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a84763  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a84765  ff156436a900           -call dword ptr [0xa93664]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089508) /* 0xa93664 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8476b  89355423a900           -mov dword ptr [0xa92354], esi
    *app->getMemory<x86::reg32>(x86::reg32(11084628) /* 0xa92354 */) = cpu.esi;
    // 00a84771  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84772  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a84777  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84778  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84779  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8477a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a84780(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a84780  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a84784  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a84786  7505                   -jne 0xa8478d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8478d;
    }
    // 00a84788  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a8478d:
    // 00a8478d  48                     -dec eax
    (cpu.eax)--;
    // 00a8478e  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8478f  a3041fa900             -mov dword ptr [0xa91f04], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083524) /* 0xa91f04 */) = cpu.eax;
    // 00a84794  ff154036a900           -call dword ptr [0xa93640]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089472) /* 0xa93640 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8479a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8479f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void sub_a847b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a847b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a847b2  66a1001fa900           -mov ax, word ptr [0xa91f00]
    cpu.ax = *app->getMemory<x86::reg16>(x86::reg32(11083520) /* 0xa91f00 */);
    // 00a847b8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a847b9  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a847bb  8b15fc1ea900           -mov edx, dword ptr [0xa91efc]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083516) /* 0xa91efc */);
    // 00a847c1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a847c2  ff154436a900           -call dword ptr [0xa93644]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089476) /* 0xa93644 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a847c8  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a847ce  8bd2                   -mov edx, edx
    cpu.edx = cpu.edx;
    // 00a847d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a847d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a847d0;
    // 00a847b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a847b2  66a1001fa900           -mov ax, word ptr [0xa91f00]
    cpu.ax = *app->getMemory<x86::reg16>(x86::reg32(11083520) /* 0xa91f00 */);
    // 00a847b8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a847b9  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a847bb  8b15fc1ea900           -mov edx, dword ptr [0xa91efc]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083516) /* 0xa91efc */);
    // 00a847c1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a847c2  ff154436a900           -call dword ptr [0xa93644]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089476) /* 0xa93644 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a847c8  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a847ce  8bd2                   -mov edx, edx
    cpu.edx = cpu.edx;
L_entry_0x00a847d0:
    // 00a847d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void sub_a847e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a847e0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a847e1  bb00093d00             -mov ebx, 0x3d0900
    cpu.ebx = 4000000 /*0x3d0900*/;
L_0x00a847e6:
    // 00a847e6  ff15f836a900           -call dword ptr [0xa936f8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089656) /* 0xa936f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a847ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a847ee  7403                   -je 0xa847f3
    if (cpu.flags.zf)
    {
        goto L_0x00a847f3;
    }
    // 00a847f0  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a847f1  75f3                   -jne 0xa847e6
    if (!cpu.flags.zf)
    {
        goto L_0x00a847e6;
    }
L_0x00a847f3:
    // 00a847f3  8b150c1fa900           -mov edx, dword ptr [0xa91f0c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083532) /* 0xa91f0c */);
    // 00a847f9  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a847fa  ff154836a900           -call dword ptr [0xa93648]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089480) /* 0xa93648 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84800  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84801  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a84807  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 00a8480d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a84810  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a84810(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a84810;
    // 00a847e0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a847e1  bb00093d00             -mov ebx, 0x3d0900
    cpu.ebx = 4000000 /*0x3d0900*/;
L_0x00a847e6:
    // 00a847e6  ff15f836a900           -call dword ptr [0xa936f8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089656) /* 0xa936f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a847ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a847ee  7403                   -je 0xa847f3
    if (cpu.flags.zf)
    {
        goto L_0x00a847f3;
    }
    // 00a847f0  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a847f1  75f3                   -jne 0xa847e6
    if (!cpu.flags.zf)
    {
        goto L_0x00a847e6;
    }
L_0x00a847f3:
    // 00a847f3  8b150c1fa900           -mov edx, dword ptr [0xa91f0c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083532) /* 0xa91f0c */);
    // 00a847f9  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a847fa  ff154836a900           -call dword ptr [0xa93648]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089480) /* 0xa93648 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84800  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84801  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a84807  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 00a8480d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00a84810:
    // 00a84810  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void sub_a84830(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a84830  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84831  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a84835  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a84837  83f803                 +cmp eax, 3
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
    // 00a8483a  770d                   -ja 0xa84849
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a84849;
    }
    // 00a8483c  ff24851448a800         -jmp dword ptr [eax*4 + 0xa84814]
    cpu.ip = *app->getMemory<x86::reg32>(11028500 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a84843:
    // 00a84843  ff155436a900           -call dword ptr [0xa93654]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089492) /* 0xa93654 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a84849:
    // 00a84849  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8484b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8484c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x00a8484f:
    // 00a8484f  ff155836a900           -call dword ptr [0xa93658]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089496) /* 0xa93658 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84855  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a84857  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84859  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8485a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x00a8485d:
    // 00a8485d  bb00093d00             -mov ebx, 0x3d0900
    cpu.ebx = 4000000 /*0x3d0900*/;
L_0x00a84862:
    // 00a84862  ff155036a900           -call dword ptr [0xa93650]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089488) /* 0xa93650 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84868  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8486a  7515                   -jne 0xa84881
    if (!cpu.flags.zf)
    {
        goto L_0x00a84881;
    }
L_0x00a8486c:
    // 00a8486c  ff155036a900           -call dword ptr [0xa93650]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089488) /* 0xa93650 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84872  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a84874  7503                   -jne 0xa84879
    if (!cpu.flags.zf)
    {
        goto L_0x00a84879;
    }
    // 00a84876  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a84877  75f3                   -jne 0xa8486c
    if (!cpu.flags.zf)
    {
        goto L_0x00a8486c;
    }
L_0x00a84879:
    // 00a84879  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a8487b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8487d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8487e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a84881:
    // 00a84881  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a84882  75de                   -jne 0xa84862
    if (!cpu.flags.zf)
    {
        goto L_0x00a84862;
    }
    // 00a84884  ebe6                   -jmp 0xa8486c
    goto L_0x00a8486c;
  case 0x00a84886:
    // 00a84886  ff154c36a900           -call dword ptr [0xa9364c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089484) /* 0xa9364c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8488c  c1e80c                 -shr eax, 0xc
    cpu.eax >>= 12 /*0xc*/ % 32;
    // 00a8488f  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 00a84894  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a84899  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8489b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8489d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8489e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void sub_a848b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a848b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a848b1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a848b2  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a848b6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a848b7  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a848bb  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a848bc  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a848c0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a848c1  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a848c5  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a848c6  ff155c36a900           -call dword ptr [0xa9365c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089500) /* 0xa9365c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a848cc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a848d1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a848d2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a848d3  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void sub_a848e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a848e0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a848e1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a848e2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a848e3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a848e5  744d                   -je 0xa84934
    if (cpu.flags.zf)
    {
        goto L_0x00a84934;
    }
    // 00a848e7  b9603aa800             -mov ecx, 0xa83a60
    cpu.ecx = 11024992 /*0xa83a60*/;
    // 00a848ec  be403aa800             -mov esi, 0xa83a40
    cpu.esi = 11024960 /*0xa83a40*/;
    // 00a848f1  8b1de436a900           -mov ebx, dword ptr [0xa936e4]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11089636) /* 0xa936e4 */);
L_0x00a848f7:
    // 00a848f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a848f9  7449                   -je 0xa84944
    if (cpu.flags.zf)
    {
        goto L_0x00a84944;
    }
    // 00a848fb  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a848fc  ba3039a800             -mov edx, 0xa83930
    cpu.edx = 11024688 /*0xa83930*/;
    // 00a84901  bfb039a800             -mov edi, 0xa839b0
    cpu.edi = 11024816 /*0xa839b0*/;
    // 00a84906  89151037a900           -mov dword ptr [0xa93710], edx
    *app->getMemory<x86::reg32>(x86::reg32(11089680) /* 0xa93710 */) = cpu.edx;
    // 00a8490c  893d0c37a900           -mov dword ptr [0xa9370c], edi
    *app->getMemory<x86::reg32>(x86::reg32(11089676) /* 0xa9370c */) = cpu.edi;
    // 00a84912  ba303aa800             -mov edx, 0xa83a30
    cpu.edx = 11024944 /*0xa83a30*/;
    // 00a84917  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a84918:
    // 00a84918  89151036a900           -mov dword ptr [0xa93610], edx
    *app->getMemory<x86::reg32>(x86::reg32(11089424) /* 0xa93610 */) = cpu.edx;
    // 00a8491e  89350837a900           -mov dword ptr [0xa93708], esi
    *app->getMemory<x86::reg32>(x86::reg32(11089672) /* 0xa93708 */) = cpu.esi;
    // 00a84924  891d0437a900           -mov dword ptr [0xa93704], ebx
    *app->getMemory<x86::reg32>(x86::reg32(11089668) /* 0xa93704 */) = cpu.ebx;
    // 00a8492a  890d0037a900           -mov dword ptr [0xa93700], ecx
    *app->getMemory<x86::reg32>(x86::reg32(11089664) /* 0xa93700 */) = cpu.ecx;
    // 00a84930  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84931  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84932  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84933  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a84934:
    // 00a84934  8b35a836a900           -mov esi, dword ptr [0xa936a8]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(11089576) /* 0xa936a8 */);
    // 00a8493a  8b1dac36a900           -mov ebx, dword ptr [0xa936ac]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11089580) /* 0xa936ac */);
    // 00a84940  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a84942  ebb3                   -jmp 0xa848f7
    goto L_0x00a848f7;
L_0x00a84944:
    // 00a84944  89351037a900           -mov dword ptr [0xa93710], esi
    *app->getMemory<x86::reg32>(x86::reg32(11089680) /* 0xa93710 */) = cpu.esi;
    // 00a8494a  890d0c37a900           -mov dword ptr [0xa9370c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(11089676) /* 0xa9370c */) = cpu.ecx;
    // 00a84950  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a84952  ebc4                   -jmp 0xa84918
    goto L_0x00a84918;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void sub_a84990(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a84990  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84991  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a84992  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a84993  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a84994  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a84996  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00a84999  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00a8499c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8499e  83f812                 +cmp eax, 0x12
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a849a1  7331                   -jae 0xa849d4
    if (!cpu.flags.cf)
    {
        goto L_0x00a849d4;
    }
    // 00a849a3  83f808                 +cmp eax, 8
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
    // 00a849a6  0f83c4010000           -jae 0xa84b70
    if (!cpu.flags.cf)
    {
        goto L_0x00a84b70;
    }
    // 00a849ac  83f804                 +cmp eax, 4
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
    // 00a849af  0f83bc020000           -jae 0xa84c71
    if (!cpu.flags.cf)
    {
        goto L_0x00a84c71;
    }
    // 00a849b5  83f802                 +cmp eax, 2
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
    // 00a849b8  0f835d030000           -jae 0xa84d1b
    if (!cpu.flags.cf)
    {
        goto L_0x00a84d1b;
    }
    // 00a849be  83f801                 +cmp eax, 1
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
    // 00a849c1  0f849b030000           -je 0xa84d62
    if (cpu.flags.zf)
    {
        goto L_0x00a84d62;
    }
L_0x00a849c7:
    // 00a849c7  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
  [[fallthrough]];
  case 0x00a849c9:
L_0x00a849c9:
    // 00a849c9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a849cb  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a849cd  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a849ce  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a849cf  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a849d0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a849d1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a849d4:
    // 00a849d4  0f86c4060000           -jbe 0xa8509e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8509e;
    }
    // 00a849da  83f865                 +cmp eax, 0x65
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(101 /*0x65*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a849dd  734a                   -jae 0xa84a29
    if (!cpu.flags.cf)
    {
        goto L_0x00a84a29;
    }
    // 00a849df  83f819                 +cmp eax, 0x19
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a849e2  0f83fe000000           -jae 0xa84ae6
    if (!cpu.flags.cf)
    {
        goto L_0x00a84ae6;
    }
    // 00a849e8  83f815                 +cmp eax, 0x15
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(21 /*0x15*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a849eb  0f832b010000           -jae 0xa84b1c
    if (!cpu.flags.cf)
    {
        goto L_0x00a84b1c;
    }
    // 00a849f1  83f813                 +cmp eax, 0x13
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a849f4  75d1                   -jne 0xa849c7
    if (!cpu.flags.zf)
    {
        goto L_0x00a849c7;
    }
    // 00a849f6  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a849f9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a849fb  0f856d060000           -jne 0xa8506e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8506e;
    }
    // 00a84a01  891d3c1fa900           -mov dword ptr [0xa91f3c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(11083580) /* 0xa91f3c */) = cpu.ebx;
    // 00a84a07  891d341fa900           -mov dword ptr [0xa91f34], ebx
    *app->getMemory<x86::reg32>(x86::reg32(11083572) /* 0xa91f34 */) = cpu.ebx;
    // 00a84a0d  891d381fa900           -mov dword ptr [0xa91f38], ebx
    *app->getMemory<x86::reg32>(x86::reg32(11083576) /* 0xa91f38 */) = cpu.ebx;
    // 00a84a13  891d301fa900           -mov dword ptr [0xa91f30], ebx
    *app->getMemory<x86::reg32>(x86::reg32(11083568) /* 0xa91f30 */) = cpu.ebx;
    // 00a84a19  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84a1e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84a20  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84a22  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84a23  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84a24  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84a25  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84a26  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84a29:
    // 00a84a29  0f8658050000           -jbe 0xa84f87
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a84f87;
    }
    // 00a84a2f  83f869                 +cmp eax, 0x69
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(105 /*0x69*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a84a32  733f                   -jae 0xa84a73
    if (!cpu.flags.cf)
    {
        goto L_0x00a84a73;
    }
    // 00a84a34  83f867                 +cmp eax, 0x67
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(103 /*0x67*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a84a37  0f8216010000           -jb 0xa84b53
    if (cpu.flags.cf)
    {
        goto L_0x00a84b53;
    }
    // 00a84a3d  0f865d050000           -jbe 0xa84fa0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a84fa0;
    }
    // 00a84a43  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84a46  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84a4b  83f803                 +cmp eax, 3
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
    // 00a84a4e  0f8773ffffff           -ja 0xa849c7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a849c7;
    }
    // 00a84a54  ff24857849a800         -jmp dword ptr [eax*4 + 0xa84978]
    cpu.ip = *app->getMemory<x86::reg32>(11028856 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a84a5b:
    // 00a84a5b  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84a5d  6a04                   -push 4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00a84a5f  6a05                   -push 5
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00a84a61  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84a62  ff156836a900           -call dword ptr [0xa93668]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089512) /* 0xa93668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84a68  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84a6a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84a6c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84a6d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84a6e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84a6f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84a70  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84a73:
    // 00a84a73  772a                   -ja 0xa84a9f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a84a9f;
    }
    // 00a84a75  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84a78  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a84a7a  0f84e2040000           -je 0xa84f62
    if (cpu.flags.zf)
    {
        goto L_0x00a84f62;
    }
    // 00a84a80  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a84a82  ff159036a900           -call dword ptr [0xa93690]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089552) /* 0xa93690 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84a88  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a84a89  ff159436a900           -call dword ptr [0xa93694]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089556) /* 0xa93694 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84a8f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84a94  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84a96  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84a98  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84a99  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84a9a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84a9b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84a9c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84a9f:
    // 00a84a9f  83f86b                 +cmp eax, 0x6b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(107 /*0x6b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a84aa2  0f826e040000           -jb 0xa84f16
    if (cpu.flags.cf)
    {
        goto L_0x00a84f16;
    }
    // 00a84aa8  0f8622060000           -jbe 0xa850d0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a850d0;
    }
    // 00a84aae  83f86c                 +cmp eax, 0x6c
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
    // 00a84ab1  0f8510ffffff           -jne 0xa849c7
    if (!cpu.flags.zf)
    {
        goto L_0x00a849c7;
    }
    // 00a84ab7  833df81ea90000         +cmp dword ptr [0xa91ef8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11083512) /* 0xa91ef8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a84abe  0f8505ffffff           -jne 0xa849c9
    if (!cpu.flags.zf)
    {
        goto L_0x00a849c9;
    }
    // 00a84ac4  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84ac7  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84acc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a84ace  0f8561020000           -jne 0xa84d35
    if (!cpu.flags.zf)
    {
        goto L_0x00a84d35;
    }
    // 00a84ad4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84ad5  ff15fc36a900           -call dword ptr [0xa936fc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089660) /* 0xa936fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84adb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84add  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84adf  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84ae0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84ae1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84ae2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84ae3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84ae6:
    // 00a84ae6  0f8616050000           -jbe 0xa85002
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a85002;
    }
    // 00a84aec  83f81b                 +cmp eax, 0x1b
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
    // 00a84aef  0f8249050000           -jb 0xa8503e
    if (cpu.flags.cf)
    {
        goto L_0x00a8503e;
    }
    // 00a84af5  0f865b050000           -jbe 0xa85056
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a85056;
    }
    // 00a84afb  83f81c                 +cmp eax, 0x1c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a84afe  0f85c3feffff           -jne 0xa849c7
    if (!cpu.flags.zf)
    {
        goto L_0x00a849c7;
    }
    // 00a84b04  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84b07  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84b0c  a3381fa900             -mov dword ptr [0xa91f38], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083576) /* 0xa91f38 */) = cpu.eax;
    // 00a84b11  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84b13  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84b15  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84b16  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84b17  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84b18  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84b19  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84b1c:
    // 00a84b1c  772c                   -ja 0xa84b4a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a84b4a;
    }
    // 00a84b1e  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84b21  83fa08                 +cmp edx, 8
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
    // 00a84b24  0f879ffeffff           -ja 0xa849c9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a849c9;
    }
    // 00a84b2a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a84b2c  ff24855449a800         -jmp dword ptr [eax*4 + 0xa84954]
    cpu.ip = *app->getMemory<x86::reg32>(11028820 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a84b33:
L_0x00a84b33:
    // 00a84b33  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84b34  ff159036a900           -call dword ptr [0xa93690]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089552) /* 0xa93690 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84b3a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84b3f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84b41  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84b43  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84b44  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84b45  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84b46  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84b47  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84b4a:
    // 00a84b4a  83f818                 +cmp eax, 0x18
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
    // 00a84b4d  0f8574feffff           -jne 0xa849c7
    if (!cpu.flags.zf)
    {
        goto L_0x00a849c7;
    }
L_0x00a84b53:
    // 00a84b53  8b4516                 -mov eax, dword ptr [ebp + 0x16]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(22) /* 0x16 */);
    // 00a84b56  c1f810                 +sar eax, 0x10
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
    // 00a84b59  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a84b5a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84b5f  ff15b836a900           -call dword ptr [0xa936b8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089592) /* 0xa936b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84b65  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84b67  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84b69  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84b6a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84b6b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84b6c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84b6d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84b70:
    // 00a84b70  0f8640050000           -jbe 0xa850b6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a850b6;
    }
    // 00a84b76  83f80c                 +cmp eax, 0xc
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
    // 00a84b79  734b                   -jae 0xa84bc6
    if (!cpu.flags.cf)
    {
        goto L_0x00a84bc6;
    }
    // 00a84b7b  83f80a                 +cmp eax, 0xa
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
    // 00a84b7e  0f8296040000           -jb 0xa8501a
    if (cpu.flags.cf)
    {
        goto L_0x00a8501a;
    }
    // 00a84b84  0f874a020000           -ja 0xa84dd4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a84dd4;
    }
    // 00a84b8a  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84b8d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a84b8f  0f84b5020000           -je 0xa84e4a
    if (cpu.flags.zf)
    {
        goto L_0x00a84e4a;
    }
    // 00a84b95  83f801                 +cmp eax, 1
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
    // 00a84b98  0f84cb020000           -je 0xa84e69
    if (cpu.flags.zf)
    {
        goto L_0x00a84e69;
    }
    // 00a84b9e  83f802                 +cmp eax, 2
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
    // 00a84ba1  0f8522feffff           -jne 0xa849c9
    if (!cpu.flags.zf)
    {
        goto L_0x00a849c9;
    }
    // 00a84ba7  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84ba8  ff157836a900           -call dword ptr [0xa93678]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089528) /* 0xa93678 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84bae  6a04                   -push 4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00a84bb0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84bb5  ff157c36a900           -call dword ptr [0xa9367c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089532) /* 0xa9367c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84bbb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84bbd  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84bbf  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84bc0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84bc1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84bc2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84bc3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84bc6:
    // 00a84bc6  0f8664030000           -jbe 0xa84f30
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a84f30;
    }
    // 00a84bcc  83f80e                 +cmp eax, 0xe
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a84bcf  7339                   -jae 0xa84c0a
    if (!cpu.flags.cf)
    {
        goto L_0x00a84c0a;
    }
    // 00a84bd1  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a84bd5  0f859e030000           -jne 0xa84f79
    if (!cpu.flags.zf)
    {
        goto L_0x00a84f79;
    }
    // 00a84bdb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a84be0:
    // 00a84be0  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84be3  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a84be4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a84be6  0f8594030000           -jne 0xa84f80
    if (!cpu.flags.zf)
    {
        goto L_0x00a84f80;
    }
    // 00a84bec  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a84bf1:
    // 00a84bf1  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a84bf2  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84bf4  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84bf9  ff15d836a900           -call dword ptr [0xa936d8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089624) /* 0xa936d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84bff  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84c01  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84c03  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84c04  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84c05  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84c06  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84c07  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84c0a:
    // 00a84c0a  7742                   -ja 0xa84c4e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a84c4e;
    }
    // 00a84c0c  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a84c10  0f841dffffff           -je 0xa84b33
    if (cpu.flags.zf)
    {
        goto L_0x00a84b33;
    }
    // 00a84c16  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a84c18  ff159036a900           -call dword ptr [0xa93690]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089552) /* 0xa93690 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84c1e  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84c21  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00a84c24  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00a84c27  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00a84c29  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00a84c2b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a84c2e  8d45bc                 -lea eax, [ebp - 0x44]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 00a84c31  d91c24                 -fstp dword ptr [esp]
    *app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a84c34  e837ecffff             -call 0xa83870
    cpu.esp -= 4;
    sub_a83870(app, cpu);
    if (cpu.terminate) return;
    // 00a84c39  8d45bc                 -lea eax, [ebp - 0x44]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 00a84c3c  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a84c3d  ff159436a900           -call dword ptr [0xa93694]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089556) /* 0xa93694 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84c43  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84c45  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84c47  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84c48  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84c49  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84c4a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84c4b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84c4e:
    // 00a84c4e  83f80f                 +cmp eax, 0xf
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
    // 00a84c51  0f8570fdffff           -jne 0xa849c7
    if (!cpu.flags.zf)
    {
        goto L_0x00a849c7;
    }
    // 00a84c57  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84c5a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a84c5b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84c60  ff158c36a900           -call dword ptr [0xa9368c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089548) /* 0xa9368c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84c66  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84c68  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84c6a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84c6b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84c6c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84c6d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84c6e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84c71:
    // 00a84c71  7721                   -ja 0xa84c94
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a84c94;
    }
    // 00a84c73  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84c76  83f901                 +cmp ecx, 1
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
    // 00a84c79  0f8309020000           -jae 0xa84e88
    if (!cpu.flags.cf)
    {
        goto L_0x00a84e88;
    }
    // 00a84c7f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a84c81  0f843e020000           -je 0xa84ec5
    if (cpu.flags.zf)
    {
        goto L_0x00a84ec5;
    }
    // 00a84c87  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a84c89  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84c8b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84c8d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84c8e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84c8f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84c90  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84c91  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84c94:
    // 00a84c94  83f806                 +cmp eax, 6
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
    // 00a84c97  7326                   -jae 0xa84cbf
    if (!cpu.flags.cf)
    {
        goto L_0x00a84cbf;
    }
    // 00a84c99  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a84c9d  0f84f2000000           -je 0xa84d95
    if (cpu.flags.zf)
    {
        goto L_0x00a84d95;
    }
    // 00a84ca3  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00a84ca8:
    // 00a84ca8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a84ca9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84cae  ff157436a900           -call dword ptr [0xa93674]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089524) /* 0xa93674 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84cb4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84cb6  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84cb8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84cb9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84cba  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84cbb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84cbc  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84cbf:
    // 00a84cbf  0f87b3000000           -ja 0xa84d78
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a84d78;
    }
    // 00a84cc5  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a84cc9  0f84cd000000           -je 0xa84d9c
    if (cpu.flags.zf)
    {
        goto L_0x00a84d9c;
    }
    // 00a84ccf  891d2c1fa900           -mov dword ptr [0xa91f2c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(11083564) /* 0xa91f2c */) = cpu.ebx;
L_0x00a84cd5:
    // 00a84cd5  8b0d5423a900           -mov ecx, dword ptr [0xa92354]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11084628) /* 0xa92354 */);
    // 00a84cdb  83f901                 +cmp ecx, 1
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
    // 00a84cde  0f85c7000000           -jne 0xa84dab
    if (!cpu.flags.zf)
    {
        goto L_0x00a84dab;
    }
    // 00a84ce4  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84ce6  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a84ce7  8b3d2c1fa900           -mov edi, dword ptr [0xa91f2c]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(11083564) /* 0xa91f2c */);
    // 00a84ced  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a84cee  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a84cef  6a03                   -push 3
    *app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00a84cf1  ff156036a900           -call dword ptr [0xa93660]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089504) /* 0xa93660 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84cf7  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84cf9  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a84cfb  a12c1fa900             -mov eax, dword ptr [0xa91f2c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083564) /* 0xa91f2c */);
    // 00a84d00  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a84d01  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a84d03  6a03                   -push 3
    *app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
L_0x00a84d05:
    // 00a84d05  ff156436a900           -call dword ptr [0xa93664]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089508) /* 0xa93664 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84d0b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84d10  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84d12  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84d14  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d15  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d16  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d17  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d18  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84d1b:
    // 00a84d1b  762b                   -jbe 0xa84d48
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a84d48;
    }
    // 00a84d1d  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84d20  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84d25  a3fc1ea900             -mov dword ptr [0xa91efc], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083516) /* 0xa91efc */) = cpu.eax;
    // 00a84d2a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84d2c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84d2e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d2f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d30  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d31  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d32  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84d35:
    // 00a84d35  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a84d37  ff15fc36a900           -call dword ptr [0xa936fc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089660) /* 0xa936fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84d3d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84d3f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84d41  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d42  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d43  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d44  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d45  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84d48:
    // 00a84d48  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84d4b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a84d4c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84d51  ff156c36a900           -call dword ptr [0xa9366c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089516) /* 0xa9366c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84d57  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84d59  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84d5b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d5c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d5d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d5e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d5f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84d62:
    // 00a84d62  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84d65  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84d66  e865f9ffff             -call 0xa846d0
    cpu.esp -= 4;
    sub_a846d0(app, cpu);
    if (cpu.terminate) return;
    // 00a84d6b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a84d6d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84d6f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84d71  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d72  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d73  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d74  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d75  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84d78:
    // 00a84d78  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84d7b  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84d7c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84d7d  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84d7f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84d84  ff157036a900           -call dword ptr [0xa93670]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089520) /* 0xa93670 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84d8a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84d8c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84d8e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d8f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d90  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d91  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84d92  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84d95:
    // 00a84d95  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a84d97  e90cffffff             -jmp 0xa84ca8
    goto L_0x00a84ca8;
L_0x00a84d9c:
    // 00a84d9c  c7052c1fa90001000000   -mov dword ptr [0xa91f2c], 1
    *app->getMemory<x86::reg32>(x86::reg32(11083564) /* 0xa91f2c */) = 1 /*0x1*/;
    // 00a84da6  e92affffff             -jmp 0xa84cd5
    goto L_0x00a84cd5;
L_0x00a84dab:
    // 00a84dab  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84dad  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a84daf  8b1d2c1fa900           -mov ebx, dword ptr [0xa91f2c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11083564) /* 0xa91f2c */);
    // 00a84db5  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84db6  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84db8  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a84dba  ff156036a900           -call dword ptr [0xa93660]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089504) /* 0xa93660 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84dc0  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84dc2  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a84dc4  8b352c1fa900           -mov esi, dword ptr [0xa91f2c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(11083564) /* 0xa91f2c */);
    // 00a84dca  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a84dcb  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84dcd  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a84dcf  e931ffffff             -jmp 0xa84d05
    goto L_0x00a84d05;
L_0x00a84dd4:
    // 00a84dd4  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84dd7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a84dd9  83fa03                 +cmp edx, 3
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
    // 00a84ddc  750a                   -jne 0xa84de8
    if (!cpu.flags.zf)
    {
        goto L_0x00a84de8;
    }
    // 00a84dde  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00a84de3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a84de5  894d18                 -mov dword ptr [ebp + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x00a84de8:
    // 00a84de8  3b05241fa900           +cmp eax, dword ptr [0xa91f24]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(11083556) /* 0xa91f24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a84dee  7427                   -je 0xa84e17
    if (cpu.flags.zf)
    {
        goto L_0x00a84e17;
    }
    // 00a84df0  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84df2  6a04                   -push 4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00a84df4  6a05                   -push 5
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00a84df6  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a84df8  a3241fa900             -mov dword ptr [0xa91f24], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083556) /* 0xa91f24 */) = cpu.eax;
    // 00a84dfd  ff156836a900           -call dword ptr [0xa93668]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089512) /* 0xa93668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84e03  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84e05  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84e07  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84e09  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a84e0b  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84e0d  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a84e0f  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84e11  ff15c036a900           -call dword ptr [0xa936c0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089600) /* 0xa936c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a84e17:
    // 00a84e17  8b15201fa900           -mov edx, dword ptr [0xa91f20]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083552) /* 0xa91f20 */);
    // 00a84e1d  a1241fa900             -mov eax, dword ptr [0xa91f24]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083556) /* 0xa91f24 */);
    // 00a84e22  e8b9faffff             -call 0xa848e0
    cpu.esp -= 4;
    sub_a848e0(app, cpu);
    if (cpu.terminate) return;
    // 00a84e27  8b35241fa900           -mov esi, dword ptr [0xa91f24]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(11083556) /* 0xa91f24 */);
    // 00a84e2d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a84e2e  8b7d18                 -mov edi, dword ptr [ebp + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84e31  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a84e32  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84e34  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84e39  ff15bc36a900           -call dword ptr [0xa936bc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089596) /* 0xa936bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84e3f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84e41  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84e43  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84e44  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84e45  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84e46  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84e47  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84e4a:
    // 00a84e4a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84e4b  ff157836a900           -call dword ptr [0xa93678]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089528) /* 0xa93678 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84e51  6a07                   -push 7
    *app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 00a84e53  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84e58  ff157c36a900           -call dword ptr [0xa9367c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089532) /* 0xa9367c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84e5e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84e60  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84e62  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84e63  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84e64  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84e65  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84e66  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84e69:
    // 00a84e69  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a84e6a  ff157836a900           -call dword ptr [0xa93678]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089528) /* 0xa93678 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84e70  6a04                   -push 4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00a84e72  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84e77  ff157c36a900           -call dword ptr [0xa9367c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089532) /* 0xa9367c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84e7d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84e7f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84e81  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84e82  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84e83  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84e84  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84e85  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84e88:
    // 00a84e88  765a                   -jbe 0xa84ee4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a84ee4;
    }
    // 00a84e8a  83f902                 +cmp ecx, 2
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a84e8d  0f8534fbffff           -jne 0xa849c7
    if (!cpu.flags.zf)
    {
        goto L_0x00a849c7;
    }
    // 00a84e93  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a84e94  ff158036a900           -call dword ptr [0xa93680]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089536) /* 0xa93680 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84e9a  6a03                   -push 3
    *app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00a84e9c  bfffff0000             -mov edi, 0xffff
    cpu.edi = 65535 /*0xffff*/;
    // 00a84ea1  ff158436a900           -call dword ptr [0xa93684]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089540) /* 0xa93684 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84ea7  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a84ea9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84eae  893d001fa900           -mov dword ptr [0xa91f00], edi
    *app->getMemory<x86::reg32>(x86::reg32(11083520) /* 0xa91f00 */) = cpu.edi;
    // 00a84eb4  ff158836a900           -call dword ptr [0xa93688]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089544) /* 0xa93688 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84eba  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84ebc  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84ebe  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84ebf  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84ec0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84ec1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84ec2  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84ec5:
    // 00a84ec5  6a07                   -push 7
    *app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 00a84ec7  ff158436a900           -call dword ptr [0xa93684]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089540) /* 0xa93684 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84ecd  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84ece  ff158836a900           -call dword ptr [0xa93688]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089544) /* 0xa93688 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84ed4  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84ed9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84edb  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84edd  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84ede  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84edf  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84ee0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84ee1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84ee4:
    // 00a84ee4  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a84ee6  ff158036a900           -call dword ptr [0xa93680]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089536) /* 0xa93680 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84eec  6a03                   -push 3
    *app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00a84eee  ff158436a900           -call dword ptr [0xa93684]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089540) /* 0xa93684 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84ef4  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 00a84ef9  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a84efb  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84f00  a3001fa900             -mov dword ptr [0xa91f00], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083520) /* 0xa91f00 */) = cpu.eax;
    // 00a84f05  ff158836a900           -call dword ptr [0xa93688]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089544) /* 0xa93688 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84f0b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84f0d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84f0f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f10  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f11  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f12  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f13  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84f16:
    // 00a84f16  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84f19  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84f1a  ff158836a900           -call dword ptr [0xa93688]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089544) /* 0xa93688 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84f20  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84f25  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84f27  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84f29  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f2a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f2b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f2c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f2d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84f30:
    // 00a84f30  8b7d18                 -mov edi, dword ptr [ebp + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84f33  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a84f34  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84f39  ff153436a900           -call dword ptr [0xa93634]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089460) /* 0xa93634 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84f3f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84f41  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84f43  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f44  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f45  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f46  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f47  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x00a84f4a:
    // 00a84f4a  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a84f4c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84f51  ff159036a900           -call dword ptr [0xa93690]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089552) /* 0xa93690 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84f57  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84f59  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84f5b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f5c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f5d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f5e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f5f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84f62:
    // 00a84f62  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84f63  ff159036a900           -call dword ptr [0xa93690]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089552) /* 0xa93690 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84f69  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84f6e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84f70  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84f72  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f73  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f74  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f75  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f76  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84f79:
    // 00a84f79  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a84f7b  e960fcffff             -jmp 0xa84be0
    goto L_0x00a84be0;
L_0x00a84f80:
    // 00a84f80  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a84f82  e96afcffff             -jmp 0xa84bf1
    goto L_0x00a84bf1;
L_0x00a84f87:
    // 00a84f87  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00a84f8a  ff15b436a900           -call dword ptr [0xa936b4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089588) /* 0xa936b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84f90  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84f95  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84f97  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84f99  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f9a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f9b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f9c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84f9d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a84fa0:
    // 00a84fa0  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a84fa3  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a84fa8  a30c1fa900             -mov dword ptr [0xa91f0c], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083532) /* 0xa91f0c */) = cpu.eax;
    // 00a84fad  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84faf  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84fb1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84fb2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84fb3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84fb4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84fb5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x00a84fb8:
    // 00a84fb8  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84fba  6a04                   -push 4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00a84fbc  6a04                   -push 4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00a84fbe  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a84fbf  ff156836a900           -call dword ptr [0xa93668]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089512) /* 0xa93668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84fc5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84fc7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84fc9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84fca  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84fcb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84fcc  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84fcd  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x00a84fd0:
    // 00a84fd0  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84fd2  6a04                   -push 4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00a84fd4  6a05                   -push 5
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00a84fd6  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84fd8  ff156836a900           -call dword ptr [0xa93668]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089512) /* 0xa93668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84fde  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84fe0  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84fe2  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84fe3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84fe4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84fe5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84fe6  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x00a84fe9:
    // 00a84fe9  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84feb  6a04                   -push 4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00a84fed  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a84fef  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a84ff1  ff156836a900           -call dword ptr [0xa93668]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089512) /* 0xa93668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a84ff7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a84ff9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a84ffb  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84ffc  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84ffd  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84ffe  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a84fff  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a85002:
    // 00a85002  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a85005  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a8500a  a3081fa900             -mov dword ptr [0xa91f08], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083528) /* 0xa91f08 */) = cpu.eax;
    // 00a8500f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a85011  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a85013  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85014  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85015  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85016  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85017  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a8501a:
    // 00a8501a  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a8501d  a3201fa900             -mov dword ptr [0xa91f20], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083552) /* 0xa91f20 */) = cpu.eax;
    // 00a85022  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a85024  a1241fa900             -mov eax, dword ptr [0xa91f24]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083556) /* 0xa91f24 */);
    // 00a85029  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a8502e  e8adf8ffff             -call 0xa848e0
    cpu.esp -= 4;
    sub_a848e0(app, cpu);
    if (cpu.terminate) return;
    // 00a85033  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a85035  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a85037  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85038  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85039  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8503a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8503b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a8503e:
    // 00a8503e  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a85041  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a85046  a3341fa900             -mov dword ptr [0xa91f34], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083572) /* 0xa91f34 */) = cpu.eax;
    // 00a8504b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8504d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a8504f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85050  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85051  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85052  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85053  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a85056:
    // 00a85056  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a85059  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a8505e  a33c1fa900             -mov dword ptr [0xa91f3c], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083580) /* 0xa91f3c */) = cpu.eax;
    // 00a85063  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a85065  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a85067  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85068  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85069  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8506a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8506b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a8506e:
    // 00a8506e  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a85071  a3301fa900             -mov dword ptr [0xa91f30], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083568) /* 0xa91f30 */) = cpu.eax;
    // 00a85076  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a85079  a33c1fa900             -mov dword ptr [0xa91f3c], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083580) /* 0xa91f3c */) = cpu.eax;
    // 00a8507e  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00a85081  a3341fa900             -mov dword ptr [0xa91f34], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083572) /* 0xa91f34 */) = cpu.eax;
    // 00a85086  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00a85089  a3381fa900             -mov dword ptr [0xa91f38], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083576) /* 0xa91f38 */) = cpu.eax;
    // 00a8508e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a85093  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a85095  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a85097  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85098  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85099  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8509a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8509b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a8509e:
    // 00a8509e  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a850a1  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a850a6  a3441fa900             -mov dword ptr [0xa91f44], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083588) /* 0xa91f44 */) = cpu.eax;
    // 00a850ab  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a850ad  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a850af  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a850b0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a850b1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a850b2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a850b3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a850b6:
    // 00a850b6  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00a850b9  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a850ba  ff15ec36a900           -call dword ptr [0xa936ec]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089644) /* 0xa936ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a850c0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a850c5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a850c7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a850c9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a850ca  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a850cb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a850cc  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a850cd  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a850d0:
    // 00a850d0  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a850d3  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a850d8  a3101fa900             -mov dword ptr [0xa91f10], eax
    *app->getMemory<x86::reg32>(x86::reg32(11083536) /* 0xa91f10 */) = cpu.eax;
    // 00a850dd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a850df  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a850e1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a850e2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a850e3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a850e4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a850e5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void sub_a850f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a850f0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a850f1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a850f2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a850f3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a850f4  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a850f7  8b15381fa900           -mov edx, dword ptr [0xa91f38]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083576) /* 0xa91f38 */);
    // 00a850fd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a850ff  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a85101  0f85a1000000           -jne 0xa851a8
    if (!cpu.flags.zf)
    {
        goto L_0x00a851a8;
    }
L_0x00a85107:
    // 00a85107  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a85109  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8510a  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8510c  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8510e  68ff000000             -push 0xff
    *app->getMemory<x86::reg32>(cpu.esp-4) = 255 /*0xff*/;
    cpu.esp -= 4;
    // 00a85113  8b35041fa900           -mov esi, dword ptr [0xa91f04]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(11083524) /* 0xa91f04 */);
    // 00a85119  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8511a  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00a8511f  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a85121  894c2418               -mov dword ptr [esp + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00a85125  ff159836a900           -call dword ptr [0xa93698]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089560) /* 0xa93698 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8512b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8512d  743e                   -je 0xa8516d
    if (cpu.flags.zf)
    {
        goto L_0x00a8516d;
    }
    // 00a8512f  b818000000             -mov eax, 0x18
    cpu.eax = 24 /*0x18*/;
    // 00a85134  e8771b0000             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a85139  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8513b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8513d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8513f  742c                   -je 0xa8516d
    if (cpu.flags.zf)
    {
        goto L_0x00a8516d;
    }
    // 00a85141  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a85145  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a85147  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8514b  c7420804000000         -mov dword ptr [edx + 8], 4
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 4 /*0x4*/;
    // 00a85152  894204                 -mov dword ptr [edx + 4], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a85155  a1181fa900             -mov eax, dword ptr [0xa91f18]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083544) /* 0xa91f18 */);
    // 00a8515a  89420c                 -mov dword ptr [edx + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a8515d  a11c1fa900             -mov eax, dword ptr [0xa91f1c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083548) /* 0xa91f1c */);
    // 00a85162  894210                 -mov dword ptr [edx + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00a85165  a1041fa900             -mov eax, dword ptr [0xa91f04]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083524) /* 0xa91f04 */);
    // 00a8516a  894214                 -mov dword ptr [edx + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x00a8516d:
    // 00a8516d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8516f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85170  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a85172  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a85174  68ff000000             -push 0xff
    *app->getMemory<x86::reg32>(cpu.esp-4) = 255 /*0xff*/;
    cpu.esp -= 4;
    // 00a85179  8b2d041fa900           -mov ebp, dword ptr [0xa91f04]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(11083524) /* 0xa91f04 */);
    // 00a8517f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a85180  bf14000000             -mov edi, 0x14
    cpu.edi = 20 /*0x14*/;
    // 00a85185  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a85187  897c2418               -mov dword ptr [esp + 0x18], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00a8518b  ff159836a900           -call dword ptr [0xa93698]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089560) /* 0xa93698 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a85191  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a85193  7509                   -jne 0xa8519e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8519e;
    }
    // 00a85195  833d381fa90000         +cmp dword ptr [0xa91f38], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11083576) /* 0xa91f38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8519c  7517                   -jne 0xa851b5
    if (!cpu.flags.zf)
    {
        goto L_0x00a851b5;
    }
L_0x00a8519e:
    // 00a8519e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a851a0  83c414                 +add esp, 0x14
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
    // 00a851a3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a851a4  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a851a5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a851a6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a851a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a851a8:
    // 00a851a8  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a851aa  ff15381fa900           -call dword ptr [0xa91f38]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11083576) /* 0xa91f38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a851b0  e952ffffff             -jmp 0xa85107
    goto L_0x00a85107;
L_0x00a851b5:
    // 00a851b5  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a851b6  ff15381fa900           -call dword ptr [0xa91f38]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11083576) /* 0xa91f38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a851bc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a851be  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a851c1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a851c2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a851c3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a851c4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a851c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void sub_a851d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a851d0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a851d1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a851d2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a851d3  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a851d7  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a851dc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a851de  7508                   -jne 0xa851e8
    if (!cpu.flags.zf)
    {
        goto L_0x00a851e8;
    }
L_0x00a851e0:
    // 00a851e0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a851e2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a851e3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a851e4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a851e5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a851e8:
    // 00a851e8  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00a851eb  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a851ec  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a851ed  ff159c36a900           -call dword ptr [0xa9369c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089564) /* 0xa9369c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a851f3  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a851f4  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a851f6  ff159c36a900           -call dword ptr [0xa9369c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089564) /* 0xa9369c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a851fc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a851fe  e89d1b0000             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a85203  833d381fa90000         +cmp dword ptr [0xa91f38], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11083576) /* 0xa91f38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8520a  74d4                   -je 0xa851e0
    if (cpu.flags.zf)
    {
        goto L_0x00a851e0;
    }
    // 00a8520c  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8520e  ff15381fa900           -call dword ptr [0xa91f38]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11083576) /* 0xa91f38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a85214  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a85216  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85217  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85218  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85219  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void sub_a85220(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a85220  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a85221  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a85222  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a85223  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a85224  833d381fa90000         +cmp dword ptr [0xa91f38], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11083576) /* 0xa91f38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8522b  7408                   -je 0xa85235
    if (cpu.flags.zf)
    {
        goto L_0x00a85235;
    }
    // 00a8522d  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a8522f  ff15381fa900           -call dword ptr [0xa91f38]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11083576) /* 0xa91f38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a85235:
    // 00a85235  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a85239  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a8523d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8523e  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a85240  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a85241  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a85245  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a85246  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a8524a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8524b  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a8524f  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a85250  8b6c2428               -mov ebp, dword ptr [esp + 0x28]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a85254  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a85255  a1041fa900             -mov eax, dword ptr [0xa91f04]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083524) /* 0xa91f04 */);
    // 00a8525a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8525b  ff15a436a900           -call dword ptr [0xa936a4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089572) /* 0xa936a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a85261  8b15381fa900           -mov edx, dword ptr [0xa91f38]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083576) /* 0xa91f38 */);
    // 00a85267  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a85269  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8526b  7509                   -jne 0xa85276
    if (!cpu.flags.zf)
    {
        goto L_0x00a85276;
    }
    // 00a8526d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8526f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85270  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85271  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85272  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85273  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x00a85276:
    // 00a85276  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a85278  ff15381fa900           -call dword ptr [0xa91f38]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11083576) /* 0xa91f38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8527e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a85280  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85281  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85282  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85283  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85284  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void sub_a85290(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a85290  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a85291  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a85292  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a85293  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a85294  833d381fa90000         +cmp dword ptr [0xa91f38], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11083576) /* 0xa91f38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8529b  7408                   -je 0xa852a5
    if (cpu.flags.zf)
    {
        goto L_0x00a852a5;
    }
    // 00a8529d  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a8529f  ff15381fa900           -call dword ptr [0xa91f38]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11083576) /* 0xa91f38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a852a5:
    // 00a852a5  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a852a9  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a852ad  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a852ae  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a852b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a852b1  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a852b5  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a852b6  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a852ba  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a852bb  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a852bd  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a852c1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a852c2  8b6c242c               -mov ebp, dword ptr [esp + 0x2c]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a852c6  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a852c7  a1041fa900             -mov eax, dword ptr [0xa91f04]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11083524) /* 0xa91f04 */);
    // 00a852cc  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a852cd  ff15a036a900           -call dword ptr [0xa936a0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089568) /* 0xa936a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a852d3  8b15381fa900           -mov edx, dword ptr [0xa91f38]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11083576) /* 0xa91f38 */);
    // 00a852d9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a852db  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a852dd  7509                   -jne 0xa852e8
    if (!cpu.flags.zf)
    {
        goto L_0x00a852e8;
    }
    // 00a852df  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a852e1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a852e2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a852e3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a852e4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a852e5  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x00a852e8:
    // 00a852e8  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a852ea  ff15381fa900           -call dword ptr [0xa91f38]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11083576) /* 0xa91f38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a852f0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a852f2  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a852f3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a852f4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a852f5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a852f6  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void sub_a85300(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a85300  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a85301  81ecf0000000           -sub esp, 0xf0
    (cpu.esp) -= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00a85307  8b9424f8000000         -mov edx, dword ptr [esp + 0xf8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(248) /* 0xf8 */);
    // 00a8530e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a85310  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a85313  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a85319  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a8531c  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a85322  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a85324  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a85327  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a85329  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8532b  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8532e  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a85331  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a85334  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a85337  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a85339  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8533b  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a8533e  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85345  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a85348  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a8534b  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85352  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a85355  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85358  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a8535b  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a8535e  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85365  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a85368  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a8536b  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85372  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a85375  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85378  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8537b  8b9424fc000000         -mov edx, dword ptr [esp + 0xfc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 00a85382  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a85386  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a85389  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a8538f  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a85392  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a85398  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a8539a  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a8539d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a8539f  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a853a1  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a853a4  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a853a7  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a853aa  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a853ad  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a853af  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a853b1  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a853b4  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a853bb  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a853be  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a853c1  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a853c8  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a853cb  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a853ce  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a853d1  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a853d4  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a853db  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a853de  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a853e1  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a853e8  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a853eb  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a853ee  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a853f1  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00a853f8  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00a853fc  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a853ff  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a85405  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a85408  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a8540e  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a85410  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a85413  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a85415  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85417  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8541a  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a8541d  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a85420  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a85423  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a85425  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a85427  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a8542a  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85431  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a85434  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a85437  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8543e  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a85441  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85444  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a85447  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a8544a  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85451  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a85454  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a85457  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8545e  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a85461  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85464  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85467  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00a8546e  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00a85475  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a85478  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a8547e  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a85481  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a85487  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a85489  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a8548c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a8548e  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85490  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85493  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a85496  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a85499  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a8549c  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a8549e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a854a0  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a854a3  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a854aa  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a854ad  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a854b0  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a854b7  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a854ba  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a854bd  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a854c0  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a854c3  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a854ca  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a854cd  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a854d0  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a854d7  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a854da  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a854dd  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a854e0  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00a854e4  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a854e5  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00a854e9  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a854ea  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a854ee  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a854ef  ff150c37a900           -call dword ptr [0xa9370c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089676) /* 0xa9370c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a854f5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a854f7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a854f8  8d8424b8000000         -lea eax, [esp + 0xb8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00a854ff  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85500  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00a85507  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85508  ff150c37a900           -call dword ptr [0xa9370c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089676) /* 0xa9370c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8550e  81c4f0000000           -add esp, 0xf0
    (cpu.esp) += x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00a85514  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85515  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void sub_a85520(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a85520  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a85521  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a85522  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a85523  81ecf0000000           -sub esp, 0xf0
    (cpu.esp) -= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00a85529  8bac2400010000         -mov ebp, dword ptr [esp + 0x100]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00a85530  8bbc2404010000         -mov edi, dword ptr [esp + 0x104]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00a85537  8bb42408010000         -mov esi, dword ptr [esp + 0x108]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 00a8553e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a85540  0f8e1a020000           -jle 0xa85760
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a85760;
    }
    // 00a85546  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x00a85547:
    // 00a85547  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a8554a  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00a8554d  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00a85551  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a85553  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a85556  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a8555c  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a8555f  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a85565  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a85567  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a8556a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a8556c  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8556e  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85571  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a85574  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a85577  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a8557a  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a8557c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8557e  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a85581  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85588  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a8558b  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a8558e  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85595  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a85598  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8559b  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a8559e  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a855a1  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a855a8  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a855ab  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a855ae  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a855b5  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a855b8  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a855bb  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a855be  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a855c1  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00a855c4  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00a855c8  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a855ca  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a855cd  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a855d3  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a855d6  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a855dc  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a855de  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a855e1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a855e3  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a855e5  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a855e8  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a855eb  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a855ee  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a855f1  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a855f3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a855f5  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a855f8  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a855ff  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a85602  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a85605  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8560c  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a8560f  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85612  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a85615  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a85618  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8561f  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a85622  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a85625  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8562c  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a8562f  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85632  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85635  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a85638  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00a8563b  8d8424b8000000         -lea eax, [esp + 0xb8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00a85642  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a85644  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a85647  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a8564d  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a85650  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a85656  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a85658  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a8565b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a8565d  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8565f  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85662  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a85665  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a85668  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a8566b  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a8566d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8566f  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a85672  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85679  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a8567c  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a8567f  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85686  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a85689  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8568c  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a8568f  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a85692  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85699  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a8569c  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a8569f  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a856a6  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a856a9  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a856ac  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a856af  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a856b1  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00a856b4  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a856b8  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a856ba  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a856bd  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a856c3  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a856c6  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a856cc  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a856ce  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a856d1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a856d3  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a856d5  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a856d8  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a856db  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a856de  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a856e1  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a856e3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a856e5  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a856e8  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a856ef  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a856f2  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a856f5  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a856fc  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a856ff  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85702  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a85705  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a85708  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8570f  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a85712  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a85715  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8571c  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a8571f  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85722  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85725  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00a85729  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8572a  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00a8572e  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8572f  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a85733  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85734  ff150c37a900           -call dword ptr [0xa9370c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089676) /* 0xa9370c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8573a  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8573e  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8573f  8d8424bc000000         -lea eax, [esp + 0xbc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00a85746  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85747  8d842484000000         -lea eax, [esp + 0x84]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00a8574e  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8574f  83c610                 +add esi, 0x10
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a85752  ff150c37a900           -call dword ptr [0xa9370c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089676) /* 0xa9370c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a85758  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a85759  0f85e8fdffff           -jne 0xa85547
    if (!cpu.flags.zf)
    {
        goto L_0x00a85547;
    }
    // 00a8575f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a85760:
    // 00a85760  81c4f0000000           -add esp, 0xf0
    (cpu.esp) += x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00a85766  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85767  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85768  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85769  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void sub_a85770(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a85770  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a85771  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00a85777  8b9424bc000000         -mov edx, dword ptr [esp + 0xbc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00a8577e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a85780  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a85783  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a85789  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a8578c  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a85792  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a85794  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a85797  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a85799  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8579b  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8579e  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a857a1  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a857a4  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a857a7  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a857a9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a857ab  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a857ae  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a857b5  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a857b8  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a857bb  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a857c2  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a857c5  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a857c8  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a857cb  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a857ce  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a857d5  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a857d8  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a857db  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a857e2  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a857e5  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a857e8  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a857eb  8b9424c0000000         -mov edx, dword ptr [esp + 0xc0]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 00a857f2  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a857f6  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a857f9  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a857ff  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a85802  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a85808  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a8580a  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a8580d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a8580f  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85811  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85814  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a85817  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a8581a  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a8581d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a8581f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a85821  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a85824  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8582b  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a8582e  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a85831  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85838  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a8583b  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8583e  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a85841  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a85844  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8584b  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a8584e  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a85851  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85858  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a8585b  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8585e  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85861  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00a85868  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00a8586c  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a8586f  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a85875  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a85878  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a8587e  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a85880  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a85883  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a85885  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85887  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8588a  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a8588d  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a85890  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a85893  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a85895  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a85897  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a8589a  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a858a1  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a858a4  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a858a7  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a858ae  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a858b1  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a858b4  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a858b7  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a858ba  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a858c1  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a858c4  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a858c7  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a858ce  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a858d1  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a858d4  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a858d7  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00a858db  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a858dc  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00a858e0  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a858e1  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a858e5  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a858e6  ff151037a900           -call dword ptr [0xa93710]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089680) /* 0xa93710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a858ec  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00a858f2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a858f3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void sub_a85900(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a85900  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a85901  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a85902  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a85903  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00a85909  8bbc24c4000000         -mov edi, dword ptr [esp + 0xc4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00a85910  8bac24c8000000         -mov ebp, dword ptr [esp + 0xc8]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00a85917  8bb424cc000000         -mov esi, dword ptr [esp + 0xcc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00a8591e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a85920  0f8e85010000           -jle 0xa85aab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a85aab;
    }
    // 00a85926  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x00a85927:
    // 00a85927  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a8592a  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00a8592d  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00a85931  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a85933  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a85936  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a8593c  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a8593f  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a85945  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a85947  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a8594a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a8594c  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8594e  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85951  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a85954  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a85957  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a8595a  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a8595c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8595e  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a85961  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85968  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a8596b  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a8596e  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85975  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a85978  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8597b  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a8597e  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a85981  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85988  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a8598b  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a8598e  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85995  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a85998  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8599b  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8599e  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a859a1  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00a859a4  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00a859a8  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a859aa  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a859ad  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a859b3  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a859b6  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a859bc  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a859be  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a859c1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a859c3  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a859c5  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a859c8  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a859cb  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a859ce  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a859d1  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a859d3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a859d5  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a859d8  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a859df  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a859e2  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a859e5  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a859ec  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a859ef  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a859f2  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a859f5  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a859f8  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a859ff  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a85a02  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a85a05  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85a0c  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a85a0f  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85a12  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85a15  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a85a17  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00a85a1a  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a85a1e  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a85a20  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a85a23  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a85a29  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a85a2c  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a85a32  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a85a34  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a85a37  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a85a39  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85a3b  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85a3e  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a85a41  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a85a44  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a85a47  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a85a49  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a85a4b  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a85a4e  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85a55  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a85a58  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a85a5b  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85a62  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a85a65  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85a68  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a85a6b  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a85a6e  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85a75  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a85a78  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a85a7b  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85a82  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a85a85  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85a88  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85a8b  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00a85a8f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85a90  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00a85a94  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85a95  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a85a99  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85a9a  83c60c                 +add esi, 0xc
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
    // 00a85a9d  ff151037a900           -call dword ptr [0xa93710]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089680) /* 0xa93710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a85aa3  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a85aa4  0f857dfeffff           -jne 0xa85927
    if (!cpu.flags.zf)
    {
        goto L_0x00a85927;
    }
    // 00a85aaa  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a85aab:
    // 00a85aab  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00a85ab1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85ab2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85ab3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85ab4  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void sub_a85ac0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a85ac0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a85ac1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a85ac2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a85ac3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a85ac4  81ecc4000000           -sub esp, 0xc4
    (cpu.esp) -= x86::reg32(x86::sreg32(196 /*0xc4*/));
    // 00a85aca  8bb424d8000000         -mov esi, dword ptr [esp + 0xd8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(216) /* 0xd8 */);
    // 00a85ad1  8b9424dc000000         -mov edx, dword ptr [esp + 0xdc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00a85ad8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a85ada  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a85add  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a85ae3  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a85ae6  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a85aec  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a85aee  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a85af1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a85af3  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85af5  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85af8  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a85afb  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a85afe  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a85b01  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a85b03  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a85b05  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a85b08  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85b0f  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a85b12  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a85b15  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85b1c  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a85b1f  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85b22  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a85b25  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a85b28  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85b2f  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a85b32  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a85b35  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85b3c  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a85b3f  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85b42  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85b45  8b9424dc000000         -mov edx, dword ptr [esp + 0xdc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00a85b4c  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a85b50  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a85b53  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a85b56  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a85b5c  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a85b5f  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a85b65  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a85b67  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a85b6a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a85b6c  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85b6e  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85b71  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a85b74  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a85b77  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a85b7a  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a85b7c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a85b7e  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a85b81  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85b88  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a85b8b  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a85b8e  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85b95  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a85b98  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85b9b  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a85b9e  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a85ba1  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85ba8  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a85bab  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a85bae  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85bb5  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a85bb8  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85bbb  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85bbe  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a85bc0  0f8ed9000000           -jle 0xa85c9f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a85c9f;
    }
    // 00a85bc6  8b8424dc000000         -mov eax, dword ptr [esp + 0xdc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00a85bcd  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00a85bd0  898424c0000000         -mov dword ptr [esp + 0xc0], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 00a85bd7  8b8424dc000000         -mov eax, dword ptr [esp + 0xdc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00a85bde  8bbc24dc000000         -mov edi, dword ptr [esp + 0xdc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00a85be5  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00a85bea  8bac24dc000000         -mov ebp, dword ptr [esp + 0xdc]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00a85bf1  898424b8000000         -mov dword ptr [esp + 0xb8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.eax;
    // 00a85bf8  8b8424dc000000         -mov eax, dword ptr [esp + 0xdc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00a85bff  81c7a0000000           -add edi, 0xa0
    (cpu.edi) += x86::reg32(x86::sreg32(160 /*0xa0*/));
    // 00a85c05  05e0000000             -add eax, 0xe0
    (cpu.eax) += x86::reg32(x86::sreg32(224 /*0xe0*/));
    // 00a85c0a  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00a85c0d  898424bc000000         -mov dword ptr [esp + 0xbc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */) = cpu.eax;
L_0x00a85c14:
    // 00a85c14  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00a85c18  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a85c1a  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a85c1d  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a85c23  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a85c26  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a85c2c  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a85c2e  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a85c31  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a85c33  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85c35  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85c38  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a85c3b  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a85c3e  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a85c41  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a85c43  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a85c45  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a85c48  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85c4f  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a85c52  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a85c55  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85c5c  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a85c5f  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85c62  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a85c65  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a85c68  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85c6f  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a85c72  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a85c75  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85c7c  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a85c7f  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85c82  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85c85  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00a85c89  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85c8a  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00a85c8e  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85c8f  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a85c93  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85c94  ff151037a900           -call dword ptr [0xa93710]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089680) /* 0xa93710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a85c9a  83fe02                 +cmp esi, 2
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
    // 00a85c9d  7d0d                   -jge 0xa85cac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a85cac;
    }
L_0x00a85c9f:
    // 00a85c9f  81c4c4000000           -add esp, 0xc4
    (cpu.esp) += x86::reg32(x86::sreg32(196 /*0xc4*/));
    // 00a85ca5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85ca6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85ca7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85ca8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85ca9  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a85cac:
    // 00a85cac  8b9424c0000000         -mov edx, dword ptr [esp + 0xc0]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 00a85cb3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a85cb5  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a85cb8  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a85cbe  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a85cc1  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a85cc7  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a85cc9  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a85ccc  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a85cce  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85cd0  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85cd3  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a85cd6  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a85cd9  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a85cdc  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a85cde  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a85ce0  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a85ce3  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85cea  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a85ced  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a85cf0  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85cf7  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a85cfa  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85cfd  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a85d00  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a85d03  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85d0a  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a85d0d  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a85d10  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85d17  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a85d1a  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85d1d  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85d20  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00a85d24  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85d25  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a85d29  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85d2a  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00a85d2e  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85d2f  ff151037a900           -call dword ptr [0xa93710]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089680) /* 0xa93710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a85d35  83fe03                 +cmp esi, 3
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
    // 00a85d38  0f8c61ffffff           -jl 0xa85c9f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a85c9f;
    }
    // 00a85d3e  8b9424b8000000         -mov edx, dword ptr [esp + 0xb8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00a85d45  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a85d49  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a85d4c  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a85d52  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a85d55  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a85d5b  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a85d5d  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a85d60  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a85d62  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85d64  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85d67  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a85d6a  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a85d6d  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a85d70  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a85d72  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a85d74  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a85d77  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85d7e  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a85d81  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a85d84  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85d8b  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a85d8e  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85d91  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a85d94  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a85d97  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85d9e  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a85da1  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a85da4  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85dab  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a85dae  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85db1  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85db4  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a85db8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85db9  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a85dbd  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85dbe  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00a85dc5  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85dc6  ff151037a900           -call dword ptr [0xa93710]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089680) /* 0xa93710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a85dcc  83fe04                 +cmp esi, 4
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a85dcf  0f8ccafeffff           -jl 0xa85c9f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a85c9f;
    }
    // 00a85dd5  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00a85dd9  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a85ddb  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a85dde  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a85de4  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a85de7  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a85ded  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a85def  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a85df2  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a85df4  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85df6  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85df9  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a85dfc  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a85dff  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a85e02  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a85e04  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a85e06  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a85e09  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85e10  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a85e13  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a85e16  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85e1d  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a85e20  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85e23  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a85e26  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a85e29  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85e30  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a85e33  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a85e36  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85e3d  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a85e40  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85e43  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85e46  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a85e4a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85e4b  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00a85e4f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85e50  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a85e54  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85e55  ff151037a900           -call dword ptr [0xa93710]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089680) /* 0xa93710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a85e5b  83fe05                 +cmp esi, 5
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
    // 00a85e5e  0f8c3bfeffff           -jl 0xa85c9f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a85c9f;
    }
    // 00a85e64  8b8424dc000000         -mov eax, dword ptr [esp + 0xdc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00a85e6b  05c0000000             -add eax, 0xc0
    (cpu.eax) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00a85e70  898424b4000000         -mov dword ptr [esp + 0xb4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 00a85e77  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a85e79  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a85e7b  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a85e7e  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a85e84  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a85e87  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a85e8d  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a85e8f  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a85e92  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a85e94  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85e96  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85e99  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a85e9c  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a85e9f  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a85ea2  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a85ea4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a85ea6  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a85ea9  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85eb0  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a85eb3  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a85eb6  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85ebd  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a85ec0  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85ec3  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a85ec6  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a85ec9  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85ed0  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a85ed3  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a85ed6  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85edd  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a85ee0  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85ee3  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85ee6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a85ee8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85ee9  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00a85eed  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85eee  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00a85ef2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85ef3  ff151037a900           -call dword ptr [0xa93710]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089680) /* 0xa93710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a85ef9  83fe06                 +cmp esi, 6
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a85efc  0f8c9dfdffff           -jl 0xa85c9f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a85c9f;
    }
    // 00a85f02  8b9424bc000000         -mov edx, dword ptr [esp + 0xbc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00a85f09  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a85f0d  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a85f10  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a85f16  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a85f19  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a85f1f  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a85f21  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a85f24  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a85f26  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85f28  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85f2b  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a85f2e  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a85f31  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a85f34  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a85f36  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a85f38  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a85f3b  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85f42  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a85f45  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a85f48  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85f4f  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a85f52  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85f55  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a85f58  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a85f5b  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85f62  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a85f65  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a85f68  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a85f6f  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a85f72  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85f75  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a85f78  81c5c0000000           -add ebp, 0xc0
    (cpu.ebp) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00a85f7e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a85f80  81c7c0000000           -add edi, 0xc0
    (cpu.edi) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00a85f86  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85f87  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00a85f8b  8b9c24c0000000         -mov ebx, dword ptr [esp + 0xc0]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 00a85f92  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85f93  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00a85f9a  81c3c0000000           -add ebx, 0xc0
    (cpu.ebx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00a85fa0  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a85fa1  83ee06                 -sub esi, 6
    (cpu.esi) -= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 00a85fa4  899c24c8000000         -mov dword ptr [esp + 0xc8], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */) = cpu.ebx;
    // 00a85fab  ff151037a900           -call dword ptr [0xa93710]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089680) /* 0xa93710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a85fb1  8b9424c0000000         -mov edx, dword ptr [esp + 0xc0]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 00a85fb8  8b8c24b8000000         -mov ecx, dword ptr [esp + 0xb8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00a85fbf  8b8424b4000000         -mov eax, dword ptr [esp + 0xb4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00a85fc6  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00a85fcc  81c1c0000000           -add ecx, 0xc0
    (cpu.ecx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00a85fd2  898424dc000000         -mov dword ptr [esp + 0xdc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */) = cpu.eax;
    // 00a85fd9  899424c0000000         -mov dword ptr [esp + 0xc0], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */) = cpu.edx;
    // 00a85fe0  898c24b8000000         -mov dword ptr [esp + 0xb8], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.ecx;
    // 00a85fe7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a85fe9  0f8f25fcffff           -jg 0xa85c14
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a85c14;
    }
    // 00a85fef  81c4c4000000           -add esp, 0xc4
    (cpu.esp) += x86::reg32(x86::sreg32(196 /*0xc4*/));
    // 00a85ff5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85ff6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85ff7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85ff8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a85ff9  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void sub_a86000(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86000  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a86001  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a86002  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a86003  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a86004  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00a8600a  8bbc24c8000000         -mov edi, dword ptr [esp + 0xc8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00a86011  8bac24cc000000         -mov ebp, dword ptr [esp + 0xcc]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00a86018  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8601a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a8601c  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a8601f  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a86025  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a86028  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a8602e  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a86030  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a86033  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a86035  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86037  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8603a  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a8603d  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a86040  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a86043  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a86045  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a86047  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a8604a  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a86051  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a86054  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a86057  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8605e  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a86061  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86064  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a86067  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a8606a  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a86071  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a86074  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a86077  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8607e  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a86081  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86084  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86087  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a8608b  8d5520                 -lea edx, [ebp + 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00a8608e  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a86091  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a86097  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a8609a  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a860a0  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a860a2  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a860a5  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a860a7  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a860a9  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a860ac  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a860af  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a860b2  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a860b5  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a860b7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a860b9  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a860bc  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a860c3  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a860c6  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a860c9  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a860d0  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a860d3  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a860d6  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a860d9  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a860dc  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a860e3  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a860e6  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a860e9  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a860f0  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a860f3  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a860f6  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a860f9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a860fb  0f8e91000000           -jle 0xa86192
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a86192;
    }
    // 00a86101  8d7560                 -lea esi, [ebp + 0x60]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(96) /* 0x60 */);
L_0x00a86104:
    // 00a86104  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00a86107  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00a8610b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a8610d  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a86110  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a86116  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a86119  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a8611f  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a86121  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a86124  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a86126  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86128  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8612b  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a8612e  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a86131  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a86134  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a86136  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a86138  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a8613b  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a86142  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a86145  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a86148  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8614f  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a86152  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86155  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a86158  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a8615b  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a86162  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a86165  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a86168  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8616f  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a86172  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86175  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86178  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00a8617c  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8617d  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00a86181  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a86182  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a86186  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a86187  ff151037a900           -call dword ptr [0xa93710]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089680) /* 0xa93710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8618d  83ff02                 +cmp edi, 2
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
    // 00a86190  7d0d                   -jge 0xa8619f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8619f;
    }
L_0x00a86192:
    // 00a86192  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00a86198  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86199  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8619a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8619b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8619c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a8619f:
    // 00a8619f  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a861a3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a861a5  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a861a8  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a861ae  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a861b1  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a861b7  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a861b9  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a861bc  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a861be  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a861c0  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a861c3  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a861c6  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a861c9  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a861cc  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a861ce  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a861d0  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a861d3  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a861da  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a861dd  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a861e0  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a861e7  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a861ea  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a861ed  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a861f0  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a861f3  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a861fa  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a861fd  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a86200  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a86207  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a8620a  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8620d  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86210  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a86214  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a86215  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00a86219  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8621a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8621e  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8621f  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a86222  83c640                 -add esi, 0x40
    (cpu.esi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00a86225  ff151037a900           -call dword ptr [0xa93710]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089680) /* 0xa93710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8622b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8622d  0f8fd1feffff           -jg 0xa86104
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a86104;
    }
    // 00a86233  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00a86239  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8623a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8623b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8623c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8623d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void sub_a86240(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86240  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a86241  83ec78                 -sub esp, 0x78
    (cpu.esp) -= x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00a86244  8b942484000000         -mov edx, dword ptr [esp + 0x84]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00a8624b  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a8624f  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a86252  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a86258  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a8625b  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a86261  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a86263  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a86266  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a86268  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8626a  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8626d  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a86270  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a86273  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a86276  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a86278  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8627a  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a8627d  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a86284  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a86287  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a8628a  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a86291  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a86294  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86297  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a8629a  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a8629d  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a862a4  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a862a7  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a862aa  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a862b1  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a862b4  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a862b7  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a862ba  8b942480000000         -mov edx, dword ptr [esp + 0x80]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00a862c1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a862c3  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a862c6  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a862cc  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a862cf  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a862d5  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a862d7  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a862da  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a862dc  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a862de  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a862e1  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a862e4  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a862e7  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a862ea  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a862ec  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a862ee  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a862f1  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a862f8  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a862fb  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a862fe  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a86305  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a86308  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8630b  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a8630e  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a86311  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a86318  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a8631b  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a8631e  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a86325  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a86328  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8632b  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8632e  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a86332  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a86333  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a86337  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a86338  ff151036a900           -call dword ptr [0xa93610]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089424) /* 0xa93610 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8633e  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00a86341  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86342  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void sub_a86350(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86350  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a86351  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a86352  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a86353  83ec78                 -sub esp, 0x78
    (cpu.esp) -= x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00a86356  8bbc2488000000         -mov edi, dword ptr [esp + 0x88]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00a8635d  8bac248c000000         -mov ebp, dword ptr [esp + 0x8c]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00a86364  8bb42490000000         -mov esi, dword ptr [esp + 0x90]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00a8636b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8636d  0f8e09010000           -jle 0xa8647c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8647c;
    }
    // 00a86373  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x00a86374:
    // 00a86374  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a86376  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00a86379  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8637d  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a8637f  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a86382  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a86388  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a8638b  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a86391  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a86393  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a86396  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a86398  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8639a  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8639d  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a863a0  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a863a3  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a863a6  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a863a8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a863aa  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a863ad  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a863b4  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a863b7  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a863ba  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a863c1  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a863c4  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a863c7  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a863ca  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a863cd  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a863d4  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a863d7  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a863da  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a863e1  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a863e4  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a863e7  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a863ea  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a863ed  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00a863f0  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00a863f4  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a863f6  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a863f9  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a863ff  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a86402  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a86408  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a8640a  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a8640d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a8640f  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86411  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86414  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a86417  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a8641a  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a8641d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a8641f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a86421  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a86424  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8642b  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a8642e  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a86431  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a86438  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a8643b  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8643e  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a86441  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a86444  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8644b  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a8644e  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a86451  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a86458  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a8645b  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8645e  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86461  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00a86465  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a86466  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8646a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8646b  83c608                 +add esi, 8
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
    // 00a8646e  ff151036a900           -call dword ptr [0xa93610]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089424) /* 0xa93610 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a86474  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a86475  0f85f9feffff           -jne 0xa86374
    if (!cpu.flags.zf)
    {
        goto L_0x00a86374;
    }
    // 00a8647b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a8647c:
    // 00a8647c  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00a8647f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86480  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86481  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86482  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void sub_a86490(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86490  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a86491  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a86492  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a86493  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a86494  83ec78                 -sub esp, 0x78
    (cpu.esp) -= x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00a86497  8bac248c000000         -mov ebp, dword ptr [esp + 0x8c]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00a8649e  8bbc2490000000         -mov edi, dword ptr [esp + 0x90]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00a864a5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a864a7  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a864a9  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a864ac  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a864b2  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a864b5  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a864bb  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a864bd  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a864c0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a864c2  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a864c4  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a864c7  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a864ca  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a864cd  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a864d0  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a864d2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a864d4  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a864d7  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a864de  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a864e1  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a864e4  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a864eb  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a864ee  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a864f1  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a864f4  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a864f7  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a864fe  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a86501  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a86504  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8650b  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a8650e  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86511  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86514  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a86516  0f8e89000000           -jle 0xa865a5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a865a5;
    }
    // 00a8651c  8d7720                 -lea esi, [edi + 0x20]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
L_0x00a8651f:
    // 00a8651f  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a86523  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a86525  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a86528  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a8652e  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a86531  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a86537  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a86539  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a8653c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a8653e  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86540  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86543  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a86546  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a86549  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a8654c  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a8654e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a86550  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a86553  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8655a  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a8655d  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a86560  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a86567  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a8656a  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8656d  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a86570  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a86573  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8657a  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a8657d  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a86580  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a86587  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a8658a  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8658d  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86590  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a86594  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a86595  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a86599  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8659a  ff151036a900           -call dword ptr [0xa93610]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089424) /* 0xa93610 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a865a0  83fd02                 +cmp ebp, 2
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a865a3  7d0a                   -jge 0xa865af
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a865af;
    }
L_0x00a865a5:
    // 00a865a5  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00a865a8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a865a9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a865aa  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a865ab  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a865ac  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a865af:
    // 00a865af  83c740                 -add edi, 0x40
    (cpu.edi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00a865b2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a865b4  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a865b6  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a865b9  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a865bf  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a865c2  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a865c8  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a865ca  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a865cd  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a865cf  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a865d1  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a865d4  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a865d7  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a865da  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a865dd  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a865df  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a865e1  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a865e4  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a865eb  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a865ee  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a865f1  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a865f8  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a865fb  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a865fe  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a86601  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a86604  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8660b  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a8660e  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a86611  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a86618  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a8661b  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8661e  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86621  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a86623  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a86624  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00a86628  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a86629  83c640                 -add esi, 0x40
    (cpu.esi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00a8662c  83ed02                 -sub ebp, 2
    (cpu.ebp) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a8662f  ff151036a900           -call dword ptr [0xa93610]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089424) /* 0xa93610 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a86635  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a86637  0f8fe2feffff           -jg 0xa8651f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8651f;
    }
    // 00a8663d  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00a86640  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86641  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86642  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86643  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86644  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void sub_a86650(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86650  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a86651  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a86654  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00a86658  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8665a  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a8665d  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a86663  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a86666  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a8666c  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a8666e  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a86671  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a86673  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86675  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86678  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a8667b  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a8667e  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a86681  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a86683  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a86685  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a86688  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8668f  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a86692  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a86695  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8669c  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a8669f  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a866a2  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a866a5  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a866a8  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a866af  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a866b2  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a866b5  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a866bc  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a866bf  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a866c2  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a866c5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a866c7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a866c8  ff15b036a900           -call dword ptr [0xa936b0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089584) /* 0xa936b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a866ce  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a866d1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a866d2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void sub_a866e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a866e0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a866e1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a866e2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a866e3  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a866e6  8b74244c               -mov esi, dword ptr [esp + 0x4c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00a866ea  8b6c2450               -mov ebp, dword ptr [esp + 0x50]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00a866ee  8b7c2454               -mov edi, dword ptr [esp + 0x54]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00a866f2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a866f4  0f8e89000000           -jle 0xa86783
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a86783;
    }
    // 00a866fa  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x00a866fb:
    // 00a866fb  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi);
    // 00a866fd  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00a86700  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a86704  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a86706  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a86709  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a8670f  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a86712  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a86718  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a8671a  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a8671d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a8671f  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86721  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86724  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a86727  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a8672a  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a8672d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a8672f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a86731  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a86734  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8673b  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a8673e  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a86741  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a86748  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a8674b  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8674e  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a86751  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a86754  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8675b  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a8675e  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a86761  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a86768  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a8676b  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8676e  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86771  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a86772  83c704                 +add edi, 4
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
    // 00a86775  ff15b036a900           -call dword ptr [0xa936b0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089584) /* 0xa936b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8677b  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8677c  0f8579ffffff           -jne 0xa866fb
    if (!cpu.flags.zf)
    {
        goto L_0x00a866fb;
    }
    // 00a86782  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a86783:
    // 00a86783  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a86786  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86787  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86788  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86789  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void sub_a86790(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86790  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a86791  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a86792  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a86795  8b7c2448               -mov edi, dword ptr [esp + 0x48]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00a86799  8b74244c               -mov esi, dword ptr [esp + 0x4c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00a8679d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8679f  0f8e80000000           -jle 0xa86825
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a86825;
    }
    // 00a867a5  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x00a867a6:
    // 00a867a6  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a867aa  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a867ac  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00a867af  d80d5c23a900           -fmul dword ptr [0xa9235c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084636) /* 0xa9235c */));
    // 00a867b5  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00a867b8  d80d5823a900           -fmul dword ptr [0xa92358]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11084632) /* 0xa92358 */));
    // 00a867be  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00a867c0  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00a867c3  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a867c5  d918                   -fstp dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a867c7  d95804                 -fstp dword ptr [eax + 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a867ca  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a867cd  894820                 -mov dword ptr [eax + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a867d0  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00a867d3  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a867d5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a867d7  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00a867da  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a867e1  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00a867e4  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00a867e7  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a867ee  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a867f1  d95824                 -fstp dword ptr [eax + 0x24]
    *app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a867f4  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00a867f7  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00a867fa  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a86801  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a86804  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a86807  8b0c9d1032a900         -mov ecx, dword ptr [ebx*4 + 0xa93210]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11088400) /* 0xa93210 */ + cpu.ebx * 4);
    // 00a8680e  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00a86811  d95828                 -fstp dword ptr [eax + 0x28]
    *app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86814  d95818                 -fstp dword ptr [eax + 0x18]
    *app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86817  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a86818  83c620                 +add esi, 0x20
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8681b  ff15b036a900           -call dword ptr [0xa936b0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11089584) /* 0xa936b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a86821  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a86822  7582                   -jne 0xa867a6
    if (!cpu.flags.zf)
    {
        goto L_0x00a867a6;
    }
    // 00a86824  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a86825:
    // 00a86825  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a86828  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86829  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8682a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 */
void sub_a8682e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8682e  e99d060000             -jmp 0xa86ed0
    return sub_a86ed0(app, cpu);
}

/* align: skip  */
/* data blob: 0332a800574154434f4d20432f432b2b33322052756e2d54696d652073797374656d2e2028632920436f7079726967687420627920574154434f4d20496e7465726e6174696f6e616c20436f72702e20313938382d313939342e20416c6c207269676874732072657365727665642e */
void sub_a868a2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a868a2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a868a3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a868a5  d9e4                   -ftst 
    cpu.fpu.compare(cpu.fpu.st(0), 0.0);
    // 00a868a7  83ec18                 +sub esp, 0x18
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a868aa  9b                     -wait 
    /*nothing*/;
    // 00a868ab  dd7df8                 -fnstsw word ptr [ebp - 8]
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.fpu.status.word;
    // 00a868ae  dd55e8                 +fst qword ptr [ebp - 0x18]
    *app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    // 00a868b1  8a65f9                 -mov ah, byte ptr [ebp - 7]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */);
    // 00a868b4  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a868b5  751a                   -jne 0xa868d1
    if (!cpu.flags.zf)
    {
        goto L_0x00a868d1;
    }
    // 00a868b7  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
L_0x00a868b9:
    // 00a868b9  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a868bb  dd5df0                 -fstp qword ptr [ebp - 0x10]
    *app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a868be  8945f8                 -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00a868c1  8955fc                 -mov dword ptr [ebp - 4], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00a868c4  e8a1070000             -call 0xa8706a
    cpu.esp -= 4;
    sub_a8706a(app, cpu);
    if (cpu.terminate) return;
    // 00a868c9  83ec08                 +sub esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a868cc  e9f9000000             -jmp 0xa869ca
    goto L_0x00a869ca;
L_0x00a868d1:
    // 00a868d1  d9c1                   +fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 00a868d3  d9fc                   +frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 00a868d5  d8da                   +fcomp st(2)
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(2));
    cpu.fpu.pop();
    // 00a868d7  9b                     -wait 
    /*nothing*/;
    // 00a868d8  dd7dfa                 -fnstsw word ptr [ebp - 6]
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-6) /* -0x6 */) = cpu.fpu.status.word;
    // 00a868db  9b                     -wait 
    /*nothing*/;
    // 00a868dc  8a65fb                 -mov ah, byte ptr [ebp - 5]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
    // 00a868df  733b                   -jae 0xa8691c
    if (!cpu.flags.cf)
    {
        goto L_0x00a8691c;
    }
    // 00a868e1  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00a868e3  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a868e4  75d3                   -jne 0xa868b9
    if (!cpu.flags.zf)
    {
        goto L_0x00a868b9;
    }
    // 00a868e6  66b80200               -mov ax, 2
    cpu.ax = 2 /*0x2*/;
    // 00a868ea  668945fc               -mov word ptr [ebp - 4], ax
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ax;
    // 00a868ee  df45fc                 +fild word ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg16(*app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00a868f1  d9c2                   +fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 00a868f3  d9f8                   +fprem 
    cpu.fpu.st(0) = cpu.fpu.rem(cpu.fpu.st(0), cpu.fpu.st(1));
    // 00a868f5  9b                     -wait 
    /*nothing*/;
    // 00a868f6  dd7dfc                 -fnstsw word ptr [ebp - 4]
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.fpu.status.word;
    // 00a868f9  9b                     -wait 
    /*nothing*/;
    // 00a868fa  8a65fd                 -mov ah, byte ptr [ebp - 3]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */);
    // 00a868fd  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a868fe  b400                   -mov ah, 0
    cpu.ah = 0 /*0x0*/;
    // 00a86900  7a11                   -jp 0xa86913
    if (cpu.flags.pf)
    {
        goto L_0x00a86913;
    }
    // 00a86902  d9e4                   +ftst 
    cpu.fpu.compare(cpu.fpu.st(0), 0.0);
    // 00a86904  9b                     -wait 
    /*nothing*/;
    // 00a86905  dd7dfc                 -fnstsw word ptr [ebp - 4]
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.fpu.status.word;
    // 00a86908  9b                     -wait 
    /*nothing*/;
    // 00a86909  8a65fd                 -mov ah, byte ptr [ebp - 3]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */);
    // 00a8690c  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a8690d  b400                   -mov ah, 0
    cpu.ah = 0 /*0x0*/;
    // 00a8690f  7402                   -je 0xa86913
    if (cpu.flags.zf)
    {
        goto L_0x00a86913;
    }
    // 00a86911  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
L_0x00a86913:
    // 00a86913  8865f9                 -mov byte ptr [ebp - 7], ah
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */) = cpu.ah;
    // 00a86916  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86918  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8691a  eb08                   -jmp 0xa86924
    goto L_0x00a86924;
L_0x00a8691c:
    // 00a8691c  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a8691d  7405                   -je 0xa86924
    if (cpu.flags.zf)
    {
        goto L_0x00a86924;
    }
    // 00a8691f  e987000000             -jmp 0xa869ab
    goto L_0x00a869ab;
L_0x00a86924:
    // 00a86924  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 00a86926  dd5df0                 -fstp qword ptr [ebp - 0x10]
    *app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a86929  9b                     -wait 
    /*nothing*/;
    // 00a8692a  668b45f6               -mov ax, word ptr [ebp - 0xa]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 00a8692e  6625f07f               -and ax, 0x7ff0
    cpu.ax &= x86::reg16(x86::sreg16(32752 /*0x7ff0*/));
    // 00a86932  662df03f               -sub ax, 0x3ff0
    (cpu.ax) -= x86::reg16(x86::sreg16(16368 /*0x3ff0*/));
    // 00a86936  663d0001               +cmp ax, 0x100
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(256 /*0x100*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8693a  736f                   -jae 0xa869ab
    if (!cpu.flags.cf)
    {
        goto L_0x00a869ab;
    }
    // 00a8693c  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 00a8693e  db5dfc                 -fistp dword ptr [ebp - 4]
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00a86941  9b                     -wait 
    /*nothing*/;
    // 00a86942  668b45fe               -mov ax, word ptr [ebp - 2]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 00a86946  6609c0                 +or ax, ax
    cpu.clear_co();
    cpu.set_szp((cpu.ax |= x86::reg16(x86::sreg16(cpu.ax))));
    // 00a86949  750b                   -jne 0xa86956
    if (!cpu.flags.zf)
    {
        goto L_0x00a86956;
    }
    // 00a8694b  668b45fc               -mov ax, word ptr [ebp - 4]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a8694f  e881000000             -call 0xa869d5
    cpu.esp -= 4;
    sub_a869d5(app, cpu);
    if (cpu.terminate) return;
    // 00a86954  eb2b                   -jmp 0xa86981
    goto L_0x00a86981;
L_0x00a86956:
    // 00a86956  6640                   +inc ax
    {
        x86::reg16& tmp = cpu.ax;
        cpu.flags.of = ~(1 & (tmp >> 15));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 15);
        cpu.set_szp(tmp);
    }
    // 00a86958  7551                   -jne 0xa869ab
    if (!cpu.flags.zf)
    {
        goto L_0x00a869ab;
    }
    // 00a8695a  660b45fc               +or ax, word ptr [ebp - 4]
    cpu.clear_co();
    cpu.set_szp((cpu.ax |= x86::reg16(x86::sreg16(*app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */)))));
    // 00a8695e  744b                   -je 0xa869ab
    if (cpu.flags.zf)
    {
        goto L_0x00a869ab;
    }
    // 00a86960  66f7d8                 -neg ax
    cpu.ax = ~cpu.ax + 1;
    // 00a86963  e86d000000             -call 0xa869d5
    cpu.esp -= 4;
    sub_a869d5(app, cpu);
    if (cpu.terminate) return;
    // 00a86968  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00a8696a  f6059026a90001         +test byte ptr [0xa92690], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(x86::reg32(11085456) /* 0xa92690 */) & 1 /*0x1*/));
    // 00a86971  7504                   -jne 0xa86977
    if (!cpu.flags.zf)
    {
        goto L_0x00a86977;
    }
    // 00a86973  def1                   +fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00a86975  eb0a                   -jmp 0xa86981
    goto L_0x00a86981;
L_0x00a86977:
    // 00a86977  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00a8697c  e8fe080000             -call 0xa8727f
    cpu.esp -= 4;
    sub_a8727f(app, cpu);
    if (cpu.terminate) return;
L_0x00a86981:
    // 00a86981  dd55f8                 -fst qword ptr [ebp - 8]
    *app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    // 00a86984  9b                     -wait 
    /*nothing*/;
    // 00a86985  668b45f8               -mov ax, word ptr [ebp - 8]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00a86989  660b45fa               -or ax, word ptr [ebp - 6]
    cpu.ax |= x86::reg16(x86::sreg16(*app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-6) /* -0x6 */)));
    // 00a8698d  660b45fc               +or ax, word ptr [ebp - 4]
    cpu.clear_co();
    cpu.set_szp((cpu.ax |= x86::reg16(x86::sreg16(*app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */)))));
    // 00a86991  7514                   -jne 0xa869a7
    if (!cpu.flags.zf)
    {
        goto L_0x00a869a7;
    }
    // 00a86993  668b45fe               -mov ax, word ptr [ebp - 2]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 00a86997  66d1e0                 -shl ax, 1
    cpu.ax <<= 1 /*0x1*/ % 32;
    // 00a8699a  663de0ff               +cmp ax, 0xffe0
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65504 /*0xffe0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8699e  7507                   -jne 0xa869a7
    if (!cpu.flags.zf)
    {
        goto L_0x00a869a7;
    }
L_0x00a869a0:
    // 00a869a0  b002                   -mov al, 2
    cpu.al = 2 /*0x2*/;
    // 00a869a2  e912ffffff             -jmp 0xa868b9
    goto L_0x00a868b9;
L_0x00a869a7:
    // 00a869a7  ddd9                   +fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a869a9  eb1f                   -jmp 0xa869ca
    goto L_0x00a869ca;
L_0x00a869ab:
    // 00a869ab  d9ed                   -fldln2 
    cpu.fpu.push(0.6931471805599453);
    // 00a869ad  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 00a869af  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a869b1  d9e1                   -fabs 
    cpu.fpu.st(0) = cpu.fpu.abs(cpu.fpu.st(0));
    // 00a869b3  d9f1                   -fyl2x 
    cpu.fpu.st(1) = cpu.fpu.log2(cpu.fpu.st(0)) * cpu.fpu.st(1);
    cpu.fpu.pop();
    // 00a869b5  b007                   -mov al, 7
    cpu.al = 7 /*0x7*/;
    // 00a869b7  e840070000             -call 0xa870fc
    cpu.esp -= 4;
    sub_a870fc(app, cpu);
    if (cpu.terminate) return;
    // 00a869bc  3c00                   +cmp al, 0
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
    // 00a869be  75e0                   -jne 0xa869a0
    if (!cpu.flags.zf)
    {
        goto L_0x00a869a0;
    }
    // 00a869c0  8a65f9                 -mov ah, byte ptr [ebp - 7]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */);
    // 00a869c3  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a869c4  7302                   -jae 0xa869c8
    if (!cpu.flags.cf)
    {
        goto L_0x00a869c8;
    }
    // 00a869c6  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x00a869c8:
    // 00a869c8  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a869ca:
    // 00a869ca  dd5df8                 -fstp qword ptr [ebp - 8]
    *app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a869cd  dd45f8                 -fld qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00a869d0  9b                     -wait 
    /*nothing*/;
    // 00a869d1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a869d3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a869d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a869d5(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x00a869d5:
    // 00a869d5  66d1e8                 +shr ax, 1
    {
        x86::reg16 tmp = 1 /*0x1*/ % 32;
        x86::reg16& op = cpu.ax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (16 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a869d8  7604                   -jbe 0xa869de
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a869de;
    }
    // 00a869da  d8c8                   +fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 00a869dc  ebf7                   -jmp 0xa869d5
    goto L_0x00a869d5;
L_0x00a869de:
    // 00a869de  7313                   -jae 0xa869f3
    if (!cpu.flags.cf)
    {
        goto L_0x00a869f3;
    }
    // 00a869e0  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
L_0x00a869e2:
    // 00a869e2  740b                   -je 0xa869ef
    if (cpu.flags.zf)
    {
        goto L_0x00a869ef;
    }
    // 00a869e4  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 00a869e6  66d1e8                 +shr ax, 1
    {
        x86::reg16 tmp = 1 /*0x1*/ % 32;
        x86::reg16& op = cpu.ax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (16 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a869e9  7302                   -jae 0xa869ed
    if (!cpu.flags.cf)
    {
        goto L_0x00a869ed;
    }
    // 00a869eb  dcc9                   +fmul st(1), st(0)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
L_0x00a869ed:
    // 00a869ed  ebf3                   -jmp 0xa869e2
    goto L_0x00a869e2;
L_0x00a869ef:
    // 00a869ef  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a869f1  eb04                   -jmp 0xa869f7
    goto L_0x00a869f7;
L_0x00a869f3:
    // 00a869f3  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a869f5  d9e8                   -fld1 
    cpu.fpu.push(1.0);
L_0x00a869f7:
    // 00a869f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a869f8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a869f8  dd44240c               -fld qword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a869fc  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00a86a00  e89dfeffff             -call 0xa868a2
    cpu.esp -= 4;
    sub_a868a2(app, cpu);
    if (cpu.terminate) return;
    // 00a86a05  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a86a10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86a10  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a86a11  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a86a12  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a86a15  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a86a19  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00a86a1b  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a86a1f  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a86a22  b87a23a900             -mov eax, 0xa9237a
    cpu.eax = 11084666 /*0xa9237a*/;
    // 00a86a27  e8780e0000             -call 0xa878a4
    cpu.esp -= 4;
    sub_a878a4(app, cpu);
    if (cpu.terminate) return;
    // 00a86a2c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a86a2f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86a30  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86a31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a86a40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86a40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a86a42  0f8538100000           -jne 0xa87a80
    if (!cpu.flags.zf)
    {
        return sub_a87a80(app, cpu);
    }
    // 00a86a48  e853110000             -call 0xa87ba0
    cpu.esp -= 4;
    sub_a87ba0(app, cpu);
    if (cpu.terminate) return;
    // 00a86a4d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a86a4f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a86a50(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86a50  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a86a54(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86a54  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a86a55  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a86a56  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a86a58  ff157025a900           -call dword ptr [0xa92570]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085168) /* 0xa92570 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a86a5e  803d7038a90000         +cmp byte ptr [0xa93870], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(11090032) /* 0xa93870 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a86a65  750f                   -jne 0xa86a76
    if (!cpu.flags.zf)
    {
        goto L_0x00a86a76;
    }
    // 00a86a67  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a86a6c  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00a86a71  e806150000             -call 0xa87f7c
    cpu.esp -= 4;
    sub_a87f7c(app, cpu);
    if (cpu.terminate) return;
L_0x00a86a76:
    // 00a86a76  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a86a78  e803000000             -call 0xa86a80
    cpu.esp -= 4;
    sub_a86a80(app, cpu);
    if (cpu.terminate) return;
    // 00a86a7d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86a7e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86a7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a86a80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86a80  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a86a81  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a86a83  ff157025a900           -call dword ptr [0xa92570]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085168) /* 0xa92570 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a86a89  ff157425a900           -call dword ptr [0xa92574]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085172) /* 0xa92574 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a86a8f  833d3427a90000         +cmp dword ptr [0xa92734], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11085620) /* 0xa92734 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a86a96  7406                   -je 0xa86a9e
    if (cpu.flags.zf)
    {
        goto L_0x00a86a9e;
    }
    // 00a86a98  ff153427a900           -call dword ptr [0xa92734]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085620) /* 0xa92734 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a86a9e:
    // 00a86a9e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a86aa0  e9f7130000             -jmp 0xa87e9c
    return sub_a87e9c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a86ab0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86ab0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a86ab1  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a86ab3  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a86ab4  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 00a86ab6  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00a86ab9  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 00a86abb  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00a86abe  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 00a86ac0  e80b150000             -call 0xa87fd0
    cpu.esp -= 4;
    sub_a87fd0(app, cpu);
    if (cpu.terminate) return;
    // 00a86ac5  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86ac6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86ac7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a86ad0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86ad0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a86ad1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a86ad2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a86ad3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a86ad4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a86ad5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a86ad6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a86ad8  8b35a43ea900           -mov esi, dword ptr [0xa93ea4]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */);
    // 00a86ade  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a86ae0  743f                   -je 0xa86b21
    if (cpu.flags.zf)
    {
        goto L_0x00a86b21;
    }
    // 00a86ae2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a86ae4  743b                   -je 0xa86b21
    if (cpu.flags.zf)
    {
        goto L_0x00a86b21;
    }
    // 00a86ae6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a86ae8  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a86ae9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a86aeb  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a86aed  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a86aef  49                     -dec ecx
    (cpu.ecx)--;
    // 00a86af0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a86af2  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 00a86af4  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a86af6  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a86af7  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a86af8  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00a86afa  eb1f                   -jmp 0xa86b1b
    goto L_0x00a86b1b;
L_0x00a86afc:
    // 00a86afc  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a86afe  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a86b00  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a86b02  e879150000             -call 0xa88080
    cpu.esp -= 4;
    sub_a88080(app, cpu);
    if (cpu.terminate) return;
    // 00a86b07  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a86b09  750d                   -jne 0xa86b18
    if (!cpu.flags.zf)
    {
        goto L_0x00a86b18;
    }
    // 00a86b0b  803c393d               +cmp byte ptr [ecx + edi], 0x3d
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a86b0f  7507                   -jne 0xa86b18
    if (!cpu.flags.zf)
    {
        goto L_0x00a86b18;
    }
    // 00a86b11  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00a86b14  01c8                   +add eax, ecx
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
    // 00a86b16  eb0b                   -jmp 0xa86b23
    goto L_0x00a86b23;
L_0x00a86b18:
    // 00a86b18  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a86b1b:
    // 00a86b1b  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a86b1d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a86b1f  75db                   -jne 0xa86afc
    if (!cpu.flags.zf)
    {
        goto L_0x00a86afc;
    }
L_0x00a86b21:
    // 00a86b21  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a86b23:
    // 00a86b23  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86b24  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86b25  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86b26  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86b27  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86b28  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86b29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a86b30(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86b30  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a86b31  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a86b32  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a86b34  39d0                   +cmp eax, edx
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
    // 00a86b36  746c                   -je 0xa86ba4
    if (cpu.flags.zf)
    {
        goto L_0x00a86ba4;
    }
L_0x00a86b38:
    // 00a86b38  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00a86b3a  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a86b3c  39c1                   +cmp ecx, eax
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
    // 00a86b3e  7569                   -jne 0xa86ba9
    if (!cpu.flags.zf)
    {
        goto L_0x00a86ba9;
    }
    // 00a86b40  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a86b42  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 00a86b47  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a86b49  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00a86b4e  7554                   -jne 0xa86ba4
    if (!cpu.flags.zf)
    {
        goto L_0x00a86ba4;
    }
    // 00a86b50  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a86b53  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a86b56  39c1                   +cmp ecx, eax
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
    // 00a86b58  754f                   -jne 0xa86ba9
    if (!cpu.flags.zf)
    {
        goto L_0x00a86ba9;
    }
    // 00a86b5a  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a86b5c  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 00a86b61  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a86b63  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00a86b68  753a                   -jne 0xa86ba4
    if (!cpu.flags.zf)
    {
        goto L_0x00a86ba4;
    }
    // 00a86b6a  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a86b6d  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a86b70  39c1                   +cmp ecx, eax
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
    // 00a86b72  7535                   -jne 0xa86ba9
    if (!cpu.flags.zf)
    {
        goto L_0x00a86ba9;
    }
    // 00a86b74  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a86b76  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 00a86b7b  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a86b7d  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00a86b82  7520                   -jne 0xa86ba4
    if (!cpu.flags.zf)
    {
        goto L_0x00a86ba4;
    }
    // 00a86b84  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00a86b87  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a86b8a  39c1                   +cmp ecx, eax
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
    // 00a86b8c  751b                   -jne 0xa86ba9
    if (!cpu.flags.zf)
    {
        goto L_0x00a86ba9;
    }
    // 00a86b8e  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a86b91  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a86b94  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a86b96  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 00a86b9b  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a86b9d  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00a86ba2  7494                   -je 0xa86b38
    if (cpu.flags.zf)
    {
        goto L_0x00a86b38;
    }
L_0x00a86ba4:
    // 00a86ba4  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a86ba6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86ba7  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86ba8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a86ba9:
    // 00a86ba9  38c8                   +cmp al, cl
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
    // 00a86bab  751d                   -jne 0xa86bca
    if (!cpu.flags.zf)
    {
        goto L_0x00a86bca;
    }
    // 00a86bad  3c00                   +cmp al, 0
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
    // 00a86baf  74f3                   -je 0xa86ba4
    if (cpu.flags.zf)
    {
        goto L_0x00a86ba4;
    }
    // 00a86bb1  38ec                   +cmp ah, ch
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a86bb3  7515                   -jne 0xa86bca
    if (!cpu.flags.zf)
    {
        goto L_0x00a86bca;
    }
    // 00a86bb5  80fc00                 +cmp ah, 0
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a86bb8  74ea                   -je 0xa86ba4
    if (cpu.flags.zf)
    {
        goto L_0x00a86ba4;
    }
    // 00a86bba  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00a86bbd  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 00a86bc0  38c8                   +cmp al, cl
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
    // 00a86bc2  7506                   -jne 0xa86bca
    if (!cpu.flags.zf)
    {
        goto L_0x00a86bca;
    }
    // 00a86bc4  3c00                   +cmp al, 0
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
    // 00a86bc6  74dc                   -je 0xa86ba4
    if (cpu.flags.zf)
    {
        goto L_0x00a86ba4;
    }
    // 00a86bc8  38ec                   +cmp ah, ch
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x00a86bca:
    // 00a86bca  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00a86bcc  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a86bce  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86bcf  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86bd0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a86be0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86be0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a86be1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a86be2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
L_0x00a86be3:
    // 00a86be3  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a86be5  fec2                   -inc dl
    (cpu.dl)++;
    // 00a86be7  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a86bed  f6827825a90002         +test byte ptr [edx + 0xa92578], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11085176) /* 0xa92578 */) & 2 /*0x2*/));
    // 00a86bf4  7403                   -je 0xa86bf9
    if (cpu.flags.zf)
    {
        goto L_0x00a86bf9;
    }
    // 00a86bf6  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a86bf7  ebea                   -jmp 0xa86be3
    goto L_0x00a86be3;
L_0x00a86bf9:
    // 00a86bf9  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a86bfb  80f92b                 +cmp cl, 0x2b
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a86bfe  7405                   -je 0xa86c05
    if (cpu.flags.zf)
    {
        goto L_0x00a86c05;
    }
    // 00a86c00  80f92d                 +cmp cl, 0x2d
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a86c03  7501                   -jne 0xa86c06
    if (!cpu.flags.zf)
    {
        goto L_0x00a86c06;
    }
L_0x00a86c05:
    // 00a86c05  40                     -inc eax
    (cpu.eax)++;
L_0x00a86c06:
    // 00a86c06  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00a86c08:
    // 00a86c08  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a86c0a  fec3                   -inc bl
    (cpu.bl)++;
    // 00a86c0c  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a86c12  f6837825a90020         +test byte ptr [ebx + 0xa92578], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11085176) /* 0xa92578 */) & 32 /*0x20*/));
    // 00a86c19  740f                   -je 0xa86c2a
    if (cpu.flags.zf)
    {
        goto L_0x00a86c2a;
    }
    // 00a86c1b  6bd20a                 -imul edx, edx, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00a86c1e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a86c20  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a86c22  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a86c24  40                     -inc eax
    (cpu.eax)++;
    // 00a86c25  83ea30                 +sub edx, 0x30
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
    // 00a86c28  ebde                   -jmp 0xa86c08
    goto L_0x00a86c08;
L_0x00a86c2a:
    // 00a86c2a  80f92d                 +cmp cl, 0x2d
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a86c2d  7502                   -jne 0xa86c31
    if (!cpu.flags.zf)
    {
        goto L_0x00a86c31;
    }
    // 00a86c2f  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x00a86c31:
    // 00a86c31  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a86c33  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86c34  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86c35  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86c36  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a86c40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86c40  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a86c41  8b154038a900           -mov edx, dword ptr [0xa93840]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11089984) /* 0xa93840 */);
    // 00a86c47  83fa20                 +cmp edx, 0x20
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
    // 00a86c4a  7d12                   -jge 0xa86c5e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a86c5e;
    }
    // 00a86c4c  42                     -inc edx
    (cpu.edx)++;
    // 00a86c4d  890495bc37a900         -mov dword ptr [edx*4 + 0xa937bc], eax
    *app->getMemory<x86::reg32>(x86::reg32(11089852) /* 0xa937bc */ + cpu.edx * 4) = cpu.eax;
    // 00a86c54  89154038a900           -mov dword ptr [0xa93840], edx
    *app->getMemory<x86::reg32>(x86::reg32(11089984) /* 0xa93840 */) = cpu.edx;
    // 00a86c5a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a86c5c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86c5d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a86c5e:
    // 00a86c5e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a86c63  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86c64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a86c68(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86c68  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a86c69  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a86c6a  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a86c6b  0fa0                   -push fs
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 00a86c6d  0fa8                   -push gs
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 00a86c6f  8b1d4038a900           -mov ebx, dword ptr [0xa93840]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11089984) /* 0xa93840 */);
    // 00a86c75  83fb21                 +cmp ebx, 0x21
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33 /*0x21*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a86c78  7425                   -je 0xa86c9f
    if (cpu.flags.zf)
    {
        goto L_0x00a86c9f;
    }
    // 00a86c7a  c7054038a90021000000   -mov dword ptr [0xa93840], 0x21
    *app->getMemory<x86::reg32>(x86::reg32(11089984) /* 0xa93840 */) = 33 /*0x21*/;
    // 00a86c84  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a86c86  7417                   -je 0xa86c9f
    if (cpu.flags.zf)
    {
        goto L_0x00a86c9f;
    }
    // 00a86c88  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
L_0x00a86c8f:
    // 00a86c8f  8b82bc37a900           -mov eax, dword ptr [edx + 0xa937bc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(11089852) /* 0xa937bc */);
    // 00a86c95  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a86c98  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a86c99  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a86c9b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a86c9d  75f0                   -jne 0xa86c8f
    if (!cpu.flags.zf)
    {
        goto L_0x00a86c8f;
    }
L_0x00a86c9f:
    // 00a86c9f  0fa9                   -pop gs
    cpu.gs = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a86ca1  0fa1                   -pop fs
    cpu.fs = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a86ca3  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a86ca4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86ca5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86ca6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a86cb0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86cb0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a86cb1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a86cb2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a86cb3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a86cb4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a86cb5  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a86cb6  0fa0                   -push fs
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 00a86cb8  0fa8                   -push gs
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 00a86cba  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a86cbb  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a86cbe  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a86cc0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a86cc2  7405                   -je 0xa86cc9
    if (cpu.flags.zf)
    {
        goto L_0x00a86cc9;
    }
    // 00a86cc4  83f8d4                 +cmp eax, -0x2c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-44 /*-0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a86cc7  7607                   -jbe 0xa86cd0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a86cd0;
    }
L_0x00a86cc9:
    // 00a86cc9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a86ccb  e9be000000             -jmp 0xa86d8e
    goto L_0x00a86d8e;
L_0x00a86cd0:
    // 00a86cd0  8d680b                 -lea ebp, [eax + 0xb]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00a86cd3  83e5f8                 -and ebp, 0xfffffff8
    cpu.ebp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 00a86cd6  83fd10                 +cmp ebp, 0x10
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
    // 00a86cd9  7305                   -jae 0xa86ce0
    if (!cpu.flags.cf)
    {
        goto L_0x00a86ce0;
    }
    // 00a86cdb  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
L_0x00a86ce0:
    // 00a86ce0  ff15c426a900           -call dword ptr [0xa926c4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085508) /* 0xa926c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a86ce6  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a86ce8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a86cea  882424                 -mov byte ptr [esp], ah
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x00a86ced:
    // 00a86ced  3b2d8426a900           +cmp ebp, dword ptr [0xa92684]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(11085444) /* 0xa92684 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a86cf3  760c                   -jbe 0xa86d01
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a86d01;
    }
    // 00a86cf5  8b0d8026a900           -mov ecx, dword ptr [0xa92680]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11085440) /* 0xa92680 */);
    // 00a86cfb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a86cfd  7510                   -jne 0xa86d0f
    if (!cpu.flags.zf)
    {
        goto L_0x00a86d0f;
    }
    // 00a86cff  eb02                   -jmp 0xa86d03
    goto L_0x00a86d03;
L_0x00a86d01:
    // 00a86d01  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a86d03:
    // 00a86d03  890d8426a900           -mov dword ptr [0xa92684], ecx
    *app->getMemory<x86::reg32>(x86::reg32(11085444) /* 0xa92684 */) = cpu.ecx;
    // 00a86d09  8b0d7c26a900           -mov ecx, dword ptr [0xa9267c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11085436) /* 0xa9267c */);
L_0x00a86d0f:
    // 00a86d0f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a86d11  743c                   -je 0xa86d4f
    if (cpu.flags.zf)
    {
        goto L_0x00a86d4f;
    }
    // 00a86d13  8b7114                 -mov esi, dword ptr [ecx + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00a86d16  890d8026a900           -mov dword ptr [0xa92680], ecx
    *app->getMemory<x86::reg32>(x86::reg32(11085440) /* 0xa92680 */) = cpu.ecx;
    // 00a86d1c  39fe                   +cmp esi, edi
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
    // 00a86d1e  721c                   -jb 0xa86d3c
    if (cpu.flags.cf)
    {
        goto L_0x00a86d3c;
    }
    // 00a86d20  b87c26a900             -mov eax, 0xa9267c
    cpu.eax = 11085436 /*0xa9267c*/;
    // 00a86d25  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a86d27  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a86d2d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a86d2f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a86d31  e8ca130000             -call 0xa88100
    cpu.esp -= 4;
    sub_a88100(app, cpu);
    if (cpu.terminate) return;
    // 00a86d36  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a86d38  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a86d3a  7542                   -jne 0xa86d7e
    if (!cpu.flags.zf)
    {
        goto L_0x00a86d7e;
    }
L_0x00a86d3c:
    // 00a86d3c  3b358426a900           +cmp esi, dword ptr [0xa92684]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(11085444) /* 0xa92684 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a86d42  7606                   -jbe 0xa86d4a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a86d4a;
    }
    // 00a86d44  89358426a900           -mov dword ptr [0xa92684], esi
    *app->getMemory<x86::reg32>(x86::reg32(11085444) /* 0xa92684 */) = cpu.esi;
L_0x00a86d4a:
    // 00a86d4a  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a86d4d  ebc0                   -jmp 0xa86d0f
    goto L_0x00a86d0f;
L_0x00a86d4f:
    // 00a86d4f  803c2400               +cmp byte ptr [esp], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a86d53  750b                   -jne 0xa86d60
    if (!cpu.flags.zf)
    {
        goto L_0x00a86d60;
    }
    // 00a86d55  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a86d57  e8b8160000             -call 0xa88414
    cpu.esp -= 4;
    sub_a88414(app, cpu);
    if (cpu.terminate) return;
    // 00a86d5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a86d5e  7515                   -jne 0xa86d75
    if (!cpu.flags.zf)
    {
        goto L_0x00a86d75;
    }
L_0x00a86d60:
    // 00a86d60  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a86d62  e819170000             -call 0xa88480
    cpu.esp -= 4;
    sub_a88480(app, cpu);
    if (cpu.terminate) return;
    // 00a86d67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a86d69  7413                   -je 0xa86d7e
    if (cpu.flags.zf)
    {
        goto L_0x00a86d7e;
    }
    // 00a86d6b  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 00a86d6d  880c24                 -mov byte ptr [esp], cl
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.cl;
    // 00a86d70  e978ffffff             -jmp 0xa86ced
    goto L_0x00a86ced;
L_0x00a86d75:
    // 00a86d75  c6042401               -mov byte ptr [esp], 1
    *app->getMemory<x86::reg8>(cpu.esp) = 1 /*0x1*/;
    // 00a86d79  e96fffffff             -jmp 0xa86ced
    goto L_0x00a86ced;
L_0x00a86d7e:
    // 00a86d7e  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 00a86d80  882db03ea900           -mov byte ptr [0xa93eb0], ch
    *app->getMemory<x86::reg8>(x86::reg32(11091632) /* 0xa93eb0 */) = cpu.ch;
    // 00a86d86  ff15cc26a900           -call dword ptr [0xa926cc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085516) /* 0xa926cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a86d8c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a86d8e:
    // 00a86d8e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a86d91  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86d92  0fa9                   -pop gs
    cpu.gs = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a86d94  0fa1                   -pop fs
    cpu.fs = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a86d96  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a86d97  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86d98  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86d99  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86d9a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86d9b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86d9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_a86da0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86da0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a86da1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a86da2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a86da3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a86da4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a86da6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a86da8  0f84f3000000           -je 0xa86ea1
    if (cpu.flags.zf)
    {
        goto L_0x00a86ea1;
    }
    // 00a86dae  ff15c426a900           -call dword ptr [0xa926c4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085508) /* 0xa926c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a86db4  8b0d5038a900           -mov ecx, dword ptr [0xa93850]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11090000) /* 0xa93850 */);
    // 00a86dba  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a86dbc  7440                   -je 0xa86dfe
    if (cpu.flags.zf)
    {
        goto L_0x00a86dfe;
    }
    // 00a86dbe  39f1                   +cmp ecx, esi
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
    // 00a86dc0  770c                   -ja 0xa86dce
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a86dce;
    }
    // 00a86dc2  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a86dc4  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a86dc6  39f0                   +cmp eax, esi
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
    // 00a86dc8  0f878d000000           -ja 0xa86e5b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a86e5b;
    }
L_0x00a86dce:
    // 00a86dce  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a86dd0  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a86dd3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a86dd5  7410                   -je 0xa86de7
    if (cpu.flags.zf)
    {
        goto L_0x00a86de7;
    }
    // 00a86dd7  39f1                   +cmp ecx, esi
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
    // 00a86dd9  770c                   -ja 0xa86de7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a86de7;
    }
    // 00a86ddb  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a86ddd  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a86ddf  39f0                   +cmp eax, esi
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
    // 00a86de1  0f8774000000           -ja 0xa86e5b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a86e5b;
    }
L_0x00a86de7:
    // 00a86de7  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a86dea  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a86dec  7410                   -je 0xa86dfe
    if (cpu.flags.zf)
    {
        goto L_0x00a86dfe;
    }
    // 00a86dee  39f1                   +cmp ecx, esi
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
    // 00a86df0  770c                   -ja 0xa86dfe
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a86dfe;
    }
    // 00a86df2  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a86df4  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a86df6  39f0                   +cmp eax, esi
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
    // 00a86df8  0f875d000000           -ja 0xa86e5b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a86e5b;
    }
L_0x00a86dfe:
    // 00a86dfe  8b0d8026a900           -mov ecx, dword ptr [0xa92680]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11085440) /* 0xa92680 */);
    // 00a86e04  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a86e06  7434                   -je 0xa86e3c
    if (cpu.flags.zf)
    {
        goto L_0x00a86e3c;
    }
    // 00a86e08  39f1                   +cmp ecx, esi
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
    // 00a86e0a  7708                   -ja 0xa86e14
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a86e14;
    }
    // 00a86e0c  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a86e0e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a86e10  39f0                   +cmp eax, esi
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
    // 00a86e12  7747                   -ja 0xa86e5b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a86e5b;
    }
L_0x00a86e14:
    // 00a86e14  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a86e16  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a86e19  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a86e1b  740c                   -je 0xa86e29
    if (cpu.flags.zf)
    {
        goto L_0x00a86e29;
    }
    // 00a86e1d  39f1                   +cmp ecx, esi
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
    // 00a86e1f  7708                   -ja 0xa86e29
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a86e29;
    }
    // 00a86e21  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a86e23  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a86e25  39f0                   +cmp eax, esi
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
    // 00a86e27  7732                   -ja 0xa86e5b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a86e5b;
    }
L_0x00a86e29:
    // 00a86e29  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a86e2c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a86e2e  740c                   -je 0xa86e3c
    if (cpu.flags.zf)
    {
        goto L_0x00a86e3c;
    }
    // 00a86e30  39f1                   +cmp ecx, esi
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
    // 00a86e32  7708                   -ja 0xa86e3c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a86e3c;
    }
    // 00a86e34  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a86e36  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a86e38  39f0                   +cmp eax, esi
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
    // 00a86e3a  771f                   -ja 0xa86e5b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a86e5b;
    }
L_0x00a86e3c:
    // 00a86e3c  8b0d7c26a900           -mov ecx, dword ptr [0xa9267c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11085436) /* 0xa9267c */);
    // 00a86e42  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a86e44  7455                   -je 0xa86e9b
    if (cpu.flags.zf)
    {
        goto L_0x00a86e9b;
    }
L_0x00a86e46:
    // 00a86e46  39f1                   +cmp ecx, esi
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
    // 00a86e48  7708                   -ja 0xa86e52
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a86e52;
    }
    // 00a86e4a  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a86e4c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a86e4e  39f0                   +cmp eax, esi
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
    // 00a86e50  7709                   -ja 0xa86e5b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a86e5b;
    }
L_0x00a86e52:
    // 00a86e52  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a86e55  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a86e57  75ed                   -jne 0xa86e46
    if (!cpu.flags.zf)
    {
        goto L_0x00a86e46;
    }
    // 00a86e59  eb40                   -jmp 0xa86e9b
    goto L_0x00a86e9b;
L_0x00a86e5b:
    // 00a86e5b  b87c26a900             -mov eax, 0xa9267c
    cpu.eax = 11085436 /*0xa9267c*/;
    // 00a86e60  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a86e62  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a86e68  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a86e6a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a86e6c  e83f130000             -call 0xa881b0
    cpu.esp -= 4;
    sub_a881b0(app, cpu);
    if (cpu.terminate) return;
    // 00a86e71  8b158026a900           -mov edx, dword ptr [0xa92680]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11085440) /* 0xa92680 */);
    // 00a86e77  890d5038a900           -mov dword ptr [0xa93850], ecx
    *app->getMemory<x86::reg32>(x86::reg32(11090000) /* 0xa93850 */) = cpu.ecx;
    // 00a86e7d  39d1                   +cmp ecx, edx
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
    // 00a86e7f  7312                   -jae 0xa86e93
    if (!cpu.flags.cf)
    {
        goto L_0x00a86e93;
    }
    // 00a86e81  8b1d8426a900           -mov ebx, dword ptr [0xa92684]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(11085444) /* 0xa92684 */);
    // 00a86e87  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00a86e8a  39d8                   +cmp eax, ebx
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
    // 00a86e8c  7605                   -jbe 0xa86e93
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a86e93;
    }
    // 00a86e8e  a38426a900             -mov dword ptr [0xa92684], eax
    *app->getMemory<x86::reg32>(x86::reg32(11085444) /* 0xa92684 */) = cpu.eax;
L_0x00a86e93:
    // 00a86e93  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a86e95  8825b03ea900           -mov byte ptr [0xa93eb0], ah
    *app->getMemory<x86::reg8>(x86::reg32(11091632) /* 0xa93eb0 */) = cpu.ah;
L_0x00a86e9b:
    // 00a86e9b  ff15cc26a900           -call dword ptr [0xa926cc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085516) /* 0xa926cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a86ea1:
    // 00a86ea1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86ea2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86ea3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86ea4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86ea5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a86eb0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86eb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a86eb1(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a86eb1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a86ed0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a86ed0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a86ed1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a86ed2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a86ed3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a86ed4  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a86ed8  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a86edc  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a86ee0  83ff03                 +cmp edi, 3
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a86ee3  0f8777010000           -ja 0xa87060
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a87060;
    }
    // 00a86ee9  2eff24bdc06ea800       -jmp dword ptr cs:[edi*4 + 0xa86ec0]
    cpu.ip = *app->getMemory<x86::reg32>(11038400 + cpu.edi * 4); goto dynamic_jump;
  case 0x00a86ef1:
    // 00a86ef1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a86ef3  e8a0190000             -call 0xa88898
    cpu.esp -= 4;
    sub_a88898(app, cpu);
    if (cpu.terminate) return;
    // 00a86ef8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a86efa  0f8462010000           -je 0xa87062
    if (cpu.flags.zf)
    {
        goto L_0x00a87062;
    }
    // 00a86f00  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a86f01  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a86f02  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a86f03  e808c3ffff             -call 0xa83210
    cpu.esp -= 4;
    sub_a83210(app, cpu);
    if (cpu.terminate) return;
    // 00a86f08  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a86f0a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a86f0c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f0d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f0e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f0f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f10  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
  case 0x00a86f13:
    // 00a86f13  8b156038a900           -mov edx, dword ptr [0xa93860]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11090016) /* 0xa93860 */);
    // 00a86f19  42                     -inc edx
    (cpu.edx)++;
    // 00a86f1a  89156038a900           -mov dword ptr [0xa93860], edx
    *app->getMemory<x86::reg32>(x86::reg32(11090016) /* 0xa93860 */) = cpu.edx;
    // 00a86f20  83fa01                 +cmp edx, 1
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
    // 00a86f23  7e16                   -jle 0xa86f3b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a86f3b;
    }
    // 00a86f25  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a86f27  e8e41b0000             -call 0xa88b10
    cpu.esp -= 4;
    sub_a88b10(app, cpu);
    if (cpu.terminate) return;
    // 00a86f2c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a86f2e  740b                   -je 0xa86f3b
    if (cpu.flags.zf)
    {
        goto L_0x00a86f3b;
    }
    // 00a86f30  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a86f32  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a86f34  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f35  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f36  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f37  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f38  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a86f3b:
    // 00a86f3b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a86f40  e8e70f0000             -call 0xa87f2c
    cpu.esp -= 4;
    sub_a87f2c(app, cpu);
    if (cpu.terminate) return;
    // 00a86f45  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a86f47  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a86f49  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a86f4e  e8c50c0000             -call 0xa87c18
    cpu.esp -= 4;
    sub_a87c18(app, cpu);
    if (cpu.terminate) return;
    // 00a86f53  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a86f55  750b                   -jne 0xa86f62
    if (!cpu.flags.zf)
    {
        goto L_0x00a86f62;
    }
    // 00a86f57  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a86f59  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a86f5b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f5c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f5d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f5e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f5f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a86f62:
    // 00a86f62  e8d1180000             -call 0xa88838
    cpu.esp -= 4;
    sub_a88838(app, cpu);
    if (cpu.terminate) return;
    // 00a86f67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a86f69  750b                   -jne 0xa86f76
    if (!cpu.flags.zf)
    {
        goto L_0x00a86f76;
    }
    // 00a86f6b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a86f6d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a86f6f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f70  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f71  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f72  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f73  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a86f76:
    // 00a86f76  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a86f78  e81b190000             -call 0xa88898
    cpu.esp -= 4;
    sub_a88898(app, cpu);
    if (cpu.terminate) return;
    // 00a86f7d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a86f7f  750b                   -jne 0xa86f8c
    if (!cpu.flags.zf)
    {
        goto L_0x00a86f8c;
    }
    // 00a86f81  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a86f83  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a86f85  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f86  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f87  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f88  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86f89  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a86f8c:
    // 00a86f8c  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00a86f91  e8960f0000             -call 0xa87f2c
    cpu.esp -= 4;
    sub_a87f2c(app, cpu);
    if (cpu.terminate) return;
    // 00a86f96  e8d9190000             -call 0xa88974
    cpu.esp -= 4;
    sub_a88974(app, cpu);
    if (cpu.terminate) return;
    // 00a86f9b  833da827a90000         +cmp dword ptr [0xa927a8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11085736) /* 0xa927a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a86fa2  7422                   -je 0xa86fc6
    if (cpu.flags.zf)
    {
        goto L_0x00a86fc6;
    }
    // 00a86fa4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a86fa5  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a86fa6  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a86fa7  ff15a827a900           -call dword ptr [0xa927a8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085736) /* 0xa927a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a86fad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a86faf  7515                   -jne 0xa86fc6
    if (!cpu.flags.zf)
    {
        goto L_0x00a86fc6;
    }
    // 00a86fb1  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00a86fb6  e8c10f0000             -call 0xa87f7c
    cpu.esp -= 4;
    sub_a87f7c(app, cpu);
    if (cpu.terminate) return;
    // 00a86fbb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a86fbd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a86fbf  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86fc0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86fc1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86fc2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86fc3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a86fc6:
    // 00a86fc6  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00a86fcb  e85c0f0000             -call 0xa87f2c
    cpu.esp -= 4;
    sub_a87f2c(app, cpu);
    if (cpu.terminate) return;
    // 00a86fd0  e81b1c0000             -call 0xa88bf0
    cpu.esp -= 4;
    sub_a88bf0(app, cpu);
    if (cpu.terminate) return;
    // 00a86fd5  ff15e826a900           -call dword ptr [0xa926e8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085544) /* 0xa926e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a86fdb  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a86fdc  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a86fdd  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a86fde  e82dc2ffff             -call 0xa83210
    cpu.esp -= 4;
    sub_a83210(app, cpu);
    if (cpu.terminate) return;
    // 00a86fe3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a86fe5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a86fe7  7577                   -jne 0xa87060
    if (!cpu.flags.zf)
    {
        goto L_0x00a87060;
    }
    // 00a86fe9  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a86fee  e8890f0000             -call 0xa87f7c
    cpu.esp -= 4;
    sub_a87f7c(app, cpu);
    if (cpu.terminate) return;
    // 00a86ff3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a86ff5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86ff6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86ff7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86ff8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a86ff9  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
  case 0x00a86ffc:
    // 00a86ffc  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a86ffd  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a86ffe  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a86fff  e80cc2ffff             -call 0xa83210
    cpu.esp -= 4;
    sub_a83210(app, cpu);
    if (cpu.terminate) return;
    // 00a87004  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a87006  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8700b  e8dc180000             -call 0xa888ec
    cpu.esp -= 4;
    sub_a888ec(app, cpu);
    if (cpu.terminate) return;
    // 00a87010  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a87012  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87013  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87014  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87015  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87016  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
  case 0x00a87019:
    // 00a87019  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8701a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8701b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8701c  e8efc1ffff             -call 0xa83210
    cpu.esp -= 4;
    sub_a83210(app, cpu);
    if (cpu.terminate) return;
    // 00a87021  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a87026  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a87028  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00a8702d  e84a0f0000             -call 0xa87f7c
    cpu.esp -= 4;
    sub_a87f7c(app, cpu);
    if (cpu.terminate) return;
    // 00a87032  833da827a90000         +cmp dword ptr [0xa927a8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11085736) /* 0xa927a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a87039  7409                   -je 0xa87044
    if (cpu.flags.zf)
    {
        goto L_0x00a87044;
    }
    // 00a8703b  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8703c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8703d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8703e  ff15a827a900           -call dword ptr [0xa927a8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085736) /* 0xa927a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a87044:
    // 00a87044  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00a87049  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8704b  e82c0f0000             -call 0xa87f7c
    cpu.esp -= 4;
    sub_a87f7c(app, cpu);
    if (cpu.terminate) return;
    // 00a87050  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a87055  e892180000             -call 0xa888ec
    cpu.esp -= 4;
    sub_a888ec(app, cpu);
    if (cpu.terminate) return;
    // 00a8705a  ff0d6038a900           -dec dword ptr [0xa93860]
    (*app->getMemory<x86::reg32>(x86::reg32(11090016) /* 0xa93860 */))--;
L_0x00a87060:
    // 00a87060  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a87062:
    // 00a87062  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87063  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87064  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87065  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87066  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 */
void sub_a8706a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8706a  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8706b  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a8706d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8706e  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8706f  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a87070  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a87071  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a87074  8a6518                 -mov ah, byte ptr [ebp + 0x18]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00a87077  80fc01                 +cmp ah, 1
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
    // 00a8707a  772f                   -ja 0xa870ab
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a870ab;
    }
    // 00a8707c  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a8707e  7524                   -jne 0xa870a4
    if (!cpu.flags.zf)
    {
        goto L_0x00a870a4;
    }
    // 00a87080  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00a87082  dc5d10                 +fcomp qword ptr [ebp + 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(cpu.ebp + x86::reg32(16) /* 0x10 */));
    cpu.fpu.pop();
    // 00a87085  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00a87087  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a87088  730a                   -jae 0xa87094
    if (!cpu.flags.cf)
    {
        goto L_0x00a87094;
    }
    // 00a8708a  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a8708c  894de8                 -mov dword ptr [ebp - 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 00a8708f  894dec                 -mov dword ptr [ebp - 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 00a87092  eb4f                   -jmp 0xa870e3
    goto L_0x00a870e3;
L_0x00a87094:
    // 00a87094  7607                   -jbe 0xa8709d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8709d;
    }
    // 00a87096  b847800000             -mov eax, 0x8047
    cpu.eax = 32839 /*0x8047*/;
    // 00a8709b  eb38                   -jmp 0xa870d5
    goto L_0x00a870d5;
L_0x00a8709d:
    // 00a8709d  b847400000             -mov eax, 0x4047
    cpu.eax = 16455 /*0x4047*/;
    // 00a870a2  eb31                   -jmp 0xa870d5
    goto L_0x00a870d5;
L_0x00a870a4:
    // 00a870a4  b847200000             -mov eax, 0x2047
    cpu.eax = 8263 /*0x2047*/;
    // 00a870a9  eb2a                   -jmp 0xa870d5
    goto L_0x00a870d5;
L_0x00a870ab:
    // 00a870ab  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00a870ad  dc5d10                 +fcomp qword ptr [ebp + 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(cpu.ebp + x86::reg32(16) /* 0x10 */));
    cpu.fpu.pop();
    // 00a870b0  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00a870b2  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a870b3  720a                   -jb 0xa870bf
    if (cpu.flags.cf)
    {
        goto L_0x00a870bf;
    }
    // 00a870b5  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a870b7  8955e8                 -mov dword ptr [ebp - 0x18], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 00a870ba  8955ec                 -mov dword ptr [ebp - 0x14], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 00a870bd  eb24                   -jmp 0xa870e3
    goto L_0x00a870e3;
L_0x00a870bf:
    // 00a870bf  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00a870c1  dc5d08                 +fcomp qword ptr [ebp + 8]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    cpu.fpu.pop();
    // 00a870c4  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00a870c6  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a870c7  7307                   -jae 0xa870d0
    if (!cpu.flags.cf)
    {
        goto L_0x00a870d0;
    }
    // 00a870c9  b807810000             -mov eax, 0x8107
    cpu.eax = 33031 /*0x8107*/;
    // 00a870ce  eb05                   -jmp 0xa870d5
    goto L_0x00a870d5;
L_0x00a870d0:
    // 00a870d0  b807110000             -mov eax, 0x1107
    cpu.eax = 4359 /*0x1107*/;
L_0x00a870d5:
    // 00a870d5  8d5d10                 -lea ebx, [ebp + 0x10]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00a870d8  8d5508                 -lea edx, [ebp + 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a870db  e8a81b0000             -call 0xa88c88
    cpu.esp -= 4;
    sub_a88c88(app, cpu);
    if (cpu.terminate) return;
    // 00a870e0  dd5de8                 -fstp qword ptr [ebp - 0x18]
    *app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a870e3:
    // 00a870e3  dd45e8                 -fld qword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 00a870e6  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a870e9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a870ea  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a870eb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a870ec  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a870ed  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a870ee  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x00 */
void sub_a870f2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a870f2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a870f3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a870f5  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a870f8  eb31                   -jmp 0xa8712b
    return sub_a8712b(app, cpu);
}

/* align: skip  */
void sub_a870fa(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a870fa  b004                   -mov al, 4
    cpu.al = 4 /*0x4*/;
    // 00a870fc  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a870fd  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a870ff  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a87102  dc159426a900           +fcom qword ptr [0xa92694]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(11085460) /* 0xa92694 */));
    // 00a87108  9b                     -wait 
    /*nothing*/;
    // 00a87109  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 00a8710c  9b                     -wait 
    /*nothing*/;
    // 00a8710d  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 00a87110  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a87111  7618                   -jbe 0xa8712b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8712b;
    }
    // 00a87113  3c07                   +cmp al, 7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a87115  740e                   -je 0xa87125
    if (cpu.flags.zf)
    {
        goto L_0x00a87125;
    }
    // 00a87117  dd5df0                 +fstp qword ptr [ebp - 0x10]
    *app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8711a  8945f8                 -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00a8711d  8955fc                 -mov dword ptr [ebp - 4], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00a87120  e83e1c0000             -call 0xa88d63
    cpu.esp -= 4;
    sub_a88d63(app, cpu);
    if (cpu.terminate) return;
L_0x00a87125:
    // 00a87125  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00a87127  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a87129  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8712a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8712b:
    // 00a8712b  dc159c26a900           +fcom qword ptr [0xa9269c]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(11085468) /* 0xa9269c */));
    // 00a87131  9b                     -wait 
    /*nothing*/;
    // 00a87132  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 00a87135  9b                     -wait 
    /*nothing*/;
    // 00a87136  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 00a87139  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a8713a  7704                   -ja 0xa87140
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a87140;
    }
    // 00a8713c  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00a8713e  eb14                   -jmp 0xa87154
    goto L_0x00a87154;
L_0x00a87140:
    // 00a87140  d9ea                   -fldl2e 
    cpu.fpu.push(1.4426950408889634);
    // 00a87142  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a87144  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a87146  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 00a87148  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a8714a  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 00a8714c  d9f0                   -f2xm1 
    cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));
    // 00a8714e  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00a87150  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a87152  d9fd                   -fscale 
    cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));
L_0x00a87154:
    // 00a87154  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87156  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00a87158  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a8715a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8715b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a870fc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a870fc;
    // 00a870fa  b004                   -mov al, 4
    cpu.al = 4 /*0x4*/;
L_entry_0x00a870fc:
    // 00a870fc  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a870fd  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a870ff  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a87102  dc159426a900           +fcom qword ptr [0xa92694]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(11085460) /* 0xa92694 */));
    // 00a87108  9b                     -wait 
    /*nothing*/;
    // 00a87109  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 00a8710c  9b                     -wait 
    /*nothing*/;
    // 00a8710d  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 00a87110  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a87111  7618                   -jbe 0xa8712b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8712b;
    }
    // 00a87113  3c07                   +cmp al, 7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a87115  740e                   -je 0xa87125
    if (cpu.flags.zf)
    {
        goto L_0x00a87125;
    }
    // 00a87117  dd5df0                 +fstp qword ptr [ebp - 0x10]
    *app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8711a  8945f8                 -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00a8711d  8955fc                 -mov dword ptr [ebp - 4], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00a87120  e83e1c0000             -call 0xa88d63
    cpu.esp -= 4;
    sub_a88d63(app, cpu);
    if (cpu.terminate) return;
L_0x00a87125:
    // 00a87125  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00a87127  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a87129  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8712a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8712b:
    // 00a8712b  dc159c26a900           +fcom qword ptr [0xa9269c]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(11085468) /* 0xa9269c */));
    // 00a87131  9b                     -wait 
    /*nothing*/;
    // 00a87132  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 00a87135  9b                     -wait 
    /*nothing*/;
    // 00a87136  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 00a87139  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a8713a  7704                   -ja 0xa87140
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a87140;
    }
    // 00a8713c  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00a8713e  eb14                   -jmp 0xa87154
    goto L_0x00a87154;
L_0x00a87140:
    // 00a87140  d9ea                   -fldl2e 
    cpu.fpu.push(1.4426950408889634);
    // 00a87142  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a87144  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a87146  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 00a87148  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a8714a  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 00a8714c  d9f0                   -f2xm1 
    cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));
    // 00a8714e  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00a87150  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a87152  d9fd                   -fscale 
    cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));
L_0x00a87154:
    // 00a87154  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87156  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00a87158  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a8715a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8715b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8712b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a8712b;
    // 00a870fa  b004                   -mov al, 4
    cpu.al = 4 /*0x4*/;
    // 00a870fc  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a870fd  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a870ff  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a87102  dc159426a900           +fcom qword ptr [0xa92694]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(11085460) /* 0xa92694 */));
    // 00a87108  9b                     -wait 
    /*nothing*/;
    // 00a87109  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 00a8710c  9b                     -wait 
    /*nothing*/;
    // 00a8710d  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 00a87110  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a87111  7618                   -jbe 0xa8712b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8712b;
    }
    // 00a87113  3c07                   +cmp al, 7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a87115  740e                   -je 0xa87125
    if (cpu.flags.zf)
    {
        goto L_0x00a87125;
    }
    // 00a87117  dd5df0                 +fstp qword ptr [ebp - 0x10]
    *app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8711a  8945f8                 -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00a8711d  8955fc                 -mov dword ptr [ebp - 4], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00a87120  e83e1c0000             -call 0xa88d63
    cpu.esp -= 4;
    sub_a88d63(app, cpu);
    if (cpu.terminate) return;
L_0x00a87125:
    // 00a87125  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00a87127  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a87129  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8712a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8712b:
L_entry_0x00a8712b:
    // 00a8712b  dc159c26a900           +fcom qword ptr [0xa9269c]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(11085468) /* 0xa9269c */));
    // 00a87131  9b                     -wait 
    /*nothing*/;
    // 00a87132  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 00a87135  9b                     -wait 
    /*nothing*/;
    // 00a87136  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 00a87139  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a8713a  7704                   -ja 0xa87140
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a87140;
    }
    // 00a8713c  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00a8713e  eb14                   -jmp 0xa87154
    goto L_0x00a87154;
L_0x00a87140:
    // 00a87140  d9ea                   -fldl2e 
    cpu.fpu.push(1.4426950408889634);
    // 00a87142  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a87144  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a87146  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 00a87148  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a8714a  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 00a8714c  d9f0                   -f2xm1 
    cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));
    // 00a8714e  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00a87150  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a87152  d9fd                   -fscale 
    cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));
L_0x00a87154:
    // 00a87154  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87156  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00a87158  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a8715a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8715b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8715c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8715c  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00a87160  e895ffffff             -call 0xa870fa
    cpu.esp -= 4;
    sub_a870fa(app, cpu);
    if (cpu.terminate) return;
    // 00a87165  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void sub_a87168(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87168  db6c2410               -fld xword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00a8716c  db6c2404               -fld xword ptr [esp + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(4) /* 0x4 */)));
L_0x00a87170:
    // 00a87170  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a87174  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a87176  0f8386000000           -jae 0xa87202
    if (!cpu.flags.cf)
    {
        goto L_0x00a87202;
    }
    // 00a8717c  350000000e             -xor eax, 0xe000000
    cpu.eax ^= x86::reg32(x86::sreg32(234881024 /*0xe000000*/));
    // 00a87181  a90000000e             +test eax, 0xe000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 234881024 /*0xe000000*/));
    // 00a87186  7403                   -je 0xa8718b
    if (cpu.flags.zf)
    {
        goto L_0x00a8718b;
    }
    // 00a87188  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a8718a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8718b:
    // 00a8718b  c1e81c                 -shr eax, 0x1c
    cpu.eax >>= 28 /*0x1c*/ % 32;
    // 00a8718e  80b8742da90000         +cmp byte ptr [eax + 0xa92d74], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11087220) /* 0xa92d74 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a87195  7503                   -jne 0xa8719a
    if (!cpu.flags.zf)
    {
        goto L_0x00a8719a;
    }
    // 00a87197  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a87199  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8719a:
    // 00a8719a  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a8719e  25ff7f0000             +and eax, 0x7fff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/))));
    // 00a871a3  7467                   -je 0xa8720c
    if (cpu.flags.zf)
    {
        goto L_0x00a8720c;
    }
    // 00a871a5  3dff7f0000             +cmp eax, 0x7fff
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
    // 00a871aa  7460                   -je 0xa8720c
    if (cpu.flags.zf)
    {
        goto L_0x00a8720c;
    }
    // 00a871ac  d97c241c               -fnstcw word ptr [esp + 0x1c]
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.fpu.control.word;
    // 00a871b0  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a871b4  0d3f030000             -or eax, 0x33f
    cpu.eax |= x86::reg32(x86::sreg32(831 /*0x33f*/));
    // 00a871b9  25fff30000             -and eax, 0xf3ff
    cpu.eax &= x86::reg32(x86::sreg32(62463 /*0xf3ff*/));
    // 00a871be  89442420               -mov dword ptr [esp + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00a871c2  d96c2420               -fldcw word ptr [esp + 0x20]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a871c6  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a871ca  25ff7f0000             -and eax, 0x7fff
    cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/));
    // 00a871cf  83f801                 +cmp eax, 1
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
    // 00a871d2  7417                   -je 0xa871eb
    if (cpu.flags.zf)
    {
        goto L_0x00a871eb;
    }
    // 00a871d4  d80d842da900           -fmul dword ptr [0xa92d84]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11087236) /* 0xa92d84 */));
    // 00a871da  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a871dc  d80d842da900           -fmul dword ptr [0xa92d84]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11087236) /* 0xa92d84 */));
    // 00a871e2  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a871e4  d96c241c               -fldcw word ptr [esp + 0x1c]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a871e8  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a871ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a871eb:
    // 00a871eb  d80d882da900           -fmul dword ptr [0xa92d88]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11087240) /* 0xa92d88 */));
    // 00a871f1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a871f3  d80d882da900           -fmul dword ptr [0xa92d88]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11087240) /* 0xa92d88 */));
    // 00a871f9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a871fb  d96c241c               -fldcw word ptr [esp + 0x1c]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a871ff  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a87201  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a87202:
    // 00a87202  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a87206  0b442408               +or eax, dword ptr [esp + 8]
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)))));
    // 00a8720a  7503                   -jne 0xa8720f
    if (!cpu.flags.zf)
    {
        goto L_0x00a8720f;
    }
L_0x00a8720c:
    // 00a8720c  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a8720e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8720f:
    // 00a8720f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a87213  25ff7f0000             +and eax, 0x7fff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/))));
    // 00a87218  75f2                   -jne 0xa8720c
    if (!cpu.flags.zf)
    {
        goto L_0x00a8720c;
    }
    // 00a8721a  d97c241c               -fnstcw word ptr [esp + 0x1c]
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.fpu.control.word;
    // 00a8721e  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a87222  0d3f030000             -or eax, 0x33f
    cpu.eax |= x86::reg32(x86::sreg32(831 /*0x33f*/));
    // 00a87227  25fff30000             -and eax, 0xf3ff
    cpu.eax &= x86::reg32(x86::sreg32(62463 /*0xf3ff*/));
    // 00a8722c  89442420               -mov dword ptr [esp + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00a87230  d96c2420               -fldcw word ptr [esp + 0x20]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a87234  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a87238  25ff7f0000             +and eax, 0x7fff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/))));
    // 00a8723d  7411                   -je 0xa87250
    if (cpu.flags.zf)
    {
        goto L_0x00a87250;
    }
    // 00a8723f  3dff7f0000             +cmp eax, 0x7fff
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
    // 00a87244  7432                   -je 0xa87278
    if (cpu.flags.zf)
    {
        goto L_0x00a87278;
    }
    // 00a87246  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a8724a  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8724c  732a                   -jae 0xa87278
    if (!cpu.flags.cf)
    {
        goto L_0x00a87278;
    }
    // 00a8724e  eb08                   -jmp 0xa87258
    goto L_0x00a87258;
L_0x00a87250:
    // 00a87250  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a87254  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a87256  7220                   -jb 0xa87278
    if (cpu.flags.cf)
    {
        goto L_0x00a87278;
    }
L_0x00a87258:
    // 00a87258  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a8725a  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8725c  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a8725e  d80d8c2da900           +fmul dword ptr [0xa92d8c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(11087244) /* 0xa92d8c */));
    // 00a87264  db7c2404               +fstp xword ptr [esp + 4]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87268  db6c2410               +fld xword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00a8726c  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a8726e  9b                     -wait 
    /*nothing*/;
    // 00a8726f  d96c241c               -fldcw word ptr [esp + 0x1c]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a87273  e9f8feffff             -jmp 0xa87170
    goto L_0x00a87170;
L_0x00a87278:
    // 00a87278  d96c241c               -fldcw word ptr [esp + 0x1c]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a8727c  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a8727e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8727f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a8727f  83ec2c                 +sub esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a87282  ff2485902da900         -jmp dword ptr [eax*4 + 0xa92d90]
    cpu.ip = *app->getMemory<x86::reg32>(11087248 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a87289:
    // 00a87289  d8f0                   -fdiv st(0)
    cpu.fpu.st(0) /= x86::Float(cpu.fpu.st(0));
    // 00a8728b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8728e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a8728f:
    // 00a8728f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87292  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00a87294:
    // 00a87294  d8f8                   -fdivr st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0)) / cpu.fpu.st(0);
    // 00a87296  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87299  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a8729a:
    // 00a8729a  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8729d  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00a8729f:
    // 00a8729f  d8f0                   -fdiv st(0)
    cpu.fpu.st(0) /= x86::Float(cpu.fpu.st(0));
    // 00a872a1  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a872a4  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a872a5:
    // 00a872a5  def8                   -fdivp st(0)
    cpu.fpu.st(0) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a872a7  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a872aa  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a872ab:
    // 00a872ab  d8f8                   -fdivr st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0)) / cpu.fpu.st(0);
    // 00a872ad  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a872b0  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a872b1:
    // 00a872b1  def0                   -fdivrp st(0)
    cpu.fpu.st(0) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a872b3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a872b6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a872b7:
    // 00a872b7  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a872bb  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a872bd  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a872c0  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a872c4  e89ffeffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a872c9  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00a872cd  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a872cf  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a872d2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a872d3:
    // 00a872d3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a872d6  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00a872d8:
    // 00a872d8  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a872db  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a872df  e884feffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a872e4  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a872e8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a872ea  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a872ed  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a872ee:
    // 00a872ee  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a872f1  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00a872f3:
    // 00a872f3  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a872f5  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a872f9  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a872fb  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a872fe  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87302  e861feffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a87307  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00a8730b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8730e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a8730f:
    // 00a8730f  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87312  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87316  e84dfeffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a8731b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8731e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a8731f:
    // 00a8731f  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87323  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87326  e83dfeffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a8732b  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a8732f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87332  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a87333:
    // 00a87333  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87337  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8733a  e829feffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a8733f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87342  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a87343:
    // 00a87343  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87347  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a87349  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a8734b  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8734e  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87352  e811feffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a87357  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a87359  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00a8735d  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00a8735f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87362  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a87363:
    // 00a87363  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87366  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00a87368:
    // 00a87368  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8736b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a8736d  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87371  e8f2fdffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a87376  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a87378  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a8737c  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00a8737e  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87381  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a87382:
    // 00a87382  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87385  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00a87387:
    // 00a87387  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00a87389  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8738d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a8738f  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a87391  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87394  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87398  e8cbfdffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a8739d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a8739f  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00a873a3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a873a6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a873a7:
    // 00a873a7  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a873aa  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a873ac  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a873b0  e8b3fdffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a873b5  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a873b7  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a873ba  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a873bb:
    // 00a873bb  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a873bf  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a873c1  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a873c4  e89ffdffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a873c9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a873cb  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a873cf  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a873d2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a873d3:
    // 00a873d3  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a873d7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a873d9  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a873dc  e887fdffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a873e1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a873e3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a873e6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a873e7:
    // 00a873e7  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a873eb  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00a873ed  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a873ef  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a873f2  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a873f6  e86dfdffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a873fb  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00a873fd  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00a87401  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00a87403  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87406  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a87407:
    // 00a87407  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8740a  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00a8740c:
    // 00a8740c  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8740f  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00a87411  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87415  e84efdffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a8741a  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00a8741c  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a87420  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00a87422  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87425  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a87426:
    // 00a87426  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87429  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00a8742b:
    // 00a8742b  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00a8742d  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87431  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00a87433  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a87435  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87438  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8743c  e827fdffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a87441  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00a87443  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00a87447  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8744a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a8744b:
    // 00a8744b  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8744e  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00a87450  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87454  e80ffdffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a87459  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00a8745b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8745e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a8745f:
    // 00a8745f  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87463  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00a87465  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87468  e8fbfcffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a8746d  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00a8746f  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a87473  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87476  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a87477:
    // 00a87477  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8747b  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00a8747d  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87480  e8e3fcffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a87485  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00a87487  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8748a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a8748b:
    // 00a8748b  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8748f  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00a87491  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a87493  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87496  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8749a  e8c9fcffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a8749f  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00a874a1  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00a874a5  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00a874a7  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a874aa  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a874ab:
    // 00a874ab  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a874ae  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00a874b0:
    // 00a874b0  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a874b3  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00a874b5  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a874b9  e8aafcffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a874be  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00a874c0  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a874c4  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00a874c6  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a874c9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a874ca:
    // 00a874ca  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a874cd  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00a874cf:
    // 00a874cf  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00a874d1  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a874d5  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00a874d7  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a874d9  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a874dc  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a874e0  e883fcffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a874e5  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00a874e7  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00a874eb  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a874ee  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a874ef:
    // 00a874ef  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a874f2  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00a874f4  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a874f8  e86bfcffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a874fd  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00a874ff  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87502  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a87503:
    // 00a87503  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87507  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00a87509  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8750c  e857fcffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a87511  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00a87513  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a87517  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8751a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a8751b:
    // 00a8751b  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8751f  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00a87521  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87524  e83ffcffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a87529  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00a8752b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8752e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a8752f:
    // 00a8752f  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87533  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00a87535  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a87537  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8753a  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8753e  e825fcffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a87543  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00a87545  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00a87549  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00a8754b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8754e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a8754f:
    // 00a8754f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87552  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00a87554:
    // 00a87554  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87557  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00a87559  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8755d  e806fcffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a87562  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00a87564  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a87568  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00a8756a  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8756d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a8756e:
    // 00a8756e  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87571  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00a87573:
    // 00a87573  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00a87575  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87579  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00a8757b  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a8757d  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87580  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87584  e8dffbffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a87589  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00a8758b  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00a8758f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87592  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a87593:
    // 00a87593  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87596  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00a87598  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8759c  e8c7fbffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a875a1  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00a875a3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a875a6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a875a7:
    // 00a875a7  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a875ab  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00a875ad  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a875b0  e8b3fbffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a875b5  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00a875b7  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a875bb  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a875be  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a875bf:
    // 00a875bf  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a875c3  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00a875c5  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a875c8  e89bfbffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a875cd  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00a875cf  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a875d2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a875d3:
    // 00a875d3  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a875d7  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00a875d9  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a875db  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a875de  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a875e2  e881fbffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a875e7  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00a875e9  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00a875ed  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00a875ef  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a875f2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a875f3:
    // 00a875f3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a875f6  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00a875f8:
    // 00a875f8  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a875fb  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00a875fd  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87601  e862fbffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a87606  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00a87608  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a8760c  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00a8760e  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87611  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a87612:
    // 00a87612  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87615  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00a87617:
    // 00a87617  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00a87619  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8761d  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00a8761f  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a87621  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87624  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87628  e83bfbffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a8762d  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00a8762f  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00a87633  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87636  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a87637:
    // 00a87637  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8763a  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00a8763c  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87640  e823fbffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a87645  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00a87647  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8764a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a8764b:
    // 00a8764b  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8764f  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00a87651  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87654  e80ffbffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a87659  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00a8765b  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a8765f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87662  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a87663:
    // 00a87663  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87667  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00a87669  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8766c  e8f7faffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a87671  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00a87673  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87676  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a87677:
    // 00a87677  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8767b  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00a8767d  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a8767f  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87682  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87686  e8ddfaffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a8768b  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00a8768d  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00a87691  d9cf                   -fxch st(7)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(7);
        cpu.fpu.st(7) = tmp;
    }
    // 00a87693  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87696  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a87697:
    // 00a87697  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8769a  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00a8769c:
    // 00a8769c  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8769f  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00a876a1  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a876a5  e8befaffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a876aa  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00a876ac  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a876b0  d9cf                   -fxch st(7)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(7);
        cpu.fpu.st(7) = tmp;
    }
    // 00a876b2  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a876b5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a876b6:
    // 00a876b6  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a876b9  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00a876bb:
    // 00a876bb  d9cf                   -fxch st(7)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(7);
        cpu.fpu.st(7) = tmp;
    }
    // 00a876bd  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a876c1  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00a876c3  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a876c5  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a876c8  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a876cc  e897faffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a876d1  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00a876d3  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00a876d7  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a876da  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a876db:
    // 00a876db  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a876de  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00a876e0  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a876e4  e87ffaffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a876e9  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00a876eb  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a876ee  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a876ef:
    // 00a876ef  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a876f3  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00a876f5  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a876f8  e86bfaffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a876fd  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00a876ff  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a87703  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87706  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00a87707:
    // 00a87707  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8770b  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00a8770d  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87710  e853faffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a87715  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00a87717  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8771a  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_a8771b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8771b  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8771e  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87721  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87725  e83efaffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a8772a  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8772d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8772e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8772e  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87731  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87735  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87738  e82bfaffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a8773d  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87740  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a87741(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87741  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87744  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87748  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8774b  e818faffff             -call 0xa87168
    cpu.esp -= 4;
    sub_a87168(app, cpu);
    if (cpu.terminate) return;
    // 00a87750  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a87753  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a87754(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87754  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a87755  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a87759  250000807f             -and eax, 0x7f800000
    cpu.eax &= x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
    // 00a8775e  3d0000807f             +cmp eax, 0x7f800000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a87763  7433                   -je 0xa87798
    if (cpu.flags.zf)
    {
        goto L_0x00a87798;
    }
    // 00a87765  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00a87767  2500380000             +and eax, 0x3800
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(14336 /*0x3800*/))));
    // 00a8776c  740d                   -je 0xa8777b
    if (cpu.flags.zf)
    {
        goto L_0x00a8777b;
    }
    // 00a8776e  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00a87772  e8a4ffffff             -call 0xa8771b
    cpu.esp -= 4;
    sub_a8771b(app, cpu);
    if (cpu.terminate) return;
    // 00a87777  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87778  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a8777b:
    // 00a8777b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a8777d  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a87780  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87783  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00a87787  e88fffffff             -call 0xa8771b
    cpu.esp -= 4;
    sub_a8771b(app, cpu);
    if (cpu.terminate) return;
    // 00a8778c  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 00a8778f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a87791  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a87794  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87795  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a87798:
    // 00a87798  d8742408               -fdiv dword ptr [esp + 8]
    cpu.fpu.st(0) /= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00a8779c  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8779d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void sub_a877a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a877a0  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a877a1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a877a5  250000f07f             -and eax, 0x7ff00000
    cpu.eax &= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 00a877aa  3d0000f07f             +cmp eax, 0x7ff00000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a877af  7433                   -je 0xa877e4
    if (cpu.flags.zf)
    {
        goto L_0x00a877e4;
    }
    // 00a877b1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00a877b3  2500380000             +and eax, 0x3800
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(14336 /*0x3800*/))));
    // 00a877b8  740d                   -je 0xa877c7
    if (cpu.flags.zf)
    {
        goto L_0x00a877c7;
    }
    // 00a877ba  dd442408               -fld qword ptr [esp + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00a877be  e858ffffff             -call 0xa8771b
    cpu.esp -= 4;
    sub_a8771b(app, cpu);
    if (cpu.terminate) return;
    // 00a877c3  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a877c4  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a877c7:
    // 00a877c7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a877c9  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a877cc  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a877cf  dd442414               -fld qword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00a877d3  e843ffffff             -call 0xa8771b
    cpu.esp -= 4;
    sub_a8771b(app, cpu);
    if (cpu.terminate) return;
    // 00a877d8  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 00a877db  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a877dd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a877e0  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a877e1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a877e4:
    // 00a877e4  dc742408               -fdiv qword ptr [esp + 8]
    cpu.fpu.st(0) /= x86::Float(*app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00a877e8  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a877e9  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void sub_a877ec(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a877ec  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a877ed  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a877f1  250000807f             -and eax, 0x7f800000
    cpu.eax &= x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
    // 00a877f6  3d0000807f             +cmp eax, 0x7f800000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a877fb  7433                   -je 0xa87830
    if (cpu.flags.zf)
    {
        goto L_0x00a87830;
    }
    // 00a877fd  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00a877ff  2500380000             +and eax, 0x3800
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(14336 /*0x3800*/))));
    // 00a87804  740d                   -je 0xa87813
    if (cpu.flags.zf)
    {
        goto L_0x00a87813;
    }
    // 00a87806  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00a8780a  e81fffffff             -call 0xa8772e
    cpu.esp -= 4;
    sub_a8772e(app, cpu);
    if (cpu.terminate) return;
    // 00a8780f  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87810  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a87813:
    // 00a87813  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a87815  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a87818  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8781b  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00a8781f  e80affffff             -call 0xa8772e
    cpu.esp -= 4;
    sub_a8772e(app, cpu);
    if (cpu.terminate) return;
    // 00a87824  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 00a87827  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a87829  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a8782c  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8782d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a87830:
    // 00a87830  d87c2408               -fdivr dword ptr [esp + 8]
    cpu.fpu.st(0) = x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)) / cpu.fpu.st(0);
    // 00a87834  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87835  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void sub_a87838(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87838  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a87839  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a8783d  250000f07f             -and eax, 0x7ff00000
    cpu.eax &= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 00a87842  3d0000f07f             +cmp eax, 0x7ff00000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a87847  7433                   -je 0xa8787c
    if (cpu.flags.zf)
    {
        goto L_0x00a8787c;
    }
    // 00a87849  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00a8784b  2500380000             +and eax, 0x3800
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(14336 /*0x3800*/))));
    // 00a87850  740d                   -je 0xa8785f
    if (cpu.flags.zf)
    {
        goto L_0x00a8785f;
    }
    // 00a87852  dd442408               -fld qword ptr [esp + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00a87856  e8d3feffff             -call 0xa8772e
    cpu.esp -= 4;
    sub_a8772e(app, cpu);
    if (cpu.terminate) return;
    // 00a8785b  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8785c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a8785f:
    // 00a8785f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a87861  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a87864  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a87867  dd442414               -fld qword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00a8786b  e8befeffff             -call 0xa8772e
    cpu.esp -= 4;
    sub_a8772e(app, cpu);
    if (cpu.terminate) return;
    // 00a87870  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 00a87873  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a87875  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a87878  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87879  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a8787c:
    // 00a8787c  dc7c2408               -fdivr qword ptr [esp + 8]
    cpu.fpu.st(0) = x86::Float(*app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)) / cpu.fpu.st(0);
    // 00a87880  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87881  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a87890(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87890  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a87891  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a87893  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a87895  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00a87897  e844150000             -call 0xa88de0
    cpu.esp -= 4;
    sub_a88de0(app, cpu);
    if (cpu.terminate) return;
    // 00a8789c  ff4310                 -inc dword ptr [ebx + 0x10]
    (*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */))++;
    // 00a8789f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a878a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a878a4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a878a4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a878a5  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a878a6  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a878a7  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a878a8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a878aa  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00a878ad  ff15ac26a900           -call dword ptr [0xa926ac]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085484) /* 0xa926ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a878b3  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a878b6  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a878b9  83f901                 +cmp ecx, 1
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
    // 00a878bc  741b                   -je 0xa878d9
    if (cpu.flags.zf)
    {
        goto L_0x00a878d9;
    }
    // 00a878be  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a878c0  7410                   -je 0xa878d2
    if (cpu.flags.zf)
    {
        goto L_0x00a878d2;
    }
    // 00a878c2  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00a878c5  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a878cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a878cd  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a878ce  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a878cf  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a878d0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a878d1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a878d2:
    // 00a878d2  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00a878d9:
    // 00a878d9  8a660c                 -mov ah, byte ptr [esi + 0xc]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a878dc  80e4cf                 -and ah, 0xcf
    cpu.ah &= x86::reg8(x86::sreg8(207 /*0xcf*/));
    // 00a878df  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a878e2  88660c                 -mov byte ptr [esi + 0xc], ah
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ah;
    // 00a878e5  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a878e8  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a878eb  83e530                 -and ebp, 0x30
    cpu.ebp &= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a878ee  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a878f0  7507                   -jne 0xa878f9
    if (!cpu.flags.zf)
    {
        goto L_0x00a878f9;
    }
    // 00a878f2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a878f4  e807160000             -call 0xa88f00
    cpu.esp -= 4;
    sub_a88f00(app, cpu);
    if (cpu.terminate) return;
L_0x00a878f9:
    // 00a878f9  8a4e0d                 -mov cl, byte ptr [esi + 0xd]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 00a878fc  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a878fe  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 00a87901  7414                   -je 0xa87917
    if (cpu.flags.zf)
    {
        goto L_0x00a87917;
    }
    // 00a87903  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 00a87905  80e5fa                 -and ch, 0xfa
    cpu.ch &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 00a87908  88e8                   -mov al, ch
    cpu.al = cpu.ch;
    // 00a8790a  886e0d                 -mov byte ptr [esi + 0xd], ch
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.ch;
    // 00a8790d  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a8790f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a87914  88460d                 -mov byte ptr [esi + 0xd], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.al;
L_0x00a87917:
    // 00a87917  b99078a800             -mov ecx, 0xa87890
    cpu.ecx = 11040912 /*0xa87890*/;
    // 00a8791c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8791e  e86d160000             -call 0xa88f90
    cpu.esp -= 4;
    sub_a88f90(app, cpu);
    if (cpu.terminate) return;
    // 00a87923  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a87925  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a87927  7418                   -je 0xa87941
    if (cpu.flags.zf)
    {
        goto L_0x00a87941;
    }
    // 00a87929  8a660d                 -mov ah, byte ptr [esi + 0xd]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 00a8792c  80e4fa                 -and ah, 0xfa
    cpu.ah &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 00a8792f  88e3                   -mov bl, ah
    cpu.bl = cpu.ah;
    // 00a87931  88660d                 -mov byte ptr [esi + 0xd], ah
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 00a87934  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00a87937  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a87939  885e0d                 -mov byte ptr [esi + 0xd], bl
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 00a8793c  e83f010000             -call 0xa87a80
    cpu.esp -= 4;
    sub_a87a80(app, cpu);
    if (cpu.terminate) return;
L_0x00a87941:
    // 00a87941  f6460c20               +test byte ptr [esi + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 00a87945  7405                   -je 0xa8794c
    if (cpu.flags.zf)
    {
        goto L_0x00a8794c;
    }
    // 00a87947  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00a8794c:
    // 00a8794c  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a8794f  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a87951  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00a87954  897e0c                 -mov dword ptr [esi + 0xc], edi
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00a87957  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8795d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8795f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87960  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87961  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87962  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87963  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a87970(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87970  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a87971  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a87972  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a87973  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a87974  8a25a123a900           -mov ah, byte ptr [0xa923a1]
    cpu.ah = *app->getMemory<x86::reg8>(x86::reg32(11084705) /* 0xa923a1 */);
    // 00a8797a  80e4f8                 -and ah, 0xf8
    cpu.ah &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a8797d  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 00a8797f  8825a123a900           -mov byte ptr [0xa923a1], ah
    *app->getMemory<x86::reg8>(x86::reg32(11084705) /* 0xa923a1 */) = cpu.ah;
    // 00a87985  80ca04                 -or dl, 4
    cpu.dl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00a87988  8815a123a900           -mov byte ptr [0xa923a1], dl
    *app->getMemory<x86::reg8>(x86::reg32(11084705) /* 0xa923a1 */) = cpu.dl;
    // 00a8798e  8b156c23a900           -mov edx, dword ptr [0xa9236c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11084652) /* 0xa9236c */);
    // 00a87994  bb6023a900             -mov ebx, 0xa92360
    cpu.ebx = 11084640 /*0xa92360*/;
    // 00a87999  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8799b  7466                   -je 0xa87a03
    if (cpu.flags.zf)
    {
        goto L_0x00a87a03;
    }
L_0x00a8799d:
    // 00a8799d  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 00a879a2  e809f3ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a879a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a879a9  7521                   -jne 0xa879cc
    if (!cpu.flags.zf)
    {
        goto L_0x00a879cc;
    }
    // 00a879ab  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 00a879b0  e8fbf2ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a879b5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a879b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a879b9  7513                   -jne 0xa879ce
    if (!cpu.flags.zf)
    {
        goto L_0x00a879ce;
    }
    // 00a879bb  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a879c0  b8f816a900             -mov eax, 0xa916f8
    cpu.eax = 11081464 /*0xa916f8*/;
    // 00a879c5  e832240000             -call 0xa89dfc
    cpu.esp -= 4;
    sub_a89dfc(app, cpu);
    if (cpu.terminate) return;
    // 00a879ca  eb02                   -jmp 0xa879ce
    goto L_0x00a879ce;
L_0x00a879cc:
    // 00a879cc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00a879ce:
    // 00a879ce  a1b037a900             -mov eax, dword ptr [0xa937b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11089840) /* 0xa937b0 */);
    // 00a879d3  895904                 -mov dword ptr [ecx + 4], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a879d6  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a879d8  894b08                 -mov dword ptr [ebx + 8], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00a879db  c7410800000000         -mov dword ptr [ecx + 8], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a879e2  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a879e5  c6401400               -mov byte ptr [eax + 0x14], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a879e9  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a879ec  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00a879f3  890db037a900           -mov dword ptr [0xa937b0], ecx
    *app->getMemory<x86::reg32>(x86::reg32(11089840) /* 0xa937b0 */) = cpu.ecx;
    // 00a879f9  8b4b26                 -mov ecx, dword ptr [ebx + 0x26]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(38) /* 0x26 */);
    // 00a879fc  83c31a                 -add ebx, 0x1a
    (cpu.ebx) += x86::reg32(x86::sreg32(26 /*0x1a*/));
    // 00a879ff  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a87a01  759a                   -jne 0xa8799d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8799d;
    }
L_0x00a87a03:
    // 00a87a03  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a87a05  8935b437a900           -mov dword ptr [0xa937b4], esi
    *app->getMemory<x86::reg32>(x86::reg32(11089844) /* 0xa937b4 */) = cpu.esi;
    // 00a87a0b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87a0c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87a0d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87a0e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87a0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a87a10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87a10  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a87a12  e80d000000             -call 0xa87a24
    cpu.esp -= 4;
    sub_a87a24(app, cpu);
    if (cpu.terminate) return;
    // 00a87a17  e904250000             -jmp 0xa89f20
    return sub_a89f20(app, cpu);
}

/* align: skip  */
void sub_a87a1c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87a1c  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a87a21  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a87a24  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a87a25  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a87a26  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a87a27  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a87a28  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a87a2a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a87a2d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a87a2f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a87a32  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a87a34  be6023a900             -mov esi, 0xa92360
    cpu.esi = 11084640 /*0xa92360*/;
    // 00a87a39  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a87a3b  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a87a3d  a1b037a900             -mov eax, dword ptr [0xa937b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11089840) /* 0xa937b0 */);
    // 00a87a42  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a87a44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a87a46  742f                   -je 0xa87a77
    if (cpu.flags.zf)
    {
        goto L_0x00a87a77;
    }
L_0x00a87a48:
    // 00a87a48  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a87a4a  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a87a4d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a87a52  f6400d40               +test byte ptr [eax + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 00a87a56  7513                   -jne 0xa87a6b
    if (!cpu.flags.zf)
    {
        goto L_0x00a87a6b;
    }
    // 00a87a58  f6400d08               +test byte ptr [eax + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 00a87a5c  750d                   -jne 0xa87a6b
    if (!cpu.flags.zf)
    {
        goto L_0x00a87a6b;
    }
    // 00a87a5e  39f0                   +cmp eax, esi
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
    // 00a87a60  720f                   -jb 0xa87a71
    if (cpu.flags.cf)
    {
        goto L_0x00a87a71;
    }
    // 00a87a62  3dae23a900             +cmp eax, 0xa923ae
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11084718 /*0xa923ae*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a87a67  7302                   -jae 0xa87a6b
    if (!cpu.flags.cf)
    {
        goto L_0x00a87a6b;
    }
    // 00a87a69  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00a87a6b:
    // 00a87a6b  e824250000             -call 0xa89f94
    cpu.esp -= 4;
    sub_a89f94(app, cpu);
    if (cpu.terminate) return;
    // 00a87a70  43                     -inc ebx
    (cpu.ebx)++;
L_0x00a87a71:
    // 00a87a71  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a87a73  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a87a75  75d1                   -jne 0xa87a48
    if (!cpu.flags.zf)
    {
        goto L_0x00a87a48;
    }
L_0x00a87a77:
    // 00a87a77  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a87a79  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87a7a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87a7b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87a7c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87a7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a87a24(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a87a24;
    // 00a87a1c  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a87a21  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00a87a24:
    // 00a87a24  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a87a25  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a87a26  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a87a27  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a87a28  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a87a2a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a87a2d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a87a2f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a87a32  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a87a34  be6023a900             -mov esi, 0xa92360
    cpu.esi = 11084640 /*0xa92360*/;
    // 00a87a39  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a87a3b  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a87a3d  a1b037a900             -mov eax, dword ptr [0xa937b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11089840) /* 0xa937b0 */);
    // 00a87a42  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a87a44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a87a46  742f                   -je 0xa87a77
    if (cpu.flags.zf)
    {
        goto L_0x00a87a77;
    }
L_0x00a87a48:
    // 00a87a48  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a87a4a  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a87a4d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a87a52  f6400d40               +test byte ptr [eax + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 00a87a56  7513                   -jne 0xa87a6b
    if (!cpu.flags.zf)
    {
        goto L_0x00a87a6b;
    }
    // 00a87a58  f6400d08               +test byte ptr [eax + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 00a87a5c  750d                   -jne 0xa87a6b
    if (!cpu.flags.zf)
    {
        goto L_0x00a87a6b;
    }
    // 00a87a5e  39f0                   +cmp eax, esi
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
    // 00a87a60  720f                   -jb 0xa87a71
    if (cpu.flags.cf)
    {
        goto L_0x00a87a71;
    }
    // 00a87a62  3dae23a900             +cmp eax, 0xa923ae
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11084718 /*0xa923ae*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a87a67  7302                   -jae 0xa87a6b
    if (!cpu.flags.cf)
    {
        goto L_0x00a87a6b;
    }
    // 00a87a69  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00a87a6b:
    // 00a87a6b  e824250000             -call 0xa89f94
    cpu.esp -= 4;
    sub_a89f94(app, cpu);
    if (cpu.terminate) return;
    // 00a87a70  43                     -inc ebx
    (cpu.ebx)++;
L_0x00a87a71:
    // 00a87a71  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a87a73  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a87a75  75d1                   -jne 0xa87a48
    if (!cpu.flags.zf)
    {
        goto L_0x00a87a48;
    }
L_0x00a87a77:
    // 00a87a77  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a87a79  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87a7a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87a7b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87a7c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87a7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_a87a80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87a80  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a87a81  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a87a82  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a87a83  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a87a84  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a87a85  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a87a86  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a87a88  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00a87a8b  ff15ac26a900           -call dword ptr [0xa926ac]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085484) /* 0xa926ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a87a91  8a610d                 -mov ah, byte ptr [ecx + 0xd]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 00a87a94  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a87a96  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 00a87a99  0f847a000000           -je 0xa87b19
    if (cpu.flags.zf)
    {
        goto L_0x00a87b19;
    }
    // 00a87a9f  88e7                   -mov bh, ah
    cpu.bh = cpu.ah;
    // 00a87aa1  80e7ef                 -and bh, 0xef
    cpu.bh &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00a87aa4  8a410c                 -mov al, byte ptr [ecx + 0xc]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a87aa7  88790d                 -mov byte ptr [ecx + 0xd], bh
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 00a87aaa  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00a87aac  0f84a2000000           -je 0xa87b54
    if (cpu.flags.zf)
    {
        goto L_0x00a87b54;
    }
    // 00a87ab2  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a87ab5  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a87ab8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a87aba  0f8494000000           -je 0xa87b54
    if (cpu.flags.zf)
    {
        goto L_0x00a87b54;
    }
    // 00a87ac0  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a87ac3  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a87ac5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a87ac7  0f8487000000           -je 0xa87b54
    if (cpu.flags.zf)
    {
        goto L_0x00a87b54;
    }
L_0x00a87acd:
    // 00a87acd  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a87acf  0f857f000000           -jne 0xa87b54
    if (!cpu.flags.zf)
    {
        goto L_0x00a87b54;
    }
    // 00a87ad5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a87ad7  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a87ad9  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a87adc  e84f260000             -call 0xa8a130
    cpu.esp -= 4;
    sub_a8a130(app, cpu);
    if (cpu.terminate) return;
    // 00a87ae1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a87ae3  83f8ff                 +cmp eax, -1
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
    // 00a87ae6  750d                   -jne 0xa87af5
    if (!cpu.flags.zf)
    {
        goto L_0x00a87af5;
    }
    // 00a87ae8  8a590c                 -mov bl, byte ptr [ecx + 0xc]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a87aeb  80cb20                 +or bl, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 00a87aee  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a87af0  88590c                 -mov byte ptr [ecx + 0xc], bl
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 00a87af3  eb1c                   -jmp 0xa87b11
    goto L_0x00a87b11;
L_0x00a87af5:
    // 00a87af5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a87af7  7518                   -jne 0xa87b11
    if (!cpu.flags.zf)
    {
        goto L_0x00a87b11;
    }
    // 00a87af9  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 00a87afe  e81d270000             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a87b03  8a610c                 -mov ah, byte ptr [ecx + 0xc]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a87b06  80cc20                 -or ah, 0x20
    cpu.ah |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00a87b09  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 00a87b0e  88610c                 -mov byte ptr [ecx + 0xc], ah
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ah;
L_0x00a87b11:
    // 00a87b11  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a87b13  29d6                   +sub esi, edx
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
    // 00a87b15  75b6                   -jne 0xa87acd
    if (!cpu.flags.zf)
    {
        goto L_0x00a87acd;
    }
    // 00a87b17  eb3b                   -jmp 0xa87b54
    goto L_0x00a87b54;
L_0x00a87b19:
    // 00a87b19  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a87b1c  83780800               +cmp dword ptr [eax + 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a87b20  7432                   -je 0xa87b54
    if (cpu.flags.zf)
    {
        goto L_0x00a87b54;
    }
    // 00a87b22  80610cef               -and byte ptr [ecx + 0xc], 0xef
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00a87b26  f6410d20               +test byte ptr [ecx + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 00a87b2a  7528                   -jne 0xa87b54
    if (!cpu.flags.zf)
    {
        goto L_0x00a87b54;
    }
    // 00a87b2c  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a87b2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a87b31  7411                   -je 0xa87b44
    if (cpu.flags.zf)
    {
        goto L_0x00a87b44;
    }
    // 00a87b33  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a87b35  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a87b3a  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a87b3c  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a87b3f  e83c270000             -call 0xa8a280
    cpu.esp -= 4;
    sub_a8a280(app, cpu);
    if (cpu.terminate) return;
L_0x00a87b44:
    // 00a87b44  83f8ff                 +cmp eax, -1
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
    // 00a87b47  750b                   -jne 0xa87b54
    if (!cpu.flags.zf)
    {
        goto L_0x00a87b54;
    }
    // 00a87b49  8a590c                 -mov bl, byte ptr [ecx + 0xc]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a87b4c  80cb20                 -or bl, 0x20
    cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00a87b4f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a87b51  88590c                 -mov byte ptr [ecx + 0xc], bl
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bl;
L_0x00a87b54:
    // 00a87b54  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a87b57  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a87b5a  c7410400000000         -mov dword ptr [ecx + 4], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a87b61  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a87b63  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a87b65  7518                   -jne 0xa87b7f
    if (!cpu.flags.zf)
    {
        goto L_0x00a87b7f;
    }
    // 00a87b67  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a87b6a  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 00a87b6e  740f                   -je 0xa87b7f
    if (cpu.flags.zf)
    {
        goto L_0x00a87b7f;
    }
    // 00a87b70  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a87b73  e888270000             -call 0xa8a300
    cpu.esp -= 4;
    sub_a8a300(app, cpu);
    if (cpu.terminate) return;
    // 00a87b78  83f8ff                 +cmp eax, -1
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
    // 00a87b7b  7502                   -jne 0xa87b7f
    if (!cpu.flags.zf)
    {
        goto L_0x00a87b7f;
    }
    // 00a87b7d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x00a87b7f:
    // 00a87b7f  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a87b82  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a87b88  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a87b8a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87b8b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87b8c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87b8d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87b8e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87b8f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87b90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a87ba0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87ba0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a87ba5  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a87ba8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a87ba9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a87baa  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a87bab  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a87bad  ff15bc26a900           -call dword ptr [0xa926bc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085500) /* 0xa926bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a87bb3  8b15b037a900           -mov edx, dword ptr [0xa937b0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11089840) /* 0xa937b0 */);
    // 00a87bb9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a87bbb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a87bbd  741a                   -je 0xa87bd9
    if (cpu.flags.zf)
    {
        goto L_0x00a87bd9;
    }
L_0x00a87bbf:
    // 00a87bbf  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a87bc2  85480c                 -test dword ptr [eax + 0xc], ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) & cpu.ecx));
    // 00a87bc5  740c                   -je 0xa87bd3
    if (cpu.flags.zf)
    {
        goto L_0x00a87bd3;
    }
    // 00a87bc7  43                     -inc ebx
    (cpu.ebx)++;
    // 00a87bc8  f6400d10               +test byte ptr [eax + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 00a87bcc  7405                   -je 0xa87bd3
    if (cpu.flags.zf)
    {
        goto L_0x00a87bd3;
    }
    // 00a87bce  e8adfeffff             -call 0xa87a80
    cpu.esp -= 4;
    sub_a87a80(app, cpu);
    if (cpu.terminate) return;
L_0x00a87bd3:
    // 00a87bd3  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a87bd5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a87bd7  75e6                   -jne 0xa87bbf
    if (!cpu.flags.zf)
    {
        goto L_0x00a87bbf;
    }
L_0x00a87bd9:
    // 00a87bd9  ff15c026a900           -call dword ptr [0xa926c0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085504) /* 0xa926c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a87bdf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a87be1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87be2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87be3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87be4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a87bf0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87bf0  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a87bf6  05da000000             -add eax, 0xda
    (cpu.eax) += x86::reg32(x86::sreg32(218 /*0xda*/));
    // 00a87bfb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a87bfc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87bfc  a17c38a900             -mov eax, dword ptr [0xa9387c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11090044) /* 0xa9387c */);
    // 00a87c01  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a87c04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a87c04(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a87c04;
    // 00a87bfc  a17c38a900             -mov eax, dword ptr [0xa9387c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11090044) /* 0xa9387c */);
    // 00a87c01  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00a87c04:
    // 00a87c04  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
