//
// Created by Robert Twyman Skelly on 8/26/22.
//

#include <vector>
#include "DumbOne.h"

DumbOne::
DumbOne(SudokuBoard *board_ptr) {
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
  compute_singular_moves();
}


bool DumbOne::compute_singular_moves() {

  std::vector<int> entries(9);
  for (int i = 1; i <= 9; i++) {
    entries = board_ptr->get_row(i);

    int singular_empty_index, singular_empty_value;
    std::tie(singular_empty_index, singular_empty_value)  = get_singular_empty(entries);
    if (singular_empty_index == -1)
      continue ;  // No singular empty cells found.
    board_ptr->is_valid_cell_update(singular_empty_index, i, singular_empty_value);
    performed_update = true;
    return true;
  }
  return false;
}

std::tuple<int, int>
DumbOne::
get_singular_empty(std::vector<int> entries) {
  int empty_index = -1;  // -1 indicates no empty cells found or multiple empty cells found.
  int value = 45; // This is (n)(n+1)/2, n=9 => 45. Used to determine the missing entry value.

  for (int i = 0; i < entries.size(); i++) {
    value -= entries[i];
    if (entries[i] == 0){
      if (empty_index != -1)
        return std::make_tuple(-1, -1);
      empty_index = i;

    }
  }
  return std::make_tuple(empty_index, value);
}
