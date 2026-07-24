/*155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int value) pushes the element value onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
Example 1:
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
Output
[null,null,null,null,-3,null,0,-2]
Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
Constraints:
-2^31 <= val <= 2^31 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
    }

    void push(int value) {
        st.push(value);

        if (minSt.empty() || value <= minSt.top()) {
            minSt.push(value);
        }
    }

    void pop() {
        if (st.empty())
            return;

        if (st.top() == minSt.top()) {
            minSt.pop();
        }

        st.pop();
    }

    int top() {
        if (st.empty())
            return -1;
        return st.top();
    }

    int getMin() {
        if (minSt.empty())
            return -1;
        return minSt.top();
    }
};

int main() {
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << "Minimum: " << minStack.getMin() << endl;

    minStack.pop();

    cout << "Top: " << minStack.top() << endl;

    cout << "Minimum: " << minStack.getMin() << endl;

    return 0;
}