#include <iostream>
using namespace std;

// Function to calculate factorial
int factorial(int num) {
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate binomial coefficient
int binomialCoeff(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n, r;
    cout << "Enter n and r: ";
    cin >> n >> r;

    if (r > n || n < 0 || r < 0) {
        cout << "Invalid input. Ensure that 0 ≤ r ≤ n." << endl;
    } else {
        int result = binomialCoeff(n, r);
        cout << "Binomial Coefficient C(" << n << ", " << r << ") = " << result << endl;
    }

    return 0;
}