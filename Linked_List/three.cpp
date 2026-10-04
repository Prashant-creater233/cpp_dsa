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

class CircularList {
    Node* head;
    Node* tail;

public:
    CircularList() {
        head = tail = NULL;
    }    

    void insertAtHead(int val) {
        Node* newNode = new Node(val);

        if(tail == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if(tail == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtHead() {
        if(head == NULL) return;
        else if(head == tail) { // single node
            delete head;
            head = tail = NULL;
        } else { // 2 or more node
            Node* temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void deleteAtTail() {
        if(head == NULL) return;
        else if(head == tail) { // single node
            delete head;
            head = tail = NULL;
        } else { // 2 or more node
            Node* temp = tail;

            Node* prev = head;
            while(prev->next != tail) {
                prev = prev->next;
            }

            tail = prev;
            tail->next;
            tail->next = head;

            temp->next =NULL;
            delete temp;
            
        }
    }

    void print() {
        if(head == NULL) return;

        cout << head->data << "->";
        Node* temp = head->next;

        while(temp != head) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        
        cout << head->data << endl;
    }
};

int main() {
    CircularList cll;

    // cll.insertAtHead(1);
    // cll.insertAtHead(2);
    // cll.insertAtHead(3);

    cll.insertAtTail(1);
    cll.insertAtTail(2);
    cll.insertAtTail(3);

    // cll.deleteAtHead();
    // cll.deleteAtHead();
    // cll.deleteAtHead();

    cll.print();

    cll.deleteAtTail();
    cll.print();

    cll.deleteAtTail();
    cll.print();

    cll.deleteAtTail();
    cll.print();

    return 0;
}