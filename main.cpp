#include <iostream>
#include "SudokuBoard.h"




int main() {
  std::string input = "070000043040009610800634900094052000358460020000800530080070091902100005007040802";
  std::string solution = "679518243543729618821634957794352186358461729216897534485276391962183475137945862";

  SudokuBoard board(input);
  board.print_board();
//  board.print_board_with_boarder();
  return 0;
}
