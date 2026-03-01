#ifndef LIB_SURFACE_H_
#define LIB_SURFACE_H_

#include <lib/winapp.h>
#include <lib/memmap.h>

struct SDL_Texture;

namespace win32
{

class Renderer;

class Surface : public GenericResource
{
public:
    Surface(Renderer* renderer, x86::reg32 bufferIndex);
    ~Surface();

    Renderer* getRenderer();
    x86::reg32 lock();
    void unlock();

private:
    Renderer*   m_renderer;
    x86::reg32  m_surfaceIndex;
};

}

#endif

