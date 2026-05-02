/*Interleave 2 halves of a queue of even size.
Given a queue of even length, divide it into two equal halves and rearrange the elements such that they are interleaved.
Example
Input Queue:
1 2 3 4 5 6 7 8 9 10
Output Queue (After Interleaving):
1 6 2 7 3 8 4 9 5 10*/

#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int> &org) { // O(n) time and O(n) space
    int n = org.size();

    if (n % 2 != 0) {
        cout << "Queue size must be even\n";
        return;
    }

    queue<int> first;

    // Store first half
    for (int i = 0; i < n / 2; i++) {
        first.push(org.front());
        org.pop();
    }

    // Interleave both halves
    while (!first.empty()) {
        org.push(first.front());
        first.pop();

        org.push(org.front());
        org.pop();
    }
}

int main() {
    queue<int> q;

    for (int i = 1; i <= 10; i++) {
        q.push(i);
    }

    interleave(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}