#include <iostream>
using namespace std;

void FastExponentiation(int x, int n) {
    int ans = 1;

    while(n > 0) {
        int lastBit = n & 1;
        if(lastBit) {
            ans = ans * x;
        }
        x = x * x;
        n = n >> 1;
    }

    cout << ans << endl;
}

int main() {
    int x, n;
    cin >> x >> n;
    FastExponentiation(x, n);
    return 0;
}