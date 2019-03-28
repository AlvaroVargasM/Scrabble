#include "Searcher.h"
#include "LinkedList.h"
#include "Node.h"
#include "Organizer.h"

Searcher::Searcher() {
    //LinkedList confirmedWords[16];
}

bool Searcher::wordSearcher(LinkedList InputWord, GameBoard gb) {
    Node * temp1 = InputWord.getHead();
    Node * temp2 = InputWord.getLastNode(InputWord);
    if (InputWord.isHorizontal(InputWord)) {
        while (temp2->getL() != '.') {
            int i = temp2->getI();
            int j = temp2->getJ();
            InputWord.addLast(gb.getTile(i,++j));
        }
        while (temp1->getL() != '.') {
            int i = temp1->getI();
            int j = temp1->getJ();
            InputWord.addLast(gb.getTile(i,--j));
        }
    }
    else {
        while (temp2->getL() != '.') {
            int i = temp2->getI();
            int j = temp2->getJ();
            InputWord.addLast(gb.getTile(++i,j));
        }
        while (temp1->getL() != '.') {
            int i = temp1->getI();
            int j = temp1->getJ();
            InputWord.addLast(gb.getTile(--i,j));
        }
    }

    if (InputWord.getWord(InputWord)) {
        confirmedWords[0] = InputWord;
    }
}

int Searcher::pointsSearcher() {

}