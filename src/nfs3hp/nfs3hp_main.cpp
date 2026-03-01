#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>
#include <lib/file.h>
#include <lib/registry.h>
#include <nfs3hp.h>
#include <cstring>

#ifdef _WIN32
__declspec(dllimport) void dbgsetup();
#else
# define dbgsetup()
#endif

int main(int argc, char* argv[])
{
    NFS2_USE(argc);
    dbgsetup();
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
        nfs3hp::Application app("nfs3.exe");
        app.addRegistryKey(win32::HKEY_LOCAL_MACHINE, "SOFTWARE\\Electronic Arts\\Need For Speed III", "3D Device Description", new win32::RegistryValue("3Dfx Voodoo 2"));
        app.addRegistryKey(win32::HKEY_LOCAL_MACHINE, "SOFTWARE\\Electronic Arts\\Need For Speed III", "3D Card", new win32::RegistryValue("3Dfx Voodoo 2"));
        //app.addRegistryKey(win32::HKEY_LOCAL_MACHINE, "SOFTWARE\\Electronic Arts\\Need For Speed III", "Thrash Driver", new win32::RegistryValue("softtri"));
        app.addRegistryKey(win32::HKEY_LOCAL_MACHINE, "SOFTWARE\\Electronic Arts\\Need For Speed III", "Thrash Driver", new win32::RegistryValue("voodoo2"));
        app.addRegistryKey(win32::HKEY_LOCAL_MACHINE, "SOFTWARE\\Electronic Arts\\Need For Speed III", "Group", new win32::RegistryValue("3Dfx"));
        app.addRegistryKey(win32::HKEY_LOCAL_MACHINE, "SOFTWARE\\Electronic Arts\\Need For Speed III", "D3D Device", new win32::RegistryValue(x86::reg32(0)));
        app.addRegistryKey(win32::HKEY_LOCAL_MACHINE, "SOFTWARE\\Electronic Arts\\Need For Speed III", "Triple Buffer", new win32::RegistryValue(x86::reg32(0)));
        //app.addRegistryKey(win32::HKEY_LOCAL_MACHINE, "SOFTWARE\\Electronic Arts\\Need For Speed III", "Hardware Acceleration", new win32::RegistryValue(x86::reg32(0)));
        app.addRegistryKey(win32::HKEY_LOCAL_MACHINE, "SOFTWARE\\Electronic Arts\\Need For Speed III", "Hardware Acceleration", new win32::RegistryValue(x86::reg32(1)));
        app.execute();
    }
    SDL_Quit();
    return 0;
}
