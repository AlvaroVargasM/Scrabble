#ifndef QUEUE_USING_OOP_ORGANIZER_H
#define QUEUE_USING_OOP_ORGANIZER_H


#include <iostream>
#include <fstream>
#include <string>
#include "Dictionary.h"


/**
 * Class organizer which manages the diccionaries
 */
class Organizer {
private:
    std::ifstream fileReader;
    std::ofstream fileWriter;
    std::string path;
    std::string filename;
    Dictionary* currentWords;
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

public:
    Organizer(std::string,std::string);

    void createWordFiles();

    bool searchWord(std::string);

    bool searchByIndex(int, int, char, std::string);
};


#endif //QUEUE_USING_OOP_ORGANIZER_H
