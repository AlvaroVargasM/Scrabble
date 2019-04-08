#ifndef QUEUE_USING_OOP_DICTIONARY_H
#define QUEUE_USING_OOP_DICTIONARY_H


#include "Element.h"
#include <string>

/**
 * Dictionary class manages all the dictionaries related to specific letters
 */
class Dictionary {
private:
    Element* header;
    int length;

public:
    Dictionary();

    Element* getHead();

    int getLength();

    Element* getIndex(int);

    void insertNode(std::string);
};


#endif //QUEUE_USING_OOP_DICTIONARY_H
