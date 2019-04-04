#include <iostream>
#include "LinkedList.h"
#include "PackTile.h"

/**
 * Linked list constructor, initialize a the head Node to null pointer
 */
LinkedList::LinkedList() {
    head = nullptr;
}

/**
 * Linked list deconstructor
 */
LinkedList::~LinkedList() {}

/**
 * Adds a  new Node at the begging of the list, receives a Pack Tile
 * @param pTile is converted into a Node
 */
void LinkedList::addFront(PackTile pTile) {
    char let = pTile.getLetter();
    int i = pTile.getRow();
    int j = pTile.getColumn();
    int pts = pTile.getValue();

    Node *n = new Node(let,i,j,pts);
    n->setNext(this->head);
    this->head = n;
}

/**
 * Adds a new Node at the begging of the list, receives a Tile
 * @param tile is converted into Node
 */
void LinkedList::addFront(Tile tile) {
    char let = tile.getLetter();
    int i = tile.getRow();
    int j = tile.getColumn();
    int pts = tile.getPoints();

    Node *n = new Node(let,i,j,pts);
    n->setNext(this->head);
    this->head = n;
}

/**
 * Adds a new Node at the end of the list, receives a Pack Tile
 * @param pTile  is converted into Node
 */
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

/**
 * Adds a new Node at the end of the list, receives a Tile
 * @param tile is converted into Node
 */
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

/**
 * Prints an abstraction of the list, with Nodes as: Letter:Points
 */
void LinkedList::printList() {
    Node* temp = this->head;

    do {
        std::cout << temp->getL() <<  ":" << temp->getPts() <<" -> ";
        temp = temp->getNext();
    } while (temp != nullptr);

    std::cout << "NULL \n";
}

/**
 * Takes the list, goes through the list taking the char from each Node, letters, to form a string, word.
 * @return the word contained in the linked list
 */
std::string LinkedList::getWord() {
    Node* searcherPtr = this->head;
    std::string word;

    while(searcherPtr != nullptr) {
        word += searcherPtr->getL();
        searcherPtr = searcherPtr->getNext();
    }

    return word;
}

/**
 * Checks if a linked list of at least two nodes is horizontal
 * @return the horizontal state
 */
bool LinkedList::isHorizontal() {
    Node *n1 = this->head;
    Node *n2 = n1->getNext();

    if (n1->getI() == n2->getI())
        return true;
    else
        return false;
}

/**
 * The method calls for the last node of a linked list
 * @return the last Node of the linked list
 */
Node* LinkedList::getLastNode() {
    Node *temp = this->head;
    while (temp->getNext() != nullptr)
        temp = temp->getNext();

    return temp;
}

/**
 * Deletes the first Node of a linked list
 */
void LinkedList::deleteFrontNode(){
    Node *searcherPtr = head;

    if (head == nullptr)
        std::cout << "The list is empty, can't delete front node.\n";
    else
        head = head->getNext();

    delete searcherPtr;
}

/**
 * Deletes the last Node of the linked list
 */
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

/**
 * Checks for the amount of Nodes in a linked list
 * @return the size of the linked list
 */
int LinkedList::getSize() {
    Node* searcherPtr = this->head;
    int size = 0;

    while(searcherPtr != nullptr) {
        ++size;
        searcherPtr = searcherPtr->getNext();
    }

    return size;
}