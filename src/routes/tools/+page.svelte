<script>
    import { invoke } from '@tauri-apps/api/tauri';
  
    function skip() {
      try {
        invoke('skip');
        console.log('Skipped to the next track');
      } catch (error) {
        console.error('Error invoking skip:', error);
      }
    }
  
    function shuffle() {
      try {
        invoke('shuffle');
        console.log('Shuffled the playlist');
      } catch (error) {
        console.error('Error invoking shuffle:', error);
      }
    }
  </script>
  
  <main>
    <h1>Music Player Tools</h1>
    
    <button on:click={skip}>Skip to Next</button>
    <button on:click={shuffle}>Shuffle Playlist</button>
<div id="tools">
    <h1>tools</h1>
    <a href="/">back</a>
</div>

<style>
  #tools {
    display: flex;
    flex-direction: column;
    align-items: center;
  }
    main {
    display: flex;
    flex-direction: column;
    align-items: center;
    justify-content: center;
    height: 75vh;
    padding: 20px;
  }

  h1 {
    font-size: 24px;
    margin-bottom: 20px;
  }

  #tools {
    display: flex;
    flex-direction: column;
    align-items: center;
  }

  button {
    margin: 10px;
    padding: 10px;
    font-size: 16px;
    cursor: pointer;
  }

  a {
    margin-top: 20px;
    font-size: 16px;
    color: #black; 
    text-decoration: none;
    cursor: pointer;
  }
</style>
</main>