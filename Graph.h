//
// Created by yk034471 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_YKPTN_GRAPH_H
#define GRAPH_PUZZLE_GAME_YKPTN_GRAPH_H

#include "AbstractGraph.h"
#include "Path.h"
#include "Heap.h"
#include "MinHeap.h"
#include "HeapNode.h"
#include "Edge.h"
#include <string>
#include <vector>

namespace array {
    class Graph : public AbstractGraph {
    private:
        int **edges;

        std::vector<std::string> words;
    public:
        explicit Graph(int vertexCount);

        ~Graph();

        void addEdge(int from, int to);

        void addEdge(int from, int to, int weight);

        void addWord(const std::string& word);

        int getIndex(const std::string& word);

        std::vector<std::string> shortestPath(const std::string& start, const std::string& end);
    protected:
        void depthFirstSearch(bool* visited, int fromNode);

        void breadthFirstSearch(bool* visited, int startNode);

        Edge* edgeList(int& edgeCount);

        Path* dijkstra(int source);
    };
}


#endif //GRAPH_PUZZLE_GAME_YKPTN_GRAPH_H
