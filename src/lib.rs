use async_mpd::MpdClient;
use once_cell::sync::OnceCell;
use tokio::runtime::Runtime;
use neon::prelude::*;
use neon::types::JsPromise;
mod m3p;

// Return a global tokio runtime or create one if it doesn't exist.
// Throws a JavaScript exception if the `Runtime` fails to create.
fn runtime<'a, C: Context<'a>>(cx: &mut C) -> NeonResult<&'static Runtime> {
    static RUNTIME: OnceCell<Runtime> = OnceCell::new();

    RUNTIME.get_or_try_init(|| Runtime::new().or_else(|err| cx.throw_error(err.to_string())))
}

fn hello(mut cx: FunctionContext) -> JsResult<JsString> {
    Ok(cx.string("hello node"))
}

fn mpd_connect(mut cx: FunctionContext) -> JsResult<JsPromise> {
    let rt = runtime(&mut cx)?;
    let (deferred, promise) = cx.promise();
    let channel = cx.channel();
    let mut con = m3p::Connection{
        ip: "127.0.0.1:6600".to_string(),
        connection: MpdClient::new()
    };

    rt.spawn(async move {
        let result = con.init().await;
        deferred.settle_with(&channel, move |mut cx| {
            match result {
            Ok(result) => Ok(cx.string(result)),
            Err(_) => cx.throw_error("Could Not Connect to MPD")
            }
        })
    });
    Ok(promise)
}


#[neon::main]
fn main(mut cx: ModuleContext) -> NeonResult<()> {
    cx.export_function("hello", hello)?;
    cx.export_function("m3p_get_ip", mpd_connect)?;
    Ok(())
}
