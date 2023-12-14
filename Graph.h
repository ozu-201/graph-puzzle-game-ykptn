//
// Created by yk034471 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_YKPTN_GRAPH_H
#define GRAPH_PUZZLE_GAME_YKPTN_GRAPH_H

#include "AbstractGraph.h"


namespace array {
    class Graph : public AbstractGraph {
    private:
        int **edges;
    public:
        explicit Graph(int vertexCount);

        ~Graph();

        void addEdge(int from, int to);

        void addEdge(int from, int to, int weight);
    protected:
        void breadthFirstSearch(bool* visited, int startNode);
    };
}


#endif //GRAPH_PUZZLE_GAME_YKPTN_GRAPH_H
