#include <iostream>
using namespace std;
void countSetBits(int n) {
    int count = 0;
    while (n > 0)
    {
        count += n & 1; // Increment count if last bit is 1
        n = n >> 1;     // Right shift n to process the next bit
    }
    cout << count << endl;
}
int main() {
    int n = 13; // Example number
    countSetBits(n); // Output: 3 (since 13 is 1101 in binary)
    return 0;
}