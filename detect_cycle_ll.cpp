// Detect cycle in a linked list using Floyd's Cycle Detection Algorithm
#include <iostream>
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Global head and tail
Node* head = NULL;
Node* tail = NULL;

// push_front function
void push_front(int value) {

    Node* newNode = new Node(value);

    if (head == NULL) {
        head = tail = newNode;
    } 
    else {
        newNode->next = head;
        head = newNode;
    }
}

// pop_front function
void pop_front() {

    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    temp->next = NULL;
    delete temp;
}

// printList function
void printList(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Floyd Cycle Detection function
bool detectCycle(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

// Function to create cycle (CORRECTED SAFETY CHECK ONLY)
void createCycle(int position) {

    if (position < 0)
        return;

    Node* temp = head;

    for (int i = 0; i < position; i++) {

        if (temp == NULL)   // safety check added
            return;

        temp = temp->next;
    }

    if (tail != NULL)
        tail->next = temp;
}


// removeCycle function (CORRECTED WRONG CONDITION ONLY)
void removeCycle() {

    if (head == NULL)
        return;

    Node* slow = head;
    Node* fast = head;
    bool cycleExists = false;

    // Detect cycle
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout << "Cycle detected in linked list\n";
            cycleExists = true;
            break;
        }
    }

    if (!cycleExists)
    {
        cout << "No cycle detected in linked list\n";
        return;
    }
    
    
    // Find the start of the cycle
    slow = head;

    // CORRECTED CONDITION HERE
    if (slow == fast)
    {
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL;
    }
    else
    {
        Node* prev = fast;
        while (slow != fast) {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL;
    }
}


// main function with user input
int main() {

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        push_front(value);
    }

    cout << "Linked List: ";
    printList(head);

    // Ask user to create cycle
    int pos;
    cout << "Enter position to create cycle (-1 for no cycle): ";
    cin >> pos;

    if (pos != -1)
        createCycle(pos);

    // Detect cycle
    if (detectCycle(head))
        cout << "Cycle detected in linked list\n";
    else
        cout << "No cycle detected\n";

    return 0;
}