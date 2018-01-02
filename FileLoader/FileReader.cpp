//
// Created by lukasz on 12/5/16.
//

#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <tuple>

FileReader::FileReader() {

}

bool FileReader::isOpen() {
    return file.is_open();
}

void FileReader::loadFile(std::string filename) {
    file.open(filename, std::ios_base::in);
    if(file.is_open())
        printf("OPENED\n");
    else
        printf("NOT OPENED \n");
}

std::tuple<int, std::vector<int>> FileReader::returnSize() {
   int size;
    file >> size;
    int x;
    std::vector<int> distance;
    while(file >> x)
        distance.push_back(x);

    return std::make_tuple(size,distance);

}



