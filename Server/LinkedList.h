#ifndef QUEUE_USING_OOP_LINKEDLIST_H
#define QUEUE_USING_OOP_LINKEDLIST_H

#include <string>

#include "Node.h"
#include "Tile.h"

class LinkedList {
private:
    Node *head;
public:
    LinkedList();
    ~LinkedList();
    void addLast(Tile);
    void addFront(Tile);
    void printList();
    std::string getWord(LinkedList);
};


#endif //QUEUE_USING_OOP_LINKEDLIST_H
