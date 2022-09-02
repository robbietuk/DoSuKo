//
// Created by Robert Twyman Skelly on 9/2/22.
//

#include "testing.h"


Testing::Testing() {
    std::cout << "Testing constructor called" << std::endl;
}

void
Testing::
print_error_message() const {
  std::cout << "Test: " << test_name
            << " failed with the following error message:\n"
            << error_message << std::endl;
}

void
Testing::set_test_name(const std::string &name) {
  test_name = name;
}

void
Testing::add_to_error_message(const std::string &message) {
  error_message += message + "\n";
}
