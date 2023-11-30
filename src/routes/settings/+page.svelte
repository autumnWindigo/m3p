<!-- Settings +page.svelte -->
<script>
	import { onMount } from 'svelte';
	import { colorMode } from './colorMode.js';
	
	let userName = "John Doe";
	let isAutoPlayEnabled = false;
	
	function toggleAutoPlay() {
		isAutoPlayEnabled = !isAutoPlayEnabled;
		// Add logic to handle auto-play state change
		console.log("Auto-play state changed:", isAutoPlayEnabled);
	}
	
	function toggleDarkMode() {
		colorMode.update(mode=> (mode === 'light' ? 'dark' : 'light'));
		console.log("Dark mode state changed:", $colorMode);
	}
	
	$: updateBackgroundColor();
	
	function updateBackgroundColor() {
		const body = document.body;
		if ($colorMode == 'dark'){
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
	<h1>{userName}'s Settings</h1>

	<div class="auto-play-toggle">
		<p>Auto-play</p>
		<label>
			<input type="checkbox" bind:checked={isAutoPlayEnabled}/>
			<span class = "slider"></span>
		</label>
	</div>

    <p class="section-heading">Change Color</p>
	<button on:click={toggleDarkMode} class="color-mode-button">
		Toggle Dark Mode: {$colorMode === 'dark' ? 'On' : 'Off'}
	</button>

    <a href="/">About us</a>
	<a href="/">Listening history</a> /*at some point we can import an array that adds on any song listened to in the session*/
    <a href="/">Back</a>
</main>
<style>
	main {
	padding: 20px;
	display: flex;
	flex-direction: column;
	align-items: center;
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
	width: 60px;
	height: 34px;
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

	.color-mode-button {
	margin-top: 10px;
	padding: 10px;
	background-color: #2196F3; /* Set a background color for better visibility */
	color: #fff; /* Set text color */
	cursor: pointer;
	border: none;
	border-radius: 4px;
	}
</style>