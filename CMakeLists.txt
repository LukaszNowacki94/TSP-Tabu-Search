cmake_minimum_required(VERSION 3.6)
project(tabu_search)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp FileLoader/FileReader.cpp FileLoader/FileReader.h TspTabuSearch/TspTabuSearch.cpp TspTabuSearch/TspTabuSearch.h TabuList/TabuList.cpp TabuList/TabuList.h Menu/Menu.cpp Menu/Menu.h TestData/TestData.cpp TestData/TestData.h)
add_executable(tabu_search ${SOURCE_FILES})