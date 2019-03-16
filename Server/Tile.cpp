#include "Tile.h"

Tile::Tile() {}

char Tile::getLetter() const {
    return letter;
}

void Tile::setLetter(char letter) {
    Tile::letter = letter;
}

float Tile::getMultiplier() const {
    return multiplier;
}

void Tile::setMultiplier(float multiplier) {
    Tile::multiplier = multiplier;
}