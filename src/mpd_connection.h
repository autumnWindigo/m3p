#ifndef MPD_CONNECTION_
#define MPD_CONNECTION_

#include <mpd/client.h>
#include <mpd/connection.h>
#include <mpd/error.h>
#include <mpd/player.h>
#include <cstdio>
#include <iostream>
#include <ostream>

// TODO Put documentation for mpd_connection here
namespace MPD {

struct Connection {
public:

    Connection();

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
    void connect();

private:
    mpd_connection *connection;
    int port;
};
}

#endif

