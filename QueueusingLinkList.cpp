#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
private:
    Node* head;
    Node* tail;
public:
   Queue() {
        head = NULL;
        tail = NULL;
    }
    void push(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop() {
        if (head == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    } 
    int front() {
        if (head == NULL) {
            cout << "Queue is empty" << endl;
            return -1; // Return -1 to indicate an error
        }
        return head->data;
    }
    bool empty() {
        return head == NULL;
    }
};
int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // Output: 10

    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // Output: 20

    q.pop();
    q.pop();

    if (q.empty()) {
        cout << "Queue is empty" << endl; // Output: Queue is empty
    }

    return 0;
} 