#ifndef MPD_SONG_
#define MPD_SONG_
#include "mpd/tag.h"
#include <mpd/client.h>
#include <string>

namespace MPD {
// Struct for songs TODO
struct Song {
public:
    // Creates a song, moves one song fowards
    Song();

    // Deletes song, frees space
    ~Song();

    // Checks if it's currently safe to create a new song
    bool is_safe();

    // Getters, make for all the tags
    std::string get_date();
    std::string get_title();
    std::string get_artist();
    int get_length();

    // Don't know if necessary yet
    mpd_song *get(){ return song; };
    unsigned get_idx(){ return idx; };

private:
    std::string get_tag(mpd_tag_type tag) {
        return mpd_song_get_tag(song, tag, idx);
    }

    mpd_song *song;
    unsigned idx;
};
}

#endif

