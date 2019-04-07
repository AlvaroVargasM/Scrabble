#ifndef QUEUE_USING_OOP_ELEMENT_H
#define QUEUE_USING_OOP_ELEMENT_H

#include <string>

class Element {
private:
    std::string data;
    Element* next;

public:
    Element(std::string);

    int getDataLength();

    std::string getData();

    Element* getNext();

    void setNext(Element*);
};

#endif //QUEUE_USING_OOP_ELEMENT_H
