#include <iostream>
using namespace std;

void updateIthBit(int num, int i, int val) {

    // Step 1: Clear ith bit
    num = num & ~(1 << i);

    // Step 2: Set ith bit to val (0 or 1)
    num = num | (val << i);

    cout << num << endl;
}

int main() {
    updateIthBit(7, 2, 0);  // 7 = 111 → clear 2nd bit → 011 = 3
    updateIthBit(7, 2, 1);  // 7 = 111 → set 2nd bit → remains 7

    return 0;
}