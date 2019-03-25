//
// Created by jondorito on 16/03/19.
//

#ifndef UNTITLED1_ORGANIZER_H
#define UNTITLED1_ORGANIZER_H

#include <iostream>
#include <fstream>
#include <string>
#include "LInkedList.h"

using namespace std;


class Organizer {
private:
    ifstream fileReader;
    ofstream fileWriter;
    string path;
    string filename;
    LinkedList* currentWords;
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
public:
    Organizer(string, string);
    void createWordFiles();
    bool searchWord(string);
    bool searchByIndex(int, int, char, string);





};


#endif //UNTITLED1_ORGANIZER_H
