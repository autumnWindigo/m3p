// Prevents additional console window on Windows in release, DO NOT REMOVE!!
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]
use tokio::sync::mpsc;
use tokio::sync::Mutex;
use tracing::info;
use tauri::Manager;

struct AsyncProcInputTx {
    inner: Mutex<mpsc::Sender<String>>,
}

#[tokio::main]
async fn main() {
    tracing_subscriber::fmt::init();

    let (async_proc_input_tx, async_proc_input_rx) = mpsc::channel(1);
    let (async_proc_output_tx, mut async_proc_output_rx) = mpsc::channel(1);
    tauri::Builder::default()
        .manage(AsyncProcInputTx {
            inner: Mutex::new(async_proc_input_tx),
        })
        .invoke_handler(tauri::generate_handler![send_ip])
        .setup(|app| {
            tauri::async_runtime::spawn(async move {
                async_process_model(async_proc_input_rx, async_proc_output_tx).await
            });

            let app_handle = app.handle();
            tauri::async_runtime::spawn(async move {
                loop {
                    if let Some(output) = async_proc_output_rx.recv().await {
                        rs2js(output, &app_handle);
                    }
                }
            });

            // Try stuff here?
            Ok(())
        })
        .run(tauri::generate_context!())
        .expect("Error while running tauri application")
}

#[tauri::command]
async fn send_ip(ip: String, state: tauri::State<'_, AsyncProcInputTx>) -> Result<(), String> {
    info!(?ip, "send_ip");
    println!("hi!");
    let async_proc_input_tx = state.inner.lock().await;
    async_proc_input_tx
        .send(ip)
        .await
        .map_err(|err| err.to_string())
}

// A function that sends a message from Rust to JavaScript via a Tauri Event
fn rs2js<R: tauri::Runtime>(message: String, manager: &impl Manager<R>) {
    info!(?message, "rs2js");
    manager
        .emit_all("rs2js", message)
        .unwrap();
}

// #[tauri::command]
// async fn attemp_connection() {
//
// }
//

async fn async_process_model(
    mut input_rx: mpsc::Receiver<String>,
    output_tx: mpsc::Sender<String>,
) -> Result<(), Box<dyn std::error::Error + Send + Sync>> {
    loop {
        while let Some(input) = input_rx.recv().await {
            let output = input;
            output_tx.send(output).await?;
        }
    }
}
