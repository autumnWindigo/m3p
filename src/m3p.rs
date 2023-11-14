// Import necessary libraries
use std::str;
use mpd::Client;
use serde_derive::{Serialize, Deserialize};
use neon::types::Finalize;

// Define a struct to represent a connection to an MPD server
pub struct Connection {
    pub connection: Option<Client>, // Optional MPD client connection
    pub ip: String // IP address associated with the connection
}

// Implement the Finalize trait for the Connection struct
impl Finalize for Connection {}

// Implement methods for the Connection struct
impl Connection {
    // Method to initialize the connection to the MPD server
    pub fn init(&mut self) {
        // Attempt to connect to the MPD server at "127.0.0.1:6600"
        self.connection = match Client::connect("127.0.0.1:6600") {
            Ok(result) => Some(result), // If successful, store the client connection
            Err(_) => None // If unsuccessful, store None
        }
    }

    // Method to get the IP address associated with the connection
    pub fn get_ip(&self) -> &String {
        &self.ip
    }
    pub fn new(ip: String) -> Self {
            Self {
                connection: None,
                ip,
            }
        }
}

// Define a configuration struct with default, serializable, and deserializable attributes
#[derive(Default, Serialize, Deserialize)]
struct Config {
    mpd_ip: String, // MPD server IP address
    vim_binds: bool // Boolean flag for Vim key bindings
}