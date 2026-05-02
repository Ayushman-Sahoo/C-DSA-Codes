// Odd Even Linked List
/*We have a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.
Sample Input 1 : 8->12->10->5->4->1->6->NULL
Sample Output 1 : 8->12->10->4->6->5->1->NULL
Sample Input 2 : 1->3->5->7->NULL
Sample Output 2 : 1->3->5->7->NULL*/
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

// Even Odd function
Node* evenOdd(Node* head) {

    Node* evenHead = NULL;
    Node* evenTail = NULL;
    Node* oddHead = NULL;
    Node* oddTail = NULL;

    Node* curr = head;

    while(curr != NULL) {

        if(curr->data % 2 == 0) {

            if(evenHead == NULL) {
                evenHead = evenTail = curr;
            }
            else {
                evenTail->next = curr;
                evenTail = curr;
            }
        }
        else {

            if(oddHead == NULL) {
                oddHead = oddTail = curr;
            }
            else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }

        curr = curr->next;
    }

    // If no even numbers
    if(evenHead == NULL)
        return oddHead;

    // Connect even and odd lists
    evenTail->next = oddHead;

    if(oddTail != NULL)
        oddTail->next = NULL;

    return evenHead;
}

// Display
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
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for(int i = 0; i < n; i++) {
        cin >> val;
        insert(head, val);
    }

    cout << "Original List:\n";
    display(head);

    head = evenOdd(head);

    cout << "Modified List:\n";
    display(head);

    return 0;
}