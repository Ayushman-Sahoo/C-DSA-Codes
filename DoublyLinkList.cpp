#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyList{
public:
    Node* head;
    Node* tail;

    // Constructor (IMPORTANT FIX)
    DoublyList() {
        head = NULL;
        tail = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } 
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } 
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        } 
        else {
            tail = NULL;
        }

        delete temp;
    }

    void pop_back() {
        if(tail == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = tail;

        if(head == tail) {
            head = tail = NULL;
        }
        else {
            tail = tail->prev;
            tail->next = NULL;
        }

        cout << temp->data << " deleted from back\n";
        delete temp;
    }

    void push_back(int val) {

        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        cout << val << " inserted at back\n";
    }
};

int main() {

    DoublyList dbll;

    dbll.insert(10);
    dbll.insert(20);
    dbll.insert(30);
    dbll.insert(40);

    cout << "Doubly Linked List: ";
    dbll.display();

    dbll.push_front(5);
    dbll.push_back(50);

    dbll.display();

    dbll.pop_front();
    dbll.pop_back();

    dbll.display();

    return 0;
}