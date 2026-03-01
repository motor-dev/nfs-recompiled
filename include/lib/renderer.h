#ifndef LIB_RENDERER_H_
#define LIB_RENDERER_H_

#include <lib/winapp.h>
#include <winapi/types.h>
#include <lib/memmap.h>

struct SDL_Renderer;
struct SDL_Texture;

namespace win32
{

class Window;
class GlideRenderer;

class Renderer: public GenericResource
{
    friend class GlideRenderer;
public:
    Renderer(WinApplication* application, Window* window);
    ~Renderer();

    x86::reg32 lock(x86::reg32 index);
    void unlock(x86::reg32 index);

    void swap();
    void setVideoMode(x86::reg32 w, x86::reg32 h, x86::reg32 bpp);
    void updatePalette(x86::reg32 colorCount, const x86::reg32* colors);
    x86::reg32 getVideoMemorySize() const { return m_videoMemory->getBlockSize(); }

    x86::reg32 getWidth() const     { return m_width; }
    x86::reg32 getHeight() const    { return m_height; }

private: // friend class GlideRenderer
    void present();
    void setCurrent();
    void clearCurrent();

private:
    void update();
    x86::reg32 getFrontBuffer() const;
    x86::reg32 getBackBuffer() const;

private:
    WinApplication* m_application;
    Window*         m_window;
    void*           m_renderer;
    unsigned int    m_texture;
    MemMap*         m_videoMemory;
    x86::reg32      m_currentBuffer;
    x86::reg32      m_width;
    x86::reg32      m_height;
    x86::reg32      m_depth;
    x86::reg32      m_colorPalette[256];
};

}

#endif
