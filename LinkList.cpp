// LinkList Implementation
#include <iostream>
using namespace std;
class Node {
public:    
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }

    ~Node() {
        if (next != NULL) {
            cout << "Deleting node with value: " << next->data << endl;
            delete next;
            next = NULL;
        }
    }
};

class List {
public:
    Node* head;
    Node* tail;
    
    List() {
        head = NULL;
        tail = NULL;
    }

    ~List() {
        Node* temp = head;
        cout << "Deleting list..." << endl;
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
        
    }
    
    void push_front(int value) {
        //Node* newNode(value);//static allocation deletes itself after the function ends
        Node* newNode = new Node(value); //dynamic allocation, we have to delete it ourselves
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        } 
    }
    void push_back(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    } 

    void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

    void insert(int value, int pos) {
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 0; i < pos-1; i++)
        {
            if (temp == NULL) {
                cout << "Position out of bounds!" << endl;
                return;
            }
            temp = temp->next;
        }
        // temp is now at the position-1 i.e. previous/left node
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL; // disconnect the node to be deleted
        delete temp; // delete the node
    }

    void pop_back() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == NULL) { // only one node
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail; // delete the last node
        tail = temp; // update tail to the new last node
        tail->next = NULL; // disconnect the new last node
    }

    //Iterative search
    int seachItr(int key) {
        Node* temp = head;
        int idx = 0;
        while (temp != NULL) {
            if (temp->data == key) {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1; // Return -1 if element not found
    }

    //Recursive search
    int searchRec(int key) {
        return searchRecHelper(head, key);
    }
    int searchRecHelper(Node* h, int key) {
        if (h == NULL) {
            return -1;
        }
        if (h->data == key) {
            return 0;
        }
        int idx = searchRecHelper(h->next, key);
        if (idx == -1) {
            return -1;
        }
        return idx + 1;
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        tail = head; // update tail to the current head before reversing
        while (curr != NULL) {
            Node* next = curr->next; // store next node
            curr->next = prev; // reverse the link
            prev = curr; // move prev to current
            curr = next; // move to next node
        }
        swap(head, tail); // swap head and tail pointers
    }

   void revmoveNth(int n) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    // Step 1: calculate size of list
    int size = 0;
    Node* temp = head;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }

    // Step 2: check if n is valid
    if (n > size || n <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Step 3: if deleting first node
    if (n == size) {
        Node* toDelete = head;
        cout << "Deleting node with value: " << toDelete->data << endl;
        head = head->next;
        toDelete->next = NULL;
        delete toDelete;
        return;
    }

    // Step 4: go to previous node
    Node* prev = head;
    for (int i = 1; i < size - n; i++) {
        prev = prev->next;
    }

    // Step 5: delete nth node from end
    Node* toDelete = prev->next;
    cout << "Deleting node with value: " << toDelete->data << endl;
    prev->next = toDelete->next;

    if (toDelete == tail) {
        tail = prev;
    }

    toDelete->next = NULL;
    delete toDelete;
}
};

int main() {
    List ll;
    ll.push_front(40);
    ll.push_front(30);
    ll.push_front(20);
    ll.push_front(10); 
    ll.display();
    
    ll.push_back(50);
    ll.push_back(60);
    ll.display();

    ll.insert(25, 2);
    ll.display();
    

    ll.reverse();
    ll.display();

    ll.pop_front();
    ll.display();

    ll.pop_back();
    ll.display();

    ll.revmoveNth(2);
    ll.display();
    
    ll.seachItr(25) ? cout << "Element found at index: " << ll.seachItr(25) << endl : cout << "Element not found!" << endl;

    cout << "Element found at index (recursive): " << ll.searchRec(25) << endl;
    return 0;
}