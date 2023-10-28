#ifndef CONFIG_
#define CONFIG_

#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/filesystem.hpp>

#ifdef __linux__
    #include <unistd.h>
    #include <sys/types.h>
    #include <pwd.h>
    #include <cstdlib>
#endif

namespace M3P {

struct Config {
public:
    Config();
    std::string get_path(){ return path; }

private:
    std::string path;

    std::string find_path();
};
}
#endif

