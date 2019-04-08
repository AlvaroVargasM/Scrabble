#ifndef QUEUE_USING_OOP_STACK_H
#define QUEUE_USING_OOP_STACK_H

#include "../Networking/PackTile.h"
#include "NodeS.h"

/**
 *The Pila class, has the function of generating chips with the combinations that the
 *  client has requested, to be doing an exchange of values ​​every time there are chips
 *  that do not work the player.
 */
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

    PackTile* swap(PackTile *arr);

    void generate();

    void printStack();
};

#endif //QUEUE_USING_OOP_STACK_H
