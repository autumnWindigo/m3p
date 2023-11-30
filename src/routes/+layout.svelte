<script>
	import Toolbar from './Toolbar.svelte';
	import './global.css';
	import { colorMode } from './colorMode.js';
</script>

<div class="app" style="background-color: {$colorMode === 'dark' ? '#333': 'ivory'};">
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
