use std::collections::HashMap;

use async_mpd::{MpdClient, Status};

#[tauri::command]
pub async fn time_change(newTime: i32) -> null{
    let mut client = MpdClient::new();
    client.connect("127.0.0.1:6600").await.expect("cannot connect to client");
    client.shuffle().await?;
}