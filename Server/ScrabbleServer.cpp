//
// Created by jondorito on 27/03/19.
//

#include "ScrabbleServer.h"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>
#include <string.h>

using namespace std;

int ScrabbleServer::start() {
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if(listening == 1) {
        cerr << "Socket wasn't instanced correctly" << endl;
        return 1;
    }
    //Binding the socket to IP and Port
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    if (bind(listening, (sockaddr *)&hint, sizeof(hint)) == -1){
        cout << "Can't bind to IP/PORT" << endl;
    }

    if(listen(listening, SOMAXCONN) == -1){
        cout << "Can't listen" << endl;
        return -3;
    }

    //Accept client
    sockaddr_in client;
    socklen_t  clientSize;
    char host[NI_MAXHOST];
    char svc[NI_MAXSERV];

    int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);
    if(clientSocket == -1){
        cout << "Problem with client" << endl;
    }

    close(listening);

    memset(host, 0, NI_MAXHOST);
    memset(svc, 0, NI_MAXSERV);

    int result = getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, svc, NI_MAXSERV, 0);

    if(result){
        cout << host << " connected on " << svc << endl;
    }else{
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on " << ntohs(client.sin_port) << endl;
    }

    char buffer[4096];
    while(true){
        memset(buffer, 0, 4096);
        int bytesRecv = recv(clientSocket, buffer, 4096, 0);
        if(bytesRecv == -1){
            cout << "There was a connection issue" << endl;
            break;
        }

        if (bytesRecv == 0){
            cout << "Client disconnected" << endl;
        }

        cout << "Received: " << string(buffer, 0, bytesRecv) << endl;

        send(clientSocket, buffer, bytesRecv + 1, 0);
    }

    close(clientSocket);

}
