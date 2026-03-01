#ifndef WINAPI_TYPES_H_
#define WINAPI_TYPES_H_

#include <x86.h>

namespace win32
{

class Mutex;

static const x86::reg32 MAX_PATH = 260;

typedef x86::reg32  DWORD;
typedef x86::reg16  WORD;
typedef x86::reg8   BYTE;
typedef x86::sreg32 LONG;
typedef x86::reg32  ULONG;
typedef x86::reg32  SIZE_T;
typedef x86::reg32  UINT;
typedef x86::sreg16 SHORT;
typedef x86::reg16  WCHAR;
typedef char        CHAR;
typedef x86::reg32  BOOL;
typedef x86::reg32  WPARAM;
typedef x86::reg32  LPARAM;
typedef x86::reg32  HRESULT;
typedef x86::sreg32 LSTATUS;
typedef x86::sreg32 LRESULT;

typedef x86::reg32  IID[4];
typedef const IID*  REFIID;

typedef x86::reg32* PHKEY;
typedef x86::reg32  REGSAM;

typedef x86::reg32  ATOM;
typedef x86::reg32  HANDLE;
typedef HANDLE      HINSTANCE;
typedef HANDLE      HMODULE;
typedef HANDLE      HWND;
typedef HANDLE      HMENU;
typedef HANDLE      HCURSOR;
typedef HANDLE      HICON;
typedef HANDLE      HGDIOBJ;
typedef HANDLE      HBRUSH;
typedef HANDLE      HDC;
typedef HANDLE      HHOOK;


struct RECT
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
};
typedef RECT *PRECT, *LPRECT;


struct POINT
{
    LONG x;
    LONG y;
};
typedef POINT* LPPOINT;


struct COORD
{
    SHORT X;
    SHORT Y;
};


struct MSG
{
    HWND    hWindow;
    DWORD   message;
    DWORD   wParam;
    DWORD   lParam;
    DWORD   time;
    POINT   pt;
    DWORD   lPrivate;
};
typedef MSG *PMSG, *LPMSG;


struct PAINTSTRUCT
{
    HDC  hdc;
    BOOL fErase;
    RECT rcPaint;
    BOOL fRestore;
    BOOL fIncUpdate;
    BYTE rgbReserved[32];
};
typedef PAINTSTRUCT *LPPAINTSTRUCT;


struct GUID
{
    DWORD   Data1;
    WORD    Data2;
    WORD    Data3;
    BYTE    Data4[8];

    bool operator==(const GUID& other) const
    {
        return Data1 == other.Data1
            && Data2 == other.Data2
            && Data3 == other.Data3
            && Data4[0] == other.Data4[0]
            && Data4[1] == other.Data4[1]
            && Data4[2] == other.Data4[2]
            && Data4[3] == other.Data4[3]
            && Data4[4] == other.Data4[4]
            && Data4[5] == other.Data4[5]
            && Data4[6] == other.Data4[6]
            && Data4[7] == other.Data4[7];
    }
};

struct FILETIME
{
    DWORD   dwLowDateTime;
    DWORD   dwHighDateTime;
};
typedef FILETIME* LPFILETIME;

struct WIN32_FIND_DATAA
{
    DWORD       dwFileAttributes;
    FILETIME    ftCreationTime;
    FILETIME    ftLastAccessTime;
    FILETIME    ftLastWriteTime;
    DWORD       nFileSizeHigh;
    DWORD       nFileSizeLow;
    DWORD       dwReserved0;
    DWORD       dwReserved1;
    CHAR        cFileName[MAX_PATH];
    CHAR        cAlternateFileName[14];
    /*DWORD       dwFileType;
    DWORD       dwCreatorType;
    WORD        wFinderFlags;*/
};
typedef WIN32_FIND_DATAA *LPWIN32_FIND_DATAA;


struct MEMORYSTATUS
{
    DWORD dwLength;
    DWORD dwMemoryLoad;
    DWORD dwTotalPhys;
    DWORD dwAvailPhys;
    DWORD dwTotalPageFile;
    DWORD dwAvailPageFile;
    DWORD dwTotalVirtual;
    DWORD dwAvailVirtual;
};
typedef MEMORYSTATUS *LPMEMORYSTATUS;


struct MEMORY_BASIC_INFORMATION
{
    x86::reg32  BaseAddress;
    x86::reg32  AllocationBase;
    DWORD       AllocationProtect;
    SIZE_T      RegionSize;
    DWORD       State;
    DWORD       Protect;
    DWORD       Type;
};
typedef MEMORY_BASIC_INFORMATION *PMEMORY_BASIC_INFORMATION, *LPMEMORY_BASIC_INFORMATION;


struct CPINFO
{
    UINT MaxCharSize;
    BYTE DefaultChar[2];
    BYTE LeadByte[12];
};
typedef CPINFO *PCPINFO, *LPCPINFO;


struct COMMPROP
{
    WORD  wPacketLength;
    WORD  wPacketVersion;
    DWORD dwServiceMask;
    DWORD dwReserved1;
    DWORD dwMaxTxQueue;
    DWORD dwMaxRxQueue;
    DWORD dwMaxBaud;
    DWORD dwProvSubType;
    DWORD dwProvCapabilities;
    DWORD dwSettableParams;
    DWORD dwSettableBaud;
    WORD  wSettableData;
    WORD  wSettableStopParity;
    DWORD dwCurrentTxQueue;
    DWORD dwCurrentRxQueue;
    DWORD dwProvSpec1;
    DWORD dwProvSpec2;
    WCHAR wcProvChar[1];
};
typedef COMMPROP *LPCOMMPROP;


