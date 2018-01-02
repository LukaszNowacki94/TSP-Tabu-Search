//
// Created by lukasz on 12/5/16.
//

#ifndef TABU_SEARCH_TSPTABUSEARCH_H
#define TABU_SEARCH_TSPTABUSEARCH_H


#include <vector>
#include "../TabuList/TabuList.h"

class TspTabuSearch {
public:
    int size;
    int numberOfIterations = 54;
    int tabuLength = 10;

    std::vector<int> bestResult;
    void loadAsymetricDistance(std::vector<int> weight);
    void loadSymetricDistance(std::vector<int> weight);
    TspTabuSearch(int size);

    TspTabuSearch();
    ~TspTabuSearch();

    std::vector<int> returnResult();
    std::vector<int> getInitialSolution();
    void displayDistance();
    int getPathCost(std::vector<int> path);
private:
    TabuList tabuList;
    int **distance;

    std::vector<int> swapCities(std::vector<int>,int,int);
    std::vector<int> getBestNeighbour(std::vector<int>);

};


#endif //TABU_SEARCH_TSPTABUSEARCH_H
