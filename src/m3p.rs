use std::str;
use async_mpd::MpdClient;
use serde_derive::{Serialize, Deserialize};

pub struct Connection {
    pub connection: MpdClient,
    pub ip: String
}

impl Connection {
    pub async fn init(&mut self) -> Result<String, async_mpd::Error> {
        self.connection.connect("127.0.0.1:6600").await
    }

    pub fn get_address(&self) -> &str {
        &self.ip
    }
}

#[derive(Default, Serialize, Deserialize)]
struct Config {
    mpd_ip: String,

}
