<script>
    let paused = true;
    let volume = 50;
    let audio = new Audio();

    export let selectedSong;

    let playbackPosition = 0;
    let duration = 0;

    // Function to handle play/pause
    function handlePlayPause() {
        paused = !paused;

        const { audioData } = selectedSong;
        const audioBlob = new Blob([audioData], { type: "audio/mpeg" });
        const audioUrl = URL.createObjectURL(audioBlob);

        audio.src = audioUrl;
        audio.currentTime = playbackPosition; // Set the playback position
        audio.volume = volume / 100;

        // Event listener to update duration when metadata is loaded
        audio.addEventListener("loadedmetadata", () => {
            duration = audio.duration;
        });

        if (!paused) {
            audio.play();
        } else {
            audio.pause();
        }
    }

    // Function to handle volume change
    function handleVolumeChange() {
        audio.volume = volume / 100;
    }

    // Function to handle seek slider change
    function handleSeekSliderChange(event) {
        playbackPosition = event.target.value;
        audio.currentTime = playbackPosition;
    }

    // Event listener to update playback position continuously
    audio.addEventListener("timeupdate", () => {
        if (!audio.paused) {
            playbackPosition = audio.currentTime;
        }
    });

</script>

<div id="playbar-background">
    <button id="play-pause" on:click={handlePlayPause}>
        {paused ? "\u23F5" : "\u23F8"}
    </button>
    <input
        id="seek-slider"
        type="range"
        bind:value={playbackPosition}
        max={duration}
        on:input={handleSeekSliderChange}
    />
    <input
        id="volume"
        type="range"
        min="0"
        max="100"
        bind:value={volume}
        on:input={handleVolumeChange}
    />
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
        background-color: #b7790b;
        transition: 0.2s;
    }

    #seek-slider:hover {
        background-color: #ffb916;
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
        background-color: #1c2126;
        color: #ffcf50;
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
        background-color: #1c2126;
    }

    #volume::-webkit-slider-thumb {
        -webkit-appearance: none;
        appearance: none;
        width: 0.5rem;
        height: 0.5rem;
        background-color: ivory;
        border-radius: 0.5rem;
        border: "solid";
        border-color: #1c2126;
        border-width: 2px;
        transition: 0.1s;
    }

    #volume::-moz-range-thumb {
        width: 0.5rem;
        height: 0.5rem;
        background-color: ivory;
        border-radius: 0.5rem;
        border: "solid";
        border-color: #1c2126;
        transition: 0.1s;
    }

    #volume:hover::-webkit-slider-thumb {
        width: 1rem;
        height: 1rem;
        border-radius: 1rem;
    }

    #volume:hover::-moz-range-thumb {
        width: 1rem;
        height: 1rem;
        border-radius: 1rem;
    }

    #volume::-moz-range-progress {
        background-color: gold;
    }
</style>
