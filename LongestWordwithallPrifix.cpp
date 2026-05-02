/*Longest Word with all Prefix
Find the longest word in the given dictionary such that all of its prefixes are also present in the dictionary.
Input:
dict[] = ["a", "banana", "app", "appl", "ap", "apply", "apple"]*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node() {
        endOfWord = false;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string key) {
        Node* temp = root;

        for(int i = 0; i < key.size(); i++) {
            if(temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }

        temp->endOfWord = true;
    }

    void longestHelper(Node* root, string &ans, string temp) {

        for(pair<char, Node*> child : root->children) {

            if(child.second->endOfWord == false) {
                continue;
            }

            temp += child.first;

            if((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size())) {
                ans = temp;
            }

            longestHelper(child.second, ans, temp);

            temp = temp.substr(0, temp.size() - 1);
        }
    }

    string longestStringWithEOW(){
        string ans = "";
        longestHelper(root, ans, "");
        return ans;
    }
};

string longestString(vector<string> dict) {

    Trie trie;

    for(int i = 0; i < dict.size(); i++) {
        trie.insert(dict[i]);
    }

    return trie.longestStringWithEOW();
}

int main() {
    vector<string> dict = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << longestString(dict) << endl;
    return 0;
}