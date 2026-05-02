#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Global head
Node* head = NULL;


// Function to insert at end
void insert(int value) {

    Node* newNode = new Node(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}


// Function to print list
void printList(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}


// Function to split list at middle
Node* splitAtMid(Node* head) {

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;
    }

    Node* rightHead = slow->next;
    slow->next = NULL;

    return rightHead;
}


// Function to merge two sorted linked lists
Node* merge(Node* left, Node* right) {

    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    Node* result = NULL;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    }
    else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}


// Merge Sort function (same as your image style)
Node* mergeSort(Node* head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* rightHead = splitAtMid(head);

    head = mergeSort(head);        // left head
    rightHead = mergeSort(rightHead); // right head

    return merge(head, rightHead);
}


// Main function
int main() {

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";

    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(value);
    }

    cout << "\nOriginal Linked List:\n";
    printList(head);

    head = mergeSort(head);

    cout << "\nSorted Linked List:\n";
    printList(head);

    return 0;
}  