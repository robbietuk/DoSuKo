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
  explicit Testing(std::string testName);

  // main run_tests function to be overridden by child classes.
  virtual void run_tests() = 0;

  //! Get the name of the test.
  std::string get_test_name();

  //! Prints the error message to the console.
  void print_error_message();

  //! Returns the error message string.
  std::string get_error_message();

  //! Reports an error has_error and adds a message to the error message.
  void report_error(const std::string &message);

  //! Resets the error status and error message. BEWARE, erases all previous related errors..
  void reset_error_status();

  //! Returns the error status for program exit.
  bool get_testOK() { return !testOK; }

private:

  //! Adds a string message to the error message with "\n" between entries.
  void add_to_error_message(const std::string &message);

  //! The name of the test.
  std::string test_name;

  //! The error message to be printed if the test fails.
  std::string error_message;

  //! Bool used to determine if the test passed or failed.
  bool testOK = true;
};


#endif//DOSUKO_TESTING_H