struct COMMTIMEOUTS
{
    DWORD ReadIntervalTimeout;
    DWORD ReadTotalTimeoutMultiplier;
    DWORD ReadTotalTimeoutConstant;
    DWORD WriteTotalTimeoutMultiplier;
    DWORD WriteTotalTimeoutConstant;
};
typedef COMMTIMEOUTS *LPCOMMTIMEOUTS;


struct DCB
{
    DWORD DCBlength;
    DWORD BaudRate;
    DWORD fBinary : 1;
    DWORD fParity : 1;
    DWORD fOutxCtsFlow : 1;
    DWORD fOutxDsrFlow : 1;
    DWORD fDtrControl : 2;
    DWORD fDsrSensitivity : 1;
    DWORD fTXContinueOnXoff : 1;
    DWORD fOutX : 1;
    DWORD fInX : 1;
    DWORD fErrorChar : 1;
    DWORD fNull : 1;
    DWORD fRtsControl : 2;
    DWORD fAbortOnError : 1;
    DWORD fDummy2 : 17;
    WORD  wReserved;
    WORD  XonLim;
    WORD  XoffLim;
    BYTE  ByteSize;
    BYTE  Parity;
    BYTE  StopBits;
    char  XonChar;
    char  XoffChar;
    char  ErrorChar;
    char  EofChar;
    char  EvtChar;
    WORD  wReserved1;
};
typedef DCB *LPDCB;


struct SYSTEMTIME
{
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
};
typedef SYSTEMTIME* LPSYSTEMTIME;


struct OVERLAPPED
{
    x86::reg32 Internal;
    x86::reg32 InternalHigh;
    union
    {
        struct
        {
            DWORD Offset;
            DWORD OffsetHigh;
        };
        x86::reg32 Pointer;
    };
    HANDLE    hEvent;
};
typedef OVERLAPPED *LPOVERLAPPED;


struct SYSTEM_INFO
{
    union
    {
        DWORD dwOemId;
        struct
        {
            WORD wProcessorArchitecture;
            WORD wReserved;
        };
    };
    DWORD     dwPageSize;
    x86::reg32 lpMinimumApplicationAddress;
    x86::reg32 lpMaximumApplicationAddress;
    x86::reg32 dwActiveProcessorMask;
    DWORD     dwNumberOfProcessors;
    DWORD     dwProcessorType;
    DWORD     dwAllocationGranularity;
    WORD      wProcessorLevel;
    WORD      wProcessorRevision;
};
typedef SYSTEM_INFO *LPSYSTEM_INFO;


struct TIME_ZONE_INFORMATION
{
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
};
typedef TIME_ZONE_INFORMATION *LPTIME_ZONE_INFORMATION;


struct INPUT_RECORD
{
    struct FOCUS_EVENT_RECORD
    {
        BOOL bSetFocus;
    };
    struct KEY_EVENT_RECORD
    {
        BOOL  bKeyDown;
        WORD  wRepeatCount;
        WORD  wVirtualKeyCode;
        WORD  wVirtualScanCode;
        union
        {
            WCHAR UnicodeChar;
            CHAR  AsciiChar;
        } uChar;
        DWORD dwControlKeyState;
    };
    struct MENU_EVENT_RECORD
    {
        UINT dwCommandId;
    };
    struct MOUSE_EVENT_RECORD
    {
        COORD dwMousePosition;
        DWORD dwButtonState;
        DWORD dwControlKeyState;
        DWORD dwEventFlags;
    };
    struct WINDOW_BUFFER_SIZE_RECORD
    {
        COORD dwSize;
    };

    WORD  EventType;
    union
    {
        KEY_EVENT_RECORD          KeyEvent;
        MOUSE_EVENT_RECORD        MouseEvent;
        WINDOW_BUFFER_SIZE_RECORD WindowBufferSizeEvent;
        MENU_EVENT_RECORD         MenuEvent;
        FOCUS_EVENT_RECORD        FocusEvent;
    } Event;
};
typedef INPUT_RECORD    *PINPUT_RECORD, *LPINPUT_RECORD;


typedef struct SECURITY_ATTRIBUTES* LPSECURITY_ATTRIBUTES;
typedef win32::Mutex**              LPCRITICAL_SECTION;
typedef void*                       PVOID;
typedef void*                       LPVOID;
typedef const void*                 PCVOID;
typedef const void*                 LPCVOID;
typedef BOOL*                       LPBOOL;
typedef LONG*                       PLONG;
typedef LONG*                       LPLONG;
typedef CHAR*                       LPSTR;
typedef const CHAR*                 LPCSTR;
typedef const CHAR*                 LPCCH;
typedef WCHAR*                      LPWSTR;
typedef const WCHAR*                LPCWSTR;
typedef const WCHAR*                LPCWCH;
typedef DWORD*                      LPDWORD;
typedef WORD*                       LPWORD;
typedef BYTE*                       LPBYTE;
typedef ULONG*                      ULONG_PTR;
typedef HANDLE*                     LPHANDLE;


typedef x86::reg32 FARPROC;
typedef x86::reg32 LPTHREAD_START_ROUTINE;
typedef x86::reg32 PHANDLER_ROUTINE;
typedef x86::reg32 LPTOP_LEVEL_EXCEPTION_FILTER;

}

#endif
