// Create and append the modal to the body
const modal = document.createElement('div');
modal.classList.add('modal');
modal.innerHTML = `
    <div class="modal-content">
        <h2>Game Over</h2>
        <p>Your Score: <span class="points"></span></p>
        <button class="close-button">Close</button>
    </div>
`;
document.body.appendChild(modal);

// Show modal when the game is over
function showModal() {
    modal.style.display = 'block';
    document.querySelector('.points').innerHTML = score; // Display score in modal
}

// Add event listener to close button
modal.querySelector('.close-button').addEventListener('click', () => {
    modal.style.display = 'none';
});

// Update the canPlay function to show modal on game over
function canPlay() {
    for (let i = 0; i < 4; i++) {
        for (let j = 0; j < 4; j++) {
            if (filledCell[i][j] == 0) {
                return 1;
            }
        }
    }
    showModal(); // Show modal if no moves are left
    return 0;
}
