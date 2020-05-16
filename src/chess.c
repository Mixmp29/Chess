#include "board.h"
#include "board_print_plain.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char board[9][9]={{"XABCDEFGH"},
			  {"1rnbqkbnr"},
			  {"2pppppppp"},
			  {"3        "},
			  {"4        "},
			  {"5        "},
			  {"6        "},
			  {"7PPPPPPPP"},
	  	 	  {"8RNBQKBNR"}};

    int flag_game = 0;

    while(flag_game == 0)
    {
	    print_board(board);
	    move(board);
    }
	return 0;
}
