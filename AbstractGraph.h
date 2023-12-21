//
// Created by yk034471 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_YKPTN_ABSTRACTGRAPH_H
#define GRAPH_PUZZLE_GAME_YKPTN_ABSTRACTGRAPH_H

#include "Path.h"

class AbstractGraph {
protected:
    int vertexCount;
    Path* initializePaths(int source) const;
public:
    explicit AbstractGraph(int vertexCount);
};


#endif //GRAPH_PUZZLE_GAME_YKPTN_ABSTRACTGRAPH_H
