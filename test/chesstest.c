#include "board.h"
#include "board_print_plain.h"
#include "chesstest.h"
#include "ctest.h"

char board[8][8];

CTEST(syntax, player_one) {
  int expected = 0;
  int result = player('n');
  ASSERT_EQUAL(expected, result);
}

CTEST(syntax, player_two) {
  int expected = 1;
  int result = player('N');
  ASSERT_EQUAL(expected, result);
}

CTEST(syntax, no_player) {
  int expected = 2;
  int result = player(' ');
  ASSERT_EQUAL(expected, result);
}

CTEST(syntax, print_type_1) {
  int expected = 0;
  int result = print_type("e2-e4 ");
  ASSERT_EQUAL(expected, result);
}

CTEST(syntax, print_type_2) {
  int expected = 1;
  int result = print_type("pe2-e4 ");
  ASSERT_EQUAL(expected, result);
}

CTEST(syntax, print_type_1_and_mate) {
  int expected = 0;
  int result = print_type("e2-e4# ");
  ASSERT_EQUAL(expected, result);
}

CTEST(syntax, print_type_2_and_mate) {
  int expected = 1;
  int result = print_type("pe2-e4# ");
  ASSERT_EQUAL(expected, result);
}

CTEST(syntax, print_type_1_correct) {
  int expected = 0;
  int result = check_writing("e2-e4 ");
  ASSERT_EQUAL(expected, result);
}

CTEST(syntax, print_type_1_incorrect) {
  int expected = -1;
  int result = check_writing("2e-e4 ");
  ASSERT_EQUAL(expected, result);
}

CTEST(syntax, print_type_2_correct) {
  int expected = 0;
  int result = check_writing("pe2-e4 ");
  ASSERT_EQUAL(expected, result);
}

CTEST(syntax, print_type_2_incorrect) {
  int expected = -1;
  int result = check_writing("z2e-e4 ");
  ASSERT_EQUAL(expected, result);
}

CTEST(syntax, move_correct) {
  int expected = 0;
  int result = move(board, "e2-e4 ");
  ASSERT_EQUAL(expected, result);
}

CTEST(syntax, move_incorrect_no_figure) {
  int expected = -1;
  int result = move(board, "e5-e2 ");
  ASSERT_EQUAL(expected, result);
}

CTEST(syntax, move_incorrect_wrong_figure) {
  int expected = -1;
  int result = move(board, "ke2-e4 ");
  ASSERT_EQUAL(expected, result);
}

CTEST(syntax, move_incorrect_wrong_attack) {
  int expected = -1;
  int result = move(board, "pa2xa4 ");
  ASSERT_EQUAL(expected, result);
}

CTEST(syntax, move_incorrect_attack_self) {
  int expected = -1;
  int result = move(board, "pa2xb2 ");
  ASSERT_EQUAL(expected, result);
}

CTEST(syntax, move_incorrect_attack) {
  int expected = -1;
  int result = move(board, "b2-e8 ");
  ASSERT_EQUAL(expected, result);
}

CTEST(syntax, move_attack_success) {
  int expected = 0;
  int result = move(board, "f1xe8 ");
  ASSERT_EQUAL(expected, result);
}

CTEST(syntax, mate) {
  int expected = 1;
  int result = move(board, "a1-a3# ");
  ASSERT_EQUAL(expected, result);
}

