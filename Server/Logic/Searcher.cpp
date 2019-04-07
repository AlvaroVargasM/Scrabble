#include "Searcher.h"
#include "LinkedList.h"
#include "Node.h"
#include "Organizer.h"
#include <array>

Searcher::Searcher() {}

/**
 * This method takes a word (in the form of a linked list) and expands it based on the game board, it takes the word,
 * checks if it's horizontal, after that if its horizontal it checks for the adjacent letters in the game board in the
 * x axis, in the other case it checks for the adjacent letters in the game board in the y axis.
 * @param word to expand
 * @param board to check
 * @return the expanded word (linked list)
 */
LinkedList Searcher::wordExpand(LinkedList word, GameBoard board) {
    Node* firstNodePtr = word.getHead();
    Node* lastNodePtr = word.getLastNode();

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
    return word;
}

/**
 * Checks if a word (in the form of a linked list) is connected in any way with another word (also a linked list)
 * @param word to check
 * @param board  to check
 * @return connection status
 */
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

/**
 * This checks if a list was expanded by comparing its size after a wordExpand
 * @param list1 the original list
 * @param list2 the list after expansion
 * @return expansion statuts
 */
bool Searcher::isWordExpanded(LinkedList list1, LinkedList list2) {
    if (list1.getSize() == list2.getSize())
        return false;
    else
        return true;
}

/**
 * This method counts all the points of a word (in the form of a linked list) in the game board
 * @param word to check
 * @param board to get the multipliers from
 * @return the amount of points obtained by that word (linked list)
 */
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

/**
 * This method validates the grammar of a word (in the form of a linked list)
 * @param word to check
 * @param board needed to use the organizer
 * @return the validation of the word
 */
bool Searcher::wordVerify(LinkedList word, GameBoard board) {
    if (board.getOrganizer()->searchWord(word.getWord())) {
        board.setVerifiedWord(word);
        return true;
    }
    return false;
}