#include <lib/socket.h>
//#include <winsock.h>
#include <cstdio>
//#include <SDL2/SDL_net.h>

namespace win32
{

static MemMap* s_netToABuffer;

Socket::Socket()
    :   m_address(0x31a26f20)
    ,   m_node(0x0000000000000008)
    ,   m_port(0x0bb9)
{
}

Socket::~Socket()
{
}

x86::reg32 Socket::bind(x86::reg32 /*network*/, x86::reg64 /*node*/, x86::reg16 /*port*/)
{
    return 0;
}

x86::reg32 Socket::netToA(WinApplication* app, x86::reg32 address)
{
    char* buffer = &app->getMemory<char>(s_netToABuffer->getBlockStart());
    sprintf(buffer, "%d.%d.%d.%d", address & 0xff, (address >> 8) & 0xff, (address >> 16) & 0xff, address >> 24);
    return s_netToABuffer->getBlockStart();
}

void Socket::init()
{
    s_netToABuffer = new MemMap(4096);
    //SDLNet_Init();
}

void Socket::fini()
{
    //SDLNet_Quit();
    delete s_netToABuffer;
}

}

