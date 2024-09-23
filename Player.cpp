//
// Created by OlegMakeienko on 2024-09-23.
//

#include "Player.h"

#include <ncurses.h>

#include "utils.h"

using namespace std;

Player::Player() {
}

void Player::choice() {
    int ch = 0;
    int x = 1;
    int y = 1;

    gotoxy(x, y);

    while (true) {
        ch = getch();

        switch (ch) {
            case KEY_RIGHT: x++; break;
            case KEY_LEFT: x--; break;
            case KEY_DOWN: y++; break;
            case KEY_UP: y--; break;
        }
        gotoxy(x, y);
    }
}
