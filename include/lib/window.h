#ifndef LIB_WINDOW_H_
#define LIB_WINDOW_H_

#include <lib/winapp.h>
#include <winapi/types.h>

struct SDL_Window;

namespace win32
{

class WindowClass : public GenericResource
{
    friend class Window;
public:
    WindowClass(x86::reg32 windowProc);
    ~WindowClass();

private:
    x86::reg32 m_wndProc;
};

class Window : public GenericResource
{
    friend class Renderer;
public:
    Window(const char* title, int x, int y, int w, int h);
    ~Window();

    static x86::reg32 getMessage(const x86::CPU& cpu, MSG* result, Window* window, x86::reg32 filterMin, x86::reg32 msgMax);
    static x86::reg32 postMessage(x86::reg32 hWnd, x86::reg32 message, x86::reg32 wParam, x86::reg32 lParam);
    static x86::reg32 getMessageHandler();

private:
    SDL_Window*     m_window;
};

}

#endif
