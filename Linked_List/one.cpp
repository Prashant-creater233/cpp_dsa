#include <iostream>
#include <vector>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }  
    
    void push_front(int val) {
        Node* newNode = new Node(val); // dynamically allocate memory for a new node
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void printLL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};  

int main() {
    List l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);

    l1.printLL();

    return 0;
}