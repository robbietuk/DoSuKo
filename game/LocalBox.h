//
// Created by Robert Twyman Skelly on 9/2/22.
//

#ifndef DOSUKO_LOCALBOX_H
#define DOSUKO_LOCALBOX_H

class LocalBox {
public:
  LocalBox(int col, int row, int value = -1) {
    this->col = col;
    this->row = row;
    this->value = value;
  }

public:
  int col;
  int row;
  int value;
  int local_box[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
};
#endif//DOSUKO_LOCALBOX_H
