/*  Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Example 4:
Input: head = [1,2,3]
Output: [2,1,3]

Constraints:
The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
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

// ================= NODE CLASS =================
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// ================= SWAP PAIRS FUNCTION =================
ListNode* swapPairs(ListNode* head) {

    // Empty list or single node
    if (head == NULL || head->next == NULL)
        return head;

    // First two nodes
    ListNode* first = head;
    ListNode* second = head->next;

    // Recursive call for remaining list
    first->next = swapPairs(second->next);

    // Swap
    second->next = first;

    // Return new head
    return second;
}

// ================= PRINT LIST =================
void printList(ListNode* head) {

    while (head != NULL) {
        cout << head->val;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

// ================= MAIN =================
int main() {

    // Create linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original List:" << endl;
    printList(head);

    // Swap pairs
    head = swapPairs(head);

    cout << "After Swapping Pairs:" << endl;
    printList(head);

    return 0;
}