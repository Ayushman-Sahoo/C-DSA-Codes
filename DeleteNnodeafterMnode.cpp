//Delete N Nodes After M Nodes of a Linked List
/*We have a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes, continue the same till end of the linked list. Difficulty Level: Rookie.
Sample Input 1 : M=2 N=2    LL: 1->2->3->4->5->6->7->8
Sample Output 1 : 1->2->5->6
Sample Input 2 : M=3 N=2    LL: 1->2->3->4->5->6->7->8->9->10
Sample Output 2 : 1->2->3->6->7->8*/
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

// Delete N nodes after M nodes
void deleteNafterM(Node*& head, int M, int N) {

    Node* curr = head;

    while(curr != NULL) {

        // Step 1: Skip M nodes
        for(int i = 1; i < M && curr != NULL; i++) {
            curr = curr->next;
        }

        if(curr == NULL)
            return;

        // Step 2: Delete next N nodes
        Node* temp = curr->next;

        for(int i = 0; i < N && temp != NULL; i++) {

            Node* del = temp;
            temp = temp->next;
            delete del;
        }

        // Step 3: Connect remaining list
        curr->next = temp;

        // Move curr forward
        curr = temp;
    }
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
    int n, val, M, N;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for(int i = 0; i < n; i++) {
        cin >> val;
        insert(head, val);
    }

    cout << "Enter M and N: ";
    cin >> M >> N;

    cout << "Original List:\n";
    display(head);

    deleteNafterM(head, M, N);

    cout << "Updated List:\n";
    display(head);

    return 0;
}