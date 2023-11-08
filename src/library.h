#ifndef MPD_LIBRARY_
#define MPD_LIBRARY_
#include "song.h"
#include <functional>
#include <mpd/client.h>

namespace MPD {

/**
 * @class Library
 * @brief Holds set of mpd_songs. Full mpd library by default, can act as a subset or playlist.
 *
 */
struct Library {
public:
    /**
     * @brief Constructor for Library
     */
    Library();

    /**
     * @brief Deconstructor for Library struct
     */
    ~Library();

    /**
     * @brief From the title of a song, returns pointer to song
     *
     * @param title Title of song
     * @return Pointer to song
     */
    mpd_song *find_song(std::string title);

    /**
     * @brief Initializes library with current system mpd library
     */
    void load_library();

    /**
     * @brief Creates subset which contains songs that match current search
     *
     * @param search Current search for songs
     * @return Subset matching search
     */
    Library find_songs(std::string search);

    /**
     * @brief returns total number of songs in library, -1 if empty.
     *
     * @return number of songs in Library
     */
    int get_song_count();

    /**
     * @brief Preforms on string tag using a getter which is passed as param
     *
     * @param get_tag_value Getter function which returns info from MPD::Song
     */
    void sort(std::function<std::string(MPD::Song)> get_tag_value);

    /**
     * @brief sorts current library by date
     */
    void sort_by_date();

    /**
     * @brief sorts current library by title
     */
    void sort_by_title();

    /**
     * @brief prints song titles in Library to standard out
     */
    void print();


private:
    /**
     * @brief Prepares Library to be innitialized
     */
    void prep_library();

    /**
     * @brief Vector of MPD::Song(s) that acts as the main playlist of the library
     */
    std::vector<MPD::Song> playlist;

    /**
     * @brief Number of songs in the Library
     */
    int song_count = 0;

    /**
     * @brief True if Library is currently sorted, false otherwise. Must be true for find_song(s).
     *
     */
    bool is_sorted = false;

    /**
     * @brief Returns mpd_tag_type of current sort, NULL if not sorted or custom sort.
     */
    mpd_tag_type current_sort;
};
}

#endif

