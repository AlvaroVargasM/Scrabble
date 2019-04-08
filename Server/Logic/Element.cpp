#include "Element.h"


/**
 * Receives the data is going to store
 * @param data
 */
Element::Element(std::string data) {
    this->data = data;
    this->next = nullptr;
}

/**
 * Get the data of the node
 * @return std::string
 */
std::string Element::getData() {
    return this->data;
}

/**
 * Get a pointer to next node
 * @return Element*
 */
Element* Element::getNext() {
    return this->next;
}

/**
 * Get the length of the list
 * @return length
 */
int Element::getDataLength() {
    return this->data.size();
}

/**
 * Sets the next node
 * @param next
 */
void Element::setNext(Element *next) {
    this->next = next;
}