<!-- Profile.svelte -->
<script>
    import { format } from 'date-fns';
    import { onMount, onDestroy } from 'svelte';

    let userName = "M3P Profile";
    let dateCreated = new Date();
    let bio = "Welcome to my music world! Proud customer of m3p";
    let isEditMode = false;

    function toggleEditMode() {
        isEditMode = !isEditMode;
    }

    const listeningStatistics = {
        labels: ['Rock', 'Pop', 'Electronic', 'Jazz', 'Hip Hop'],
        data: [20, 15, 10, 5, 50] // Example data, replace with actual statistics
    };

    let chart;

    onMount(() => {
        // Initialize the chart
        const ctx = document.querySelector('canvas').getContext('2d');
        chart = new Chart(ctx, {
            type: 'bar',
            data: {
                labels: listeningStatistics.labels,
                datasets: [{
                    label: 'Listening Statistics',
                    data: listeningStatistics.data,
                    backgroundColor: 'rgba(75, 192, 192, 0.2)',
                    borderColor: 'rgba(75, 192, 192, 1)',
                    borderWidth: 1
                }]
            },
            options: {
                responsive: true,
                maintainAspectRatio: false
            }
        });
    });

    onDestroy(() => {
        // Cleanup the chart when the component is unmounted
        chart.destroy();
    });
</script>

<div class="profile-container">
    <h1>User Profile</h1>

    <div class="user-info">
        <div class="profile-details">
            <p><strong>Name:</strong> {userName}</p>
            <p><strong>Date Created:</strong> {format(dateCreated, 'MMMM d, yyyy')}</p>
            <p><strong>Bio:</strong> {bio}</p>
        </div>
    </div>

    {#if isEditMode}
        <!-- Edit mode -->
        <div class="edit-mode">
            <label for="newBio">Update Bio:</label>
            <textarea bind:value={bio} id="newBio"></textarea>
        </div>
    {:else}
        <!-- View mode -->
        <div class="chart-container">
            <canvas bind:this={chart} />
        </div>
    {/if}

    <button on:click={toggleEditMode}>
        {#if isEditMode}
            Save Bio
        {:else}
            Edit Bio
        {/if}
    </button>
</div>

<style>
    /* styling for the profile page */
    /*
    body {
        font-family: 'Arial', sans-serif;
        background-color: #f8f8f8;
        margin: 0;
        padding: 0;
    }
    */
    .profile-container {
        max-width: 800px;
        margin: 50px auto;
        background-color: #fff;
        padding: 20px;
        border-radius: 8px;
        box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
    }

    h1 {
        color: #333;
    }


    .profile-details {
        text-align: left;
    }

    .edit-mode {
        margin-bottom: 20px;
    }

    textarea {
        width: 100%;
        height: 100px;
        resize: vertical;
        padding: 10px;
        border: 1px solid #ccc;
        border-radius: 4px;
    }

    .chart-container {
        width: 100%;
        margin: 20px 0;
    }

    button {
        background-color: #4CAF50;
        color: #fff;
        padding: 10px 20px;
        border: none;
        border-radius: 4px;
        cursor: pointer;
        font-size: 16px;
    }

    button:hover {
        background-color: #45a049;
    }
</style>