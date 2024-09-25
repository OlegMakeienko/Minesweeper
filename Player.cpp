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
    int prevX, prevY;

    int maxX = field.getWidth();
    int maxY = field.getHeight();

    gotoxy(x, y);

    while (true) {
        ch = getch();

        prevX = x, prevY = y;  // Spara föregående position

        switch (ch) {
            case KEY_RIGHT:
                if (x < maxX - 1) x++;
            break;
            case KEY_LEFT:
                if (x > 1) x--;
            break;
            case KEY_DOWN:
                if (y < maxY - 1) y++;
            break;
            case KEY_UP:
                if (y > 1) y--;
            break;
            case 10: //Enter
                field.reveal(x, y);
            break;
        }

        if (field.isBorder(x, y)) {
            x = prevX;
            y = prevY;
        }

        clear();
        field.showField();
        gotoxy(x, y);
    }
}

