//
// Created by jondorito on 26/03/19.
//

#include "Dictionary.h"
#include "Element.h"
#include <string>
#include <iostream>

/**
 * Dictionary constructor
 */
Dictionary::Dictionary() {
    this->length = 0;
    this->header = nullptr;
}

/**
 * returns a pointer of the header node in the list
 * @return Element
 */
Element* Dictionary::getHead() {
    return this->getHead();
}

/**
 * returns the length of the list
 * @return
 */
int Dictionary::getLength() {
    return this->length;
}


/**
 * return a node base on its position in the list
 * @param index
 * @return Element*
 */
Element* Dictionary::getIndex(int index) {
    int listIndex = 1;
    Element* temp = this->header;
    while(listIndex < index){
        temp = temp->getNext();
        listIndex++;
    }return temp;
}


/**
 * Creates a new node and put on the right position base on data.length in ascending order
 * @param data
 */
void Dictionary::insertNode(std::string data) {
    Element* temp = new Element(data);
    if(this->length == 0){
        this->header = temp;
        this->length++;
    }else{
        Element* current = this->header;
        if(temp->getData().size() <= current->getData().size()){
            this->header = temp;
            temp->setNext(current);
            this->length++;
        }else{
            Element* follow;
            while(current->getNext() != nullptr){
                follow = current->getNext();
                if((current->getData().size() <= temp->getData().size()) &&
                   (temp->getData().size() <= follow->getData().size())){
                    current->setNext(temp);
                    temp->setNext(follow);
                    this->length++;
                    break;
                }else{
                    current = follow;
                }
            }
            if(current->getNext() == nullptr){
                current->setNext(temp);
                this->length++;
            }
        }
    }
}