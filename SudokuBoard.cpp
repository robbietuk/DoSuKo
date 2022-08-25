//
// Created by Robert Twyman Skelly on 8/25/22.
//

#include "SudokuBoard.h"
#include <iostream>

SudokuBoard::
SudokuBoard(const std::string &board_config) {
  auto board_config_iter = board_config.begin();
  for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
      board_array[i][j] = (int) *board_config_iter - '0';
      board_config_iter++;
      }
  }
}

void SudokuBoard::print_board() {
  for (auto & i : board_array) { // row
    for (int j : i) { // element [row][col]
      std::cout << j << "  ";
    }
    std::cout << std::endl;
  }
}

void SudokuBoard::print_board_with_boarder() {

  // This doesn't x_gap and num_x_character does not work but it is fine for now.
  const int x_gap = 3;
  const int num_x_character =
          this->get_num_rows() +
          (this->get_num_rows() - 2) * x_gap;

  std::string boarder_horizontal;
  for (int i = 0; i < num_x_character; i++) { boarder_horizontal += "-"; }

  const std::string boarder_vertical = " | ";

  std::string output;
  for (int i = 0; i < this->get_num_columns(); i++) {
    if (i % 3 == 0)
      output += "\n" + boarder_horizontal + "\n";
    else
      output += "\n";

    for (int j = 0; j < this->get_num_rows(); j++) {
      if (j % 3 == 0)
        output += boarder_vertical;
      else
        output += " ";
      output += std::to_string(this->board_array[i][j]);
    }
    output += boarder_vertical;
  }
    output += "\n" + boarder_horizontal + "\n";
  std::cout << output << std::endl;
}

int SudokuBoard::
get_num_rows() {
  return sizeof(board_array)/sizeof(board_array[0]);
}

int SudokuBoard::
get_num_columns() {
  return sizeof(board_array[0])/sizeof(board_array[0][0]);
}

void SudokuBoard::
update_board(int x, int y, int value) {
  board_array[x][y] = value;
}

