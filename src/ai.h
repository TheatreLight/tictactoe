#pragma once

#include <string>
#include <vector>

#include "field_draw.h"

class Ai {
 public:
    std::string get_turn_index(Field field);
    void find_place(Field field);
    void set_indexes(int row_index, int col_index) {
        row = row_index;
        col = col_index;
    }
 private:
    bool check_horiz(Field field);
    bool check_vertic(Field field);
    bool check_diag(Field field);
    void search_x(Field field);
    bool is_row_already_blocked(int row);
    bool is_col_already_blocked(int col);
    bool ai_first_turn(Field field);

    int row = 0;
    int col = 0;
    std::vector<int> finded_row {0};
    std::vector<int> finded_col {0};

};