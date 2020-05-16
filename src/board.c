#include "board.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void move(char board[9][9])
{
    int count[6] = {0};
    char move[6];
    char figure;
    int i = 0, j = 0, player_took_figure = 0, cycle = 0, move_figure = 0, this_figure = 0;
    printf("Input a command. Example: 'e7-e5' or 'Pd7xd2' or 'Bc7-c5'\n");
    while (cycle == 0)
    {
        fgets(move, 7, stdin);
        for (int k = 0; k < 6; k++)
        {
            if (move[2] == '-')
            {
                move[5] = ' ';
                switch(move[k])
                {
                    case 'a': i = 1; break;
                    case 'b': i = 2; break;
                    case 'c': i = 3; break;
                    case 'd': i = 4; break;
                    case 'e': i = 5; break;
                    case 'f': i = 6; break;
                    case 'g': i = 7; break;
                    case 'h': i = 8; break;
                    case '1': j = 1; break;
                    case '2': j = 2; break;
                    case '3': j = 3; break;
                    case '4': j = 4; break;
                    case '5': j = 5; break;
                    case '6': j = 6; break;
                    case '7': j = 7; break;
                    case '8': j = 8; break;
                    case '-': break;
                    case ' ': break;
                    default: printf("Incorrect input! Enter like 'e7-e5 or 'Pd7xd5' \n"); break;
                }     
                if(move[k] == '-')
                {
                    figure = board[j][i];
                    board[j][i] = ' ';
                    move_figure = 1;
                }
            }
            if (move[3] == '-')
            {
                switch(move[k])
                {
                    case 'a': i = 1; break;
                    case 'b': i = 2; break;
                    case 'c': i = 3; break;
                    case 'd': i = 4; break;
                    case 'e': i = 5; break;
                    case 'f': i = 6; break;
                    case 'g': i = 7; break;
                    case 'h': i = 8; break;
                    case '1': j = 1; break;
                    case '2': j = 2; break;
                    case '3': j = 3; break;
                    case '4': j = 4; break;
                    case '5': j = 5; break;
                    case '6': j = 6; break;
                    case '7': j = 7; break;
                    case '8': j = 8; break;
                    case '-': break;
                    case 'R': count[0]++; break; 
                    case 'N': count[1]++; break;
                    case 'B': count[2]++; break;
                    case 'Q': count[3]++; break;
                    case 'K': count[4]++; break;
                    case 'P': count[5]++; break;
                    default: printf("Incorrect input! Enter like 'e7-e5 or 'Pd7xd5' \n"); break;
                }
                if(move[k] == '-')
                {
                     figure = board[j][i];
                    board[j][i] = ' ';
                    if ((figure == 'R' || figure == 'r') && count[0] == 1)
                        this_figure++;
                    else if ((figure == 'N' || figure == 'n') && count[1] == 1)
                        this_figure++;
                    else if ((figure == 'B' || figure == 'b') && count[2] == 1)
                        this_figure++;
                    else if ((figure == 'Q' || figure == 'q') && count[3] == 1)
                        this_figure++;
                    else if ((figure == 'K' || figure == 'k') && count[4] == 1)
                        this_figure++;
                    else if ((figure == 'P' || figure == 'p') && count[5] == 1)
                        this_figure++;
                }
            }
            if (move[3] == 'x')
            {
                switch(move[k])
                {
                    case 'a': i = 1; break;
                    case 'b': i = 2; break;
                    case 'c': i = 3; break;
                    case 'd': i = 4; break;
                    case 'e': i = 5; break;
                    case 'f': i = 6; break;
                    case 'g': i = 7; break;
                    case 'h': i = 8; break;
                    case '1': j = 1; break;
                    case '2': j = 2; break;
                    case '3': j = 3; break;
                    case '4': j = 4; break;
                    case '5': j = 5; break;
                    case '6': j = 6; break;
                    case '7': j = 7; break;
                    case '8': j = 8; break;
                    case 'x': break;
                    case 'R': count[0]++; break; 
                    case 'N': count[1]++; break;
                    case 'B': count[2]++; break;
                    case 'Q': count[3]++; break;
                    case 'K': count[4]++; break;
                    case 'P': count[5]++; break;
                    default: printf("Incorrect input! Enter like 'e7-e5 or 'Pd7xd5' \n"); break;
                }
                if(move[k] == 'x')
                {
                    figure = board[j][i];
                    board[j][i] = ' ';
                    if ((figure == 'R' || figure == 'r') && count[0] == 1)
                        player_took_figure++;
                    else if ((figure == 'N' || figure == 'n') && count[1] == 1)
                        player_took_figure++;
                    else if ((figure == 'B' || figure == 'b') && count[2] == 1)
                        player_took_figure++;
                    else if ((figure == 'Q' || figure == 'q') && count[3] == 1)
                        player_took_figure++;
                    else if ((figure == 'K' || figure == 'k') && count[4] == 1)
                        player_took_figure++;
                    else if ((figure == 'P' || figure == 'p') && count[5] == 1)
                        player_took_figure++;
                }
            }
        }
        if (move[3] == 'x' && board[j][i] != ' ' && player_took_figure == 1)
            {
                board[j][i] = figure;
                player_took_figure = 0;
                cycle++;
                fgets(move, 6, stdin); // костыль 
            }
        else if (board[j][i] == ' ' && player_took_figure == 1)
            {
                printf("There is no figure in this field. Enter the command again.\n");
                fgets(move, 6, stdin); // костыль 
            }
        if (move_figure == 1)
        {
            board[j][i] = figure;
            move_figure = 0;
            cycle++;
        }
        if (this_figure == 1)
        {
            board[j][i] = figure;
            this_figure = 0;
            cycle++;
            fgets(move, 6, stdin); // костыль 
        }
    }
}
