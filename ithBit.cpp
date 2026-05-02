#include <iostream>
using namespace std;

// Function to get the ith bit of a number
int getIthBit(int num, int i) {
    int bitMask = 1 << i;

    if(!(num & bitMask)) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    cout << getIthBit(6, 2);  // Example → checking 2nd bit of 6 (binary 110)

    return 0;
}