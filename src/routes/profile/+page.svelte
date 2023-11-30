<!-- Profile.svelte -->
<script>
	import { createEventDispatcher } from 'svelte';

	let userName = "John Doe";
	let userEmail = "john@example.com";
	let favoriteSongs = ["Song 1", "Song 2", "Song 3"];
	let newEmail = '';
	let isEditingEmail = false;

	const dispatch = createEventDispatcher();

	function toggleEditEmail() {
		isEditingEmail = !isEditingEmail;
		if (!isEditingEmail) {
			// Save the new email when editing is done
			userEmail = newEmail;
			dispatch('emailChanged', newEmail);
		}
	}

	function submitNewEmail() {
		toggleEditEmail();
	}
</script>

<main class ="profile-page">
	<section class="profile-info">
		<h1>{userName}'s Profile</h1>
		<p>
			Email: {#if isEditingEmail}
				<input bind:value={newEmail} />
				<button on:click={submitNewEmail}>Submit</button>
			{:else}
				{userEmail}
				<button on:click={toggleEditEmail}>Edit Email</button>
			{/if}
		</p>
	</section>

	<section class="favorite-songs">
		<h2>Favorite Songs</h2>
		<ul>
			{#each favoriteSongs as song (song)}
				<li>{song}</li>
			{/each}
		</ul>
	</section>
	<div>
		<a href="/">Back</a>
	</div>
</main>

<style>
	main.profile-page {
	display: flex;
	flex-direction: column;
	align-items: center;
	padding: 20px;
	}

	.profile-info {
	margin-bottom: 20px;
	text-align: center;
	}

	input {
	margin-right: 10px;
	padding: 8px;
	font-size: 16px;
	}

	button {
	background-color: #2196F3;
	color: #fff;
	border: none;
	border-radius: 4px;
	padding: 8px;
	cursor: pointer;
	font-size: 16px;
	}

	.favorite-songs {
	text-align: center;
	margin-top: 20px;
	margin-bottom: 70px;
	}

	ul {
	list-style-type: none;
	padding: 0;
	}

	li {
	margin-bottom: 8px;
	}
</style>