cmake_minimum_required(VERSION 3.13)
project(Queue_using_OOP)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS  -pthread)

add_executable(Server main.cpp Tile.cpp Tile.h GameBoard.cpp GameBoard.h Node.cpp Node.h Searcher.cpp Searcher.h Dictionary.cpp Dictionary.h Element.cpp Element.h Organizer.cpp Organizer.h Server.cpp Server.h JSONParser.cpp JSONParser.h LinkedList.h LinkedList.cpp Stack.cpp Stack.h PackTile.cpp PackTile.h Player.cpp Player.h NodeS.cpp NodeS.h GenericLinkedList.cpp GenericLinkedList.h GenericNode.cpp GenericNode.h Game.cpp Game.h SocketHandler.cpp SocketHandler.h)