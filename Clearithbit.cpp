#include <iostream>
using namespace std;

int clearIthBit(int num, int i) {
    int bitMask = ~(1 << i);   // mask with ith bit = 0, others = 1
    return (num & bitMask);    // AND clears the bit
}

int main() {
    cout << clearIthBit(7, 1);
    // 7 = 111 (binary)
    // clear 1st bit -> 101 = 5

    return 0;
}
