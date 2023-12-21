//
// Created by yk034471 on 12/21/2023.
//

#ifndef GRAPH_PUZZLE_GAME_YKPTN_MINHEAP_H
#define GRAPH_PUZZLE_GAME_YKPTN_MINHEAP_H


#include "Heap.h"

class MinHeap : public Heap{
protected:
    void percolateDown(int no) override;
    void percolateUp(int no) override;
public:
    explicit MinHeap(int N);
    void update(int k, int newValue) override;
};



#endif //GRAPH_PUZZLE_GAME_YKPTN_MINHEAP_H
