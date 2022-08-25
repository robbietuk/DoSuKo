//
// Created by Robert Twyman Skelly on 8/25/22.
//

#ifndef DOSUKO_SUDOKUBOARD_H
#define DOSUKO_SUDOKUBOARD_H

#include <iostream>

struct ColRowVal {
    int col;
    int row;
    int value;
};


class SudokuBoard {
public:
    explicit SudokuBoard(const std::string &board_config);

//    SudokuBoard(const std::string &board_config, int size_x, int size_y);
    ~SudokuBoard() = default;

    void construct_board(const std::string &board_config);

    //! Prints the board to the console.
    void print_board();

    //! Prints the board with boarders to the console.
    void print_board_with_boarder();

    //! Returns the number of rows
    int get_num_rows();

    //! Returns the number of columns
    int get_num_columns();

    //! Updates col,row with value if it is a valid update.
    bool do_update_if_valid(int col, int row, int value);

    //! Returns true if setting col,row to value is valid.
    bool is_valid_update(int col, int row, int value);

    //! Returns a pointer to an array of booleans indicating which indices (+1) are valid for col,row.
    bool *get_valid_entries(int col, int row);

    //! Checks all rows, columns, and boxes for any 0 values.
    bool is_solved();

    //! Returns the a valid move.
    ColRowVal any_valid_moves();

private:
    //! Insets the value at the given position in the board. THERE ARE NO ERROR CHECKS.
    void do_update(int col, int row, int value);

    bool is_free_position(int col, int row);

    bool is_value_in_local_box(int col, int row, int value);

    bool is_value_in_local_row(int row, int value);

    bool is_value_in_local_column(int col, int value);


private:
    //! Board array
    int board_array[9][9]{};
};


#endif //DOSUKO_SUDOKUBOARD_H
