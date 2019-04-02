#include "Searcher.h"
#include "LinkedList.h"
#include "Node.h"
#include "Organizer.h"
#include <array>

Searcher::Searcher() {}

LinkedList Searcher::wordExpand(LinkedList word, GameBoard board) {
    Node* firstNodePtr = word.getHead();
    Node* lastNodePtr = word.getLastNode();

    std::cout << "Received word: " << word.getWord() << std::endl;

    if (word.isHorizontal()) {
        while (lastNodePtr->getL() != '.'){
            int i = lastNodePtr->getI();
            int j = lastNodePtr->getJ();
            word.addLast(board.getTile(i,++j));
            lastNodePtr = lastNodePtr->getNext();
        }
        word.deleteEndNode();

        while (firstNodePtr->getL() != '.'){
            int i = firstNodePtr->getI();
            int j = firstNodePtr->getJ();
            word.addFront(board.getTile(i,--j));
            firstNodePtr = word.getHead();
        }
        word.deleteFrontNode();

    } else {
        while (lastNodePtr->getL() != '.') {
            int i = lastNodePtr->getI();
            int j = lastNodePtr->getJ();
            word.addLast(board.getTile(++i, j));
            lastNodePtr = lastNodePtr->getNext();
        }
        word.deleteEndNode();

        while (firstNodePtr->getL() != '.') {
            int i = firstNodePtr->getI();
            int j = firstNodePtr->getJ();
            word.addFront(board.getTile(--i, j));
            firstNodePtr = word.getHead();
        }
        word.deleteFrontNode();
    }

    std::cout << "Expanded word: " << word.getWord() << std::endl;

    return word;
}

bool Searcher::wordConnect(LinkedList word, GameBoard board) {
    Node *searcherPtr = word.getHead();

    std::cout << "Word before connection check: " << word.getWord() << std::endl;

    int size = word.getSize();
    bool horizontalDirection = word.isHorizontal();

    for(int k = 0;k < size;++k) {
        int i = searcherPtr->getI();
        int j = searcherPtr->getJ();

        if(horizontalDirection) {
            word.addLast(board.getTile(++i,j));
            if (word.getLastNode()->getL() != '.') {
                word.deleteEndNode();
                std::cout << "Word after connection check: " << word.getWord() << std::endl;
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

int Searcher::wordPointCount() {
    confirmedWords[0].printList();
    int points = confirmedWords[0].getPoints();
    return points;
}

bool Searcher::wordVerify(LinkedList word, GameBoard board) {
    std::cout << "Word reached at grammar verification: " << word.getWord() << std::endl;
    if (board.getOrganizer()->searchWord(word.getWord())) {
        confirmedWords[0] = word;
        return true;
    }
    return false;
}