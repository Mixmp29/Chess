#include "board_print_plain.h"
#include <stdlib.h>
#include <stdio.h>

void print_board(char board[9][9])
{
    for (int i=0;i<9;i++)
	{
		for (int j=0;j<9;j++)
		{ 
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
