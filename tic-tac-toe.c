#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tic-tac-toe.h"
#ifdef _WIN32
    #define OS "nt"
#elif __unix__
    #define OS "posix"
#endif

int checksequence(char *fields) {
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

void board(char x, char o, unsigned char *p1, unsigned char *p2, char *fields) {
    int i;

    if (OS == "nt") {
        system("cls");
    }
    else if (OS == "posix") {
        system("clear");
    }

    printf("\tTic-Tac-Toe\n\n");
    printf("\n\n");
    printf("%s: (%c)\n%s: (%c)\n\n\n", p1, x, p2, o);

    printf("    |    |    \n");
    printf("  %c |  %c | %c\n", fields[0], fields[1], fields[2]);
    printf("----|----|----\n");
    printf("  %c |  %c | %c\n", fields[3], fields[4], fields[5]);
    printf("----|----|----\n");
    printf("  %c |  %c | %c\n", fields[6], fields[7], fields[8]);
    printf("    |    |    \n");
}

int main() {
    int choice;
    char p1[20], p2[20];
    char x, o;
    char fields[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int player;
    int play, score = -1;
    char symbol;

    printf("*******************************\n");
    printf("*   Welcome to Tic-Tac-Toe!   *\n");
    printf("*                             *\n");
    printf("*   1. Play                   *\n");
    printf("*   2. Leadboard              *\n");
    printf("*******************************\n\n");
    printf("\nChoose what you want: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        do {
            printf("\nEnter name of Player 1: ");
            scanf("%s", p1);
            printf("Enter name of Player 2: ");
            scanf("%s", p2);
            !strcmp(p1, p2) ? printf("Enter different names for players\n\n") : 0;
        } while (!strcmp(p1, p2));
        x = 'X';
        o = '0';
        
        board(x, o, p1, p2, fields);

        do {
            player = ((player % 2) ? 1 : 2);
            if (player == 1)
                printf("\n%s type the field you wanna play: ", p1);
            else
                printf("\n%s type the field you wanna play: ", p2);
            scanf("%d", &play);
            symbol = ((player == 1) ? x : o);
            if (play == 1 && fields[0] == '1')
                fields[0] = symbol;
            else if (play == 2 && fields[1] == '2')
                fields[1] = symbol;
            else if (play == 3 && fields[2] == '3')
                fields[2] = symbol;
            else if (play == 4 && fields[3] == '4')
                fields[3] = symbol;
            else if (play == 5 && fields[4] == '5')
                fields[4] = symbol;
            else if (play == 6 && fields[5] == '6')
                fields[5] = symbol;
            else if (play == 7 && fields[6] == '7')
                fields[6] = symbol;
            else if (play == 8 && fields[7] == '8')
                fields[7] = symbol;
            else if (play == 9 && fields[8] == '9')
                fields[8] = symbol;
            else {
                printf("Wrong Selection\n");
                player--;
            }
            score = checksequence(fields);
            player++;
            board(x, o, p1, p2, fields);
        }while (score == -1);
        if (score == 1) {
            if (player == 2) {
                printf("\n\n%s wins!\n", p1);
            } else {
                printf("\n\n%s wins!\n", p2);
            }
        } else {
            printf("\n\nGame draws!\n\n");
        }
        break;
    
    default:
        break;
    }
}