playGame();

function getHumanChoice() {
    let humanChoice = prompt("Enter Rock, Paper, or Scissors");
    return humanChoice.toLowerCase();
}

function getComputerChoice() {
    const choices = ["rock", "paper", "scissors"];
    const randomIndex = Math.floor(Math.random() * choices.length);
    return choices[randomIndex];
}

function playGame() {
    let humanScore = 0;
    let computerScore = 0;

    function capitalize(word) {
        return word.charAt(0).toUpperCase() + word.slice(1);
    }

    function playRound(humanChoice, computerChoice) {
        if (humanChoice === computerChoice) {
            console.log(`It's a tie! You both chose ${capitalize(humanChoice)}.`);
        } else if (
            (humanChoice === "rock" && computerChoice === "scissors") ||
            (humanChoice === "paper" && computerChoice === "rock") ||
            (humanChoice === "scissors" && computerChoice === "paper")
        ) {
            console.log(`You win! ${capitalize(humanChoice)} beats ${capitalize(computerChoice)}.`);
            humanScore++;
        } else {
            console.log(`You lose! ${capitalize(computerChoice)} beats ${capitalize(humanChoice)}.`);
            computerScore++;
        }
    }

    for (let i = 1; i <= 5; i++) {
        let humanChoice = getHumanChoice();
        let computerChoice = getComputerChoice();
        playRound(humanChoice, computerChoice);
    }

    console.log(`Final Scores: Human = ${humanScore}, Computer = ${computerScore}`);
}

playGame();
