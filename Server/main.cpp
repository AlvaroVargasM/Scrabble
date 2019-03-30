#include <iostream>
#include "Tile.h"
#include "GameBoard.h"
#include "LinkedList.h"
#include "Organizer.h"

int main(){
    // Game board is set
    GameBoard gb;

    gb.setLetters('.');

    gb.setCoordinates();
    gb.getCoordinates();

    std::cout << "\n";

    gb.setMultipliers(2, 3, 4, 5);
    gb.getMultipliers();

    gb.changeTile(7,7,'C',3);
    gb.changeTile(7,8,'A',4);
    gb.changeTile(7,9,'M',5);
    gb.changeTile(7,10,'I',6);
    gb.changeTile(7,11,'O',7);
    gb.changeTile(7,12,'N',8);


    std::cout << "\n";

    gb.getLetters();

    std::cout << "\n";

    // Linked list for getting words of in the game board

    LinkedList ll;

    ll.addLast(gb.getTile(7,7));
    ll.addLast(gb.getTile(7,8));
    ll.addLast(gb.getTile(7,9));
    ll.addLast(gb.getTile(7,10));
    ll.addLast(gb.getTile(7,11));
    ll.addLast(gb.getTile(7,12));


    ll.printList();
    std::cout << ll.getWord(ll) << "\n";
    std::cout << ll.getPoints(ll) << "\n";
    std::cout << ll.isHorizontal(ll) << "\n";

    std::cout << ll.getWord(ll) << std::endl;
    ll.deleteEndNode();
    ll.printList();// alvaro ya borra el ultimo nodo.
    ll.deleteFrontNode();
    ll.printList() ;
    ll.deleteEndNode();
    ll.deleteFrontNode();
    ll.printList() ;


    Organizer* org = new Organizer("/home/jondorito/Documents/Datos II/ScrabbleProject/Dictionaries/", "ThisFile.txt");

    return 0;
}