//
// Created by jonathangarcia on 01/04/19.
//
#include <iostream>
#include "NodeS.h"
#include "PackTile.h"
NodeS ::NodeS(PackTile* packTile) {
    this->data=packTile;
    this->next= nullptr;
    this->prev= nullptr;
}
void NodeS::setNext(NodeS* n) {
    this->next= n;}

void NodeS::setPrev(NodeS* n){
     this->prev=n;
 }
NodeS* NodeS::getPrev() {
    return this->prev;


}



NodeS* NodeS::getNext()  {
    return this->next;
}
PackTile* NodeS::getData() {
    return this->data;
}


