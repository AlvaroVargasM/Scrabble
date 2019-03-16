//
// Created by alvar on 16/03/19.
//

#include "GameBoard.h"
#include <iostream>

GameBoard::GameBoard() {}


void GameBoard::getGameBoardLetters() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++)
            std::cout << board[i][j].getLetter() << " ";
        std::cout << std::endl;
    }
}

void GameBoard::setGameBoardLetters(char l) {
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            board[i][j].setLetter(l);
}

void GameBoard::getGameBoardMultipliers() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++)
            std::cout << board[i][j].getMultiplier() << " ";
        std::cout << std::endl;
    }
}

void GameBoard::setGameBoardMultipliers(float m1, float m2, float m3) {
    for (int row = 0; row < 15; row++)
        for (int column = 0; column < 15; column++) {
            if (row == 0 && column == 7) {
                board[row][column].setMultiplier(m1);
                continue;
            }
            if (row == 7 && column == 7) {
                board[row][column].setMultiplier(m2);
                continue;
            }
            if (row == 14 && column == 7) {
                board[row][column].setMultiplier(m3);
                continue;
            }
            else
                board[row][column].setMultiplier(0);
        }
}

void GameBoard::changeTile(int i, int j, char l) {
    board[i][j].setLetter(l);
}

void GameBoard::checkTile(int i, int j) {
    std::cout << board[i][j].getLetter() << std::endl;
}
