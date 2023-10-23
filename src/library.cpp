#include "mpd/song.h"
#include "song.h"
#include "library.h"
#include "mpd_connection.h"
#include <algorithm>
#include <boost/algorithm/string/case_conv.hpp>
#include <cstdlib>
#include <functional>

namespace MPD{
Library::Library() : playlist(), song_count(0) {};

Library::~Library() {
}

void Library::prep_library() {
    MPD::Connection::instance()->check_error();
    mpd_send_list_queue_meta(MPD::Connection::instance()->get());
}

void Library::load_library() {
    prep_library();
    MPD::Song *song = nullptr;

    while ((song = new MPD::Song)->is_safe() != false) {
        song_count++;
        playlist.push_back(*song);
    }
}

mpd_song *Library::find_song(std::string search) {
// TODO Return song based on title
// Must be sorted to match first
    if (!is_sorted)
        return nullptr;

    // Convert search string to lowercase to make sure case doesn't mess up the search
    boost::algorithm::to_lower(search);

    //Binary search to find the song by title
    int left = 0;
    int right = playlist.size() - 1;


    while(left <= right){
        int mid = left + (right - left) / 2;
        MPD::Song& song = playlist[mid];
        std::string songTitle = song.get_title();
        boost::algorithm::to_lower(songTitle);

        if (songTitle == search) {
            return song.get(); // Found the song
        } else if (songTitle < search){
            left = mid + 1;
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    // Failed to find song
    return nullptr;
}

void Library::sort(std::function<std::string(MPD::Song)> get_tag_value) {
    std::sort(playlist.begin(), playlist.end(),
            [get_tag_value](MPD::Song a, MPD::Song b)->int
            {
                return boost::algorithm::to_lower_copy(get_tag_value(a))
                     < boost::algorithm::to_lower_copy(get_tag_value(b));
            });
    is_sorted = true;
}

void Library::sort_by_date() {
    sort([](MPD::Song s)->std::string { return s.get_date(); });
    current_sort = MPD_TAG_DATE;
}

void Library::sort_by_title() {
    sort([](MPD::Song s)->std::string { return s.get_title(); });
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
