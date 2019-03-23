#include <iostream>
#include "Tile.h"
#include "GameBoard.h"
#include "LinkedList.h"

int main(){

    GameBoard gb;

    gb.setGameBoardLetters('.');

    std::cout << "\n";

    gb.setGameBoardMultipliers(2,3,4,5);
    gb.getGameBoardMultipliers();

    gb.changeTile(7,7,'B');
    gb.changeTile(7,8,'O');
    gb.changeTile(7,9,'C');
    gb.changeTile(7,10,'A');

    gb.changeTile(8,7,'A');
    gb.changeTile(9,7,'N');
    gb.changeTile(10,7,'C');
    gb.changeTile(11,7,'O');

    std::cout << "\n";

    gb.getGameBoardLetters();

    std::cout << "\n";

    LinkedList ll;

    ll.addLast(gb.getTile(10,7));
    ll.addLast(gb.getTile(11,7));
    ll.addFront(gb.getTile(9,7));
    ll.addFront(gb.getTile(8,7));
    ll.addFront(gb.getTile(7,7));
    ll.addLast(gb.getTile(12,7));
    ll.addLast(gb.getTile(13,7));
    ll.printList();

    std::cout << ll.getWord(ll);

    return 0;
}