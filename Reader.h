//
// Created by yk034471 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_YKPTN_READER_H
#define GRAPH_PUZZLE_GAME_YKPTN_READER_H

#include "Graph.h"
#include "AbstractGraph.h"
#include <string>


class Reader {
public:
    Reader(const std::string& filename);
    void readToGraph(array::Graph& graph);
private:
    std::string dictionaryFilename;
};


#endif //GRAPH_PUZZLE_GAME_YKPTN_READER_H
