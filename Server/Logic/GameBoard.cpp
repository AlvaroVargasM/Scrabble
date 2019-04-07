#include "GameBoard.h"
#include <iostream>

/**
 * 'Game board' constructor, when creating a 'Game Board' instance we set all of the tile's multipliers,
 * chars and coordinates to a default state.
 */
GameBoard::GameBoard() {
    this->setMultipliers(2,3,4,5);
    this->setLetters('.');
    this->printCoordinates();
}

/**
 * Prints the matrix's letters.
 */
void GameBoard::printLetters() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++)
            std::cout << this->board[i][j].getLetter() << " ";
        std::cout << std::endl;
    }
}

/**
 * Sets all letters on the matrix to the char we pass.
 * @param l char that will be set on every 'Tile'
 */
void GameBoard::setLetters(char l) {
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            this->board[i][j].setLetter(l);
}

/**
 * Sets the multipliers in the matrix forming a pre-established geometrical figure.
 * @param m1 first multiplier, the most common one
 * @param m2 second multiplier, fairly common
 * @param m3 third multiplier, it is a word multiplier hard to reach from the center of the matrix
 * @param m4 fourth multiplier, word multiplier, hardest to reach
 */
void GameBoard::setMultipliers(int m1, int m2, int m3, int m4) {
    for (int row = 0; row < 15; row++) {
        for (int column = 0; column < 15; column++) {
            if ((row == 3  && (column == 6 || column == 8 )) ||
                (row == 4  && (column == 5 || column == 9 )) ||
                (row == 5  && (column == 4 || column == 10)) ||
                (row == 6  && (column == 3 || column == 11)) ||
                (row == 8  && (column == 3 || column == 11)) ||
                (row == 9  && (column == 4 || column == 10)) ||
                (row == 10 && (column == 5 || column == 9 )) ||
                (row == 11 && (column == 6 || column == 8 ))) {
                this->board[row][column].setMultiplier(m1);
                this->board[row][column].setWordMultiplier(false);
                continue;
            }
            if                (((row == 2 || row == 12) && (column == 4 || column == 7 || column == 10))
                || ((row == 4 || row == 7 || row == 10) && (column == 2 || column == 12))) {
                this->board[row][column].setMultiplier(m2);
                this->board[row][column].setWordMultiplier(false);
                continue;
            }
            if ((row == 2 || row == 12) && (column == 2 || column == 12)) {
                this->board[row][column].setMultiplier(m3);
                this->board[row][column].setWordMultiplier(true);
                continue;
            }
            if ((row == 1 || row == 13) && (column == 1 || column == 13)) {
                this->board[row][column].setMultiplier(m4);
                this->board[row][column].setWordMultiplier(true);
                continue;
            }
            else {
                board[row][column].setMultiplier(1);
                this->board[row][column].setWordMultiplier(false);
            }
        }
    }
}

/**
 * Prints the positions of the matrix's tiles.
 */
void GameBoard::printCoordinates() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            this->board[i][j].setRow(i);
            this->board[i][j].setColumn(j);
        }
    }
}

/**
 * Modified a single 'Tile' based on the position in the matrix we indicate.
 * @param i row
 * @param j column
 * @param l letter to change
 * @param pts points to change
 */
void GameBoard::changeTile(int i, int j, char l, int pts) {
    this->board[i][j].setLetter(l);
    this->board[i][j].setPoints(pts);
}

/**
 * We receive a Tile form Game Board using it's coordinates.
 * @param i row
 * @param j column
 * @return Tile object
 */
Tile GameBoard::getTile(int i, int j) {
    return this->board[i][j];
}

/**
 * We modified the Game Board based with a  linked list.
 * @param word the word we want to set in the matrix
 */
void GameBoard::setVerifiedWord(LinkedList word) {
    Node * searcher = word.getHead();
    while (searcher != nullptr) {
        this->changeTile(searcher->getI(),searcher->getJ(),searcher->getL(),searcher->getPts());
        searcher = searcher->getNext();
    }
}

/**
 * Returns the GameBoard pointer to the Organizer.
 * @return The Organizer pointer
 */
Organizer* GameBoard::getOrganizer(){
    return this->org;
}

/**
 * Sets the organizer of GameBoard to the one we pass.
 * @param org to set
 */
void GameBoard::setOrganizer(Organizer * org) {
    this->org = org;
}