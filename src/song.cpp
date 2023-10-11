#include "song.h"
#include "mpd/song.h"
#include "mpd_connection.h"
#include <cassert>

namespace MPD {
Song::Song() : song(mpd_recv_song(MPD::Connection::instance()->get())),
                idx(0) {}

Song::~Song() {
    //mpd_song_free(song);
}

std::string Song::get_date() {
    // TODO VV Fix these it crashes program
    //if (is_safe()) return NULL;
    return get_tag(MPD_TAG_DATE);
}

std::string Song::get_title() {
    //if (is_safe()) return NULL;
    return get_tag(MPD_TAG_TITLE);
}

std::string Song::get_artist() {
    //if (is_safe()) return NULL;
    return get_tag(MPD_TAG_ARTIST);
}

// Returns -1 if null or error
int Song::get_length() {
    if (is_safe()) return -1;
    return mpd_song_get_duration(song);
}

// Probably make better, might be error not just null
bool Song::is_safe() {
    if ( song == NULL )
        return false;
    return true;
}

}
