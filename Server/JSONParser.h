//
// Created by jondorito on 29/03/19.
//

#ifndef QUEUE_USING_OOP_JSONPARSER_H
#define QUEUE_USING_OOP_JSONPARSER_H

#include <string.h>
#include <string>
#include <stdlib.h>
#include "GameBoard.h"

using namespace std;


class JSONParser {
public:
    string parseBoard(GameBoard);
    JSONParser();

private:
    string json;


};


#endif //QUEUE_USING_OOP_JSONPARSER_H
