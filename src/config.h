#ifndef CONFIG_
#define CONFIG_

#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/json.hpp>
#include <boost/json/src.hpp>
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
    boost::filesystem::path get(){ return path; }

    bool parse();

private:
    boost::filesystem::path path;

    boost::filesystem::path find_path();

    bool create(std::string home);
};
}
#endif

