#include <SDL_main.h>
#include <SDL.h>
#include <lib/file.h>
#include <nfs2se.h>
#include <cstring>

int main(int argc, char* argv[])
{
    NFS2_USE(argc);
    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "--data") == 0 && i + 1 < argc)
            win32::File::setDataDirectory(argv[++i]);
        else if (strcmp(argv[i], "--cd") == 0 && i + 1 < argc)
            win32::File::setCdDirectory(argv[++i]);
        else
            win32::File::setDataDirectory(argv[i]);
    }
    SDL_Init(SDL_INIT_TIMER|SDL_INIT_EVENTS|SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_JOYSTICK);
    {
        nfs2se::Application app(argv[0]);
        app.execute();
    }
    SDL_Quit();
    return 0;
}
