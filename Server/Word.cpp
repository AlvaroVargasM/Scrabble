#include <iostream>
#include "Word.h"

Word::Word() {
    head = nullptr;
}

Word::~Word() {}

void Word::addFront(Tile t) {
    // std::cout << "list has elements, adding new node at front \n";

    char let = t.getLetter();
    int mult = t.getMultiplier();

    Node *n = new Node(let, mult);
    n->setNext(head);
    head = n;
}

void Word::addLast(Tile t) {
    char let = t.getLetter();
    int mult = t.getMultiplier();

    Node* n = new Node(let,mult);
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

void Word::printList() {
    Node* temp = head;

    do {
        std::cout << temp->getL() << " : " << temp->getM() << " -> ";
        temp = temp->getNext();
    } while (temp != nullptr);

    std::cout << "NULL \n";
}

std::string Word::getWord(Word ll) {
    Node* searcher = head;
    char arr[100];

    for (int i = 0; i < 100 && searcher != nullptr; i++) {
        arr[i] = searcher->getL();
        searcher = searcher->getNext();
    }
    std::string word(arr);
    return word;
}