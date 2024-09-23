//
// Created by OlegMakeienko on 2024-09-23.
//

#include "utils.h"
#include <ncurses.h>

void gotoxy(int x, int y) {
    move(y, x);
}
