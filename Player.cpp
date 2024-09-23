//
// Created by OlegMakeienko on 2024-09-23.
//

#include "Player.h"

#include <ncurses.h>

#include "utils.h"

using namespace std;

Player::Player() {
}

void Player::choice(Field &field) {
    int ch = 0;
    int x = 1, y = 1;
    int prevX = 1, prevY = 1;

    gotoxy(x, y);

    while (true) {
        ch = getch();

        prevX = x, prevY = y;

        switch (ch) {
            case KEY_RIGHT: x++; break;
            case KEY_LEFT: x--; break;
            case KEY_DOWN: y++; break;
            case KEY_UP: y--; break;
        }

        if (field.isBorder(x, y)) {
            x = prevX;
            y = prevY;
        }
        gotoxy(x, y);
    }
}
