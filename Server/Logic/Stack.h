#ifndef QUEUE_USING_OOP_STACK_H
#define QUEUE_USING_OOP_STACK_H

#include "../Networking/PackTile.h"
#include "NodeS.h"

class Stack {
private:
    NodeS *head;

public:
    Stack();

    int counter = 0;

    void push(PackTile *l);

    PackTile pop();

    int size();

    bool isEmpty();

    NodeS* getLasNode();

    bool isFull();

    void swap(PackTile *arr);

    void generate();

    void printStack();
};

#endif //QUEUE_USING_OOP_STACK_H
