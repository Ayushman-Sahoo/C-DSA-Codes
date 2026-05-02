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
            if(currentNode->children.count(key[i]) == 0){
                currentNode->children[c] = new Node();
            }
            currentNode = currentNode->children[key[i]];
        }
        currentNode->isEndOfWord = true;
    }

    // Function to search for a word in the trie
    bool search(string key){
        Node* currentNode = root;
        for(int i = 0; i < key.length(); i++){
            char c = key[i];
            if(currentNode->children.count(key[i])){
                currentNode = currentNode->children[key[i]];
            }
            else{
                return false;
            }
        }
        return currentNode->isEndOfWord;
    }

};


int main() {
    Trie trie;
    vector<string> words = {"the", "a", "their", "there", "any", "thee"};
    
    for(int i = 0; i < words.size(); i++){
        trie.insert(words[i]);
    }

    cout << trie.search("the") << endl; // Output: 1 (true)
    cout << trie.search("their") << endl; // Output: 1 (true)
    cout << trie.search("there") << endl; // Output: 1 (true)
    cout << trie.search("any") << endl; // Output: 1 (true) 
    cout << trie.search("thee") << endl; // Output: 1 (true)
    cout << trie.search("th") << endl; // Output: 0 (false)

    
    return 0;
}