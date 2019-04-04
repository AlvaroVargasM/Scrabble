#ifndef QUEUE_USING_OOP_LINKEDLIST_H
#define QUEUE_USING_OOP_LINKEDLIST_H

#include <string>
#include "Node.h"
#include "Tile.h"
#include "PackTile.h"

class LinkedList {
private:
    Node *head;
public:
    LinkedList();
    ~LinkedList();

    void addLast(PackTile pTile);
    void addFront(PackTile pTile);

    void addLast(Tile tile);
    void addFront(Tile Tile);

    Node* getLastNode();
    void printList();

    std::string getWord();
    //int getPoints();

    bool isHorizontal();

    void deleteEndNode();
    void deleteFrontNode();

    Node *getHead() const;
    void setHead(Node *head);

    int getSize();
};

#endif QUEUE_USING_OOP_LINKEDLIST_H
