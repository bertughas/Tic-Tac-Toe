#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];

// Function to generate a random number that has not been used before
int generateNumber() {
    int number;
    char *ptr = board;
    int result = 0;
    while (!result) {
        number = 1 + rand() % 9;
        if (*(ptr + number - 1) != 'X' && *(ptr + number - 1) != 'O') {
            result = 1;
        }
    }
    return number;
}

// Function for computer's move
void computerMove() {
    int compNumber = generateNumber();
    char *ptr = board;
    *(ptr + compNumber - 1) = 'O';
}

void xComputerMove(){
    int xcompNumber = generateNumber();
    char *ptr = board;
    *(ptr + xcompNumber - 1) = 'X';
}

// Function to print the game board
void printBoard() {
    for (int i = 0; i < 3; i++) {
        printf("\n\t");
        for (int j = 0; j < 3; j++) {
            printf("|%c|\t", board[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize the game board with default values
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to make a move on the board
void makeMove(int row, int column, char player) {
    if (board[row][column] == ' ') {
        board[row][column] = player;
    } else {
        printf("\nInvalid choice, please try again.");
    }
}

// Function to check if the game is over
int checkGame(char player) {
    if ((board[0][0] == player && board[0][1] == player && board[0][2] == player) || // check rows
        (board[1][0] == player && board[1][1] == player && board[1][2] == player) ||
        (board[2][0] == player && board[2][1] == player && board[2][2] == player) ||
        (board[0][0] == player && board[1][0] == player && board[2][0] == player) || // check columns
        (board[0][1] == player && board[1][1] == player && board[2][1] == player) ||
        (board[0][2] == player && board[1][2] == player && board[2][2] == player) ||
        (board[0][0] == player && board[1][1] == player && board[2][2] == player) || // check diagonals
        (board[2][0] == player && board[1][1] == player && board[0][2] == player)) {
        return 1; // Player wins
    }
    return 0; // No winner yet
}

int main() {
    srand(time(NULL));
    int choice;
    printf("Welcome to Tic Tac Toe game.\n");
    printf("1- Two players\n");
    printf("2- Against computer\n");
    printf("Your choice:");
    scanf("%d", &choice);

    initializeBoard(); // Initialize the board with default values

    switch (choice) {
        case 1:
            system("cls");
            char player1, player2;
            int row, column;
            int result = 0;
            while (!result) {
                printf("Player 1, choose your symbol (O or X):");
                scanf(" %c", &player1);
                printf("Player 2, choose your symbol (O or X):");
                scanf(" %c", &player2);

                if (player1 == player2) {
                    printf("Both players cannot choose the same symbol.");
                } else {
                    while (!result) {
                        printf("Player 1, enter the row and column numbers (0-2):");
                        scanf("%d%d", &row, &column);
                        makeMove(row, column, player1);
                        printBoard();
                        result = checkGame(player1);
                        if (result) {
                            printf("Player 1 wins.\n");
                            break;
                        }
                        printf("Player 2, enter the row and column numbers (0-2):");
                        scanf("%d%d", &row, &column);
                        makeMove(row, column, player2);
                        printBoard();
                        result = checkGame(player2);
                        if (result) {
                            printf("Player 2 wins.\n");
                            break;
                        }
                    }
                }
            }
            break;
        case 2:
            system("cls");
            char player;
            int gameResult = 0;
            int moves = 0;
            printf("Choose your symbol (O or X):");
            scanf(" %c", &player);
            if(player=='X'){
            while (!gameResult) {
                moves++;
                printf("Enter the row and column numbers (0-2):");
                scanf("%d%d", &row, &column);
                makeMove(row, column, player);
                gameResult = checkGame(player);
                if (gameResult) {
                    printf("You win!\n");
                    printBoard();
                    break;
                }
                computerMove();
                printBoard();
                gameResult = checkGame('O');
                if (gameResult) {
                    printf("Computer wins!\n");
                    printBoard();
                    break;
                }
                if (moves == 5) {
                    printf("It's a tie!\n");
                    printBoard();
                    break;
                }
            }

    }
    else if(player=='O'){
            while (!gameResult) {
                int moves = 0;
                int gameResult=0;
                moves++;
                printf("Enter the row and column numbers (0-2):");
                scanf("%d%d", &row, &column);
                makeMove(row, column, player);
                gameResult = checkGame(player);
                if (gameResult) {
                    printf("You win!\n");
                    printBoard();
                    break;
                }
                xComputerMove();
                printBoard();
                gameResult = checkGame('X');
                if (gameResult) {
                    printf("Computer wins!\n");
                    printBoard();
                    break;
                }
                if (moves == 5) {
                    printf("It's a tie!\n");
                    printBoard();
                    break;
                }
            }


    }
        break;
        default:
            printf("Invalid choice, please try again.\n");
            break;
    }
    return 0;
    }

