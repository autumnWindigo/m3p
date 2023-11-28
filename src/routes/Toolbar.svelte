<!-- Toolbar.svelte -->
<script>
    import { onMount } from 'svelte';

    let showToolbar = false;

    export function toggleToolbar() {
        showToolbar = !showToolbar;
    }

    onMount(() => {
        //Listen for keydown event on the document
        window.addEventListener('keydown', handleKeyDown);

        return () => {
            //Cleanup: Remove the event listener when the component is unmounted
            window.removeEventListener('keydown', handleKeyDown);
        }
    });

    function handleKeyDown(event) {
        // Check if the pressed key is '=' or '+'
        if (event.key === '=' || event.key === '+') {
            toggleToolbar();
        }
    }
</script>

<div class={`toolbar ${showToolbar ? '' : 'hidden'}`}>
    <!-- This is where we add our tool bar info -->
    <!-- I included some blank examples as a placeholder-->
    <p>m3p</p>
    <a href="/profile" on:click={toggleToolbar}>profile</a>
    <a href="/tools" on:click={toggleToolbar}>tools</a>
    <a href="/settings" on:click={toggleToolbar}>settings</a>
</div>

<style>
    .toolbar {
        display: flex;
        justify-content: space-evenly;

        background-color: #33373B;
        color: ivory;
        padding: 10px;
        position: fixed;
        top: 0;
        left: 0;
        right: 0;
        z-index: 1;
        transform: translateY(0);
        transition: transform 0.3s ease-in-out;
    }

    .toolbar.hidden {
        transform: translateY(-100%);
    }

    a {
        background-color: gold;
        /**scale: 0.75; when the buttons are scaled the hover animation bugs out, gotta fix this */
    }

    p {
        position: absolute;
        left: 1rem;
    }
</style>
