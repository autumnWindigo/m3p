#ifndef MPD_LIBRARY_
#define MPD_LIBRARY_
#include <mpd/client.h>

namespace MPD {
// Stores information about song library
struct Library {
public:
    Library();

    /* TODO
       Quickly find song in library */
    mpd_song *find_song();


private:
};
}

#endif

