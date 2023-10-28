#include "config.h"
/* Get config file based on Operating System
 For linux, we need to load a default config into /etc/
 and let the user create one in ~/.config/m3p/

 I don't know what the convention is for windows
*/


using namespace M3P;
Config::Config() : path(find_path()) {}

std::string Config::find_path() {
    std::string path;
    // Someone figure this out for windows lol
    // I literally don't have a windows box to test on
    #ifdef __linux__
        const char *home;
        if ((home = getenv("HOME")) == NULL )
            home = getpwuid(getuid())->pw_dir;

        path.append(home) += "/.config/m3p/config.json";
    #endif

    if (boost::filesystem::exists(path))
        return path;

    // Create config file here!
    // (it crashes if we don't)
    return nullptr;
}
