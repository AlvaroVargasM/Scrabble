#include "Node.h"

Node::Node(char _l, int _m, int _i, int _j, int _pts) {
    this->l = _l;
    this->m = _m;
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

int Node::getM() const {
    return this->m;
}

void Node::setM(int m) {
    Node::m = m;
}

Node *Node::getNext() const {
    return this->next;
}

void Node::setNext(Node *next) {
    Node::next = next;
}

bool Node::isWM() const {
    return this->wM;
}

void Node::setWM(bool wM) {
    Node::wM = wM;
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
