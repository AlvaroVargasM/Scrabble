//
// Created by jondorito on 16/03/19.
//

#ifndef UNTITLED1_NODE_H
#define UNTITLED1_NODE_H

#include <string>

using namespace std;

class Node {
private:
    string data;
    Node* next;
public:
    Node(string );
    int getDataLength();
    string getData();
    Node* getNext();
    void setNext(Node*);

};


#endif //UNTITLED1_NODE_H
