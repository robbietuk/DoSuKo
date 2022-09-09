//
// Created by Robert Twyman Skelly on 9/2/22.
//

#ifndef DOSUKO_CELL_H
#define DOSUKO_CELL_H


class Cell {
public:
  explicit Cell(int value = 0)
      : val(value) {};

  void set_value(int value) {
    val = value;
  }

  int get_value() const {
    return val;
  }


private: // Variables
  int val;
};


#endif//DOSUKO_CELL_H
