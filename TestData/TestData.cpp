#include "TestData.h"

////
//// Created by lukasz on 12/11/16.
////
//
#include <chrono>
#include <tuple>
#include "TestData.h"

void TestData::testAsymTabuSearch(int numberOfTests, std::string filename) {

}

void TestData::testSymTabuSearch(int numberOfTests, std::string filename) {
    fileReader.loadFile(filename);

    if(fileReader.isOpen()){

        std::tuple<int, std::vector<int>> values  = fileReader.returnSize();
        TspTabuSearch search(std::get<0>(values));
        search.loadSymetricDistance(std::get<1>(values));
        int sum  = 0;
        start = std::chrono::steady_clock::now();
        for(int i = 0 ; i < numberOfTests; i++) {
            sum+= search.getPathCost(search.returnResult());
        }
        end = std::chrono::steady_clock::now();
        std::cout<<"TOTAL TIME: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
        std::cout << "Time difference[microseconds] = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()/numberOfTests <<std::endl;
        std::cout << "Time difference[ns] = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - start).count()/numberOfTests <<std::endl;
        std::cout <<"AVERAGE DISTANCE = " << sum/numberOfTests<< std::endl;
    }
    fileReader.file.close();

}
TestData::TestData() {

}
