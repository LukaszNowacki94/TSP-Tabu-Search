//
// Created by lukasz on 12/10/16.
//

#ifndef TABU_SEARCH_TABULIST_H
#define TABU_SEARCH_TABULIST_H


class TabuList {
public:
    int ** tabuList;
    TabuList(int size);

    TabuList();

    void tabuMove(int, int);
    void decrementTabu();
private:
    int size;
};


#endif //TABU_SEARCH_TABULIST_H
