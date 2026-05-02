#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool isEndOfWord;

    Node(){
        isEndOfWord = false;
    }
};

class Trie{
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    // Function to insert a word into the trie
    void insert(string key){
        Node* currentNode = root;

        for(int i = 0; i < key.length(); i++){
            char c = key[i];

            if(currentNode->children.count(c) == 0){
                currentNode->children[c] = new Node();
            }

            currentNode = currentNode->children[c];
        }

        currentNode->isEndOfWord = true;
    }

    // Function to search for a word in the trie
    bool search(string key){
        Node* currentNode = root;

        for(int i = 0; i < key.length(); i++){
            char c = key[i];

            if(currentNode->children.count(c)){
                currentNode = currentNode->children[c];
            }
            else{
                return false;
            }
        }

        return currentNode->isEndOfWord;
    }
};

bool helper(Trie &trie, string key){
    if(key.length() == 0){
        return true;
    }

    for(int i = 0; i < key.length(); i++){
        string prefix = key.substr(0, i+1);
        string suffix = key.substr(i+1);

        if(trie.search(prefix) && helper(trie, suffix)){
            return true;
        }
    }

    return false;
}

bool wordBreak(vector<string> dict, string s){
    Trie trie;

    for(int i = 0; i < dict.size(); i++){
        trie.insert(dict[i]);
    }

    return helper(trie, s);
}

int main() {

    vector<string> words = {"the", "a", "their", "there", "any", "thee"};
    string s = "there";

    if(wordBreak(words, s)){
        cout << "Word Break Possible";
    }
    else{
        cout << "Word Break Not Possible";
    }

    return 0;
}