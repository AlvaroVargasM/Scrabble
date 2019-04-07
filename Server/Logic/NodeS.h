#ifndef QUEUE_USING_OOP_NODES_H
#define QUEUE_USING_OOP_NODES_H

#include "../Networking/PackTile.h"

class NodeS {
private:
    PackTile *data;
    NodeS* next;
    NodeS*prev;

public:
    NodeS(PackTile* packTile);

    void setNext(NodeS* n);

    NodeS* getNext();

    PackTile*getData();

    void setPrev(NodeS * n);

    NodeS* getPrev();
};

#endif //QUEUE_USING_OOP_NODES_H
