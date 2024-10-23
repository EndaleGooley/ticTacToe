  ⭕️❌⭕️❌⭕️❌⭕️❌⭕️❌⭕️❌⭕️ ##Tic-Tac-Toe Game ❌⭕️❌⭕️❌⭕️❌⭕️❌⭕️❌⭕️❌⭕️❌

## Overview
This project is a console-based **Tic-Tac-Toe** game written in C++. The game allows the user to play against a basic AI. It includes features like alternating turns, checking for wins and ties, and a simple AI that either wins, blocks, or makes random moves.

## Features
- **Two-player mode**: Playable by a human against an AI.
- **Win and tie conditions**: The game checks for winning combinations and ties.
- **Basic AI**: The AI tries to win, block the player, or pick a random position.
- **Dynamic board display**: The game board updates in real-time after every move.

## Installation
- **Device**: Macbook Air M1, 2020
- **Platform**: VScode (via clone repository)
- To clone the repository, use the command:
  ```bash
  git clone https://github.com/ticTacToe/tic-tac-toe.git

## Development challenges
i) 
Problem:
 For some reason, slot 1 (position 1 on the board) wasn't storing the player's mark even though other slots were working fine.

Solution: After careful debugging, I realized the issue was due to how the board was being validated. The condition board[move - 1] == '0' + move wasn't general enough for all slots. I fixed this by ensuring that the program checks whether the slot contains 'X' or 'O' instead of comparing it with the initial numeric character.

ii) 
Problem: 
Building the AI was another challenge. The AI had to:
-Try to win if it could place its mark to win.
-Block the player if the player was about to win.
-Make a random move if neither of the above applied.

Solution: I wrote the aiMove() function to simulate moves by temporarily placing a mark on the board, checking if the AI could win, and reverting the move if it didn't result in a win. Similarly, it checks if the player is about to win and blocks them. If neither condition is met, the AI makes a random valid move.

iii)
Problem:
 One of the first challenges was ensuring that player input was correctly mapped to the board. Initially, there were issues where the game wasn't storing the player’s move in specific slots (particularly slot 1). The condition for validating whether a slot was available was improperly handled.

Solution: I modified the playerMove() function to check if a slot was already occupied by checking for 'X' or 'O' instead of relying on the original numeric value ('1', '2', etc.). This prevented overwriting marks in already used slots.

## How to Play
- The game will display the board with numbered positions (1-9).
- The player goes first and selects a position by entering a number (1-9). corresponding to the desired slot on the board.
- The AI will then make its move.
- The game will continue until either player wins the or the game ends in a tie.

## Feuture Improvments
- Score counter: Add a feature that stores the total number of wins. By both the user and AI.
- Design: Improve the users interface with colored output or a graphical version of the game.
- Implementing Minimax Algorithenm to make the AI unbeatable

# Author 
- This project was developed by Endale Gooley. It serves as a foundational C++ project and helped deepen my understanding of game development, algorithms, and debugging in C++.
