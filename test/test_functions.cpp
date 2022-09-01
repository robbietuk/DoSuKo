//
// Created by Robert Twyman Skelly on 9/1/22.
//

#include <iostream>
#include <vector>

#include "DumbOne.h"
#include "solver_functions.h"


bool test_get_singular_empty(){

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


  test_pass = test_pass && test_get_singular_empty();


  if (test_pass){
    std::cout << "All tests passed." << std::endl;
    return 0;
  } else {
    std::cout << "Some tests failed." << std::endl;
    return 1;
  }
}