//
// Created by Robert Twyman Skelly on 9/2/22.
//

#ifndef DOSUKO_TEST_BOARDS_H
#define DOSUKO_TEST_BOARDS_H

#include "SudokuBoard.h"
#include "testing.h"

struct known_possible_updates {
  int row;
  int col;
  std::vector<int> allowed_values;
  std::vector<int> disallowed_values;
};


class TestBoards : public Testing {

public:
  explicit TestBoards();


  void run_tests() override;

private:
  void test_board_is_completed();
  void test_encoding_and_decoding();
  void test_updates();

private:
  std::string example_problem;
  std::string example_solution;

  // Board update tests
  //{
    //! Test specific problem board of `example_problem` configuration
    void _test_updates_problem_board();

    //! Create board with all Cells having value 0 and insert all values (1-9) into each Cell.
    void _test_updates_empty_board();

    void _test_updates_special_boards();

    void _test_updates_know_possible_updates(SudokuBoard board, std::vector<known_possible_updates> possible_updates);

    void _test_update_is_allowed(SudokuBoard board, int row, int col, std::vector<int> allowed_values);
    void _test_update_is_disallowed(SudokuBoard board, int row, int col, std::vector<int> disallowed_values);
  //}
};


#endif//DOSUKO_TEST_BOARDS_H
