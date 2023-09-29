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

    Connection();

    ~Connection();

    /* Creates an instance of Connection to use */
    static Connection* instance()
    {
        static Connection con;
        return &con;
    }

    /* Plays next song in que */
    void play_next();

    /**
     * Checks if there are any errors in the mpd connection
     *  and writes them to std err
     *
     * @return true if error, false otherwise
     */
    bool check_error();

    /* Closes Connection to mpd server */
    void close_connection();

    /* Connects client to mpd server */
    mpd_connection* connect();

    /* Set volume 0-100 */
    void set_volume(int);

    /* Returns Volume 0-100, -1 if error */
    int get_volume();

    /* Returns connection */
    mpd_connection *get() { return connection; }

private:
    mpd_connection *connection;
    int port;
};
}

#endif

