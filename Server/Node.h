#ifndef QUEUE_USING_OOP_NODE_H
#define QUEUE_USING_OOP_NODE_H


class Node {
private:
    char l;
    int m;
    Node *next;
public:
    Node(char, int);

    char getL() const;

    void setL(char l);

    int getM() const;

    void setM(int m);

    Node *getNext() const;

    void setNext(Node *next);
};


#endif //QUEUE_USING_OOP_NODE_H
