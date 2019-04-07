#ifndef QUEUE_USING_OOP_PACKTILE_H
#define QUEUE_USING_OOP_PACKTILE_H

/**
 * Pack tile is simpler way to represent a tile  used for communication, it is send between server and client
 */
class PackTile {
private:
    char letter;
    int row;
    int column;
    int value;

public:
    PackTile();

    PackTile(int row,int column,char letter,int points);

    PackTile(char letter,int points);

    char getLetter() const;

    int getRow() const;

    int getColumn() const;

    int getValue() const;
};

#endif //QUEUE_USING_OOP_PACKTILE_H