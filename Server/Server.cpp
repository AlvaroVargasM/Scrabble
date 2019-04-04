//
// Created by jondorito on 01/04/19.
//

#include "Server.h"
#include <iostream>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <netdb.h>
#include <unistd.h>
#include <thread>
#include "Game.h"
#include "SocketHandler.h"

using namespace std;

void handleClient(int* clientSocket) {
    char buf[4096];
    while (true)
    {
        memset(buf, 0, 4096);

        // Wait for client to send data
        int bytesReceived = recv(*clientSocket, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            cerr << "Error in recv(). Quitting" << endl;
            break;
        }

        if (bytesReceived == 0)
        {
            cout << "Client disconnected " << endl;
            break;
        }

        cout << string(buf, 0, bytesReceived) << endl;

        char* message = "Whatever you say";

        // Echo message back to client
        send(*clientSocket, message, strlen(message), 0);
    }

    // Close the socket
    close(*clientSocket);
}

Server::Server() {
    // Create a socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
    {
        cerr << "Can't create a socket! Quitting" << endl;
    }

    // Bind the ip address and port to a socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    bind(listening, (sockaddr*)&hint, sizeof(hint));

    // Tell Winsock the socket is for listening
    listen(listening, SOMAXCONN);

    this->games->add(*new Game());

    // Wait for a connection
    while(true) {

        if(needNewGame()){
            this->games->add(*new Game());
            this->newGame = false;
        }

        sockaddr_in client;
        socklen_t clientSize = sizeof(client);

        int clientSocket = accept(listening, (sockaddr *) &client, &clientSize);
        int* clientSocketPtr = &clientSocket;

        char host[NI_MAXHOST];      // Client's remote name
        char service[NI_MAXSERV];   // Service (i.e. port) the client is connect on

        memset(host, 0, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
        memset(service, 0, NI_MAXSERV);

        if (getnameinfo((sockaddr *) &client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
            cout << host << " connected on port " << service << endl;
        } else {
            inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
            cout << host << " connected on port " << ntohs(client.sin_port) << endl;
        }

        thread clientThread(&SocketHandler::handleClient, new SocketHandler(), clientSocketPtr);
        clientThread.detach();
    }

    // Close listening socket
    //close(listening);

    // While loop: accept and echo message back to client
    /*char buf[4096];

    while (true)
    {
        memset(buf, 0, 4096);

        // Wait for client to send data
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            cerr << "Error in recv(). Quitting" << endl;
            break;
        }

        if (bytesReceived == 0)
        {
            cout << "Client disconnected " << endl;
            break;
        }

        cout << string(buf, 0, bytesReceived) << endl;

        // Echo message back to client
        send(clientSocket, buf, bytesReceived + 1, 0);
    }

    // Close the socket
    close(clientSocket);*/
}

bool Server::needNewGame() {
    return this->newGame;
}
