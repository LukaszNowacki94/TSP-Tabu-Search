#include <iostream>
#include <tuple>
#include "FileLoader/FileReader.h"
#include "TspTabuSearch/TspTabuSearch.h"
#include "TestData/TestData.h"
#include "Menu/Menu.h"

int main() {
    srand(time(NULL));
//    std::cout << "Hello, World!" << std::endl;
//    FileReader fileReader;
//    fileReader.loadFile("gr17.txt");
//    if(fileReader.isOpen()) {
//        std::tuple<int, std::vector<int>> values = fileReader.returnSize();
//        TspTabuSearch search(std::get<0>(values));
//        search.loadSymetricDistance(std::get<1>(values));
//        search.displayDistance();
//        std::vector<int> ret =  search.returnResult();
//
//        std::cout << "PATH COST: " <<search.getPathCost(ret) << std::endl;
//        for(int i =0 ; i < ret.size() -1;i++)
//        {
//            std::cout << ret[i] << " -> ";
//        }
//        std::cout << ret[ret.size()-1] << std::endl;
//    }
//    else
//        printf("Cannot load a file \n");
//    Menu menu;
//    menu.showMainMenu();
    TestData data;
    data.testSymTabuSearch(10,"abr17.txt");
//    data.testSymTabuSearch(10,"aft53.txt");
//    data.testSymTabuSearch(10,"akro124p.txt");
//    printf("KOniec \n");

    return 0;
}