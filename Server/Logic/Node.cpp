#include "Node.h"

/**
 * Node constructor, receives and assign all of the data needed in the Node to work in the LinkedList
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

char Node::getL() const {
    return this->l;
}

Node *Node::getNext() const {
    return this->next;
}

void Node::setNext(Node *next) {
    Node::next = next;
}

int Node::getPts() const {
    return this->pts;
}

int Node::getI() const {
    return this->i;
}

int Node::getJ() const {
    return j;
}