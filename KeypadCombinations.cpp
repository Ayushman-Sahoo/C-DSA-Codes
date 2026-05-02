// Keypad Combinations Question
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Recursive function to generate all combinations
void bfs(int pos, int len, string ans, string Dig, vector<vector<char>> L)
{
    // Base case: if full combination formed, print it
    if (pos == len)
    {
        cout << ans << endl;
        return;
    }

    // Get letters corresponding to current digit
    vector<char> letters = L[Dig[pos] - '0'];

    // Try each letter and move to next digit
    for (int i = 0; i < letters.size(); i++)
    {
        bfs(pos + 1, len, ans + letters[i], Dig, L);
    }
}

// Function to start generating combinations
void letterCombinations(string Dig, vector<vector<char>> L)
{
    int len = Dig.size();

    // If input is empty, print nothing
    if (len == 0)
    {
        cout << "";
        return;
    }

    string ans = ""; // stores current combination

    // Call recursive function
    bfs(0, len, ans, Dig, L);
}

int main()
{
    // Keypad mapping (index = digit)
    vector<vector<char>> L =
    {
        {}, {},              // 0 and 1 have no letters
        {'a','b','c'},      // 2
        {'d','e','f'},      // 3
        {'g','h','i'},      // 4
        {'j','k','l'},      // 5
        {'m','n','o'},      // 6
        {'p','q','r','s'},  // 7
        {'t','u','v'},      // 8
        {'w','x','y','z'}   // 9
    };

    string digits;

    // Take input from user
    cout << "Enter digits (2-9): ";
    cin >> digits;

    // Print all combinations
    cout << "Possible combinations are:\n";
    letterCombinations(digits, L);

    return 0;
}
