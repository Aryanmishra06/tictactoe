#include <stdio.h>

// Function to print the Tic Tac Toe board
void printBoard(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if(j < 2)
                printf("|");
        }
        printf("\n");
        if(i < 2)
            printf("---|---|---\n");
    }
}

// Function to check if there is a winner
int checkWinner(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];
    return '\0';
}

int main() {
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    int player = 1;
    int row, col;
    char mark;
    int winner = '\0';

    while(winner == '\0') {
        printBoard(board);
        printf("Player %d's turn. Enter your move: ", player);
        scanf("%d%d", &row, &col);
        row--; col--;
        if(board[row][col] != 'X' && board[row][col] != 'O') {
            if(player == 1) {
                mark = 'X';
                player = 2;
            } else {
                mark = 'O';
                player = 1;
            }
            board[row][col] = mark;
            winner = checkWinner(board);
        } else {
            printf("Invalid move! Try again.\n");
        }
    }

    printBoard(board);
    if(winner == 'X')
        printf("Player 1 has won!\n");
    else
        printf("Player 2 has won!\n");

    return 0;
}