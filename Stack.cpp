/*#include <iostream>
#include <vector>
using namespace std;
//using stack vector and class template
// create stack using vector
template<class T>
class Stack {
  vector<T> vec;
public:
  void push(T val){   // added return type void
    vec.push_back(val);
  }
  void pop(){   // added return type void
    if (!vec.empty()) {
      vec.pop_back();
    }
  }
   T top(){   // added return type void
    if (vec.empty()) {
      cout << "Stack is empty" << endl;
      return T(); // Return default value of type T to indicate stack is empty
    }
    int lastIdx = vec.size() - 1;
    cout << vec[lastIdx] << endl;
    return vec[lastIdx];
  }
  bool empty(){   // added return type bool
    return vec.empty();
  }
};  

int main() {
  Stack<int> s;

  s.push(10);
  s.push(20);
  while (!s.empty())
  {
    s.top();
    s.pop();
  }
  return 0;
}*/






// Creating stack using array
/*#include <iostream>
using namespace std;

class Stack {
  int* arr;
  int size;
  int topIndex;

public:
  Stack(int n) {
    size = n;
    arr = new int[size];
    topIndex = -1;
  }

  void push(int val) {
    if (topIndex < size - 1) {
      topIndex++;
      arr[topIndex] = val;
    }
    else {
      cout << "Stack Overflow" << endl;
    }
  }

  void pop() {
    if (topIndex >= 0) {
      topIndex--;
    }
    else {
      cout << "Stack Underflow" << endl;
    }
  }

  int top() {
    if (topIndex >= 0) {
      return arr[topIndex];
    }
    else {
      cout << "Stack is empty" << endl;
      return -1;
    }
  }

  bool empty() {
    return topIndex == -1;
  }
};

int main() {
  Stack s(5);

  s.push(5);
  s.push(4);
  s.push(3);
  s.push(2);
  s.push(1);

  while (!s.empty()) {
    cout << s.top() << endl;
    s.pop();
  }

  return 0;
}*/




// Creating stack using Linked List
/*#include<iostream>
using namespace std;

// Node class
class Node {
public:
  int data;
  Node* next;

  Node(int val) {
    data = val;
    next = NULL;
  }
};

// Stack class
class Stack {
  Node* topNode;

public:
  Stack() {
    topNode = NULL;
  }

  void push(int val) {
    Node* newNode = new Node(val);
    newNode->next = topNode;
    topNode = newNode;
  }

  void pop() {
    if (topNode == NULL) {
      cout << "Stack is empty" << endl;
      return;
    }
    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
  }

  int top() {
    if (topNode == NULL) {
      cout << "Stack is empty" << endl;
      return -1;
    }
    return topNode->data;
  }

  bool isEmpty() {
    return topNode == NULL;
  }
};

int main() {
  Stack s;

  s.push(3);
  s.push(2);
  s.push(1);

  while (!s.isEmpty()) {
    cout << s.top() << endl;
    s.pop();
  }

  return 0;
}*/


//Program using stl
/*#include <iostream>
#include <stack>   // STL stack header
using namespace std;

int main() {
    stack<int> s;   // create stack

    // push elements
    s.push(10);
    s.push(20);
    s.push(30);

    // display and pop elements
    while (!s.empty()) {
        cout << s.top() << endl;  // show top element
        s.pop();                  // remove top element
    }

    return 0;
}*/



//Push at bottom of stack
#include <iostream>
#include <stack>
using namespace std;

void pushAtBottom(stack<int>& s, int val) {
    if (s.empty()) {
        s.push(val);
        return;
    }
    int topElement = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(topElement);
}

int main(){
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);

  pushAtBottom(s, 0);
  while (!s.empty())
  {
    cout << s.top() << endl;
    s.pop();
  }
  
}