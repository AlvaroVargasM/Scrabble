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
            word.addLast(board.getTile(i, ++j));
            lastNodePtr = lastNodePtr->getNext();
        }
        word.deleteEndNode();

        while (firstNodePtr->getL() != '.'){
            int i = firstNodePtr->getI();
            int j = firstNodePtr->getJ();
            word.addFront(board.getTile(i, --j));
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

    int size = word.getSize();
    bool horizontalDirection = word.isHorizontal();

    for(int k = 0;k < size;++k) {
        int i = searcherPtr->getI();
        int j = searcherPtr->getJ();

        if(horizontalDirection) {
            word.addLast(board.getTile(++i, j));
            if (word.getLastNode()->getL() != '.') {
                word.deleteEndNode();
                return true;
            }
            else {
                word.deleteEndNode();
                i = searcherPtr->getI();
            }

            word.addLast(board.getTile(--i, j));
            if (word.getLastNode()->getL() != '.') {
                word.deleteEndNode();
                return true;
            }
            else {
                word.deleteEndNode();
            }
        }
        else {
            word.addLast(board.getTile(i, ++j));
            if (word.getLastNode()->getL() != '.') {
                word.deleteEndNode();
                return true;
            }
            else {
                word.deleteEndNode();
                j = searcherPtr->getJ();
            }

            word.addLast(board.getTile(i, --j));
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
/*
int Searcher::wordPointCount() {
    confirmedWords[0].printList();
    int points = confirmedWords[0].getPoints();
    return points;
}
*/

bool Searcher::isWordExpanded(LinkedList list1, LinkedList list2) {
    if (list1.getSize() == list2.getSize())
        return false;
    else
        return true;
}

int Searcher::wordPointCount(LinkedList word, GameBoard board) {
    Node *searcher = word.getHead();
    int points = 0;
    int wordMultiplier = 1;
    while(searcher != nullptr) {
        int i = searcher->getI();
        int j = searcher->getJ();
        int pts = searcher->getPts();
        int m = 1;

        Tile t = board.getTile(i,j);

        if (t.isWordMultiplier()) {
            wordMultiplier = t.getMultiplier();
        }
        else
            m = t.getMultiplier();

        points += (pts * m);
        searcher = searcher->getNext();
    }
    return points * wordMultiplier;
}

bool Searcher::wordVerify(LinkedList word, GameBoard board) {
    if (board.getOrganizer()->searchWord(word.getWord())) {
        board.setVerifiedWord(word);
        //confirmedWords[0] = word;
        return true;
    }
    return false;
}

std::string Searcher::verify(PackTile *) {
    return std::__cxx11::string();
}
