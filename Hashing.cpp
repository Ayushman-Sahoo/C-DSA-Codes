#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node() {
        if(next != NULL) {
            delete next;
        }
    }
};

class HashTable {
    int totSize;
    int currSize;
    Node** table;

    int hashFunction(string key) {
        int idx = 0;
        for(int i = 0; i < key.size(); i++) {
            idx = idx + (key[i] * key[i]);
        }
        return idx % totSize;
    }

    void rehash() {
        Node** oldTable = table;
        int oldSize = totSize;

        totSize = 2 * totSize;
        table = new Node*[totSize];

        for(int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }

        currSize = 0;

        for(int i = 0; i < oldSize; i++) {
            Node* temp = oldTable[i];

            while(temp != NULL) {
                insert(temp->key, temp->val);
                temp = temp->next;
            }
        }

        for(int i = 0; i < oldSize; i++) {
            if(oldTable[i] != NULL) {
                delete oldTable[i];
            }
        }

        delete[] oldTable;
    }

public:
    HashTable(int size) {
        totSize = size;
        currSize = 0;

        table = new Node*[totSize];

        for(int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, int val) { // O(1) avg
        int idx = hashFunction(key);

        Node* newNode = new Node(key, val);
        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lambda = currSize/(double)totSize;
        if(lambda > 1) {
            rehash(); // O(n) worst
        }
    }

    void remove(string key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];
        Node* prev = NULL;

        while(temp != NULL) {
            if(temp->key == key) {
                if(prev == NULL) {
                    table[idx] = temp->next;
                } else {
                    prev->next = temp->next;
                }

                temp->next = NULL;
                delete temp;
                currSize--;
                return;
            }

            prev = temp;
            temp = temp->next;
        }
    }

    bool exists(string key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];

        while(temp != NULL) {
            if(temp->key == key) {
                return true;
            }
            temp = temp->next;
        }

        return false;
    }

    int search(string key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];

        while(temp != NULL) {
            if(temp->key == key) {
                return temp->val;
            }
            temp = temp->next;
        }

        return -1;
    }

    void print() {
        for(int i = 0; i < totSize; i++) {
            cout << "idx" << i << " -> ";

            Node* temp = table[i];
            while(temp != NULL) {
                cout << "(" << temp->key << ", " << temp->val << ") -> ";
                temp = temp->next;
            }

            cout << endl;
        }
    }
};

int main() {
    HashTable ht(10);

    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("US", 50);
    ht.insert("Nepal", 10);
    ht.insert("UK", 20);

    ht.print();

    if(ht.exists("India")) {
        cout << "India population : " << ht.search("India") << endl;
    }

    ht.remove("US");

    cout << "\nAfter removing US:\n";
    ht.print();

    return 0;
}


/*#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    unordered_map<string, int> m;

    m["China"] = 150;
    m["India"] = 150;
    m["US"] = 50;
    m["Nepal"] = 10;

    for(pair<string, int> country : m) {
        cout << country.first << " : " << country.second << endl;
    }

    if(m.count("Nepal")) {
        cout << "Nepal exists\n";
    } 
    else {
        cout << "Nepal doesn't exist\n";
    }

    return 0;
}*/

/*#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;

    m["India"] = 150;
    m["China"] = 140;
    m["US"] = 50;
    m["Nepal"] = 10;

    for(auto country : m) {
        cout << country.first << " : " << country.second << endl;
    }

    return 0;
}*/

/*#include <iostream>
#include <unordered_set>
using namespace std;

int main(){

    unordered_set<int> s;

    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(1);
    s.insert(1);

    if (s.find(3) != s.end())
    {
      cout << "3 exists\n";
    }
    else
    {
      cout << "3 doesn't exist\n";
    } 
    s.erase(3);
    cout << s.size() << endl;

    return 0;
}*/

/*#include <iostream>
#include <set>
using namespace std;

int main(){

    set<int> s;

    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(1);
    s.insert(1);

    if (s.find(3) != s.end())
    {
        cout << "3 exists\n";
    }
    else
    {
        cout << "3 doesn't exist\n";
    }

    s.erase(3);
    cout << s.size() << endl;

    return 0;
}*/

/*#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

    int arr[7] = {1, 2, 7, 11, 15, 5, 9};
    int n = 7;
    int target = 9;
    unordered_map<int, int> m; //key = arr[i], val = i

    for(int i = 0; i < n; i++) {
        int comp = target - arr[i];

        if(m.count(comp)) {
            cout << "ans = " << m[comp] << ", " << i << endl;
            break;
        }

        m[arr[i]] = i;
    }

    return 0;
}*/