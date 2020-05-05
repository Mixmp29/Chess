all:
	gcc -Wall -Werror -c chess.c
	gcc -Wall -Werror -c board_print_plain.c
	gcc chess.o board_print_plain.o -o chess
