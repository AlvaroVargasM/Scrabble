//
// Created by jondorito on 26/03/19.
//

//Hola

#include "Organizer.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <thread>

/**
 * This is the organizer constructor
 * @param path
 * @param filename
 */
Organizer::Organizer(string path, string filename) {
    this->path = path;
    this->filename = this->path + filename;
    createWordFiles();
}

void writeWordFiles(char* letter, Dictionary* list, string* path){
    ofstream writer;
    string newFile = "_words.txt";
    newFile.insert(0, 1, *letter);
    writer.open(*path + newFile);
    for(int i = 1; i <= list->getLength(); i++){
        writer << list->getIndex(i)->getData() << endl;
    }
}

void writeChartFiles(char* letter, Dictionary* list, string* path){
    ofstream newWriter;
    string chartFile = "_chart.txt";
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
            newWriter << to_string(numLetters) << ',' << to_string(amount) << ',' << to_string(iniPosition) << ',' << to_string(finalPosition) << endl;
            amount = 0;
            numLetters++;
            finalPosition++;
            iniPosition = finalPosition;
        }
    }
}

void Organizer::createWordFiles() {
    ifstream reader;
    reader.open(this->filename);
    string line;
    for(int i = 0; i < 26; i++){
        Dictionary* list = new Dictionary();
        while((reader >> line) && (line.at(0) == this->alphabet[i])){
            list->insertNode(line);
        }
        char* letter = &this->alphabet[i];
        string* path = &this->path;
        thread thread1(writeWordFiles, letter, list, path);
        thread thread2(writeChartFiles, letter, list, path);
        if(i != 25){
            thread1.detach();
            thread2.detach();
        }else{
            thread1.join();
            thread2.join();
        }
    }
}

bool Organizer::searchWord(string word){
    char letter = word.at(0);
    string filename = "_chart.txt";
    filename.insert(0, 1, letter);
    int num = word.size();
    ifstream reader;
    reader.open(this->path + filename);
    string line;
    int iniPos;
    int finalPos;
    while(reader >> line) {
        string numLetters = line.substr(0, line.find(','));
        if (atoi(numLetters.c_str()) == word.size()) {
            break;
        }
    }
    vector<string> placeholder;
    stringstream ss(line);
    while(ss.good()){
        string substr;
        getline(ss, substr, ',');
        placeholder.push_back(substr);
    }
    bool found = searchByIndex(atoi(placeholder[2].c_str()), atoi(placeholder[3].c_str()), letter, word);
    return found;
}

bool Organizer::searchByIndex(int iPos, int fPos, char letter, string word){
    ifstream reader;
    string filename = "_words.txt";
    filename.insert(0, 1, letter);
    reader.open(this->path + filename);
    int marker = 0;
    string line;
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
