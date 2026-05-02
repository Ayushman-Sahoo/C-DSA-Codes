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

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    string result = reverseString(str);

    cout << "Reversed string: " << result << endl;

    return 0;
}