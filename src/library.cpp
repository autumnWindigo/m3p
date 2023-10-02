#include "song.h"
#include "library.h"
#include "mpd_connection.h"

namespace MPD{
Library::Library() : playlist(nullptr), song_count(0) {};

Library::~Library() {
    free(playlist);
}

// We need to allocate memory as we go for the library
// Can't know the size it takes until it's already made.
// loop through songs from MPD until null
// and on each song allocate more memory to array

void Library::prep_library() {
    MPD::Connection::instance()->check_error();
    mpd_send_list_queue_meta(MPD::Connection::instance()->get());
}

// Might be loading a playlist so can't use mpd_stats
// This works just trust me
void Library::load_library() {
    prep_library();
    MPD::Song *song = nullptr;

    while ((song = new MPD::Song)->is_safe() != false) {
        song_count++;
        playlist = (MPD::Song*) realloc(playlist, song_count * sizeof(*playlist));
        playlist[song_count - 1] = *song;
    }
}

mpd_song *Library::find_song() {
// TODO Return song based on title
    return nullptr;
}

void Library::sort(mpd_tag_type tag) {
// TODO Sort based on input tag
}

int Library::get_song_count() {
    return song_count;
}
}
