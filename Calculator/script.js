/* Display and Buttons */
const display = document.getElementById("display");
const clear = document.querySelector(".clear");
const equal = document.querySelector(".equal");
const decimal = document.querySelector(".decimal");

let numbers = document.querySelectorAll(".number");
let operators = document.querySelectorAll(".operator-btn");

/* Screens, Number, Operator Values */
let previousScreen = document.querySelector(".previous");
let currentScreen = document.querySelector(".current");

let currentNum = "";
let previousNum = "";
let operator = "";

const currentDisplayNumber = document.querySelector(".currentNumber");
const previousDisplayNumber = document.querySelector(".previousNumber");

/* Append to Display */

function appendToDisplay(input) {
  display.value += input;
}

/* Clear Button */

clear.addEventListener("click", clearCalculator);
function clearEntry() {
  display.value = "";
  currentNum = "";
  previousNum = "";
  operator = "";
  currentDisplayNumber.textContent = "";
  previousDisplayNumber.textContent = "";
}

/* Decimal */
decimal.addEventListener("click", () => {
  addDecimal();
});

/* Equal Button */
equal.addEventListener("click", () => {
  if (currentNum != "" && previousNum != "") {
    compute();
  }
});

/* Operate Function */

function handleOperator(op) {
  if (previousNum === "") {
    previousNum = currentNum;
    operatorCheck(op);
  } else if (currentNum === "") {
    operatorCheck(op);
  } else {
    compute();
    operator = op;
    currentDisplayNumber.textContent = "0";
    previousDisplayNumber.textContent = previousNum + " " + operator;
  }
}

function operatorCheck(text) {
  operator = text;
  previousDisplayNumber.textContent = previousNum + " " + operator;
  currentDisplayNumber.textContent = "0";
  currentNum = "";
}

/* ADD ERROR MESSAGE FOR DIVIDNG BY 0 */

/* ROUND OFFLONG DECIMALS */

function roundNumber(num) {
  return Math.round(num * 100000) / 100000;
}

/* Functions for Addition, Subtraction, Multiplication, Division */

/* Addition */

function addDecimal() {
  if (!currentNum.includes(".")) {
    currentNum += ".";
    currentDisplayNumber.textContent = currentNum;
  }
}

/* Display Results */

function displayResults() {
  if (previousNum.length <= 11) {
    currentDisplayNumber.textContent = previousNum;
  } else {
    currentDisplayNumber.textContent = previousNum.slice(0, 11) + "...";
  }
  previousDisplayNumber.textContent = "";
  operator = "";
  currentNum = "";
}

/* Keyboard Presses */
window.addEventListener("keydown", handleKeyPress);
function handleKeyPress(e) {
  e.preventDefault();
  if (e.key >= 0 && e.key <= 9) {
    handleNumber(e.key);
  }
  if (
    e.key === "Enter" ||
    (e.key === "=" && currentNum != "" && previousNum != "")
  ) {
    compute();
  }
  if (e.key === "+" || e.key === "-" || e.key === "/") {
    handleOperator(e.key);
  }
  if (e.key === "*") {
    handleOperator("x");
  }
  if (e.key === ".") {
    addDecimal();
  }
  if (e.key === "Backspace") {
    handleDelete();
  }
}