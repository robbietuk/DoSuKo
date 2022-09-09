//
// Created by Robert Twyman Skelly on 9/2/22.
//


#include "test_basic_cell_boards.h"
#include "SudokuBoard.h"
#include "Cell.h"
#include <iostream>
#include <string>

TestBasicCellBoards::TestBasicCellBoards()
    : Testing("TestBasicCellBoards") {
  // Problem and solution for problem boards
  example_problem_string = "070000043040009610800634900094052000358460020000800530080070091902100005007040802";
  example_solution_string = "679518243543729618821634957794352186358461729216897534485276391962183475137945862";

  // Create board with all zeros
  zeros_board_string = "";
  for (int i = 1; i < 82; i++)
    zeros_board_string += "0";

  // Construct simple board
  simple_board_string = zeros_board_string;
  simple_board_string[1] = '1';  // Add '1' to the 0th row, 1st column Cell (array starts at 0)
  simple_board_string[9] = '2';  // Add '2' to the 1st row, 0th column Cell (array starts at 0)
}

void TestBasicCellBoards::run_tests() {
  test_updates();
  test_board_is_completed();
  test_encoding_and_decoding();
}

void TestBasicCellBoards::test_board_is_completed() {

  std::cout << "\n\tTesting board_is_completed()..." << std::endl;
  SudokuBoard<Cell> problem_board(example_problem_string);
  SudokuBoard<Cell> solution_board(example_solution_string);
  if (!solution_board.is_solved())
    report_error("test_board_is_completed: The solution board is reported as NOT solved");
  if (problem_board.is_solved())
    report_error("test_board_is_completed: The problem board IS reported as solved");

}
void TestBasicCellBoards::test_encoding_and_decoding() {
  std::cout << "\n\tTesting encoding and decoding()..." << std::endl;
  SudokuBoard<Cell> solution_board(example_solution_string);
  std::string encoded_board_string = solution_board.encode();
  if (encoded_board_string != example_solution_string)
    report_error("test_encoding_and_decoding: The encoded board does not match the original solution board"
                 "\n\tORIGINAL:  " +
                 example_solution_string +
                 "\n\tREENCODED: " + encoded_board_string);
}

void TestBasicCellBoards::test_updates() {
  std::cout << "\n\tTesting updates()..." << std::endl;
  _test_updates_on_zeros_board();
  _test_updates_on_simple_board();
  _test_updates_on_problem_board();
}

void TestBasicCellBoards::_test_updates_on_problem_board() {
  SudokuBoard<Cell> problem_board(example_problem_string);
  std::vector<known_possible_updates> possible_updates = {
          {0, 0,  // Allowed and disallowed allowed_values for cell (0,0)
           {1,2,5,6},
           {3,4,7,8,9}
          },
          {5, 4,  // Allowed and disallowed allowed_values for cell (4,5)
           {1,9},
           {2,3,4, 5,6, 7,8}},
  };
  _test_updates_know_possible_updates(problem_board, possible_updates);
}

void TestBasicCellBoards::_test_updates_on_zeros_board(){
  SudokuBoard<Cell> zeros_board(zeros_board_string);

  // Create a vector of known_possible_updates for each Cell and assign all possible values
  std::vector all_values = {1,2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<known_possible_updates> possible_updates_vec(81);
  for (int col = 0; col < 9; col++)
    for (int row = 0; row < 9; row++)
      possible_updates_vec[1] = {row, col, all_values};

  // Run test on all possible_update configurations on the empty board
  _test_updates_know_possible_updates(zeros_board, possible_updates_vec);
}

void TestBasicCellBoards::_test_updates_on_simple_board() {
  SudokuBoard<Cell> board(simple_board_string);


  std::vector<known_possible_updates> possible_updates_vec = {
          {0,0,
           {3,4,5,6,7,8,9},
           {1,2}},
          {0,1, {}, {1,2,3,4,5,6,7,8,9}
          }
  };
  _test_updates_know_possible_updates(board, possible_updates_vec);
}

void TestBasicCellBoards::_test_updates_know_possible_updates(SudokuBoard<Cell> board, std::vector<known_possible_updates> possible_updates) {

  for (auto &possible_update : possible_updates) {
    _test_update_is_allowed(board, possible_update.row, possible_update.col, possible_update.allowed_values);
    _test_update_is_disallowed(board, possible_update.row, possible_update.col, possible_update.disallowed_values);
  }
}

void TestBasicCellBoards::_test_update_is_allowed(SudokuBoard<Cell> board, int row, int col, std::vector<int> allowed_values) {
  for (int value : allowed_values) {
    if (!board.is_valid_cell_update(row, col, value)){
      //Some error exists, lets diagnose it
      std::string err_msg = "test_updates: The value " + std::to_string(value) +
                            " is marked as allowed in cell (row: " + std::to_string(row) + ", col: " + std::to_string(col) + ") by the test. BUT the board returns false.\n";
      if (!board.is_free_position(row, col))
        err_msg += "\t- The cell at(row: " + std::to_string(row) + ", col: " + std::to_string(col) + " is not 0 and has value " +
                   std::to_string(board.get_cell_ptr(row, col)->get_value()) + "\n";
      if (!board.is_value_in_local_row(row, value))
        err_msg += "\t- The value " + std::to_string(value) +
                   " is in the local row of the cell at row: " + std::to_string(row) + "\n";
      if (!board.is_value_in_column(col, value))
        err_msg += "\t- The value " + std::to_string(value) +
                   " is in the local column of the cell at col: " + std::to_string(col) + "\n";
      if (!board.is_value_in_local_box(row, col, value))
        err_msg += "\t- The value " + std::to_string(value) +
                   " is in the local box of the cell at (row: " + std::to_string(row) + ", col: " + std::to_string(col) + ")\n";
      report_error(err_msg);
    }
  }
}

void TestBasicCellBoards::_test_update_is_disallowed(SudokuBoard<Cell> board, int row, int col, std::vector<int> disallowed_values) {
  for (int value : disallowed_values){
    if (board.is_valid_cell_update(row, col, value)) {
      board.is_valid_cell_update(row, col, value);
      std::string err_msg = "test_updates: The value " + std::to_string(value) +
                            " is marked as disallowed in cell " + std::to_string(col) + "," +
                            std::to_string(col) +
                            " by the test. BUT the board returns true, indicating no issue with the entry.\n";

      report_error(err_msg);
    }
  }
}


int main() {
  TestBasicCellBoards test_boards;
  test_boards.run_tests();
  test_boards.print_error_message();
  return test_boards.get_testOK();
}
