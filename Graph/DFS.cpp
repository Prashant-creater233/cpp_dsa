#include <iostream>
#include <vector>
#include <list>
#include <queue>
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
//         l[v].push_back(u);
//     }

//     // BFS Traversal
//     void bfs() { // O(V + E)
//         queue<int> q;
//         vector<bool> vis(V, false);

//         q.push(0);
//         vis[0] = true;

//         while(q.size() > 0) {
//             int u = q.front(); //u-v
//             q.pop();

//             cout << u << " ";
//             for(int v : l[u]) {//v-> immediate neibhour
//                 if((!vis[v])) {
//                     vis[v] = true;
//                     q.push(v);
//                 }
//             }
//         }

//         cout << endl;
//     }



//     //DFS(depth first search) Traversal
//     void dfsHelper(int u, vector<bool> &vis) { // O(V+E) (Time Complexity)
//         cout << u << " ";
//         vis[u] =true;

//         for(int v : l[u]) {
//             if(!vis[v]) {
//                 dfsHelper(v, vis);
//             }
//         }
//     }

//     void dfs() {
//         int src = 0;
//         vector<bool> vis(V, false);

//         dfsHelper(src, vis);
//         cout << endl;
//     }
// };

// int main() {
//     Graph g(5);

//     g.addEdge(0, 1);
//     g.addEdge(1, 2);
//     g.addEdge(1, 3);
//     g.addEdge(2, 4);

//     cout << "dfs : ";
//     g.dfs();

//     cout << "bfs : ";
//     g.bfs();

//     return 0;
// }


//practice

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
//         l[v].push_back(u);
//     }

//     //dfs Traversal
//     void dfsHelper(int u, vector<bool>& vis) {
//         cout << u << " ";
//         vis[u] = true;

//         for(int v : l[u]) {
//             if(!vis[v]) {
//                 vis[v] = true;
//                 dfsHelper(v, vis);
//             }
//         }
//     }

//     void dfs() {
//         int src = 1;
//         vector<bool> vis(V, false);

//         dfsHelper(src, vis);
//         cout << endl;
//     }
// };

// int main() {
//     Graph g(9);

//     g.addEdge(1, 2);
//     g.addEdge(1, 6);
//     g.addEdge(1, 7);
//     g.addEdge(2, 8);
//     g.addEdge(6, 4);
//     g.addEdge(8, 5);

//     g.dfs();

//     return 0;
// }


// practice 2

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
        l[v].push_back(u);
    }

    //dfs Traversal
    void dfsHelper(int u, vector<bool>& vis) {
        cout << u << " ";
        vis[u] = true;

        for(int v : l[u]) {
            if(!vis[v]) {
                vis[v] = true;
                dfsHelper(v, vis);
            }
        }
    }

    void dfs() {
        int src = 1;
        vector<bool> vis(V, false);

        dfsHelper(src, vis);
        cout << endl;
    }
};

int main() {
    Graph g(11);

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 10);
    g.addEdge(3, 8);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(8, 9);

    g.dfs();

    return 0;
}