#include <iostream>
#include "Tile.h"
#include "GameBoard.h"
#include "LinkedList.h"
#include "Organizer.h"
#include "Searcher.h"

int main(){
    // Game board is set
    GameBoard gb;
    Organizer* org = new Organizer("/home/alvar/CLionProjects/Scrabble/Server/Database/","ThisFile");
    gb.setOrganizer(org);
    gb.setLetters('.');
    gb.setCoordinates();

    std::cout << "\n";

    std::cout << "Setting multipliers \n";
    gb.setMultipliers(2, 3, 4, 5);
    gb.getMultipliers();

    gb.changeTile(7,7,'s',3);
    gb.changeTile(7,8,'t',4);
    gb.changeTile(7,9,'a',5);
    gb.changeTile(7,10,'r',6);
    gb.changeTile(7,11,'t',7);
    gb.changeTile(7,12,'e',8);
    gb.changeTile(7,13,'r',1);

    gb.changeTile(6,9,'l',5);
    gb.changeTile(8,9,'n',5);
    gb.changeTile(9,9,'d',5);


    std::cout << "\n";
    std::cout << "Setting letters in board \n";
    gb.getLetters();

    std::cout << "\n";

    LinkedList ll;
    ll.addLast(gb.getTile(7,8));
    ll.addLast(gb.getTile(7,9));
    ll.addLast(gb.getTile(7,10));
    ll.addLast(gb.getTile(7,11));
    std::cout << "Setting the list \n";
    ll.printList();

    std::cout << "\n";

    std::cout << "Word contained in the list: " << ll.getWord(ll) << "\n";
    std::cout << "\n";


    LinkedList l;
    l.addLast(gb.getTile(7,9));
    l.addLast(gb.getTile(8,9));
    l.printList();
    std::cout << l.getWord(l) << "\n";

    Searcher sea;
    sea.wordSearcher(ll,gb);
    sea.wordSearcher(l,gb);

    /*
    ll.deleteEndNode();
    ll.printList();// alvaro ya borra el ultimo nodo.
    ll.deleteFrontNode();
    ll.printList() ;
    ll.deleteEndNode();
    ll.deleteFrontNode();
    ll.printList() ;
    Organizer* org = new Organizer("/home/jondorito/Documents/Datos II/ScrabbleProject/Dictionaries/", "ThisFile.txt");
    */

    return 0;
}