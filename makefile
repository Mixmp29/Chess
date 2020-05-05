all:
	gcc -Wall -Werror -c chess.c
	gcc -Wall -Werror -c board_print_plain.c
	gcc -Wall -Werror -c board.c
	gcc chess.o board.o board_print_plain.o -o chess
