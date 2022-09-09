//
// Created by Robert Twyman Skelly on 9/9/22.
//

#include "test_potential_cell_boards.h"
#include "SudokuBoard.h"
#include "Cell.h"


void
TestPotentialCellBoards::run_tests() {
  test_basic_possible_value_functionality();

}

void TestPotentialCellBoards::test_basic_possible_value_functionality() {
  // Construct board
  SudokuBoard<PotentialCell> zeros_board(EBS.zeros_board_string);
  PotentialCell * cell_ptr = zeros_board.get_cell_ptr(0, 0);

  // Add 2 and 3 to possible values
  cell_ptr->add_potential_value(2);
  cell_ptr->add_potential_value(3);
  std::set<int> * potential_values_ptr = cell_ptr->get_potiential_values();
  if (potential_values_ptr->size() != 2)
    report_error("test_updates: The number of possible values for cell (0,0) should be, but IS NOT, 2.");

  // Now remove 2
  cell_ptr->remove_possible_value(2);
  if (potential_values_ptr->size() != 1)
    report_error("test_updates: The number of possible values for cell (0,0) should be, but IS NOT, 1.");

  cell_ptr->remove_possible_value(4);
  if (potential_values_ptr->size() != 1)
    report_error("test_updates: The number of possible values for cell (0,0) should be, but IS NOT, 1.");
}

int
main() {
  TestPotentialCellBoards test;
  test.run_tests();
  test.print_error_message();
  return test.get_testOK();
}

