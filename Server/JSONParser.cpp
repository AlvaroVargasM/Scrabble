//
// Created by jondorito on 29/03/19.
//

#include "JSONParser.h"
#include <string>
#include "Tile.h"
#include <iostream>

using namespace std;

JSONParser::JSONParser() {

}

string JSONParser::parseBoard(GameBoard board) {
    int n = 0;
    int m = 0;
    this->json = "{board{Tiles:";
    cout << "Voy a parsear" << endl;
    for(int i = 0; i < 225; i++){
        if(m == 14){
            n++;
            m = 0;
        }else{
            m++;
        }
        this->json += "tile:";
        Tile current = board.getTile(n, m);
        string letter = to_string(current.getLetter());
        string multiplier = to_string(current.getMultiplier());
        string wordMultiplier = to_string(current.isWordMultiplier());
        string points = to_string(current.getPoints());
        string blocked = to_string(current.isBlocked());
        string final = letter + ',' + multiplier + ',' + wordMultiplier + ',' + points + ',' + blocked;
        this->json += final;
        cout << "Iteracion numero " << i << " N es " << n << " M es " << m << endl;
    }
    this->json += "}}";
    cout << this->json << endl;
}
