#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val){
      data = val;
      next = NULL;
    }
};

Node* splitAtMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL) {
        prev->next = NULL; // Split the list into two halves
    }

    return slow; // Return the head of the second half
}

// Display list
void display(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Insert at end
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current; // Move prev to current
        current = next; // Move to next node
    }

    return prev; // New head of the reversed list
}

void ZigZag(Node* head) {
    Node* rightHead = splitAtMid(head);
    Node* left = head;
    Node* rightHeadRev = reverse(rightHead); // Reverse the second half of the list

    //alternate merging : 1st Head = head and 2nd Head = rightHeadRev
    Node* tempLeft = left;
    Node* tempRight = rightHeadRev;
    Node* prev = NULL;

    while (tempLeft != NULL && tempRight != NULL) {
        if (prev == NULL) {
            head = tempLeft;
        } else {
            prev->next = tempLeft;
        }
        prev = tempLeft;
        tempLeft = tempLeft->next;

        prev->next = tempRight;
        prev = tempRight;
        tempRight = tempRight->next;
    }

    if (tempLeft != NULL) {
        prev->next = tempLeft;
    } else if (tempRight != NULL) {
        prev->next = tempRight;
    }
}

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

    cout << "\nOriginal List:\n";
    display(head);
    ZigZag(head);

    cout << "\nZig-Zag List:\n";
    display(head);
    return 0;
} 