#include <iostream>
using namespace std;

int setIthBit(int num, int i) {
    int bitMask = 1 << i;  // creates mask with ith bit = 1
    return (num | bitMask);  // OR sets the bit
}

int main() {
    cout << setIthBit(6, 1);  
    // 6 = 110 (binary)
    // set 1st bit → becomes 111 (which is 7)

    return 0;
}