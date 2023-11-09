#ifndef CONFIG_
#define CONFIG_

#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/json.hpp>
#include <boost/json/src.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <iostream>


#ifdef __linux__
    #include <unistd.h>
    #include <sys/types.h>
    #include <pwd.h>
    #include <cstdlib>
#endif

/**
 * @brief Configuration settings for the M3P application.
 */
namespace M3P {

struct Config {
public:
    /**
    * @brief Constructor for the Config struct.
    *
    * Initializes a Config object, which represents the configuration settings for the M3P application.
    */
    Config();
    /**
    * @brief Get the path to the configuration file.
    *
    * @return The path to the configuration file as a boost::filesystem::path.
    */
    boost::filesystem::path get(){ return path; }

    /**
    * @brief Parse the configuration file.
    *
    * This function parses the configuration file and loads the settings into the Config object.
    *
    * @return True if parsing is successful, false otherwise.
    */
    bool parse();

private:
    boost::filesystem::path path;///< The path to the configuration file.
    /**
    * @brief Find the path to the configuration file.
    *
    * This function searches for the configuration file and returns its path.
    *
    * @return The path to the configuration file as a boost::filesystem::path.
    */
    boost::filesystem::path find_path();
    /**
    * @brief Create a default configuration file.
    *
    * This function creates a default configuration file in the provided home directory.
    *
    * @param home The home directory where the configuration file should be created.
    * @return True if the creation is successful, false otherwise.
    */
    bool create(std::string home);
};
}
#endif

