#include "board.h"
#include "board_print_plain.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    char board[8][8] = {{"rnbqkbnr"},
                        {"pppppppp"},
                        {"        "},
                        {"        "},
                        {"        "},
                        {"        "},
                        {"PPPPPPPP"},
                        {"RNBQKBNR"}};
    int ShowMustGoOn;
    char m[9];
    do {
        board_print(board);
	fgets(m, 9, stdin);
        ShowMustGoOn = move(board, m);
    } while (ShowMustGoOn != 1);
    board_print(board);
    printf("Игра окончена!\n");
    return 0;
}
