//
// Created by yk034471 on 1/4/2024.
//
#include <Reader.h>
#include <iostream>

int main() {
    std::string filename = "C:\\Users\\TEMP\\Desktop\\EnglishDictionary.txt";
    Reader reader(filename);
    std::string start, end;
    std::cout << "Enter starting word: " << std::endl;
    std::getline(std::cin, start);
    std::cout << "Enter destination word: " << std::endl;
    std::getline(std::cin, end);
    reader.readToGraph(start,end);
    return 0;
}
