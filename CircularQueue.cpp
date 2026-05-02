#include<iostream>
using namespace std;
class CircularQueue {
private:
    int* arr;
    int frontIndex;
    int rear;
    int capacity;
    int currentSize;
public:
   CircularQueue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        frontIndex = 0;
        rear = -1;
        currentSize = 0;
    }
    void push(int data) {
        if (currentSize == capacity) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Circular increment
        arr[rear] = data;
        currentSize++;
    }
    void pop() {
        if (currentSize == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        frontIndex = (frontIndex + 1) % capacity; // Circular increment
        currentSize--;
    } 
    int front() {
        if (currentSize == 0) {
            cout << "Queue is empty" << endl;
            return -1; // Return -1 to indicate an error
        }
        return arr[frontIndex];
    }
    bool empty() {
        return currentSize == 0;
    }
    ~CircularQueue() {
        delete[] arr;
    }
};
int main() {
    CircularQueue q(5); // Create a circular queue with capacity 5
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Front element: " << q.front() << endl; // Output: 10

    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // Output: 20

    q.push(60); // This will show "Queue is full" since the queue is at capacity

    return 0;
}