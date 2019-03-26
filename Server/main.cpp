#include <iostream>
#include "Tile.h"
#include "GameBoard.h"
#include "Word.h"
#include "Organizer.h"

int main(){
    // Game board is set
    GameBoard gb;

    gb.setLetters('.');

    std::cout << "\n";

    gb.setMultipliers(2, 3, 4, 5);
    gb.getMultipliers();

    gb.changeTile(7,7,'C');
    gb.changeTile(7,8,'A');
    gb.changeTile(7,9,'M');
    gb.changeTile(7,10,'I');
    gb.changeTile(7,11,'O');
    gb.changeTile(7,12,'N');

    std::cout << "\n";

    gb.getLetters();

    std::cout << "\n";

    // Linked list for getting words of in the game board

    Word ll;

    ll.addLast(gb.getTile(7,7));
    ll.addLast(gb.getTile(7,8));
    ll.addLast(gb.getTile(7,9));
    ll.addLast(gb.getTile(7,10));
    ll.addLast(gb.getTile(7,11));
    ll.addLast(gb.getTile(7,12));

    ll.printList();

    std::cout << ll.getWord(ll) << std::endl;

    Organizer* org = new Organizer("/home/jondorito/Documents/Datos II/ScrabbleProject/Dictionaries/", "ThisFile.txt");

    return 0;
}