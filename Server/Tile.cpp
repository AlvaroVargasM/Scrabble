#include "Tile.h"

Tile::Tile() {}

char Tile::getLetter() const {
    return this->letter;
}

void Tile::setLetter(char letter) {
    Tile::letter = letter;
}

int Tile::getMultiplier() const {
    return this->multiplier;
}

void Tile::setMultiplier(int multiplier) {
    Tile::multiplier = multiplier;
}

bool Tile::isWordMultiplier() const {
    return this->wordMultiplier;
}

void Tile::setWordMultiplier(bool wordMultiplier) {
    Tile::wordMultiplier = wordMultiplier;
}

int Tile::getPoints() const {
    return this->points;
}

void Tile::setPoints(int points) {
    Tile::points = points;
}

int Tile::getRow() const {
    return this->row;
}

void Tile::setRow(int row) {
    Tile::row = row;
}

int Tile::getColumn() const {
    return this->column;
}

void Tile::setColumn(int column) {
    Tile::column = column;
}

bool Tile::isBlocked() const {
    return this->blocked;
}

void Tile::setBlocked(bool blocked) {
    Tile::blocked = blocked;
}