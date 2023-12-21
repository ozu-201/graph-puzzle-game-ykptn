//
// Created by yk034471 on 12/14/2023.
//

#include "Reader.h"
#include "Graph.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


Reader::Reader(const std::string& filename) : dictionaryFilename(filename) {}

int Reader::countLetters(const std::string& word) {
    int count = 0;
    for(char letter : word) {
        if((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
            count++;
        }
        else if(letter >= -128 && letter <= -97) {
            count++;
        }
    }
    return count;
}

void Reader::readToGraph(const std::string& start, const std::string& end) {
    std::ifstream file(dictionaryFilename);
    if (file.is_open()) {
        std::string word;
        int count3letter = 0, count4letter = 0, count5letter = 0;
        while (file >> word) {
            if(countLetters(word) == 3) {
                count3letter++;
                word3List.push_back(word);
            }
            if(countLetters(word) == 4) {
                count4letter++;
                word4List.push_back(word);
            }
            if(countLetters(word) == 5) {
                count5letter++;
                word5List.push_back(word);
            }
        }
        file.close();
        array::Graph g3(count3letter);
        array::Graph g4(count4letter);
        array::Graph g5(count5letter);
        for(const std::string& word3 : word3List) {
            g3.addWord(word3);
        }
        for(const std::string& word4 : word4List) {
            g4.addWord(word4);
        }
        for(const std::string& word5 : word5List) {
            g5.addWord(word5);
        }
    } else {
        std::cout << "File couldn't open" << std::endl;
    }
}

