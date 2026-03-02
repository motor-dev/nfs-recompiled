#include "softtria.h"
#include <x86.h>
#include <winapi/wrapper.h>

namespace softtria
{

win32::Library s_library = win32::Library("softtria.dll");
win32::Library* s_registry = &(s_library
        .registerSymbol("_THRASH_about@0", &sub_a40f30)
        .registerSymbol("_THRASH_clearwindow@0", &sub_a42070)
        .registerSymbol("_THRASH_clip@16", &sub_a42090)
        .registerSymbol("_THRASH_drawline@8", &sub_a43c20)
        .registerSymbol("_THRASH_drawlinemesh@12", &sub_a43df0)
        .registerSymbol("_THRASH_drawlinestrip@8", &sub_a43e30)
        .registerSymbol("_THRASH_drawpoint@4", &sub_a43e60)
        .registerSymbol("_THRASH_drawpointmesh@12", &sub_a43eb0)
        .registerSymbol("_THRASH_drawpointstrip@8", &sub_a43ef0)
        .registerSymbol("_THRASH_drawquad@16", &sub_a43aa0)
        .registerSymbol("_THRASH_drawquadmesh@12", &sub_a43b30)
        .registerSymbol("_THRASH_drawtri@12", &sub_a439a0)
        .registerSymbol("_THRASH_drawtrifan@8", &sub_a43be0)
        .registerSymbol("_THRASH_drawtrimesh@12", &sub_a43a50)
        .registerSymbol("_THRASH_drawtristrip@8", &sub_a43b90)
        .registerSymbol("_THRASH_flushwindow@0", &sub_a42080)
        .registerSymbol("_THRASH_idle@0", &sub_a42080)
        .registerSymbol("_THRASH_init@0", &sub_a417d0)
        .registerSymbol("_THRASH_is@0", &sub_a41b50)
        .registerSymbol("_THRASH_lockwindow@0", &sub_a42130)
        .registerSymbol("_THRASH_pageflip@0", &sub_a42350)
        .registerSymbol("_THRASH_readrect@20", &sub_a41b60)
        .registerSymbol("_THRASH_restore@0", &sub_a417f0)
        .registerSymbol("_THRASH_selectdisplay@4", &sub_a41820)
        .registerSymbol("_THRASH_setstate@8", &sub_a41cc0)
        .registerSymbol("_THRASH_settexture@4", &sub_a42b30)
        .registerSymbol("_THRASH_setvideomode@12", &sub_a41880)
        .registerSymbol("_THRASH_sync@4", &sub_a42060)
        .registerSymbol("_THRASH_talloc@20", &sub_a42850)
        .registerSymbol("_THRASH_treset@0", &sub_a42c80)
        .registerSymbol("_THRASH_tupdate@12", &sub_a429c0)
        .registerSymbol("_THRASH_unlockwindow@4", &sub_a422d0)
        .registerSymbol("_THRASH_window@4", &sub_a41ff0)
        .registerSymbol("_THRASH_writerect@20", &sub_a41c00)

    );
}
