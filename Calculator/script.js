const display = document.getElementById("display");
const clear = document.querySelector(".clear");
const equal = document.querySelector(".equal");
const decimal = document.querySelector(".decimal");

let numbers = document.querySelectorAll(".number");
let oeprators = document.querySelectorAll(".operator-btn");

let previousScreen = document.querySelector(".previous");
let currentScreen = document.querySelector(".current");

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
