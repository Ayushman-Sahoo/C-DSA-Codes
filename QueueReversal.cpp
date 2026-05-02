#include <iostream>
#include <queue>
#include <stack>

using namespace std;
void reverseQueue(queue<int>& q) {
    stack<int> s;

    // Step 1: Dequeue all elements from the queue and push them onto the stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Pop all elements from the stack and enqueue them back to the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}
int main() {
    queue<int> q;
    // Enqueue some elements into the queue
    for (int i = 0; i < 5; i++)
    {
      q.push(i);
    }
    // Reverse the queue
    reverseQueue(q);
    // Print the reversed queue
    for (int i = 0; i < 5; i++)
    {
      cout << q.front() << " ";
      q.pop();
    }
    
    return 0;
} 