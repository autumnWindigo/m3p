#ifndef MPD_LIBRARY_
#define MPD_LIBRARY_
#include "song.h"
#include <mpd/client.h>

namespace MPD {
// Stores information about song library
struct Library {
public:
    Library();

    /* TODO
       Quickly find song in library */
    mpd_song *find_song();

    void load_library();

    int get_song_count();

private:
    void prep_library();

    MPD::Song *playlist;
    int song_count;
};
}

#endif

