#ifndef MPD_LIBRARY_
#define MPD_LIBRARY_
#include "song.h"
#include <functional>
#include <mpd/client.h>

namespace MPD {
// Stores information about song library
struct Library {
public:
    Library();

    ~Library();

    /* TODO
       Quickly find song in library */
    mpd_song *find_song();

    // Loads songs in MPD library into the playlist array
    void load_library();

    int get_song_count();

    // returns playlist
    MPD::Song *get();

    void sort_by_date();
    void sort_by_title();
    void print();
    void sort(std::function<std::string(MPD::Song)>);

private:
    void prep_library();

    std::vector<MPD::Song> playlist;

    // acts as upper bound for playlist array
    int song_count;

    mpd_tag_type current_sort;
};
}

#endif

