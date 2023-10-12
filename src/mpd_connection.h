#ifndef MPD_CONNECTION_
#define MPD_CONNECTION_

#include "mpd/song.h"
#include <mpd/client.h>
#include <mpd/connection.h>
#include <mpd/error.h>
#include <mpd/player.h>
#include <cstdio>
#include <iostream>
#include <ostream>

// TODO Put documentation for mpd_connection here
namespace MPD {

// Responsible for handling mpd connection
struct Connection {
public:

    /**
     * @brief Constructor for connection to mpd server
     */
    Connection();

    /**
     * @brief Deconstructor for MPD::Connection object
     */
    ~Connection();

    /**
     * @brief Wrapper for connection instance
     *
     * @return static connection to mpd server
     */
    static Connection* instance()
    {
        static Connection con;
        return &con;
    }

    /**
     * @brief plays next song in que
     */
    void play_next();

    /**
     * @brief Checks if there are any errors in the mpd connection
     *  and writes them to std err
     *
     * @return true if error, false otherwise
     */
    bool check_error();

    /**
     * @brief Safely closes connection to mpd server
     */
    void close_connection();

    /**
     * @brief Establishes connection to mpd server using config
     *
     * @return connection to mpd server
     */
    mpd_connection* connect();

    /**
     * @brief Sets volume of mpd server
     */
    void set_volume(int);

    /**
     * @brief returns volume of mpd server
     *
     * @return Volume of mpd server, -1 if error
     */
    int get_volume();

    /**
     * @brief Getter for connection to mpd server
     *
     * @return pointer for mpd_connection
     */
    mpd_connection *get() { return connection; }

private:
    /** @TODO add more vars here for proper connection using config file */

    /**
     * @brief connection object for mpd server
     */
    mpd_connection *connection;

    /**
     * @brief Port of mpd server
     */
    int port;
};
}

#endif

