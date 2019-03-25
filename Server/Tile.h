#ifndef PROJECT_TILE_H
#define PROJECT_TILE_H


class Tile {
private:
    char letter;
    int multiplier;
    bool wordMultiplier;
    int points;


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
};


#endif //PROJECT_TILE_H