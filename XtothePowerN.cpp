//recursion to calculate x raised to the power n
#include <iostream>
using namespace std;

int power(int x, int n) {
    // Base case
    if (n == 0) {
        return 1;
    }

    // Recursive call
    int halfPow = power(x, n / 2);
    int halfPowSquare = halfPow * halfPow;

    // If n is odd
    if (n % 2 != 0) {
        return x * halfPowSquare;
    }

    return halfPowSquare;
}

int main() {
    int x, n;
    cout << "Enter X: ";
    cin >> x;
    cout << "Enter N: ";
    cin >> n;

    cout << "Result: " << power(x, n);
    return 0;
}
//loop
/*#include <iostream>
using namespace std;

int main() {
    int x, n;
    cout << "Enter value of X: ";
    cin >> x;
    cout << "Enter value of N: ";
    cin >> n;

    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * x;
    }

    cout << "Result: " << result;
    return 0;
}
*/