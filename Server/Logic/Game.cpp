#include "Game.h"
#include "GameBoard.h"
#include "Searcher.h"
#include "Stack.h"
#include "../Networking/PackTile.h"
#include "LinkedList.h"
#include "../Networking/GenericLinkedList.h"

Game::Game() {
    // Stack * stack = new Stack;
    this->players = new GenericLinkedList<Player>();
    Game* ptr = &(*this);
    //this->accessCode = to_string(&ptr);
}

void Game::addPlayer(Player* player) {
    this->players->add(*player);
}

const Searcher &Game::getSearcher() const {
    return this->searcher;
}

void Game::setSearcher(const Searcher &searcher) {
    Game::searcher = searcher;
}

std::string Game::verify(PackTile* p) {
    std::string response;
    LinkedList word;

    for(int i = 0;i < 7;i++)
        if (p[i].getValue() != -1)
            word.addLast(p[i]);

    LinkedList expWord = this->searcher.wordExpand(word,this->board);

    if(this->searcher.isWordExpanded(word,expWord)) {
        if (this->searcher.wordVerify(expWord, this->board)) {
            this->current->setTurn(false);
            response = "1," + std::to_string(this->searcher.wordPointCount(expWord, this->board));
        }
        else
            response = "0";
    }

    else {
        if (this->searcher.wordConnect(word, this->board)) {
            if (this->searcher.wordVerify(word, this->board)) {
                response = "1," + std::to_string(this->searcher.wordPointCount(expWord, this->board));
            }
            else
                response = "0";
        }
        else
            response = "0";
    }
    return response;
}
