#include "Node.h"

Node::Node(char _l, int _m, int _i, int _j) {
    l = _l;
    m = _m;
    next = nullptr;
    wM = false;
    pts = 0;
    i = _i;
    j = _j;
}

char Node::getL() const {
    return l;
}

void Node::setL(char l) {
    Node::l = l;
}

int Node::getM() const {
    return m;
}

void Node::setM(int m) {
    Node::m = m;
}

Node *Node::getNext() const {
    return next;
}

void Node::setNext(Node *next) {
    Node::next = next;
}

bool Node::isWM() const {
    return wM;
}

void Node::setWM(bool wM) {
    Node::wM = wM;
}

int Node::getPts() const {
    return pts;
}

void Node::setPts(int pts) {
    Node::pts = pts;
}

int Node::getI() const {
    return i;
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
