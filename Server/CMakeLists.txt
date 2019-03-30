cmake_minimum_required(VERSION 3.13)
project(Queue_using_OOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(Server main.cpp Tile.cpp Tile.h GameBoard.cpp GameBoard.h Node.cpp Node.h Searcher.cpp Searcher.h Dictionary.cpp Dictionary.h Element.cpp Element.h Organizer.cpp Organizer.h ScrabbleServer.cpp ScrabbleServer.h JSONParser.cpp JSONParser.h LinkedList.h LinkedList.cpp)