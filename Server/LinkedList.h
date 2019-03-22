#ifndef QUEUE_USING_OOP_LINKEDLIST_H
#define QUEUE_USING_OOP_LINKEDLIST_H


#include "Node.h"
#include "Tile.h"

class LinkedList {
private:
    Node *head;
public:
    LinkedList();
    void addLast(Tile);
    void printList();
};


#endif //QUEUE_USING_OOP_LINKEDLIST_H
