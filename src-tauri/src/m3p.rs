use std::str;
use mpd::Client;
use serde_derive::{Serialize, Deserialize};
use neon::types::Finalize;

pub struct Connection {
    pub connection: Option<Client>,
    pub ip: String
}

impl Finalize for Connection {}

impl Connection {
    pub fn init(&mut self) {
        self.connection = match Client::connect("127.0.0.1:6600") {
            Ok(result) => Some(result),
            Err(_) => None
        }
    }

    pub fn get_ip(&self) -> &String {
        &self.ip
    }
}

#[derive(Default, Serialize, Deserialize)]
struct Config {
    mpd_ip: String,
    vim_binds: bool
}
