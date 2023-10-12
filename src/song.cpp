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
    return get_tag(MPD_TAG_DATE);
}

std::string Song::get_title() {
    return get_tag(MPD_TAG_TITLE);
}

std::string Song::get_artist() {
    return get_tag(MPD_TAG_ARTIST);
}

int Song::get_length() {
    if (is_safe()) return -1;
    return mpd_song_get_duration(song);
}

/** @TODO make better */
bool Song::is_safe() {
    if ( song == NULL )
        return false;
    return true;
}

}
