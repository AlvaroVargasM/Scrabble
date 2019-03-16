#ifndef PROJECT_TILE_H
#define PROJECT_TILE_H


class Tile {
private:
    char letter;
    float multiplier;
public:
    Tile();

    char getLetter() const;

    void setLetter(char letter);

    float getMultiplier() const;

    void setMultiplier(float multiplier);
};


#endif //PROJECT_TILE_H