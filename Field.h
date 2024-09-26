//
// Created by OlegMakeienko on 2024-09-22.
//

#ifndef FIELD_H
#define FIELD_H
#include <vector>

using namespace std;

#include "Constanter.h"

class Field {
private:
    // const int BORDER = 100;
    // const int MINE = 10;
    // const int EMPTY_CELL = 0;
    int size;
    vector <vector <int>> field;
    vector <vector <int>> mask;
public:
    Field();
    void initFieldWithMask();
    void setRandomMines(int numMines);
    void setDigitsAroundMines();
    void showField();
    bool isBorder(int x, int y);
    int reveal(int x, int y);
    void openNearlyCells(int x, int y);
    void revealRecursive(int x, int y);

    int getWidth() { return size; }
    int getHeight() { return size; }
};



#endif //FIELD_H
