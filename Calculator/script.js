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

function appendToDisplay(input) {
  display.value += input;
}

function clearEntry() {
  display.value = "";
}

function allClear() {
  display.value = "";
  a.value = "";
  b.value = "";
  operator.value = "";
}

function operate() {
  try {
    // display.value = eval(display.value);
  }
  catch(error) {
    display.value = "Error";
  }
}
