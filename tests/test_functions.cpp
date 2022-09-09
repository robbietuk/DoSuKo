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

void TestFunctions::run_tests() {}


int main() {
  bool test_pass = true;

  TestFunctions test_functions;
  test_functions.run_tests();
  test_functions.print_error_message();
  return test_functions.get_testOK();
}

