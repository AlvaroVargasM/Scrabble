//
// Created by alvar on 30/03/19.
//

#include "PackTile.h"

PackTile::PackTile(char l, int i, int j, int v) {
    this->letter = l;
    this->row = i;
    this->column = j;
    this->value = v;
}

PackTile::PackTile(char l, int v) {
    this->letter = l;
    this->value = v;
}

char PackTile::getLetter() const {
    return this->letter;
}


int PackTile::getRow() const {
    return this->row;
}


int PackTile::getColumn() const {
    return this->column;
}

void PackTile::setCoordinates(int i, int j) {
    this->row = i;
    this->column = j;
}

int PackTile::getValue() const {
    return this->value;
}
