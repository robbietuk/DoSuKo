//
// Created by Robert Twyman Skelly on 9/9/22.
//

#include "test_potential_cell_boards.h"
#include "SudokuBoard.h"
#include "Cell.h"


void
TestPotentialCellBoards::run_tests() {

  // Construct board
  SudokuBoard<PotentialCell> zeros_board(EBS.zeros_board_string);
  zeros_board.get_cell_ptr(0, 0)->set_value(1);
  if (zeros_board.get_cell_ptr(0, 0)->get_value() != 1)
    report_error("test_updates: The value of the cell (0,0) is not 1");

}

int
main() {
  TestPotentialCellBoards test;
  test.run_tests();
  test.print_error_message();
  return test.get_testOK();
}

