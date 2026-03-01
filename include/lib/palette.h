#ifndef LIB_PALETTE_H_
#define LIB_PALETTE_H_

#include <lib/winapp.h>

namespace win32
{

class Renderer;

struct PALETTEENTRY
{
    x86::reg8 peRed;
    x86::reg8 peGreen;
    x86::reg8 peBlue;
    x86::reg8 peFlags;
};
typedef PALETTEENTRY* LPPALETTEENTRY;

class Palette : public GenericResource
{
public:
    Palette(Renderer* renderer, const PALETTEENTRY* entries, x86::reg32 entryCount);
    ~Palette();

    void setEntries(const PALETTEENTRY* entries, x86::reg32 firstEntry, x86::reg32 entryCount);
private:
    x86::reg32      m_paletteSize;
    x86::reg32      m_palette[256];
    Renderer*       m_renderer;
};

}

#endif

