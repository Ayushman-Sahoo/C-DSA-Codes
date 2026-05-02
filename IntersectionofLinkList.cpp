// Intersection of Two Linked Lists
/*In a system there are two singly linked list. By some programming error, the end node of one of the linked lists got linked to the second list, forming an inverted Y-shaped list. Write a program to get the point where two linked lists merge.*/
#include <iostream>
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

int getLength(Node* head){
    int length = 0;
    Node* temp = head;

    while(temp != NULL) {
        length++;
        temp = temp->next;
    }

    return length;
}

Node* getIntersection(Node* headA, Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    Node* tempA = headA;
    Node* tempB = headB;

    // Align the start of both lists
    if (lenA > lenB) {
        for (int i = 0; i < lenA - lenB; i++) {
            tempA = tempA->next;
        }
    } else {
        for (int i = 0; i < lenB - lenA; i++) {
            tempB = tempB->next;
        }
    }

    // Move both pointers until they point to the same node
    while (tempA != NULL && tempB != NULL) {
        if (tempA == tempB) {
            return tempA; // Intersection found
        }
        tempA = tempA->next;
        tempB = tempB->next;
    }

    return NULL; // No intersection
}

void display(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

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

int main() {
    Node* headA = NULL;
    Node* headB = NULL;

    // Create first linked list: 1 -> 2 -> 3 -> 4 -> 5
    insert(headA, 1);
    insert(headA, 2);
    insert(headA, 3);
    insert(headA, 4);
    insert(headA, 5);

    // Create second linked list: 9 -> 8
    insert(headB, 9);
    insert(headB, 8);

    // Create intersection at node with value 3
    headB->next = headA->next->next; // Pointing to node with value 3

    cout << "List A: ";
    display(headA);

    cout << "List B: ";
    display(headB);

    Node* intersectionNode = getIntersection(headA, headB);

    if (intersectionNode != NULL) {
        cout << "Intersection at node with value: " << intersectionNode->data << endl;
    } else {
        cout << "No intersection found.\n";
    }

    return 0;
}