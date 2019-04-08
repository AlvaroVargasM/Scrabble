//
// Created by jondorito on 26/03/19.
//

//Hola

#include "Organizer.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <thread>

/**
 * This is the organizer constructor
 * @param path
 * @param filename
 */
Organizer::Organizer(std::string path, std::string filename) {
    this->path = path;
    this->filename = this->path + filename;
    createWordFiles();
}

/**
 * This function is in charge of creating the word.txt of each word by using a LinkedList with these words
 * @param letter
 * @param list
 * @param path
 */
void writeWordFiles(char* letter, Dictionary* list, std::string* path){
    std::ofstream writer;
    std::string newFile = "_words.txt";
    newFile.insert(0, 1, *letter);
    writer.open(*path + newFile);
    for(int i = 1; i <= list->getLength(); i++){
        writer << list->getIndex(i)->getData() << std::endl;
    }
}

/**
 * This function is in charge of creating the chart files for each word where one saves  quantity information related
 * to the specific letter
 * @param letter
 * @param list
 * @param path
 */
void writeChartFiles(char* letter, Dictionary* list, std::string* path){
    std::ofstream newWriter;
    std::string chartFile = "_chart.txt";
    chartFile.insert(0, 1, *letter);
    newWriter.open(*path + chartFile);
    int amount = 0;
    int numLetters = 1;
    int iniPosition = 0;
    int finalPosition = 0;
    for(int i = 1; i <= list->getLength(); i++){
        if(numLetters == list->getIndex(i)->getDataLength()) {
            amount++;
            finalPosition++;
        }else{
            newWriter << std::to_string(numLetters) << ',' << std::to_string(amount) << ',' << std::to_string(iniPosition) << ',' << std::to_string(finalPosition) << std::endl;
            amount = 0;
            numLetters++;
            finalPosition++;
            iniPosition = finalPosition;
        }
    }
}

/**
 * this function is the main process of for creating the documents, it is called when an organizer is created
 */
void Organizer::createWordFiles() {
    std::ifstream reader;
    reader.open(this->filename);
    std::string line;
    for(int i = 0; i < 26; i++){
        Dictionary* list = new Dictionary();
        while((reader >> line) && (line.at(0) == this->alphabet[i])){
            list->insertNode(line);
        }
        char* letter = &this->alphabet[i];
        std::string* path = &this->path;
        std::thread thread1(writeWordFiles, letter, list, path);
        std::thread thread2(writeChartFiles, letter, list, path);
        if(i != 25){
            thread1.detach();
            thread2.detach();
        }else{
            thread1.join();
            thread2.join();
        }
    }
}

/**
 * This function searches for a word by looking in the letter.txt file
 * @param word
 * @return bool
 */
bool Organizer::searchWord(std::string word){
    char letter = word.at(0);
    std::string filename = "_chart.txt";
    filename.insert(0, 1, letter);
    int num = word.size();
    std::ifstream reader;
    reader.open(this->path + filename);
    std::string line;
    int iniPos;
    int finalPos;
    while(reader >> line) {
        std::string numLetters = line.substr(0, line.find(','));
        if (atoi(numLetters.c_str()) == word.size()) {
            break;
        }
    }
    std::vector<std::string> placeholder;
    std::stringstream ss(line);
    while(ss.good()){
        std::string substr;
        getline(ss, substr, ',');
        placeholder.push_back(substr);
    }
    bool found = searchByIndex(atoi(placeholder[2].c_str()), atoi(placeholder[3].c_str()), letter, word);
    return found;
}


/**
 * This function uses two indexes to search between then and find the word
 * @param iPos
 * @param fPos
 * @param letter
 * @param word
 * @return bool
 */
bool Organizer::searchByIndex(int iPos, int fPos, char letter, std::string word){
    std::ifstream reader;
    std::string filename = "_words.txt";
    filename.insert(0, 1, letter);
    reader.open(this->path + filename);
    int marker = 0;
    std::string line;
    for(marker; marker != iPos; marker++){
        reader >> line;
    }
    for(marker; marker < fPos; marker++){
        reader >> line;
        if(word.compare(line)) {
            return true;
        }
    }
    return false;
}
