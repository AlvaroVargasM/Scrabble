#ifndef QUEUE_USING_OOP_SEARCHER_H
#define QUEUE_USING_OOP_SEARCHER_H

#include "Tile.h"
#include "LinkedList.h"
#include "GameBoard.h"

/**
 * This class is in charge of the words in the game, for that it uses linked lists to interact with the game board.
 */
class Searcher {
public:
    Searcher();

    LinkedList wordExpand(LinkedList word, GameBoard board);

    bool wordConnect(LinkedList word, GameBoard board);

    bool wordVerify(LinkedList word, GameBoard board);

    bool isWordExpanded(LinkedList list1, LinkedList l2);

    int wordPointCount(LinkedList word, GameBoard board);

    bool wordCorrectPosition(LinkedList word);
};


#endif //QUEUE_USING_OOP_SEARCHER_H
