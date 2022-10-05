#pragma once

#include "field_draw.h"
#include "playercontroller.h"
#include "ai.h"

class GameMode {
 public:
    GameMode(int size_, int mode_) {
        size = size_;
        mode = mode_;
    }
    void game();
    bool scan_win(Field field);
 private:
    int is_horizontal(Field field);
    int is_vertical(Field field);
    int is_diagonal(Field field);
    int size;
    int mode;
};