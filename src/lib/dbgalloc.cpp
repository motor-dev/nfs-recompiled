#ifdef _WIN32
#include <crtdbg.h>
struct MemoryDebugger
{
    MemoryDebugger()
    {
        _CrtSetBreakAlloc(-1);
    }
    ~MemoryDebugger()
    {
        _CrtDumpMemoryLeaks();
    }
};
__declspec(dllexport) MemoryDebugger s_debugger;
__declspec(dllexport) void dbgsetup()
{
    (void)s_debugger;
}
#endif
