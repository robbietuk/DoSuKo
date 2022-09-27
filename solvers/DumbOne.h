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


public: // methods
  void solve_board();

  bool is_board_marked_as_solved() const { return board_solved; }

  SudokuBoard<PotentialCell> * get_board_ptr() const { return board_ptr; }


private: // methods
  void compute_next_move();
  void evaluate_all_potential_moves_and_apply_singular_values();
//  void compute_stalemate_split();
  void compute_logical_set_difference_options();
  std::set<int> compute_set_of_potential_values(const int row, const int col);

public:  // variables

private:// variables
  SudokuBoard<PotentialCell> *board_ptr;
  bool board_solved;
  bool performed_update;

};


#endif//MAIN_CPP_DUMBONE_H
