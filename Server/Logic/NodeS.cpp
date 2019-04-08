#include <iostream>
#include "NodeS.h"
#include "../Networking/PackTile.h"


/**
 * Node constructor, receives and assign all of the data needed in the Node to work in the Stack.
 * @param data.
 * @param next node.
 */

NodeS ::NodeS(PackTile* packTile) {
    this->data = packTile;
    this->next = nullptr;
    this->prev = nullptr;
}
/**
 * Sets the target of the Node's pointer.
 * @param next Node to point to
 */
void NodeS::setNext(NodeS* n) {
    this->next = n;
}
/**
 * Gets the next Node in the stack.
 * @return the next Node
 */
NodeS* NodeS::getNext() {
    return this->next;
}
/**
 * Gets the packtile value of the node
 * @return the packtile value
 */
PackTile* NodeS::getData() {
    return this->data;
}