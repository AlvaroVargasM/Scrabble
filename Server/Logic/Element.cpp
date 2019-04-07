#include "Element.h"

Element::Element(std::string data) {
    this->data = data;
    this->next = nullptr;
}

std::string Element::getData() {
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