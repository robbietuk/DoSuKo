#include <iostream>
#include "SudokuBoard.h"




int main() {
  std::string input = "070000043040009610800634900094052000358460020000800530080070091902100005007040802";
  std::string solution = "679518243543729618821634957794352186358461729216897534485276391962183475137945862";

  SudokuBoard board(input);
  board.print_board();
  //  board.print_board_with_boarder();

  int row = 4;
  int col = 5;

  //  for (int value = 1; value < 10; value++) {
  //    std::cout << "Value: " << value
  //              << " into pos (col,row): (" << col << ", " << row << ") is valid: "
  //              << std::to_string(board.is_valid_update(col, row, value)) << std::endl;
  //  }
  bool *valid_entries = board.get_valid_entries(col, row);

  {
    std::cout << "For pos (col,row): (" << col << ", " << row << ") valid entries:\n";
    for (int i = 0; i < 9; i++) {
      if (valid_entries[i])
        std::cout << "Value: " << i + 1 << " is valid.\n";
    }
  }

  ColRowVal possible_move = board.any_valid_moves();
  std::cout << possible_move.row << " " << possible_move.col << " " << possible_move.value << std::endl;

  return 0;
}
