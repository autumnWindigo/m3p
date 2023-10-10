#include "mpd/song.h"
#include "song.h"
#include "library.h"
#include "mpd_connection.h"
#include <algorithm>
#include <cstdlib>
#include <functional>

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

    // TODO Check if playlist = NULL ever (that means heap failed return -1);
    while ((song = new MPD::Song)->is_safe() != false) {
        song_count++;
        playlist = (MPD::Song*) realloc(playlist, song_count * sizeof(*playlist));
        if (playlist == NULL)
            // Heap failed
            exit(EXIT_FAILURE);
        playlist[song_count - 1] = *song;
    }
    // Sort based on default_sort in config
}

mpd_song *Library::find_song() {
// TODO Return song based on title
// Must be sorted to match first
    return nullptr;
}

void Library::sort_temp(mpd_tag_type tag) {

}

void Library::sort(std::function<std::string(MPD::Song)> get_tag_value) {
// TODO Sort based on input tag
    std::sort(playlist, playlist + sizeof(&playlist)/sizeof(playlist[0]),
            [get_tag_value](MPD::Song a, MPD::Song b)->int
            {
                return get_tag_value(a) > get_tag_value(b);
            });
}

// This lets us do sort_by_custom?
void Library::sort_by_date() {
    // Passing Lambda into sort so we can pass any get function into sort
    //   as long as it returns a string, so we can pass any function to it
    sort([](MPD::Song a)->std::string { return a.get_date();});
    current_sort = MPD_TAG_DATE;
}

void Library::sort_by_title() {
    sort([](MPD::Song a)->std::string {
        std::cout << "in lambda" << std::endl;
        return a.get_title();});
    current_sort = MPD_TAG_TITLE;
}

int Library::get_song_count() {
    return song_count;
}

void Library::print() {
    for (int i = 0; i < song_count; i++) {
        std::cout << playlist[i].get_title() << std::endl;
    }
}
}
