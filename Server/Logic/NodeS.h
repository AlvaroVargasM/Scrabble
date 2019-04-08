#ifndef QUEUE_USING_OOP_NODES_H
#define QUEUE_USING_OOP_NODES_H

#include "../Networking/PackTile.h"


/**
 * class that models the real abstraction of the behavior of the nodes of a Stack and assigns them in the Stack class.
 */

class NodeS {
private:
    PackTile *data;
    NodeS *next;
    NodeS *prev;

public:
    NodeS(PackTile* packTile);

    void setNext(NodeS *n);

    NodeS *getNext();

    PackTile *getData();

};

#endif //QUEUE_USING_OOP_NODES_H
