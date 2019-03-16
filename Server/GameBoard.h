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
    void setGameBoardMultipliers(float, float, float);

};


#endif //QUEUE_USING_OOP_BOARD_H
