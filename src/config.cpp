#include "config.h"
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <iostream>
/* Get config file based on Operating System
 For linux, we need to load a default config into /etc/
 and let the user create one in ~/.config/m3p/

 I don't know what the convention is for windows
*/


using namespace M3P;
namespace filesystem = boost::filesystem;

Config::Config() : path(find_path()) {}

filesystem::path Config::find_path() {
    // Someone figure this out for windows lol (like C:/Users/JohnDoe/.config/m3p)
    // I literally don't have a windows box to test on
    #ifdef __linux__
        auto home = (getenv("HOME") != NULL) ? getenv("HOME") : getpwuid(getuid())->pw_dir;
        auto string_path = std::string(home).append("/.config/m3p/config.json");
    #endif

    if (!filesystem::exists(string_path) && !create(std::string(home)))
        return filesystem::path();

    return filesystem::path(string_path);
}

// Create default config file
bool Config::create(std::string home) {
    #ifdef __linux__
        if (!filesystem::exists(home + "/.config/m3p"))
            filesystem::create_directory(home + "./config/m3p");

    #endif

    return true;
}

// Parse config file
bool Config::parse() {


    return false;
}
