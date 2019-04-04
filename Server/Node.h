#ifndef QUEUE_USING_OOP_NODE_H
#define QUEUE_USING_OOP_NODE_H

/**
 * Node class for beaing used in the link list, it stores data similar to a Tile
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

    void setL(char l);


    Node *getNext() const;

    void setNext(Node *next);

    int getPts() const;

    void setPts(int pts);

    int getI() const;

    void setI(int i);

    int getJ() const;

    void setJ(int j);
};


#endif //QUEUE_USING_OOP_NODE_H
