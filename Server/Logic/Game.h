#ifndef QUEUE_USING_OOP_GAME_H
#define QUEUE_USING_OOP_GAME_H

#include "../Networking/PackTile.h"
#include "GameBoard.h"
#include "Searcher.h"
#include "../Networking/GenericLinkedList.h"

class Game {
private:
    GameBoard board;
    Searcher searcher;
    GenericLinkedList<Player>* players;
    string accessCode;
    Player * current;
public:
    Game();
    void addPlayer(Player*);
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