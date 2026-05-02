#include <iostream>
using namespace std;

// Function to convert decimal to binary (returns integer form)
long long decimalToBinary(int n) {
    int pow = 1;        // 10^0, 10^1, 10^2...
    long long binNum = 0;  // store binary digits in integer form

    while (n > 0) {
        int rem = n % 2;         // remainder (0 or 1)
        binNum += rem * pow;     // place it at correct position
        n = n / 2;               // reduce n
        pow = pow * 10;          // increase place value (1, 10, 100, …)
    }

    return binNum;
}

int main() {
    int num;
    cout << "Enter a decimal number: ";
    cin >> num;

    cout << "Binary: " << decimalToBinary(num) << endl;

    return 0;
}
