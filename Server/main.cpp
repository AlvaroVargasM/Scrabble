#include <iostream>
#include "Tile.h"
#include "GameBoard.h"

int main(){

    GameBoard gb;

    gb.setGameBoardLetters('.');

    std::cout << "\n";

    gb.setGameBoardMultipliers(2,3,4,5);
    gb.getGameBoardMultipliers();

    gb.changeTile(7,7,'B');
    gb.changeTile(7,8,'O');
    gb.changeTile(7,9,'C');
    gb.changeTile(7,10,'A');

    gb.changeTile(8,7,'A');
    gb.changeTile(9,7,'N');
    gb.changeTile(10,7,'C');
    gb.changeTile(11,7,'O');

    std::cout << "\n";

    gb.getGameBoardLetters();

    std::cout << "\n";

    int test[10][10];
    std::cout << &test[0][0] << std::endl;

    return 0;
}