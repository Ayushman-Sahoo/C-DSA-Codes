/* Valid Parenthesis
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type. */

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else {
            if (st.empty()) return false;

            char top = st.top();

            if ((c == ')' && top == '(') || 
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                st.pop();   // pop only when matching
            }
            else {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    string s = "{[()]}";

    if (isValid(s)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }

    return 0;
}