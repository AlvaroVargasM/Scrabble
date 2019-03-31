#include "Searcher.h"
#include "LinkedList.h"
#include "Node.h"
#include "Organizer.h"
#include <array>

//Hola

Searcher::Searcher() {}

bool Searcher::wordSearcher(LinkedList InputWord, GameBoard gb) {
    Node* temp1 = InputWord.getHead();
    Node* temp2 = InputWord.getLastNode();

    if (InputWord.isHorizontal()) {
        while (temp2->getL() != '.'){
            std::cout << "Adding a new node at the end:\n";
            int i = temp2->getI();
            int j = temp2->getJ();
            InputWord.addLast(gb.getTile(i,++j));
            temp2 = temp2->getNext();
            InputWord.printList();
        }
        InputWord.deleteEndNode();

        while (temp1->getL() != '.'){
            std::cout << "Adding a new node at the begging:\n";
            int i = temp1->getI();
            int j = temp1->getJ();
            InputWord.addFront(gb.getTile(i,--j));
            temp1 = InputWord.getHead();
            InputWord.printList();
        }
        InputWord.deleteFrontNode();

    } else {
        while (temp2->getL() != '.') {
            std::cout << "Adding a new node at the begging:\n";
            int i = temp2->getI();
            int j = temp2->getJ();
            InputWord.addLast(gb.getTile(++i, j));
            temp2 = temp2->getNext();
            InputWord.printList();
        }
        InputWord.deleteEndNode();

        while (temp1->getL() != '.') {
            std::cout << "Adding a new node at the end:\n";
            int i = temp1->getI();
            int j = temp1->getJ();
            InputWord.addFront(gb.getTile(--i, j));
            temp1 = InputWord.getHead();
            InputWord.printList();
        }
        InputWord.deleteFrontNode();
    }

    std::cout << "\n\nExpanded word:\n";
    InputWord.printList();
    std::string word = InputWord.getWord();
    std::cout << word << "\n\n";


    if (gb.getOrganizer()->searchWord(word)) {
        //confirmedWords[0] = InputWord;
        return true;
    }
    return false;
}

int Searcher::pointsSearcher() {}