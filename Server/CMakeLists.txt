cmake_minimum_required(VERSION 3.13)
project(Queue_using_OOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(Server main.cpp Tile.cpp Tile.h GameBoard.cpp GameBoard.h)