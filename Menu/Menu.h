//
// Created by lukasz on 12/11/16.
//

#ifndef TABU_SEARCH_MENU_H
#define TABU_SEARCH_MENU_H


#include "../FileLoader/FileReader.h"
#include "../TspTabuSearch/TspTabuSearch.h"

class Menu {
   public:
    Menu();
    void showMainMenu();
    void showAsymMenu();
    void showSymMenu();
private:
    FileReader fileReader;

};


#endif //TABU_SEARCH_MENU_H
