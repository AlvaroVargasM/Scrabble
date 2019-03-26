//
// Created by jondorito on 26/03/19.
//

#include "Element.h"

Element::Element(string data) {
    this->data = data;
    this->next = nullptr;
}

string Element::getData() {
    return this->data;
}

Element* Element::getNext() {
    return this->next;
}

int Element::getDataLength() {
    return this->data.size();
}

void Element::setNext(Element *next) {
    this->next = next;
}
