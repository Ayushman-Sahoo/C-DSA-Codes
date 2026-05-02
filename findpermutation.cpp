//using backtracking to find all permutations of an array
#include <iostream>
using namespace std;
// Function to print the array
void permutation(string str, string ans)
{
    int n = str.size();

    // BASE CASE:
    // If string becomes empty, print the permutation
    if(n == 0)
    {
        cout << ans << "\n";
        return;
    }

    // LOOP:
    // Try every character in the string
    for(int i = 0; i < n; i++)
    {
        // CHOOSE:
        // Take current character
        char ch = str[i];

        // Remaining string after removing current character
        string remaining = str.substr(0, i) + str.substr(i + 1);

        // EXPLORE:
        // Recursively generate permutations for remaining string
        permutation(remaining, ans + ch);
    }
}
int main()
{
    string str;

    // Take input from user
    cout << "Enter the string: ";
    cin >> str;

    cout << "\nAll permutations are:\n";

    // Initial call with empty answer
    permutation(str, "");

    return 0;
}