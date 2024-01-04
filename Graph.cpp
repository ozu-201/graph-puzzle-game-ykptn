//
// Created by yk034471 on 12/14/2023.
//

#include "Graph.h"
#include "Queue.h"
#include <string>
#include <iostream>
#include <algorithm>

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

    void Graph::addWord(const std::string& word) { //adds word to graph
        words.push_back(word);
        int wordIndex = words.size() - 1;
        for(int i = 0; i < wordIndex; i++) {
            const std::string& currentWord = words[i];
            if(currentWord.size() != word.size()) {
                continue;
            }
            int diffCount = 0; //finds differences
            for(int j = 0; j < word.size(); j++) {
                if(word[j] != currentWord[j]) {
                    diffCount++;
                }
            }
            if(diffCount == 1) { //if difference is one letter it adds a edge between them not directed
                addEdge(i,wordIndex);
                addEdge(wordIndex,i);
            }
        }
    }

    int Graph::getIndex(const std::string& word) { //finds the index of a word
        auto it = std::find(words.begin(), words.end(), word);
        if(it != words.end()) {
            return std::distance(words.begin(), it);
        }
        return -1;
    }

    void Graph::depthFirstSearch(bool *visited, int fromNode) {
        for (int toNode = 0; toNode < vertexCount; toNode++){
            if (edges[fromNode][toNode] > 0){
                if (!visited[toNode]){
                    visited[toNode] = true;
                    depthFirstSearch(visited, toNode);
                }
            }
        }
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

    std::vector<std::string> Graph::shortestPath(const std::string& start, const std::string& end) { //finds the shortest path from a word to another word
        int source = getIndex(start);
        int destination = getIndex(end);
        Path* shortestPaths = initializePaths(source); //like dijkstra
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++){
            heap.insert(HeapNode(shortestPaths[i].getDistance(), i));
        }
        while (!heap.isEmpty()){
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            for (int toNode = 0; toNode < vertexCount; toNode++){
                if(edges[fromNode][toNode] > 0) {
                    int newDistance = shortestPaths[fromNode].getDistance() + edges[fromNode][toNode];
                    if (newDistance < shortestPaths[toNode].getDistance()) {
                        int position = heap.search(toNode);
                        heap.update(position, newDistance);
                        shortestPaths[toNode].setDistance(newDistance);
                        shortestPaths[toNode].setPrevious(fromNode);
                    }
                }
            }
        }
        std::vector<std::string> pathList;
        int current = destination; //current word
        while(current != source) {
            pathList.push_back(words[current]);
            current = shortestPaths[current].getPrevious();
        }
        pathList.push_back(words[source]); //adds also the starting word
        std::reverse(pathList.begin(), pathList.end()); //reverses the array
        std::cout << "The shortest path from " << start << " to " << end << " is:" << std::endl;
        for(const std::string& word:pathList) { //prints the path
            std::cout << word << " ";
        }
        std::cout << std::endl;
        delete[] shortestPaths;
        return pathList;
    }

    Path *Graph::dijkstra(int source) {
        Path* shortestPaths = initializePaths(source);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++){
            heap.insert(HeapNode(shortestPaths[i].getDistance(), i));
        }
        while (!heap.isEmpty()){
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            for (int toNode = 0; toNode < vertexCount; toNode++){
                int newDistance = shortestPaths[fromNode].getDistance() + edges[fromNode][toNode];
                if (newDistance < shortestPaths[toNode].getDistance()){
                    int position = heap.search(toNode);
                    heap.update(position, newDistance);
                    shortestPaths[toNode].setDistance(newDistance);
                    shortestPaths[toNode].setPrevious(fromNode);
                }
            }
        }
        return shortestPaths;
    }

    Edge *Graph::edgeList(int &edgeCount) {
        Edge* list;
        edgeCount = 0;
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                if (edges[i][j] > 0){
                    edgeCount++;
                }
            }
        }
        list = new Edge[edgeCount];
        int index = 0;
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                if (edges[i][j] > 0){
                    list[index] = Edge(i, j, edges[i][j]);
                    index++;
                }
            }
        }
        return list;
    }
}
