//
// Created by jondorito on 04/04/19.
//

#ifndef QUEUE_USING_OOP_SOCKETHANDLER_H
#define QUEUE_USING_OOP_SOCKETHANDLER_H


#include <string>
#include <mutex>
#include "GenericLinkedList.h"
#include "../Logic/Game.h"

class SocketHandler {
public:
    SocketHandler(GenericLinkedList<std::string>*, GenericLinkedList<Game*>*, Organizer*);
    void handleClient(int*);
    bool registeredBefore(std::string*);
    Game* searchForUser(std::string*);
    std::string handleJSON(std::string*);
private:
    std::string token;
    GenericLinkedList<std::string>* usernames;
    GenericLinkedList<Game*>* games;
    Organizer* org;

};


#endif //QUEUE_USING_OOP_SOCKETHANDLER_H
