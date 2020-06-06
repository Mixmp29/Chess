all:
	gcc -c -Wall -Werror -o build/src/board.o src/board.c
	gcc -c -Wall -Werror -o build/src/board_print_plain.o src/board_print_plain.c
	gcc -c -Wall -Werror -o build/src/chess.o src/chess.c
	gcc -o bin/chess build/src/board.o build/src/board_print_plain.o build/src/chess.o
	gcc -c -Wall -Werror -o build/test/board.o src/board.c
	gcc -c -Wall -Werror -o build/test/board_print_plain.o src/board_print_plain.c
	gcc -c -Wall -Werror -o build/test/main.o test/main.c -I thirdparty -I src
	gcc -c -Wall -Werror -o build/test/chesstest.o test/chesstest.c -I thirdparty -I src
	gcc -o bin/chesstest build/test/board.o build/test/board_print_plain.o build/test/main.o build/test/chesstest.o
clean:
	rm -rf build/src/*.o build/test/*.o
