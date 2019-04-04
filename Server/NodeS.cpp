//
// Created by jonathangarcia on 01/04/19.
//
#include <iostream>
#include "NodeS.h"
#include "PackTile.h"

NodeS ::NodeS(PackTile *packTile) {
    this->data=packTile;
    this->next= nullptr;
}
void NodeS::setNext(NodeS *n) {
    this->next= n;


}

NodeS* NodeS::getNext()  {
    return this->next;
}
PackTile* NodeS::getData() {
    return this->data;

}


