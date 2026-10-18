#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;


// with scretch

// class Node {
// public:
//     int data;
//     Node* next;

//     Node(int val) {
//         data = val;
//         next = NULL;
//     }
// };

// class Queue {
//     Node* head;
//     Node* tail;

// public:
//     Queue() {
//         head = tail = NULL;
//     }    

//     void push(int data) { // insert data at tail  O(1)
//         Node* newNode = new Node(data);
//         if(empty()) {
//             head = tail = newNode;
//         } else {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }

//     void pop() { // O(1)
//         if(empty()) {
//             cout << "LL is EMPTY\n";
//         } else {
//             Node* temp = head;
//             head = head->next;
//             delete temp;
//         }
//     }

//     int front() { // O(1)
//         if(empty()) {
//             cout << "LL is EMPTY\n";
//             return -1;
//         } 

//         return head->data;
//     }   

//     bool empty() {
//         return head == NULL;
//     }
// };

// int main() {
//     Queue q;
//     q.push(1);
//     q.push(2);
//     q.push(3);

//     while(!q.empty()) {
//         cout << q.front() << " ";
//         q.pop();
//     }

//     cout << endl;

//     return 0;
// }


// using STL direct implementation

// int main() {
//     queue<int> q;
//     q.push(1);
//     q.push(2);
//     q.push(3);

//     while(!q.empty()) {
//         cout << q.front() << " ";
//         q.pop();
//     }

//     cout << endl;

//     return 0;
// }



// Deque  ( Double Ended Queue )

int main() {
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

    dq.push_front(4); // 4,1,2,3
    cout << dq.front() << " " << dq.back() << endl;
    
    dq.pop_back(); // 4,1,2
    cout << dq.front() << " " << dq.back() << endl;

    return 0;
}