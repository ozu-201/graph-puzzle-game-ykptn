cmake_minimum_required(VERSION 3.25)
project(graph_puzzle_game_ykptn)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(graph_puzzle_game_ykptn
        AbstractGraph.cpp
        AbstractGraph.h
        Graph.cpp
        Graph.h
        Reader.cpp
        Reader.h Queue.h Queue.cpp Element.cpp Path.cpp Path.h MinHeap.cpp MinHeap.h Heap.cpp Heap.h HeapNode.cpp HeapNode.h Edge.cpp Edge.h main.cpp)
