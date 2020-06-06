#define CTEST_MAIN
#include "board.h"
#include "chesstest.h"
#include "ctest.h"
#include <stdio.h>

int main(int argc, const char *argv[]) {
  int result = ctest_main(argc, argv);
  printf("Tests completed!\n");
  return result;
}
