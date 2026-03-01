#include <cpu.h>
//#include <intrin.h>
#include <SDL2/SDL_timer.h>

namespace x86
{

void CPU::rdtsc()
{
    edx_eax = SDL_GetTicks();
}

void CPU::cpuid()
{
    switch(eax)
    {
    case 0:
        eax = 1;
        ebx = 0x756e6547;
        edx = 0x49656e69;
        ecx = 0x6c65746e;
        break;
    case 1:
        eax = 0x0510;
        ebx = 0x0000;
        ecx = 0x0000;
        edx = 0x008001BF; // with MMX
        //edx = 0x000001BF; // without MMX
        break;
    default:
        NFS2_ASSERT(false);     
    }
}

}