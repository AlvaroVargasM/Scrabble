#ifndef QUEUE_USING_OOP_PACKTILE_H
#define QUEUE_USING_OOP_PACKTILE_H

class PackTile {
private:
    char letter;
    int row;
    int column;
    int value;
public:
    PackTile();

    PackTile(char letter,int row,int column,int points);
    PackTile(char letter,int points);

    char getLetter() const;

    int getRow() const;

    int getColumn() const;

    void setCoordinates(int row,int column);

    int getValue() const;
};

#endif //QUEUE_USING_OOP_PACKTILE_H