#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int player(char figure)
{
    switch (figure) {
    case 'p':
    case 'q':
    case 'k':
    case 'r':
    case 'b':
    case 'n':
        return 0;
    case 'P':
    case 'Q':
    case 'K':
    case 'R':
    case 'B':
    case 'N':
        return 1;
    default:
        return 2;
    }
}

int print_type(char c[9])
{
    if ((strlen(c) == 6) && (c[5] != '#'))
        return 0;
    if ((strlen(c) == 7) && (c[5] == '#'))
        return 0;
    if ((strlen(c) == 7) && (c[5] != '#'))
        return 1;
    if ((strlen(c) == 8) && (c[6] == '#'))
        return 1;
    return -1;
}

int letter_check(char c)
{
    switch (c) {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
        return 1;
    default:
        return 0;
    }
}

int number_check(char c)
{
    switch (c) {
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
        return 1;
    default:
        return 0;
    }
}

int check_writing(char c[9])
{
    if (print_type(c) == 0) {
        if ((c[2] != '-') && (c[2] != 'x')) {
            printf("Неверный ввод!\n");
            return -1;
        }
        if ((letter_check(c[0]) == 0) || (letter_check(c[3]) == 0)) {
            printf("Неверный ввод!\n");
            return -1;
        }
        if ((number_check(c[1]) == 0) || (number_check(c[4]) == 0)) {
            printf("Неверный ввод!\n");
            return -1;
        }
        return 0;
    } else {
        if ((c[3] != '-') && (c[3] != 'x')) {
            printf("Неверный ввод!\n");
            return -1;
        }
        if ((letter_check(c[1]) == 0) || (letter_check(c[4]) == 0)) {
            printf("Неверный ввод!\n");
            return -1;
        }
        if ((number_check(c[2]) == 0) || (number_check(c[5]) == 0)) {
            printf("Неверный ввод!\n");
            return -1;
        }
        return 0;
    }
    printf("Неизвестная ошибка");
    return -1;
}

int move(char board[8][8], char c[9])
{
    char figure, figure2;
    int move_type = -1;
    int player_move = -1;
    int player_def = -2;
    int gameover = 0;
    int x, y, x1, y1;
    if (print_type(c) == -1) {
        printf("Неверный ввод!\n");
        return -1;
    }
    if (check_writing(c))
        return -1;

    if (print_type(c) == 0) {
        for (int i = 0; i < 5; i++) {
            if ((c[i] != '-') && (c[i] != 'x')) {
                switch (c[i]) {
                case 'a':
                    x = 0;
                    break;
                case 'b':
                    x = 1;
                    break;
                case 'c':
                    x = 2;
                    break;
                case 'd':
                    x = 3;
                    break;
                case 'e':
                    x = 4;
                    break;
                case 'f':
                    x = 5;
                    break;
                case 'g':
                    x = 6;
                    break;
                case 'h':
                    x = 7;
                    break;
                case '1':
                    y = 0;
                    break;
                case '2':
                    y = 1;
                    break;
                case '3':
                    y = 2;
                    break;
                case '4':
                    y = 3;
                    break;
                case '5':
                    y = 4;
                    break;
                case '6':
                    y = 5;
                    break;
                case '7':
                    y = 6;
                    break;
                case '8':
                    y = 7;
                    break;
                default:
                    printf("Incorrect input!\n");
                }
            } else {
                if (c[i] == 'x')
                    move_type = 1;
                else
                    move_type = 0;
                x1 = x;
                y1 = y;
                figure = board[y1][x1];
                if (c[5] == '#')
                    gameover = 1;
            }
        }
    } else {
        for (int i = 1; i < 6; i++) {
            if ((c[i] != '-') && (c[i] != 'x')) {
                switch (c[i]) {
                case 'a':
                    x = 0;
                    break;
                case 'b':
                    x = 1;
                    break;
                case 'c':
                    x = 2;
                    break;
                case 'd':
                    x = 3;
                    break;
                case 'e':
                    x = 4;
                    break;
                case 'f':
                    x = 5;
                    break;
                case 'g':
                    x = 6;
                    break;
                case 'h':
                    x = 7;
                    break;
                case '1':
                    y = 0;
                    break;
                case '2':
                    y = 1;
                    break;
                case '3':
                    y = 2;
                    break;
                case '4':
                    y = 3;
                    break;
                case '5':
                    y = 4;
                    break;
                case '6':
                    y = 5;
                    break;
                case '7':
                    y = 6;
                    break;
                case '8':
                    y = 7;
                    break;
                default:
                    printf("Incorrect input!\n");
                }
            } else {
                if (c[i] == 'x')
                    move_type = 1;
                else
                    move_type = 0;
                x1 = x;
                y1 = y;
                figure = board[y1][x1];
                if (figure != c[0]) {
                    printf("Указанная фигура не совпадает с действительной!\n");
                    return -1;
                }
                if (c[6] == '#')
                    gameover = 1;
            }
        }
    }

    figure2 = board[y][x];

    if (figure == ' ') {
        printf("В указанной ячейке нет фигуры!\n");
        return -1;
    }
    player_move = player(figure);
    player_def = player(figure2);
    if (player_move == player_def) {
        printf("Нельзя атаковать свои фигуры!\n");
        return -1;
    } else {
        if ((player_def == 2) && (move_type == 1)) {
            printf("Неверный тип хода!\n");
            return -1;
        }
        if ((move_type == 0) && (player_def != 2)) {
            printf("Неверный тип хода!\n");
            return -1;
        }
    }
    board[y1][x1] = ' ';
    board[y][x] = figure;
    player_move = -1;
    player_def = -1;
    move_type = 0;
    if (gameover == 1)
        return 1;
    return 0;
}

