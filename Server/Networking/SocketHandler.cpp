//
// Created by jondorito on 04/04/19.
//
#define RAPIDJSON_HAS_STDSTRING 1

#include "SocketHandler.h"
#include "GenericLinkedList.h"
#include <iostream>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <netdb.h>
#include <unistd.h>
#include <mutex>
#include "../libraries/rapidjson/document.h"
#include "../NetPackage.h"
#include <vector>
#include <sstream>
#include "PackTile.h"

/**
 * Sets the pointers for the list of games, usernames and org
 * @param usernames
 * @param games
 * @param org
 */
SocketHandler::SocketHandler(GenericLinkedList<std::string> *usernames, GenericLinkedList<Game*>* games, Organizer* org) {
    this->usernames = usernames;
    this->games = games;
    this->org = org;
}

/**
 * Searches for an specific user within the game instances
 * @param user
 * @return Game*
 */
Game* SocketHandler::searchForUser(std::string* user) {
    for(int i = 0; i < *this->games->getLength(); i++){
        Game* temp = this->games->get(i)->getData();
        for(int j = 0; i < *temp->getPlayers()->getLength(); i++){
            if(temp->getPlayers()->get(j)->getData().getName() == *user){
                return temp;
            }
        }
    }
    return nullptr;
}

/**
 * This functions checks whether a user has been registered before or not
 * @param user
 * @return bool
 */
bool SocketHandler::registeredBefore(std::string* user){
    for(int i = 0; i < *this->usernames->getLength(); i++){
        if(this->usernames->get(i)->getData() == *user){
            return true;
        }
    }return false;
}


/**
 * This functions handle the socket related to an specific client
 * @param clientSocket
 */
void SocketHandler::handleClient(int * clientSocket) {
    char buf[4096];
    do
    {
        memset(buf, 0, 4096);

        // Wait for client to send data
        int bytesReceived = recv(*clientSocket, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            std::cerr << "Error in recv(). Quitting" << std::endl;
            break;
        }

        if (bytesReceived == 0)
        {
            std::cout << "Client disconnected " << std::endl;
            break;
        }

        std::string inMessage = std::string(buf, 0, bytesReceived);

        std::string response = handleJSON(&inMessage);




        std::cout << std::string(buf, 0, bytesReceived) << std::endl;

        // Echo message back to client
        send(*clientSocket, response.c_str(), response.size(), 0);
    }while(true);

    // Close the socket
    close(*clientSocket);
}


/**
 * This function handle the json command depending on the command key on an specific json
 * @param json
 * @return std::string
 */
std::string SocketHandler::handleJSON(std::string *json) {
    rapidjson::Document doc;
    doc.Parse(*json);
    NetPackage *netpack = new NetPackage();
    netpack->setFrom("Server");
    std::string command = doc["NetPackage"]["command"].GetString();
    std::string user = doc["NetPackage"]["from"].GetString();
    std::string data = doc["NetPackage"]["data"].GetString();
    if(command == "register") {
        std::string user = doc["NetPackage"]["from"].GetString();
        if (this->usernames->getLength() != 0) {
            if (registeredBefore(&user)) {
                netpack->setCommand("DENIED");
                netpack->setData("false");
            } else {
                this->usernames->add(user);
                netpack->setData("true");
                netpack->setCommand("CONFIRMATION");
            }
            return netpack->getJSONPackage();
        }else{
            this->usernames->add(user);
            netpack->setData("true");
            netpack->setCommand("CONFIRMATION");
            return netpack->getJSONPackage();
        }
    }
    if(command=="CREATE"){
        Game* temp = new Game(this->org);
        this->games->add(temp);
        std::string code = to_string(*this->games->getLength());
        temp->setAccess(code);
        Player* p1 = new Player();
        p1->setName(user);
        temp->addPlayer(p1);
        netpack->setCommand("CREATED");
        netpack->setData(code);
        return netpack->getJSONPackage();
    }
    if(command == "SEARCH"){
        for(int i = 0; i < *this->games->getLength(); i++){
            std::cout << *this->games->get(i)->getData()->getAccessCode() << ',' << data << endl;
            if(*this->games->get(i)->getData()->getAccessCode() == data){
                netpack->setCommand("CREATED");
                netpack->setData("true");
                return netpack->getJSONPackage();
            }
        }
        netpack->setCommand("INVALID");
        netpack->setData("false");
        return netpack->getJSONPackage();
    }
    if(command == "VERIFY"){
        std::cout << "si es verify" << std::endl;
        Game* temp = searchForUser(&user);
        if(temp != nullptr){
            //PackTile *tiles = convertToPackTileObject(data);
            //std::cout << tiles->getLetter() << std::endl;
            //std::string result = temp->verify(tiles);
            std::cout << "si devolvio resultado";
           // netpack->setData(result);
            netpack->setCommand("VALIDATED");
            return netpack->getJSONPackage();
        }
    }

}
