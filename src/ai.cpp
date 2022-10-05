#include "ai.h"

bool Ai::check_horiz(Field field) {
    char** tmp = field.field_arr();
    if (is_row_already_blocked(row)) return false;
    for (int i = 2; i < field.get_size(); ++i) {
        if (tmp[row][i] == 'X' && tmp[row][i+2] == 'X') {
            col = i+2;
            return true;
        }
    }
    return false;
}

bool Ai::check_vertic(Field field) {
    char** tmp = field.field_arr();
    if (is_col_already_blocked(col)) return false;
    for (int i = 2; i < field.get_size(); ++i) {
        if (tmp[i][col] == 'X' && tmp[i+2][col] == 'X') {
            row = i+2;
            return true;
        }
    }
    return false;
}

bool Ai::check_diag(Field field) {
    char** tmp = field.field_arr();
    for (int i = 2, count = 0; i < field.get_size(); ++i) {
        if (tmp[i][i] == 'X') count++;
        if (count == 2) return true;
    }
    for (int i = 2, j = field.get_size()-3, count = 0; i < field.get_size(); ++i) {
        if (tmp[i][j] == 'X') count++;
        if (count == 2) return true;
    }

    return false;
}

bool Ai::is_row_already_blocked(int _row) {
    for(auto elem : finded_row) {
        if (elem == _row)
            return true;
    }
    return false;
}

bool Ai::is_col_already_blocked(int _col) {
    for(auto elem : finded_col) {
        if (elem == _col)
            return true;
    }
    return false;
}

void Ai::search_x(Field field) {
    char** tmp = field.field_arr();
    for (int i = 2; i < field.get_size(); ++i) {
        if (is_row_already_blocked(i)) continue;
        for (int j = 2; j < field.get_size(); ++j) {
            if (is_col_already_blocked(j)) continue;
            if (tmp[i][j] == 'X') {
                row = i;
                col = j;
                return;
            }
        }
    }
}

void Ai::find_place(Field field) {
    char** tmp = field.field_arr();
    search_x(field);
    if (ai_first_turn(field)) {
        row = col = field.get_size() / 2 +1;
        return;
    }

    if (check_horiz(field)) {
        for (int j = 0; j < field.get_size(); ++j) {
            if (tmp[row][j] == ' ') {
                col = j;
                return;
            }
        }
    } else if (check_vertic(field)) {
        for (int i = 0; i < field.get_size(); ++i) {
            if (tmp[i][col] == ' ') {
                row = i;
                return;
            }
        }
    } else if (check_diag(field)) {
        char ch = '\0';
        for (int i = 1; i < field.get_size(); ++i) {
            ch = tmp[i][i];
            if (ch == ' ') {
                row = col = i;
                return;
            }
        }
        if (ch != ' ') {
            for (int i = 0, j = field.get_size()-1; i < field.get_size(); ++i, --j) {
                if (tmp[i][j] == ' ') {
                    row = i;
                    col = j;
                    return;
                }
            }
        }

    } else {
        for (int i = 1; i < field.get_size(); ++i) {
            for (int j = 2; j < field.get_size(); ++j) {
                if (tmp[i][j] == ' ') {
                    row = i;
                    col = j;
                    return;
                }
            }
        }
    }

    for (int i = 2; i < field.get_size(); ++i) {
        for (int j = 2; j < field.get_size(); ++j) {
            if (tmp[i][j] == ' ') {
                row = i;
                col = j;
                return;
            }
        }
    }
}

std::string Ai::get_turn_index(Field field) {
    finded_row.push_back(row);
    finded_col.push_back(col);
    std::string index {""};
    char first = row / 2 + 48;
    index.push_back(first);
    char second = col / 2 + 96;
    index.push_back(second);
    return index;
}

bool Ai::ai_first_turn(Field field) {
    char** tmp = field.field_arr();
    for(int i = 2; i < field.get_size(); ++i) {
        for (int j = 2; j < field.get_size(); ++j) {
            if (tmp[i][j] == 'X' || tmp[i][j] == 'O') return false;
        }
    }
    return true;
}
