#include "Tile.h"

Tile::Tile() {}

char Tile::getLetter() const {
    return letter;
}

void Tile::setLetter(char letter) {
    Tile::letter = letter;
}

int Tile::getMultiplier() const {
    return multiplier;
}

void Tile::setMultiplier(int multiplier) {
    Tile::multiplier = multiplier;
}

bool Tile::isWordMultiplier() const {
    return wordMultiplier;
}

void Tile::setWordMultiplier(bool wordMultiplier) {
    Tile::wordMultiplier = wordMultiplier;
}

int Tile::getPoints() const {
    return points;
}

void Tile::setPoints(int points) {
    Tile::points = points;
}

int Tile::getRow() const {
    return row;
}

void Tile::setRow(int row) {
    Tile::row = row;
}

int Tile::getColumn() const {
    return column;
}

void Tile::setColumn(int column) {
    Tile::column = column;
}
