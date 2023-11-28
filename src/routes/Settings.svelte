<!-- Settings.svelte -->
<script>
    let userName = "John Doe";
    let isAutoPlayEnabled = false;

    function toggleAutoPlay() {
        isAutoPlayEnabled = !isAutoPlayEnabled;
        // Add logic to handle auto-play state change
        console.log("Auto-play state changed:", isAutoPlayEnabled);
    }
</script>

<div class="settings-container">
    <h1>{userName}'s Settings</h1>

    <div class="auto-play-toggle">
        <p>Auto-play</p>
        <label>
            <input type="checkbox" bind:checked={isAutoPlayEnabled} />
            <span class="slider"></span>
        </label>
    </div>
</div>

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