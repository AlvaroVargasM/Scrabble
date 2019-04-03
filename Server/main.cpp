#include <iostream>
#include "Tile.h"
#include "GameBoard.h"
#include "LinkedList.h"
#include "Organizer.h"
#include "Searcher.h"
#include "Stack.h"

int main(){
    // Game board and organizer are set
    GameBoard gb;
    Organizer* org = new Organizer("/home/alvar/CLionProjects/Scrabble/Server/Database/", "ThisFile.txt");
    gb.setOrganizer(org);

    std::cout << "\n";

    // Adding words to the board
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

    gb.changeTile(1,0,'f',8);
    gb.changeTile(1,1,'i',6);
    gb.changeTile(1,2,'s',5);
    gb.changeTile(1,3,'h',4);

    gb.getLetters();

    std::cout <<"\n";

    // Adding a new linked list formed from the board
    LinkedList lll;
    lll.addLast(gb.getTile(1,0));
    lll.addLast(gb.getTile(1,1));
    lll.addLast(gb.getTile(1,2));
    lll.addLast(gb.getTile(1,3));

    LinkedList ll;
    ll.addLast(gb.getTile(7,8));
    ll.addLast(gb.getTile(7,9));
    ll.addLast(gb.getTile(7,10));
    ll.addLast(gb.getTile(7,11));

    LinkedList l;
    l.addLast(gb.getTile(6,9));
    l.addLast(gb.getTile(7,9));
    l.addLast(gb.getTile(8,9));
    l.addLast(gb.getTile(9,9));


/*stack
 *test case
 * */
    Stack *stack= new Stack;

    stack->generate();//genera los Packtiles
    std::cout << stack->size();
   // stack->pop();  revienta  cuando va a sacar  un Packtile del stack



//
    std::cout <<"\n";





    // Searching for expanded words and connected words
    Searcher sea;

    LinkedList exw = (sea.wordExpand(ll, gb));

    if(sea.wordConnect(exw,gb)) {
        if(sea.wordVerify(exw,gb))
            std::cout << sea.wordPointCount();
    }
return 0;
}