//
// Created by jonathangarcia on 30/03/19.
//
#ifndef QUEUE_USING_OOP_STACK_H
#define QUEUE_USING_OOP_STACK_H
#include "PackTile.h"
#include "NodeS.h"
class Stack {
private:
    NodeS*head;
public:
    Stack();
    int counter=0;
    void push(PackTile *l);
    PackTile pop();
    int size();

    bool isEmpty();
    NodeS* getLasNode();
    bool isFull();
  void Swap(PackTile arr[7]);
    void generate();
    void PrintStack();

};
#endif //QUEUE_USING_OOP_STACK_H
