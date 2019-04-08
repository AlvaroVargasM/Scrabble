//
// Created by jondorito on 01/04/19.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H


#include "GenericLinkedList.h"
#include "../Logic/Game.h"

/**
 * Class Server is in charge of running the server while on runtime, also has list of the games and the clientNames
 */
class Server {
public:
    Server();

private:
    GenericLinkedList<Game*>* games = new GenericLinkedList<Game*>();
    GenericLinkedList<std::string> *clientNames = new GenericLinkedList<std::string>();

};


#endif //SERVER_SERVER_H

