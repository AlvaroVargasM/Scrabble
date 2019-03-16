#include <iostream>
#include "Tile.h"
#include "GameBoard.h"

int main(){

    GameBoard gb;

    gb.setGameBoardLetters('.');
    gb.getGameBoardLetters();

    std::cout << "\n";

    gb.setGameBoardMultipliers(3.5,2.5,1.5);
    gb.getGameBoardMultipliers();

    gb.changeTile(7,7,'B');
    gb.changeTile(7,8,'C');
    gb.changeTile(7,9,'R');

    std::cout << "\n";

    gb.checkTile(7,7);
    gb.checkTile(7,8);
    gb.checkTile(7,9);

    std::cout << "\n";

    gb.getGameBoardLetters();

    return 0;
}