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
  test_set_diff();
}

void
TestFunctions::test_set_diff() {
  std::cout << "\n\tTesting set_differences()..." << std::endl;
  std::set<int> A = {1, 2, 5}, B = {2, 3}, C = {4, 5, 6};
  std::set<int> AmB = compute_set_diff(A, B);
  if (AmB != std::set<int>{1,5})
    report_error("test_set_differences: The set difference of A and B should be {1, 5}, but IS NOT.");

  std::set<int> AmBmC = compute_set_diff(AmB, C);
  if (AmBmC != std::set<int>{1})
    report_error("test_set_differences: The set difference of A and B should be {1}, but IS NOT.");
}


int main() {
  bool test_pass = true;

  TestFunctions test_functions;
  test_functions.run_tests();
  test_functions.print_error_message();
  return test_functions.get_testOK();
}

