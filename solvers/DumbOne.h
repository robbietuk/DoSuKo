//
// Created by Robert Twyman Skelly on 8/26/22.
//

#ifndef MAIN_CPP_DUMBONE_H
#define MAIN_CPP_DUMBONE_H

#include "PotentialCell.h"
#include "SudokuBoard.h"

class DumbOne {
public:
  explicit DumbOne(SudokuBoard<PotentialCell> *board_ptr);
  DumbOne();
  ~DumbOne() = default;

  void solve_board();

  bool get_board_solved() const { return board_solved; }

  SudokuBoard<PotentialCell> * get_board_ptr() const { return board_ptr; }


private:
  void compute_next_move();



public:

private:
  SudokuBoard<PotentialCell> *board_ptr;
  bool board_solved;
  bool performed_update;
  void evaluate_all_potential_moves();
  std::set<int> get_set_of_potential_values(const int row, const int col);
};


#endif//MAIN_CPP_DUMBONE_H
