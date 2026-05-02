//Stack implemented using two queues
#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q1, q2;

public:
    // Push element (O(1))
    void push(int x) {
        q1.push(x);
    }

    // Remove top element (O(n))
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        // Move all except last element
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Remove last element
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);
    }

    // Get top element (O(n))
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        // Move all except last element
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int ans = q1.front(); // last element
        q2.push(ans);
        q1.pop();

        // Swap back
        swap(q1, q2);

        return ans;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;

    s.pop();
    cout << "Top after pop: " << s.top() << endl;

    return 0;
}

/*#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q1, q2;

public:
    // Push element (O(n))
    void push(int x) {
        // Push into empty q2
        q2.push(x);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);
    }

    // Remove top element (O(1))
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q1.pop();
    }

    // Get top element (O(1))
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;

    s.pop();
    cout << "Top after pop: " << s.top() << endl;

    return 0;
}
*/