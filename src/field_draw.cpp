#include "field_draw.h"

Field::Field(int current_size) {
    size = current_size * 2 + 3;
    field = new char*[size];
    for (int i = 0; i < size; ++i) {
        field[i] = new char[size] {' '};
    }
    first_row();
    first_column();
    fill_other();
}

void Field::paint_arr() {
    char** output_ = field_arr();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout<<output_[i][j];
        }
        std::cout<<std::endl;
    }
}

void Field::set_field(char ch, int row, int col) {
    field[row][col] = ch;
}

void Field::first_row() {
    char fill_ = 'a';
    for (int i = 1; i < size-1; i++) {
        if (i%2 == 0) {
            field[0][i] = fill_;
            ++fill_;
        } else {
            field[0][i] = ' ';
        }
    }
}

void Field::first_column() {
    char fill_ = '1';
    for (int i = 2; i < size-1; ++i) {
        if (i%2 == 0) {
            field[i][0] = fill_;
            ++fill_;
        } else {
            field[i][0] = ' ';
        }
    }
}

void Field::fill_other() {
    for (int i = 1; i < size-1; ++i) {
        for (int j = 1; j < size; ++j) {
            if (i%2 != 0) {
                field[i][j] = '-';
            } else {
                if (j%2 != 0)
                    field[i][j] = '|';
                else
                    field[i][j] = ' ';
            }
        }
    }
    for (int j = 0; j < size; ++j) {
        field[size-1][j] = '`';
    }
    for (int i = 0; i < size; ++i) {
        field[i][size-1] = '`';
    }
}
