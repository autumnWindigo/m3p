<script>
    import MainPlayerContent from "./MainPlayerContent.svelte";
    import Playbar from "./Playbar.svelte";
</script>

<div>
    <div id="player-background">
        <MainPlayerContent />
        <Playbar />
    </div>
</div>

<style>
    #player-background {
        height: 90vh;
        width: 100vw;
        background-color: #1C2126;
        border-radius: 1vw 1vw 3vw 3vw;

        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: flex-start;
        position: relative;
    }
</style>
