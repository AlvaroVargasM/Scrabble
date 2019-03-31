#include "GameBoard.h"
#include <iostream>

GameBoard::GameBoard() {
    this->setMultipliers(2,3,4,5);
    this->setLetters('.');
    this->setCoordinates();
}

void GameBoard::getLetters() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++)
            std::cout << this->board[i][j].getLetter() << " ";
        std::cout << std::endl;
    }
}

void GameBoard::setLetters(char l) {
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            this->board[i][j].setLetter(l);
}

void GameBoard::getMultipliers() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++)
            std::cout << this->board[i][j].getMultiplier() << " ";
        std::cout << std::endl;
    }
}

void GameBoard::setMultipliers(int m1, int m2, int m3, int m4) {
    for (int row = 0; row < 15; row++)
        for (int column = 0; column < 15; column++) {
            if ((row == 3 && (column == 6 || column == 8)) ||
                (row == 4 && (column == 5 || column == 9)) ||
                (row == 5 && (column == 4 || column == 10)) ||
                (row == 6 && (column == 3 || column == 11)) ||
                (row == 8 && (column == 3 || column == 11)) ||
                (row == 9 && (column == 4 || column == 10)) ||
                (row == 10 && (column == 5 || column == 9)) ||
                (row == 11 && (column == 6 || column == 8))){
                this->board[row][column].setMultiplier(m1);
                continue;

            }
            if              (((row == 2 || row == 12) && (column == 4 || column == 7 || column == 10))
              || ((row == 4 || row == 7 || row == 10) && (column == 2 || column == 12))) {
                this->board[row][column].setMultiplier(m2);
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
            else
                board[row][column].setMultiplier(1);
        }
}

void GameBoard::setCoordinates() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            this->board[i][j].setRow(i);
            this->board[i][j].setColumn(j);
        }
    }
}

void GameBoard::getCoordinates() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++)
            std::cout << "[" << this->board[i][j].getRow() << "] " << "[" << this->board[i][j].getColumn()<< "] ;";
        std::cout << std::endl;
    }
}


void GameBoard::changeTile(int i, int j, char l, int pts) {
    this->board[i][j].setLetter(l);
    this->board[i][j].setPoints(pts);
}

void GameBoard::checkTile(int i, int j) {
    std::cout << this->board[i][j].getLetter() << std::endl;
}

Tile GameBoard::getTile(int i, int j) {
    return this->board[i][j];
}

Organizer* GameBoard::getOrganizer(){
    return this->org;
}
void GameBoard::setOrganizer(Organizer * org) {
    this->org = org;
}