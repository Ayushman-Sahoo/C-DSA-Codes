// Using backtracking to find all permutations of an array
#include <iostream>
using namespace std;

// Function to print the array
void printArray(int arr[], int n)
{
    // Loop through the array and print each element
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl; // Move to next line after printing one permutation
}

// Backtracking function to generate permutations
void backtrack(int arr[], int start, int n)
{
    // BASE CASE:
    // If start index reaches end of array,
    // it means one permutation is ready
    if(start == n)
    {
        printArray(arr, n); // Print the current permutation
        return;             // Return to previous call
    }

    // LOOP:
    // Try every element from current position to end
    for(int i = start; i < n; i++)
    {
        // CHOOSE:
        // Swap current element with start element
        // This fixes one element at current position
        swap(arr[start], arr[i]);

        // EXPLORE:
        // Recursively generate permutations for remaining elements
        backtrack(arr, start + 1, n);

        // BACKTRACK (UNDO STEP):
        // Restore the original array by swapping back
        // This is necessary to try other possibilities
        swap(arr[start], arr[i]);
    }
}

int main()
{
    // Declare and initialize the array
    int arr[] = {1, 2, 3};

    // Find size of array
    int n = 3;

    // Print message
    cout << "All permutations of the array are:\n";

    // Call backtracking function starting from index 0
    backtrack(arr, 0, n);

    return 0; // End of program
}