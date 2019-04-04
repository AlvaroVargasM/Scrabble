//
// Created by jonathangarcia on 30/03/19.
//

#ifndef QUEUE_USING_OOP_STACK_H
#define QUEUE_USING_OOP_STACK_H

#include "PackTile.h"
#include "NodeS.h"


class Stack {
private:
   // NodeS*top= nullptr;
public:
    Stack();
    NodeS*top= nullptr;


   // int top;
    int capacity;
    int counter=0;
    void push(PackTile *l);
    PackTile pop();
    int size();
    bool isEmpty();
    bool isFull();
    PackTile swap();
    void generate();
};


#endif //QUEUE_USING_OOP_STACK_H
