//
// Created by Robert Twyman Skelly on 9/1/22.
//

#include <iostream>
#include <vector>

#include "test_functions.h"
#include "DumbOne.h"
#include "solver_functions.h"


TestFunctions::TestFunctions()
    : Testing("TestFunctions") {}

void TestFunctions::run_tests() {
  test_get_singular_empty();
}
bool
TestFunctions::test_get_singular_empty() {
  DumbOne dumb1;
  std::vector<Cell> full_vec =  {Cell(1), Cell(2), Cell(3),
                                Cell(4), Cell(5), Cell(6),
                                Cell(7), Cell(8), Cell(9)};
  bool test_pass = true;

  for (int corr_index = 0; corr_index < 9; corr_index++) {
    std::vector<Cell> test_vec = full_vec;
    test_vec[corr_index].set_value(0);
    int index, value;
    std::tie(index, value) = get_singular_empty(test_vec);
    if (index != corr_index || value != corr_index + 1) {
      test_pass = false;
      break;
    }
  }
  return test_pass;
}


int main() {
  bool test_pass = true;

  TestFunctions test_functions;
  test_functions.run_tests();
  test_functions.print_error_message();
  return test_functions.get_testOK();
}

