#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {}

void LinkedList::addFront(Tile t) {
    char let = t.getLetter();
    int mult = t.getMultiplier();
    int i = t.getRow();
    int j = t.getColumn();
    int pts = t.getPoints();

    Node *n = new Node(let,mult,i,j,pts);
    n->setNext(head);
    head = n;
}

void LinkedList::addLast(Tile t) {
    char let = t.getLetter();
    int mult = t.getMultiplier();
    int i = t.getRow();
    int j = t.getColumn();
    int pts = t.getPoints();

    Node* n = new Node(let,mult,i,j,pts);
    n->setNext(nullptr);

    if(head == nullptr)
        head = n;
    else {
        Node *temp = head;
        while(temp->getNext() != nullptr)
            temp = temp->getNext();
        temp->setNext(n);
    }
}

void LinkedList::printList() {
    Node* temp = head;

    do {
        std::cout << temp->getL() << ":" << temp->getM() <<  ":" << temp->getPts() <<" -> ";
        temp = temp->getNext();
    } while (temp != nullptr);

    std::cout << "NULL \n";
}


//30/03/2019
std::string LinkedList::getWord() {
    Node* searcher = this->head;
    std::string var;

    for (int i = 0;searcher != nullptr; i++) {
        var+=searcher->getL();
        searcher = searcher->getNext();
    }

    return var;
}

//29/03/19
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
    Node *temp = head;

    if (head == nullptr)
        std::cout << "The list is empty.";
    else
        head = head->getNext();

    delete temp;
}

 void LinkedList::deleteEndNode() {
     Node *ptr, *prev;

     if (head == nullptr)
         std::cout << "The list is empty.";
     else {
         ptr = head;
         while (ptr->getNext() != nullptr) {
             prev = ptr;
             ptr = ptr->getNext();

         }
         prev->setNext(nullptr);
         free(ptr);
     }
 }

Node *LinkedList::getHead() const {
    return head;
}

void LinkedList::setHead(Node *head) {
    LinkedList::head = head;
}