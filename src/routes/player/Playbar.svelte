<script>
    let paused = true;

    function handlePlayPause() {
        paused = !paused;
    }
</script>

<div id="playbar-background">
    <button id="play-pause" on:click={handlePlayPause}>{paused ? "O" : "I"}</button>
    <input id="seek-slider" type="range">
    
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
        width: 80%;
        height: 0.25rem;
        border-radius: 0.25rem;
        background-color: #B7790B;
        
    }
    #seek-slider::-webkit-slider-thumb {
        -webkit-appearance: none;
        width: 0;
        height: 0;
    }
    #seek-slider:hover::-webkit-slider-thumb {
        width: 10px;
        height: 10px;
        background-color: ivory;
        border-radius: 10px;
    }

    #play-pause {
    }

</style>