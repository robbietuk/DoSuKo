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
  test_board_is_completed();
  test_encoding_and_decoding();
  test_updates();
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
  std::string solution_board_string = solution_board.encode();
  if (solution_board_string != example_solution)
    report_error("test_encoding_and_decoding: The encoded board does not match the original");
}

void
TestBoards::test_updates() {
  std::cout << "\n\tTesting updates()..." << std::endl;
  SudokuBoard problem_board(example_problem);
  SudokuBoard solution_board(example_solution);

  // Allowed and disallowed values for cell (0,0)
  std::vector<int> allowed_values = {1,2,5,6,7};
  std::vector<int> disallowed_values = {3,4,7,8,9};

  int col = 0, row = 0;
  for (int value : allowed_values) {
    if (!problem_board.is_valid_cell_update(col,row,value)){
      std::string err_msg = "test_updates: The value " + std::to_string(value) +
                            " is marked as allowed in cell (0,0) by the test. BUT the board returns false.\n";
      if (!problem_board.is_free_position(col,row))
        err_msg += "\t- The cell at" + std::to_string(col) + "," + std::to_string(row) +
                   " is not 0 and has value " + std::to_string(problem_board.get_cell(col,row).get_value()) + "\n";
      if (!problem_board.is_value_in_local_row(row, value))
        err_msg += "\t- The value " + std::to_string(value) +
                   " is in the local row of the cell at " + std::to_string(row) + "\n";
      if (!problem_board.is_value_in_local_column(col, value))
          err_msg += "\t- The value " + std::to_string(value) +
                       " is in the local column of the cell at " + std::to_string(col) + "\n";
      if (!problem_board.is_value_in_local_box(col, row, value))
          err_msg += "\t- The value " + std::to_string(value) +
                       " is in the local box of the cell at " + std::to_string(col) + "," + std::to_string(row) + "\n";
      report_error(err_msg);
    }
  }
  for (int value : disallowed_values){
    if (problem_board.is_valid_cell_update(col,row,value)){
      std::string err_msg = "test_updates: The value " + std::to_string(value) +
                            " is marked as disallowed in cell (0,0) by the test. "
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
