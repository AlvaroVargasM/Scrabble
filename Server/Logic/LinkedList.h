#ifndef QUEUE_USING_OOP_LINKEDLIST_H
#define QUEUE_USING_OOP_LINKEDLIST_H

#include <string>
#include "Node.h"
#include "Tile.h"
#include "../Networking/PackTile.h"

/**
 * Linked list that uses Nodes similar to Tile, it is used to manage possible words formed in Game Board
 */
class LinkedList {
private:
    Node *head;

public:
    LinkedList();

    ~LinkedList();

    void addLast(PackTile pTile);

    void addLast(Tile tile);

    void addFront(Tile tile);

    Node* getLastNode();

    void printList();

    std::string getWord();

    bool isHorizontal();

    void deleteEndNode();

    void deleteFrontNode();

    Node *getHead() const;

    int getSize();
};

#endif QUEUE_USING_OOP_LINKEDLIST_H
