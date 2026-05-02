//Swapping Nodes in a Linked List
/*We have a linked list and two keys in it, swap nodes for two given keys. Nodes should be
swapped by changing links. Swapping data of nodes may be expensive in many situations when
data contains many fields. It may be assumed that all keys in the linked list are distinct.
Sample Input 1 : 1->2->3->4,  x = 2, y = 4
Sample Output 1 : 1->4->3->2*/
#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert at end
void insert(Node*& head, int val) {

    Node* newNode = new Node(val);

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Swap nodes by links
void swapNodes(Node*& head, int x, int y) {

    if(x == y)
        return;

    Node* prevX = NULL;
    Node* currX = head;

    // Find x
    while(currX != NULL && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    Node* prevY = NULL;
    Node* currY = head;

    // Find y
    while(currY != NULL && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    // If not found
    if(currX == NULL || currY == NULL)
        return;

    // Change previous links
    if(prevX != NULL)
        prevX->next = currY;
    else
        head = currY;

    if(prevY != NULL)
        prevY->next = currX;
    else
        head = currX;

    // Swap next pointers
    Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;
}

// Display list
void display(Node* head) {

    while(head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL\n";
}

// Main
int main() {

    Node* head = NULL;
    int n, val, x, y;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for(int i = 0; i < n; i++) {
        cin >> val;
        insert(head, val);
    }

    cout << "Enter x and y to swap: ";
    cin >> x >> y;

    cout << "Original List:\n";
    display(head);

    swapNodes(head, x, y);

    cout << "List after swapping:\n";
    display(head);

    return 0;
}