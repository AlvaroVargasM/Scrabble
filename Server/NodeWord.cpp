//
// Created by jondorito on 25/03/19.
//

#include "NodeWord.h"

NodeWord::NodeWord(string data) {
    this->data = data;
    this->next = nullptr;
}

string NodeWord::getData() {
    return this->data;
}

NodeWord* NodeWord::getNext() {
    return this->next;
}

int NodeWord::getDataLength() {
    return this->data.size();
}

void NodeWord::setNext(NodeWord *next) {
    this->next = next;
}
