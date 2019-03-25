//
// Created by jondorito on 16/03/19.
//

#include "LInkedList.h"
#include "Node.h"
#include <string>
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
    this->length = 0;
    this->header = nullptr;
}

//returns a pointer of the header node in the list
Node* LinkedList::getHead() {
    return this->getHead();
}

//returns the length of the list
int LinkedList::getLength() {
    return this->length;
}

//return a node base on its position in the list
Node* LinkedList::getIndex(int index) {
    int listIndex = 1;
    Node* temp = this->header;
    while(listIndex < index){
        temp = temp->getNext();
        listIndex++;
    }return temp;
}


//Creates a new node and put on the right position base on data.length in ascending order
void LinkedList::insertNode(string data) {
    Node* temp = new Node(data);
    if(this->length == 0){
        this->header = temp;
        this->length++;
    }else{
        Node* current = this->header;
        if(temp->getData().size() <= current->getData().size()){
            this->header = temp;
            temp->setNext(current);
            this->length++;
        }else{
            Node* follow;
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
