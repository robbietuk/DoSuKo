//
// Created by Robert Twyman Skelly on 9/2/22.
//

#ifndef DOSUKO_POSSIBLECELL_H
#define DOSUKO_POSSIBLECELL_H

#include <vector>

class PossibleCell {
public:
  PossibleCell(int value = 0) {
    set_value_and_clear_possibles(value);
  }

  void set_value_and_clear_possibles(int value) {
    this->value = value;
    possible_values.clear();
  }
  void add_possible_value(int value) {
    for (auto it = possible_values.begin(); it != possible_values.end(); ++it) {
      if (*it == value) {
        return;
      }
    }
    possible_values.push_back(value);
  }

  void remove_possible_value(int value) {
    for (auto it = possible_values.begin(); it != possible_values.end(); ++it) {
      if (*it == value) {
        possible_values.erase(it);
        break;  // there should not be more than one instance of value in possible_values
      }
    }
  }

  int get_value() const {
    return value;
  }

  [[nodiscard]] const std::vector<int> &get_possible_values() const {
    return possible_values;
  }

private: // Variables
    int value;
    std::vector<int> possible_values;
};

#endif//DOSUKO_POSSIBLECELL_H
