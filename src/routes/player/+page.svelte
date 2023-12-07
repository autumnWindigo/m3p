<script>
    import Playbar from "./Playbar.svelte";

    let songs = [
        { artist: 'Artist 1', title: 'Song 1', album: 'Album 1' },
        { artist: 'Artist 2', title: 'Song 2', album: 'Album 2' },
        { artist: 'Artist 3', title: 'Song 3', album: 'Album 3' },
    ];
</script>

<div>
    <div id="player-background">
        <div id="main-menu">
            <h2>Main Menu</h2>
            <table>
                <thead>
                    <tr>
                        <th>Artist</th>
                        <th>Song</th>
                        <th>Album</th>
                    </tr>
                </thead>
                <tbody>
                    {#each songs as { artist, title, album }}
                        <tr>
                            <td>{artist}</td>
                            <td>{title}</td>
                            <td>{album}</td>
                        </tr>
                    {/each}
                </tbody>
            </table>
        </div>
        <a id="back" href="/">back</a>
        <Playbar />
    </div>
</div>

<style>
    #player-background {
        height: 90vh;
        width: 98vw;
        background-color: #1C2126;
        border-radius: 3vw;
        display: flex;
        flex-direction: column;
        align-items: flex-start;
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
