#include <lib/palette.h>
#include <lib/renderer.h>

namespace win32
{

Palette::Palette(Renderer* renderer, const PALETTEENTRY* entries, x86::reg32 entryCount)
    :   m_paletteSize(entryCount)
    ,   m_renderer(renderer)
{
    setEntries(entries, 0, entryCount);
}

Palette::~Palette()
{
}

void Palette::setEntries(const PALETTEENTRY *entries, x86::reg32 firstEntry, x86::reg32 entryCount)
{
    NFS2_ASSERT(firstEntry + entryCount <= m_paletteSize);
    for (x86::reg32 i = 0; i < entryCount; ++i)
    {
        m_palette[firstEntry + i] = entries[i].peRed << 24| entries[i].peGreen << 16 | entries[i].peBlue << 8 | 0xff ;
    }
    m_renderer->updatePalette(m_paletteSize, m_palette);
}

}
