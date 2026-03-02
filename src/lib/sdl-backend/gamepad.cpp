#include <lib/gamepad.h>
#include <SDL_events.h>
#include <SDL_log.h>


namespace win32
{

static x86::reg32 s_kbPoll = 3;

static GamepadState s_state;
static Gamepad* s_gp1;

void Input::poll()
{
    s_kbPoll = 3;
    SDL_JoystickUpdate();
}

void Gamepad::updateKeys()
{
    if (s_gp1)
    {
        SDL_JoystickUpdate();
        if (s_kbPoll == 0)
        {
            GamepadState state = s_gp1->getState();
            SDL_Event event;
            for (x86::reg32 axis = 0; axis < 10; ++axis)
            {
                if (state.axes[axis] != s_state.axes[axis])
                {
                    event.type = SDL_JOYAXISMOTION;
                    event.jaxis.which = 0;
                    event.jaxis.axis = axis;
                    event.jaxis.value = state.axes[axis];
                    SDL_PushEvent(&event);
                }
            }
            for (x86::reg32 button = 0; button < 64; ++button)
            {
                x86::reg64 bMask = 1ll << button;
                if ((s_state.buttons & bMask) != (state.buttons & bMask))
                {
                    event.type = state.buttons & bMask ? SDL_JOYBUTTONDOWN : SDL_JOYBUTTONUP;
                    event.jbutton.which = 0;
                    event.jbutton.button = button;
                    event.jbutton.state = state.buttons & bMask ? SDL_PRESSED : SDL_RELEASED;
                    SDL_PushEvent(&event);
                }
            }
            s_state = state;
        }
        else
        {
            SDL_Log("Ignoring event poll");
            SDL_Event event;
            for (x86::reg32 button = 0; button < 64; ++button)
            {
                x86::reg64 bMask = 1ll << button;
                if ((s_state.buttons & bMask))
                {
                    event.type = SDL_JOYBUTTONUP;
                    event.jbutton.which = 0;
                    event.jbutton.button = button;
                    event.jbutton.state = SDL_RELEASED;
                    SDL_PushEvent(&event);
                }
            }
            memset(&s_state, 0, sizeof(s_state));
            s_kbPoll--;
        }
    }
}

x86::reg32 Input::getButtonCount() const
{
    return 0;
}

x86::reg32 Input::getAxesCount() const
{
    return 0;
}

Gamepad::Gamepad(x86::reg32 gamepadIndex)
    :   m_joystick(SDL_JoystickOpen(gamepadIndex))
{
    SDL_JoystickEventState(0);
    if (!s_gp1)
        s_gp1 = this;
}

Gamepad::~Gamepad()
{
    if (s_gp1)
        s_gp1 = nullptr;
    SDL_JoystickClose(m_joystick);
}

x86::reg32 Gamepad::getCount()
{
    return SDL_NumJoysticks();
}

x86::reg32 Gamepad::getButtonCount() const
{
    return SDL_JoystickNumButtons(m_joystick);
}

x86::reg32 Gamepad::getAxesCount() const
{
    return SDL_JoystickNumAxes(m_joystick);
}

GamepadState Gamepad::getState() const
{
    GamepadState result;
    memset(&result, 0, sizeof(result));
    for (x86::reg32 button = 0; button < getButtonCount(); ++button)
    {
        result.buttons |= (SDL_JoystickGetButton(m_joystick, button) ? 1 : 0) << button;
    }
    for (x86::reg32 axis = 0; axis < getAxesCount(); ++axis)
    {
        result.axes[axis] = SDL_JoystickGetAxis(m_joystick, axis);
    }
    return result;
}


}

