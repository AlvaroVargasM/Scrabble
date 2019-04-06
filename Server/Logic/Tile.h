#ifndef PROJECT_TILE_H
#define PROJECT_TILE_H

/**
 * Class Tile works as the base for the 'GameBoard', it stores all the data that a tile will need,
 * its methods are only setters and getters.
 */
class Tile {
private:
    char letter;
    int multiplier;
    bool wordMultiplier;
    int points;
    int row;
    int column;

public:
    Tile();

    char getLetter() const;

    void setLetter(char letter);

    int getMultiplier() const;

    void setMultiplier(int multiplier);

    bool isWordMultiplier() const;

    void setWordMultiplier(bool wordMultiplier);

    int getPoints() const;

    void setPoints(int points);

    int getRow() const;

    void setRow(int row);

    int getColumn() const;

    void setColumn(int column);
};

#endif //PROJECT_TILE_H