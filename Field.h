//
// Created by OlegMakeienko on 2024-09-22.
//

#ifndef FIELD_H
#define FIELD_H
#include <vector>

using namespace std;


class Field {
private:
    const int BORDER = 100;
    const int MINE = 10;
    const int EMPTY_CELL = 0;
    int size;
    vector <vector <int>> field;
public:
    Field();
    void initField();
    void setRandomMines(int numMines);
    void setDigitsAroundMines();
    void showField();
};



#endif //FIELD_H
