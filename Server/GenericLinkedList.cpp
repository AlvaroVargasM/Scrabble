//
// Created by jondorito on 03/04/19.
//

#include "GenericLinkedList.h"
#include "GenericNode.h"

#include <iostream>

/*template <class T>
GenericLinkedList<T>::GenericLinkedList() {
    this->length = 0;
    this->header = nullptr;
}

template<class T>
void GenericLinkedList<T>::add(T data) {
    GenericNode<T> temp = new GenericNode<T>(data);
    this->header = &temp;
}

template <class T>
T* GenericLinkedList<T>::get(int i) {
    if(this->length == 0){
        return nullptr;
    }
    GenericNode<T>* temp = this->header;
    for(int j = 0; j < i; j++){
        temp = temp->getNext();
    }
    return &temp;
}

template <class T>
void GenericLinkedList<T>::remove(int i) {
    if(i == 1){
        this->header = nullptr;
    }
    GenericNode<T>* temp = get(i-1);
    GenericNode<T>* temp1 = get(i+1);
    temp->setNext(temp1);
}*/