#pragma once

#include <string>

#include "field_draw.h"

class PlayerController {
 public:
    void set_turn(Field field, char ch);
    void set_indexes(std::string turn_);
    int get_row() {
      return row_index;
    }
    int get_column() {
      return column_index;
    }

 private:
    unsigned int row_index = 0;
    unsigned int column_index = 0;
};
