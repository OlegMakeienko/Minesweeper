//
// Created by OlegMakeienko on 2024-09-22.
//

#include "Game.h"

#include "Field.h"
#include "Player.h"
#include "utils.h"
using namespace std;

#include <iostream>
#include <unistd.h>
#include <ncurses.h>

void Game::showLogo() {

    initscr();
    //gotoxy(40, 5);
    mvprintw(10, 45, "Minesweeper (by Oleg Makeienko)");
    refresh();
    napms(2000);
    clear();
    refresh();
    endwin();
}

void Game::run() {
    showLogo();
    clear();
    initscr();
    refresh();
    keypad(stdscr, TRUE);
    noecho();

    Field field;
    Player player;
    field.initFieldWithMask();
    field.setRandomMines(19);
    field.setDigitsAroundMines();
    field.showField();
    player.choice(field);

    getch(); // Vänta på användarens input
    endwin();
}


