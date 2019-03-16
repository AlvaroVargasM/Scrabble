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