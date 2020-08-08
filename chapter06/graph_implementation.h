#ifndef DATA_STRUCTURE_GRAPH_IMPLEMENTATION_H
#define DATA_STRUCTURE_GRAPH_IMPLEMENTATION_H

#include "../chapter02/Vector.h"
#include "graph.h"

template <typename Tv> struct Vertex{
    Tv data;
    int inDegree, outDegree;
    VStatus status;
    int dTime, fTime;
    int parent;
    int priority;
    Vertex(Tv const &d = (Tv)0) :
            data(d), inDegree(0), outDegree(0), status(UNDISCOVERED),
            dTime(-1), fTime(-1), parent(-1), priority(INT_MAX) {}
};

template <typename Te> struct Edge{
    Te data;
    int weight;
    EType type;
    Edge(Te const &d, int w) :
            data(d), weight(w), type(UNDETERMINED) {}
};

template<typename Tv, typename Te>
class GraphMatrix : public Graph<Tv, Te> {
private:
    Vector<Vertex<Tv>> V;   // 顶点集合
    Vector<Vector<Edge<Te>*>> E;    // 边集(邻接矩阵)
public:
    GraphMatrix() { this->n = this->e = 0; }
    ~GraphMatrix() {
        for (int j = 0; j < this->n; j++) {
            for (int k = 0; k < this->n; k++) {
                delete E[j][k];
            }
        }
    }

    // 顶点的基本操作
    virtual Tv& vertex(int i) { return V[i].data; } // 数据
    virtual int inDegree(int i) { return V[i].inDegree; } // 入度
    virtual int outDegree(int i) { return V[i].outDegree; } // 出度
    virtual int firstNbr(int i) { return nextNbr(i, this->n); } // 首个邻接顶点
    virtual int nextNbr(int i, int j)
    {
        while ((-1 < j) && (!exists(i, --j)))
            return j;
    }
    virtual VStatus &status(int i) { return V[i].status; }
    virtual int& dTime(int i) { return V[i].dTime; }
    virtual int& fTime(int i) { return V[i].fTime; }
    virtual int& parent(int i) { return V[i].parent; }
    virtual int& priority(int i) { return V[i].priority; }

    // 顶点的动态操作
    virtual int insert(Tv const& vertex) {
        for (int j = 0; j < this->n; j++)
            E[j].insert(nullptr);
        this->n++;
        E.insert(Vector<Edge<Te>*>(this->n, this->n, (Edge<Te>*) nullptr));
        return V.insert(Vertex<Tv>(vertex));
    }

    virtual Tv remove(int i) {
        for (int j = 0; j < this->n; j++) {
            if (exists(i, j)) {
                delete E[i][j];
                V[j].inDegree--;
            }
        }
        E.remove(i);
        this->n--;
        Tv vBak = vertex(i);
        V.remove(i);
        for (int j = 0; j < this->n; j++) {
            if (Edge<Te> *e = E[j].remove(i)) {
                delete e;
                V[j].outDegree--;
            }
        }
        return vBak;
    }

    // 边的操作
    virtual bool exists(int i, int j) {
        return (0 <= i) && (i < this->n) && (0 <= j) && (j < this->n) && (E[i][j] != nullptr);
    }

    virtual EType& type(int i, int j) { return E[i][j]->type; }
    virtual Te& edge(int i, int j) { return E[i][j]->data; }
    virtual int& weight(int i, int j) { return E[i][j]->weight; }

    // 边的动态操作
    virtual void insert(Te const& edge, int w, int i, int j) {  // 插入权重为w的边e = (i, j)
        if (exists(i, j))
            return;
        E[i][j] = new Edge<Te>(edge, w);
        this->e++;
        V[i].outDegree++;
        V[j].inDegree++;
    }

    virtual Te remove(int i, int j) {
        Te eBak = edge(i, j);
        delete E[i][j];
        E[i][j] = nullptr;
        this->e--;
        V[i].outDegree--;
        V[j].inDegree--;
        return eBak;
    }
};

#endif //DATA_STRUCTURE_GRAPH_IMPLEMENTATION_H
