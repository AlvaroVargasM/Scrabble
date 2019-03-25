//
// Created by alvar on 16/03/19.
//

#include "GameBoard.h"
#include <iostream>

GameBoard::GameBoard() {}


void GameBoard::getLetters() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++)
            std::cout << board[i][j].getLetter() << " ";
        std::cout << std::endl;
    }
}

void GameBoard::setLetters(char l) {
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            board[i][j].setLetter(l);
}

void GameBoard::getMultipliers() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++)
            std::cout << board[i][j].getMultiplier() << " ";
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
                    board[row][column].setMultiplier(m1);
                    continue;
            }
            if (((row == 2 || row == 12) && (column == 4 || column == 7 || column == 10)) || ((row == 4 || row == 7 || row == 10) && (column == 2 || column == 12))) {
                board[row][column].setMultiplier(m2);
                continue;
            }
            if ((row == 2 || row == 12) && (column == 2 || column == 12)) {
                board[row][column].setMultiplier(m3);
                board[row][column].setWordMultiplier(true);
                continue;
            }
            if ((row == 1 || row == 13) && (column == 1 || column == 13)) {
                board[row][column].setMultiplier(m4);
                board[row][column].setWordMultiplier(true);
                continue;
            }
            else
                board[row][column].setMultiplier(1);
        }
}

void GameBoard::changeTile(int i, int j, char l) {
    board[i][j].setLetter(l);
}

void GameBoard::checkTile(int i, int j) {
    std::cout << board[i][j].getLetter() << std::endl;
}

Tile GameBoard::getTile(int i, int j) {
    return board[i][j];
}
