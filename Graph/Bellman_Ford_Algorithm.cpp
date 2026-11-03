
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

void bellmanFord(int src, vector<vector<Edge>>& g, int V) {

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // V-1 iterations
    for (int i = 0; i < V - 1; i++) {

        for (int u = 0; u < V; u++) {

            if (dist[u] == INT_MAX) continue;

            for (Edge e : g[u]) {

                if (dist[e.v] > dist[u] + e.wt) {
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < V; i++) {
        cout << "Distance from source " << src
             << " to vertex " << i << " is ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }
}

int main() {

    int V = 6;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(2, 1));
    g[1].push_back(Edge(3, 7));

    g[2].push_back(Edge(4, 3));

    g[3].push_back(Edge(5, 1));

    g[4].push_back(Edge(3, 2));
    g[4].push_back(Edge(5, 5));

    bellmanFord(0, g, V);

    return 0;
}
