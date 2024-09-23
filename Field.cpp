//
// Created by OlegMakeienko on 2024-09-22.
//

#include "Field.h"

#include <iostream>
#include <vector>

using namespace std;

Field::Field() {
    size = 7;
}

void Field::initField() {
    for (int i = 0; i < size; i++) {
        vector <int> temp;
        for (int j = 0; j < size; j++) {
            if (i == 0 || j == 0 || i == size - 1 || j == size - 1) {
                temp.push_back(BORDER);
            } else {
                temp.push_back(EMPTY_CELL);
            }
        }
        field.push_back(temp);
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

void Field::showField() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (field[i][j] == BORDER) {
                cout << "#";
            } else if (field[i][j] == EMPTY_CELL) {
                 cout << " ";
            } else if (field[i][j] == MINE) {
                cout << "X";
            }



            //cout << field [i][j] << " ";
            // if (i == 0 || j == 0 || i == size - 1 || j == size - 1) {
            //     cout << "x";
            // } else {
            //     cout << " ";
            // }
        }
        cout << endl;
    }
}

