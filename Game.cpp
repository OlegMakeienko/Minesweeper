//
// Created by OlegMakeienko on 2024-09-22.
//

#include "Game.h"

#include "Field.h"
using namespace std;

#include <iostream>
#include <unistd.h>
#include <ncurses.h>

void gotoxy(int x, int y) {
    move(y, x);
}

void Game::showLogo() {
    initscr();
    gotoxy(40, 5);
    printw("Minesweeper (by Oleg Makeienko)");
    refresh();
    napms(2000);
    clear();
    refresh();
    endwin();
}

void Game::run() {
    //showLogo();
    Field field;
    field.initField();
    field.setRandomMines(1);
    field.setDigitsAroundMines();
    field.showField();
}
