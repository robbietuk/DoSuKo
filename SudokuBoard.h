//
// Created by Robert Twyman Skelly on 8/25/22.
//

#ifndef DOSUKO_SUDOKUBOARD_H
#define DOSUKO_SUDOKUBOARD_H

#include <iostream>


class SudokuBoard {
public:
    explicit SudokuBoard(const std::string &board_config);
//    SudokuBoard(const std::string &board_config, int size_x, int size_y);
    ~SudokuBoard() {}

    void print_board();

    int get_size_x();
    int get_size_y();

    void update_board(int x, int y, int value);




private:
    //! Board array
    int board_array[9][9];
};


#endif //DOSUKO_SUDOKUBOARD_H
