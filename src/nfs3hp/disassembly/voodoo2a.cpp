#include "voodoo2a.h"
#include <x86.h>
#include <winapi/wrapper.h>

namespace voodoo2a
{

win32::Library s_library = win32::Library("voodoo2a.dll");
win32::Library* s_registry = &(s_library
        .registerSymbol("_THRASH_about@0", &sub_a83c60)
        .registerSymbol("_THRASH_clearwindow@0", &sub_a847b0)
        .registerSymbol("_THRASH_clip@16", &sub_a848b0)
        .registerSymbol("_THRASH_drawline@8", &sub_a86240)
        .registerSymbol("_THRASH_drawlinemesh@12", &sub_a86350)
        .registerSymbol("_THRASH_drawlinestrip@8", &sub_a86490)
        .registerSymbol("_THRASH_drawpoint@4", &sub_a86650)
        .registerSymbol("_THRASH_drawpointmesh@12", &sub_a866e0)
        .registerSymbol("_THRASH_drawpointstrip@8", &sub_a86790)
        .registerSymbol("_THRASH_drawquad@16", &sub_a85300)
        .registerSymbol("_THRASH_drawquadmesh@12", &sub_a85520)
        .registerSymbol("_THRASH_drawtri@12", &sub_a85770)
        .registerSymbol("_THRASH_drawtrifan@8", &sub_a86000)
        .registerSymbol("_THRASH_drawtrimesh@12", &sub_a85900)
        .registerSymbol("_THRASH_drawtristrip@8", &sub_a85ac0)
        .registerSymbol("_THRASH_flushwindow@0", &sub_a847d0)
        .registerSymbol("_THRASH_idle@0", &sub_a84810)
        .registerSymbol("_THRASH_init@0", &sub_a83f50)
        .registerSymbol("_THRASH_is@0", &sub_a83df0)
        .registerSymbol("_THRASH_lockwindow@0", &sub_a850f0)
        .registerSymbol("_THRASH_pageflip@0", &sub_a847e0)
        .registerSymbol("_THRASH_readrect@20", &sub_a85220)
        .registerSymbol("_THRASH_restore@0", &sub_a84100)
        .registerSymbol("_THRASH_selectdisplay@4", &sub_a83f10)
        .registerSymbol("_THRASH_setstate@8", &sub_a84990)
        .registerSymbol("_THRASH_settexture@4", &sub_a846d0)
        .registerSymbol("_THRASH_setvideomode@12", &sub_a843d0)
        .registerSymbol("_THRASH_sync@4", &sub_a84830)
        .registerSymbol("_THRASH_talloc@20", &sub_a844b0)
        .registerSymbol("_THRASH_treset@0", &sub_a84690)
        .registerSymbol("_THRASH_tupdate@12", &sub_a84630)
        .registerSymbol("_THRASH_unlockwindow@4", &sub_a851d0)
        .registerSymbol("_THRASH_window@4", &sub_a84780)
        .registerSymbol("_THRASH_writerect@20", &sub_a85290)

    );
}
