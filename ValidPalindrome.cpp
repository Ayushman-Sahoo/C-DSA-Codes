#include <iostream>
using namespace std;

bool isPalindrome(char word[], int len) {
    int st = 0;
    int end = len - 1;

    while (st < end) {
        if (word[st] != word[end]) {
            return false;
        }
        st++;
        end--;
    }
    return true;
}

int main() {
    char word[30];
    cout << "Enter a word: ";
    cin >> word;

    int len = 0;
    while (word[len] != '\0') {
        len++;
    }

    bool result = isPalindrome(word, len);

    if (result) {
        cout << "Valid Palindrome: true" << endl;
    } else {
        cout << "Valid Palindrome: false" << endl;
    }

    return 0;
}
