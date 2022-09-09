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

    if (!performed_update) {
      // Did not perform a valid update.
      ColRowVal possible_moves = board_ptr->any_valid_moves();
      if (possible_moves.value == -1) {
        break;
      }
      break; // todo: Not sure what to do here....
    }
  }
}

void
DumbOne::
compute_next_move() {
  performed_update = false;
  evaluate_all_potential_moves();
}

void DumbOne::evaluate_all_potential_moves() {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      PotentialCell * cell = board_ptr->get_cell_ptr(row, col);
      if (cell->get_value() != 0) {
        cell->clear_potential_values();
        continue;
      }
      //cell is 0 value
      //todo this should use set notation
      std::set<int> pot_vals = get_set_of_potential_values(row, col);
      if (pot_vals.size() == 1) {
        //only one potential value
        int value = *pot_vals.begin();
        board_ptr->do_update_cell_if_valid(row, col, value);
        performed_update = true;
      }
      else {
        //more than one potential value
        cell->add_potential_values(pot_vals);
      }
    }
  }
}
std::set<int>
DumbOne::get_set_of_potential_values(const int row, const int col) {
  std::set<int> potential_values;
  for (int i = 1; i <= 9; i++) {
    if (board_ptr->is_valid_cell_update(row, col, i)) {
      potential_values.insert(i);
    }
  }
  return potential_values;
}
