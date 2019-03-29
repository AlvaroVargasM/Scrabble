#ifndef QUEUE_USING_OOP_NODE_H
#define QUEUE_USING_OOP_NODE_H


class Node {
private:
    char l;
    int m;
    Node *next;
    bool wM;
    int pts;
    int i;
    int j;
    bool blocked;

public:
    Node(char, int, int, int, int);

    char getL() const;

    void setL(char l);

    int getM() const;

    void setM(int m);

    Node *getNext() const;

    void setNext(Node *next);

    bool isWM() const;

    void setWM(bool wM);

    int getPts() const;

    void setPts(int pts);

    int getI() const;

    void setI(int i);

    int getJ() const;

    void setJ(int j);

    bool isBlocked() const;

    void setBlocked(bool blocked);
};


#endif //QUEUE_USING_OOP_NODE_H
