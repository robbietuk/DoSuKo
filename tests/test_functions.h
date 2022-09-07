//
// Created by Robert Twyman Skelly on 9/2/22.
//

#ifndef DOSUKO_TEST_FUNCTIONS_H
#define DOSUKO_TEST_FUNCTIONS_H

#include <string>
#include "testing.h"


class TestFunctions: public Testing {

public:
  explicit TestFunctions();

  void run_tests() override;

private:
  //! Test the get_singular_empty() function
  bool test_get_singular_empty();

};

#endif//DOSUKO_TEST_FUNCTIONS_H
