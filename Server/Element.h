//
// Created by jondorito on 26/03/19.
//

#ifndef QUEUE_USING_OOP_ELEMENT_H
#define QUEUE_USING_OOP_ELEMENT_H


#include <string>

using namespace std;

class Element {
private:
    string data;
    Element* next;
public:
    Element(string );
    int getDataLength();
    string getData();
    Element* getNext();
    void setNext(Element*);

};


#endif //QUEUE_USING_OOP_ELEMENT_H
