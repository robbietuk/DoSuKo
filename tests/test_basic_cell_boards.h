//
// Created by Robert Twyman Skelly on 9/2/22.
//

#ifndef DOSUKO_TEST_BASIC_CELL_BOARDS_H
#define DOSUKO_TEST_BASIC_CELL_BOARDS_H

#include "SudokuBoard.h"
#include "testing.h"

struct known_possible_updates {
  int row;
  int col;
  std::vector<int> allowed_values;
  std::vector<int> disallowed_values;
};


class TestBasicCellBoards : public Testing {

public:
  explicit TestBasicCellBoards();


  void run_tests() override;

private:
  void test_board_is_completed();
  void test_encoding_and_decoding();
  void test_updates();

private:
  std::string example_problem_string;
  std::string example_solution_string;
  std::string zeros_board_string;
  std::string simple_board_string;

  // Board update tests
  //{
    //! Test specific problem board of `example_problem_string` configuration
    void _test_updates_on_problem_board();

    //! Create board with all Cells having value 0 and insert all values (1-9) into each Cell.
    void _test_updates_on_zeros_board();

    void _test_updates_on_simple_board();



    void _test_updates_know_possible_updates(SudokuBoard board, std::vector<known_possible_updates> possible_updates);
    void _test_update_is_allowed(SudokuBoard board, int row, int col, std::vector<int> allowed_values);
    void _test_update_is_disallowed(SudokuBoard board, int row, int col, std::vector<int> disallowed_values);
  //}

    void test_possible_cell();
};


#endif//DOSUKO_TEST_BASIC_CELL_BOARDS_H