#include <unistd.h>

#include "gamemode.h"

void GameMode::game() {
    Field field(size);
    Ai ai_brain;
    Ai ai_brain_2;
    PlayerController player_1;
    PlayerController player_2;
    std::string turn;
    int priority = 0;
    switch (mode) {
        case 0:
            std::cout<<"Who is the first? You(1) or AI(2)?"<<std::endl;
            std::cin>>priority;
            while (true) {
                if (priority == 0 || priority == 1) {
                    field.paint_arr();
                    if (scan_win(field)) break;
                    std::cout<<"Player turn"<<std::endl;
                    std::cin>>turn;
                    player_1.set_indexes(turn);
                    player_1.set_turn(field, 'X');
                    priority = 0;
                }
                
                if (priority == 0 || priority == 2) {
                    field.paint_arr();
                    if (scan_win(field)) break;
                    ai_brain.set_indexes(player_1.get_row(), player_1.get_column());
                    std::cout<<"Computer turn"<<std::endl;
                    sleep(1);
                    ai_brain.find_place(field);
                    turn = ai_brain.get_turn_index(field);
                    player_2.set_indexes(turn);
                    player_2.set_turn(field, 'O');
                    priority = 0;
                }
            }
            break;
        case 1:
            while (true) {
                field.paint_arr();
                if (scan_win(field)) break;
                std::cout<<"Player A turn"<<std::endl;
                std::cin>>turn;
                player_1.set_indexes(turn);
                player_1.set_turn(field, 'X');
                field.paint_arr();
                if (scan_win(field)) break;
                std::cout<<"PLayer B turn"<<std::endl;
                std::cin>>turn;
                player_2.set_indexes(turn);
                player_2.set_turn(field, 'O');
            }
            break;
        case 2:            
            while (true) {
                field.paint_arr();
                if (scan_win(field)) break;
                ai_brain.set_indexes(player_2.get_row(), player_2.get_column());
                std::cout<<"Computer #1 turn"<<std::endl;
                sleep(1);
                ai_brain.find_place(field);
                turn = ai_brain.get_turn_index(field);
                player_1.set_indexes(turn);
                player_1.set_turn(field, 'X');
                field.paint_arr();
                if (scan_win(field)) break;
                ai_brain_2.set_indexes(player_1.get_row(), player_1.get_column());
                std::cout<<"Computer #2 turn"<<std::endl;
                sleep(1);
                ai_brain_2.find_place(field);
                turn = ai_brain_2.get_turn_index(field);
                player_2.set_indexes(turn);
                player_2.set_turn(field, 'O');
            }
            break;
        default:
            break;
    }
}

bool GameMode::scan_win(Field field) {
    char** tmp = field.field_arr();
    int space_count = 0;
    for (int i = 2; i < field.get_size(); ++i) {
        for (int j = 2; j < field.get_size(); ++j) {
            if (tmp[i][j] == ' ') space_count++;
        }
    }
    int winner = is_horizontal(field);
    if (winner == 1) {
        std::cout<<"Player A win!"<<std::endl;
        return true;
    } else if (winner == 2) {
        std::cout<<"Player B win!"<<std::endl;
        return true;
    }

    winner = is_vertical(field);
    if (winner == 1) {
        std::cout<<"Player A win!"<<std::endl;
        return true;
    } else if (winner == 2) {
        std::cout<<"Player B win!"<<std::endl;
        return true;
    }

    winner = is_diagonal(field);
    if (winner == 1) {
        std::cout<<"Player A win!"<<std::endl;
        return true;
    } else if (winner == 2) {
        std::cout<<"Player B win!"<<std::endl;
        return true;
    }

    if (space_count == 0) {
        std::cout<<"Nobody win!!";
        return true;
    }
    return false;
}

int GameMode::is_horizontal(Field field) {
    char** tmp = field.field_arr();
    for (int i = 2, count_x = 0, count_o = 0; i < field.get_size(); ++i) {
        for (int j = 2; j < field.get_size(); ++j) {
            if ('X' == tmp[i][j]) {
                count_x++;
                if (count_x == field.get_size() / 2 - 1) return 1;
            } else if ('O' == tmp[i][j]) {
                count_o++;
                if (count_o == field.get_size() / 2 - 1) return 2;
            } else if (' ' == tmp[i][j]) {
                // return 0;
            }

        }
        count_o = 0;
        count_x = 0;
    }
    return 0;
}

int GameMode::is_vertical(Field field) {
    char** tmp = field.field_arr();
    for (int i = 2, count_x = 0, count_o = 0; i < field.get_size(); ++i) {
        for (int j = 2; j < field.get_size(); ++j) {
            if ('X' == tmp[j][i]) {
                count_x++;
                if (count_x == field.get_size() / 2 - 1) return 1;
            } else if ('O' == tmp[j][i]) {
                count_o++;
                if (count_o == field.get_size() / 2 - 1) return 2;
            } else if (' ' == tmp[j][i]) {
                // return 0;
            }

        }
        count_o = 0;
        count_x = 0;
    }
    return 0;
}

int GameMode::is_diagonal(Field field) {
    char** tmp = field.field_arr();
    int count_x = 0, count_o = 0;
    for (int i = 2; i < field.get_size(); ++i) {
        if ('X' == tmp[i][i]) {
            count_x++;
            if (count_x == field.get_size() / 2 - 1) return 1;
        } else if ('O' == tmp[i][i]) {
            count_o++;
            if (count_o == field.get_size() / 2 - 1) return 2;
        }
    }
    count_x = 0;
    count_o = 0;
    for (int i = 0, j = field.get_size()-1; i < field.get_size(); ++i, --j) {
        char x = tmp[i][j];
        if ('X' == tmp[i][j]) {
            count_x++;
            if (count_x == field.get_size() / 2 - 1) return 1;
        } else if ('O' == tmp[i][j]) {
            count_o++;
            if (count_o == field.get_size() / 2 - 1) return 2;
        }
    }

    return 0;
}
