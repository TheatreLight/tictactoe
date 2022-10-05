#pragma once

#include <iostream>

class Field {
 public:
    Field(int current_size);
    void paint_arr();
    void set_field(char ch, int row, int col);
    char** field_arr() {
        return field;
    }
    int get_size() {
        return size;
    }

 private:
    void first_row();
    void first_column();
    void fill_other();

    int size;
    char **field;

};