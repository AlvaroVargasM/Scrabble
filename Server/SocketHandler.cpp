//
// Created by jondorito on 04/04/19.
//

#include "SocketHandler.h"
#include <iostream>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <netdb.h>
#include <unistd.h>

void SocketHandler::handleClient(int * clientSocket) {
    char buf[4096];
    while (true)
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

        std::cout << std::string(buf, 0, bytesReceived) << std::endl;

        char* message = "Whatever you say";

        // Echo message back to client
        send(*clientSocket, message, strlen(message), 0);
    }

    // Close the socket
    close(*clientSocket);
}
