#include "song.h"
#include "library.h"
#include "mpd_connection.h"

namespace MPD{
// just testing to figure this out, it's weird
//mpd_send_list_queue_meta(MPD::Connection::instance()->get());

// We need to allocate memory as we go for the library
// Can't know the size it takes until it's already made.
// loop through songs from MPD until null
// and on each song allocate more memory to array
}
