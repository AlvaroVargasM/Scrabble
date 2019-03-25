//
// Created by jondorito on 16/03/19.
//

#ifndef UNTITLED1_LINKEDLIST_H
#define UNTITLED1_LINKEDLIST_H

#include "Node.h"
#include <string>

using namespace std;


class LinkedList {
private:
    Node* header;
    int length;
public:
    LinkedList();
    Node* getHead();
    int getLength();
    Node* getIndex(int);
    void insertNode(string);



};


#endif //UNTITLED1_LINKEDLIST_H
