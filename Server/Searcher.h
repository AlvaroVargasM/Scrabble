#ifndef QUEUE_USING_OOP_SEARCHER_H
#define QUEUE_USING_OOP_SEARCHER_H

#include "Tile.h"
#include "LinkedList.h"
#include "GameBoard.h"

class Searcher {
public:
    LinkedList confirmedWords[16];
    Searcher();
    bool wordSearcher(LinkedList,GameBoard);
    int pointsSearcher();
};


#endif //QUEUE_USING_OOP_SEARCHER_H
