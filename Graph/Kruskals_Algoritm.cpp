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

        for(int i=0; i<V; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void addEdge(int u, int v, int w) {
        edges.push_back(Edge(u, v, w));
    }

    int find(int x) {
        if(par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }

    void unionByRank(int a, int b) {
        int parA = find(a);
        int parB = find(b);
        if(parA == parB) return;

        if(rank[parA] == rank[parB]) {
            par[parA] = parB;
            rank[parB]++;
        } else if(rank[parA] < rank[parB]) {
            par[parA] = parB;
        } else {
            par[parB] = parA;
        }
    }

    void kruskal() {  // O(ElogE)
        sort(edges.begin(), edges.end()); //O(ElogE)
        int mstCost = 0;
        int count = 0;

        vector<Edge> mstEdges;

        for(int i=0; i<edges.size(); i++) {
            Edge e = edges[i];

            int parU = find(e.u);
            int parV = find(e.v);

            if(parU != parV && count < V - 1) { //no cycle and not all vertices included
                unionByRank(parU, parV);
                mstCost += e.w;
                mstEdges.push_back(e);
                count++;
            }
        }
        cout << "Total MST Cost: " << mstCost << endl;
        cout << "Edges in the MST: " << endl;
        for(auto e : mstEdges) {
            cout << e.u << " - " << e.v << " Weight: " << e.w << endl;
        }
    }
};


int main() {
    Graph g(6);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    
    g.kruskal();

    return 0;
}