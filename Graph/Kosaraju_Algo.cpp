#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;


class Graph {
public:
    vector<vector<int>> adj;
    int V;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }   
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void topoSort(int curr, vector<bool> &vis, stack<int> &s) {
        vis[curr] = true;

        for(int neigh : adj[curr]) {
            if(!vis[neigh]) {
                topoSort(neigh, vis, s);
            }
        }

        s.push(curr);
    }

    void kosaraju() {
        //step1 - topo order
        stack<int> s;
        vector<bool> vis(V, false);

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                topoSort(i, vis, s);
            }
        }

        //step2 - transpose graph
        vector<vector<int>> transpose(V);

        for(int u=0; u<V; u++) { //u --> v
            vis[u] = false;
            for(int v : adj[u]) { // v --> u
                transpose[v].push_back(u);
            }
        }

        //step3 dfs on transpose
    }

};    


int main() {
    Graph graph(5);

    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 0);
    graph.addEdge(2, 1);
    graph.addEdge(3, 4);

    graph.kosaraju();

    return 0;
}