//
// Created by Robert Twyman Skelly on 9/1/22.
//

#ifndef DOSUKO_SOLVER_FUNCTIONS_H
#define DOSUKO_SOLVER_FUNCTIONS_H

#include "BasicCell.h"
//#include <iostream>
//#include <vector>
#include <set>

///*!
//    * @brief Returns the index of the first empty cell in the row. OR -1 if no empty cells are found.
//    * @param row The row to search.
//    * @return The index of the first empty cell in the row and the missing val.
//  */
//std::tuple<int, int> get_singular_empty(std::vector<BasicCell> *cell_ptr);


std::set<int> compute_set_diff(std::set<int> set1, std::set<int> set2);


#endif//DOSUKO_SOLVER_FUNCTIONS_H
