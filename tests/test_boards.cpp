//
// Created by Robert Twyman Skelly on 9/2/22.
//


#include <iostream>
#include <string>
#include "test_boards.h"
#include "SudokuBoard.h"

TestBoards::TestBoards()
    : Testing("TestBoards") {
  example_problem  = "070000043040009610800634900094052000358460020000800530080070091902100005007040802";
  example_solution = "679518243543729618821634957794352186358461729216897534485276391962183475137945862";
}

void 
TestBoards::run_tests() {
  test_updates();
  test_board_is_completed();
  test_encoding_and_decoding();
}
void
TestBoards::test_board_is_completed() {

  std::cout << "\n\tTesting board_is_completed()..." << std::endl;
  SudokuBoard problem_board(example_problem);
  SudokuBoard solution_board(example_solution);
  if (!solution_board.is_solved())
    report_error("test_board_is_completed: The solution board is reported as NOT solved");
  if (problem_board.is_solved())
    report_error("test_board_is_completed: The problem board IS reported as solved");

}
void TestBoards::test_encoding_and_decoding() {
  std::cout << "\n\tTesting encoding and decoding()..." << std::endl;
  SudokuBoard solution_board(example_solution);
  std::string encoded_board_string = solution_board.encode();
  if (encoded_board_string != example_solution)
    report_error("test_encoding_and_decoding: The encoded board does not match the original solution board"
                 "\n\tORIGINAL:  " + example_solution +
                 "\n\tREENCODED: " + encoded_board_string);
}

void
TestBoards::test_updates() {
  std::cout << "\n\tTesting updates()..." << std::endl;
  _test_updates_empty_board();
  _test_updates_special_boards();
  _test_updates_problem_board();
}

void
TestBoards::_test_updates_problem_board() {
  SudokuBoard problem_board(example_problem);
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

void
TestBoards::_test_updates_empty_board(){

  // Create board with all zeros
  std::string zeros;
  for (int i = 1; i < 82; i++)
    zeros += "0";
  SudokuBoard empty_board(zeros);

  // Create a vector of known_possible_updates for each Cell and assign all possible values
  std::vector all_values = {1,2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<known_possible_updates> possible_updates_vec(81);
  for (int col = 0; col < 9; col++)
    for (int row = 0; row < 9; row++)
      possible_updates_vec[1] = {row, col, all_values};

  // Run test on all possible_update configurations on the empty board
  _test_updates_know_possible_updates(empty_board, possible_updates_vec);
}

void
TestBoards::_test_updates_special_boards() {
  // Create board with all zeros
  std::string board_str;
  for (int i = 1; i < 82; i++)
    board_str += "0";
  board_str[1] = '1';  // Add '1' to the 0th row, 1st column Cell (array starts at 0)
  board_str[9] = '2';  // Add '2' to the 1st row, 0th column Cell (array starts at 0)
  SudokuBoard board(board_str);


  std::vector<known_possible_updates> possible_updates_vec = {
          {0,0, {3,4,5,6,7,8,9}, {1,2}}
  };
  _test_updates_know_possible_updates(board, possible_updates_vec);


}

void
TestBoards::_test_updates_know_possible_updates(SudokuBoard board, std::vector<known_possible_updates> possible_updates) {

  for (auto &possible_update : possible_updates) {
    _test_update_is_allowed(board, possible_update.row, possible_update.col, possible_update.allowed_values);
    _test_update_is_disallowed(board, possible_update.row, possible_update.col, possible_update.disallowed_values);
  }
}

void TestBoards::_test_update_is_allowed(SudokuBoard board, int row, int col, std::vector<int> allowed_values) {
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

void TestBoards::_test_update_is_disallowed(SudokuBoard board, int row, int col, std::vector<int> disallowed_values) {
  for (int value : disallowed_values){
    if (board.is_valid_cell_update(row, col, value)) {
      board.is_valid_cell_update(row, col, value);
      std::string err_msg = "test_updates: The value " + std::to_string(value) +
                            " is marked as disallowed in cell " + std::to_string(col) + "," + std::to_string(col) + " by the test. "
                                                                                                                    "BUT the board returns true, indicating no issue with the entry.\n";

      report_error(err_msg);
    }
  }
}


int main() {
  TestBoards test_boards;
  test_boards.run_tests();
  test_boards.print_error_message();
  return test_boards.get_testOK();
}
