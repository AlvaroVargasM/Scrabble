#include "Node.h"

Node::Node(char _l, int _i, int _j, int _pts) {
    this->l = _l;
    this->next = nullptr;
    this->wM = false;
    this->pts = _pts;
    this->i = _i;
    this->j = _j;
    this->blocked = false;
}

char Node::getL() const {
    return this->l;
}

void Node::setL(char l) {
    Node::l = l;
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

void Node::setPts(int pts) {
    Node::pts = pts;
}

int Node::getI() const {
    return this->i;
}

void Node::setI(int i) {
    Node::i = i;
}

int Node::getJ() const {
    return j;
}

void Node::setJ(int j) {
    Node::j = j;
}

bool Node::isBlocked() const {
    return blocked;
}

void Node::setBlocked(bool blocked) {
    Node::blocked = blocked;
}
