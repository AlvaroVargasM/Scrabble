//
// Created by jondorito on 26/03/19.
//

#ifndef QUEUE_USING_OOP_DICTIONARY_H
#define QUEUE_USING_OOP_DICTIONARY_H


#include "Element.h"
#include <string>

using namespace std;


class Dictionary {
private:
    Element* header;
    int length;
public:
    Dictionary();
    Element* getHead();
    int getLength();
    Element* getIndex(int);
    void insertNode(string);



};


#endif //QUEUE_USING_OOP_DICTIONARY_H
