#include <iostream>
#include "Tile.h"
#include "GameBoard.h"

int main(){

    GameBoard gb;

    gb.setGameBoardLetters('H');
    gb.getGameBoardLetters();

    std::cout << "\n";

    gb.setGameBoardMultipliers(3.5,2.5,1.5);
    gb.getGameBoardMultipliers();

    return 0;
}