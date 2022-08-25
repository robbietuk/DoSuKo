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
  for (auto & i : board_array) {
    for (int j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
}

int SudokuBoard::
get_size_x() {
  return sizeof(board_array);
}

int SudokuBoard::
get_size_y() {
  return sizeof(board_array[0]);
}

void SudokuBoard::
update_board(int x, int y, int value) {
  board_array[x][y] = value;
}

//SudokuBoard::
//SudokuBoard(const std::string &board_config, int size_x, int size_y) {
//
//
//  }