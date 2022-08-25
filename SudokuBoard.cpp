//
// Created by Robert Twyman Skelly on 8/25/22.
//

#include "SudokuBoard.h"
#include <iostream>

SudokuBoard::
        SudokuBoard(const std::string &board_config) {
  construct_board(board_config);
}

void SudokuBoard::
        construct_board(const std::string &board_config) {
  if (board_config.size() != 81) {
    std::string error_message =
            "Board config must be 81 characters long. (" +
            std::to_string(board_config.size()) + " given).\n" +
            "Board config: " + board_config + "\n";
    throw std::runtime_error(error_message);
  }

  bool valid_board = true;
  for (int i = 0; i < board_config.size(); i++) {
    int value = board_config[i] - '0';
    if (value != 0) {
      if (!do_update_if_valid(i / 9, i % 9, value)) {
        do_update_if_valid(i / 9, i % 9, value);
        valid_board = false;
      }
    }
  }
  if (!valid_board) {
    std::string error_message = "Board config is not compatible with game rules.\n"
                                "Board config: " +
                                board_config + "\n";
    throw std::runtime_error(error_message);
  }
}

void SudokuBoard::print_board() {
  for (auto &i: board_array) {// row
    for (int j: i) {          // element [row][col]
      std::cout << j << "  ";
    }
    std::cout << std::endl;
  }
}

void SudokuBoard::
        print_board_with_boarder() {

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

bool SudokuBoard::
do_update_if_valid(int col, int row, int value) {
  if (is_valid_update(col, row, value)) {
    do_update(col, row, value);
    return true;
  }
  return false;
}

void SudokuBoard::
do_update(int col, int row, int value) {
  board_array[col][row] = value;
}

bool SudokuBoard::
is_valid_update(int col, int row, int value) {

  assert(value > 0 && value <= 9);

  if (!this->is_free_position(col, row))
    return false;

  if (!this->is_value_in_local_box(col, row, value))
    return false;

  if (!this->is_value_in_local_row(row, value))
    return false;

  if (!this->is_value_in_local_column(col, value))
    return false;

  return true;
}

bool SudokuBoard::
is_free_position(int col, int row) {
  return board_array[col][row] == 0;
}


bool SudokuBoard::
is_value_in_local_box(int col, int row, int value) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int di = (row / 3) * 3 + i;// e.g. (5/3) * 3 = 3
      int dj = (col / 3) * 3 + j;// need to divide (int) by 3 and multiply by 3,
      if (value == board_array[di][dj])
        return false;
    }
  }
  return true;
}

bool SudokuBoard::
is_value_in_local_column(int col, int value) {
  for (int j = 0; j < this->get_num_rows(); j++) {
    if (value == board_array[col][j])
      return false;
  }
  return true;
}

bool SudokuBoard::
is_value_in_local_row(int row, int value) {
  for (int i = 0; i < this->get_num_columns(); i++) {
    if (value == board_array[i][row])
      return false;
  }
  return true;
}

bool *SudokuBoard::
        get_valid_entries(int col, int row) {
  bool *value_entries = new bool[9];
  for (int i = 0; i < 9; i++) {
    int value = i + 1;
    value_entries[i] = is_valid_update(col, row, value);
  }

  return value_entries;
}

bool SudokuBoard::is_solved() {
  for (int i = 0; i < this->get_num_rows(); i++) {
    for (int j = 0; j < this->get_num_columns(); j++) {
      if (this->board_array[i][j] == 0)
        return false;
    }
  }
  return true;
}

ColRowVal SudokuBoard::
        any_valid_moves() {
  for (int i = 0; i < this->get_num_rows(); i++) {
    for (int j = 0; j < this->get_num_columns(); j++) {
      bool *valid_entries = get_valid_entries(j, i);

      for (int val = 0; val < 9; val++) {
        if (valid_entries[val] == 1)
          return ColRowVal{j, i, val + 1};
      }
    }
  }
  return ColRowVal{-1, -1, -1};
}