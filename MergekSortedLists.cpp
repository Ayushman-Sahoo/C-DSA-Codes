//Merge k Sorted Lists
/*We have K sorted linked lists of size N each, merge them and print the sorted output.
Sample Input 1 : k = 2, n =  2
l1 = 1->3->NULL
l2 = 6->8->NULL
l3 = 9->10->NULL
Sample Output 1 : 1>3->6->8->9->10->NULL*/
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

// Display list
void display(Node* head) {

    while(head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Merge two sorted lists
Node* mergeTwoLists(Node* l1, Node* l2) {

    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    Node* result = NULL;

    if(l1->data <= l2->data) {
        result = l1;
        result->next = mergeTwoLists(l1->next, l2);
    }
    else {
        result = l2;
        result->next = mergeTwoLists(l1, l2->next);
    }

    return result;
}

// Merge K lists
Node* mergeKLists(Node* lists[], int k) {

    Node* result = NULL;

    for(int i = 0; i < k; i++) {
        result = mergeTwoLists(result, lists[i]);
    }

    return result;
}

// Main
int main() {

    int k, n, val;

    cout << "Enter number of linked lists (k): ";
    cin >> k;

    Node* lists[k];

    for(int i = 0; i < k; i++) {

        lists[i] = NULL;

        cout << "Enter number of elements in list " << i+1 << ": ";
        cin >> n;

        cout << "Enter elements:\n";

        for(int j = 0; j < n; j++) {
            cin >> val;
            insert(lists[i], val);
        }
    }

    Node* result = mergeKLists(lists, k);

    cout << "Merged Sorted List:\n";
    display(result);

    return 0;
}