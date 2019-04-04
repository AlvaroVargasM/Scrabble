#ifndef QUEUE_USING_OOP_GAME_H
#define QUEUE_USING_OOP_GAME_H

#include "PackTile.h"
#include "GameBoard.h"
#include "Searcher.h"

class Game {
private:
    GameBoard board;
    Searcher searcher;
public:
    Game();
    void addPlayer();
    std::string verify(PackTile*);

    const GameBoard &getBoard() const {
        return board;
    }

    void setBoard(const GameBoard &board) {
        Game::board = board;
    }

    const Searcher &getSearcher() const;

    void setSearcher(const Searcher &searcher);
};


#endif //QUEUE_USING_OOP_GAME_H
