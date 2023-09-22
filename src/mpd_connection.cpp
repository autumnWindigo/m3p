#include <mpd/client.h>
#include <cstdio>
#include <iostream>
#include <mpd/connection.h>
#include <mpd/error.h>
#include <mpd/player.h>
#include <ostream>

using namespace std;

enum Connection_state { connected, disconnected, error };
class MPD_Connection {
    public:
    mpd_connection *conn;
    Connection_state conn_state;

    // Default Constructor
    MPD_Connection() {
        conn = mpd_connection_new(NULL, 0, 0);
        conn_state = connected;
        check_error();
    }
    void play_next();

    bool check_error();

    void close_connection();
};

/**
 * Checks if there are any errors in the mpd connection
 *  and writes them to std err
 *
 * @param mpd_connection within object
 * @return true if error, false otherwise
 */
bool MPD_Connection::check_error() {
    if (conn == NULL) {
        cerr << "Out of memory" << endl;
        conn_state = disconnected;
        return true;
    }
    if (mpd_connection_get_error(conn) != MPD_ERROR_SUCCESS) {
        cerr << mpd_connection_get_error_message(conn) << endl;
        conn_state = error;
        return true;
    }
    return false;
}

void MPD_Connection::play_next() {
    check_error();
    mpd_run_next(conn);
}

void MPD_Connection::close_connection() {

}
