#ifndef MPD_SONG_
#define MPD_SONG_
#include "mpd/tag.h"
#include <mpd/client.h>
#include <string>

namespace MPD {
// Struct for songs TODO
/**
 * @class Song
 * @brief Wrapper class for mpd_song
 *
 */
struct Song {
public:

    /**
     * @brief Constructor, sets song to current mpd_song in que.
     */
    Song();

    /**
     * @brief Deconstructor, frees mpd_song
     */
    ~Song();

    /**
     * @brief Checks if object is valid for use
     *
     * @return true if valid, false if not
     */
    bool is_safe();

    /**
     * @brief Getter for date tag in audio file
     */
    std::string get_date();

    /**
     * @brief Getter for title tag in audio file
     */
    std::string get_title();

    /**
     * @brief Getter for artist tag in audio file
     */
    std::string get_artist();
    int get_length();

    /**
     * @brief Getter for mpd_song pointer
     *
     * @return mpd_song in object, nullptr if failed to innitialize
     */
    mpd_song *get(){ return song; };

    /**
     * @brief Getter for idx
     *
     * @return unsigned idx
     */
    unsigned get_idx(){ return idx; };

private:
    /**
     * @brief General Getter for pre-defined MPD tags in audio files
     *
     * @param tag Tag which you want to get
     * @return Contents of the tag
     */
    std::string get_tag(mpd_tag_type tag) {
        return mpd_song_get_tag(song, tag, idx);
    }

    /**
     * @brief pointer to mpd_song
     */
    mpd_song *song;

    /**
     * @brief unsigned int needed for mpd_song_get_tag()
     */
    unsigned idx;
};
}

#endif

