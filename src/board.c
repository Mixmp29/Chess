#include "board.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void move(char board[9][9])
{
    char move[6];
    char test_board[9][9];
    char figure;
    fgets(move, 6, stdin);
    int i, j, c, d;
    for (int k = 0; k < strlen(move); k++)
    {
        if (move[k] != '-')
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
                default: printf("Incorrect input! \n");
            }
        }
        else //if(move[k] == '-')
        {
            c = i; d = j;
            figure = board[j][i];
            test_board[d][c] = ' ';
        }
    }
    switch(figure)
    {
        case 'P':   {
                        if(c == i && (d-1 == j || d-2 == j) && d == 7)
                        {
                            board[d][c] = test_board[d][c];
                            board[j][i] = figure;
                        }
                        else if(c == i && d-1 == j && d != 7)
                        {
                            board[d][c] = test_board[d][c];
                            board[j][i] = figure;
                        }
                    }
        //default:
    }
}
