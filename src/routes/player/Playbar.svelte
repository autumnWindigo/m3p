<script>
    let paused = true;
    let volume = 50;

    function handlePlayPause() { paused = !paused; }
</script>

<div id="playbar-background">
    <button id="play-pause" on:click={handlePlayPause}>{paused ? "\u23F5" : "\u23F8"}</button>
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
        transition: 0.2s;
        
    }

    #seek-slider:hover {
        background-color: #FFB916;
    }

    #seek-slider::-webkit-slider-thumb {
        -webkit-appearance: none;
        appearance: none;
        width: 0;
        height: 0;
        transition: 0.2s;
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
        transition: 0.2s;
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
        background-color: #1C2126;
        color: gold;
        border-radius: 3rem;
        margin: 0 1.5rem;
        scale: 1.25;
    }

    #volume {
        -webkit-appearance: none;
        appearance: none;
        width: 20%;
        height: 0.25rem;
        border-radius: 0.25rem;
        margin: 0 1rem;
        background-color: #1C2126;
    }

    #volume::-webkit-slider-thumb {
        width: 10px;
        height: 10px;
        background-color: ivory;
        border-radius: 10px;
        border: "solid";
        border-color: #1C2126;
    }

    #volume::-moz-range-thumb {
        width: 10px;
        height: 10px;
        background-color: ivory;
        border-radius: 10px;
        border: "solid";
        border-color: #1C2126;
    }

    #volume::-moz-range-progress {
        background-color: gold;
    }

</style>