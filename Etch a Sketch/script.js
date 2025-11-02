const container = document.querySelector(".container");
const button = document.querySelector(".input");

function generateGrid(size) {
    let grid_size = parseInt(size);
    if (isNaN(grid_size) || grid_size < 8 || grid_size > 64) {
        alert("Please enter a number between 8 and 64. Defaulting to 10.");
        grid_size = 10;
    }

    container.innerHTML = "";
    container.style.gridTemplateColumns = `repeat(${grid_size}, 1fr)`;
    container.style.gridTemplateRows = `repeat(${grid_size}, 1fr)`;

    for (let i = 0; i < grid_size * grid_size; i++) {
        let box = document.createElement("div");
        box.classList.add("box");
        box.addEventListener("mouseover", changeColor);
        container.appendChild(box);
    }
}

function randomColor() {
    let r = Math.floor(Math.random() * 256);
    let g = Math.floor(Math.random() * 256);
    let b = Math.floor(Math.random() * 256);
    return `rgb(${r}, ${g}, ${b})`;
}

function changeColor(e) {
    e.target.style.backgroundColor = randomColor();
}

button.addEventListener("click", () => {
    const sizeInput = prompt("Enter the number of squares per side for the new grid (8-64):"); // **UPDATED PROMPT MESSAGE**

    if (sizeInput === null || sizeInput.trim() === "") {
        return; 
    }

    const newSize = parseInt(sizeInput);

    if (!isNaN(newSize) && newSize >= 8 && newSize <= 64) {
        generateGrid(newSize);
    } else {
        alert("Invalid input. Please enter a number between 8 and 64."); // **UPDATED ALERT MESSAGE**
    }
});

window.addEventListener("load", () => {
    generateGrid(10);
});