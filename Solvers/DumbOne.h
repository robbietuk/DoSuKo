//
// Created by Robert Twyman Skelly on 8/26/22.
//

#ifndef MAIN_CPP_DUMBONE_H
#define MAIN_CPP_DUMBONE_H

#include "SudokuBoard.h"

class DumbOne {
public:
    explicit DumbOne(SudokuBoard *board_ptr);
    ~DumbOne() = default;

    void solve_board();

private:
  SudokuBoard *board_ptr;
};


#endif//MAIN_CPP_DUMBONE_H
