#include <iostream>
#include <vector>
#include <queue>
using namespace std;  

class Heap {
  vector<int> vec;
public:
  void push(int val) {
    vec.push_back(val);

    //fix the heap property
    //Max-Heap: parent should be greater than children
    int idx = vec.size() - 1; //child index
    int parentIdx = (idx - 1) / 2; //parent index
    while (parentIdx >= 0 && vec[parentIdx] < vec[idx]) {
      swap(vec[parentIdx], vec[idx]);
      idx = parentIdx;
      parentIdx = (idx - 1) / 2;
    }

    //Min-Heap: parent should be smaller than children
    {
      int idx = vec.size() - 1; //child index
      int parentIdx = (idx - 1) / 2; //parent index
      while (parentIdx >= 0 && vec[parentIdx] > vec[idx]) {
        swap(vec[parentIdx], vec[idx]);
        idx = parentIdx;
        parentIdx = (idx - 1) / 2;
      }
    }
  }

  void heapify(int idx) {
    if (idx >= vec.size()) {
      return;
    }
    
    int leftChildIdx = 2 * idx + 1;
    int rightChildIdx = 2 * idx + 2;
    int largestIdx = idx;

    if (leftChildIdx < vec.size() && vec[leftChildIdx] > vec[largestIdx]) {
      largestIdx = leftChildIdx;
    }
    if (rightChildIdx < vec.size() && vec[rightChildIdx] > vec[largestIdx]) {
      largestIdx = rightChildIdx;
    }
    if (largestIdx != idx) {
      swap(vec[idx], vec[largestIdx]);
      heapify(largestIdx); //recursively heapify the affected subtree
    }
  }

  void pop() {
    swap(vec[0], vec[vec.size() - 1]); //swap top with last element
    vec.pop_back(); //remove last element
    heapify(0); //fix the heap property starting from the root
  } 

  int top() {
    return vec[0]; //highest priority element
  }

  bool empty() {
    return vec.size() == 0;
  }
  
  void print() {
    for (int val : vec) {
      cout << val << " ";
    }
    cout << endl;
  }
};

class Student {
  string name;
  int grade;
public:
  Student(string name, int grade){
    this->name = name;
    this->grade = grade;
  }

  //Max-Heap: higher grade has higher priority
  bool operator<(const Student& other) const {
    return grade < other.grade; //compare based on grade
  }

  void print() {
    cout << name << ": " << grade << endl;
  }
};

struct CompareStudent {
  bool operator()(pair<string ,int>& s1, pair<string ,int>& s2) {
    return s1.second < s2.second; //for Max-Heap
    //return s1.second > s2.second; //for Min-Heap
  }
};

int main() {
  /*Heap heap;
  heap.push(5);
  heap.push(3);
  heap.push(8);
  heap.push(1);

  cout << "Top element: " << heap.top() << endl;
  heap.print();

  heap.pop();
  cout << "Top element after pop: " << heap.top() << endl;
  heap.print();*/

  priority_queue<Student , vector<Student>, CompareStudent> pq;

  pq.push(Student("Alice", 85));
  pq.push(Student("Bob", 90));
  pq.push(Student("Charlie", 80));

  while (!pq.empty())
  {
    Student s = pq.top();
    s.print();
    pq.pop();
  }
  return 0;
}