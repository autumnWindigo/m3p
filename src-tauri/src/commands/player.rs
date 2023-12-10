use std::collections::HashMap;
use serde::{Serialize, Deserialize};
use serde_json::{Value, json};
use youtube_dl::{self, YoutubeDl};

use async_mpd::{MpdClient, Status, Filter, Tag, Track, ToFilterExpr};

#[derive(Serialize, Deserialize)]
struct Song {
    id: u32,
    title: String,
    Artist: String,

}

#[tauri::command]
pub async fn toggle_play() {
    let mut client = MpdClient::new();
    client.connect("127.0.0.1:6600").await.expect("cannot connect to client");
    let _ = client.status().await;
    let _ = client.play().await;
}

#[tauri::command]
pub async fn mpd_status() -> Status {
    let mut client = MpdClient::new();
    client.connect("127.0.0.1:6600").await.expect("cannot connect to client");
    client.status().await.expect("Client cannot retrieve status")
}

// Doesn't do anything yet
#[tauri::command]
pub async fn update_library() {
    let mut client = MpdClient::new();
    client.connect("127.0.0.1:6600").await.expect("cannot connect to client");

    let songs = client.queue().await;
}

#[tauri::command]
pub async fn update_json() -> serde_json::Value {
    let mut client = MpdClient::new();
    let mut song_array = Vec::<Song>::new();
    client.connect("127.0.0.1:6600").await.expect("cannot connect to client");
    let songs = client.queue().await;

    for song in songs.unwrap() {
        song_array.push(Song {
            id: song.id.expect("No Id"),
            Artist: song.artist.expect("No Artist"),
            title: song.title.expect("No title")
        })
    }

    serde_json::Value::String(serde_json::to_string(&song_array).expect("Conversion to Json failed"))
}

#[tauri::command]
pub async fn search_title(title: String) -> Vec<Track> {
    let mut client = MpdClient::new();
    client.connect("127.0.0.1:6600").await.expect("cannot connect to client");

    let filter = Filter::new()
        .and(Tag::Title.contains(title));

    client.search(&filter).await.expect("Search Failed")
}

// Returns JSON output of the download
#[tauri::command]
pub async fn download_song(link: String) -> Value {
    let output = YoutubeDl::new(link)
        .socket_timeout("15")
        .extract_audio(true)
        .extra_arg("--force-ipv4")
        .extra_arg("--embed-thumbnail")
        .extra_arg("--embed-metadata")
        .extra_arg("--audio-format best")
        .extra_arg("--audio-quality 0")
        .run_raw_async().await; // Where music is stored

    output.unwrap()
}
