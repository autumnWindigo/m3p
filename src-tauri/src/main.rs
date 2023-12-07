// Prevents additional console window on Windows in release, DO NOT REMOVE!!
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]
mod commands;
mod client;
use commands::config;
use commands::player;

#[tokio::main]
async fn main() {
    tauri::async_runtime::set(tokio::runtime::Handle::current());

    tauri::Builder::default()
        .setup(|_app| {
            Ok(())
        })
        .invoke_handler(tauri::generate_handler![
            config::set_config_by_key,
            player::download_song,
            player::update_library,
            player::search_title,
            player::mpd_status,
            player::toggle_play,

        ])
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}
