/*#include <iostream>
using namespace std;
// Recursive function to find Fibonacci number
int fibonacci(int n) {
    if (n == 0)
        return 0;          // base case 1
    if (n == 1)
        return 1;          // base case 2
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Fibonacci number at position " << n << " is " << fibonacci(n) << endl;

    return 0;
}*/
//loop
/*#include <iostream>
using namespace std;

int main() {
    int n;
    int a = 0, b = 1, c;

    cout << "Enter number of terms: ";
    cin >> n;

    cout << "Fibonacci series: ";

    for (int i = 1; i <= n; i++) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }

    return 0;
}*/

//Using Dynamic Programming (Memoization) Top-Down Approach
/*#include <iostream> 
#include <vector>
using namespace std;

int fibonacci(int n, vector<int>& memo) {
    if (n == 0)
        return 0;          // base case 1
    if (n == 1)
        return 1;          // base case 2

    if (memo[n] != -1)
        return memo[n];    // return cached result

    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo); // store result in cache
    return memo[n];
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> memo(n + 1, -1); // Initialize memoization array with -1
    cout << "Fibonacci number at position " << n << " is " << fibonacci(n, memo) << endl;

    return 0;
}*/
//Using Dynamic Programming (Tabulation) Bottom-Up Approach
#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Fibonacci number at position " << n << " is " << fibonacci(n) << endl;

    return 0;
}
