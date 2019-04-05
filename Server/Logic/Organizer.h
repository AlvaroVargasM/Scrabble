//
// Created by jondorito on 26/03/19.
//

#ifndef QUEUE_USING_OOP_ORGANIZER_H
#define QUEUE_USING_OOP_ORGANIZER_H


#include <iostream>
#include <fstream>
#include <string>
#include "Dictionary.h"

using namespace std;


class Organizer {
private:
    ifstream fileReader;
    ofstream fileWriter;
    string path;
    string filename;
    Dictionary* currentWords;
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
public:
    Organizer(string, string);
    void createWordFiles();
    bool searchWord(string);
    bool searchByIndex(int, int, char, string);





};



#endif //QUEUE_USING_OOP_ORGANIZER_H
