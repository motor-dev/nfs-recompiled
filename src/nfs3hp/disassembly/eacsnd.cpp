#include "eacsnd.h"
#include <x86.h>
#include <winapi/wrapper.h>

namespace eacsnd
{

win32::Library s_library = win32::Library("eacsnd.dll");
win32::Library* s_registry = &(s_library
        .registerSymbol("_iSNDdirectcaps@4", &sub_a32c28)
        .registerSymbol("_iSNDdirectcreate3dbuf@28", &sub_a33f4c)
        .registerSymbol("_iSNDdirectplay3d@28", &sub_a34014)
        .registerSymbol("_iSNDdirectpos3d@12", &sub_a33e68)
        .registerSymbol("_iSNDdirectrate@8", &sub_a33f0c)
        .registerSymbol("_iSNDdirectrecordpacket@4", &sub_a33904)
        .registerSymbol("_iSNDdirectrecordstart@16", &sub_a338fc)
        .registerSymbol("_iSNDdirectrecordstop@0", &sub_a3390c)
        .registerSymbol("_iSNDdirectremovebuf@4", &sub_a33fc0)
        .registerSymbol("_iSNDdirectserve@0", &sub_a33b24)
        .registerSymbol("_iSNDdirectsetfunctions@32", &sub_a32bd8)
        .registerSymbol("_iSNDdirectstart@8", &sub_a3382c)
        .registerSymbol("_iSNDdirectstop@0", &sub_a3387c)
        .registerSymbol("_iSNDdirectstopbuf@4", &sub_a341b0)
        .registerSymbol("_iSNDdirectvol@8", &sub_a33e18)
        .registerSymbol("_iSNDdllversion@0", &sub_a32bc4)

    );
}
