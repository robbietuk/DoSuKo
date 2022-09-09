//
// Created by Robert Twyman Skelly on 9/1/22.
//

#include "solver_functions.h"
#include "BasicCell.h"
#include <vector>

//std::tuple<int, int>
//get_singular_empty(std::vector<BasicCell> *cell_ptr) {
//  int empty_index = -1;  // -1 indicates no empty cells found or multiple empty cells found.
//  int determining_value = 45; // This is (n)(n+1)/2, n=9 => 45. Used to determine the missing entry determining_value.
//
//  for (int i = 0; i < cell_ptr->size(); i++) {
//    determining_value -= cell_ptr->at(i).get_value();
//    if (cell_ptr->at(i).get_value() == 0){
//      if (empty_index != -1)
//        return std::make_tuple(-1, -1);
//      empty_index = i;
//
//    }
//  }
//  return std::make_tuple(empty_index, determining_value);
//}