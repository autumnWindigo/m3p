<!-- Settings.svelte -->
<script>
    let userName = "John Doe";
    let isAutoPlayEnabled = false;
	let yes = false;

    function toggleAutoPlay() {
        isAutoPlayEnabled = !isAutoPlayEnabled;
        // Add logic to handle auto-play state change
        console.log("Auto-play state changed:", isAutoPlayEnabled);
    }
</script>

<main>
	<h1>{userName}'s Settings</h1>
	<h2>Auto-play</h2>
	<label>
		<input type="checkbox" bind:checked={isAutoPlayEnabled}/>
		<span class="slider"></span>
	</label>
	<h3>Subscribe to email</h3>
	<label>
		<input type="checkbox" bind:checked={yes} />
	</label>
	{#if yes}
	<p>Thank you. We will bombard your inbox and sell your personal details.</p>
	{:else}
	<p>If you're not paying, you're the product.</p>
	{/if}
	<button disabled={!yes}> Subscribe </button>
	
	<p>Change color</p>
	<a href="/">About</a>
	<a href="/">Back</a>
	
</main>


<style>
    /* Add styling for the settings page */
    .settings-container {
        padding: 20px;
    }

    .auto-play-toggle {
        display: flex;
        align-items: center;
        margin-top: 20px;
    }

    label {
        position: relative;
        display: inline-block;
        width: 60px;
        height: 34px;
    }

    input {
        display: none;
    }

    .slider {
        position: absolute;
        cursor: pointer;
        top: 0;
        left: 0;
        right: 0;
        bottom: 0;
        background-color: #ccc;
        border-radius: 34px;
        transition: .4s;
    }

    input:checked + .slider {
        background-color: #2196F3;
    }

    .slider:before {
        position: absolute;
        content: "";
        height: 26px;
        width: 26px;
        left: 4px;
        bottom: 4px;
        background-color: white;
        border-radius: 50%;
        transition: .4s;
    }

    input:checked + .slider:before {
        transform: translateX(26px);
    }
</style>