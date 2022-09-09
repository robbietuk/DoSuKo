//
// Created by Robert Twyman Skelly on 8/25/22.
//

#include "ColRowVal.h"
#include "LocalBox.h"
#include "SudokuBoard.h"
#include <iostream>
#include <vector>


template<class CellType>
SudokuBoard<CellType>::SudokuBoard() = default;

template<class CellType>
SudokuBoard<CellType>::SudokuBoard(const std::string &board_config) {
  construct_board(board_config);
}

template<class CellType>
void
SudokuBoard<CellType>::construct_board(const std::string &board_config) {
  is_board_string_valid(board_config);
  reset_board_array();
  bool valid_board = true;
  for (int i = 0; i < board_config.size(); i++) {
    const int value = board_config[i] - '0';
    const int col = i % 9;
    const int row = i / 9;
    if (value != 0) {
      if (!do_update_cell_if_valid(row, col, value)) {
        valid_board = false;
        break;
      }
    }
  }
  if (!valid_board) {
    std::string error_message = "Board config is not compatible with game rules.\n"
                                "Board config: " +
                                board_config + "\n" +
                                is_valid_update_error_message;
    throw std::runtime_error(error_message);
  }
}

template<class CellType>
std::string
SudokuBoard<CellType>::encode() {
    std::string board_string;
    for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
        board_string += std::to_string(get_cell_ptr(row, col)->get_value());
      }
    }
    return board_string;
}

template<class CellType>
void
SudokuBoard<CellType>::reset_board_array() {
  for (auto &row : board_array) {
    for (auto &cell : row) {
      cell.set_value(0);
    }
  }
}

template<class CellType>
void
SudokuBoard<CellType>::print_board_2D_visualisation() {
  std::cout << "\n" <<  get_board_2D_visualisation();
}

template<class CellType>
std::string
SudokuBoard<CellType>::get_board_2D_visualisation() {
  std::string visualise_board_string;
  for (int row = 0; row < get_num_rows(); row++){
    for (int col = 0; col < get_num_columns(); col++){
      visualise_board_string += std::to_string(get_cell_ptr(row, col)->get_value()) + "  ";
    }
    visualise_board_string += "\n";
  }
  return visualise_board_string;
}

template<class CellType>
std::string
SudokuBoard<CellType>::get_board_as_string_with_boarders() {
#if 1
  std::cerr << "get_board_as_string_with_boarders() has been disabled because bad." << std::endl;
  return "";
#else
  // This doesn't x_gap and num_x_character does not work but it is fine for now.
  const int x_gap = 3;
  const int num_x_character =
          this->get_num_rows() +
          (this->get_num_rows() - 2) * x_gap;

  std::string boarder_horizontal;
  for (int i = 0; i < num_x_character; i++) { boarder_horizontal += "-"; }

  const std::string boarder_vertical = " | ";

  std::string output;
  for (int i = 0; i < this->get_num_rows(); i++) {
    if (i % 3 == 0)
      output += "\n" + boarder_horizontal + "\n";
    else
      output += "\n";

    for (int j = 0; j < this->get_num_columns(); j++) {
      if (j % 3 == 0)
        output += boarder_vertical;
      else
        output += " ";
      output += std::to_string(this->board_array[i][j]->get_value());
    }
    output += boarder_vertical;
  }
  output += "\n" + boarder_horizontal + "\n";
  return output;
#endif
}

template<class CellType>
int
SudokuBoard<CellType>::get_num_rows() {
  return sizeof(board_array)/sizeof(board_array[0]);
}

template<class CellType>
int
SudokuBoard<CellType>::get_num_columns() {
  return sizeof(board_array[0])/sizeof(board_array[0][0]);
}

template<class CellType>
bool SudokuBoard<CellType>::do_update_cell_if_valid(int row, int col, int value) {
  if (is_valid_cell_update(row, col, value)) {
    do_update(row, col, value);
    return true;
  }
  return false;
}

template<class CellType>
void
SudokuBoard<CellType>::do_update(int row, int col, int value) {
  get_cell_ptr(row, col)->set_value(value);
}

template<class CellType>
bool
SudokuBoard<CellType>::is_valid_cell_update(int row, int col, int value) {

  assert(value > 0 && value <= 9);
  is_valid_update_error_message = "";
  if (!this->is_free_position(row, col)){
    is_valid_update_error_message += "Position is not free. \n"
                                    "Current value:" + std::to_string(get_cell_ptr(row, col)->get_value()) + "\n"
                                    "Position: " + std::to_string(col) + "," + std::to_string(row) + "\n"
                                    "Trying to inset value: " + std::to_string(value) + "\n";
  }

  if (this->is_value_in_local_row(row, value)) {
    is_valid_update_error_message += "Value is in local row. \n"
                                    "Current value:" + std::to_string(get_cell_ptr(row, col)->get_value()) + "\n"
                                    "Position: " + std::to_string(col) + "," + std::to_string(row) + "\n";
  }

  if (this->is_value_in_column(col, value)){
    is_valid_update_error_message += "Value is in local column. \n"
                                    "Current value:" + std::to_string(get_cell_ptr(row, col)->get_value()) + "\n"
                                    "Position: " + std::to_string(col) + "," + std::to_string(row) + "\n";
  }

  if (this->is_value_in_local_box(row, col, value)) {
    is_valid_update_error_message += "Value is in local box. \n"
                                     "Current value:" +
                                     std::to_string(get_cell_ptr(row, col)->get_value()) +
                                     "\nPosition: " +
                                     std::to_string(col) + "," + std::to_string(row) +
                                     "\nTrying to inset value: " +
                                     std::to_string(value) + "\n";
  }

  if (!is_valid_update_error_message.empty()){
    is_valid_update_error_message += get_board_2D_visualisation() + "\n";
    return false;
  }

  return true;
}

