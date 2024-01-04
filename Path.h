//
// Created by yk034471 on 12/21/2023.
//

#ifndef GRAPH_PUZZLE_GAME_YKPTN_PATH_H
#define GRAPH_PUZZLE_GAME_YKPTN_PATH_H


class Path {
private:
    int distance;
    int previous;
public:
    Path(int distance, int previous);
    Path() = default;
    int getDistance() const;
    void setDistance(int _distance);
    void setPrevious(int _previous);
    int getPrevious() const;
};


#endif //GRAPH_PUZZLE_GAME_YKPTN_PATH_H
