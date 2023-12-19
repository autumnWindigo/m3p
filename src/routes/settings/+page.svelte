<!-- Settings +page.svelte -->
<script>
	import { onMount } from 'svelte';
	import { colorMode } from '../colorMode.js';
	
	let userName = "John Doe";
	let isAutoPlayEnabled = false;
	
	function toggleAutoPlay() {
		isAutoPlayEnabled = !isAutoPlayEnabled;
		// Add logic to handle auto-play state change
		console.log("Auto-play state changed:", isAutoPlayEnabled);
	}
	
	function toggleDarkMode() {
		colorMode.update(mode => (mode === 'light' ? 'dark' : 'light'));
		console.log("Dark mode state changed:", $colorMode);
	}
	
	function updateBackgroundColor() {
		const body = document.body;
		if ($colorMode == 'dark') {
			body.style.backgroundColor = '#333';
		} else {
			body.style.backgroundColor = 'ivory';
		}
	}
	
	onMount(() => {
		updateBackgroundColor();
	});
	
</script>

<main>
    <div class="settings-container">
        <div class="toggle">
            <p>auto-play</p>
            <label>
                <input type="checkbox" bind:checked={isAutoPlayEnabled} />
                <span class="slider"></span>
            </label>
        </div>

		<div class="toggle">
			<p>dark mode</p>
            <label>
                <input type="checkbox" on:click={toggleDarkMode} />
                <span class="slider"></span>
            </label>
		</div>
	</div>

	<div class="additional-info">
        <a href="/">Listening history</a> <!-- at some point we can import an array that adds on any song listened to in the session -->
        <a href="/">Back</a>
	</div>
</main>

<style>
	/* styling for the settings page */
		main {
		position: relative;
		display: flex;
		flex-direction: column;
		justify-content: center;
		align-items: center;
		height: 75vh;
	}

	.settings-container {
		display: flex;
		flex-direction: column;
		align-items: center;
		padding: 20px;
		border-radius: 8px;
		margin-bottom: 20px;
		background-color: transparent; /* Remove explicit background color */
		box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); /* Add a subtle box-shadow for separation */
	}

	.additional-info {
	justify-content:center;
	display: flex;
	}

	p {
	margin: 0 20px 0 0;
	font-weight: bold;
	color: #333;
	}

	.toggle {
	display: flex;
	align-items: center;
	margin-top: 20px;
	}

	a {
	margin: 1rem;
	color: #333;
	text-decoration: none;
	}

	label {
	position: relative;
	width: 60px;
	height: 34px;
	}

	input {
	display: none;
	}

	.slider {
	position: absolute;
	cursor: pointer;
	inset: 0;
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