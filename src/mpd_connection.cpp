#include "mpd_connection.h"

using namespace std;

namespace MPD {

// Make more clear when we add config support
Connection::Connection() : connection(nullptr),
                                port(0){}

bool Connection::check_error()
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

void Connection::play_next()
{
    check_error();
    mpd_run_next(connection);
}

void Connection::set_volume(int volume)
{
    check_error();
    mpd_run_set_volume(connection, volume);
}

int Connection::get_volume()
{
    check_error();
    return mpd_run_get_volume(connection);
}

void Connection::close_connection()
{
    mpd_connection_free(connection);
}

void Connection::connect()
{
    connection = mpd_connection_new(NULL, port, 0);
}
}
