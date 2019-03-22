#ifndef QUEUE_USING_OOP_BOARD_H
#define QUEUE_USING_OOP_BOARD_H

#include "Tile.h"

class GameBoard {
private:
    Tile board[15][15];
public:
    GameBoard();
    void getGameBoardLetters();
    void setGameBoardLetters(char);
    void getGameBoardMultipliers();
    void setGameBoardMultipliers(int, int, int, int);
    void changeTile(int, int, char);
    void checkTile(int, int);
    Tile getTile(int,int);
};


#endif //QUEUE_USING_OOP_BOARD_H
