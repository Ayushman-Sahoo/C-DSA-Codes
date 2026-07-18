/*143. Reorder List
You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
Constraints:
The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
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

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

void reorderList(ListNode* head) {
    if (!head || !head->next)
        return;

    // Step 1: Find middle
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    ListNode *prev = NULL;
    ListNode *curr = slow->next;
    slow->next = NULL;

    while (curr) {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Step 3: Merge two halves
    ListNode *first = head;
    ListNode *second = prev;

    while (second) {
        ListNode *temp1 = first->next;
        ListNode *temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next)
            cout << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    if (n == 0)
        return 0;

    int x;
    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new ListNode(x);
        tail = tail->next;
    }

    reorderList(head);
    printList(head);

    return 0;
}