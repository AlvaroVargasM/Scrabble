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

int LinkedList::getPoints(LinkedList ll) {
    Node *temp = head;
    int aiuda = 0;


    while (temp->getNext() != nullptr){
        if (temp->isWM()) {
            std::cout << "Multiplier should multiply the word\n";
        }
        aiuda += temp->getPts();
        temp = temp->getNext();
    }

    return aiuda;
}

bool LinkedList::isHorizontal(LinkedList ll) {
    Node *n1 = head;
    Node *n2 = n1->getNext();

    if (n1->getI() == n2->getI())
        return true;
    else
        return false;
}

Node* LinkedList::getLastNode(LinkedList) {
    Node *temp = head;
    while (temp->getNext() != nullptr)
        temp = temp->getNext();
    return temp->getNext();
}

Node *LinkedList::getHead() const {
    return head;
}

void LinkedList::setHead(Node *head) {
    LinkedList::head = head;
}

