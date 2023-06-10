#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "tic-tac-toe.h"
#define SYMBOL_X 'X'
#define SYMBOL_O 'O'
#ifdef _WIN32
    #define OS "nt"
#elif __unix__
    #define OS "posix"
#endif

int moves[NUM_SEQUENCES][MAX_SEQUENCE_LENGTH - 1];

int checkGameOver(char *fields) {
    if (fields[0] == fields[1] && fields[1] == fields[2])
        return 1;
    else if (fields[0] == fields[4] && fields[4] == fields[8])
        return 1;
    else if (fields[0] == fields[3] && fields[3] == fields[6])
        return 1;
    else if (fields[1] == fields[4] && fields[4] == fields[7])
        return 1;
    else if (fields[2] == fields[5] && fields[5] == fields[8])
        return 1;
    else if (fields[2] == fields[4] && fields[4] == fields[6])
        return 1;
    else if (fields[3] == fields[4] && fields[4] == fields[5])
        return 1;
    else if (fields[6] == fields[7] && fields[7] == fields[8])
        return 1;
    else if (fields[0] != '1' && fields[1] != '2' && fields[2] != '3' && fields[3] != '4' && fields[4] != '5' && fields[5] != '6' && fields[6] != '7' && fields[7] != '8' && fields[8] != '9')
        return 0;
    else
        return -1;
}

void displayBoard(const char *player1, const char *player2, const char *fields) {
    #ifdef _WIN32
        system("cls");
    #elif __unix__
        system("clear");
    #endif

    printf("\n%s vs %s\n\n", player1, player2);

    printf(" %c | %c | %c \n", fields[0], fields[1], fields[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", fields[3], fields[4], fields[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", fields[6], fields[7], fields[8]);
    printf("\n");
}

int isValidMove(int move, const char *fields) {
    if (move < 1 || move > 9) {
        return 0;
    }

    int index = move - 1;
    if (fields[index] >= '1' && fields[index] <= '9') {
        return 1;
    }

    return 0;
}

void updateBoard(char playerSymbol, int move, char *fields, int *player) {
    int isValid = 0;

    while (!isValid) {
        isValid = isValidMove(move, fields);

        if (isValid) {
            fields[move - 1] = playerSymbol;
        } else {
            printf("Invalid selection. Please choose a valid position: ");
            scanf("%d", &move);
        }
    }
}

void playGame(const char *player1, const char *player2, int isAgainstAI) {
    char fields[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int currentPlayer;
    int selectedPosition;
    char symbol;

    currentPlayer = rand() % 2 + 1;

    displayBoard(player1, player2, fields);

    int score = -1;
    while (score == -1) {
        if (currentPlayer == 1 || (currentPlayer == 2 && !isAgainstAI)) {
            printf("\n%s, enter the field you want to play: ", (currentPlayer == 1) ? player1 : player2);
            scanf("%d", &selectedPosition);
        } else {
            printf("\n%s is making a move...\n", player2);
            selectedPosition = getRandomMove(fields);
            printf("%s chose position %d\n", player2, selectedPosition);
        }
            
        symbol = (currentPlayer == 1) ? SYMBOL_X : SYMBOL_O;
        updateBoard(symbol, selectedPosition, fields, &currentPlayer);

        score = checkGameOver(fields);
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
        displayBoard(player1, player2, fields);
        printf("The AI played in position %d", selectedPosition);
    }

    if (score == 1) {
        if (currentPlayer == 2) {
            printf("\n\n%s wins!\n", player1);
        } else {
            printf("\n\n%s wins!\n", player2);
        }
    } else {
        printf("\n\nGame draws!\n\n");
    }
}

int getRandomMove(char *fields) {
    int move;
    int availableMoves[9];
    int numAvailableMoves = 0;

    for (int i = 0; i <= 9; i++) {
        if (isValidMove(i, fields)) {
            availableMoves[numAvailableMoves] = i;
            numAvailableMoves++;
        }
    }

    if (numAvailableMoves > 0) {
        int randomIndex = rand() % numAvailableMoves;
        move = availableMoves[randomIndex];
    } else {
        move = -1;
    }

    printf("%d", move);
    return move;
}

void readWinnerSequences() {
    FILE *f;
    f = fopen("everyWinSequence.txt", "r");
    if (f == 0 || f == NULL) {
        printf("IA isn't available");
    }

    int i, j;

    for (i = 0; i < NUM_SEQUENCES; i++) {
        for (j = 0; j < MAX_SEQUENCE_LENGTH - 1; j++) {
            if (fscanf(f, "%1d", &moves[i][j]) != 1) {
                printf("Failed to read sequence from file.\n");
                fclose(f);
                break;
            }
        }
        fscanf(f, "\n");
    }

    fclose(f);
}

int main() {
    int choice;
    char player1[20], player2[20];
    
    printf("*******************************\n");
    printf("*   Welcome to Tic-Tac-Toe!   *\n");
    printf("*                             *\n");
    printf("*   1. Play vs Friend         *\n");
    printf("*   2. Play vs Computer       *\n");
    printf("*******************************\n\n");
    printf("\nChoose what you want: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        do {
            printf("\nEnter name of Player 1: ");
            scanf("%s", player1);
            printf("Enter name of Player 2: ");
            scanf("%s", player2);
            if (strcmp(player1, player2) == 0) {
                printf("Enter different names for players\n\n");
            }
        } while (strcmp(player1, player2) == 0);
        
        srand(time(NULL));
        playGame(player1, player2, 0);        
        break;
    
    case 2:
        printf("\nEnter your name: ");
        scanf("%s", player1);

        strcpy(player2, "AI");

        srand(time(NULL));
        playGame(player1, player2, 1);
        break;
    default:
        break;
    }
}