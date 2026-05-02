#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if(n == 0) return false;      // 0 is not a power of 2
    return (n & (n - 1)) == 0;    // only 1 bit is set in power of 2
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if(isPowerOfTwo(num))
        cout << num << " is a Power of 2";
    else
        cout << num << " is NOT a Power of 2";

    return 0;
}
