//
// Created by Robert Twyman Skelly on 8/26/22.
//

#include "DumbOne.h"
#include "PotentialCell.h"
#include "ColRowVal.h"
#include "solver_functions.h"
#include <vector>

DumbOne::
DumbOne(SudokuBoard<PotentialCell> *board_ptr) {
    this->board_ptr = board_ptr;
    board_solved = this->board_ptr->is_solved();
    performed_update = false;
}

DumbOne::
DumbOne() {
    board_ptr = nullptr;
    board_solved = false;
    performed_update = false;
}

void
DumbOne::
solve_board() {

  performed_update = false;
  while(true) {
    if (board_solved)
      break;

    compute_next_move();
    board_solved = board_ptr->is_solved();
    if (!performed_update)
      break;
  }
}

void
DumbOne::compute_next_move() 
{
  performed_update = false;
  evaluate_all_potential_moves_and_apply_singular_values();
  if (performed_update)
    return; // Progress was made, repeat cheap iterations until no progress is made.

  compute_logical_set_difference_options();
}

void 
DumbOne::evaluate_all_potential_moves_and_apply_singular_values() 
{
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      PotentialCell * cell = board_ptr->get_cell_ptr(row, col);
      if (cell->get_value() != 0) 
      {
        cell->clear_potential_values();
        continue;
      }

      //cell is 0 value
      std::set<int> pot_vals = compute_set_of_potential_values(row, col);
      if (pot_vals.size() == 1) {
        //only one potential value and it can be assigned as value
        int value = *pot_vals.begin();
        board_ptr->do_update_cell_if_valid(row, col, value);
        performed_update = true;
      }
      else 
      {
        //more than one potential value
        cell->add_potential_values(pot_vals);
      }
    }
  }
}

std::set<int>
DumbOne::compute_set_of_potential_values(const int row, const int col) 
{
  std::set<int> potential_values;
  for (int value = 1; value <= 9; value++) {
    if (board_ptr->is_valid_cell_update(row, col, value)) 
      potential_values.insert(value);
  }
  return potential_values;
}

void 
DumbOne::compute_logical_set_difference_options() 
{
  // Idea
  // Assume two cells (A and B) in a row, col, local box have potential values evaluated - they should
  // compute the set difference of the two cells.
  //
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      PotentialCell * cell = board_ptr->get_cell_ptr(row, col);
      if (cell->get_value() != 0) {
        cell->clear_potential_values();
        continue;
      }
      
      // cell is 0 value
      // A new unique version of the potential values
      std::set<int> logical_potential_values = *cell->get_potiential_values_ptr();
      
      for (auto friend_cell_get_method : {board_ptr->get_row(row), board_ptr->get_col(col), board_ptr->get_local_box_cells(row, col)}) {
        for (auto friend_cell : friend_cell_get_method) {
          auto friend_cell_value = friend_cell->get_value();
          logical_potential_values.erase(friend_cell_value);
        }
      }

      if (logical_potential_values.size() == 1)
        std::cout << "row: " << row << " col: " << col << " logical_potential_values: " << logical_potential_values.size() << std::endl;
    }
  }
}


//void DumbOne::compute_stalemate_split() {
//  // A stalemate indicates that there are no cells with only one potential value left.
//  // i.e. cell A has potential values of (1,2) and cell B has potential values of (1,2)
//  // in this case, we need to guess the value of one of the cells and iterate through the loop.
//  // However, the chosen path may not be the correct one so the algorithm may need to revert back to a previous state.
//
//  for
//}
