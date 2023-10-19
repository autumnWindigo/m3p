#include "song.h"
#include "mpd/song.h"
#include "mpd_connection.h"
#include <cassert>

/**
 * Constructor for the Song class.
 *
 * Initializes the Song object by receiving a song from the MPD connection and setting the index to 0.
 */
namespace MPD {
Song::Song() : song(mpd_recv_song(MPD::Connection::instance()->get())),
                idx(0) {}

/**
 * Destructor for the Song class.
 *
 * Frees the memory associated with the MPD song when the Song object is destroyed.
 */
Song::~Song() {
    mpd_song_free(song);
}

/** Get the date of the song.
  * @return A string representing the date of the song, or nullptr if the song is not safe.
  */

std::string Song::get_date() {
    if (is_safe()) return nullptr;
    return mpd_song_get_tag(song, MPD_TAG_DATE, idx);
}

/** Get the title of the song.
 *  @return A string representing the title of the song, or nullptr if the song is not safe.
 */
std::string Song::get_title() {
    if (is_safe()) return nullptr;
    assert(song);
    return mpd_song_get_tag(song, MPD_TAG_TITLE, idx);
}

/** Get the artist of the song.
 * @return A string representing the artist of the song, or nullptr if the song is not safe.
 */
std::string Song::get_artist() {
    if (is_safe()) return nullptr;
    assert(song);
    return mpd_song_get_tag(song, MPD_TAG_ARTIST, idx);
}

/** Get the length of the song in seconds.
 * @return The length of the song in seconds, or -1 if the song is not safe.
 */
int Song::get_length() {
    if (is_safe()) return -1;
    return mpd_song_get_duration(song);
}


/** Check if the song is safe (not null or in an error state).
 * @return true if the song is safe, false otherwise.
 */
bool Song::is_safe() {
    if ( song == NULL )
        return false;
    return true;
}

}
