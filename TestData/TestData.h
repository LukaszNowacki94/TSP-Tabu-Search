//
// Created by lukasz on 12/11/16.
//

#ifndef TABU_SEARCH_TESTDATA_H
#define TABU_SEARCH_TESTDATA_H


#include <chrono>
#include "../TspTabuSearch/TspTabuSearch.h"
#include "../FileLoader/FileReader.h"

class TestData {
public:
    TestData();
    void testAsymTabuSearch(int numberOfTests, std::string filename);
    void testSymTabuSearch(int numberOfTests, std::string filename);
private:
    FileReader fileReader;
    std::chrono::steady_clock::time_point start,end;
};


#endif //TABU_SEARCH_TESTDATA_H
