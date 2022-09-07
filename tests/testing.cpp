//
// Created by Robert Twyman Skelly on 9/2/22.
//

#include "testing.h"
#include <string>

Testing::Testing(std::string test_name)
    : test_name(test_name) {
    std::cout << "Setting the test_name to " << this->test_name << std::endl;
}

void
Testing::
print_error_message() {
  if (!this->error_message.empty()){
    std::cerr << "Test: " << test_name
              << " failed with the following error message:\n"
              << get_error_message() << std::endl;
  } else if (this->testOK) {
    std::cerr << "Test: " << test_name << " - PASSED!" << std::endl;
  }
}

std::string
Testing::get_test_name() {
  return test_name;
}

void
Testing::add_to_error_message(const std::string &message) {
  if (message.empty()) {
    error_message += "UNKNOWN ERROR!!!!!\n";
    return;
  }
  error_message += message + "\n";
}

std::string
Testing::get_error_message() {
  return error_message;
}
void Testing::report_error(const std::string &message) {
  testOK = false;
  add_to_error_message(message);
}

void Testing::reset_error_status() {
  testOK = true;
  error_message = "";
}
