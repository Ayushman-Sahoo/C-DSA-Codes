// Tower of Hanoi using recursion
#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    // Base case: only one disk to move
    if (n == 1) {
      cout << "transfer disk " << n << " from " << source << " to " << destination << endl;
      return;
    }
    //transfer top n-1 from src to helper using dest as 'helper'
    towerOfHanoi(n-1, source, auxiliary, destination);

    //transfer nth from src to dest
    cout << "transfer disk " << n << " from " << source << " to " << destination << endl;
    
    //transfer n-1 from helper to dest using src as 'helper'
    towerOfHanoi(n-1, auxiliary, destination, source);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}

// Loop Approach
/*#include <iostream>   
using namespace std;
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

// Function to move top disk between two rods
void moveBetweenRods(stack<int>& from, stack<int>& to, char src, char dest)
{
    // If source rod is empty
    if (from.empty())
    {
        from.push(to.top());
        cout << "Shift disk " << to.top() << " from " << dest << " to " << src << endl;
        to.pop();
    }
    // If destination rod is empty
    else if (to.empty())
    {
        to.push(from.top());
        cout << "Shift disk " << from.top() << " from " << src << " to " << dest << endl;
        from.pop();
    }
    // If top disk of source is smaller
    else if (from.top() < to.top())
    {
        to.push(from.top());
        cout << "Shift disk " << from.top() << " from " << src << " to " << dest << endl;
        from.pop();
    }
    // If top disk of destination is smaller
    else
    {
        from.push(to.top());
        cout << "Shift disk " << to.top() << " from " << dest << " to " << src << endl;
        to.pop();
    }
}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    stack<int> A, B, C;

    // Push disks into rod A
    for (int i = n; i >= 1; i--)
        A.push(i);

    int totalMoves = pow(2, n) - 1;

    char src = 'A', aux = 'B', dest = 'C';

    // If n is even, swap destination and auxiliary
    if (n % 2 == 0)
        swap(dest, aux);

    for (int i = 1; i <= totalMoves; i++)
    {
        if (i % 3 == 1)
            moveBetweenRods(A, C, src, dest);
        else if (i % 3 == 2)
            moveBetweenRods(A, B, src, aux);
        else
            moveBetweenRods(B, C, aux, dest);
    }

    return 0;
}*/