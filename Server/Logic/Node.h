#ifndef QUEUE_USING_OOP_NODE_H
#define QUEUE_USING_OOP_NODE_H

/**
 * Node class for beaing used in the link list, it stores data similar to a Tile.
 */
class Node {
private:
    char l;
    Node *next;
    int pts;
    int i;
    int j;

public:
    Node(char letter,int row,int columns,int points);

    char getL() const;

    Node *getNext() const;

    void setNext(Node *next);

    int getPts() const;

    int getI() const;

    int getJ() const;
};

#endif //QUEUE_USING_OOP_NODE_H
