#include <lib/window.h>
#include <lib/thread.h>
#include <SDL3/SDL.h>
#include <cstring>

#define WM_KEYDOWN  0x0100
#define WM_KEYUP    0x0101
#define WM_CHAR     0x0102

namespace win32
{

Uint32 g_userEvent   = 0;
Uint32 g_userEvent1  = 0;
Uint32 g_userEvent2  = 0;
Uint32 g_wmCharEvent = 0;

static struct CustomEventRegistrar
{
    CustomEventRegistrar()
    {
        Uint32 base = SDL_RegisterEvents(4);
        g_userEvent   = base + 0;
        g_userEvent1  = base + 1;
        g_userEvent2  = base + 2;
        g_wmCharEvent = base + 3;
    }
} s_customEventRegistrar;


static const x86::reg32 WM_QUIT = 0x0012;
static const x86::reg32 WM_USER = 0x0400;
static const x86::reg32 WM_USER_END = 0xC000;
static WindowClass* s_class;

static const x86::reg8 s_scancodeTable[100] =
{
    0x00, 0x00, 0x00, 0x00, 0x1E, 0x30, 0x2E, 0x20, 0x12, 0x21,
    0x22, 0x23, 0x17, 0x24, 0x25, 0x26, 0x32, 0x31, 0x18, 0x19,
    0x10, 0x13, 0x1F, 0x14, 0x16, 0x2F, 0x11, 0x2D, 0x15, 0x2C,
    0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B,
    0x1C, 0x01, 0x0E, 0x0F, 0x39, 0x0C, 0x0D, 0x1A, 0x1B, 0x2B,
    0x00, 0x27, 0x28, 0x29, 0x33, 0x34, 0x35, 0x3A, 0x3B, 0x3C,
    0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x57, 0x58,
    0x37, 0x46, 0x59, 0x52, 0x47, 0x49, 0x53, 0x4F, 0x51, 0x4D,
    0x4B, 0x50, 0x48, 0x45, 0x35, 0x37, 0x4A, 0x4E, 0x1C, 0x4F,
    0x50, 0x51, 0x4B, 0x4C, 0x4D, 0x47, 0x48, 0x49, 0x52, 0x53
};


WindowClass::WindowClass(x86::reg32 windowProc)
    :   m_wndProc(windowProc)
{
    s_class = this;
}

WindowClass::~WindowClass()
{
}

Window::Window(const char *title, int /*x*/, int /*y*/, int w, int h)
    :   m_window(SDL_CreateWindow(title, w, h, SDL_WINDOW_RESIZABLE|SDL_WINDOW_OPENGL))
{
    if (!m_window)
    {
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "Failed to create window: %s", SDL_GetError());
        return;
    }
}

Window::~Window()
{
}

