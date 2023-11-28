<script>
	import Toolbar from './Toolbar.svelte';
	import { Router, Route } from 'svelte-routing';
	import './global.css';
	import Profile from './Profile.svelte';
	import Settings from './Settings.svelte';
</script>

<div class="app">
	<Toolbar/>
	<main>
		<slot />
	</main>

	<footer>
		<p>m3p music player</p>
	</footer>
</div>

<style>
	.app {
		display: flex;
		flex-direction: column;
		align-items: center;
		min-height: 100vh;
		background-color: ivory;
	}

	main {
		flex: 1;
		display: flex;
	}

	footer {
		display: flex;
		flex-direction: column;
		justify-content: center;
		align-items: center;
		padding: 12px;
	}

	@media (min-width: 480px) {
		footer {
			padding: 12px 0;
		}
	}
</style>
