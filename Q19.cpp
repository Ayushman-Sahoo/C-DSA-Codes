/* Remove Nth Node From End of List
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 
Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Function to remove nth node from end
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // Move fast pointer n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move both pointers
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete node
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return dummy->next;
}

// Function to create linked list
ListNode* createList(int arr[], int size) {
    if (size == 0) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, size;

    cout << "Enter number of elements: ";
    cin >> size;

    int arr[size];
    cout << "Enter elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter n: ";
    cin >> n;

    ListNode* head = createList(arr, size);

    cout << "Original List: ";
    printList(head);

    head = removeNthFromEnd(head, n);

    cout << "Updated List: ";
    printList(head);

    return 0;
}