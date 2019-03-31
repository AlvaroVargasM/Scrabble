#ifndef QUEUE_USING_OOP_BOARD_H
#define QUEUE_USING_OOP_BOARD_H

#include "Tile.h"
#include "Organizer.h"
#include "Player.h"

class GameBoard {
private:
    Tile board[15][15];
    Player* current;
public:
    GameBoard();
    void getLetters();
    void setLetters(char letter);
    void getMultipliers();
    void setMultipliers(int multiplier1,int multiplier2,int multiplier3,int multiplier4);
    void setCoordinates();
    void getCoordinates();
    void changeTile(int row,int column,char letter,int points);
    void checkTile(int row,int column);
    Tile getTile(int row,int column);
    Organizer* org;
    Organizer* getOrganizer();
    void setOrganizer(Organizer*);


};

#endif //QUEUE_USING_OOP_BOARD_H