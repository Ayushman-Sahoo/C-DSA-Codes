/*146. LRU Cache 
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]
Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
Constraints:
1 <= capacity <= 3000
0 <= key <= 10^4
0 <= value <= 10^5
At most 2 * 105 calls will be made to get and put.
*/

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];
        int value = it->second;

        // Move accessed node to front (Most Recently Used)
        cache.erase(it);
        cache.push_front({key, value});
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Key already exists
            cache.erase(mp[key]);
        }
        else if (cache.size() == capacity) {
            // Remove Least Recently Used
            auto last = cache.back();
            mp.erase(last.first);
            cache.pop_back();
        }

        // Insert new node at front
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }

    void display() {
        cout << "Cache (MRU -> LRU): ";
        for (auto p : cache)
            cout << "[" << p.first << ":" << p.second << "] ";
        cout << endl;
    }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.display();

    cache.put(2, 2);
    cache.display();

    cout << "get(1) = " << cache.get(1) << endl;
    cache.display();

    cache.put(3, 3);
    cache.display();

    cout << "get(2) = " << cache.get(2) << endl;

    cache.put(4, 4);
    cache.display();

    cout << "get(1) = " << cache.get(1) << endl;
    cout << "get(3) = " << cache.get(3) << endl;
    cout << "get(4) = " << cache.get(4) << endl;

    return 0;
}