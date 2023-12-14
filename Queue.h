//
// Created by yk034471 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_YKPTN_QUEUE_H
#define GRAPH_PUZZLE_GAME_YKPTN_QUEUE_H


#include "Element.h"

namespace array {

    class Queue {
    private:
        Element *array;
        int first;
        int last;
        int N;
    public:
        explicit Queue(int N);

        ~Queue();

        bool isFull() const;

        bool isEmpty() const;

        void enqueue(Element element);

        Element dequeue();
    };

}


#endif //GRAPH_PUZZLE_GAME_YKPTN_QUEUE_H
