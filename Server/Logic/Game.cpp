#include <thread>
#include "Game.h"
#include "GameBoard.h"
#include "Searcher.h"
#include "Stack.h"
#include "../Networking/PackTile.h"
#include "LinkedList.h"
#include "../Networking/GenericLinkedList.h"

/**
 * The constructor for the Game class, it creates a GameBoard, for this it uses the parameter af a pointer to organizer,
 * a generic linked list of players and an access code.
 * @param organizer for the board
 */
Game::Game(Organizer *organizer) {
    this->board.setOrganizer(organizer);
    // Stack * stack = new Stack;
    this->players = new GenericLinkedList<Player>();
    Game* ptr = &(*this);
    this->accessCode = "";
}

/**
 * Adds a new player to the players variable
 * @param player
 */
void Game::addPlayer(Player* player) {
    this->players->add(*player);
}

/**
 * Gets the access code from the game
 * @return access code
 */
std::string* Game::getAccessCode() {
    return &this->accessCode;
}

/**
 * Gets the searcher of the game
 * @return searcher
 */
const Searcher &Game::getSearcher() const {
    return this->searcher;
}

/**
 * Sets the searcher of the game
 * @param searcher
 */
void Game::setSearcher(const Searcher &searcher) {
    Game::searcher = searcher;
}

/**
 * This method verifies a word, it checks for position, connections with other words, grammar and counts the points
 * for that word in the case the word passes all previous requirements to be qualified as a valid word.
 * @param p the array of PackTiles to form the word (LinkedList)
 * @return the response as a string, with "0" meaning that the word was not validated,
 * and "1,"+the word points, in string, when the word is validated
 */
std::string Game::verify(PackTile* p) {
    std::string response;
    LinkedList word;

    for(int i = 0;i < 7;i++) {
        if (p[i].getValue() != -1)
            word.addLast(p[i]);
    }

    if(!this->searcher.wordCorrectPosition(word))
        return (response = "0");
    std::cout << "\nThe word to verify has an accepted position\n";

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
    return response;
}

/**
 * Sets the access code of the game
 * @param accessCode
 */
void Game::setAccess(std::string accessCode) {
    this->accessCode = accessCode;
}

/**
 * Gets the player
 * @return
 */
GenericLinkedList<Player> *Game::getPlayers() {
    return this->players;
}

/**
 * Sets the game board
 * @param board
 */
void Game::setBoard(const GameBoard &board) {
    Game::board = board;
}

/**
 * gets the game board in game
 * @return game board
 */
GameBoard& Game::getBoard() {
    return this->board;
}
