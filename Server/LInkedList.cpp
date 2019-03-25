//
// Created by jondorito on 25/03/19.
//

#include "LInkedList.h"
#include "NodeWord.h"
#include <string>
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
    this->length = 0;
    this->header = nullptr;
}

//returns a pointer of the header node in the list
NodeWord* LinkedList::getHead() {
    return this->getHead();
}

//returns the length of the list
int LinkedList::getLength() {
    return this->length;
}

//return a node base on its position in the list
NodeWord* LinkedList::getIndex(int index) {
    int listIndex = 1;
    NodeWord* temp = this->header;
    while(listIndex < index){
        temp = temp->getNext();
        listIndex++;
    }return temp;
}


//Creates a new node and put on the right position base on data.length in ascending order
void LinkedList::insertNode(string data) {
    NodeWord* temp = new NodeWord(data);
    if(this->length == 0){
        this->header = temp;
        this->length++;
    }else{
        NodeWord* current = this->header;
        if(temp->getData().size() <= current->getData().size()){
            this->header = temp;
            temp->setNext(current);
            this->length++;
        }else{
            NodeWord* follow;
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