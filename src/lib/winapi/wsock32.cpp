#include <winapi/wsock32.h>
#include <x86.h>
#include <lib/socket.h>


namespace win32 { namespace wsock32
{

enum SocketLevel
{
    SOL_SOCKET = 0xffff
};

enum SocketOption
{
    SO_DEBUG                    = 0x0001,
    SO_ACCEPTCONN               = 0x0002,
    SO_REUSEADDR                = 0x0004,
    SO_KEEPALIVE                = 0x0008,
    SO_DONTROUTE                = 0x0010,
    SO_BROADCAST                = 0x0020,
    SO_USELOOPBACK              = 0x0040,
    SO_LINGER                   = 0x0080,
    SO_OOBINLINE                = 0x0100,
    SO_DONTLINGER               = ~SO_LINGER,
    
    SO_SNDBUF                   = 0x1001,
    SO_RCVBUF                   = 0x1002,
    SO_SNDLOWAT                 = 0x1003,
    SO_RCVLOWAT                 = 0x1004,
    SO_SNDTIMEO                 = 0x1005,
    SO_RCVTIMEO                 = 0x1006,
    SO_ERROR                    = 0x1007,
    SO_TYPE                     = 0x1008,
    
    IPX_PTYPE                   = 0x4000,
    IPX_FILTERPTYPE             = 0x4001,
    IPX_DSTYPE                  = 0x4002,
    IPX_STOPFILTERPTYPE         = 0x4003,
    IPX_EXTENDED_ADDRESS        = 0x4004,
    IPX_RECVHDR                 = 0x4005,
    IPX_MAXSIZE                 = 0x4006,
    IPX_ADDRESS                 = 0x4007,
    IPX_GETNETINFO              = 0x4008,
    IPX_GETNETINFO_NORIP        = 0x4009,
    IPX_SPXGETCONNECTIONSTATUS  = 0x400b,
    IPX_ADDRESS_NOTIFY          = 0x400c,
    IPX_MAX_ADAPTER_NUM         = 0x400d,
    IPX_RERIPNETNUMBER          = 0x400e,
    IPX_RECEIVE_BROADCAST       = 0x400f,
    IPX_IMMEDIATESPXACK         = 0x4010,

    SO_CONNDATA                 = 0x7000,
    SO_CONNOPT                  = 0x7001,
    SO_DISCDATA                 = 0x7002,
    SO_DISCOPT                  = 0x7003,
    SO_CONNDATALEN              = 0x7004,
    SO_CONNOPTLEN               = 0x7005,
    SO_DISCDATALEN              = 0x7006,
    SO_DISCOPTLEN               = 0x7007,
    
    SO_OPENTYPE                 = 0x7008,
    
    SO_SYNCHRONOUS_ALERT        = 0x10,
    SO_SYNCHRONOUS_NONALERT     = 0x20,
    
    SO_MAXDG                    = 0x7009,
    SO_MAXPATHDG                = 0x700A,
    SO_UPDATE_ACCEPT_CONTEXT    = 0x700B,
    SO_CONNECT_TIME             = 0x700C
};

int select(WinApplication* app, x86::CPU& cpu, int nfds,
           fd_set* readfds, fd_set* writefds, fd_set* exceptfds,
           const timeval *timeout)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(nfds);
    NFS2_USE(readfds);
    NFS2_USE(writefds);
    NFS2_USE(exceptfds);
    NFS2_USE(timeout);
    NFS2_ASSERT(false);
    return -1;
}

int sendto(WinApplication* app, x86::CPU& cpu, SOCKET s, const char* buf, int len,
           int flags, const sockaddr* to, int tolen)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(s);
    NFS2_USE(flags);
    NFS2_USE(buf);
    NFS2_USE(len);
    NFS2_USE(to);
    NFS2_USE(tolen);
    NFS2_ASSERT(false);
    return -1;
}

int getsockname(WinApplication* app, x86::CPU& cpu,
                SOCKET s, sockaddr* name, int* namelen)
{
    NFS2_USE(cpu);
    Socket* socket = dynamic_cast<Socket*>(app->getResource(s));
    x86::reg32 address = socket->getAddress();
    x86::reg64 node = socket->getNode();
    x86::reg16 port = socket->getPort();
    *namelen = 14;
    name->sa_data[0] = (address) & 0xff;
    name->sa_data[1] = (address>>8) & 0xff;
    name->sa_data[2] = (address>>16) & 0xff;
    name->sa_data[3] = (address>>24) & 0xff;
    name->sa_data[4] = (node) & 0xff;
    name->sa_data[5] = (node >> 8) & 0xff;
    name->sa_data[6] = (node >> 16) & 0xff;
    name->sa_data[7] = (node >> 24) & 0xff;
    name->sa_data[8] = (node >> 32) & 0xff;
    name->sa_data[9] = (node >> 40) & 0xff;
    name->sa_data[10] = (port) & 0xff;
    name->sa_data[11] = (port >> 8) & 0xff;
    return 0;
}

int bind(WinApplication* app, x86::CPU& cpu,
         SOCKET s, const sockaddr* name, int namelen)
{
    NFS2_USE(cpu);
    NFS2_USE(namelen);
    x86::reg32 address = name->sa_data[0]
                      | (name->sa_data[1] << 8)
                      | (name->sa_data[2] << 16)
                      | (name->sa_data[3] << 24);
    x86::reg64 node = x86::reg64(name->sa_data[4])
                   | (x86::reg64(name->sa_data[5]) << 8)
                   | (x86::reg64(name->sa_data[6]) << 16)
                   | (x86::reg64(name->sa_data[7]) << 24)
                   | (x86::reg64(name->sa_data[8]) << 32)
                   | (x86::reg64(name->sa_data[9]) << 40);
    x86::reg16 port = name->sa_data[10] | (name->sa_data[11] << 8);
    Socket* socket = dynamic_cast<Socket*>(app->getResource(s));
    return socket->bind(address, node, port);
}

