#include<iostream>
#include <deque>

using namespace std;

class Stack {
  deque<int> deq;
public:
  void push(int x) {
    deq.push_back(x);
  }
  
  void pop() {
    deq.pop_back();
  }
  
  int top() {
    return deq.back();
  }
  
  bool empty() {
    return deq.empty();
  }
};
int main() {
    Stack s;
    for (int i = 0; i < 5; i++) {
        s.push(i);
    }
    // Print the stack elements
    for (int i = 0; i < 5; i++) {
        cout << s.top() << " ";
        s.pop();
    }
    
    return 0;
}