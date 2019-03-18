#ifndef PROJECT_TILE_H
#define PROJECT_TILE_H


class Tile {
private:
    char letter;
    int multiplier;
public:
    Tile();

    char getLetter() const;

    void setLetter(char letter);

    float getMultiplier() const;

    void setMultiplier(int multiplier);
};


#endif //PROJECT_TILE_H