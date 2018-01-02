//
// Created by lukasz on 12/5/16.
//

#include <cstdio>
#include <cstdlib>
#include <climits>
#include "TspTabuSearch.h"
#include <algorithm>
void TspTabuSearch::loadSymetricDistance(std::vector<int> distance_values) {
    int counter = 0;
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < i +1 ;j++){
                distance[i][j] = distance[j][i] = distance_values[counter++];
        }
    }
}

void TspTabuSearch::loadAsymetricDistance(std::vector<int> distance) {
    int counter = 0;
    for(int i = 0 ; i < size; i++)
    {
        for(int j = 0 ; j < size; j++){
            this->distance[i][j] = distance[counter++];
        }
    }

}

TspTabuSearch::TspTabuSearch(int size) {
    this->size = size;
    printf("SIZE: [%d] \n",size);
    distance = new int*[size];
    for(int i = 0 ; i < size; i++){
        distance[i] = new int[size];
    }
    tabuList = TabuList(size);
}

std::vector<int> TspTabuSearch::returnResult() {
    std::vector<int> returnResult =  getInitialSolution();;
    int returnCost = getPathCost(returnResult);
     bestResult = returnResult;
    for(int x = 0 ; x < returnResult.size(); x++) {
        int bestCost = getPathCost(bestResult);
        int city1 = 0;
        int city2 = 0;
        bool firstNeighbor = true;
//        for (int i = 0; i < bestResult.size(); i++) {
//            for (int j = 1; j < bestResult.size(); j++) {
//                if (i == j)
//                    continue;
            int x1,x2;
            do {
                x1 = rand() % bestResult.size();
                x2 = rand() % bestResult.size();
            }while(x1 == x2);
//                std::vector<int> newBestSol = swapCities(bestResult, i, j);
                std::vector<int> newBestSol = swapCities(bestResult, x1, x2);
                int newBestCost = getPathCost(newBestSol);
//                if ((newBestCost > bestCost  || firstNeighbor) && tabuList.tabuList[i][j] == 0) {
                if ((newBestCost > bestCost  || firstNeighbor) && tabuList.tabuList[x1][x2] == 0) {
                    firstNeighbor = false;
//                    city1 = i;
                    city1 = x1;
//                    city2 = j;
                    city2 = x2;
                    bestResult = newBestSol;
                    bestCost = newBestCost;
                }

              //      tabuList.tabuMove(city1, city2);

//            }

//        }
        if (city1 != 0) {
            tabuList.decrementTabu();
            tabuList.tabuMove(city1, city2);
        }
        if(bestCost < returnCost) {
            returnResult = bestResult;
            returnCost = bestCost;
        }
    }
    return returnResult;
}

void TspTabuSearch::displayDistance() {
    for(int i = 0 ; i < size; i++){
        for(int j = 0 ; j < size; j++){
            printf("%d \t",distance[i][j]);
        }
        printf("\n");
    }

}

std::vector<int> TspTabuSearch::getInitialSolution() {
    bool *isCityAlreadyVisited = new bool[size];
    for(int i = 0 ; i < size; i++) {
        isCityAlreadyVisited[i] = false;
    }
    struct {
        int city;
        int weight;
    } nextPotentialCity;
    std::vector<int> initSolution;
    int x = rand() % size;
    initSolution.push_back(x);
    isCityAlreadyVisited[x] = true;
    int lastCity = x;
    while(initSolution.size() != size){
        nextPotentialCity.weight = INT_MAX;
        for(int i = 0 ; i < size; i++){
            if(!isCityAlreadyVisited[i] && distance[lastCity][i] < nextPotentialCity.weight && lastCity != i){
                nextPotentialCity.weight = distance[lastCity][i];
                nextPotentialCity.city = i;
            }
        }
        lastCity = nextPotentialCity.city;
        isCityAlreadyVisited[nextPotentialCity.city] = true;
        initSolution.push_back(nextPotentialCity.city);
    }
    initSolution.push_back(initSolution[0]);
    return initSolution;
}

int TspTabuSearch::getPathCost(std::vector<int> path) {
    int cost = 0;
    for(int i = 0 ; i < path.size() -1; i++) {
        cost+= distance[path[i]][path[i+1]];
    }
    return cost;
}

std::vector<int> TspTabuSearch::swapCities(std::vector<int> currentPath,int city1,int city2) {

        std::swap(currentPath[city1],currentPath[city2]);
    if(currentPath[0] != currentPath[currentPath.size()-1]) {
        currentPath[currentPath.size()-1] = currentPath[0];
    }
    return currentPath;
}

std::vector<int> TspTabuSearch::getBestNeighbour(std::vector<int> currentPath) {
    return std::vector<int>();
}

TspTabuSearch::TspTabuSearch() {}

TspTabuSearch::~TspTabuSearch() {
    printf("Deleting array");
    for(int i =0 ; i < size; i++){
            delete [] distance[i];
    }
    delete [] distance;

}
