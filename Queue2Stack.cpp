//Queue using 2 stacks
// Time Complexity: O(n) for push, O(1) for pop and front
#include <iostream>
#include <stack>
using namespace std;
class Queue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element into s1
        s1.push(x);

        // Move everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        }

    void pop() {
        if (s1.empty()) {
            cout << "Queue is empty\n";
            return;
        }
        s1.pop();
    }

    int front() {
        if (s1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return s1.top();
    }
     bool empty() {
        return s1.empty();
    }
  };

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl;

    q.pop();
    cout << "Front after pop: " << q.front() << endl;

    return 0;
}

// Queue using 2 stacks
// Time Complexity: O(1) for push and front, O(n) for pop 
/*#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> s1, s2;

public:
    // O(1)
    void push(int x) {
        s1.push(x);
    }

    // O(1)
    int front() {
        if (s1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        // Move elements to get correct front
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        int ans = s2.top();

        // Put them back
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return ans;
    }

    // O(n)
    void pop() {
        if (s1.empty()) {
            cout << "Queue is empty\n";
            return;
        }

        // Move elements
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Remove front
        s2.pop();

        // Move back
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl;

    q.pop();
    cout << "Front after pop: " << q.front() << endl;

    return 0;
}*/