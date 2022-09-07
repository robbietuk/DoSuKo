//
// Created by Robert Twyman Skelly on 9/2/22.
//

#ifndef DOSUKO_TEST_BOARDS_H
#define DOSUKO_TEST_BOARDS_H

#include "testing.h"

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

};


#endif//DOSUKO_TEST_BOARDS_H
