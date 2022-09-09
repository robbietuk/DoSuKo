//
// Created by Robert Twyman Skelly on 9/2/22.
//

#ifndef DOSUKO_BASICCELL_H
#define DOSUKO_BASICCELL_H


class BasicCell {
public:
  explicit BasicCell(int value = 0)
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


#endif//DOSUKO_BASICCELL_H
