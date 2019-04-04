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

    for( i=0;i<100;i++){
        if(i<12){
            PackTile* packTileA=new PackTile('a',1);
            PackTile* packTileE= new PackTile('e',1);

            push(packTileA);
            push(packTileE);
        }
        if(i<6){
            PackTile* packTileI=new PackTile('i',1);
            PackTile* packTileS= new PackTile('s',1);
            push(packTileI);
            push(packTileS);
        }
        if(i<4){
            PackTile* packTileL=new PackTile('l',1);
            PackTile* packTileT= new PackTile('t',1);
            push(packTileL);
            push(packTileT);
        }
        if(i<5){
            PackTile* packTileN=new PackTile('n',1);
            PackTile* packTileR= new PackTile('r',1);
            PackTile* packTileU= new PackTile('u',1);
            PackTile* packTileD= new PackTile('d',2);
            push(packTileN);
            push(packTileR);
            push(packTileU);
            push(packTileD);
        }
        if(i<9){
            PackTile* packTileO= new PackTile('o',9);
            push(packTileO);
        }
        if(i<2){
            PackTile* packTileB= new PackTile('b',2);
            push(packTileB);
            PackTile* packTileM= new PackTile('m',2);
            push(packTileM);
            PackTile* packTileP= new PackTile('p',2);
            push(packTileP);
            PackTile* packTileH= new PackTile('h',4);
            push(packTileH);
        }
        if(i<1){
            PackTile* packTileF= new PackTile('f',4);
            push(packTileF);
            PackTile* packTileV= new PackTile('v',4);
            push(packTileV);
            PackTile* packTileY= new PackTile('y',4);
            push(packTileY);
            PackTile* packTileK= new PackTile('k',5);
            push(packTileK);
            PackTile* packTileQ= new PackTile('q',5);
            push(packTileQ);
            PackTile*packTileJ= new PackTile('j',8);
            push(packTileJ);
            PackTile* packTile1= new PackTile('!',0);
            push(packTile1);
            PackTile* packTileW= new PackTile('w',1);
            push(packTileW);
            PackTile* packTileX= new PackTile('x',8);
            push(packTileX);
            PackTile* packTileZ= new PackTile('z',10);
            push(packTileZ);
        }
    }
}