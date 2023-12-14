//
// Created by yk034471 on 12/14/2023.
//

#include "Graph.h"
#include "Queue.h"

namespace array {

    Graph::Graph(int vertexCount) : AbstractGraph(vertexCount) {
        edges = new int *[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            edges[i] = new int[vertexCount];
        }
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                edges[i][j] = 0;
            }
        }
    }

    Graph::~Graph() {
        for (int i = 0; i < vertexCount; i++) {
            delete[] edges[i];
        }
        delete[] edges;
    }

    void Graph::addEdge(int from, int to) {
        edges[from][to] = 1;
    }

    void Graph::addEdge(int from, int to, int weight) {
        edges[from][to] = weight;
    }
    void Graph::breadthFirstSearch(bool *visited, int startNode) {
        int fromNode;
        Queue queue = Queue(100);
        queue.enqueue( Element(startNode));
        while (!queue.isEmpty()){
            fromNode = queue.dequeue().getData();
            for (int toNode = 0; toNode < vertexCount; toNode++) {
                if (edges[fromNode][toNode] > 0) {
                    if (!visited[toNode]){
                        visited[toNode] = true;
                        queue.enqueue( Element(toNode));
                    }
                }
            }
        }
    }

}
