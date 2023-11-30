use std::collections::HashMap;

use async_mpd::{MpdClient, Status};


#[tauri::command]
pub async fn toggle_play() {
    let mut client = MpdClient::new();
    client.connect("127.0.0.1:6600").await;
    client.status();
}

#[tauri::command]
pub async fn mpd_status() -> Status {
    let mut client = MpdClient::new();
    client.connect("127.0.0.1:6600").await;
}

#[tauri::command]
pub async fn update_library() -> HashMap::<String, u32> {
    let mut song_map = HashMap::<String, u32>::new();
    let mut client = MpdClient::new();
    client.connect("127.0.0.1:6600").await;

    song_map
}
