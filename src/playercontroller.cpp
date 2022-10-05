#include "playercontroller.h"

void PlayerController::set_turn(Field field, char ch) {
    field.set_field(ch, row_index, column_index);
}

void PlayerController::set_indexes(std::string turn_) {
    const char* tmp = turn_.data();
    row_index = (tmp[0] - 48)*2;
    column_index = (tmp[1] - 96)*2;
}
