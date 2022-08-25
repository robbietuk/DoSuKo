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
    void print_board_with_boarder();

    int get_num_rows();
    int get_num_columns();

    bool do_update_if_valid(int col, int row, int value);
    bool is_valid_update(int col, int row, int value);

private:
    //! Insets the value at the given position in the board. THERE ARE NO ERROR CHECKS.
    void do_update(int col, int row, int value);

    bool is_free_position(int col, int row);
    bool is_value_in_local_box(int col, int row, int value);
    bool is_value_in_local_row(int row, int value);
    bool is_value_in_local_column(int col, int value);


private:
    //! Board array
    int board_array[9][9];
};


#endif //DOSUKO_SUDOKUBOARD_H
