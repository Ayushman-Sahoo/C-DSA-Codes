#include <iostream>
#include <deque>
using namespace std;

class Queue{
  deque<int> deq;
  public:
  void push(int x){
    deq.push_back(x);
  }
  void pop(){
    deq.pop_front();
  }
  int front(){
    return deq.front();
  }
  bool empty(){
    return deq.empty();
  }
};
int main() {
    Queue q;
    for (int i = 0; i < 5; i++)
    {
      q.push(i);
    }
    for (int i = 0; i < 5; i++)
    {
      cout << q.front() << " ";
      q.pop();
    }
    
    return 0;
}