# Tic-Tac-Toe Game in C

This is a simple implementation of the classic game Tic-Tac-Toe in C. It allows two players to play against each other and keeps track of the game state to determine the winner or a draw.

## How to Play

1. Compile the code using a C compiler.
2. Run the compiled executable.
3. Choose one of the options from the menu:
    * **1. Play:** Start a new game.
    * **2. Leaderboard:** Display the leaderboard (not implemented in this version).
4. If you choose to play, enter the names of Player 1 and Player 2.
5. The game will display the game board with numbered fields:
```shell
     |    |
   1 |  2 | 3
 ----|----|----
   4 |  5 | 6
 ----|----|----
   7 |  8 | 9
     |    |
```
6. Players take turns entering the number of the field they want to play.
7. The game will update the board with the corresponding symbol ('X' or 'O') for each player's move.
8. The game will continue until a player wins or there is a draw.
9. The winner or draw result will be displayed.

## Features

* Two-player gameplay.
* Simple console-based user interface.
* Clear the console screen between moves for better visibility.
* Checks for valid moves and prevents overwriting occupied fields.
* Determines the winner or a draw based on the game state.

## Implementation Details

* The game uses a character array fields to represent the Tic-Tac-Toe board.
* The board function is responsible for displaying the game board and player information.
* The checksequence function checks the game state and returns:
    * 1 if a player has won.
    * 0 if the game is a draw.
    * -1 if the game is still in progress.
* The main loop handles player turns, input validation, updating the game board, and calling the board function.
* The game ends when there is a winner or a draw.

## Requirements

* C compiler

## Inspiration

This implementation of Tic-Tac-Toe is inspired by the code available on [GitHub](https://github.com/mishal23/Tic-Tac-Toe).

## License

This code is released under the [MIT License](LICENSE.md). Feel free to modify and distribute it as needed.