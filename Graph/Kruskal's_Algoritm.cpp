#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Edge {
public:
    int u, v, w;

    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }

    //comparator function to sort edges based on weight
    bool operator<(const Edge& other) const {
        return this->w < other.w;
    }
};


class Graph {
public:
    int V;
    vector<Edge> edges;
    vector<int> par, rank;    

    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back(Edge(u, v, w));
    }
};
