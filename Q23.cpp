/*  23. Merge k Sorted Lists
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
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

// ================= LINKED LIST NODE =================
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// ================= MERGE TWO SORTED LISTS =================
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 != NULL && l2 != NULL) {

        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }

        tail = tail->next;
    }

    // Add remaining nodes
    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

// ================= MERGE K LISTS =================
ListNode* mergeKLists(vector<ListNode*>& lists) {

    if (lists.size() == 0)
        return NULL;

    ListNode* result = lists[0];

    for (int i = 1; i < lists.size(); i++) {
        result = mergeTwoLists(result, lists[i]);
    }

    return result;
}

// ================= CREATE LINKED LIST =================
ListNode* createList(vector<int> arr) {

    if (arr.size() == 0)
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
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

    vector<int> a = {1,4,5};
    vector<int> b = {1,3,4};
    vector<int> c = {2,6};

    // Create linked lists
    ListNode* l1 = createList(a);
    ListNode* l2 = createList(b);
    ListNode* l3 = createList(c);

    // Store in vector
    vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    // Merge all lists
    ListNode* result = mergeKLists(lists);

    // Print answer
    cout << "Merged Linked List:" << endl;
    printList(result);

    return 0;
}