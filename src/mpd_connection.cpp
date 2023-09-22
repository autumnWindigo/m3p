#include "mpd_connection.h"

using namespace std;

namespace MPD {

// Make Correct Later
Connection::Connection() : connection(nullptr),
                                port(0){}

inline bool Connection::check_error()
{
    if (connection == NULL) {
        cerr << "Out of memory" << endl;
        return true;
    }
    if (mpd_connection_get_error(connection) != MPD_ERROR_SUCCESS) {
        cerr << mpd_connection_get_error_message(connection) << endl;
        return true;
    }
    return false;
}

inline void Connection::play_next()
{
    check_error();
    mpd_run_next(connection);
    mpd_status_begin();
}

inline void Connection::close_connection()
{

}

inline void Connection::connect()
{
    connection = mpd_connection_new(NULL, 0, 0);
}
}
