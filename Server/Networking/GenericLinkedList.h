//
// Created by jondorito on 03/04/19.
//

#ifndef TESTSERVER_GenericLinkedList_H
#define TESTSERVER_GenericLinkedList_H


#include "GenericNode.h"

template <class T>
class GenericLinkedList{
public:
    GenericLinkedList();
    void add(T);
    void remove(int);
    GenericNode<T>* get(int);
    GenericNode<T>* getHead();
private:
    GenericNode<T>* header;
    int length;
};

template <class T>
GenericLinkedList<T>::GenericLinkedList() {
    this->length = 0;
    this->header = nullptr;
}

template<class T>
void GenericLinkedList<T>::add(T data) {
    if(this->length == 0){
        this->header = new GenericNode<T>(data);
    }else{
        this->header->setNext(new GenericNode<T>(data));
    }
}

template <class T>
GenericNode<T>* GenericLinkedList<T>::get(int i) {
    if(this->length == 0){
        return nullptr;
    }
    GenericNode<T>* temp = this->header;
    for(int j = 0; j < i; j++){
        temp = temp->getNext();
    }
    return temp;
}

template <class T>
void GenericLinkedList<T>::remove(int i) {
    if(i == 1){
        this->header = nullptr;
    }
    GenericNode<T>* temp = get(i-1);
    GenericNode<T>* temp1 = get(i+1);
    temp->setNext(temp1);
}

template<class T>
GenericNode<T> *GenericLinkedList<T>::getHead() {
    return this->header;
}


#endif //TESTSERVER_GenericLinkedList_H
