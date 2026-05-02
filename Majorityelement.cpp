/*Majority Element (n/3 version)
Problem:
Given an integer array of size n, find all elements that appear more than ⌊n/3⌋ times.
Example:
Input
n = 9
arr = [1, 3, 2, 5, 1, 3, 1, 5, 1]
Output
[1, 3]*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void majorityElement(int arr[], int n) {
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        if (freq.count(arr[i])) {
            freq[arr[i]]++;
        }
        else {
            freq[arr[i]] = 1;
        }
    }

    for (pair<int, int> p : freq) {
        if (p.second > n/3) {
            cout << p.first << " ";
        }
    }

    cout << endl;
}

int main() {
    int n = 9;
    int arr[9] = {1, 3, 2, 5, 1, 3, 1, 5, 1};

    majorityElement(arr, n);

    return 0;
}