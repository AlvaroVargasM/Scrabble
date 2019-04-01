#include "Searcher.h"
#include "LinkedList.h"
#include "Node.h"
#include "Organizer.h"
#include <array>

//Hola

Searcher::Searcher() {}

bool Searcher::wordExpand(LinkedList word, GameBoard board) {
    Node* firstNodePtr = word.getHead();
    Node* lastNodePtr = word.getLastNode();

    if (word.isHorizontal()) {
        while (lastNodePtr->getL() != '.'){
            std::cout << "Adding a new node at the end:\n";
            int i = lastNodePtr->getI();
            int j = lastNodePtr->getJ();
            word.addLast(board.getTile(i,++j));
            lastNodePtr = lastNodePtr->getNext();
            word.printList();
        }
        word.deleteEndNode();

        while (firstNodePtr->getL() != '.'){
            std::cout << "Adding a new node at the begging:\n";
            int i = firstNodePtr->getI();
            int j = firstNodePtr->getJ();
            word.addFront(board.getTile(i,--j));
            firstNodePtr = word.getHead();
            word.printList();
        }
        word.deleteFrontNode();

    } else {
        while (lastNodePtr->getL() != '.') {
            std::cout << "Adding a new node at the begging:\n";
            int i = lastNodePtr->getI();
            int j = lastNodePtr->getJ();
            word.addLast(board.getTile(++i, j));
            lastNodePtr = lastNodePtr->getNext();
            word.printList();
        }
        word.deleteEndNode();

        while (firstNodePtr->getL() != '.') {
            std::cout << "Adding a new node at the end:\n";
            int i = firstNodePtr->getI();
            int j = firstNodePtr->getJ();
            word.addFront(board.getTile(--i, j));
            firstNodePtr = word.getHead();
            word.printList();
        }
        word.deleteFrontNode();
    }

    std::cout << "\n\nExpanded word:\n";
    word.printList();
    std::string expandedWord = word.getWord();
    std::cout << expandedWord << "\n\n";


    if (board.getOrganizer()->searchWord(expandedWord)) {
        //confirmedWords[0] = InputWord;
        return true;
    }
    return false;
}

bool Searcher::wordConnect(LinkedList word, GameBoard board) {
    Node *searcherPtr = word.getHead();
    int size = word.getSize();
    bool horizontalDirection = word.isHorizontal();

    for(int k = 0;k < size;++k) {
        int i = searcherPtr->getI();
        int j = searcherPtr->getJ();

        if(horizontalDirection) {
            word.addLast(board.getTile(++i,j));
            if (word.getLastNode()->getL() != '.') {
                word.deleteEndNode();
                return true;
            }
            else {
                word.deleteEndNode();
                i = searcherPtr->getI();
            }

            word.addLast(board.getTile(--i,j));
            if (word.getLastNode()->getL() != '.') {
                word.deleteEndNode();
                return true;
            }
            else {
                word.deleteEndNode();
            }
        }
        else {
            word.addLast(board.getTile(i,++j));
            if (word.getLastNode()->getL() != '.') {
                word.deleteEndNode();
                return true;
            }
            else {
                word.deleteEndNode();
                j = searcherPtr->getJ();
            }

            word.addLast(board.getTile(i,--j));
            if (word.getLastNode()->getL() != '.') {
                word.deleteEndNode();
                return true;
            }
            else
                word.deleteEndNode();
        }

        searcherPtr = searcherPtr->getNext();
    }
    return false;
}

int Searcher::pointsSearcher() {}