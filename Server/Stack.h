//
// Created by jonathangarcia on 30/03/19.
//

#ifndef QUEUE_USING_OOP_STACK_H
#define QUEUE_USING_OOP_STACK_H

#include "Tile.h"



class Stack {
public:
    Tile *index;
    int top;
    int capacity;


    Stack(int size = 100);		// constructor

    void push(Tile);
    Tile pop();
    Tile peek();

    int size();
    bool isEmpty();
    bool isFull();
    Tile swap();

};


#endif //QUEUE_USING_OOP_STACK_H
