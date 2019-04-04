#include <iostream>
#include "LinkedList.h"
#include "PackTile.h"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {}

void LinkedList::addFront(PackTile pTile) {
    char let = pTile.getLetter();
    int i = pTile.getRow();
    int j = pTile.getColumn();
    int pts = pTile.getValue();

    Node *n = new Node(let,i,j,pts);
    n->setNext(this->head);
    this->head = n;
}

void LinkedList::addFront(Tile tile) {
    char let = tile.getLetter();
    int i = tile.getRow();
    int j = tile.getColumn();
    int pts = tile.getPoints();

    Node *n = new Node(let,i,j,pts);
    n->setNext(this->head);
    this->head = n;
}

void LinkedList::addLast(PackTile pTile) {
    char let = pTile.getLetter();
    int i = pTile.getRow();
    int j = pTile.getColumn();
    int pts = pTile.getValue();



    Node* n = new Node(let,i,j,pts);
    n->setNext(nullptr);

    if(this->head == nullptr)
        this->head = n;
    else {
        Node *temp = this->head;
        while(temp->getNext() != nullptr)
            temp = temp->getNext();
        temp->setNext(n);
    }
}

void LinkedList::addLast(Tile tile) {
    char let = tile.getLetter();
    int i = tile.getRow();
    int j = tile.getColumn();
    int pts = tile.getPoints();



    Node* n = new Node(let,i,j,pts);
    n->setNext(nullptr);

    if(this->head == nullptr)
        this->head = n;
    else {
        Node *temp = this->head;
        while(temp->getNext() != nullptr)
            temp = temp->getNext();
        temp->setNext(n);
    }
}
void LinkedList::printList() {
    Node* temp = this->head;

    do {
        std::cout << temp->getL() <<  ":" << temp->getPts() <<" -> ";
        temp = temp->getNext();
    } while (temp != nullptr);

    std::cout << "NULL \n";
}

//30/03/2019
std::string LinkedList::getWord() {
    Node* searcherPtr = this->head;
    std::string word;

    while(searcherPtr != nullptr) {
        word += searcherPtr->getL();
        searcherPtr = searcherPtr->getNext();
    }

    return word;
}

//29/03/19
/*
int LinkedList::getPoints() {
    Node *temp = this->head;
    int points = 0;
    int wmult = 1;

    do {
        int var = 1;
        if (temp->getM() != 1) {
            if (temp->isWM())
                wmult = temp->getM();
            else
                var = temp->getM();
        }
        points += (temp->getPts() * var);
        temp = temp->getNext();
        } while (temp != nullptr);

    return points * wmult;
}
 */

bool LinkedList::isHorizontal() {
    Node *n1 = this->head;
    Node *n2 = n1->getNext();

    if (n1->getI() == n2->getI())
        return true;
    else
        return false;
}

Node* LinkedList::getLastNode() {
    Node *temp = this->head;
    while (temp->getNext() != nullptr)
        temp = temp->getNext();

    return temp;
}

void LinkedList::deleteFrontNode(){
    Node *searcherPtr = head;

    if (head == nullptr)
        std::cout << "The list is empty, can't delete front node.\n";
    else
        head = head->getNext();

    delete searcherPtr;
}

 void LinkedList::deleteEndNode() {
     Node *ptr, *prev;

     if (head == nullptr)
         std::cout << "The list is empty, cant delete nack node.\n";
     else {
         ptr = head;
         while (ptr->getNext() != nullptr) {
             prev = ptr;
             ptr = ptr->getNext();
         }
         prev->setNext(nullptr);
         delete(ptr);
     }
 }

Node *LinkedList::getHead() const {
    return this->head;
}

void LinkedList::setHead(Node *head) {
    LinkedList::head = head;
}

int LinkedList::getSize() {
    Node* searcherPtr = this->head;
    int size = 0;

    while(searcherPtr != nullptr) {
        ++size;
        searcherPtr = searcherPtr->getNext();
    }

    return size;
}