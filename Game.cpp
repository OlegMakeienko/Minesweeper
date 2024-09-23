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
    gotoxy(40, 5);
    printw("Minesweeper (by Oleg Makeienko)");
    refresh();
    napms(2000);
    clear();
    refresh();
    endwin();
}

void Game::run() {
    system("clear"); // Rensa terminalen innan du använder ncurses
    initscr();
    refresh();
    keypad(stdscr, TRUE); // Enable keypad input
    noecho(); // Disable echoing of characters

    Field field;
    Player player;
    field.initField();
    field.setRandomMines(1);
    field.setDigitsAroundMines();
    field.showField();
    player.choice(field);

    getch(); // Vänta på användarens input
    //endwin(); // Avsluta ncurses-läget
}


