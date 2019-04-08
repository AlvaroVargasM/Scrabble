#include <thread>
#include "Game.h"
#include "GameBoard.h"
#include "Searcher.h"
#include "Stack.h"
#include "../Networking/PackTile.h"
#include "LinkedList.h"
#include "../Networking/GenericLinkedList.h"

Game::Game(Organizer *organizer) {
    this->board.setOrganizer(organizer);
    // Stack * stack = new Stack;
    this->players = new GenericLinkedList<Player>();
    Game* ptr = &(*this);
    this->accessCode = "";
}

void Game::addPlayer(Player* player) {
    this->players->add(*player);
}

std::string* Game::getAccessCode() {
    return &this->accessCode;
}

const Searcher &Game::getSearcher() const {
    return this->searcher;
}

void Game::setSearcher(const Searcher &searcher) {
    Game::searcher = searcher;
}

std::string Game::verify(PackTile* p) {
    std::cout << p->getLetter() << std::endl;
    std::string response = "0";
    LinkedList word;

    for(int i = 0;i < 7;i++)
        if (p[i].getValue() != -1)
            word.addLast(p[i]);
    word.printList();

        std::cout << "1" << std::endl;

    LinkedList expWord = this->searcher.wordExpand(word,this->board);

    if(this->searcher.isWordExpanded(word,expWord)) {
        if (this->searcher.wordVerify(expWord, this->board)) {
            //this->current->setTurn(false);
            this->board.setVerifiedWord(expWord);
            response = "1," + std::to_string(this->searcher.wordPointCount(expWord, this->board));
        }
        else
            response = "0";
    }
    else {
        std::cout << "2" << std::endl;
        if (this->searcher.wordConnect(word, this->board)) {
            if (this->searcher.wordVerify(word, this->board)) {
                //this->current->setTurn(false);
                this->board.setVerifiedWord(expWord);
                response = "1," + std::to_string(this->searcher.wordPointCount(expWord, this->board));
            }
            else
                response = "0";
        }
        else
            response = "0";
    }
    std::cout << "3" << std::endl;
    return response;
}

void Game::setAccess(std::string accessCode) {
    this->accessCode = accessCode;
}

GenericLinkedList<Player> *Game::getPlayers() {
    return this->players;
}


