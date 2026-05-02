// Count Good Digit Strings
#include <iostream>
using namespace std;

long long MOD = 1000000007;

// Recursive power function
long long power(long long base, long long exp)
{
    // Base case
    if (exp == 0)
        return 1;

    long long half = power(base, exp / 2);
    half = (half * half) % MOD;

    // If exponent is odd
    if (exp % 2 == 1)
        return (half * base) % MOD;

    return half;
}

int main()
{
    long long n;
    cout << "Enter n: ";
    cin >> n;

    long long evenPositions = (n + 1) / 2;
    long long oddPositions = n / 2;

    long long ans = (power(5, evenPositions) * power(4, oddPositions)) % MOD;

    cout << "Number of good digit strings: " << ans << endl;
    return 0;
}

// Loop Approach
/*#include <iostream>
using namespace std;

long long MOD = 1000000007;

// Binary exponentiation using loop
long long power(long long base, long long exp)
{
    long long result = 1;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % MOD;

        base = (base * base) % MOD;
        exp = exp / 2;
    }
    return result;
}

int main()
{
    long long n;
    cout << "Enter n: ";
    cin >> n;

    long long evenPositions = (n + 1) / 2;
    long long oddPositions = n / 2;

    long long ans = (power(5, evenPositions) * power(4, oddPositions)) % MOD;

    cout << "Number of good digit strings: " << ans << endl;
    return 0;
}*/