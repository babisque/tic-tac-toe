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

void updateBoard(char playerSymbol, int move, char *fields, int *player) {
            if (move == 1 && fields[0] == '1')
                fields[0] = playerSymbol;
            else if (move == 2 && fields[1] == '2')
                fields[1] = playerSymbol;
            else if (move == 3 && fields[2] == '3')
                fields[2] = playerSymbol;
            else if (move == 4 && fields[3] == '4')
                fields[3] = playerSymbol;
            else if (move == 5 && fields[4] == '5')
                fields[4] = playerSymbol;
            else if (move == 6 && fields[5] == '6')
                fields[5] = playerSymbol;
            else if (move == 7 && fields[6] == '7')
                fields[6] = playerSymbol;
            else if (move == 8 && fields[7] == '8')
                fields[7] = playerSymbol;
            else if (move == 9 && fields[8] == '9')
                fields[8] = playerSymbol;
            else {
                printf("Wrong Selection\n");
                player--;
            }
}

void playGame(const char *player1, const char *player2) {
    char fields[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int currentPlayer;
    int selectedPosition;
    char symbol;

    currentPlayer = rand() % 2 + 1;

    displayBoard(player1, player2, fields);

    int score = -1;
    while (score == -1) {
        if (currentPlayer == 1)
            printf("\n%s type the field you wanna play: ", player1);
        else
            printf("\n%s type the field you wanna play: ", player2);
        scanf("%d", &selectedPosition);
            
        symbol = (currentPlayer == 1) ? SYMBOL_X : SYMBOL_O;
        updateBoard(symbol, selectedPosition, fields, &currentPlayer);

        score = checkGameOver(fields);
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
        displayBoard(player1, player2, fields);
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

int main() {
    int choice;
    char player1[20], player2[20];
    

    printf("*******************************\n");
    printf("*   Welcome to Tic-Tac-Toe!   *\n");
    printf("*                             *\n");
    printf("*   1. Play                   *\n");
    printf("*   2. Leadboard              *\n");
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
        playGame(player1, player2);        
        break;
    
    default:
        break;
    }
}