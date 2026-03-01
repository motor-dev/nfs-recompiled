#ifndef wsock32_H_
#define wsock32_H_

#include <x86.h>
#include <winapi/types.h>
#include <lib/winapp.h>


namespace win32 { namespace wsock32
{

static const x86::reg32 WSADESCRIPTION_LEN = 256;
static const x86::reg32 WSASYS_STATUS_LEN = 128;
static const x86::reg32 FD_SETSIZE_WSA = 64;


typedef x86::reg32   SOCKET;

struct timeval
{
    int    tv_sec;         /* seconds */
    int    tv_usec;        /* and microseconds */
};

struct fd_set
{
    unsigned int    fd_count;               /* how many are SET? */
    SOCKET          fd_array[FD_SETSIZE_WSA];   /* an array of SOCKETs */
};

struct sockaddr
{
    unsigned short sa_family;       /* address family */
    char    sa_data[14];            /* up to 14 bytes of direct address */
};

typedef struct in_addr
{
    union
    {
        struct { unsigned char s_b1, s_b2, s_b3, s_b4; } S_un_b;
        struct { unsigned short s_w1, s_w2; } S_un_w;
        ULONG S_addr;
    } S_un;
#define s_addr  S_un.S_addr /* can be used for most tcp & ip code */
#define s_host  S_un.S_un_b.s_b2    // host on imp
#define s_net   S_un.S_un_b.s_b1    // network
#define s_imp   S_un.S_un_w.s_w2    // imp
#define s_impno S_un.S_un_b.s_b4    // imp #
#define s_lh    S_un.S_un_b.s_b3    // logical host
} IN_ADDR, *PIN_ADDR;


struct WSADATA
{
    WORD           wVersion;
    WORD           wHighVersion;
    unsigned short iMaxSockets;
    unsigned short iMaxUdpDg;
    Packed<char>   lpVendorInfo;
    char           szDescription[WSADESCRIPTION_LEN + 1];
    char           szSystemStatus[WSASYS_STATUS_LEN + 1];
};
typedef WSADATA* LPWSADATA;
struct hostent;

int select(WinApplication* app, x86::CPU& cpu, int nfds,
           fd_set* readfds, fd_set* writefds, fd_set* exceptfds,
           const timeval *timeout);
int sendto(WinApplication* app, x86::CPU& cpu, SOCKET s, const char* buf, int len,
           int flags, const sockaddr *to, int tolen);
int getsockname(WinApplication* app, x86::CPU& cpu,
                SOCKET s, sockaddr* name, int *namelen);
int bind(WinApplication* app, x86::CPU& cpu,
         SOCKET s, const sockaddr* name, int namelen);
unsigned short htons(WinApplication* app, x86::CPU& cpu, unsigned short hostshort);
unsigned short ntohs(WinApplication* app, x86::CPU& cpu, unsigned short netshort);
unsigned long inet_addr(WinApplication* app, x86::CPU& cpu, const char *cp);
Packed<char> inet_ntoa(WinApplication* app, x86::CPU& cpu, x86::reg32 in);
int setsockopt(WinApplication* app, x86::CPU& cpu,
               SOCKET s, int level, int optname, const char *optval, int optlen);
int closesocket(WinApplication* app, x86::CPU& cpu, SOCKET s);
SOCKET socket(WinApplication* app, x86::CPU& cpu, int af, int type, int protocol);
int WSACleanup(WinApplication* app, x86::CPU& cpu);
int WSAStartup(WinApplication* app, x86::CPU& cpu, WORD wVersionRequired, LPWSADATA lpWSAData);
int recvfrom(WinApplication* app, x86::CPU& cpu, SOCKET s, char* buf, int len,
             int flags, sockaddr *from, int* fromlen);
int gethostname(WinApplication* app, x86::CPU& cpu, char *name, int namelen);
Packed<hostent> gethostbyname(WinApplication* app, x86::CPU& cpu, const char *name);
int ioctlsocket(WinApplication* app, x86::CPU& cpu, SOCKET s,
                x86::sreg32 cmd, x86::reg32* argp);
int listen(WinApplication* app, x86::CPU& cpu, SOCKET s, int backlog);
int shutdown(WinApplication* app, x86::CPU& cpu, SOCKET s, int how);
int connect(WinApplication* app, x86::CPU& cpu, SOCKET s,
            const sockaddr *name, int namelen);
SOCKET accept(WinApplication* app, x86::CPU& cpu, SOCKET s,
              sockaddr *addr, int* addrlen);
int __WSAFDIsSet(WinApplication* app, x86::CPU& cpu, SOCKET fd, fd_set* set);
int send(WinApplication* app, x86::CPU& cpu, SOCKET s, const char* buf, int len, int flags);
int recv(WinApplication* app, x86::CPU& cpu, SOCKET s, char* buf, int len, int flags);
int WSAGetLastError(WinApplication* app, x86::CPU& cpu);

}}

#endif
