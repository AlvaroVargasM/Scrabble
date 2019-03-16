#include <iostream>
#include "Tile.h"

int main(){
    Tile board[15][15];

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            board[i][j].setLetter('a');

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++)
            std::cout << board[i][j].getLetter() << " ";
        std::cout << std::endl;
    }

    std::cout << "\n";

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
                board[i][j].setMultiplier(0);


    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++)
            std::cout << board[i][j].getMultiplier() << " ";
        std::cout << std::endl;
    }

    return 0;
}