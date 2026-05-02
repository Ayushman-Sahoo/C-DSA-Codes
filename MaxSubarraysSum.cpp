//Brute Force
/*#include <iostream>
using namespace std;

// Function to find maximum subarray sum (brute force O(n^3))
int maxSubarraySum(int arr[], int n) {
    int maxSum = arr[0]; // initialize with first element

    // Generate all subarrays
    for (int start = 0; start < n; start++) {
        for (int end = start; end < n; end++) {
            int sum = 0;
            // Calculate sum of subarray arr[start..end]
            for (int k = start; k <= end; k++) {
                sum += arr[k];
            }
            // Update max sum if needed
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }

    return maxSum;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = maxSubarraySum(arr, n);
    cout << "Maximum Subarray Sum = " << result << endl;

    return 0;
}*/

//more optimization in bruteforce approach
/*#include <iostream>
using namespace std;

// Function to find maximum subarray sum (improved O(n^2))
int maxSubarraySum(int arr[], int n) {
    int maxSum = arr[0]; // initialize with first element

    // Generate all subarrays
    for (int start = 0; start < n; start++) {
        int sum = 0; // running sum for subarrays starting at 'start'

        for (int end = start; end < n; end++) {
            sum += arr[end]; // add next element
            if (sum > maxSum) {
                maxSum = sum; // update maximum
            }
        }
    }

    return maxSum;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = maxSubarraySum(arr, n);
    cout << "Maximum Subarray Sum = " << result << endl;

    return 0;
}*/

//using Kadanes Algorithm
#include <iostream>
using namespace std;

// Function to find maximum subarray sum using Kadane's Algorithm (O(n))
int maxSubarraySum(int arr[], int n) {
    int maxSum = arr[0];       // maximum sum found so far
    int currSum = arr[0];      // current subarray sum

    for (int i = 1; i < n; i++) {
        // Either extend the current subarray OR start a new subarray at arr[i]
        currSum = max(arr[i], currSum + arr[i]);

        // Update overall max sum
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = maxSubarraySum(arr, n);
    cout << "Maximum Subarray Sum = " << result << endl;

    return 0;
}