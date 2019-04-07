cmake_minimum_required(VERSION 3.13)
project(Queue_using_OOP)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS  -pthread)

add_executable(Server main.cpp Logic/Tile.cpp Logic/Tile.h Logic/GameBoard.cpp Logic/GameBoard.h Logic/Node.cpp Logic/Node.h Logic/Searcher.cpp Logic/Searcher.h Logic/Dictionary.cpp Logic/Dictionary.h Logic/Element.cpp Logic/Element.h Logic/Organizer.cpp Logic/Organizer.h Networking/Server.cpp Networking/Server.h Networking/JSONParser.cpp Networking/JSONParser.h Logic/LinkedList.h Logic/LinkedList.cpp Logic/Stack.cpp Logic/Stack.h Networking/PackTile.cpp Networking/PackTile.h Logic/Player.cpp Logic/Player.h Logic/NodeS.cpp Logic/NodeS.h Networking/GenericLinkedList.cpp Networking/GenericLinkedList.h Networking/GenericNode.cpp Networking/GenericNode.h Logic/Game.cpp Logic/Game.h Networking/SocketHandler.cpp Networking/SocketHandler.h NetPackage.cpp NetPackage.h)