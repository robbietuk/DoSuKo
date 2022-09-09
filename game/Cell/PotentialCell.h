//
// Created by Robert Twyman Skelly on 9/2/22.
//

#ifndef DOSUKO_POTENTIALCELL_H
#define DOSUKO_POTENTIALCELL_H

//#include <vector>
#include "BasicCell.h"
#include <set>

class PotentialCell : public BasicCell {
public:
  PotentialCell(int value = 0)
      : BasicCell(value) {
    clear_potential_values();
  }

  void clear_potential_values() {
    potential_values.clear();
  }

  void add_potential_value(int value) {
    potential_values.insert(value);
  }

  void add_potential_values(std::set<int> pot_vals) {
    this->potential_values.insert(pot_vals.begin(), pot_vals.end());
  }

  void remove_possible_value(int value) {
    potential_values.erase(value);
  }

  std::set<int> * get_potiential_values() {
    return &potential_values;
  }

private: // Variables
    std::set<int> potential_values;
};

#endif//DOSUKO_POTENTIALCELL_H
