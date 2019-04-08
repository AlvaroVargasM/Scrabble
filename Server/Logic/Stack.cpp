#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Stack.h"
#include "../Networking/PackTile.h"
#include "NodeS.h"

Stack::Stack() {
    head= nullptr;
}

// Utility function to create  a new node type of Packtile and add an element x
void Stack::push(PackTile *x) {
    NodeS* nodeS= new NodeS(x);
    nodeS->setNext(this->head);
    this->head= nodeS;
    counter++;
}

//Funtion to get and return a last Node type PackTile
PackTile Stack::pop() {
     NodeS* aux;
     NodeS* temp = this->head;

     while(temp->getNext()!= nullptr){
         aux=temp;
         temp =temp->getNext();
     }
     aux->setNext(nullptr);
     delete(temp);
     counter--;
     return *aux->getData();
}

int Stack::size() {
    return counter;
}

bool Stack::isFull() {
    if (size() == 100)
        return true;
    return false;
}

NodeS *Stack::getLasNode() {
    NodeS *temp = this->head;
    while (temp->getNext() != nullptr)
        temp = temp->getNext();
    return temp;
}

// Method that will be responsible for generating the 100 PackTiles that will be sent to the player.
void Stack::generate() {
    int i;
    for (i = 0; i < 100; i++) {
        if (i < 12) {
            //PackTile *packTileA = new PackTile('a', 1);
            PackTile *packTileE = new PackTile('e', 1);
            PackTile *packTileA = new PackTile('a', 1);
            push(packTileE);
            push(packTileA);
        }
        if (i < 6) {
            PackTile *packTileI = new PackTile('i', 1);
            PackTile *packTileS = new PackTile('s', 1);
            push(packTileI);
            push(packTileS);
        }
        if (i < 4) {
            PackTile *packTileL = new PackTile('l', 1);
            PackTile *packTileT = new PackTile('t', 1);
            PackTile *packTileC = new PackTile('c', 3);
            push(packTileL);
            push(packTileT);
            push(packTileC);
        }
        if (i < 5) {
            PackTile *packTileN = new PackTile('n', 1);
            PackTile *packTileR = new PackTile('r', 1);
            PackTile *packTileU = new PackTile('u', 1);
            PackTile *packTileD = new PackTile('d', 2);
            push(packTileN);
            push(packTileR);
            push(packTileU);
            push(packTileD);
        }
        if (i < 9) {
            PackTile *packTileO = new PackTile('o', 9);
            push(packTileO);
        }
        if (i < 2) {
            PackTile *packTile1 = new PackTile('!', 0);//comodín
            push(packTile1);
            PackTile *packTileB = new PackTile('b', 3);
            push(packTileB);
            PackTile *packTileM = new PackTile('m', 3);
            push(packTileM);
            PackTile *packTileP = new PackTile('p', 3);
            push(packTileP);
            PackTile *packTileH = new PackTile('h', 4);
            push(packTileH);
            PackTile *packTileG = new PackTile('g', 2);
            push(packTileG);
        }
        if (i < 1) {
            PackTile *packTileF = new PackTile('f', 4);
            push(packTileF);
            PackTile *packTileV = new PackTile('v', 4);
            push(packTileV);
            PackTile *packTileY = new PackTile('y', 4);
            push(packTileY);
            PackTile *packTileK = new PackTile('k', 5);
            push(packTileK);
            PackTile *packTileQ = new PackTile('q', 5);
            push(packTileQ);
            PackTile *packTileJ = new PackTile('j', 8);
            push(packTileJ);
            PackTile *packTileW = new PackTile('w', 1);
            push(packTileW);
            PackTile *packTileX = new PackTile('x', 8);
            push(packTileX);
            PackTile *packTileZ = new PackTile('z', 10);
            push(packTileZ);
        }
    }
}

void Stack::printStack() {
    NodeS *temp = this->head;
    do {
        std::cout << temp->getData()->getLetter() << ":" << temp->getData()->getValue();
        std::cout << "\n";
        temp = temp->getNext();
    } while (temp != nullptr);
    std::cout << "\n";
}

PackTile* Stack::swap(PackTile *arr) {
    PackTile *packTile= new PackTile('#',-1);
    static  PackTile array[]={*packTile,*packTile,*packTile,*packTile,*packTile,*packTile,*packTile};

    srand((unsigned) time(0));
    PackTile *temp1 = &arr[0];
    PackTile *temp2 = &arr[1];
    PackTile *temp3 = &arr[2];
    int i = 0;

    srand((unsigned) time(0));
    int random1 = rand() % 98;
    int random2 = rand() % 98;
    int random3 = rand() % 98;
    NodeS *a;
    NodeS *temp = this->head;
    while (temp->getNext() != nullptr) {
        a = temp;
        i++;
        temp = temp->getNext();

        if (i == (int)random1) {
            a->setNext(a->getNext());
            delete (temp);
            counter--;
            array[0] =*a->getData();
            std::cout << arr[0].getLetter()<< arr[0].getValue();
            std::cout << "\n";
        }
        if (i == (int)random2) {
            a->setNext(a->getNext());
            delete (temp);
            counter--;
            array[1] =*a->getData();
            std::cout << arr[1].getLetter()<< arr[1].getValue();;
            std::cout << "\n";
        }
        if (i == (int)random3) {
            a->setNext(a->getNext());
            delete (temp);
            counter--;
            array[2] = *a->getData();
            std::cout << arr[2].getLetter()<< arr[0].getValue();;
            std::cout << "\n";
        }
    }
    push(temp1);
    push(temp2);
    push(temp3);
    return array;
}