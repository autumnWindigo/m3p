<!-- Settings +page.svelte -->
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
    <p class="settings-heading">{userName}'s Settings</p>

    <p class="section-heading">Auto-play Settings</p>
    <div class="auto-play-toggle">
        <input type="checkbox" bind:checked={isAutoPlayEnabled}/>
        <span class="slider"></span>
    </div>

    <p class="section-heading red-bold">Subscribe to Email</p>
    <label class="subscribe-label">
        <input type="checkbox" bind:checked={yes} />
        <span class="subscribe-text">Subscribe</span>
    </label>

    {#if yes}
        <p>Thank you. We will bombard your inbox and sell your personal details.</p>
    {:else}
        <p>If you're not paying, you're the product.</p>
    {/if}

    <button disabled={!yes}>Subscribe</button>

    <p class="section-heading">Change Color</p>

    <a href="/">About us</a>
    <a href="/">Back</a>
</main>
<style>
	main {
		padding: 20px;
	}

	.auto-play-toggle {
		display: flex;
		align-items: center;
		margin-top: 20px;
	}
	
	.settings-heading{
		font-size: 1.5em;
		margin-bottom: 10px;
	}
	
	.section-heading{
		font-size: 1.2em;
		margin-bottom: 10px;
	}
	
	.red-bold{
		color: red;
		font-weight: bold;
	}
	
	.subscribe-label {
		display: flex;
		align-items:center;
		margin-top: 10px;
		cursor: pointer;
	}
	
	.subscribe-label input {
		display: none;
	}
	
	.subscribe-text {
		margin-left: 5px;
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