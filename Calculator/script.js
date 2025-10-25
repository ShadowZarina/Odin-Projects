const display = document.getElementById("display");

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
