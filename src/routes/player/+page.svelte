<script>
  import Playbar from "./Playbar.svelte";
  import { writable, get } from "svelte/store";

  // Create a Svelte store for the songs array
  const songsStore = writable([]);

  // Becomes "song", which is an object with this structure: {artist, title, album, audioData}
  let selectedSong = null;

  const handleFileSelect = async (event) => {
    const newSongs = [];

    for (const file of event.target.files) {
      if (file.type.startsWith("audio/")) {
        const arrayBuffer = await file.arrayBuffer();
        const audioData = new Uint8Array(arrayBuffer);
        newSongs.push({
          title: file.name,
          artist: "Unknown Artist",
          album: "Unknown Album",
          audioData,
        });
      }
    }

    // Update the songs array in the store
    songsStore.set(newSongs);
    console.log("Files processed:", newSongs);
  };

  // Subscribe to changes in the songs store
  $: {
    const songs = get(songsStore);
    console.log("Songs updated:", songs);
  }

  function playSong(song) {
    selectedSong = song;
  }

</script>

<div>
  <div id="player-background">
    <div id="main-menu">
      <h2>Main Menu</h2>
      <input type="file" webkitdirectory directory multiple on:change={handleFileSelect} />
      <div id="table-container">
        <table>
          <thead>
            <tr>
              <th>Artist</th>
              <th>Song</th>
              <th>Album</th>
            </tr>
          </thead>
          <tbody>
            {#each $songsStore as { artist, title, album, audioData }}
            <tr on:click={() => playSong({ artist, title, album, audioData })}>
              <td>{artist}</td>
              <td>{title}</td>
              <td>{album}</td>
            </tr>
            {/each}
          </tbody>
        </table>
      </div>
    </div>
    <a id="back" href="/">
      back
    </a>
    {#if selectedSong}
    <Playbar {selectedSong}/>
    {/if}
  </div>
</div>

<style>
    #player-background {
        height: 90vh;
        width: 100vw;
        background-color: #1C2126;
        border-radius: 3vw;
        display: flex;
        flex-direction: column;
        align-items: center;
        position: relative;
    }

    #main-menu {
        padding: 20px;
        color: white;
        text-align: center;
        width: 90%;
    }

    #main-menu h2 {
        font-size: 1.5em;
        margin-bottom: 10px;
    }

    #table-container {
        max-height: 60vh;
        overflow-y: auto;
    }

    table {
        width: 100%;
        border-collapse: collapse;
        margin-top: 10px;
    }

    th, td {
        border: 1px solid #34495e;
        padding: 10px;
        text-align: left;
        color: white;
    }

    th {
        background-color: #2c3e50;
    }

    tr:hover {
        background-color: #2c3e50;
        transition: background-color 0.3s ease; /* Smooth transition for hover effect */
    }

    #back {
        background-color: ivory;
    }
</style>