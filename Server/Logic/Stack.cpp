/**
  *@file Stack.h
  *@version 2.0
  *@date 31/03/2019
  *@author García Ugalde Jonathan
  *@title Class Stack
  *@brief  structure of data type packtile to communicate with the GUI

  */
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Stack.h"
#include "../Networking/PackTile.h"
#include "NodeS.h"

Stack::Stack() {
    head= nullptr;
}


/**
 * This method, takes from the packtile class, creates a pointer to a packet
 * type object, assigns it to a node and assigns it to the bottom of the stack.
 * @param data type Packtile
 */
// Utility function to create  a new node type of Packtile and add an element x
void Stack::push(PackTile *x) {
    NodeS* nodeS= new NodeS(x);
    nodeS->setNext(this->head);
    this->head= nodeS;
    counter++;
}

/**
* Method that takes node by node stacked and it takes them out of the pile of Packtiles,
 * and this returns the value of the node that is going to be eliminated at the moment and returns it.
 * Based on the principle of the first value to enter is the last to exit the stack of nodes
* @return a packtile object.
*/
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
/**
* Method that allows to show how many elements have been stacked
* @return integer value
*/
int Stack::size() {
    return counter;
}

/**
Method that verifies that the stack is already full with the
 98 packtiles that are going to be generated and returns a bool value
* @return bool value
*/
bool Stack::isFull() {
    if (size() == 100)
        return true;
    return false;
}

/**
Method that verifies that the stack is already full with the
 98 packtiles that are going to be generated and returns a bool value
* @return bool value
*/

NodeS *Stack::getLasNode() {
    NodeS *temp = this->head;
    while (temp->getNext() != nullptr)
        temp = temp->getNext();
    return temp;
}
/**
This method is responsible for creating the 98 tiles of the game, Based on the client specifications.the idea is that each time that it is called to
 make a change of values ​​it will generate a new return value that will be stored in a 7 position array,
 where it is going to rename it so that the user's data can be refined in the GUI through the server.
 Access to the change will be made by the swap method.*/

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

/**
 * In this method, an array with 7 values ​​is received, of which the first 3 are those that correspond
 * to the change in the stack for another 3 random values, this method takes random positions 3 new nodes
 * and returns them in another array in addition, the values ​​that were passed by parameters are added
 * to the stack so that in a possible new request they can be accessed.
 * @param array type Packtile
 * @return array type packTile Upadated
 */
PackTile* Stack::swap(PackTile *arr) {
    PackTile *packTile= new PackTile('.',-1);
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
            std::cout << array[0].getLetter()<< array[0].getValue();
            std::cout << "\n";
        }
        if (i == (int)random2) {
            a->setNext(a->getNext());
            delete (temp);
            counter--;
            array[1] =*a->getData();
            std::cout << array[1].getLetter()<< array[1].getValue();;
            std::cout << "\n";
        }
        if (i == (int)random3) {
            a->setNext(a->getNext());
            delete (temp);
            counter--;
            array[2] = *a->getData();
            std::cout << array[2].getLetter()<< array[0].getValue();
            std::cout << "\n";
        }
    }
    push(temp1);
    push(temp2);
    push(temp3);
    return array;
}