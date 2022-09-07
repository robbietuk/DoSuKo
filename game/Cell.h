//
// Created by Robert Twyman Skelly on 9/2/22.
//

#ifndef DOSUKO_CELL_H
#define DOSUKO_CELL_H


class Cell {
public:
  explicit Cell(int value = 0)
      : value(value) {};

  void set_value(int val) {
    value = val;
  }

  int get_value() const {
    return value;
  }


private: // Variables
  int value;
};


#endif//DOSUKO_CELL_H
