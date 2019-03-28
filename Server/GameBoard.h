#ifndef QUEUE_USING_OOP_BOARD_H
#define QUEUE_USING_OOP_BOARD_H

#include "Tile.h"

class GameBoard {
private:
    Tile board[15][15];
public:
    GameBoard();
    void getLetters();
    void setLetters(char);
    void getMultipliers();
    void setMultipliers(int,int,int,int);
    void setCoordinates();
    void getCoordinates();
    void changeTile(int,int,char,int);
    void checkTile(int,int);
    Tile getTile(int,int);
};

#endif //QUEUE_USING_OOP_BOARD_H