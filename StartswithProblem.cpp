/*Complete the function for a Trie:
bool startsWith(string prefix)
Given a list of words stored in the Trie:
words[] = { "apple", "app", "mango", "man", "woman" }
Check whether the Trie contains any word that starts with the given prefix.
Test the function with the following prefixes:
prefix = "app"
prefix = "moon"*/

#include <iostream>
#include <unordered_map>
#include <vector>
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

    bool startsWith(string prefix) {

        Node* temp = root;

        for(int i = 0; i < prefix.size(); i++) {

            if(temp->children[prefix[i]]) {
                temp = temp->children[prefix[i]];
            }
            else {
                return false;
            }
        }

        return true;
    }
};

int main() {

    vector<string> words = {"apple", "app", "mango", "man", "woman"};
    Trie trie;

    for(int i = 0; i < words.size(); i++) {
        trie.insert(words[i]);
    }

    cout << trie.startsWith("app") << endl;
    cout << trie.startsWith("moon") << endl;

    return 0;
}
