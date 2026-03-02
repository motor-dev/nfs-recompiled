#include "eacsnd.h"
#include <x86.h>
#include <winapi/wrapper.h>

namespace eacsnd
{

win32::Library s_library = win32::Library("eacsnd.dll");
win32::Library* s_registry = &(s_library
        .registerSymbol("iSNDdirectcaps_", &sub_54863c)
        .registerSymbol("iSNDdirectserve_", &sub_5494d4)
        .registerSymbol("iSNDdirectsetfunctions_", &sub_548614)
        .registerSymbol("iSNDdirectstart_", &sub_5491dc)
        .registerSymbol("iSNDdirectstop_", &sub_549224)
        .registerSymbol("iSNDdllversion_", &sub_548600)

    );
}
