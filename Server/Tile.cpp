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