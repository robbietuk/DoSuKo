//
// Created by Robert Twyman Skelly on 9/2/22.
//


#include <iostream>
#include <string>
#include "test_boards.h"
#include "SudokuBoard.h"

TestBoards::TestBoards() : Testing("TestBoards") {
  example_problem  = "070000043040009610800634900094052000358460020000800530080070091902100005007040802";
  example_solution = "679518243543729618821634957794352186358461729216897534485276391962183475137945862";
}

void 
TestBoards::run_tests() {
  test_board_is_completed();
}
void
TestBoards::test_board_is_completed() {
  SudokuBoard problem_board(example_problem);
  SudokuBoard solution_board(example_solution);
  if (!solution_board.is_solved())
    add_to_error_message("test_board_is_completed: The solution board is reported as NOT solved");
  if (problem_board.is_solved())
    add_to_error_message("test_board_is_completed: The problem board IS reported as solved");

}


int main() {
  TestBoards test_boards;
  test_boards.run_tests();
  test_boards.print_error_message();
  return test_boards.get_testOK();
}
