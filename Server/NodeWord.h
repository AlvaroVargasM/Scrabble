//
// Created by jondorito on 25/03/19.
//

#ifndef QUEUE_USING_OOP_NODEWORD_H
#define QUEUE_USING_OOP_NODEWORD_H


#include <string>

using namespace std;

class NodeWord {
private:
    string data;
    NodeWord* next;
public:
    NodeWord(string );
    int getDataLength();
    string getData();
    NodeWord* getNext();
    void setNext(NodeWord*);

};



#endif //QUEUE_USING_OOP_NODEWORD_H
