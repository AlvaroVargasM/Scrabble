//
// Created by jonathangarcia on 30/03/19.
//
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Stack.h"
#include "PackTile.h"
#include "NodeS.h"
using namespace std;
Stack::Stack() {
    head= nullptr;
}
// Utility function to create  a new node type of Packtile and add an element x
void Stack::push(PackTile * x)
{   NodeS* nodeS= new NodeS(x);
    nodeS->setNext(this->head);
    this->head= nodeS;
    counter++;
}
//Funtion to get and return a last Node type PackTile
PackTile Stack::pop(){
    NodeS*a;
    NodeS* temp = this->head;
    while(temp->getNext()!= nullptr){
        a=temp;
        temp = temp->getNext();
    }
    a->setNext(nullptr);
    delete(temp);
    counter--;
    return *a->getData();

}

PackTile Stack::deleteCurrentNode(NodeS *node_ptr) {

    NodeS*temp = node_ptr;
    temp= temp->getNext();
    //anterior=anterior->setPrev(temp->getNext());




    delete(node_ptr);
    counter--;

    return *temp->getData();

    /*
     *
void deleteNode(Node *node_ptr)
{
    Node *temp = node_ptr->next;
    node_ptr->data = temp->data;
    node_ptr->next = temp->next;
    free(temp);
}  */

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
/*Method that will be responsible for generating the 100 PackTiles that will be sent to the player.

 * */

NodeS* Stack::getLasNode() {
    NodeS *temp = this->head;
    while (temp->getNext() != nullptr)
        temp = temp->getNext();

    return temp;}



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
            PackTile* packTileC=new PackTile('c',3);
            push(packTileL);
            push(packTileT);
            push(packTileC);
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
            PackTile* packTile1= new PackTile('!',0);//comodín
            push(packTile1);
            PackTile* packTileB= new PackTile('b',3);
            push(packTileB);
            PackTile* packTileM= new PackTile('m',3);
            push(packTileM);
            PackTile* packTileP= new PackTile('p',3);
            push(packTileP);
            PackTile* packTileH= new PackTile('h',4);
            push(packTileH);
            PackTile*packTileG= new PackTile('g',2);
            push(packTileG);
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

            PackTile* packTileW= new PackTile('w',1);
            push(packTileW);
            PackTile* packTileX= new PackTile('x',8);
            push(packTileX);
            PackTile* packTileZ= new PackTile('z',10);
            push(packTileZ);
        }
    }
}
void Stack:: PrintStack(){
    NodeS* temp = this->head;

    do {
        cout <<temp->getData()->getLetter() <<  ":" << temp->getData()->getValue() ;
        std::cout << "\n";
        temp = temp->getNext();
    } while (temp != nullptr);

    std::cout << "\n";
}




PackTile Stack::Swap(PackTile array[]) {
    generate();

    srand((unsigned)time(0));
    int v1 = rand()%100 ;
    PackTile temp1=array[0];

    PackTile temp2=array[1];
    PackTile temp7=array[2];

  //  cout <<v1;
    PackTile* packTile=new PackTile('#',-1);
    PackTile  arr[]={*packTile,*packTile ,*packTile ,*packTile ,*packTile ,* packTile, *packTile};
        array=arr;

    NodeS *temp=this->head;

     for(int i=0;i<(int)v1;i++) {
         temp=temp->getNext();

         if (i == (int)(( v1 )/ 2)&& (temp!= nullptr)) {
              arr[0]=deleteCurrentNode(temp);
         }

         if (i == (int)(( v1 )/ 3)) {
             arr[1]=deleteCurrentNode(temp);
         }

         if (i == (int)(( v1 )/ 5)) {
             arr[0]=deleteCurrentNode(temp);
             }


         }

      return arr[7];
}


