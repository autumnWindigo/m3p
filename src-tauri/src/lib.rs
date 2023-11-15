use neon::prelude::*;
use std::cell::RefCell;

mod m3p;

type BoxedM3p = JsBox<RefCell<m3p::Connection>>;


fn hello(mut cx: FunctionContext) -> JsResult<JsString> {
    Ok(cx.string("hello node"))
}

/// Brief: Takes m3p object and attempts a connection to server
/// Returns string detailing if successful or not, not sure if I can use
///   Results with javascript yet, so this is will change
/// * `cx`[0]: m3p object
fn m3p_connect(mut cx: FunctionContext) -> JsResult<JsString> {
    let con = cx.argument::<BoxedM3p>(0)?;
    let mut con = con.borrow_mut();
    con.init();
    match &con.connection {
        Some(_) => Ok(cx.string("Connect to mpd at:".to_owned() + con.get_ip())),
        None => cx.throw_error("Failed to connect to mpd")
    }
}

/// No Input
/// Returns m3p object who's lifetime is controlled by nodejs (ew but makes sense)
/// * `cx`:
fn m3p_new(mut cx: FunctionContext) -> JsResult<BoxedM3p> {
    Ok(cx.boxed(RefCell::new(m3p::Connection {
        // Replace once confy is running
        ip: "127.0.0.1:6600".to_string(),
        connection: None,
    })))
}

#[neon::main]
fn main(mut cx: ModuleContext) -> NeonResult<()> {
    cx.export_function("hello", hello)?;
    cx.export_function("m3p_new", m3p_new)?;
    cx.export_function("m3p_connect", m3p_connect)?;
    Ok(())
}
