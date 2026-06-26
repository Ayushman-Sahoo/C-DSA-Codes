/*86. Partition List
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.
Example 1:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* smallDummy = new ListNode(0);
        ListNode* largeDummy = new ListNode(0);

        ListNode* small = smallDummy;
        ListNode* large = largeDummy;

        while (head != nullptr) {

            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }

            head = head->next;
        }

        // End the large list
        large->next = nullptr;

        // Connect small list with large list
        small->next = largeDummy->next;

        return smallDummy->next;
    }
};

// Function to create linked list
ListNode* createList(int n) {
    if (n == 0) return nullptr;

    int x;
    cin >> x;

    ListNode* head = new ListNode(x);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        temp->next = new ListNode(x);
        temp = temp->next;
    }

    return head;
}

// Function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr)
            cout << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter the elements: ";
    ListNode* head = createList(n);

    int x;
    cout << "Enter x: ";
    cin >> x;

    Solution obj;
    head = obj.partition(head, x);

    cout << "Partitioned List: ";
    printList(head);

    return 0;
}