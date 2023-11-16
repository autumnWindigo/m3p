use async_mpd::{MpdClient, cmd};
use async_mpd::Error;


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
