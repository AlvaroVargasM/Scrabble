#include "Node.h"

/**
 * Node constructor, receives and assign all of the data needed in the Node to work in the LinkedList.
 * @param _l letter
 * @param _i row
 * @param _j column
 * @param _pts points
 */
Node::Node(char _l, int _i, int _j, int _pts) {
    this->l = _l;
    this->next = nullptr;
    this->pts = _pts;
    this->i = _i;
    this->j = _j;
}

/**
 * Gets the letter of a Node.
 * @return the letter of the Node
 */
char Node::getL() const {
    return this->l;
}

/**
 * Gets the next Node in the list.
 * @return the next Node
 */
Node *Node::getNext() const {
    return this->next;
}

/**
 * Sets the target of the Node's pointer.
 * @param next Node to point to
 */
void Node::setNext(Node *next) {
    Node::next = next;
}

/**
 * Gets the points of a Node.
 * @return the points of the Node
 */
int Node::getPts() const {
    return this->pts;
}

/**
 * Gets the row of a Node.
 * @return the row of the Node
 */
int Node::getI() const {
    return this->i;
}

/**
 * Gets the column of a Node.
 * @return the column of the Node
 */
int Node::getJ() const {
    return j;
}