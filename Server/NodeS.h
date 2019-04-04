//
// Created by jonathangarcia on 01/04/19.
//

#ifndef QUEUE_USING_OOP_NODES_H
#define QUEUE_USING_OOP_NODES_H
#include "PackTile.h"
class NodeS{
public:
    NodeS(PackTile* packTile);
    void setNext(NodeS* n);
    NodeS* getNext();
    PackTile*getData();

private:
    PackTile *data;
    NodeS* next;
};
#endif //QUEUE_USING_OOP_NODES_H
