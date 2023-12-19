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
</style>
</main>