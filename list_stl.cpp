#include <iostream>
#include <list>
#include <iterator>
using namespace std;  

void printList(list<int> ll) {
    list <int>::iterator itr;
    for (itr = ll.begin(); itr != ll.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << NULL << endl;
} 
int main() {
    list<int> ll; // Create a list of integers
    //Adding elements to the front of the list
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);

    //Adding elements to the end of the list
    ll.push_back(40);
    ll.push_back(50);

    cout << "List elements: ";
    printList(ll);
    
    cout << "Size of the list: " << ll.size() << endl;

    cout << "Head of the list: " << ll.front() << endl;
    cout << "Tail of the list: " << ll.back() << endl;

    ll.pop_front(); // Remove the first element
    cout << "List after pop_front: "; 
    printList(ll);

    ll.pop_back(); // Remove the last element
    cout << "List after pop_back: ";
    printList(ll);

    ll.insert(ll.begin(), 5); // Insert 5 at the beginning
    cout << "List after inserting 5 at the beginning: ";
    printList(ll);
     
    return 0;
}