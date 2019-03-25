//
// Created by jondorito on 25/03/19.
//

#ifndef QUEUE_USING_OOP_LINKEDLIST_H
#define QUEUE_USING_OOP_LINKEDLIST_H


#include "NodeWord.h"
#include <string>

using namespace std;


class LinkedList {
private:
    NodeWord* header;
    int length;
public:
    LinkedList();
    NodeWord* getHead();
    int getLength();
    NodeWord* getIndex(int);
    void insertNode(string);



};


#endif //QUEUE_USING_OOP_LINKEDLIST_H
