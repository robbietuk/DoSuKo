//
// Created by Robert Twyman Skelly on 9/2/22.
//

#ifndef DOSUKO_TESTING_H
#define DOSUKO_TESTING_H

#include <iostream>
#include <string>


class Testing {
public:
  //! Base class for testing.
  Testing();

  // main run_test function to be overridden by child classes.
  virtual bool run_test() = 0;

  //! Set the name of the test.
  void set_test_name(const std::string &name);
  void add_to_error_message(const std::string &message);

  void print_error_message() const;


public:
  bool testOK = true;


private:
  std::string test_name = "NonOverriddenTestName";
  std::string error_message;
};


#endif//DOSUKO_TESTING_H
