<!-- Toolbar.svelte -->
<script>
    import { onMount } from 'svelte';

    let showToolbar = true;

    export function toggleToolbar() {
        showToolbar = !showToolbar;
    }

    onMount(() => {
        //Listen for keydown event on the document
        window.addEventListener('keydown', handleKeyDown);

        return() => {
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
    <a href="/profile">profile</a>
    <a href="/tools">tools</a>
    <a href="/settings">settings</a>
</div>

<style>
    .toolbar {
        display: flex;
        justify-content: space-evenly;

        opacity: 0.9;
        background-color: #33373B;
        color: white;
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
    }
</style>
