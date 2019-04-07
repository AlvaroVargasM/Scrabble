#include "PackTile.h"

PackTile::PackTile() {
    this->row = -1;
    this->column = -1;
    this->letter = '.';
    this->value = -1;

}

PackTile::PackTile(int i,int j,char l,int v) {
    this->row = i;
    this->column = j;
    this->letter = l;
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

int PackTile::getValue() const {
    return this->value;
}
