/*  30. Substring with Concatenation of All Words
You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]

Output: [0,9]

Explanation:

The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.

Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]

Output: []

Explanation:

There is no concatenated substring.

Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

Output: [6,9,12]

Explanation:

The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].

Constraints:

1 <= s.length <= 104
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> result;

        if (s.empty() || words.empty()) {
            return result;
        }

        unordered_map<string, int> wordCount;

        for (string word : words) {
            wordCount[word]++;
        }

        int wordLen = words[0].size();
        int totalWords = words.size();

        for (int i = 0; i < wordLen; i++) {

            int left = i;
            int count = 0;

            unordered_map<string, int> window;

            for (int j = i; j + wordLen <= s.size(); j += wordLen) {

                string word = s.substr(j, wordLen);

                // If word exists in words array
                if (wordCount.find(word) != wordCount.end()) {

                    window[word]++;
                    count++;

                    // If frequency exceeds limit
                    while (window[word] > wordCount[word]) {

                        string leftWord = s.substr(left, wordLen);

                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // Valid substring found
                    if (count == totalWords) {

                        result.push_back(left);

                        string leftWord = s.substr(left, wordLen);

                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                } 
                else {

                    // Reset window
                    window.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return result;
    }
};

int main() {

    Solution obj;

    string s;
    int n;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter number of words: ";
    cin >> n;

    vector<string> words(n);

    cout << "Enter words:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    vector<int> ans = obj.findSubstring(s, words);

    cout << "Starting indices are: ";

    for (int index : ans) {
        cout << index << " ";
    }

    cout << endl;

    return 0;
}