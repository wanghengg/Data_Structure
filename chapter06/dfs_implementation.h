#ifndef DATA_STRUCTURE_DFS_IMPLEMENTATION_H
#define DATA_STRUCTURE_DFS_IMPLEMENTATION_H

#include "graph.h"

template<typename Tv, typename Te>
void Graph<Tv, Te>::dfs(int s) {
    reset();
    int clock = 0;
    int v = s;
    do {
        if (UNDISCOVERED == status(v)) {
            DFS(v, clock);
        }
    } while (s != (v = (++v % n)));
}

template<typename Tv, typename Te>
void Graph<Tv, Te>::DFS(int v, int &clock) {
    dTime(v) = ++clock;
    status(v) = DISCOVERED;
    for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) {
        switch (status(u)) {
            case UNDISCOVERED:
                type(v, u) = TREE;
                parent(u) = v;
                DFS(u, clock);
                break;
            case DISCOVERED:
                type(v, u) = BACKWARD;
                break;
            default:
                type(v, u) = (dTime(v) < dTime(u)) ? CROSS : FORWARD;
                break;
        }
    }
    status(v) = VISITED;
    fTime(v) = ++clock;
}

#endif //DATA_STRUCTURE_DFS_IMPLEMENTATION_H
