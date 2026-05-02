/*Prefix Problem

Find the shortest unique prefix for each word in a given list of words.
It is guaranteed that no word is a prefix of another word.

Input:
words[] = { "zebra", "dog", "duck", "dove" }

Output:
ans[] = { "z", "dog", "du", "dov" }*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    int freq;
    bool endOfWord;

    Node() {
        freq = 0;
        endOfWord = false;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
        root->freq = -1;
    }

    void insert(string key) { // O(L)

        Node* temp = root;

        for(int i = 0; i < key.size(); i++) {

            if(temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node();   // insert
                temp->children[key[i]]->freq = 1;
            }
            else {
                temp->children[key[i]]->freq++;
            }

            temp = temp->children[key[i]];
        }

        temp->endOfWord = true;
    }

    string getPrefix(string key) {

        Node* temp = root;
        string prefix = "";

        for(int i = 0; i < key.size(); i++) {

            prefix += key[i];

            if(temp->children[key[i]]->freq == 1) {
                break;
            }

            temp = temp->children[key[i]];
        }

        return prefix;
    }
};

void prefixProblem(vector<string> dict) { //O(n*L)

    Trie trie;

    for(int i = 0; i < dict.size(); i++) {
        trie.insert(dict[i]);
    }

    for(int i = 0; i < dict.size(); i++) {
        cout << trie.getPrefix(dict[i]) << endl;
    }

}

int main() {

    vector<string> words = {"zebra", "dog", "duck", "dove"};
    Trie trie;

    for (int i = 0; i < words.size(); i++) {
        trie.insert(words[i]);
    }

    for (int i = 0; i < words.size(); i++) {
        cout << trie.getPrefix(words[i]) << " ";
    }

    return 0;
}