//
// Created by jonathangarcia on 30/03/19.
//
#include <iostream>
#include "Stack.h"
#include "PackTile.h"
#include "NodeS.h"

using namespace std;





// Utility function to add an element x in the stack
void Stack::push(PackTile * x)
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



    return (*temp->data);

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

void Stack::generate(){
    int i;

    for( i=0;i<99;i++){
        if(i<12){
            PackTile* packTile=new PackTile('A',1);
            PackTile* packTile1= new PackTile('E',1);

            push(packTile);
            push(packTile1);}
        if(i<6){
            PackTile* packTile2=new PackTile('I',1);
            PackTile* packTile3= new PackTile('S',1);
            push(packTile2);
            push(packTile3);
        }
        if(i<4){
            PackTile* packTile8=new PackTile('L',1);
            PackTile* packTile9= new PackTile('T',1);
            push(packTile8);
            push(packTile9);
        }
        if(i<5){
            PackTile* packTile4=new PackTile('N',1);
            PackTile* packTile5= new PackTile('R',1);
            PackTile* packTile6= new PackTile('U',1);
            PackTile* packTile7= new PackTile('D',2);
            push(packTile4);
            push(packTile5);
            push(packTile6);
            push(packTile7);
        }
        if(i<9){
            PackTile* packTile10= new PackTile('O',9);
            push(packTile10);
        }
        if(i<2){
            PackTile* packTile11= new PackTile('B',2);
            push(packTile11);
            PackTile* packTile12= new PackTile('M',2);
            push(packTile12);
            PackTile* packTile13= new PackTile('P',2);
            push(packTile13);
            PackTile* packTile14= new PackTile('H',4);
            push(packTile14);
        }
        if(i<1){
            PackTile* packTile15= new PackTile('F',4);
            push(packTile15);
            PackTile* packTile16= new PackTile('V',4);
            push(packTile16);
            PackTile* packTile17= new PackTile('Y',4);
            push(packTile17);
            PackTile* packTile19= new PackTile('CH',5);
            push(packTile19);
            PackTile* packTile20= new PackTile('Q',5);
            push(packTile20);
            PackTile*packTile21= new PackTile('J',8);
            push(packTile21);
            PackTile* packTile22= new PackTile('LL',8);
            push(packTile22);
            PackTile* packTile23= new PackTile('N!',8);
            push(packTile23);
            PackTile* packTile24= new PackTile('RR',8);
            push(packTile24);
            PackTile* packTile25= new PackTile('X',8);
            push(packTile25);
            PackTile* packTile26= new PackTile('Z',10);
            push(packTile26);
        }
    }
}