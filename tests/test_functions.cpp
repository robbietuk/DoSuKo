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
  std::vector<int> full_vec =  {1,2,3,4,5,6,7,8,9};
  bool test_pass = true;

  for (int corr_index = 0; corr_index < 9; corr_index++) {
    std::vector<int> test_vec = full_vec;
    test_vec[corr_index] = 0;
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

