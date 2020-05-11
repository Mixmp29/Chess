#include "board.h"
#include "board_print_plain.h"
#include <stdio.h>
#include <stdlib.h>

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

	print_board(board);
	move(board);
	print_board(board);
	return 0;
}
