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

