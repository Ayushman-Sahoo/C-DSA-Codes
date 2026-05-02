#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> deq;
    deq.push_front(2); // Insert at the front
    deq.push_front(1);

    deq.push_back(3); // Insert at the back
    deq.push_back(4); // Insert at the back

    deq.pop_front(); // Remove from the front
    deq.pop_back();  // Remove from the back

    deq.front(); // Access the front element
    deq.back();  // Access the back element
    return 0;
}