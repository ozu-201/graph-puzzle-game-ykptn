//
// Created by yk034471 on 12/21/2023.
//

#ifndef GRAPH_PUZZLE_GAME_YKPTN_HEAPNODE_H
#define GRAPH_PUZZLE_GAME_YKPTN_HEAPNODE_H


class HeapNode {
private:
    int data;
    int name;
public:
    HeapNode(int data, int name);
    HeapNode();
    int getData() const;
    int getName() const;
    void setData(int _data);
};



#endif //GRAPH_PUZZLE_GAME_YKPTN_HEAPNODE_H
