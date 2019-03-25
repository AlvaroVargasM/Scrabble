#ifndef QUEUE_USING_OOP_LINKEDLIST_H
#define QUEUE_USING_OOP_LINKEDLIST_H

#include <string>

#include "Node.h"
#include "Tile.h"

class Word {
private:
    Node *head;
public:
    Word();
    ~Word();
    void addLast(Tile);
    void addFront(Tile);
    void printList();
    std::string getWord(Word);
};


#endif //QUEUE_USING_OOP_LINKEDLIST_H
