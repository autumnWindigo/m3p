#include "song.h"
#include "mpd/song.h"
#include "mpd_connection.h"
#include <cassert>

namespace MPD {
Song::Song() : song(mpd_recv_song(MPD::Connection::instance()->get())),
                idx(0) {}

Song::~Song() {
    assert(song);
    mpd_song_free(song);
}

std::string Song::get_date() {
    // Find a better solution, might be NULL
    assert(song);
    return mpd_song_get_tag(song, MPD_TAG_DATE, idx);
}

std::string Song::get_title() {
    assert(song);
    return mpd_song_get_tag(song, MPD_TAG_TITLE, idx);
}

std::string Song::get_artist() {
    assert(song);
    return mpd_song_get_tag(song, MPD_TAG_ARTIST, idx);

}

// Probably make better
bool Song::is_safe() {
    if ( song == NULL )
        return false;
    return true;
}

}