x86::reg32 Window::getMessage(const x86::CPU& cpu, MSG* result, Window *window, x86::reg32 filterMin, x86::reg32 msgMax)
{
    NFS2_USE(window);
    NFS2_USE(filterMin);
    NFS2_USE(msgMax);
    static LPARAM s_lastLParam;
    memset(result, 0, sizeof(MSG));
    SDL_Event event;
    for (;;)
    {
        if (SDL_WaitEvent(&event))
        {
            if (cpu.terminate)
                return 0;
            if (event.type == g_userEvent || event.type == g_userEvent1)
            {
                result->message = x86::reg32(event.user.code);
                result->wParam = static_cast<x86::reg32>(reinterpret_cast<intptr_t>(event.user.data1));
                result->lParam = static_cast<x86::reg32>(reinterpret_cast<intptr_t>(event.user.data2));
                result->hWindow = event.user.windowID;
                return result->message != WM_QUIT;
            }
            else if (event.type == g_userEvent2)
            {
                const x86::reg32 tid = static_cast<x86::reg32>(reinterpret_cast<intptr_t>(event.user.data1));
                if (tid == Thread::currentThreadId())
                {
                    return 0;
                }
            }
            else if (event.type == g_wmCharEvent)
            {
                result->message = WM_CHAR;
                result->wParam = static_cast<x86::reg32>(reinterpret_cast<intptr_t>(event.user.data1));
                result->lParam = static_cast<x86::reg32>(reinterpret_cast<intptr_t>(event.user.data2));
                return 1;
            }
            else
            {
                switch (event.type)
                {
                case SDL_EVENT_QUIT:
                    result->message = WM_QUIT;
                    return 0;
                case SDL_EVENT_KEY_DOWN:
                case SDL_EVENT_KEY_UP:
                    {
                        SDL_Scancode scancode = event.key.scancode;
                        SDL_Keycode sym = event.key.key;

                        BOOL isWMChar = false;

                        result->lParam = 1;

                        switch (sym)
                        {
                            case SDLK_LSHIFT:
                            case SDLK_RSHIFT:
                                result->wParam = 0x10;
                                break;
                            case SDLK_PAGEDOWN:
                                result->wParam = 0x21;
                                break;
                            case SDLK_PAGEUP:
                                result->wParam = 0x22;
                                break;
                            case SDLK_END:
                                result->wParam = 0x23;
                                break;
                            case SDLK_HOME:
                                result->wParam = 0x24;
                                break;
                            case SDLK_LEFT:
                                result->wParam = 0x25;
                                break;
                            case SDLK_UP:
                                result->wParam = 0x26;
                                break;
                            case SDLK_RIGHT:
                                result->wParam = 0x27;
                                break;
                            case SDLK_DOWN:
                                result->wParam = 0x28;
                                break;
                            case SDLK_INSERT:
                                result->wParam = 0x2D;
                                break;
                            case SDLK_DELETE:
                                result->wParam = 0x2E;
                                break;
                            case SDLK_KP_0:
                                result->wParam = 0x60;
                                break;
                            case SDLK_KP_1:
                                result->wParam = 0x61;
                                break;
                            case SDLK_KP_2:
                                result->wParam = 0x62;
                                break;
                            case SDLK_KP_3:
                                result->wParam = 0x63;
                                break;
                            case SDLK_KP_4:
                                result->wParam = 0x64;
                                break;
                            case SDLK_KP_5:
                                result->wParam = 0x65;
                                break;
                            case SDLK_KP_6:
                                result->wParam = 0x66;
                                break;
                            case SDLK_KP_7:
                                result->wParam = 0x67;
                                break;
                            case SDLK_KP_8:
                                result->wParam = 0x68;
                                break;
                            case SDLK_KP_9:
                                result->wParam = 0x69;
                                break;
                            case SDLK_KP_MULTIPLY:
                                result->wParam = 0x6A;
                                break;
                            case SDLK_KP_PLUS:
                                result->wParam = 0x6B;
                                break;
                            case SDLK_KP_MINUS:
                                result->wParam = 0x6D;
                                break;
                            case SDLK_KP_PERIOD:
                                result->wParam = 0x6E;
                                break;
                            case SDLK_KP_DIVIDE:
                                result->wParam = 0x6F;
                                break;
                            case SDLK_EQUALS:
                                result->wParam = 0xBB;
                                break;
                            case SDLK_MINUS:
                                result->wParam = 0xBD;
                                break;
                            case SDLK_PERIOD:
                                result->wParam = 0xBE;
                                break;
                            case SDLK_GRAVE:
                                result->wParam = 0xC0;
                                break;
                            case SDLK_APOSTROPHE:
                                result->wParam = 0xDE;
                                break;
                            case SDLK_KP_ENTER:
                                sym = SDLK_RETURN;
                            [[fallthrough]];
                            default:
                                if (!(sym & 0x40000000))
                                {
                                    isWMChar = sym >= SDLK_BACKSPACE && sym < SDLK_SPACE;
                                    result->wParam = DWORD(sym);
                                }
                        }

                        if (result->lParam == 1 && scancode < 100)
                            result->lParam |= s_scancodeTable[scancode] << 16;
                        s_lastLParam = result->lParam;

                        SDL_Event event2;
                        event2.type = g_wmCharEvent;
                        if (event.type == SDL_EVENT_KEY_UP)
                            result->message = WM_KEYUP;
                        else if (event.type == SDL_EVENT_KEY_DOWN)
                        {
                            result->message = WM_KEYDOWN;
                            if (isWMChar)
                            {
                                event2.user.data1 = reinterpret_cast<void*>(static_cast<intptr_t>(result->wParam));
                                event2.user.data2 = reinterpret_cast<void*>(static_cast<intptr_t>(result->lParam));
                                SDL_PushEvent(&event2);
                            }
                        }

                        if (sym >= SDLK_A && sym <= SDLK_Z)
                            result->wParam = sym & ~0x20;
                    }
                    return 1;
                case SDL_EVENT_JOYSTICK_BUTTON_DOWN:
                case SDL_EVENT_JOYSTICK_BUTTON_UP:
                    {
                        if (event.jbutton.which == 0)
                        {
                            if (event.jbutton.button == 7)
                            {
                                /* simulate Enter */
                                result->wParam = DWORD(SDLK_RETURN);
                                result->lParam = 1 | s_scancodeTable[SDL_SCANCODE_RETURN] << 16;
                            }
                            else if (event.jbutton.button == 6)
                            {
                                /* simulate Escape */
                                result->wParam = DWORD(SDLK_ESCAPE);
                                result->lParam = 1 | s_scancodeTable[SDL_SCANCODE_ESCAPE] << 16;
                            }
                            else
                            {
                                /* simulate Space */
                                result->wParam = DWORD(SDLK_SPACE);
                                result->lParam = 1 | s_scancodeTable[SDL_SCANCODE_SPACE] << 16;
                            }
                            result->message = event.jbutton.down ? WM_KEYDOWN : WM_KEYUP;
                            result->hWindow = event.user.windowID;

                            if (event.jbutton.down)
                            {
                                SDL_Event event2;
                                event2.type = g_wmCharEvent;
                                event2.user.data1 = reinterpret_cast<void*>(static_cast<intptr_t>(result->wParam));
                                event2.user.data2 = reinterpret_cast<void*>(static_cast<intptr_t>(result->lParam));
                                SDL_PushEvent(&event2);
                            }

                            return 1;
                        }
                    }
                    break;
                case SDL_EVENT_JOYSTICK_AXIS_MOTION:
                    if (event.jaxis.which == 0)
                    {
                        if (event.jaxis.axis == 0)
                        {
                            static x86::sreg16 s_prevAxisValue = 0;
                            if ((s_prevAxisValue > 30000) && (event.jaxis.value < 30000))
                            {
                                SDL_Event kevent;
                                kevent.type = SDL_EVENT_KEY_UP;
                                kevent.key.key = SDLK_RIGHT;
                                kevent.key.scancode = SDL_SCANCODE_RIGHT;
                                SDL_PushEvent(&kevent);
                            }
                            if ((s_prevAxisValue < -30000) && (event.jaxis.value > -30000))
                            {
                                SDL_Event kevent;
                                kevent.type = SDL_EVENT_KEY_UP;
                                kevent.key.key = SDLK_LEFT;
                                kevent.key.scancode = SDL_SCANCODE_LEFT;
                                SDL_PushEvent(&kevent);
                            }
                            if ((s_prevAxisValue < 30000) && (event.jaxis.value > 30000))
                            {
                                SDL_Event kevent;
                                kevent.type = SDL_EVENT_KEY_DOWN;
                                kevent.key.key = SDLK_RIGHT;
                                kevent.key.scancode = SDL_SCANCODE_RIGHT;
                                SDL_PushEvent(&kevent);
                            }
                            if ((s_prevAxisValue > -30000) && (event.jaxis.value < -30000))
                            {
                                SDL_Event kevent;
                                kevent.type = SDL_EVENT_KEY_DOWN;
                                kevent.key.key = SDLK_LEFT;
                                kevent.key.scancode = SDL_SCANCODE_LEFT;
                                SDL_PushEvent(&kevent);
                            }
                            s_prevAxisValue = event.jaxis.value;
                            break;
                        }
                        if (event.jaxis.axis == 1)
                        {
                            static x86::sreg16 s_prevAxisValue = 0;
                            if ((s_prevAxisValue > 30000) && (event.jaxis.value < 30000))
                            {
                                SDL_Event kevent;
                                kevent.type = SDL_EVENT_KEY_UP;
                                kevent.key.key = SDLK_DOWN;
                                kevent.key.scancode = SDL_SCANCODE_DOWN;
                                SDL_PushEvent(&kevent);
                            }
                            if ((s_prevAxisValue < -30000) && (event.jaxis.value > -30000))
                            {
                                SDL_Event kevent;
                                kevent.type = SDL_EVENT_KEY_UP;
                                kevent.key.key = SDLK_UP;
                                kevent.key.scancode = SDL_SCANCODE_UP;
                                SDL_PushEvent(&kevent);
                            }
                            if ((s_prevAxisValue < 30000) && (event.jaxis.value > 30000))
                            {
                                SDL_Event kevent;
                                kevent.type = SDL_EVENT_KEY_DOWN;
                                kevent.key.key = SDLK_DOWN;
                                kevent.key.scancode = SDL_SCANCODE_DOWN;
                                SDL_PushEvent(&kevent);
                            }
                            if ((s_prevAxisValue > -30000) && (event.jaxis.value < -30000))
                            {
                                SDL_Event kevent;
                                kevent.type = SDL_EVENT_KEY_DOWN;
                                kevent.key.key = SDLK_UP;
                                kevent.key.scancode = SDL_SCANCODE_UP;
                                SDL_PushEvent(&kevent);
                            }
                            s_prevAxisValue = event.jaxis.value;
                            break;
                        }
                    }
                    break;
                case SDL_EVENT_JOYSTICK_HAT_MOTION:
                    if (event.jhat.which == 0 && event.jhat.hat == 0)
                    {
                        static x86::reg32 s_prevHatButtons = 0;
                        x86::reg32 hatButtons = event.jhat.value;
                        SDL_Event event;
                        if ((s_prevHatButtons & SDL_HAT_LEFT) != (hatButtons & SDL_HAT_LEFT))
                        {
                            event.type = hatButtons & SDL_HAT_LEFT ? SDL_EVENT_KEY_DOWN : SDL_EVENT_KEY_UP;
                            event.key.key = SDLK_LEFT;
                            event.key.scancode = SDL_SCANCODE_LEFT;
                            SDL_PushEvent(&event);
                        }
                        if ((s_prevHatButtons & SDL_HAT_RIGHT) != (hatButtons & SDL_HAT_RIGHT))
                        {
                            event.type = hatButtons & SDL_HAT_RIGHT ? SDL_EVENT_KEY_DOWN : SDL_EVENT_KEY_UP;
                            event.key.key = SDLK_RIGHT;
                            event.key.scancode = SDL_SCANCODE_RIGHT;
                            SDL_PushEvent(&event);
                        }
                        if ((s_prevHatButtons & SDL_HAT_UP) != (hatButtons & SDL_HAT_UP))
                        {
                            event.type = hatButtons & SDL_HAT_UP ? SDL_EVENT_KEY_DOWN : SDL_EVENT_KEY_UP;
                            event.key.key = SDLK_UP;
                            event.key.scancode = SDL_SCANCODE_UP;
                            SDL_PushEvent(&event);
                        }
                        if ((s_prevHatButtons & SDL_HAT_DOWN) != (hatButtons & SDL_HAT_DOWN))
                        {
                            event.type = hatButtons & SDL_HAT_DOWN ? SDL_EVENT_KEY_DOWN : SDL_EVENT_KEY_UP;
                            event.key.key = SDLK_DOWN;
                            event.key.scancode = SDL_SCANCODE_DOWN;
                            SDL_PushEvent(&event);
                        }
                        break;
                    }
                    break;
                case SDL_EVENT_TEXT_INPUT:
                    {
                        result->message = WM_CHAR;
                        result->wParam = event.text.text[0];
                        result->lParam = s_lastLParam;
                    }
                    return 1;
                default:
                    break;
                }
            }
        }
    }
}

x86::reg32 Window::postMessage(x86::reg32 hWnd, x86::reg32 message, x86::reg32 wParam, x86::reg32 lParam)
{
    SDL_Event event;
    if (message >= WM_USER && message < WM_USER_END)
    {
        event.type = g_userEvent;
    }
    else
    {
        event.type = g_userEvent1;
    }
    event.user.code = int(message);
    event.user.data1 = reinterpret_cast<void*>(static_cast<intptr_t>(wParam));
    event.user.data2 = reinterpret_cast<void*>(static_cast<intptr_t>(lParam));
    event.user.windowID = hWnd;
    SDL_PushEvent(&event);
    return 1;
}

x86::reg32 Window::getMessageHandler()
{
    return s_class->m_wndProc;
}

}
