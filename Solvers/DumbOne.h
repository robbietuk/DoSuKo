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

  /*!
    * @brief Returns the index of the first empty cell in the row. OR -1 if no empty cells are found.
    * @param row The row to search.
    * @return The index of the first empty cell in the row and the missing value.
  */
  std::tuple<int, int> get_singular_empty(std::vector<int> entries);


public:

private:
  SudokuBoard *board_ptr;
  bool board_solved;
  bool performed_update;
};


#endif//MAIN_CPP_DUMBONE_H
