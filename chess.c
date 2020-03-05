#include <stdio.h>
#include <stdlib.h>

int main()
{
	char board[9][9]={{"XABCDEFGH"},
			  {"8rnbqkbnr"},
			  {"7pppppppp"},
			  {"6        "},
			  {"5        "},
			  {"4        "},
			  {"3        "},
			  {"2PPPPPPPP"},
	  	 	  {"1RNBQKBNR"}};

	for (int i=0;i<9;i++)
	{
		for (int j=0;j<9;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

	return 0;
}
