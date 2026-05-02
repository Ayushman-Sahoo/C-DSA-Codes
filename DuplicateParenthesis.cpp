/*Given a balanced expression that can contain opening and closing parenthesis, check if it contains any duplicate parenthesis or not.
Input: ((x+y))+z
Output: true
Explanation: Duplicate () found in subexpression ((x+y))
Input: (x+y)
Output: false
Explanation: No duplicate () is found
Input: ((x+y)+((z)))
Output: true
Explanation: Duplicate () found in subexpression ((z))*/

#include <iostream>
#include <stack>
using namespace std;

bool isDuplicate(string str) {
    stack<char> s;

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];

        // Non-closing bracket
        if (ch != ')') {
            s.push(ch);
        }
        else { // Closing bracket

            // If top is '(' → duplicate found
            if (!s.empty() && s.top() == '(') {
                return true;
            }

            // Pop until '('
            while (!s.empty() && s.top() != '(') {
                s.pop();
            }

            // Remove '('
            if (!s.empty()) {
                s.pop();
            }
        }
    }

    return false;
}

int main() {

    string str;
    cout << "Enter expression: ";
    cin >> str;

    if (isDuplicate(str)) {
        cout << "Duplicate Parentheses Found (true)" << endl;
    }
    else {
        cout << "No Duplicate Parentheses (false)" << endl;
    }

    return 0;
}