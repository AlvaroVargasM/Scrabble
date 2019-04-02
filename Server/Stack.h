//
// Created by jonathangarcia on 30/03/19.
//

#ifndef QUEUE_USING_OOP_STACK_H
#define QUEUE_USING_OOP_STACK_H

#include "PackTile.h"
#include "NodeS.h"


class Stack {
private:
    NodeS*top;
public:

    PackTile  index;
   // int top;
    int capacity;
    int counter=0;

		// constructor



    void push(PackTile l);
    PackTile pop();
    PackTile peek();

    int size();
    bool isEmpty();
    bool isFull();
    PackTile swap();

};


#endif //QUEUE_USING_OOP_STACK_H
