//
// Created by jonathangarcia on 30/03/19.
//
#include <iostream>
#include "Stack.h"
#include "PackTile.h"
#include "NodeS.h"

using namespace std;





// Utility function to add an element x in the stack
void Stack::push(PackTile  x)
{
    NodeS* nodeS;

    nodeS->data=x;
    nodeS->next=top;
    //top=nodeS;
    counter++;

}
PackTile Stack::pop(){
    NodeS * ptr = top;
    NodeS*prev;
    NodeS*temp;

    while (ptr->next != nullptr) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev= nullptr;
    temp=ptr;
    delete(ptr);
    counter--;



    return temp->data;

}
int Stack::size() {
    return counter;

}
bool Stack::isFull() {
    if(size()==100){
        return  true;
    }
    return false;

}




























