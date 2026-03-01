#ifndef LIB_GLIDETMU_H_
#define LIB_GLIDETMU_H_

#include <lib/winapp.h>
#include <winapi/types.h>

namespace win32
{

struct GlTextureSlot
{
    GlTextureSlot*  next;
    x86::reg32      lod;
    x86::reg32      x;
    x86::reg32      y;
};

class GlideTMU
{
public:
    GlideTMU(x86::reg32 atlasSize);
    ~GlideTMU();

    x86::reg32 getTextureMemSize() const { return m_videoMemorySize; }

    void returnTextureSlot(GlTextureSlot* slot);
    GlTextureSlot* reserveTextureSlot(x86::reg32 lod);

    x86::reg32 textureMemStart() const;
    x86::reg32 textureMemEnd() const;
    GlTextureSlot** getTextureInfo(x86::reg32 address);

private:
    GlTextureSlot* allocateTextureSlot();
    void freeTextureSlot(GlTextureSlot* slot);
    void breakdownTextureSlot(GlTextureSlot* slot);

private:
    x86::reg32      m_videoMemorySize;
    GlTextureSlot** m_textureSlots;
    GlTextureSlot*  m_textureSlotPool;
    GlTextureSlot*  m_firstFreeTextureSlot;
    GlTextureSlot** m_textureMem;
};

}

#endif
