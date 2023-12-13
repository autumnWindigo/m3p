use std::collections::HashMap;

use async_mpd::{MpdClient, Status};

#[tauri::command]
pub async fn time_return() -> i32 {
    let mut client = MpdClient::new();
   client.connect("127.0.0.1:6600").await.expect("cannot connect to client");
    client.time.into();
}