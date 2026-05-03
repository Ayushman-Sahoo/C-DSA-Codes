/*     Add Two numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.*/
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

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node to simplify result list creation
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        int carry = 0;

        // Loop while there is a node in l1 or l2 or carry exists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = carry + val1 + val2;

            // Move pointers safely
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;

            // Create new node with digit value
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            // Update carry
            carry = sum / 10;
        }

        // Return result list (skip dummy node)
        return dummy->next;
    }
};

/// 🔽 Helper function to create linked list
ListNode* createList(int n) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ListNode* newNode = new ListNode(x);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

/// 🔽 Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n1, n2;

    cout << "Enter size of first list: ";
    cin >> n1;
    cout << "Enter elements (in reverse order): ";
    ListNode* l1 = createList(n1);

    cout << "Enter size of second list: ";
    cin >> n2;
    cout << "Enter elements (in reverse order): ";
    ListNode* l2 = createList(n2);

    Solution obj;
    ListNode* result = obj.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}