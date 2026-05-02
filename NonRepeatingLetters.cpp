#include <iostream>
#include <queue>
using namespace std;

void FirstNonRepeat(string str) {  //O(n) and O(n) space
    queue<char> Q;
    int freq[26] = {0};

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        Q.push(ch);
        freq[ch - 'a']++;

        while (!Q.empty() && freq[Q.front() - 'a'] > 1) {
            Q.pop();
        }

        if (Q.empty()) {
            cout << "-1 ";
        } else {
            cout << Q.front() << " ";
        }
    }
}

int main() {
    string str = "aabccxb";
    FirstNonRepeat(str);
    return 0;
}