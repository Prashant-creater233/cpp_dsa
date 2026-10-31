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

//     //BFS Traversal
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
// };

// int main() {
//     Graph g(5);

//     g.addEdge(0, 1);
//     g.addEdge(1, 2);
//     g.addEdge(1, 3);
//     g.addEdge(2, 3);
//     g.addEdge(2, 4);

//     g.bfs();

//     return 0;
// }


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

//     //BFS Traversal
//     void bfs() {
//         queue<int> q;
//         vector<bool> vis(V, false);

//         q.push(0);
//         vis[0] = true;

//         while(q.size() > 0) {
//             int u = q.front();
//             q.pop();

//             cout << u << " ";

//             for(int v : l[u]) {
//                 if(!vis[v]) {
//                     vis[v] = true;
//                     q.push(v);
//                 }
//             }
//         }

//         cout << endl;
//     }
// };

// int main() {
//     Graph g(5);

//     g.addEdge(0, 1);
//     g.addEdge(0, 2);
//     g.addEdge(1, 4);
//     g.addEdge(2, 3);

//     g.bfs();

//     return 0;
// }



//Example

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

    //BFS Traversal
    void bfs() {
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(1);
        vis[1] = true;

        while(q.size() > 0) {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for(int v : l[u]) {
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    Graph g(9);

    g.addEdge(1, 2);
    g.addEdge(1, 6);
    g.addEdge(1, 7);
    g.addEdge(2, 8);
    g.addEdge(6, 4);
    g.addEdge(8, 5);

    g.bfs();

    return 0;
}