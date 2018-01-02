//
// Created by lukasz on 12/10/16.
//

#include <cstdio>
#include "TabuList.h"

TabuList::TabuList(int size) {
    this->size = size+1;
    tabuList = new int* [size+1];
    for(int i = 0; i < size+1; i++){
        tabuList[i] = new int [size+1];
    }
    printf("SIZE: [%d]\n",size +1);
}

void TabuList::tabuMove(int city1, int city2) {
    tabuList[city1][city2] += 5;
    tabuList[city2][city1] += 5;

}

void TabuList::decrementTabu() {
    for(int i = 0 ; i< size ;i++)
    {
        for(int j = 0 ; j < size; j++) {
            tabuList[i][j] -=tabuList[i][j] <= 0 ? 0 : 1;
        }
    }
}

TabuList::TabuList() {}
