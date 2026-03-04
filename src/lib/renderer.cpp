#include <lib/renderer.h>
#include <lib/window.h>
#include <lib/gamepad.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>
#include <GL/gl.h>

namespace win32
{

void GLAPIENTRY errorCallback(GLenum /*source*/, GLenum type, GLuint /*id*/, GLenum severity, GLsizei /*length*/, const GLchar* message, const void* /*userParam*/)
{
    if (severity != GL_DEBUG_SEVERITY_NOTIFICATION)
    SDL_LogError(SDL_LOG_CATEGORY_RENDER, "OpenGL: %s type = 0x%x, severity = 0x%x, \"%s\"\n",
            (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
            type, severity, message);
}
PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback;

Renderer::Renderer(WinApplication* application, Window *window)
    :   m_application(application)
    ,   m_window(window)
    ,   m_renderer(SDL_GL_CreateContext(m_window->m_window))
    ,   m_videoMemory(new MemMap(800*600*2*2)) // double buffer 16 bits 800x600
    ,   m_currentBuffer(0)
    ,   m_depth(16)
    ,   m_colorPalette()
{
    setCurrent();
    SDL_GL_SetSwapInterval(1);
    glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)SDL_GL_GetProcAddress("glDebugMessageCallback");
    if (glDebugMessageCallback)
    {
        glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallback(errorCallback, 0);
    }

    glGenTextures(1, &m_texture);
    glBindTexture(GL_TEXTURE_2D, m_texture);
    glEnable(GL_TEXTURE_2D);

    clearCurrent();
}

Renderer::~Renderer()
{
    SDL_GL_DestroyContext(static_cast<SDL_GLContext>(m_renderer));
}

void Renderer::setCurrent()
{
    SDL_GL_MakeCurrent(m_window->m_window, static_cast<SDL_GLContext>(m_renderer));
}

void Renderer::clearCurrent()
{
    SDL_GL_MakeCurrent(m_window->m_window, nullptr);
}

void Renderer::setVideoMode(x86::reg32 w, x86::reg32 h, x86::reg32 bpp)
{
    m_width = w;
    m_height = h;
    m_depth = bpp;
    setCurrent();
    glBindTexture(GL_TEXTURE_2D, m_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, nullptr);
    clearCurrent();
    //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, nullptr);
}

void Renderer::updatePalette(x86::reg32 colorCount, const x86::reg32* colors)
{
    NFS2_ASSERT(colorCount <= 256);
    memcpy(m_colorPalette, colors, colorCount*4);
}

x86::reg32 Renderer::getFrontBuffer() const
{
    return m_videoMemory->getBlockStart() + m_currentBuffer * m_width * m_height * 2;
}

x86::reg32 Renderer::getBackBuffer() const
{
    return m_videoMemory->getBlockStart() + (1 - m_currentBuffer) * m_width * m_height * 2;
}

void Renderer::present()
{
    Gamepad::updateKeys();
    glBindTexture(GL_TEXTURE_2D, m_texture);
    int w, h;
    SDL_GetWindowSizeInPixels(m_window->m_window, &w, &h);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, m_width, m_height, 0, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_TRIANGLES);
        glTexCoord2f(0.f, 0.f);
        glVertex3f(0.f, 0.f, 1.f);
        glTexCoord2f(1.f, 0.f);
        glVertex3f(GLfloat(m_width), 0.f, 1.f);
        glTexCoord2f(0.f, 1.f);
        glVertex3f(0.f, GLfloat(m_height), 1.f);

        glTexCoord2f(1.f, 0.f);
        glVertex3f(GLfloat(m_width), 0.f, 1.f);
        glTexCoord2f(1.f, 1.f);
        glVertex3f(GLfloat(m_width), GLfloat(m_height), 1.f);
        glTexCoord2f(0.f, 1.f);
        glVertex3f(0.f, GLfloat(m_height), 1.f);
    glEnd();
    glFlush();
    SDL_GL_SwapWindow(m_window->m_window);
}

void Renderer::update()
{
    glBindTexture(GL_TEXTURE_2D, m_texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if (m_depth == 16)
    {
        //MemMap::fillDebugGraph(&m_application->getMemory<x86::reg16>(getFrontBuffer()) + m_width*2);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, &m_application->getMemory<x86::reg16>(getFrontBuffer()));
    }
    else
    {
        x86::reg8* srcData = &m_application->getMemory<x86::reg8>(getFrontBuffer());
        x86::reg32* screenData = reinterpret_cast<x86::reg32*>(malloc(m_width * m_height * 4));
        for (x86::reg32 i = 0; i < m_width*m_height; ++i)
        {
            screenData[i] = m_colorPalette[srcData[i]];
        }
        //MemMap::fillDebugGraph(screenData + m_width*2);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, screenData);
        free(screenData);
    }
    present();
}

x86::reg32 Renderer::lock(x86::reg32 index)
{
    return index == 0 ? getFrontBuffer() : getBackBuffer();
}

void Renderer::unlock(x86::reg32 index)
{
    if (index == 0)
    {
        setCurrent();
        SDL_GL_SetSwapInterval(0);
        update();
        clearCurrent();
    }
}

void Renderer::swap()
{
    setCurrent();
    const SDL_DisplayMode* mode = SDL_GetCurrentDisplayMode(SDL_GetPrimaryDisplay());
    SDL_GL_SetSwapInterval(1);
    m_currentBuffer = 1 - m_currentBuffer;
    for (int i = 0; i < (mode ? (int)(mode->refresh_rate / 30) : 2); ++i)
        update();
    clearCurrent();
}

}
