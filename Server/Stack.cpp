//
// Created by jonathangarcia on 30/03/19.
//
#include <iostream>
#include "Stack.h"
#include "Tile.h"

using namespace std;

Stack::Stack(int size) {

    arr=new Tile;

    capacity = size;
    top = -1;
}




// Utility function to add an element x in the stack
void Stack::push(Tile  x)
{
    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }


    arr[++top] = x;
}

// Utility function to pop top element from the stack
Tile Stack::pop()
{
    // check for stack underflow
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }



    // decrease stack size by 1 and (optionally) return the popped element
    return arr[top--];
}

// Utility function to return top element in a stack
Tile Stack::peek()
{
    if (!isEmpty())
        return arr[top];
    else
        exit(EXIT_FAILURE);
}

// Utility function to return the size of the stack
int Stack::size()
{
    return top + 1;
}

// Utility function to check if the stack is empty or not
bool Stack::isEmpty()
{
    return top == -1;	// or return size() == 0;
}

// Utility function to check if the stack is full or not
bool Stack::isFull()
{
    return top == capacity - 1;	// or return size() == capacity;
}

Tile Stack::swap(){


}