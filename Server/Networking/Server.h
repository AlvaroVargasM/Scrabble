//
// Created by jondorito on 01/04/19.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H


#include "GenericLinkedList.h"
#include "../Logic/Game.h"

class Server {
public:
    Server();
    bool newGame = false;
private:
    GenericLinkedList<Game*>* games = new GenericLinkedList<Game*>();
    GenericLinkedList<std::string> *clientNames = new GenericLinkedList<std::string>();
    bool needNewGame();

};


#endif //SERVER_SERVER_H

