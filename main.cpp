#include <iostream>
#include <ctime>
#include <ncurses.h>

#include "Game.h"

using namespace std;

int main() {
    //srand(time(0));
    Game game;
    game.run();
}
