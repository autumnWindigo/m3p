<script>
    import Playbar from "./Playbar.svelte";

</script>

<div>
    <div id="player-background">
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
        justify-content: center;
        align-items: flex-start;
        position: relative;
    }

    #back {
        background-color: ivory;
    }
</style>
