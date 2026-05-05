/*#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the nth Catalan number using recursion
int catalanNumber(int n) {
  if (n==0 || n == 1)
  {
    return 1;
  }
  
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += catalanNumber(i) * catalanNumber(n - 1 - i);
  }
  return ans;
}

int main() {
  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  int result = catalanNumber(n);
  cout << "The " << n << "th Catalan number is: " << result << endl;

  return 0;
}*/

// using memoization to optimize the recursive solution
/*#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the nth Catalan number using dynamic programming
int catalanNumber(int n, vector<int>& dp) {
  if (n==0 || n == 1)
  {
    return 1;
  }
  if (dp[n] != -1)
  {
    return dp[n];
  }
  
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += catalanNumber(i, dp) * catalanNumber(n - 1 - i, dp);
  }
  dp[n] = ans;
  return ans;
}

int main() {
  vector<int> catalan(100, -1); // Create a vector to store computed Catalan numbers
  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  int result = catalanNumber(n, catalan);
  cout << "The " << n << "th Catalan number is: " << result << endl;

  return 0;
}*/

// using tabulation to optimize the recursive solution
#include <iostream> 
#include <vector>

using namespace std;

int catalanNumber(int n) {
  vector<int> dp(n + 1, 0); // Create a vector to store computed Catalan numbers
  dp[0] = 1; // Base case: C(0) = 1
  dp[1] = 1; // Base case: C(1) = 1

  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      dp[i] += dp[j] * dp[i - 1 - j]; // C(i) += C(j) * C(i-1-j)
    }
  }
  
  return dp[n];
}

int main() {
  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  int result = catalanNumber(n);
  cout << "The " << n << "th Catalan number is: " << result << endl;

  return 0;
}
