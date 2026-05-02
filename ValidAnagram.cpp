//Using arrays to count characters in both strings and compare the counts to determine if they are anagrams.
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;

    // Take two words from user
    cout << "Enter first word: ";
    cin >> str1;

    cout << "Enter second word: ";
    cin >> str2;

    // If lengths are different, not an anagram
    if (str1.length() != str2.length()) {
        cout << "Not an anagram" << endl;
        return 0;
    }

    // Create two arrays to count characters (for a-z)
    int count1[26] = {0};
    int count2[26] = {0};

    // Count letters in both strings
    for (int i = 0; i < str1.length(); i++) {
        count1[str1[i] - 'a']++;
        count2[str2[i] - 'a']++;
    }

    // Compare both counts
    bool isAnagram = true;
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            isAnagram = false;
            break;
        }
    }

    // Show result
    if (isAnagram)
        cout << "It is a valid anagram!" << endl;
    else
        cout << "Not an anagram" << endl;

    return 0;
}

//Using hash maps to count characters in both strings and compare the counts to determine if they are anagrams.
/*
#include <iostream>
#include <unordered_map>

using namespace std;

bool validAnagrams(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }
        
    // <char, freq>
    unordered_map<char, int> freq;

    for(int i = 0; i < s.size(); i++) {
        if(freq.count(s[i])) {
            freq[s[i]]++;
        } 
        else {
            freq[s[i]] = 1;
        }
    }
    
    for(int i = 0; i < t.size(); i++) {
        if(freq.count(t[i])) {
            freq[t[i]]--;
            if(freq[t[i]] == 0) {
                freq.erase(t[i]);
            }
        } 
        else {
            return false;
        }
    }
    return freq.size() == 0;
}

int main() {
    string s, t;
    cout << "Enter first word: ";
    cin >> s;

    cout << "Enter second word: ";
    cin >> t;

    if(validAnagrams(s, t)) {
        cout << "It is a valid anagram!" << endl;
    }
    else {
        cout << "Not an anagram" << endl;
    }

    return 0;
}
*/