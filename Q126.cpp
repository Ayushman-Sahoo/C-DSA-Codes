/*126. Word Ladder II
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].
Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
Constraints:
1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 500
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
The sum of all shortest transformation sequences does not exceed 10^5.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> parents;
    vector<vector<string>> ans;
    vector<string> path;

    void dfs(string word, string &beginWord) {
        path.push_back(word);

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        } else {
            for (string &par : parents[word]) {
                dfs(par, beginWord);
            }
        }

        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord))
            return {};

        unordered_map<string, int> level;
        queue<string> q;

        q.push(beginWord);
        level[beginWord] = 0;

        int wordLen = beginWord.size();

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            int currLevel = level[word];

            string temp = word;

            for (int i = 0; i < wordLen; i++) {
                char original = temp[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;

                    if (!dict.count(temp))
                        continue;

                    if (!level.count(temp)) {
                        level[temp] = currLevel + 1;
                        q.push(temp);
                        parents[temp].push_back(word);
                    }
                    else if (level[temp] == currLevel + 1) {
                        parents[temp].push_back(word);
                    }
                }

                temp[i] = original;
            }
        }

        if (!level.count(endWord))
            return {};

        dfs(endWord, beginWord);

        return ans;
    }
};

int main() {
    Solution obj;

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {
        "hot", "dot", "dog", "lot", "log", "cog"
    };

    vector<vector<string>> result = obj.findLadders(beginWord, endWord, wordList);

    if (result.empty()) {
        cout << "No transformation sequence found.\n";
    } else {
        cout << "Shortest Transformation Sequences:\n";
        for (auto &path : result) {
            for (auto &word : path) {
                cout << word << " ";
            }
            cout << endl;
        }
    }

    return 0;
}