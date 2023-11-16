<script>
    let paused = true;
    function handlePlayPause() {
        paused = !paused;
    }

    let volume = 0;
</script>

<div id="playbar-background">
    <button id="play-pause" on:click={handlePlayPause}>{paused ? "\u23F8" : "\u23F5"}</button>
    <input id="seek-slider" type="range" value="0">
    <input id="volume" type="range" bind:value={volume}>
    
</div>

<style>
    #playbar-background {
        width: 100%;
        height: 4rem;
        background-color: black;
        position: absolute;
        bottom: 0;

        border-radius: 3vw;

        display: flex;
        align-items: center;
        justify-content: center;
    }

    #seek-slider {
        -webkit-appearance: none;
        appearance: none;
        width: 80%;
        height: 0.25rem;
        border-radius: 0.25rem;
        background-color: #B7790B;
        
    }

    #seek-slider::-webkit-slider-thumb {
        -webkit-appearance: none;
        appearance: none;
        width: 0;
        height: 0;
    }
    #seek-slider:hover::-webkit-slider-thumb {
        width: 5px;
        height: 10px;
        background-color: ivory;
        border-radius: 10px;
        border: "solid";
        border-width: 0;
    }

    #seek-slider::-moz-range-thumb {
        width: 0;
        height: 0;
    }
    #seek-slider:hover::-moz-range-thumb {
        width: 5px;
        height: 10px;
        background-color: ivory;
        border-radius: 10px;
        border-width: 0;
    }

    #play-pause {
        appearance: none;
        border: none;
        background-color: inherit;
        color: gold;
        width: 3rem;
    }

    #volume {
        -webkit-appearance: none;
        appearance: none;
        width: 20%;
        height: 0.25rem;
        border-radius: 0.25rem;
        margin: 0 1rem;
        background-color: gold;
    }

    #volume::-moz-range-thumb {
        width: 10px;
        height: 10px;
        background-color: ivory;
        border-radius: 10px;
        border: "solid";
        border-color: #1C2126;
    }

</style>