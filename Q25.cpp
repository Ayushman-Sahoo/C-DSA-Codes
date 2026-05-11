/* Reverse Nodes in k-Group
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 
Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
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

// ================= LINKED LIST NODE =================
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// ================= REVERSE K GROUP FUNCTION =================
ListNode* reverseKGroup(ListNode* head, int k) {

    if(head == NULL || k == 1)
        return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prevGroup = dummy;

    while(true) {

        // Check if k nodes exist
        ListNode* kth = prevGroup;

        for(int i = 0; i < k; i++) {
            kth = kth->next;

            if(kth == NULL)
                return dummy->next;
        }

        // Reverse k nodes
        ListNode* groupNext = kth->next;
        ListNode* prev = groupNext;
        ListNode* curr = prevGroup->next;

        while(curr != groupNext) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Connect reversed group
        ListNode* temp = prevGroup->next;
        prevGroup->next = kth;
        prevGroup = temp;
    }

    return dummy->next;
}

// ================= PRINT LINKED LIST =================
void printList(ListNode* head) {

    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

// ================= MAIN FUNCTION =================
int main() {

    int n, k;

    cout << "Enter number of nodes: ";
    cin >> n;

    if(n <= 0) {
        cout << "List is empty" << endl;
        return 0;
    }

    cout << "Enter value of k: ";
    cin >> k;

    // Input linked list
    int x;
    cout << "Enter linked list elements: ";

    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* temp = head;

    for(int i = 1; i < n; i++) {
        cin >> x;

        temp->next = new ListNode(x);
        temp = temp->next;
    }

    cout << "Original List: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Modified List: ";
    printList(head);

    return 0;
}