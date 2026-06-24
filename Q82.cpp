/*82. Remove Duplicates from Sorted List II
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:

Input: head = [1,1,1,2,3]
Output: [2,3]

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (head != nullptr) {
            if (head->next != nullptr && head->val == head->next->val) {
                int val = head->val;

                // Skip all nodes with the duplicate value
                while (head != nullptr && head->val == val) {
                    head = head->next;
                }

                prev->next = head;
            }
            else {
                prev = prev->next;
                head = head->next;
            }
        }

        return dummy.next;
    }
};

// Create linked list from vector
ListNode* createList(vector<int>& nums) {
    if (nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* temp = head;

    for (int i = 1; i < nums.size(); i++) {
        temp->next = new ListNode(nums[i]);
        temp = temp->next;
    }

    return head;
}

// Print linked list
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
    cin >> n;  // Number of nodes

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    ListNode* head = createList(nums);

    Solution obj;
    head = obj.deleteDuplicates(head);

    printList(head);

    return 0;
}