//
// Created by yk034471 on 12/14/2023.
//

#include "Reader.h"
#include <fstream>
using namespace std;


Reader::Reader(const std::string& filename) : dictionaryFilename(filename) {}

void Reader::readToGraph(array::Graph& graph) {
    std::ifstream file(dictionaryFilename);
    if (file.is_open()) {
        std::string word;
        while (file >> word) {
        }
        file.close();
    } else {
    }
}