unsigned short htons(WinApplication* app, x86::CPU& cpu, unsigned short hostshort)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return (hostshort >> 8) | (hostshort << 8);
}

unsigned short ntohs(WinApplication* app, x86::CPU& cpu, unsigned short netshort)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return (netshort >> 8) | (netshort << 8);
}

unsigned long inet_addr(WinApplication* app, x86::CPU& cpu, const char *cp)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(cp);
    NFS2_ASSERT(false);
    return -1;
}

Packed<char> inet_ntoa(WinApplication* app, x86::CPU& cpu, x86::reg32 in)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return Packed<char>(Socket::netToA(app, in));
}

int gethostname(WinApplication* app, x86::CPU& cpu, char *name, int namelen)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(name);
    NFS2_USE(namelen);
    NFS2_ASSERT(false);
    return -1;
}

int setsockopt(WinApplication* app, x86::CPU& cpu,
               SOCKET s, int level, int optname, const char *optval, int optlen)
{
    NFS2_USE(cpu);
    NFS2_ASSERT(level == SOL_SOCKET);
    NFS2_USE(optval);
    NFS2_USE(optlen);
    SocketOption option = SocketOption(optname);
    Socket* socket = dynamic_cast<Socket*>(app->getResource(s));
    NFS2_USE(option);
    NFS2_USE(socket);
    return 0;
}

int closesocket(WinApplication* app, x86::CPU& cpu, SOCKET s)
{
    NFS2_USE(cpu);
    app->freeResource(s);
    return 0;
}

SOCKET socket(WinApplication* app, x86::CPU& cpu, int af, int type, int protocol)
{
    NFS2_USE(cpu);
    NFS2_ASSERT(af == 6);    // AF_IPX
    NFS2_ASSERT(type == 2);  // SOCK_DGRAM
    NFS2_ASSERT(protocol == 1000);
    return app->allocateResource(new Socket());
}

int WSACleanup(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    Socket::fini();
    return 0;
}

int WSAStartup(WinApplication* app, x86::CPU& cpu, WORD wVersionRequired, LPWSADATA lpWSAData)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(wVersionRequired == 0x0101);
    lpWSAData->wVersion = 1;
    lpWSAData->wHighVersion = 1;
    lpWSAData->iMaxSockets = 16;
    lpWSAData->iMaxUdpDg = 1600;
    lpWSAData->lpVendorInfo = Packed<char>();
    lpWSAData->szDescription[0] = 0;
    lpWSAData->szSystemStatus[0] = 0;
    Socket::init();
    return 0;
}

int recvfrom(WinApplication* app, x86::CPU& cpu, SOCKET s, char* buf, int len,
             int flags, sockaddr* from, int* fromlen)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(s);
    NFS2_USE(buf);
    NFS2_USE(len);
    NFS2_USE(flags);
    NFS2_USE(from);
    NFS2_USE(fromlen);
    NFS2_ASSERT(false);
    return -1;
}

Packed<hostent> gethostbyname(WinApplication* app, x86::CPU& cpu, const char *name)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(name);
    NFS2_ASSERT(false);
    return Packed<hostent>();
}

int ioctlsocket(WinApplication* app, x86::CPU& cpu, SOCKET s,
                x86::sreg32 cmd, x86::reg32* argp)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(s);
    NFS2_USE(cmd);
    NFS2_USE(argp);
    NFS2_ASSERT(false);
    return -1;
}

int listen(WinApplication* app, x86::CPU& cpu, SOCKET s, int backlog)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(s);
    NFS2_USE(backlog);
    NFS2_ASSERT(false);
    return -1;
}

int shutdown(WinApplication* app, x86::CPU& cpu, SOCKET s, int how)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(s);
    NFS2_USE(how);
    NFS2_ASSERT(false);
    return -1;
}

int connect(WinApplication* app, x86::CPU& cpu, SOCKET s,
            const sockaddr *name, int namelen)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(s);
    NFS2_USE(name);
    NFS2_USE(namelen);
    NFS2_ASSERT(false);
    return -1;
}

SOCKET accept(WinApplication* app, x86::CPU& cpu, SOCKET s,
              sockaddr *addr, int* addrlen)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(s);
    NFS2_USE(addr);
    NFS2_USE(addrlen);
    NFS2_ASSERT(false);
    return -1;
}

int __WSAFDIsSet(WinApplication* app, x86::CPU& cpu, SOCKET fd, fd_set* set)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(fd);
    NFS2_USE(set);
    NFS2_ASSERT(false);
    return -1;
}

int send(WinApplication* app, x86::CPU& cpu, SOCKET s, const char* buf, int len, int flags)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(s);
    NFS2_USE(buf);
    NFS2_USE(len);
    NFS2_USE(flags);
    NFS2_ASSERT(false);
    return -1;
}

int recv(WinApplication* app, x86::CPU& cpu, SOCKET s, char* buf, int len, int flags)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(s);
    NFS2_USE(buf);
    NFS2_USE(len);
    NFS2_USE(flags);
    NFS2_ASSERT(false);
    return -1;
}

int WSAGetLastError(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
    return -1;
}

}}
