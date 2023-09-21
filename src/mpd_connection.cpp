#include <mpd/client.h>
#include <cstdio>
#include <iostream>
#include <mpd/connection.h>
#include <mpd/error.h>
#include <ostream>

using namespace std;

class MPD_Connection {
    public:
    mpd_connection *conn;

    // Default Constructor
    MPD_Connection() {
        conn = mpd_connection_new(NULL, 0, 0);
    }

    bool is_error();
};

/**
 * Checks if there are any errors in the mpd connection
 *  and writes them to std err
 *
 * @param mpd_connection within object
 * @return true if error, false otherwise
 */
bool MPD_Connection::is_error() {
    if (conn == NULL) {
        cerr << "Out of memory" << endl;
        return true;
    }
    if (mpd_connection_get_error(conn) != MPD_ERROR_SUCCESS) {
        cerr << mpd_connection_get_error_message(conn) << endl;
        return true;
    }
    return false;
}
