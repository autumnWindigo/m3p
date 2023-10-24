#include "mpd_connection.h"
#include "mpd/connection.h"

using namespace std;

namespace MPD {

/** @TODO Make more robust once we introduce config support */
Connection::Connection() : connection(connect()),
                                port(0){}

Connection::~Connection() {
    mpd_connection_free(connection);
}

/** @TODO Make more robust to make sure all operations are safe */
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

mpd_connection* Connection::connect()
{
    return mpd_connection_new(NULL, port, 0);
}
}
