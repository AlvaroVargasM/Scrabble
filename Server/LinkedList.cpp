#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {}

void LinkedList::addFront(Tile t) {
    // std::cout << "list has elements, adding new node at front \n";

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

    if(head == nullptr) {
        // std::cout << "list id currently empty, adding new node \n";
        head = n;
    }
    else {
        // std::cout << "list has elements, adding new node at last \n";
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

std::string LinkedList::getWord(LinkedList ll) {
    Node* searcher = head;
    char arr[15];

    for (int i = 0; i < 15 && searcher != nullptr; i++) {
        arr[i] = searcher->getL();
        searcher = searcher->getNext();
    }
    std::string word(arr);
    return word;
}

//29/03/19
int LinkedList::getPoints(LinkedList ll) {
    Node *temp = head;
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
        } while (temp != nullptr) ;

    return points * wmult;
}

bool LinkedList::isHorizontal(LinkedList ll) {
    Node *n1 = head;
    Node *n2 = n1->getNext();

    if (n1->getI() == n2->getI())
        return true;
    else
        return false;
}

//getlastNode

Node* LinkedList::getLastNode(LinkedList l) {


    Node *temp = head;
    while (temp != nullptr)
        temp = temp->getNext();
    return temp;


}

void LinkedList::deleteFrontNode(){
    Node *temp = head;

    if (head== nullptr){
        std::cout << "The list is empty.";
    }
    else

        head = head->getNext();

        delete temp;






}
 void LinkedList::deleteEndNode() {

     Node *ptr, *prev;
     if (head == nullptr){
         std::cout << "The list is empty.";}
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