template<class CellType>
bool
SudokuBoard<CellType>::is_free_position(int row, int col) {
  const int test_value = get_cell_ptr(row, col)->get_value();
  return test_value == 0;
}

template<class CellType>
CellType *
SudokuBoard<CellType>::get_cell_ptr(int row, int col) {
  return &board_array[row][col];
}

template<class CellType>
bool
SudokuBoard<CellType>::is_value_in_local_box(int row, int col, int value) {
  const LocalBox lb = get_local_box_values(row, col);
  for (auto & row : lb.local_box)
    for (int cell : row)
      if (cell == value)
        return true;
  return false;
}

template<class CellType>
LocalBox
SudokuBoard<CellType>::get_local_box_values(int row, int col) {
  LocalBox lb(col, row);
  for (int lb_row = 0; lb_row < 3; lb_row++) {
    for (int lb_col = 0; lb_col < 3; lb_col++) {
      const int test_row = (row / 3) * 3 + lb_row;// e.g. (5/3) * 3 = 3
      const int test_col = (col / 3) * 3 + lb_col;// need to divide (int) by 3 and multiply by 3,
      lb.local_box[lb_row][lb_col] = get_cell_ptr(test_row, test_col)->get_value();
    }
  }
  return lb;
}

template<class CellType>
bool
SudokuBoard<CellType>::is_value_in_column(int col, int value) {
  for (int row = 0; row < this->get_num_rows(); row++) {
    const int test_cell_value = get_cell_ptr(row, col)->get_value();
    if (value == test_cell_value)
      return true;
  }
  return false;
}

template<class CellType>
bool
SudokuBoard<CellType>::is_value_in_local_row(int row, int value) {
  for (int col = 0; col < this->get_num_columns(); col++) {
    const int test_cell_value = get_cell_ptr(row, col)->get_value();
    if (value == test_cell_value)
      return true;
  }
  return false;
}

template<class CellType>
bool *
SudokuBoard<CellType>::get_valid_entries(int row, int col) {
  bool *value_entries = new bool[9];
  for (int i = 0; i < 9; i++) {
    const int value = i + 1;
    value_entries[i] = is_valid_cell_update(row, col, value);
  }
  return value_entries;
}

template<class CellType>
bool
SudokuBoard<CellType>::is_solved() {
  for (int row = 0; row < this->get_num_rows(); row++) {
    for (int col = 0; col < this->get_num_columns(); col++) {
      if (get_cell_ptr(row, col)->get_value() == 0)
        return false;
    }
  }
  return true;
}

template<class CellType>
ColRowVal SudokuBoard<CellType>::any_valid_moves() {
  for (int row = 0; row < this->get_num_rows(); row++) {
    for (int col = 0; col < this->get_num_columns(); col++) {
      bool *valid_entries = get_valid_entries(row, col);
      for (int val = 0; val < 9; val++) {
        if (valid_entries[val] == 1)
          return ColRowVal{col, row, val + 1};
      }
    }
  }
  return ColRowVal{};
}

template<class CellType>
std::vector<CellType *>
SudokuBoard<CellType>::get_row(int row) {
  std::vector<CellType *> row_vector;
  for (int col_iter = 0; col_iter < this->get_num_columns(); col_iter++) {
    row_vector.push_back(get_cell_ptr(row, col_iter));
  }
  return row_vector;
}

template<class CellType>
std::vector<CellType *>
SudokuBoard<CellType>::get_col(int col) {
  std::vector<CellType *> col_vector;
  for (int row_iter = 0; row_iter < this->get_num_rows(); row_iter++) {
    col_vector.push_back(get_cell_ptr(row_iter, col));
  }
  return col_vector;
}

template<class CellType>
void
SudokuBoard<CellType>::is_board_string_valid(const std::string &board_config) {
  if (board_config.size() != 81) {
    std::string error_message =
            "Board config must be 81 characters long. (" +
            std::to_string(board_config.size()) + " given).\n" +
            "Board config: " + board_config + "\n";
    throw std::runtime_error(error_message);
  }
  for (auto i : board_config) {
    if (i != '0' && (i < '1' || i > '9')) {
      std::string error_message =
              "Board config must only contain numbers 0-9. (" +
              std::to_string(i) + " given).\n" +
              "Board config: " + board_config + "\n";
      throw std::runtime_error(error_message);
    }
  }
}
