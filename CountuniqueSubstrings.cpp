/*Count Unique Substrings
Count the total number of distinct substrings present in a given string.
Input:
str = "ababa"
Output:
ans = 10*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
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
    }

    int countHelper(Node* node) {
        int count = 0;

        for (auto child : node->children) {
            count += countHelper(child.second);
        }
        
        return count + 1; // Count the current node as well
    }

    int countNodes(){
        return countHelper(root);
    }
};

int countUniqueSubstrings(string str) {
    Trie trie;

    for (int i = 0; i < str.size(); i++) {
        string suffix = str.substr(i);
        trie.insert(suffix);
    }

    return trie.countNodes() - 1; // Subtract 1 to exclude the empty substring
}

int main() {
    string str = "ababa";
    cout << countUniqueSubstrings(str) << endl; // Output: 10
    return 0;
}