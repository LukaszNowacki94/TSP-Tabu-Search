//
// Created by lukasz on 12/5/16.
//

#ifndef TABU_SEARCH_FileReader_H
#define TABU_SEARCH_FileReader_H
#include <fstream>
#include <iostream>
#include <vector>

class  FileReader{
public:
    std::fstream file;

    FileReader();
    bool isOpen();
    void loadFile(std::string filename);
    std::tuple<int,std::vector<int>> returnSize();
};


#endif //TABU_SEARCH_FileReader_H
