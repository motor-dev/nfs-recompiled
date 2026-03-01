#ifndef LIB_SOCKET_H_
#define LIB_SOCKET_H_

#include <lib/winapp.h>

namespace win32
{

class Socket : public GenericResource
{
public:
    Socket();
    ~Socket();

    x86::reg32 bind(x86::reg32 network, x86::reg64 node, x86::reg16 port);
    x86::reg32 getAddress() const { return m_address; }
    x86::reg64 getNode() const { return m_node; }
    x86::reg16 getPort() const { return m_port; }

    static void init();
    static void fini();
    static x86::reg32 netToA(WinApplication* app, x86::reg32 address);

private:
    x86::reg32 m_address;
    x86::reg64 m_node;
    x86::reg16 m_port;
};

}

#endif

