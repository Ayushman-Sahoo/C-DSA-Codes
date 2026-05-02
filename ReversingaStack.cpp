#include<iostream>
#include<stack>
#include<string>
using namespace std;

void pushAtBottom(stack<int> &s, int val) { // O(n)
    if (s.empty()) {
        s.push(val); // push at top = push at bottom
        return;
    }

    int temp = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(temp);
}

string reverseString(string str) {
    string ans;
    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    string reversedStr = "";
    while (!s.empty()) {
        reversedStr += s.top();
        ans += s.top();
        s.pop();
    }

    return ans;
}

void reverseStack(stack<int> &s) {
    if (s.empty()) {
        return;
    }

    int temp = s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s, temp);
}

void displayStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    displayStack(s);
    
    reverseStack(s);
    displayStack(s);
    return 0;
}