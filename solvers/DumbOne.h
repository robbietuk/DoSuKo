//
// Created by Robert Twyman Skelly on 8/26/22.
//

#ifndef MAIN_CPP_DUMBONE_H
#define MAIN_CPP_DUMBONE_H

#include "SudokuBoard.h"

class DumbOne {
public:
  explicit DumbOne(SudokuBoard *board_ptr);
  DumbOne();
  ~DumbOne() = default;

  void solve_board();

  bool get_board_solved() const { return board_solved; }


private:
  void compute_next_move();

  bool compute_singular_moves();


public:

private:
  SudokuBoard *board_ptr;
  bool board_solved;
  bool performed_update;
};


#endif//MAIN_CPP_DUMBONE_H
