#ifndef MPD_LIBRARY_
#define MPD_LIBRARY_
#include "song.h"
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

    void sort(mpd_tag_type);

private:
    void prep_library();

    MPD::Song *playlist;

    // acts as upper bound for playlist array
    int song_count;
};
}

#endif

