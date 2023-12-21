//
// Created by yk034471 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_YKPTN_READER_H
#define GRAPH_PUZZLE_GAME_YKPTN_READER_H

#include "Graph.h"
#include "AbstractGraph.h"
#include <string>
#include <vector>


class Reader {
public:
    Reader(const std::string& filename);
    void readToGraph(const std::string& start, const std::string& end);
    int countLetters(const std::string& word);
private:
    std::string dictionaryFilename;
    std::vector<std::string> word3List;
    std::vector<std::string> word4List;
    std::vector<std::string> word5List;
};


#endif //GRAPH_PUZZLE_GAME_YKPTN_READER_H
