use async_mpd::MpdClient;
use async_mpd::Error;
use async_mpd::Track;
use tokio::sync::Mutex;
use std::sync::Arc;

struct M3pState {
    connection: Arc<Mutex<MpdClient>>,
    setlist: Arc<Mutex<Vec<Track>>>,
}


impl M3pState {
    /// * Constructor for M3pState
    pub fn new() -> Self {
        Self {
            // Share connection across threads
            connection: Arc::new(Mutex::new(MpdClient::new())),
            setlist: Arc::new(Mutex::new(Vec::new()))
        }
    }

    async fn init(&self, ip: String) -> Result<(), async_mpd::Error> {
        // Arc::try_unwrap(self.connection);

        Ok(())
    }


    /// Check connection. If errors try to resolve connection to server.
    /// * return: Result -> Ok if connection is set, Error otherwise
    /// * `client`: async_MpdClient connection
    async fn check_connection(mut client: MpdClient) -> Result<(), async_mpd::Error> {
        match client.status().await {
            Ok(_) => Ok(()),
            Err(e) => {
                match e {
                    // Retry Connection
                    Error::Disconnected => match client.connect("127.0.0.1").await {
                        Ok(_) => Ok(()),
                        Err(_) => panic!("Couldn't establish mpd connection")
                    },
                    Error::CommandError { msg } => panic!("CommandError: {}", msg),
                    Error::IOError(_) => panic!("IO Error"),
                    Error::ValueError { msg } => panic!("Value Error: {}", msg),
                    Error::ServerError { msg } => panic!("Server Error: {}", msg),
                    Error::ParseInteError(_) => panic!("Parse Inte Error"),
                }
            }
        }
    }
}
