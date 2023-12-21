//
// Created by yk034471 on 12/14/2023.
//

#include <climits>
#include "AbstractGraph.h"

AbstractGraph::AbstractGraph(int vertexCount) {
    this->vertexCount = vertexCount;
}
Path *AbstractGraph::initializePaths(int source) const {
    Path* paths = new Path[vertexCount];
    for (int i = 0; i < vertexCount; i++){
        paths[i] = Path(INT_MAX, -1);
    }
    paths[source].setDistance(0);
    return paths;
}

