//
// Created by Robert Twyman Skelly on 9/2/22.
//

#ifndef DOSUKO_POTENTIALCELL_H
#define DOSUKO_POTENTIALCELL_H

//#include <vector>
#include "Cell.h"
#include <set>

class PotentialCell : public Cell {
public:
  PotentialCell(int value = 0)
      : Cell(value) {
    clear_possibles();
  }

  void clear_possibles() {
    potential_values.clear();
  }

  void add_potential_value(int value) {
    potential_values.insert(value);
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
