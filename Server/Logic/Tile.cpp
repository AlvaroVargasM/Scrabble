#include "Tile.h"
/**
 * Tile's empty constructor.
 */
Tile::Tile() {}

/**
 * Gets the letter of a Tile.
 * @return the Tile's letter
 */
char Tile::getLetter() const {
    return this->letter;
}

/**
 * Sets the letter of a Tile.
 * @param letter to set
 */
void Tile::setLetter(char letter) {
    Tile::letter = letter;
}

/**
 * Gets the multiplier of a Tile.
 * @return the Tile's multiplier
 */
int Tile::getMultiplier() const {
    return this->multiplier;
}

/**
 * Sets the multiplier of a Tile.
 * @param multiplier to set
 */
void Tile::setMultiplier(int multiplier) {
    Tile::multiplier = multiplier;
}

/**
 * Checks for the state of the boolean wordMultiplier in a Tile.
 * @return the state of wordMultiplier
 */
bool Tile::isWordMultiplier() const {
    return this->wordMultiplier;
}

/**
 * Sets the state of the boolean wordMultiplier in a Tile.
 * @param the new state of wordMultiplier
 */
void Tile::setWordMultiplier(bool wordMultiplier) {
    Tile::wordMultiplier = wordMultiplier;
}

/**
 * Gets the points of a Tile.
 * @return the Tile's points
 */
int Tile::getPoints() const {
    return this->points;
}

/**
 * Sets the points of a Tile.
 * @param points to set
 */
void Tile::setPoints(int points) {
    Tile::points = points;
}

/**
 * Gets the row of a Tile.
 * @return the Tile's row
 */
int Tile::getRow() const {
    return this->row;
}

/**
 * Sets the row of a Tile.
 * @param row to set
 */
void Tile::setRow(int row) {
    Tile::row = row;
}

/**
 * Gets the column of a Tile.
 * @return the Tile's column
 */
int Tile::getColumn() const {
    return this->column;
}

/**
 * Sets the column of a Tile.
 * @param column to set
 */
void Tile::setColumn(int column) {
    Tile::column = column;
}