#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;


class Graph {
public:
    int V;
    vector<vector<int>> adj;

    int time = 0; // global variable to keep track of discovery time
    vector<int> dt, low;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }   
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int parU, set<int> &cp) {
        dt[u] = low[u] = ++time;

        int children = 0;

        for (int i=0; i<adj[u].size(); i++) {
            int v = adj[u][i];
            
            if (dt[v] == -1) { // if v is not visited
                children++;
                dfs(v, u, cp);
                //update low value of u for parent function calls
                low[u] = min(low[u], low[v]);

                if (parU != -1 && low[v] >= dt[u]) {
                    // ARTICULATION POINT FOUND
                    cp.insert(u);
                }
            } else if (v != parU) {
                low[u] = min(low[u], dt[v]);
            }
        }

        if (parU == -1 && children > 1) {
            // ARTICULATION POINT FOUND
            cp.insert(u);
        }
    }

    int articulationPoints() { // Complete this
        time = 0;
        dt.resize(V, -1); // dt == -1 means not visited
        low.resize(V);

        set<int> criticalPoints; // to store articulation points

        for (int i=0; i<V; i++) {
            if (dt[i] == -1) {
                dfs(i, -1, criticalPoints);
            }
        }

        //print articulation points
        for (int val : criticalPoints) {
            cout << val << " ";
        }
        cout << endl;

        return criticalPoints.size();
    }

}; 


int main() {
    Graph graph(6);

    graph.addEdge(1, 0);
    graph.addEdge(1, 2);
    graph.addEdge(4, 3);
    graph.addEdge(4, 5);
    graph.addEdge(4, 1);

    cout << "Articulation points in the graph are: " << graph.articulationPoints() << endl;
    return 0;
}