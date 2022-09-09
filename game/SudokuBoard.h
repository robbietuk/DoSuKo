//
// Created by Robert Twyman Skelly on 8/25/22.
//

#ifndef DOSUKO_SUDOKUBOARD_H
#define DOSUKO_SUDOKUBOARD_H

#include "ColRowVal.h"
#include "LocalBox.h"
#include "PossibleCell.h"
#include "Cell.h"
#include <iostream>



template <class CellType>
class SudokuBoard {
public:
  SudokuBoard();
  explicit SudokuBoard(const std::string &board_config);

  void reset_board_array();

  void construct_board(const std::string &board_config);

  std::string encode();

  //! Prints the board to the console.
  void print_board_2D_visualisation();

  //! Prints the board with boarders to the console.
  std::string get_board_as_string_with_boarders();

  //! Returns the number of rows
  int get_num_rows();

  //! Returns the number of columns
  int get_num_columns();

  //! Updates col,row with value if it is a valid update.
  bool do_update_cell_if_valid(int row, int col, int value);

  //! Returns true if setting col,row to value is valid.
  bool is_valid_cell_update(int row, int col, int value);

  //! Returns a pointer to an array of booleans indicating which indices (+1) are valid for col,row.
  bool *get_valid_entries(int row, int col);

  //! Checks all rows, columns, and boxes for any 0 allowed_values.
  bool is_solved();

  //! Returns the a valid move.
  ColRowVal any_valid_moves();

  //! Returns a local box object the col,row combo is in.
  LocalBox get_local_box_values(int row, int col);

  //! Returns a vector of allowed_values corresponding to the indicated row.
  std::vector<CellType *> get_row(int row);

  //! Returns a vector of allowed_values corresponding to the indicated column.
  std::vector<CellType *> get_col(int col);

  bool is_value_in_local_box(int row, int col, int value);

  bool is_value_in_local_row(int row, int value);

  bool is_value_in_column(int col, int value);

  bool is_free_position(int row, int col);

  static void is_board_string_valid(const std::string &board_config);

  CellType * get_cell_ptr(int row, int col);

private:
  //! Insets the value at the given position in the board. THERE ARE NO ERROR CHECKS.
  void do_update(int row, int col, int value);

private:
  //! Board array
  CellType board_array[9][9];

  std::string is_valid_update_error_message;
  std::string get_board_2D_visualisation();
};

#include "SudokuBoard.inl"

#endif //DOSUKO_SUDOKUBOARD_H
