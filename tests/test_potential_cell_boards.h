//
// Created by Robert Twyman Skelly on 9/9/22.
//

#ifndef DOSUKO_TEST_POTENTIAL_CELL_BOARDS_H
#define DOSUKO_TEST_POTENTIAL_CELL_BOARDS_H


#include "testing.h"
#include "ExampleBoardStrings.h"

class TestPotentialCellBoards : public Testing {
public:
  explicit TestPotentialCellBoards()
      : Testing("TestPotentialCellBoards") {}


  void run_tests() override;


private:
  ExampleBoardStrings EBS;
  void test_basic_possible_value_functionality();
};

#endif//DOSUKO_TEST_POTENTIAL_CELL_BOARDS_H
