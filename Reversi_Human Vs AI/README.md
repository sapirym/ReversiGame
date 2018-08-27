At the beginning of the program, the user is presented with a menu that allows him to choose whether to play against an ordinary player or against the computer (AI player).
Game strategy for the AI ​​player:
In each turn, the AI ​​player will pass all possible moves on the board and score for each move. The score of each move will be determined by the maximum score the opponent can achieve in the new position of the board. The AI ​​player will choose the move that received the lowest score (ie, the move that minimizes the score that the opponent can achieve in his next step).

This strategy is the basis for a well-known gaming algorithm called minimax, in which each max player selects the best step, given that in the next move the opponent (the min player) will choose the worst step for him.

In addition, in this program I also used the technique of testing the software (Tests Unit)
Test Test library for testing software. (Https://github.com/google/googletest)
