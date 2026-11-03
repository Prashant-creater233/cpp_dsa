#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;


// class Graph {

//     int V;
//     list<int> *l; //int *arr;

// public:
//     Graph(int V) {
//         this->V = V;
//         l = new list<int> [V];
//         //arr = new int[V]
//     }   
    
//     void addEdge(int u, int v) {
//         l[u].push_back(v);
//     }

//     // Topological Sort
//     void dfs(int curr, vector<bool> &vis, stack<int> &s) {
//         vis[curr] = true;

//         for(int v : l[curr]) {
//             if(!vis[v]) {
//                 dfs(v, vis, s);
//             }
//         }

//         s.push(curr);
//     }

//     void topSort() {
//         vector<bool> vis(V, false);
//         stack<int> s;

//         for(int i = 0; i < V; i++) {
//             if(!vis[i]) {
//                 dfs(i, vis, s);
//             }
//         }

//         while(!s.empty()) {
//             cout << s.top() << " ";
//             s.pop();
//         }
//         cout << endl;
//     }

// };

// int main() {
//     Graph g(6);

//     g.addEdge(3, 1);
//     g.addEdge(2, 3);
//     g.addEdge(4, 0);
//     g.addEdge(4, 1);
//     g.addEdge(5, 0);
//     g.addEdge(5, 3);

//     cout << "Topological Sort: ";
//     g.topSort();

//     return 0;
// }    








// Topological Sorting by Kahn's Algorithm (BFS)
class Graph {

    int V;
    list<int> *l; //int *arr;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
        //arr = new int[V]
    }   
    
    void addEdge(int u, int v) {
        l[u].push_back(v);
    }

    // Topological Sort

    void topSort() {
        vector<int> res;
        
        //calaculate indegree of all vertices
        vector<int> indegree(V, 0);
        for(int u=0; u<V; u++) {
            for(int v : l[u]) {
                indegree[v]++;
            }
        }

        // 0 indegree vertices push in queue
        queue<int> q;
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // BFS
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for(int v : l[curr]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Print the topological order
        for(int val : res) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge(3, 1); // valid graph
    g.addEdge(2, 3);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(5, 0);
    g.addEdge(5, 2);

    cout << "Topological Sort: ";
    g.topSort();

    return 0;
}    