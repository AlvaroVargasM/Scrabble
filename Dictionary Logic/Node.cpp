//
// Created by jondorito on 16/03/19.
//

#include "Node.h"

Node::Node(string data) {
    this->data = data;
    this->next = nullptr;
}

string Node::getData() {
    return this->data;
}

Node* Node::getNext() {
    return this->next;
}

int Node::getDataLength() {
    return this->data.size();
}

void Node::setNext(Node *next) {
    this->next = next;
}
