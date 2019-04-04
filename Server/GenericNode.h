//
// Created by jondorito on 03/04/19.
//

#ifndef TESTSERVER_GenericNode_H
#define TESTSERVER_GenericNode_H

template<class T>
class GenericNode {
public:
    GenericNode(T);
    T getData();
    GenericNode<T>* getNext();
    void setNext(GenericNode<T>*);

private:
    GenericNode* next;
    T data;
};

template<class T>
GenericNode<T>::GenericNode(T data) {
    this->data = data;
    this->next = nullptr;
}

template<class T>
T GenericNode<T>::getData() {
    return this->data;
}

template<class T>
GenericNode<T>* GenericNode<T>::getNext() {
    return this->next;
}

template<class T>
void GenericNode<T>::setNext(GenericNode<T> *next) {
    this->next = next;
}





#endif //TESTSERVER_GenericNode_H
