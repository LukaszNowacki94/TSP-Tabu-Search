//
// Created by lukasz on 12/11/16.
//

#include <tuple>
#include "Menu.h"

void Menu::showSymMenu() {
    do {
        std::string fileName;
        printf("Give filename: ");
        std::cin >> fileName;
        fileReader.loadFile(fileName);
    }while(!fileReader.isOpen());
    std::tuple<int, std::vector<int>> values  = fileReader.returnSize();
    TspTabuSearch search(std::get<0>(values));
    search.loadSymetricDistance(std::get<1>(values));
    std::vector<int> ret =  search.returnResult();

    std::cout << "PATH COST: " <<search.getPathCost(ret) << std::endl;
    for(int i =0 ; i < ret.size() -1;i++)
    {
        std::cout << ret[i] << " -> ";
    }
    std::cout << ret[ret.size()-1] << std::endl;
}

Menu::Menu() {

}

void Menu::showMainMenu() {
    printf("1.TSP Tabu Search Symetric\n");
    printf("2.TSP Tabu Search Asymetric\n");
    printf("3.Quit\n");
    int n;
    std::cin >> n;
    switch(n){
        case 1: {
            showSymMenu();
            break;
        }
        case 2: {
            showAsymMenu();
        }
        case 3:{
            exit(0);
        }
    }
}

void Menu::showAsymMenu() {
    do {
        std::string fileName;
        printf("Give filename: ");
        std::cin >> fileName;
        fileReader.loadFile(fileName);
    }while(!fileReader.isOpen());
    std::tuple<int, std::vector<int>> values  = fileReader.returnSize();
    TspTabuSearch search(std::get<0>(values));
    search.loadAsymetricDistance(std::get<1>(values));
    std::vector<int> ret =  search.returnResult();

    std::cout << "PATH COST: " <<search.getPathCost(ret) << std::endl;
    for(int i =0 ; i < ret.size() -1;i++)
    {
        std::cout << ret[i] << " -> ";
    }
    std::cout << ret[ret.size()-1] << std::endl;
}


