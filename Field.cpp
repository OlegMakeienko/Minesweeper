//
// Created by OlegMakeienko on 2024-09-22.
//

#include "Field.h"

#include <iostream>
#include <ncurses.h>
#include <vector>

using namespace std;

Field::Field() {
    size = 7;
    initFieldWithMask();
}

void Field::initFieldWithMask() {
    field.clear();
    mask.clear();

    for (int i = 0; i < size; i++) {
        vector <int> temp;
        vector <int> maskTemp;
        for (int j = 0; j < size; j++) {
            if (i == 0 || j == 0 || i == size - 1 || j == size - 1) {
                temp.push_back(BORDER);
                maskTemp.push_back(1); // för att se border
            } else {
                temp.push_back(EMPTY_CELL);
                maskTemp.push_back(0); //field öppnas
            }
        }
        field.push_back(temp);
        mask.push_back(maskTemp);
    }
}

void Field::setRandomMines(int numMines) {
    //while (true)
    if (numMines >= (size - 1)*(size - 1)) {
        cout << "Number of mines is bigger than the size of the field." << endl;
        return;
    }

    for (int i = 0; i < numMines; ++i) {
        int x = 0;
        int y = 0;
        do {
            x = rand() % (size - 2) + 1;
            y = rand() % (size - 2) + 1;
        }
        while (field[x][y] == MINE);

        field[x][y] = MINE;
    }
}

void Field::setDigitsAroundMines() {
    int counter = 0;
    for (int i = 1; i < size - 1; ++i) {
        for (int j = 1; j < size - 1; ++j) {
            if (field[i][j] == MINE) {
                continue;
            }
            if (field[i + 1][j] == MINE) counter++;
            if (field[i - 1][j] == MINE) counter++;
            if (field[i][j - 1] == MINE) counter++;
            if (field[i][j + 1] == MINE) counter++;
            if (field[i + 1][j + 1] == MINE) counter++;
            if (field[i + 1][j - 1] == MINE) counter++;
            if (field[i - 1][j + 1] == MINE) counter++;
            if (field[i - 1][j - 1] == MINE) counter++;
            field[i][j] = counter;
            counter = 0;
        }
    }
}

void Field::showField() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (mask[i][j]) { //öppnade celler
                if (field[i][j] == BORDER) {
                    printw("#");
                } else if (field[i][j] == EMPTY_CELL) {
                    printw(" ");
                } else if (field[i][j] == MINE) {
                    printw("X");
                } else {
                    printw("%d", field[i][j]);
                }
            } else {
                printw("-"); // gömda celler
            }
        }
        printw("\n");
    }
    refresh();
}

bool Field::isBorder(int x, int y) {
    if (x < 0 || x > size || y < 0 || y > size) {
        return false;
    }
    return field[x][y] == BORDER;
}
