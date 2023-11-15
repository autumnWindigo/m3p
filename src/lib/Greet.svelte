<script>
    import { listen } from '@tauri-apps/api/event'
    import { invoke } from '@tauri-apps/api/tauri'

    let temp = '127.0.0.1'
    let ip = ''
    let dumb = ''

    console.log("hi")
    async function sendIP() {
        let response = invoke('send_ip', { temp })
        await listen('rs2js', (event) => { console.log(event.payload) })

    }

</script>

<div>
    <input id="greet-input" placeholder="Enter an ip..." bind:value="{dumb}" />
    <button on:click="{sendIP}">Greet</button>
    <p>{ip}</p>
</div>
