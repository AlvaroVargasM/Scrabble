#ifndef QUEUE_USING_OOP_BOARD_H
#define QUEUE_USING_OOP_BOARD_H

#include "Tile.h"
#include "Organizer.h"
#include "Player.h"
#include "LinkedList.h"

/**
 * Works as the base for the game, is the backbone of all game play and main logic, its matrix of 'Tile' objects,
 * it is also used as reference for many other classes and methods.
 */
class GameBoard {
private:
    Tile board[15][15];
    Player* current;

public:
    GameBoard();
    void printLetters();

    void setLetters(char letter);

    void setMultipliers(int multiplier1,int multiplier2,int multiplier3,int multiplier4);

    void printCoordinates();

    void changeTile(int row,int column,char letter,int points);

    Tile getTile(int row,int column);

    void setVerifiedWord(LinkedList word);

    Organizer* org;

    Organizer* getOrganizer();

    void setOrganizer(Organizer*);
};

#endif //QUEUE_USING_OOP_BOARD_H